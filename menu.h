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
    /*!
     * \brief h - высота
     */
    int h;
    /*!
     * \brief w - ширина
     */
    int w;
    /*!
     * \brief s - скорость
     */
    int s;
    /*!
     * \brief isPause - пауза
     */
    bool isPause;
    /*!
     * \brief isOptions - открыто меню конфигураций
     */
    bool isOptions;
    /*!
     * \brief gF - указатель на игровой виджет
     */
    gameField *gF;
    /*!
     * \brief showHideOptions - показать/скрыть меню конфигураций
     * \param flag
     */
    showHideOptions(bool flag);
    /*!
     * \brief readOptions - сохранить текущую конфигурацию
     */
    readOptions();
    /*!
     * \brief load - загрузить поле из файла
     * \param file - имя файла
     * \return карта
     */
    bool ** load(QString file);
};

#endif // MENU_H
