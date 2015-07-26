#include <QMatrix4x4>
#include "Scene.h"
#include "Painter.h"

Scene::Scene( QWidget *parent ) :
    QOpenGLWidget( parent ),
    m_maxSize( 0 )
{
    this->setFocusPolicy( Qt::StrongFocus );
    w = 0;
    h = 0;

    connect( &m_timer, SIGNAL( timeout() ),
             this, SLOT( slotUpdate() ) );


}

Scene::~Scene()
{
    delete m_game;
}

void Scene::setSize(int wS, int hS, int s, bool **f)
{
    sp = 100 * 10/s;
    m_game = new Game(wS, hS, f);
    m_maxSize = m_game->snakeMaxSize();
    m_game->newGame();
    sendStatus();
    m_timer.start( sp );
    w = wS * 10.0f;
    h = hS * 10.0f;
    paintGL();
}

void Scene::slotUpdate()
{
    Snake::Status status = m_game->status();

    switch( status ) {
        case Snake::LIVE:
            break;
        case Snake::INCREASED:
            sendStatus();
            break;
        case Snake::DEAD:
            m_game->newGame();
            sendStatus();
            break;
        case Snake::WIN:
            m_timer.stop();
            sendStatus();
            return;
    }

    m_game->tick();
    update();
}

void Scene::slotSnakeSize( size_t size )
{
    QString status = QString::number( size );
}

void Scene::initializeGL()
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

    m_vertexAttr = m_program.attributeLocation( "vertexAttr" );
    m_colorAttr = m_program.attributeLocation( "colorAttr" );
    m_matrixUniform = m_program.uniformLocation( "matrix" );
}

void Scene::paintGL()
{
    // Clear the window with current clearing color
    glClear( GL_COLOR_BUFFER_BIT );

    if ( !m_program.bind() )
        return;

    QMatrix4x4 matrix;
    matrix.ortho( 0.0f, w, h, 0.0f, -1.0f, 1.0f );
    //matrix.translate( 0.0f, 0.0f, -0.5f );
    m_program.setUniformValue( m_matrixUniform, matrix );

    Painter p( &m_program, m_vertexAttr, m_colorAttr );

    if ( m_timer.isActive() ) {
        m_game->draw( p );
    }

    m_program.release();
}

void Scene::resizeGL( int w, int h )
{
    glViewport( 0, 0, w, h );

}

void Scene::keyPressEvent( QKeyEvent *event )
{
    switch ( event->key() ) {
        case Qt::Key_A:
            m_game->keyEvent( Snake::LEFT );
            break;
        case Qt::Key_W:
            m_game->keyEvent( Snake::UP );
            break;
        case Qt::Key_D:
            m_game->keyEvent( Snake::RIGHT );
            break;
        case Qt::Key_S:
            m_game->keyEvent( Snake::DOWN );
            break;
        case Qt::Key_Space:
            m_game->newGame();
            sendStatus();
            m_timer.start( sp );
            break;
    }
}

void Scene::sendStatus()
{
    size_t points = m_game->snakeSize();
    emit signalShowStatus( QString( "%1/%2" ).arg( points ).arg( m_maxSize ) );
}
