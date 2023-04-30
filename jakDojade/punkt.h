#pragma once
struct punkt {
    int y, x;

    punkt() : y(0), x(0) {};

    punkt(int y, int x) : y(y), x(x) {};

    bool operator==(punkt drugi) const {
        return x == drugi.x && y == drugi.y;
    }

    punkt operator+(punkt drugi) const {

        return { y + drugi.y, x + drugi.x };

    }

    void operator+=(punkt drugi) {
        y += drugi.y;
        x += drugi.x;
    }
};