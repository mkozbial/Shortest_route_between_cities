#pragma once
struct punkt {
    int y, x, dystans;

    punkt() : y(0), x(0), dystans(0) {};

    punkt(int x, int y) : x(x), y(y), dystans(0){};

    punkt(int x, int y, int dystans) : x(x), y(y), dystans(dystans) {};

    bool operator==(punkt drugi) const {
        return x == drugi.x && y == drugi.y && dystans == drugi.dystans;
    }

    punkt operator+(punkt drugi) const {

        return { y + drugi.y, x + drugi.x, dystans + drugi.dystans };

    }

    void operator+=(punkt drugi) {
        y += drugi.y;
        x += drugi.x;
        dystans += drugi.dystans;
    }

    int getX() const {
		return x;
	}

    int getY() const {
		return y;
	}

    int getDystans() const {
        return dystans;
    }
};