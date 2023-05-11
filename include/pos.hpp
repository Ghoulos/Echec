#ifndef H_POS
#define H_POS

#include <iostream>
#include <memory>

using namespace std;

class Pos
{
private:
    int x;
    int y;
public:
    Pos(int x, int y);
    Pos(string);
    ~Pos();
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    bool operator==(const Pos &other) const;
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