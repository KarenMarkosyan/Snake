#include "menu.h"
#include "ui_menu.h"
#include <windows.h>

menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    isPause = false;
    isOptions = false;
    readOptions();
    ui->proceed->setVisible(isPause);
    showHideOptions(false);
}

menu::~menu()
{
    delete ui;
}

menu::showHideOptions(bool flag)
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

menu::readOptions()
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
        int ih = s.mid(0, s.indexOf('\n')).toInt();
        s.remove(0, s.indexOf('\n')+1);
        int iw = s.mid(0, s.indexOf('\n')+1).toInt();
        s.remove(0, s.indexOf('\n')+1);


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
    gF = new gameField(w, h, s, NULL);
    gF->show();
    connect(gF, SIGNAL(windowTitleChanged(QString)), this, SLOT(CLEAR()));
}


void menu::on_loard_clicked(bool checked)
{
    ui->fieldOptions->setEnabled(!checked);
    ui->path->setEnabled(checked);
    ui->couse->setEnabled(checked);
}

void menu::CLEAR()
{
    if (gF->windowTitle().isEmpty())
        delete gF;
}

void menu::on_couse_clicked()
{
    gF = new gameField(w, h, s, load(ui->path->text()));
    gF->show();
    connect(gF, SIGNAL(windowTitleChanged(QString)), this, SLOT(CLEAR()));
}
