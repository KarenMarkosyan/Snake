#ifndef SNAKE_H
#define SNAKE_H

#include <cstddef>
#include <list>
#include <utility>

class field;

/*!
 * \brief The snake class - класс змейки
 */
class snake
{
public:
    /*!
     * \brief The Status enum - перечисление статусов змейки
     */
    enum Status { INCREASED, LIVE, WIN, DEAD };
    /*!
     * \brief The Direction enum - типы управляющих сигналов
     */
    enum Direction { LEFT, UP, RIGHT, DOWN };
    /*!
     * \brief snake - конструктор по умолчанию
     */
    snake();
    /*!
     * \brief tick - обработчик таймера
     * \param f - ссылка на поле на котором находится змея
     */
    void tick(field & f);
    /*!
     * \brief keyEvent - обработчик управляющего сигнала
     */
    void keyEvent( Direction );
    /*!
     * \brief size - получить текущий размер
     * \return - размер
     */
    size_t size() const;
    /*!
     * \brief maxSize - получить максимальный размер
     * \return размер
     */
    size_t maxSize() const;
    /*!
     * \brief status - получить текущий статус змейки
     * \return - статус
     */
    snake::Status status() const;

private:
    /*!
     * \brief Blocks - переименованный тип туловища змейки
     */
    typedef std::list< std::pair<int, int> > Blocks;
    /*!
     * \brief m_blocks - список блоков являющихся частью туловища змейки
     */
    Blocks m_blocks;
    /*!
     * \brief m_direction - текущий управляющий сигнал (показывает направление движения)
     */
    Direction m_direction;
    /*!
     * \brief m_status - текущий статус змейки
     */
    snake::Status m_status;
    /*!
     * \brief m_maxSize максимальный размер змейки
     */
    size_t m_maxSize;
};

#endif // SNAKE_H
