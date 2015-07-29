#include "ceratefield.h"
#include "ui_ceratefield.h"

cerateField::cerateField(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cerateField)
{
    ui->setupUi(this);
    isCreate = false;
    ui->fielW->hide();
    setTable();
    parentW = parent;
    parentW->setEnabled(false);
    this->setEnabled(true);
}

cerateField::~cerateField()
{
    delete ui;
}

void cerateField::on_cansle_clicked()
{
    if(!isCreate){
        close();
    }
    else{
        ui->cansle->setText("Отмена");
        ui->fielW->hide();
        ui->paf->show();
        isCreate = false;
    }
}

void cerateField::on_next_clicked()
{
    if(!isCreate){
        ui->cansle->setText("Назат");
        ui->fielW->show();
        ui->paf->hide();
        isCreate = true;
    }
    else{
        QFile f(ui->dir->text() + ui->name1->text() + ".gff");
        QString output = QString::number(ui->h->value()) +"\n"
                + QString::number(ui->w->value()) +"\n";
        for (int h = 0; h < ui->h->value(); ++h){
            for (int w = 0; w < ui->h->value(); ++w){
                output += (ui->table->item(h, w) == NULL) ? "0" : "1";
            }
            output += "\n";
        }
        if (f.open(QIODevice::WriteOnly)){
            QTextStream outp(&f);
            outp << output;
            f.close();
            close();
        }
    }
}

void cerateField::on_dir_textChanged(const QString &arg1)
{
    ui->next->setEnabled(!arg1.isEmpty() && !ui->name1->text().isEmpty());
}

void cerateField::on_name1_textChanged(const QString &arg1)
{
    ui->next->setEnabled(!arg1.isEmpty() && !ui->dir->text().isEmpty());
}

void cerateField::setTable()
{
    ui->table->setColumnCount(ui->w->value());
    ui->table->setRowCount(ui->h->value());

}

void cerateField::on_w_valueChanged(int arg1)
{
    setTable();
}

void cerateField::on_h_valueChanged(int arg1)
{
    setTable();
}

void cerateField::on_table_cellClicked(int row, int column)
{
    if  (ui->table->item(row, column) == NULL){
        ui->table->setItem(row, column, new QTableWidgetItem(""));
        ui->table->item(row, column)->setBackgroundColor(QColor(50,50,50));

    }
    else{
        delete ui->table->item(row, column);
        ui->table->setItem(row, column, NULL);
    }
    ui->table->setCurrentCell(-1,-1);
}

void cerateField::on_cDir_clicked()
{
    QString d = QFileDialog::getExistingDirectory(this, "Выберете дирректорию для сохранения", "");
    if (!d.isEmpty())
        ui->dir->setText(d + "/");
}

void cerateField::closeEvent(QCloseEvent *e)
{
    parentW->setEnabled(true);
    QDialog::closeEvent(e);
}
