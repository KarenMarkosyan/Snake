#include <cstdlib>
#include <ctime>
#include "field.h"
#include "Painter.h"

int field::getW()
{
    return *wp;
}

int field::getH()
{
    return *hp;
}

field::field(int w, int h, bool **f)
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
            m_m[y][x] = (f != 0x0 && f[y][x]) ? field::BARRIER : field::EMPTY;
        }
    }


    this->newO(FRUIT);
}

field::~field()
{
    for (int i = 0; i < h; ++i)
        delete[] m_m[i];
    delete[] m_m;
}

void field::setBlock( field::Type type, int x, int y )
{
    m_m[y][x] = type;
}

field::Type field::block( int x, int y ) const
{
    return m_m[y][x];
}

void field::draw( painter &p ) const
{
    for ( int y = 0; y < h; ++y ) {
        for ( int x = 0; x < w; ++x ) {
            switch ( m_m[y][x] ) {
            case field::EMPTY:
                break;
            case field::BARRIER:
                p.bar( x * field::BLOCK_WIDTH,
                       y * field::BLOCK_HEIGHT,
                       ( x + 1 ) * field::BLOCK_WIDTH - 1,
                       ( y + 1 ) * field::BLOCK_HEIGHT - 1 , false);
                break;
            case field::SNAKE_BLOCK:
                p.bar( x * field::BLOCK_WIDTH,
                       y * field::BLOCK_HEIGHT,
                       ( x + 1 ) * field::BLOCK_WIDTH - 1,
                       ( y + 1 ) * field::BLOCK_HEIGHT - 1 , true);
                break;
            case field::FRUIT:
                p.circle( x * field::BLOCK_WIDTH + field::BLOCK_WIDTH / 2,
                          y * field::BLOCK_HEIGHT + field::BLOCK_HEIGHT / 2,
                          field::BLOCK_WIDTH / 2 - 1 );
            }
        }
    }
}

void field::newO(field::Type t)
{

    int x, y;
    std::srand( std::time( NULL ) );
    do {
        x = std::rand() % w;
        y = std::rand() % h;
    } while ( this->block( x, y ) != field::EMPTY );
    this->setBlock( t, x, y );
}


void field::clear()
{
    for ( int y = 0; y < h; ++y ) {
        for ( int x = 0; x < w; ++x ) {
           m_m[y][x] = (f != 0x0 && f[y][x]) ? field::BARRIER : field::EMPTY;
        }
    }

    this->newO(FRUIT);
}
int *field::wp = 0;
int *field::hp = 0;
