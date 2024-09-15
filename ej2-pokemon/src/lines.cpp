#include "lines.h"

using namespace std;

Point lerp(Point p0, Point p1, double t) {
  Point pt;
  pt.x = ((1-t) * p0.x) + (t*p1.x);
  pt.y = ((1-t) * p0.y) + (t*p1.y);

  return pt;
}

vector<Point> bezier(Point p0, Point p1, Point p2) {
  vector<Point> pts(1000);

  for (int t = 0; t < 1000; t++) {
    Point p11 = lerp(p0, p1, (double)t/1000.0);
    Point p12 = lerp(p1, p2, (double)t/1000.0);
    Point p22 = lerp(p11, p12, (double)t/1000.0);
    pts[t] = p22;
  }

  return pts;
}

vector<Point> chaikin(Point p1, Point p2, Point p3, Point p4, int steps) {
  vector<Point> pts;
  pts.push_back(p1);
  pts.push_back(p2);
  pts.push_back(p3);
  pts.push_back(p4);
  for (int i = 0; i < steps; i++) {
    vector<Point> npts;
    npts.push_back(p1);
    for (int j = 0; j < (int)pts.size() - 1; j++) {
      Point p11 = lerp(pts[j], pts[j+1], 0.25);
      Point p22 = lerp(pts[j], pts[j+1], 0.75);
      npts.push_back(p11);
      npts.push_back(p22);
    }
    npts.push_back(p4);
    pts = npts;
  }
  int ptsmax = 1000/(int)pts.size();
  int ptssizeog = pts.size();
  for (int i = 0; i < ptssizeog - 1; i++) {
    for (int t = 0; t < ptsmax; t++) {
      Point pn = lerp(pts[i], pts[i+1], (double)t/(double)ptsmax);
      pts.push_back(pn);
    }
  }
  return pts;
}

vector<Point> _bresenhamH(Point pi, Point pf) {
  vector<Point> pts;

  if (pi.x > pf.x) {
    Point t = pi;
    pi = pf;
    pf = t;
  }
  
  int dx = pf.x - pi.x;
  int dy = pf.y - pi.y;
  int dir = 1;
  if (dy < 0)
    dir = -1;
  dy *= dir;

  int D = 2*dy - dx;

  int y = pi.y;
  int x;

  for (int i = 0; i <= dx; i++) {
    x = pi.x + i;
    Point pr;
    pr.x = x;
    pr.y = y;
    pts.push_back(pr);

    if (D >= 0) {
      y += dir;
      D = D - 2*dx;
    }
    D = D + 2*dy;
  }

  return pts;
}

vector<Point> _bresenhamV(Point pi, Point pf) {
  vector<Point> pts;

  if (pi.y > pf.y) {
    Point t = pi;
    pi = pf;
    pf = t;
  }
  
  int dx = pf.x - pi.x;
  int dy = pf.y - pi.y;
  int dir = 1;
  if (dy < 0)
    dir = -1;
  dx *= dir;

  int D = 2*dx - dy;

  int y;
  int x = pi.x;

  for (int i = 0; i <= dy; i++) {
    y = pi.y + i;
    Point pr;
    pr.x = x;
    pr.y = y;
    pts.push_back(pr);

    if (D >= 0) {
      x += dir;
      D = D - 2*dy;
    }
    D = D + 2*dx;
  }

  return pts;
}

double absd(double n) {
  if (n >= 0) {
    return n;
  } else {
    return -n;
  }
}

vector<Point> bresenham(Point pi, Point pf) {
  vector<Point> pts;
  if (absd(pf.x - pi.x) > absd(pf.y - pi.y)) {
    pts = _bresenhamH(pi, pf);
  } else {
    pts = _bresenhamV(pi, pf);
  }

  return pts;
}
