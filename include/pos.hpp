#ifndef H_POS
#define H_POS

class Pos
{
private:
    int x;
    int y;
public:
    Pos(int x, int y);
    ~Pos();
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
};

class Dir : public Pos
{
private:
    /* data */
public:
    Dir(int, int);
    ~Dir();
};

#endif