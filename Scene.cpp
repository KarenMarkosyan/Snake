#include <QMatrix4x4>
#include "scene.h"
#include "painter.h"

scene::scene( QWidget *parent ) :
    QOpenGLWidget( parent )
{
    this->setFocusPolicy( Qt::StrongFocus );
    w = 0;
    h = 0;

    connect( &m_timer, SIGNAL( timeout() ),
             this, SLOT( slotUpdate() ) );


}

scene::~scene()
{
    delete m_game;
}

void scene::setSize(int wS, int hS, int s, bool **f)
{
    sp = 100 * 10/s;
    m_game = new game(wS, hS, f);
    m_game->newGame();
    sendStatus();
    m_timer.start( sp );
    w = wS * 10.0f;
    h = hS * 10.0f;
    paintGL();
}

void scene::slotUpdate()
{
    snake::Status status = m_game->status();

    switch( status ) {
    case snake::LIVE:
        break;
    case snake::INCREASED:
        sendStatus();
        break;
    case snake::DEAD:
        m_timer.stop();
        sendStatus();
        break;
    case snake::WIN:
        m_timer.stop();
        sendStatus();
        return;
    }

    m_game->tick();
    update();
}

void scene::initializeGL()
{
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

    QOpenGLShader vShader( QOpenGLShader::Vertex );
    vShader.compileSourceFile( ":/Shaders/vShader.glsl" );

    QOpenGLShader fShader( QOpenGLShader::Fragment );
    fShader.compileSourceFile( ":/Shaders/fShader.glsl" );

    m_program.addShader( &vShader );
    m_program.addShader( &fShader );

    if ( !m_program.link() )
    {
        qWarning( "Error: unable to link a shader program" );
        return;
    }

}

void scene::paintGL()
{
    // Clear the window with current clearing color
    glClear( GL_COLOR_BUFFER_BIT );

    if ( !m_program.bind() )
        return;

    QMatrix4x4 matrix;
    matrix.ortho( 0.0f, w, h, 0.0f, -1.0f, 1.0f );
    //matrix.translate( 0.0f, 0.0f, -0.5f );
    m_program.setUniformValue( m_program.uniformLocation( "matrix" ), matrix );

    painter p(&m_program);

    if ( m_timer.isActive() ) {
        m_game->draw( p );
    }

    m_program.release();
}

void scene::resizeGL( int w, int h )
{
    glViewport( 0, 0, w, h );

}

void scene::keyPressEvent( QKeyEvent *event )
{
    switch ( event->key() ) {
    case Qt::Key_A:
        m_game->keyEvent( snake::LEFT );
        break;
    case Qt::Key_W:
        m_game->keyEvent( snake::UP );
        break;
    case Qt::Key_D:
        m_game->keyEvent( snake::RIGHT );
        break;
    case Qt::Key_S:
        m_game->keyEvent( snake::DOWN );
        break;
    case Qt::Key_Space:
        m_game->newGame();
        sendStatus();
        m_timer.start( sp );
        break;
    }
}

void scene::sendStatus()
{
    if (m_game->status() == snake::WIN)
        emit signalShowStatus("Вы выйграли!");
    else if (m_game->status() == snake::DEAD){
        emit signalShowStatus("Змейка умерла!");
    }
}
