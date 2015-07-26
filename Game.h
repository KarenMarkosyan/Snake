#ifndef GAME_H
#define GAME_H

#include <cstddef>
#include "snake.h"
#include "field.h"

class painter;

/*!
 * \brief The game class - класс игры (отвечает за всю внутреигровую механику)
 */
class game
{
public:
    /*!
     * \brief game конструктор, который создает игру с полем заданого размера и заданной фактуры
     * \param w - ширина
     * \param h - высота
     * \param f - карта препядствий
     */
    game(int w, int h, bool **f);
    ~game();
    /*!
     * \brief newGame - начинает новую игру на проинициализированном поле
     */
    void newGame();
    /*!
     * \brief tick - обрабатывает каждое новое срабатывание таймера
     */
    void tick();
    /*!
     * \brief draw - рисует на поле обект класса painter(примитив)
     * \param p - отображаемый примитив
     */
    void draw( painter &p ) const;
    /*!
     * \brief keyEvent - передает змейки управляющий сигнал
     */
    void keyEvent( snake::Direction );
    /*!
     * \brief status - получает статус игры
     * \return
     */
    snake::Status status() const;
    /*!
     * \brief snakeSize - получает текущий размер змеи
     * \return - размер
     */
    size_t snakeSize( ) const;
    /*!
     * \brief snakeMaxSize - получает максимальный размер змеии
     * \return - размер
     */
    size_t snakeMaxSize( ) const;

private:
    /*!
     * \brief m_field - указатель на поеле игры
     */
    field *m_field;
    /*!
     * \brief m_snake - указатель на змейку
     */
    snake *m_snake;
    /*!
     * \brief m_status - теукущий игровой статус
     */
    snake::Status m_status;
};

#endif // GAME_H
