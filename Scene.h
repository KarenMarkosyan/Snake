#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QOpenGLShaderProgram>
#include "game.h"

/*!
 * \brief The scene class - класс виждета игры - осуществляет управление игровы процессом и его отображение
 */
class scene : public QOpenGLWidget
{
    Q_OBJECT

public:
    scene( QWidget *parent = 0 );
    ~scene();
    /*!
     * \brief setSize - передает основные игровые параметры объекту игры
     * \param wS - ширина поля
     * \param hS - высота поля
     * \param s  - временной промежуток обновления таймера
     * \param f  - карта препядствий
     */
    void setSize(int wS, int hS, int s, bool **f);
signals:
    /*!
     * \brief signalShowStatus - сигнал для передачи сообщеният в статусную строку
     * \param status - сообщение
     */
    void signalShowStatus( const QString &status );

private slots:
    /*!
     * \brief slotUpdate  - проверяет текущий статус игры
     */
    void slotUpdate();

private:
    /*!
     * \brief initializeGL - инициализация виджета
     */
    void initializeGL();
    /*!
     * \brief paintGL - отрисовка
     */
    void paintGL();
    /*!
     * \brief resizeGL - изменение размера виджета
     * \param w - ширина
     * \param h - высота
     */
    void resizeGL( int w, int h );
    /*!
     * \brief keyPressEvent - обработчик нажатия на клавиши
     * \param event - клавиша (Обрабатывает W,A,S,D,SPASE)
     */
    void keyPressEvent( QKeyEvent *event );

    /*!
     * \brief sendStatus передать размер змейки как сообщение в статусную строку
     */
    void sendStatus();

private:
    /*!
     * \brief m_game - указатель на игру
     */
    game *m_game;
    /*!
     * \brief m_timer - таймер обновления изображения
     */
    QTimer m_timer;
    /*!
     * \brief w - ширина поля в квадратах
     */
    float w;
    /*!
     * \brief h - высота поля в квадратах
     */
    float h;
    /*!
     * \brief m_program - шейдерная программа
     */
    QOpenGLShaderProgram m_program;
    /*!
     * \brief sp - частота обновления картинки
     */
    int sp;
};

#endif // SCENE_H
