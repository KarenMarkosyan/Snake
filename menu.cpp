#include "menu.h"
#include "ui_menu.h"


menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    isPause = false;
    isOptions = false;
    mastLoadFromP = false;
    readOptions();
    ui->proceed->setVisible(isPause);
    showHideOptions(false);
}

menu::~menu()
{
    delete ui;
}

void menu::showHideOptions(bool flag)
{
    setWindowTitle(!flag ? "Змейка: Главное меню." : "Змейка: Настройки.");
    ui->save->setVisible(flag);
    ui->cancell->setVisible(flag);
    ui->label->setVisible(flag);
    ui->label_2->setVisible(flag);
    ui->label_3->setVisible(flag);
    ui->height->setVisible(flag);
    ui->width->setVisible(flag);
    ui->speed->setVisible(flag);
    ui->fieldOptions->setVisible(flag);
    ui->path->setVisible(flag);
    ui->couse->setVisible(flag);
    ui->loard->setVisible(flag);

    ui->proceed->setVisible(isPause&&!flag);
    ui->newGame->setVisible(!flag);
    ui->options->setVisible(!flag);
    ui->exit->setVisible(!flag);
}

void menu::readOptions()
{
    h = ui->height->value();
    w = ui->width->value();
    s = ui->speed->value();
}

bool **menu::load(QString file)
{
    bool ** res = 0;
    QFile f(file);
    if (f.open(QIODevice::ReadOnly)){
        QString s(f.readAll());
        if (s.indexOf('\n') == -1){
            QMessageBox::critical(this, "Ошибка загрузки поля", "Невозможно загрузить поле из файла \"" + file +"\", так как файл некоректен.\n Игра будет запущена на пустом поле в соответствии с параметрами заданными в меню.");
            return NULL;
        }
        int ih = s.mid(0, s.indexOf('\n')).toInt();
        s.remove(0, s.indexOf('\n')+1);
        if (s.indexOf('\n') == -1){
            QMessageBox::critical(this, "Ошибка загрузки поля", "Невозможно загрузить поле из файла \"" + file +"\", так как файл некоректен.\n Игра будет запущена на пустом поле в соответствии с параметрами заданными в меню.");
            return NULL;
        }
        int iw = s.mid(0, s.indexOf('\n')+1).toInt();
        s.remove(0, s.indexOf('\n')+1);
        if (s.length() != ih*iw + ih){
            QMessageBox::critical(this, "Ошибка загрузки поля", "Невозможно загрузить поле из файла \"" + file +"\", так как файл некоректен.\n Игра будет запущена на пустом поле в соответствии с параметрами заданными в меню.");
            return NULL;
        }

        h = ih;
        w = iw;

        res = new bool *[ih];
        for (int i = 0; i < ih; ++i)
            res[i] = new bool [iw];


        for (int i = 0; i < ih; i++){
            for (int j = 0; j < iw; j++){
                res[i][j] = s.mid(0, 1).toInt();
                s.remove(0,1);
            }
            s.remove(0,2);
        }
    }
    else{
        QMessageBox::critical(this, "Ошибка загрузки поля", "Невозможно загрузить поле из файла \"" + file +"\".\n Игра будет запущена на пустом поле в соответствии с параметрами заданными в меню.");
    }
    return res;
}

void menu::on_options_clicked()
{
    showHideOptions(true);
}

void menu::on_save_clicked()
{
    readOptions();
    //Сохраняем в файл
    showHideOptions(false);
}

void menu::on_cancell_clicked()
{
    ui->height->setValue(h);
    ui->width->setValue(w);
    ui->speed->setValue(s);
    showHideOptions(false);
}

void menu::on_newGame_clicked()
{
    board = NULL;
    if (mastLoadFromP){
        board = load(p);
    }
    gF = new gameField(w, h, s, board);
    gF->show();
    connect(gF, SIGNAL(windowTitleChanged(QString)), this, SLOT(CLEAR()));
    hide();
}


void menu::on_loard_clicked(bool checked)
{
    ui->fieldOptions->setEnabled(!checked);
    ui->path->setEnabled(checked);
    ui->couse->setEnabled(checked);
    mastLoadFromP = checked;
}

void menu::CLEAR()
{
    if (gF->windowTitle().isEmpty()){
        delete gF;
        delete board;
        show();
    }
}

void menu::on_couse_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Загрузить обстановку:"), "", tr("Файл игрового поля (*.gff)"));
    if (!fileName.isEmpty())
        ui->path->setText(fileName);
}

void menu::on_path_textChanged(const QString &arg1)
{
    p = arg1;
}

void menu::on_createField_clicked()
{
    c = new cerateField(this);
    c->show();
}

void menu::closeEvent(QCloseEvent *e)
{

}
