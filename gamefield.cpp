#include "gamefield.h"
#include "ui_gamefield.h"

gameField::gameField(int w, int h, int s, bool **f, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameField)
{
    ui->setupUi(this);
    ui->fieldWidget->setSize(w, h, s, f);
    setGeometry(50,50,w*20, h*20);
    setWindowTitle("Змейка: " + QString::number(w) + " на " + QString::number(h) );
    QRect rect = frameGeometry();
    rect.moveCenter(QDesktopWidget().availableGeometry().center());
    move(rect.topLeft());
}

gameField::~gameField()
{

    delete ui->fieldWidget;
    delete ui;
}

void gameField::closeEvent(QCloseEvent *e)
{
    setWindowTitle("");
    QWidget::closeEvent(e);
}
