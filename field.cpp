#include <cstdlib>
#include <ctime>
#include "Field.h"
#include "Painter.h"

int Field::getW()
{
    return *wp;
}

int Field::getH()
{
    return *hp;
}

Field::Field(int w, int h, bool **f)
{
    this->h = h;
    this->w  = w;
    this->f  = f;
    wp = &this->w;
    hp = &this->h;

    m_m = new Type *[h];
    for (int i = 0; i < h; ++i)
        m_m[i] = new Type [w];

    for ( int y = 0; y < h; ++y ) {
        for ( int x = 0; x < w; ++x ) {
            m_m[y][x] = f[y][x] ? Field::BARRIER : Field::EMPTY;
        }
    }


    this->newO(FRUIT);
}

Field::~Field()
{
    for (int i = 0; i < h; ++i)
        delete[] m_m[i];
    delete[] m_m;
}

void Field::setBlock( Field::Type type, int x, int y )
{
    m_m[y][x] = type;
}

Field::Type Field::block( int x, int y ) const
{
    return m_m[y][x];
}

void Field::draw( Painter &p ) const
{
    for ( int y = 0; y < h; ++y ) {
        for ( int x = 0; x < w; ++x ) {
            switch ( m_m[y][x] ) {
            case Field::EMPTY:
                break;
            case Field::BARRIER:
                p.bar( x * Field::BLOCK_WIDTH,
                       y * Field::BLOCK_HEIGHT,
                       ( x + 1 ) * Field::BLOCK_WIDTH - 1,
                       ( y + 1 ) * Field::BLOCK_HEIGHT - 1 , false);
                break;
            case Field::SNAKE_BLOCK:
                p.bar( x * Field::BLOCK_WIDTH,
                       y * Field::BLOCK_HEIGHT,
                       ( x + 1 ) * Field::BLOCK_WIDTH - 1,
                       ( y + 1 ) * Field::BLOCK_HEIGHT - 1 , true);
                break;
            case Field::FRUIT:
                p.circle( x * Field::BLOCK_WIDTH + Field::BLOCK_WIDTH / 2,
                          y * Field::BLOCK_HEIGHT + Field::BLOCK_HEIGHT / 2,
                          Field::BLOCK_WIDTH / 2 - 1 );
            }
        }
    }
}

void Field::newO(Field::Type t)
{

    int x, y;
    std::srand( std::time( NULL ) );
    do {
        x = std::rand() % w;
        y = std::rand() % h;
    } while ( this->block( x, y ) != Field::EMPTY );
    this->setBlock( t, x, y );
}


void Field::clear()
{
    for ( int y = 0; y < h; ++y ) {
        for ( int x = 0; x < w; ++x ) {
           m_m[y][x] = f[y][x] ? Field::BARRIER : Field::EMPTY;
        }
    }

    this->newO(FRUIT);
}
int *Field::wp = 0;
int *Field::hp = 0;
