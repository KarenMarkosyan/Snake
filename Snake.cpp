#include <cstdlib>
#include <ctime>
#include "snake.h"
#include "field.h"

snake::snake()
{
    m_status = snake::LIVE;
    m_maxSize = (field::getW() + field::getH()) / 2;
    std::srand( std::time( NULL ) );
    std::rand();
    m_direction = static_cast<snake::Direction>( std::rand() % 4 );
    m_blocks.push_back( std::pair<int, int>( field::getW() / 2,
                                             field::getH() / 2 ) );
}

snake::Status snake::status() const
{
    return m_status;
}

void snake::tick(field &f )
{
    std::pair<int, int> p = m_blocks.front();
    switch ( m_direction ) {
        case snake::LEFT:
            --( p.first );
            break;
        case snake::UP:
            --( p.second );
            break;
        case snake::RIGHT:
            ++( p.first );
            break;
        case snake::DOWN:
            ++( p.second );
            break;
    }

    if ( ( p.first < 0 ) || ( p.first >= field::getW() ) ||
         ( p.second < 0) || ( p.second >= field::getH() ) ) {
        m_status = snake::DEAD;
        return;
    }

    if ( f.block( p.first, p.second ) == field::snake_BLOCK || f.block( p.first, p.second ) == field::BARRIER) {
        m_status = snake::DEAD;
        return;
    }

    m_blocks.push_front( p );

    if ( f.block( p.first, p.second ) != field::FRUIT ) {
        f.setBlock( field::snake_BLOCK, p.first, p.second );
        std::pair<int, int> p = m_blocks.back();
        f.setBlock( field::EMPTY, p.first, p.second );
        m_blocks.pop_back();
        m_status = snake::LIVE;
    } else {
        f.setBlock( field::snake_BLOCK, p.first, p.second );
        f.newO(field::FRUIT);
        f.newO(field::BARRIER);
        m_status = snake::INCREASED;
    }

    if ( m_blocks.size() == m_maxSize ) {
        m_status = snake::WIN;
        return;
    }
}

void snake::keyEvent( snake::Direction d )
{
    if ( d == m_direction ) {
        return;
    }

    switch ( d ) {
        case snake::LEFT:
            if ( m_direction == snake::RIGHT ) {
                return;
            }
            break;
        case snake::UP:
            if ( m_direction == snake::DOWN ) {
                return;
            }
            break;
        case snake::RIGHT:
            if ( m_direction == snake::LEFT ) {
                return;
            }
            break;
        case snake::DOWN:
            if ( m_direction == snake::UP ) {
                return;
            }
            break;
    }

    m_direction = d;
}

size_t snake::maxSize() const
{
    return m_maxSize;
}

size_t snake::size() const
{
    return m_blocks.size();
}
