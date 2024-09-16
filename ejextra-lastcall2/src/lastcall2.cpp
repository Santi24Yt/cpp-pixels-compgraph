#include <SFML/Graphics.hpp>
#include "lines.h"

using namespace std;

typedef unsigned char byt;

void dbg();
void dmainwin();
void dtoolswin();
void dspecwin();
void dlayoutwin();
void dvizwin();
void dsimwin(int tt);

int main() {
  const int width = 800;
  const int height = 450;

  int image[height][width];

  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      image[y][x] = 0x000000FF;
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

void dbg() {
  fillrect(0, 0, 800, 450, bgc);
}

/* Dibujar la ventana principal */
void dmainwin() {
  /* Ventana, tiene algunas orillas recortadas y otras rectas por lo que nos queda con 6 lados */
  int sombra[] = {
    s(5+3), s(10+3),
    s(10+3), s(5+3),
    s(793+3), s(5+3),
    s(795+3), s(8+3),
    s(795+3), s(445+3),
    s(5+3), s(445+3)
  };
  setcolor(bgck);
  setfillstyle(1, 0);
  fillpoly(6, sombra);
  int ventana[] = {
    5, 10,
    10, 5,
    793, 5,
    795, 8,
    795, 445,
    5, 445
  };
  setcolor(bgc2);
  setfillstyle(1, bgc2);
  fillpoly(6, ventana);

  /* Fondo interior de la ventana */
  fillrect(6, 40, 788, 403, bgc3, 6);

  /* Lineas de decoración */
  setcolor(bgck);
  line(10, 5, 10, 40);
  line(10, 25, 120, 25);
  line(120, 25, 128, 32);
  line(128, 32, 128, 40);
  line(765, 5, 765, 40);
  line(765, 15, 295, 15);
  line(295, 15, 285, 5);
  line(795, 10, 773, 10);
  line(773, 10, 773, 28);
  line(773, 28, 779, 33);
  line(779, 33, 795, 33);
  line(785, 10, 785, 33);

  /* Símbolo de minimizar (-) */
  fillrect(775, 19, 8, 2, bgc3);

  /* Símbolo de cerrar (x) medio deforme */
  int xpol[] = {
    786, 15,
    787, 15,
    791, 18,
    793, 15,
    794, 15,
    792, 18,
    794, 22,
    791, 19,
    788, 22,
    787, 22,
    791, 18
  };
  setcolor(bgc3);
  setfillstyle(1, bgc3);
  fillpoly(11, xpol);

  /* Triangulo de decoración */
  int tri[] = {
    60, 30,
    70, 30,
    65, 34
  };
  setcolor(bgc3);
  setfillstyle(1, bgc3);
  fillpoly(3, tri);

  /* Sección de nombre de ventana */
  fillsqrect(15, 8, 265, 13, 3, bluec);
  setcolor(14);
  char txt[] = "CHIPWIZARD TM PROFESSIONAL - SERIAL NUMBER ROM";
  outtextxy(22, 13, txt);
}

/* Dibujar la ventana de herramientas */
void dtoolswin() {
  /* Ventana */
  fillsqrect(s(12+3), s(45+3), 108, 255, 3, 0);
  fillsqrect(12, 45, 108, 255, 3, bgc2);
  /* Lineas de decoración */
  setcolor(bgck);
  line(12, 68, 120, 68);
  line(70, 45, 78, 52);
  line(78, 52, 100, 52);
  line(100, 52, 112, 68);
  /* Sección de nombre de ventana */
  fillsqrect(20, 50, 45, 12, 2, bluec);
  setcolor(14);
  char toolstx[] = "TOOLS";
  outtextxy(27, 54, toolstx);
  /* Opciónes de herramienta */
  setcolor(bgck);
  for (int i = 1; i <= 6; i++)
    rectangle(17, s(73+(30*(i-1))), 114, s(73+(30*i)));
  /* Versión de revisión */
  setcolor(bgc3);
  line(14, 258, 118, 258);
  char desrevtx[] = "DESIGN REVISION";
  outtextxy(26, 262, desrevtx);
  setcolor(bgck);
  rectangle(17, 272, 115, 290);
  line(49, 272, 49, 290);
  line(84, 272, 84, 290);
  setcolor(bgc3);
  rectangle(19, 274, 47, 288);
  setcolor(15);
  char uno[] = "1";
  char dos[] = "2";
  char tres[] = "3";
  outtextxy(30, 279, uno);
  outtextxy(65, 279, dos);
  outtextxy(96, 279, tres);
  setcolor(bgc3);
  rectangle(25, 81, 38, 95);
  rectangle(25, 111, 38, 124);
  rectangle(25, 141, 38, 152);
  rectangle(25, 171, 38, 183);
  rectangle(25, 201, 38, 213);
  rectangle(25, 231, 38, 244);
  /* Teclas de herramientas */
  char qtx[] = "Q";
  char wtx[] = "W";
  char etx[] = "E";
  char atx[] = "A";
  char stx[] = "S";
  char dtx[] = "D";
  outtextxy(29, 84,  qtx);
  outtextxy(29, 115, wtx);
  outtextxy(29, 145, etx);
  outtextxy(29, 174, atx);
  outtextxy(29, 204, stx);
  outtextxy(29, 234, dtx);
  /* Herramientas */
  fillrect(49, 77, 60, 22, bgck);
  fillrect(49, 107, 60, 22, bgck);
  fillrect(49, 137, 60, 22, bgck);
  fillrect(49, 167, 60, 22, 1, 5);
  fillrect(49, 197, 60, 22, 4, 4);
  fillrect(49, 227, 60, 22, 2, 8);
  setcolor(bgc2);
  char selecttx[] = "SELECT";
  char metaltx[] = "METAL";
  char viatx[] = "VIA []";
  char ntypetx[] = "N-TYPE";
  char ptypetx[] = "P-TYPE";
  char captx[] = "CAPACITOR";
  outtextxy(64, 86, selecttx);
  outtextxy(65, 116, metaltx);
  outtextxy(64, 146, viatx);
  setcolor(15);
  outtextxy(64, 176, ntypetx);
  outtextxy(64, 206, ptypetx);
  outtextxy(56, 236, captx);
}

/* Ventana de especificaciónes del problema */
void dspecwin() {
  /* Ventana */
  fillsqrect(s(598+3), s(285+3), 190, 150, 3, 0);
  fillsqrect(598, 285, 190, 150, 3, bgc2);
  /* Lineas de decoración */
  setcolor(bgck);
  line(598, 304, 788, 304);
  line(694, 285, 704, 292);
  line(704, 292, 768, 292);
  line(768, 292, 780, 304);
  /* Sección de nombre de la ventana */
  fillsqrect(608, 289, 85, 10, 2, bluec);
  setcolor(14);
  char spectx[] = "SPECIFICATION";
  outtextxy(614, 292, spectx);
  fillrect(600, 308, 186, 125, bgc3);
  /* Sub ventana */
  setcolor(bgck);
  line(600, 314, 785, 314);
  fillrect(607, 318, 174, 110, 0);
  fillrect(609, 340, 170, 86, 15);
  /* Texto de la especificación */
  setcolor(15);
  line(693, 319, 693, 340);
  char intx[] = "Inputs";
  outtextxy(632, 328, intx);
  char outtx[] = "Outputs";
  outtextxy(714, 328, outtx);
  setcolor(bgc2);
  line(693, 340, 693, 354);
  line(609, 354, 778, 354);
  setcolor(0);
  char readtx[] = "READ";
  outtextxy(640, 345, readtx);
  char datatx[] = "DATA";
  outtextxy(726, 345, datatx);
  /* Rectangulos que simulan texto */
  for(int i = 0; i < 5; i++)
    fillrect(615, s(365 + (8*i)), 155, 5, 0);
}

/* Ventana de layout */
void dlayoutwin() {
  /* Ventana */
  fillsqrect(s(128+3), s(45+3), 382, 252, 3, 0);
  fillsqrect(128, 45, 382, 252, 3, bgc2);
  /* Lineas de decoración */
  setcolor(bgck);
  line(128, 68, 510, 68);
  line(195, 45, 202, 55);
  line(202, 55, 490, 55);
  line(490, 55, 500, 68);
  /* Sección de nombre de la ventana */
  fillsqrect(138, 50, 50, 12, 2, bluec);
  setcolor(14);
  char layouttx[] = "LAYOUT";
  outtextxy(144, 54, layouttx);
  /* Entradas y salidas */
  fillrect(130, 75, 378, 220, 0);
  fillrect(152, 93, 50, 50, 14);
  fillrect(152, 163, 50, 50, 14);
  fillrect(152, 233, 50, 50, 14);
  fillrect(436, 93, 50, 50, 14);
  fillrect(436, 163, 50, 50, 14);
  fillrect(436, 233, 50, 50, 14);
  /* Cuadrículas de fondo */
  setcolor(bgc3);
  line(218, 104, 418, 104);
  line(218, 270, 418, 270);
  line(218, 104, 218, 270);
  line(418, 104, 418, 270);
  line(285, 104, 285, 270);
  line(320, 104, 320, 270);
  line(385, 104, 385, 270);
  line(218, 146, 418, 146);
  line(218, 188, 418, 188);
  line(218, 230, 418, 230);
  /* Layout */
  fillrect(260, 247, 86, 19, 4);
  fillrect(228, 181, 184, 19, 4, 4);
  fillrect(294, 113, 34, 19, 4, 4);
  fillrect(345, 113, 34, 19, 4);
  fillrect(327, 113, 19, 54, 1, 5);
  fillrect(260, 181, 19, 49, 1);
  fillrect(294, 214, 19, 52, 1);
  fillrect(361, 148, 19, 52, 1);
  fillrect(228, 113, 19, 19, 2, 8);
  fillrect(228, 147, 19, 19, 2, 8);
  fillrect(261, 147, 19, 19, 2, 8);
  fillrect(292, 147, 19, 19, 2, 8);
  fillrect(328, 214, 19, 19, 2, 8);
  fillrect(361, 247, 19, 19, 2, 8);
  /* Camino amarillo */
  int trail[] = {
    202, 175,
    225, 175,
    225, 108,
    311, 108,
    311, 128,
    278, 128,
    278, 142,
    344, 142,
    344, 174,
    377, 174,
    377, 260,
    354, 260,
    354, 241,
    358, 241,
    358, 193,
    326, 193,
    326, 161,
    258, 161,
    258, 128,
    243, 128,
    243, 193,
    202, 193
  };
  setcolor(14);
  setfillstyle(9, 14);
  fillpoly(22, trail);
  /* Vias */
  fillrect(392, 175, 44, 19, 14, 9);
  fillrect(258, 209, 19, 51, bgc3);
  fillrect(359, 109, 19, 51, bgc3);
  fillrect(292, 209, 52, 19, bgc3);
  fillrect(326, 218, 19, 42, bgc3);
  fillrect(326, 242, 28, 19, bgc3);
  fillrect(231, 179, 8, 8, 4);
  fillrect(298, 113, 8, 8, 4);
  fillrect(363, 113, 8, 8, 4);
  fillrect(263, 247, 8, 8, 4);
  fillrect(331, 247, 8, 8, 4);
  fillrect(397, 180, 8, 8, 4);
  fillrect(263, 213, 8, 8, 1);
  fillrect(299, 213, 8, 8, 1);
  fillrect(331, 147, 8, 8, 1);
  fillrect(365, 147, 8, 8, 1);
  /* Textos */
  char vptx[] = "+V";
  setcolor(0);
  outtextxy(172, 116, vptx);
  outtextxy(172, 258, vptx);
  outtextxy(456, 116, vptx);
  outtextxy(456, 258, vptx);
  char readtx[] = "READ";
  outtextxy(165, 183, readtx);
  char datatx[] = "DATA";
  outtextxy(449, 183, datatx);
}

/* Ventana del simulador */
void dsimwin(int tt) {
  /* Ventana */
  fillsqrect(s(12+3), s(308+3), 578, 125, 3, 0);
  fillsqrect(12, 308, 578, 125, 3, bgc2);
  /* Lineas de decoración */
  setcolor(bgck);
  line(12, 325, 590, 325);
  line(91, 308, 101, 314);
  line(101, 314, 566, 314);
  line(566, 314, 582, 325);
  /* Sección de nombre de la ventana */
  fillsqrect(21, 311, 64, 11, 2, bluec);
  setcolor(14);
  char simtx[] = "SIMULATOR";
  outtextxy(27, 314, simtx);
  /* Botones de simulador */
  fillsqrect(18, 328, 58, 100, 2, 0);
  for (int i = 0; i < 3; i++)
    sqrect(24, s(335 + (22*i)), 45, 18, 1, 2, 0);
  sqrect(24, s(335 + (22*3)), 45, 20, 1, 2, 0);
  /* Simbolo de repetir */
  setcolor(2);
  line(46, 350, 52, 344);
  line(52, 344, 46, 337);
  line(46, 337, 40, 344);
  line(40, 344, 42, 346);
  /* Simbolo de play */
  int tri[] = {
    42, 346,
    44, 344,
    45, 347
  };
  setcolor(2);
  setfillstyle(1, 2);
  fillpoly(3, tri);
  /* Simbolo de pausa */
  fillrect(42, 359, 2, 14, 2);
  fillrect(48, 359, 2, 14, 2);
  /* Simbolo de fastforward */
  int tri2[] = {
    42, 381,
    49, 388,
    42, 394
  };
  fillpoly(3, tri2);
  int tri3[] = {
    37, 404,
    44, 411,
    37, 417
  };
  fillpoly(3, tri3);
  int tri4[] = {
    44, 404,
    51, 411,
    44, 417
  };
  fillpoly(3, tri4);
  int tri5[] = {
    51, 404,
    58, 411,
    51, 417
  };
  fillpoly(3, tri5);
  /* Sección de funciones */
  setcolor(bgc3);
  line(82, 325, 82, 433);
  for (int i = 0; i < 6; i++)
    fillrect(86, s(332 + (16 * i)), 28, 12, bgc3);
  /* Nombre de funciones */
  char vptx[] = "+V";
  char readtx[] = "READ";
  char datatx[] = "DATA";
  char* textos[] = { vptx, readtx, vptx, vptx, datatx, vptx };
  /* Dibujar funciones */
  funciones fns[] = { f1, f2, f3, f4, f5, f6 };
  for (int i = 0; i < 6; i++) {
    int y = 330 + (16 * i);
    setcolor(bgc3);
    line(82, s(y), 570, s(y));
    setcolor(15);
    outtextxy(90, s(332 + (16 * i) + 4), textos[i]);
    int y2 = 332 + (16 * i);
    fillrect(122, s(y2), 444, 12, 0);
    /* Evaluar la función de 0 a 1000 y luego pasarla a tamaño de la sección */
    int prev = fns[i](0);
    for (int t = 0; t < 1000; t++) {
      int tm = map(444, t);
      int f = fns[i](t);
      int fx = 122 + tm;
      int fpy = y2 + (12 - prev);
      int fy = y2 + (12 - f);
      int color = 1;
      /* Si el tiempo ya superó al punto actual de la función dibujarlo de otro color */
      if (t <= tt)
        color = 2;
      /* Si la función cambió de valor conectar los valores con una línea */
      if (f != prev) {
        setcolor(color);
        line(s(fx), s(fpy), s(fx), s(fy));
      }
      /* Rellenar los pixeles faltantes en caso de que la escala sea mayor */
      for (int j = 0; j < (int)(scale + 1); j++) {
        putpixel(s(fx) + j, s(fy), color);
      }
      prev = f;
    }
  }
  /* Separadores de funciones */
  setcolor(bgc3);
  line(82, 426, 570, 426);
  line(118, 330, 118, 426);
  line(570, 330, 570, 426);
  line(580, 325, 580, 433);
}

/* Ventana de visualizador */
void dvizwin() {
  /* Ventana */
  fillsqrect(s(517+3), s(45+3), 270, 228, 3, 0);
  fillsqrect(517, 45, 270, 228, 3, bgc2);
  /* Lineas de decoración */
  setcolor(bgck);
  line(517, 67, 787, 67);
  line(600, 45, 608, 54);
  line(608, 54, 768, 54);
  line(768, 54, 780, 67);
  /* Sección de nombre de la ventana */
  fillsqrect(527, 49, 64, 12, 2, bluec);
  setcolor(14);
  char vistx[] = "VISUALIZER";
  outtextxy(532, 53, vistx);
  /* Visualización */
  fillrect(519, 72, 267, 199, 0);
  /* Poligonos de colores que se supone son una visualización 3d pero pierden un poco de dimensión por la falta de colores
   * y también para no tener otras 300 lineas de código */
  int rojo1[] = {
    671, 122,
    680, 142,
    613, 151,
    606, 137
  };
  setcolor(4);
  setfillstyle(1, 4);
  fillpoly(4, rojo1);
  int rojo2[] = {
    575, 209,
    738, 172,
    729, 154,
    568, 189
  };
  fillpoly(4, rojo2);
  int rojo3[] = {
    620, 243,
    698, 226,
    690, 206,
    614, 224
  };
  fillpoly(4, rojo3);
  int verde1[] = {
    551, 150,
    569, 146,
    575, 162,
    558, 166
  };
  setcolor(2);
  setfillstyle(1, 2);
  fillpoly(4, verde1);
  int verde2[] = {
    560, 171,
    577, 164,
    583, 179,
    567, 184
  };
  fillpoly(4, verde2);
  int verde3[] = {
    587, 163,
    610, 157,
    618, 175,
    594, 182
  };
  fillpoly(4, verde3);
  int verde4[] = {
    616, 157,
    637, 151,
    645, 170,
    623, 175
  };
  fillpoly(4, verde4);
  int verde5[] = {
    661, 192,
    678, 187,
    685, 203,
    668, 209
  };
  fillpoly(4, verde5);
  int verde6[] = {
    697, 205,
    717, 199,
    726, 219,
    704, 224
  };
  fillpoly(4, verde6);
  int azul1[] = {
    637, 129,
    655, 124,
    669, 163,
    650, 169
  };
  setcolor(1);
  setfillstyle(1, 1);
  fillpoly(4, azul1);
  int azul2[] = {
    600, 181,
    616, 178,
    628, 214,
    613, 221
  };
  fillpoly(4, azul2);
  int azul3[] = {
    633, 198,
    652, 194,
    668, 226,
    651, 233
  };
  fillpoly(4, azul3);
  int azul4[] = {
    671, 147,
    695, 143,
    708, 172,
    689, 179
  };
  fillpoly(4, azul4);
  int amarillo1[] = {
    519, 134,
    539, 128,
    551, 163,
    519, 168
  };
  setcolor(14);
  setfillstyle(1, 14);
  fillpoly(4, amarillo1);
  int amarillo2[] = {
    532, 218,
    573, 209,
    586, 242,
    544, 252
  };
  fillpoly(4, amarillo2);
  int amarillo3[] = {
    519, 176,
    556, 168,
    560, 178,
    573, 174,
    558, 142,
    558, 133,
    628, 119,
    632, 132,
    605, 139,
    609, 145,
    663, 133,
    671, 153,
    700, 147,
    721, 201,
    700, 206,
    696, 192,
    702, 191,
    690, 165,
    662, 170,
    653, 150,
    598, 163,
    589, 143,
    578, 145,
    593, 185,
    566, 192,
    569, 202,
    527, 212,
    519, 195
  };
  fillpoly(28, amarillo3);
  int amarillo4[] = {
    720, 88,
    762, 78,
    775, 111,
    733, 122,
    720, 90
  };
  fillpoly(4, amarillo4);
  int amarillo5[] = {
    779, 118,
    785, 137,
    785, 154,
    750, 162,
    747, 152,
    718, 158,
    713, 145,
    739, 138,
    737, 128,
  };
  fillpoly(9, amarillo5);
  int amarillo6[] = {
    754, 169,
    785, 161,
    785, 197,
    768, 202,
    754, 169
  };
  fillpoly(4, amarillo6);
  int gris1[] = {
    611, 190,
    624, 186,
    638, 221,
    623, 223
  };
  setcolor(bgc3);
  setfillstyle(1, bgc3);
  fillpoly(4, gris1);
  int gris2[] = {
    639, 184,
    680, 174,
    687, 193,
    696, 193,
    699, 207,
    679, 209,
    670, 189,
    643, 197
  };
  fillpoly(8, gris2);
  int gris3[] = {
    669, 110,
    682, 107,
    696, 141,
    681, 143
  };
  fillpoly(4, gris3);
}

