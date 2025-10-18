#include <iostream>
#include <vector>
#include <string>
#include "Point.h"
#include "Square.h"

Point::Point(int px, int py) : x(px), y(py) {}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setX(int newX) {
    x = newX;
}

void Point::setY(int newY) {
    y = newY;
}

Square::Square(const std::string n, int px, int py, unsigned int s)
    : Point(px, py), name(n), side(s) {
    area = side * side;
}

unsigned int Square::getSide() const {
    return side;
}

unsigned int Square::getArea() const {
    return area;
}

std::string Square::getName() const {
    return name;
}

void Square::setSide(unsigned int newSide) {
    side = newSide;
    area = side * side;
}

void Square::setArea(unsigned int newArea) {
    area = newArea;
}

void Square::setName(std::string newName) {
    name = newName;
}

// 두 Square 객체를 교환하는 함수
void swapSquares(Square& a, Square& b) {
    Square temp = a;
    a = b;
    b = temp;
}

int main() {
    using namespace std;

    int n;
    cin >> n;

    vector<Square> squares;
    for (int i = 0; i < n; ++i) {
        string name;
        int x, y;
        unsigned int side;
        cin >> name >> x >> y >> side;
        squares.push_back(Square(name, x, y, side));
    }

    cout << "\nSquares in increasing order of area" << endl;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (squares[j].getArea() > squares[j + 1].getArea()) {
                swapSquares(squares[j], squares[j + 1]);
            }
        }
    }

    for (const auto& s : squares) {
        cout << s.getName() << "(" << s.getX() << ", " << s.getY() << ") "
            << "side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    cout << "\nSquares in increasing order of max x-coordinate" << endl;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if ((squares[j].getX() + squares[j].getSide()) > (squares[j + 1].getX() + squares[j + 1].getSide())) {
                swapSquares(squares[j], squares[j + 1]);
            }
        }
    }

    for (const auto& s : squares) {
        cout << s.getName() << "(" << s.getX() + s.getSide() << ", " << s.getY() << ") "
            << "side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    cout << "\nSquares in increasing order of max y-coordinate" << endl;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if ((squares[j].getY() + squares[j].getSide()) > (squares[j + 1].getY() + squares[j + 1].getSide())) {
                swapSquares(squares[j], squares[j + 1]);
            }
        }
    }

    for (const auto& s : squares) {
        cout << s.getName() << "(" << s.getX() << ", " << s.getY() + s.getSide() << ") "
            << "side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    return 0;
}