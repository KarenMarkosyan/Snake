#ifndef MENU_H
#define MENU_H

#include <QFile>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

#include "gamefield.h"
#include "ceratefield.h"

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

    void on_path_textChanged(const QString &arg1);
    
    void on_createField_clicked();
public slots:
    void closeEvent(QCloseEvent *e);
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
     * \brief board - карта поля
     */
    bool **board;
    /*!
     * \brief p - путь до файла доски
     */
    QString p;
    /*!
     * \brief mastLoadFromP  - Нужно загрузить из файла
     */
    bool mastLoadFromP;

    cerateField *c;
    /*!
     * \brief showHideOptions - показать/скрыть меню конфигураций
     * \param flag
     */
    void showHideOptions(bool flag);
    /*!
     * \brief readOptions - сохранить текущую конфигурацию
     */
    void readOptions();
    /*!
     * \brief load - загрузить поле из файла
     * \param file - имя файла
     * \return карта
     */
    bool ** load(QString file);


};

#endif // MENU_H
