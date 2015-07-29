#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QWidget>
#include <QRect>
#include <QDesktopWidget>
#include <QMessageBox>

namespace Ui {
class gameField;
}
/*!
 * \brief The gameField class - класс окна игры
 */
class gameField : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief gameField - создает игры по переданным конфигурациям
     * \param w - ширина поля
     * \param h - высота поля
     * \param s - скорость игры
     * \param f - заданные препядствия
     * \param parent - родительский виджет
     */
    explicit gameField(int w, int h, int s, bool **f = 0, QWidget *parent = 0);
    ~gameField();

private:
    Ui::gameField *ui;
private slots:
    /*!
     * \brief closeEvent - перехватчик закрытия окна
     * \param e - событие закрытия
     */
    void closeEvent(QCloseEvent *e);
    void mess(QString s);
};

#endif // GAMEFIELD_H
