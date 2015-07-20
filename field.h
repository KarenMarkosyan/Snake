#ifndef FIELD_H
#define FIELD_H

class Painter;

class Field
{
public:
    static int getW();
    static int getH();
    enum { BLOCK_WIDTH = 10, BLOCK_HEIGHT = 10 };
    enum Type { EMPTY, SNAKE_BLOCK, FRUIT, BARRIER};
    Field(int w, int h);
    ~Field();
    void setBlock( Type type, int x, int y );
    Type block( int x, int y ) const;
    void draw( Painter &p ) const;
    void newO(Type t);
    void clear();

private:
    Type **m_m;
    int  w;
    int  h;
    static int *wp;
    static int *hp;
};


#endif // FIELD_H
