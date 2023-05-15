#include "../include/pos.hpp"

Pos::Pos(int x = 0, int y = 0) 
    : x(x), y(y) {}

Pos::Pos(string couple){
    x = couple[0] - 'a';
    y = couple[1] - '0' - 1;
}
Pos::~Pos() {}

int Pos::getX() const { return this->x; }

int Pos::getY() const { return this->y; }

void Pos::setX(int x) { this->x = x; }

void Pos::setY(int y) { this->y = y; }

bool Pos::operator==(const Pos &other) const{
    return (this->x == other.getX() && this->y == other.getY());
}
