#include <iostream>
#include <math.h>

struct ParameterData {
    
};

void calculate(int *pk, int dx, int dy, int *x, int *y) {
    int pk_plus_one;

    ++(*x);
    if(*pk < 0) {
        *pk = *pk + (2*dy);
    } else if(*pk > 0) {
        *pk = *pk + (2*dy) - (2*dx);
        ++(*y);
    }
};

int main() {
    int x, y, x1=200, y1=100, x2=300, y2=180;
    int pk, dx, dy;

    dx = x2 - x1;
    dy = y2 - y1;

    pk = (2*dy) - dx;
    x = x1;
    y = y1;

    while(x<=x2 && y<=y2) {
        std::cout << "X: " << x << " Y: " << y << std::endl;
        calculate(&pk, dx, dy, &x, &y);
    }
}
