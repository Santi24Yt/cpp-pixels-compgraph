#include <SFML/Graphics.hpp>
#include "lines.h"

using namespace std;

typedef unsigned char byt;

int main() {
  const int width = 1270;
  const int height = 680;

  int image[height][width];

  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      image[y][x] = 0x000000FF;
    }
  }

  // Point p1 = { 700, 400 };
  // Point p2 = { 900, 200 };
  // Point p3 = { 1100, 400 };
  // vector<Point> ptsbezier = bezier(p1, p2, p3);
  //
  // for (Point p : ptsbezier) {
  //   image[(int)p.y][(int)p.x] = 0xFFFFFFFF;
  // }
  //
  //
  // Point p4 = { 100, 400 };
  // Point p5 = { 300, 200 };
  // Point p6 = { 500, 200 };
  // Point p7 = { 700, 400 };
  // // vector<Point> ptschaink0 = chaikin(p4, p5, p6, p7, 0);
  // // vector<Point> ptschaink1 = chaikin(p4, p5, p6, p7, 1);
  // // vector<Point> ptschaink2 = chaikin(p4, p5, p6, p7, 2);
  // // vector<Point> ptschaink3 = chaikin(p4, p5, p6, p7, 3);
  // vector<Point> ptschaink4 = chaikin(p4, p5, p6, p7, 4);
  //
  // for (Point p : ptschaink4) {
  //   image[(int)p.y][(int)p.x] = 0x00FFFFFF;
  // }
  // // for (Point p : ptschaink3) {
  // //   image[(int)p.y][(int)p.x] = 0xFF00FFFF;
  // // }
  // // for (Point p : ptschaink2) {
  // //   image[(int)p.y][(int)p.x] = 0x0000FFFF;
  // // }
  // // for (Point p : ptschaink1) {
  // //   image[(int)p.y][(int)p.x] = 0xFF0000FF;
  // // }
  // // for (Point p : ptschaink0) {
  // //   image[(int)p.y][(int)p.x] = 0x00FF00FF;
  // // }
  // 
  // Point p8 = { 100, 100 };
  // Point p9 = { 400, 100 };
  // vector<Point> ptsbresen = bresenham(p8, p9);
  //
  // for (Point p : ptsbresen) {
  //   image[(int)p.y][(int)p.x] = 0x0FF0000FF;
  // }
  // image[(int)p8.y][(int)p8.x] = 0x0000FFFF;
  // image[(int)p9.y][(int)p9.x] = 0x0000FFFF;
  //
  // for (int i = 0; i < 10; i++) {
  //   int x1 = rand() % 1270;
  //   int y1 = rand() % 680;
  //   Point pb1;
  //   pb1.x = x1;
  //   pb1.y = y1;
  //   int x2 = rand() % 1270;
  //   int y2 = rand() % 680;
  //   Point pb2;
  //   pb2.x = x2;
  //   pb2.y = y2;
  //
  //   vector<Point> ptsbres = bresenham(pb1, pb2);
  //   for (Point p : ptsbres) {
  //     image[(int)p.y][(int)p.x] = 0x0FF0000FF;
  //   }
  //   image[(int)pb1.y][(int)pb1.x] = 0x0000FFFF;
  //   image[(int)pb2.y][(int)pb2.x] = 0x0000FFFF;
  // }
  //
  // srand(time(NULL));
  //
  // vector<Point> poly;
  // for (int i = 0; i < 10; i++) {
  //   int x1 = rand() % 1270;
  //   int y1 = rand() % 680;
  //   Point pp1;
  //   pp1.x = x1;
  //   pp1.y = y1;
  //   poly.push_back(pp1);
  // }
  //
  // polyfill(poly, image, 0xFFFF00FF);
  // for (Point p : poly) {
  //   image[(int)p.y][(int)p.x] = 0xFF00FFFF;
  // }
  // image[(int)poly[0].y][(int)poly[0].x] = 0xFF0000FF;
  // image[(int)poly[poly.size()-1].y][(int)poly[poly.size()-1].x] = 0x00FF00FF;
  //
  // Point p10 = { 883, 615 };
  // Point p11 = { 1126, 252 };
  // vector<Point> ptsbresen2 = bresenham(p10, p11);
  //
  // for (Point p : ptsbresen2) {
  //   image[(int)p.y][(int)p.x] = 0x0FF0000FF;
  // }
  // image[(int)p10.y][(int)p10.x] = 0x0000FFFF;
  // image[(int)p11.y][(int)p11.x] = 0x0000FFFF;
  //
  // vector<Point> poly2 = { {10, 11}, {40, 15}, {45, 50}, {20, 52} };
  // polyfill(poly2, image, 0x00FF00FF);

  vector<Point> pokemonbres = {
    {94, 83},
    {122, 70},
    {122, 101},
    {96, 140},
    {69, 185},
    {61, 248},
    {92, 280},
    {166, 269},
    {199, 248},
    {216, 212},
    {248, 185},
    {272, 170},
    {282, 150},
    {248, 153},
    {222, 143},
    {206, 122},
    {203, 87},
    {201, 71},
    {213, 62},
    {251, 27},
    {285, 19},
    {318, 2},
    {334, 35},
    {350, 67},
    {347, 97},
    {332, 125},
    {346, 159},
    {378, 180},
    {388, 202},
    {351, 189},
    {333, 254},
    {336, 283},
    {327, 305},
    {312, 324},
    {308, 424},
    {290, 445},
    {272, 430},
    {277, 373},
    {290, 319},
    {295, 314},
    {287, 302},
    {265, 302},
    {241, 290},
    {211, 301},
    {131, 384},
    {104, 384},
    {103, 361},
    {185, 295},
    {197, 289},
    {197, 277},
    {164, 295},
    {92, 301},
    {52, 277},
    {41, 231},
    {52, 182},
    {67, 126}
  };
  polyfill(pokemonbres, image, 0xFF0000FF);
  vector<Point> pokemonchaink(pokemonbres.size());
  for (int i = 0; i < (int)pokemonbres.size(); i++) {
    pokemonchaink[i].x = pokemonbres[i].x + 400;
    pokemonchaink[i].y = pokemonbres[i].y;
  }
  polychaink(pokemonchaink, image, 0x00FF00FF, 4);


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
