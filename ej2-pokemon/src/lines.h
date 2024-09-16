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

template <size_t width, size_t height>
void polyfill(vector<Point> pts, int (&img)[height][width], int c) {
  int n = (int)pts.size() - 1;
  for (int i = 0; i < n; i++) {
    vector<Point> line = bresenham(pts[i], pts[i+1]);
    for (Point p : line) {
      if (p.x < width && p.y < height && p.x >= 0 && p.y >= 0)
        img[(int)p.y][(int)p.x] = c;
    }
  }

  vector<Point> fline = bresenham(pts[0], pts[pts.size()-1]);
  for (Point p : fline) {
    if (p.x < width && p.y < height && p.x >= 0 && p.y >= 0)
      img[(int)p.y][(int)p.x] = c;
  }
}
