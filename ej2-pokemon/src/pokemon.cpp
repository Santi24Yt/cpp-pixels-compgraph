#include <SFML/Graphics.hpp>

using namespace std;

typedef unsigned char byt;

int main() {
  int width = 1270;
  int height = 680;

  int image[height][width];

  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      image[y][x] = 0xFFFFFFFF;
    }
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
