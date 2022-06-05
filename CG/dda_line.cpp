#include <graphics.h>
#include <iostream>

using namespace std;

template <typename T = int> struct Point {
  T x;
  T y;
};

int main() {
  int gd = DETECT, gmode;
  Point one, two, difference;
  float step;
  Point<float> increment, plot_point;

  cout << "Enter the co-ordinates of the line you want to draw:->" << endl;
  cout << "X1, Y1: ";
  cin >> one.x;
  cin >> one.y;

  cout << "X2, Y2: ";
  cin >> two.x;
  cin >> two.y;

  difference.x = abs(two.x - one.x);
  difference.y = abs(two.y - one.y);

  cout << "Difference (X,Y): " << difference.x << " " << difference.y << endl;

  if (difference.x >= difference.y) {
    step = difference.x;
  } else {
    step = difference.y;
  }

  cout << "STEP: " << step << endl;

  increment.x = difference.x / step;
  increment.y = difference.y / step;

  cout << "INC: " << increment.x << " " << increment.y << endl;

  plot_point.x = one.x;
  plot_point.y = one.y;

  initgraph(&gd, &gmode, NULL);
  while (plot_point.x != two.x) {
    putpixel(abs(plot_point.x), abs(plot_point.y), 30);
    plot_point.x += increment.x;
    plot_point.y += increment.y;
  }

  delay(3600);
  closegraph();

  return 0;
}
