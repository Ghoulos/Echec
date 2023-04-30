#include "../include/pos.hpp"

Pos::Pos(int x = 0, int y = 0) 
    : x(x), y(y) {}

Pos::~Pos() {}

int Pos::getX() const { return this->x; }

int Pos::getY() const { return this->y; }

void Pos::setX(int x) { this->x = x; }

void Pos::setY(int y) { this->y = y; }

Dir::Dir(int x = 0, int y = 0)
    : Pos(x, y)  {}

Dir::~Dir() {}