#include <vector>

using namespace std;

struct point {
  double x;
  double y;
};

typedef struct point Point;

Point lerp(Point p0, Point p1, double t);
vector<Point> bezier(Point p0, Point p1, Point p2);
vector<Point> chaikin(Point p1, Point p2, Point p3, Point p4, int steps);
vector<Point> bresenham(Point pi, Point pf);
