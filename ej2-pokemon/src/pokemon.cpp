#include <SFML/Graphics.hpp>

using namespace std;

typedef unsigned char byt;

struct point {
  double x;
  double y;
};

typedef struct point Point;

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

int main() {
  int width = 1270;
  int height = 680;

  int image[height][width];

  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      image[y][x] = 0x000000FF;
    }
  }

  Point p1 = { 700, 400 };
  Point p2 = { 900, 200 };
  Point p3 = { 1100, 400 };
  vector<Point> ptsbezier = bezier(p1, p2, p3);

  for (Point p : ptsbezier) {
    image[(int)p.y][(int)p.x] = 0xFFFFFFFF;
  }


  Point p4 = { 100, 400 };
  Point p5 = { 300, 200 };
  Point p6 = { 500, 200 };
  Point p7 = { 700, 400 };
  // vector<Point> ptschaink0 = chaikin(p4, p5, p6, p7, 0);
  // vector<Point> ptschaink1 = chaikin(p4, p5, p6, p7, 1);
  // vector<Point> ptschaink2 = chaikin(p4, p5, p6, p7, 2);
  // vector<Point> ptschaink3 = chaikin(p4, p5, p6, p7, 3);
  vector<Point> ptschaink4 = chaikin(p4, p5, p6, p7, 4);

  for (Point p : ptschaink4) {
    image[(int)p.y][(int)p.x] = 0x00FFFFFF;
  }
  // for (Point p : ptschaink3) {
  //   image[(int)p.y][(int)p.x] = 0xFF00FFFF;
  // }
  // for (Point p : ptschaink2) {
  //   image[(int)p.y][(int)p.x] = 0x0000FFFF;
  // }
  // for (Point p : ptschaink1) {
  //   image[(int)p.y][(int)p.x] = 0xFF0000FF;
  // }
  // for (Point p : ptschaink0) {
  //   image[(int)p.y][(int)p.x] = 0x00FF00FF;
  // }


  byt data[height * width * 4];
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      int pixel = image[y][x];
      int index = 4 * ((y * width) + x);
      data[index + 0] = (pixel >> 24) & 0xFF;
      data[index + 1] = (pixel >> 16) & 0xFF;
      data[index + 2] = (pixel >> 8) & 0xFF;
      data[index + 3] = (pixel >> 0) & 0xFF;
    }
  }

  sf::Texture texture;
  texture.create(width, height);
  texture.update(data);

  sf::Sprite sprite(texture);

  sf::RenderWindow window(sf::VideoMode(width, height), "Pokemon");
  window.setFramerateLimit(144);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
        window.close();
      }

      window.clear();
      window.draw(sprite);
      window.display();
    }
  }

  return 0;
}
