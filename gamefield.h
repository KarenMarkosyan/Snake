#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QWidget>
#include <QRect>
#include <QDesktopWidget>

namespace Ui {
class gameField;
}

class gameField : public QWidget
{
    Q_OBJECT

public:
    explicit gameField(int w, int h, int s, bool **f = 0, QWidget *parent = 0);
    ~gameField();

private:
    Ui::gameField *ui;
private slots:
    void closeEvent(QCloseEvent *e);
};

#endif // GAMEFIELD_H
