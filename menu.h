#ifndef MENU_H
#define MENU_H

#include <QFile>
#include <QMainWindow>

#include "gamefield.h"

namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();

private slots:
    void on_options_clicked();

    void on_save_clicked();

    void on_cancell_clicked();

    void on_newGame_clicked();

    void on_loard_clicked(bool checked);

    void CLEAR();

    void on_couse_clicked();

private:
    Ui::menu *ui;
    //Текущее конфигурации
    int h; //Высота
    int w; //Ширина
    int s; //Скорость
    //
    bool isPause;
    bool isOptions;
    gameField *gF;
    showHideOptions(bool flag);
    readOptions();
    bool ** load(QString file);
};

#endif // MENU_H
