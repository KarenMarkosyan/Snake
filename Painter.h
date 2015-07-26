#ifndef PAINTER_H
#define PAINTER_H

#include <QOpenGLShaderProgram>
#include <vector>

/*!
 * \brief The painter class  - класс отображения обозначений на сцене
 */
class painter
{
public:
    /*!
     * \brief painter - конструктор
     * \param program - шейдерная программа
     */
    painter( QOpenGLShaderProgram *program );
    /*!
     * \brief bar - функция отрисовки квадрата заданного цвета в заданной позиции
     * \param x1 - горизонтальная координата левого верхнего угла
     * \param y1 - вертикальная координата левого верхнего угла
     * \param x2 - горизонтальная координата правого нижнего угла
     * \param y2 - вертикальная координата правого нижнего угла
     * \param isGreen - флаг цвета (если флаг поднят то отрисовывается зеленая фигура, иначе коричьневая)
     */
    void bar( int x1, int y1, int x2, int y2 , bool isGreen);
    /*!
     * \brief circle - функция отрисовки круга(ромба) красного цвета с заданым центром и радиусом
     * \param x - горизонтальная координата центра
     * \param y - вертикальная координата центра
     * \param radius - радиус
     */
    void circle( int x, int y, int radius );

private:
    /*!
     * \brief draw - функция отрисовки массива точек с заданным цветом
     * \param vertices - массив точек
     * \param colors - массив цветов (каждый цвет соответствует своей точке)
     */
    void draw( const std::vector<float> &vertices, const std::vector<float> &colors );
    /*!
     * \brief initGreenColor - функция инициализации зеленого цвета
     */
    void initGreenColor();
    /*!
     * \brief initRedColor - функция инициализации красного цвета
     */
    void initRedColor();
    /*!
     * \brief initBrownColor - функция инициализации коричневого цвета
     */
    void initBrownColor();
    /*!
     * \brief m_program - шейдерная программа (необходима для корректного отображения цветов)
     */
    QOpenGLShaderProgram *m_program;

    /*!
     * \brief m_verticesOfBar  - вектор точек для построения квадрата
     */
    std::vector<float> m_verticesOfBar;
    /*!
     * \brief m_verticesOfCircle - вектор точек для построения круга
     */
    std::vector<float> m_verticesOfCircle;
    /*!
     * \brief m_greenColor - цвета каждой из 18 точек (зеленый)
     */
    std::vector<float> m_greenColor;
    /*!
     * \brief m_brownColor - цвета каждой из 18 точек (коричьневый)
     */
    std::vector<float> m_brownColor;
    /*!
     * \brief m_redColor - цвета каждой из 18 точек (красный)
     */
    std::vector<float> m_redColor;
};

#endif // PAINTER_H
