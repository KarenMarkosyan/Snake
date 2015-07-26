#ifndef FRUIT_H
#define FRUIT_H

class field;
/*!
 * \brief The fruit class - класс описывающий фрукт
 */
class fruit
{
public:
    /*!
     * \brief fruit - создает фрукт с задаными координатами
     * \param x
     * \param y
     */
    fruit( int x = 0, int y = 0 );
    /*!
     * \brief draw - отображает фрукт на поле
     * \return успешность
     */
    bool draw( field & ) const;

private:
    /*!
     * \brief m_x - горизонтальная координата
     */
    const int m_x;
    /*!
     * \brief m_y - вертикальная координата
     */
    const int m_y;
};

#endif // FRUIT_H
