#include "fruit.h"
#include "field.h"

fruit::fruit( int x, int y ) :
    m_x( x ),
    m_y( y )
{
}

bool fruit::draw( field &f ) const
{
    if ( f.block( m_x, m_y ) != field::EMPTY ) {
        return false;
    }
    f.setBlock( field::FRUIT, m_x, m_y );
    return true;
}
