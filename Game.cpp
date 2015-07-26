#include "game.h"
#include "painter.h"
#include "field.h"

game::game(int w, int h, bool **f)
{
    m_field = new field(w,h,f);
    m_snake = new snake;
    m_status = m_snake->status();
}

game::~game()
{
    delete m_snake;
    delete m_field;
}

void game::draw( painter &p ) const
{
    m_field->draw( p );
}

void game::keyEvent( snake::Direction d )
{
    m_snake->keyEvent( d );
}

size_t game::snakeSize() const
{
    return m_snake->size();
}

size_t game::snakeMaxSize() const
{
    return m_snake->maxSize();
}

void game::newGame()
{
    delete m_snake;
    m_snake = new snake();
    m_field->clear();
    m_status = m_snake->status();
}

snake::Status game::status() const
{
    return m_snake->status();
}

void game::tick( )
{
    m_snake->tick( *m_field );
}
