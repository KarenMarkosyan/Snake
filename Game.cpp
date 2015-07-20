#include "Game.h"
#include "Painter.h"
#include "Field.h"

Game::Game(int w, int h)
{
    m_field = new Field(w,h);
    m_snake = new Snake;
    m_maxSize = m_snake->maxSize();
    m_status = m_snake->status();
}

Game::~Game()
{
    delete m_snake;
    delete m_field;
}

void Game::draw( Painter &p ) const
{
    m_field->draw( p );
}

void Game::keyEvent( Snake::Direction d )
{
    m_snake->keyEvent( d );
}

size_t Game::snakeSize() const
{
    return m_snake->size();
}

size_t Game::snakeMaxSize() const
{
    return m_snake->maxSize();
}

void Game::newGame()
{
    delete m_snake;
    m_snake = new Snake();
    m_field->clear();
    m_maxSize = m_snake->maxSize();
    m_status = m_snake->status();
}

Snake::Status Game::status() const
{
    return m_status;
}

void Game::tick( )
{
    m_snake->tick( *m_field );
    Snake::Status status = m_snake->status();
    switch( status ) {
        case Snake::INCREASED:
            m_status = Snake::INCREASED;
            break;
        case Snake::LIVE:
            m_status = Snake::LIVE;
            break;
        case Snake::WIN:
            m_status = Snake::WIN;
            break;
        case Snake::DEAD:
            m_status = Snake::DEAD;
            break;
    }
}
