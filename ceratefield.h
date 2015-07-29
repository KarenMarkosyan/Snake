#ifndef CERATEFIELD_H
#define CERATEFIELD_H

#include <QDialog>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

namespace Ui {
class cerateField;
}

class cerateField : public QDialog
{
    Q_OBJECT

public:
    explicit cerateField(QWidget *parent = 0);
    ~cerateField();

private slots:
    void on_cansle_clicked();

    void on_next_clicked();

    void on_dir_textChanged(const QString &arg1);

    void on_name1_textChanged(const QString &arg1);

    void on_w_valueChanged(int arg1);

    void on_h_valueChanged(int arg1);

    void on_table_cellClicked(int row, int column);

    void on_cDir_clicked();

public slots:
    void closeEvent(QCloseEvent *e);

private:
    Ui::cerateField *ui;
    QWidget *parentW;
    bool isCreate;
    void setTable();
};

#endif // CERATEFIELD_H
