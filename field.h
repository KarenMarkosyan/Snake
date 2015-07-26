#ifndef FIELD_H
#define FIELD_H

class painter;

/*!
 * \brief The field class - класс описывает модель поля
 */
class field
{
public:
    /*!
     * \brief getW - получить ширину последнего созданного поля
     * \return ширина
     */
    static int getW();
    /*!
     * \brief getH - получить высоту последнего созданного поля
     * \return высота
     */
    static int getH();
    /*!
     * \brief BLOCK_WIDTH - ширина одного блока изображения
     */
    const int BLOCK_WIDTH = 10;
    /*!
     * \brief BLOCK_HEIGHT - высота одного блока изображения
     */
    const int BLOCK_HEIGHT = 10;
    /*!
     * \brief The Type enum - тип блока (Пустое поле, часть змеи, фрукт, препядствие)
     */
    enum Type { EMPTY, SNAKE_BLOCK, FRUIT, BARRIER};
    /*!
     * \brief field - строит поле заданного размера с заданым набором препядствий
     * \param w - ширина
     * \param h - высота
     * \param f - ката препядствий
     */
    field(int w, int h, bool **f);
    ~field();
    /*!
     * \brief setBlock - задать значение блока
     * \param type - тип блока
     * \param x - положение по горизонтали
     * \param y - положение по вертикали
     */
    void setBlock( Type type, int x, int y );
    /*!
     * \brief block - получить значение блока
     * \param x - положение по горизонтали
     * \param y - положение по вертикали
     * \return - тип блока
     */
    Type block( int x, int y ) const;
    /*!
     * \brief draw - отображает заданный приметив на поле
     * \param p - приметив
     */
    void draw(painter &p ) const;
    /*!
     * \brief newO - создает новый объект заданого типа в случайной позиции
     * \param t - тип
     */
    void newO(Type t);
    /*!
     * \brief clear - отчишает поле
     */
    void clear();

private:
    /*!
     * \brief m_m - массив значений поля
     */
    Type **m_m;
    /*!
     * \brief f - карта поля (изначальная)
     */
    bool **f;
    /*!
     * \brief w - ширина
     */
    int  w;
    /*!
     * \brief h - высота
     */
    int  h;
    /*!
     * \brief wp - указатель на ширину последнего созданного поля
     */
    static int *wp;
    /*!
     * \brief hp - указательна высоту последнего созданного поля
     */
    static int *hp;
};


#endif // FIELD_H
