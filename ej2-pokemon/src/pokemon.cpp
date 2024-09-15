#include <SFML/Graphics.hpp>

using namespace std;

typedef unsigned char byt;

struct punto {
  int x;
  int y;
};

struct punto lerp(struct punto p0, struct punto p1, double t) {
  struct punto pt;
  pt.x = ((1-t) * p0.x) + (t*p1.x);
  pt.y = ((1-t) * p0.y) + (t*p1.y);

  return pt;
}

vector<struct punto> bezier(struct punto p0, struct punto p1, struct punto p2) {
  vector<struct punto> puntos(1000);

  for (int t = 0; t < 1000; t++) {
    struct punto p11 = lerp(p0, p1, (double)t/1000.0);
    struct punto p12 = lerp(p1, p2, (double)t/1000.0);
    struct punto p22 = lerp(p11, p12, (double)t/1000.0);
    puntos[t] = p22;
  }

  return puntos;
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

  struct punto p1 = { 600, 400 };
  struct punto p2 = { 800, 200 };
  struct punto p3 = { 1000, 400 };
  vector<struct punto> ptsbezier = bezier(p1, p2, p3);

  for (struct punto p : ptsbezier) {
    image[p.y][p.x] = 0xFFFFFFFF;
  }


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
