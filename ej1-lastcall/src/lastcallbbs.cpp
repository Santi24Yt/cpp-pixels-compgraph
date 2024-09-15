/* Incluir graphics.h */
#include <graphics.h>

/* Incluir esta bilbioteca si estamos en windows */
#ifndef _SDL_BGI_H
#include <conio.h>
#endif

using namespace std;

/* La escala de los pixeles, ej. scale = 2, cada pixel equivale a 2 pixeles reales en la pantalla */
#define scale 1.5
#define s(a) (int)((a) * scale)

/* Colores extra que vamos a usar */
#define bgck COLOR(59, 66, 74)
#define bgc COLOR(109, 93, 106)
#define bgc2 COLOR(165, 170, 176)
#define bgc3 COLOR(94, 99, 105)
#define bluec COLOR(5, 0, 181)

/* Un apuntador a funciones para poder usar un arreglo de funciones */
typedef int (*funciones) (int t);

/* Funciones para dibujar rectangulos */
/* Dibujar rectangulo con relleno */
void fillrect(int x, int y, int w, int h, int c, int st = 1);
/* Dibujar rectangulo con relleno y orillas cuadradas */
void fillsqrect(int x, int y, int w, int h, int r, int c, int st = 1);
/* Dibujar rectangulo con orillas cuadradas */
void sqrect(int x, int y, int w, int h, int r, int c, int c2);

/* Funciones con t E [0, 1000] que devuelven un valor [0, 12] para las gráficas de la simulación */
int f1(int t);
int f2(int t);
int f3(int t);
int f4(int t);
int f5(int t);
int f6(int t);

/* Convierte un valor m que va de 0 a 1000 a uno que va de 0 a o */
int map(int o, int m);

/* Funciones que dibujan las distintas ventanas */
void dbg();
void dmainwin();
void dtoolswin();
void dspecwin();
void dlayoutwin();
void dvizwin();
void dsimwin(int tt);

/* Esperar ciertos milisegundos sin que se quede en blanco la pantalla */
void sleep(int ms) {
  swapbuffers();
  delay(ms);
  swapbuffers();
}

int main() {
  char title[] = "LastCallBBS ChipWizard TM";

  /* Inicializar la ventana dependiendo si estamos en windows o linux */
  #ifdef _SDL_BGI_H
    int w1 = initwindow(s(800), s(450));
    setwintitle(w1, title);
  #else
    initwindow(s(800), s(450), title, 0, 0, true, false);
  #endif

  /* Color de fondo/vacío */
  setbkcolor(bgck);

  /* Si la escala es muy grande usar texto grande */
  if (scale >= 2) {
    settextstyle(0, HORIZ_DIR, 2);
  }

  /* Animación de apertura de ventanas */
  for (int i = 0; i < 2; i++) {
    cleardevice();
    dbg();
    sleep(1000);
  }

  for (int i = 1, s = 15; i <= s; i++) {
    cleardevice();
    dbg();
    int wp = (790*i)/s;
    int hp = (440*i)/s;
    fillrect(s(5+3), s(5+3), s(wp), s(hp), bgck);
    fillrect(s(5), s(5), s(wp), s(hp), bgc2);
    sleep(20);
  }

  cleardevice();
  dbg();
  dmainwin();
  sleep(1000);

  for (int i = 1, s = 15; i <= s; i++) {
    cleardevice();
    dbg();
    dmainwin();
    int wp = (108*i)/s;
    int hp = (255*i)/s;
    fillsqrect(s(12+3), s(45+3), s(wp), s(hp), s(3), 0);
    fillsqrect(s(12), s(45), s(wp), s(hp), s(3), bgc2);
    sleep(20);
  }

  cleardevice();
  dbg();
  dmainwin();
  dtoolswin();
  sleep(1000);

  for (int i = 0, s = 15; i <= s; i++) {
    cleardevice();
    dbg();
    dmainwin();
    dtoolswin();
    int wp = (190*i)/s;
    int hp = (150*i)/s;
    fillsqrect(s(598+3), s(285+3), s(wp), s(hp), s(3), 0);
    fillsqrect(s(598), s(285), s(wp), s(hp), s(3), bgc2);
    sleep(20);
  }

  cleardevice();
  dbg();
  dmainwin();
  dtoolswin();
  dspecwin();
  sleep(1000);

  for (int i = 1, s = 15; i <= s; i++) {
    cleardevice();
    dbg();
    dmainwin();
    dtoolswin();
    dspecwin();
    int wp = (382*i)/s;
    int hp = (252*i)/s;
    fillsqrect(s(128+3), s(45+3), s(wp), s(hp), s(3), 0);
    fillsqrect(s(128), s(45), s(wp), s(hp), s(3), bgc2);
    sleep(20);
  }

  cleardevice();
  dbg();
  dmainwin();
  dtoolswin();
  dspecwin();
  dlayoutwin();
  sleep(1000);

  for (int i = 1, s = 15; i <= s; i++) {
    cleardevice();
    dbg();
    dmainwin();
    dtoolswin();
    dspecwin();
    dlayoutwin();
    int wp = (270*i)/s;
    int hp = (228*i)/s;
    fillsqrect(s(517+3), s(45+3), s(wp), s(hp), s(3), 0);
    fillsqrect(s(517), s(45), s(wp), s(hp), s(3), bgc2);
    sleep(20);
  }

  cleardevice();
  dbg();
  dmainwin();
  dtoolswin();
  dspecwin();
  dlayoutwin();
  dvizwin();
  sleep(1000);

  for (int i = 1, s = 15; i <= s; i++) {
    cleardevice();
    dbg();
    dmainwin();
    dtoolswin();
    dspecwin();
    dlayoutwin();
    dvizwin();
    int wp = (578*i)/s;
    int hp = (125*i)/s;
    fillsqrect(s(12+3), s(308+3), s(wp), s(hp), s(3), 0);
    fillsqrect(s(12), s(308), s(wp), s(hp), s(3), bgc2);
    sleep(20);
  }

  /* Dibujar las ventanas y actualizar cada cierto tiempo mientras no se haya presionado ninguna tecla
   * la ventana de simulación cuenta el tiempo para mostrar el progreso en sus gráficas */
  int tt = 0;
  while(!kbhit()) {
    cleardevice();
    dbg();
    dmainwin();
    dtoolswin();
    dspecwin();
    dlayoutwin();
    dvizwin();
    dsimwin(tt);
    tt = (tt+5) % 1000;
    sleep(30);
  };

  closegraph();
  return 0;
}

/* Dibujar rectangulo con relleno */
void fillrect(int x, int y, int w, int h, int c, int st) {
  /* No hay función para dibujar rectangulo con relleno pero podemos crear un polígono con relleno, y con
   * las coordenadas correctas será un rectángulo */
  int rect[] = {x, y, x+w-1, y, x+w-1, y+h-1, x, y+h-1};
  setcolor(c);
  setfillstyle(st, c);
  fillpoly(4, rect);
}

/* Dibujar rectangulo con relleno y orillas cuadradas */
void fillsqrect(int x, int y, int w, int h, int r, int c, int st) {
  /* Un rectangulo con orillas cuadradas es básicamente un octágono medio deforme, entonces hacemos un polígono de 8 lados */
  int rect[] = {
    x, y+r,
    x+r, y,
    x+w-r, y,
    x+w, y+r,
    x+w, y+h-r,
    x+w-r, y+h,
    x+r, y+h,
    x, y+h-r
  };
  setcolor(c);
  setfillstyle(st, c);
  fillpoly(8, rect);
}

/* Dibujar rectangulo con orillas cuadradas */
void sqrect(int x, int y, int w, int h, int r, int c, int c2) {
  /* Un rectangulo con orillas cuadradas es básicamente un octágono medio deforme, entonces hacemos un polígono de 8 lados */
  int rect[] = {
    x, y+r,
    x+r, y,
    x+w-r, y,
    x+w, y+r,
    x+w, y+h-r,
    x+w-r, y+h,
    x+r, y+h,
    x, y+h-r
  };
  setcolor(c);
  /* c2 debe ser el color de lo que este detras de nuestro rectángulo ya que no estamos trabajando con transparencia */
  setfillstyle(1, c2);
  fillpoly(8, rect);
}


/* Funciones con t E [0, 1000] que devuelven un valor [0, 12] para las gráficas de la simulación */
int f1(int t) {
  return 12;
}

int f2(int t) {
  if (t >= 17*6 && t < 17*14) {
    return 12;
  } else if (t >= 17*17 && t < 17*20) {
    return 12;
  } else if (t >= 17*25 && t < 17*30) {
    return 12;
  } else if (t >= 17*35 && t < 17*45) {
    return 12;
  } else {
    return 0;
  }
};

int f3 (int t) {
  return (sin((double)t/22.0) * 6) + 6;
}

int f4 (int t) {
  return (t/8) % 12;
}

int f5 (int t) {
  if (t >= 17*6 && t < 17*9) {
    return 12;
  } else if (t >= 17*10 && t < 17*12) {
    return 12;
  } else if (t >= 17*13 && t < 17*23) {
    return 12;
  } else if (t >= 17*26 && t < 17*28) {
    return 12;
  } else if (t >= 17*36 && t < 17*39) {
    return 12;
  } else if (t >= 17*41 && t < 17*42) {
    return 12;
  } else if (t >= 17*43 && t < 17*44) {
    return 12;
  } else if (t >= 17*45 && t < 17*48) {
    return 12;
  } else if (t >= 17*50) {
    return 12;
  } else {
    return 0;
  }
}

int f6 (int t) {
  double x = (double)t/22.0;
  int r = ((sin(2 * x) - 2 * sin(x)) * 3) + 6;
  if (r < 0) {
    return 0;
  } else {
    return r;
  }
}

/* Convierte un valor m que va de 0 a 1000 a uno que va de 0 a o */
int map(int o, int m) {
  return (m*o)/1000;
}

/* Dibujar nuestro fondo */
void dbg() {
  fillrect(s(0), s(0), s(800), s(450), bgc);
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
    s(5), s(10),
    s(10), s(5),
    s(793), s(5),
    s(795), s(8),
    s(795), s(445),
    s(5), s(445)
  };
  setcolor(bgc2);
  setfillstyle(1, bgc2);
  fillpoly(6, ventana);

  /* Fondo interior de la ventana */
  fillrect(s(6), s(40), s(788), s(403), bgc3, 6);

  /* Lineas de decoración */
  setcolor(bgck);
  line(s(10), s(5), s(10), s(40));
  line(s(10), s(25), s(120), s(25));
  line(s(120), s(25), s(128), s(32));
  line(s(128), s(32), s(128), s(40));
  line(s(765), s(5), s(765), s(40));
  line(s(765), s(15), s(295), s(15));
  line(s(295), s(15), s(285), s(5));
  line(s(795), s(10), s(773), s(10));
  line(s(773), s(10), s(773), s(28));
  line(s(773), s(28), s(779), s(33));
  line(s(779), s(33), s(795), s(33));
  line(s(785), s(10), s(785), s(33));

  /* Símbolo de minimizar (-) */
  fillrect(s(775), s(19), s(8), s(2), bgc3);

  /* Símbolo de cerrar (x) medio deforme */
  int xpol[] = {
    s(786), s(15),
    s(787), s(15),
    s(791), s(18),
    s(793), s(15),
    s(794), s(15),
    s(792), s(18),
    s(794), s(22),
    s(791), s(19),
    s(788), s(22),
    s(787), s(22),
    s(791), s(18)
  };
  setcolor(bgc3);
  setfillstyle(1, bgc3);
  fillpoly(11, xpol);

  /* Triangulo de decoración */
  int tri[] = {
    s(60), s(30),
    s(70), s(30),
    s(65), s(34)
  };
  setcolor(bgc3);
  setfillstyle(1, bgc3);
  fillpoly(3, tri);

  /* Sección de nombre de ventana */
  fillsqrect(s(15), s(8), s(265), s(13), s(3), bluec);
  setcolor(14);
  char txt[] = "CHIPWIZARD TM PROFESSIONAL - SERIAL NUMBER ROM";
  outtextxy(s(22), s(13), txt);
}

/* Dibujar la ventana de herramientas */
void dtoolswin() {
  /* Ventana */
  fillsqrect(s(12+3), s(45+3), s(108), s(255), s(3), 0);
  fillsqrect(s(12), s(45), s(108), s(255), s(3), bgc2);
  /* Lineas de decoración */
  setcolor(bgck);
  line(s(12), s(68), s(120), s(68));
  line(s(70), s(45), s(78), s(52));
  line(s(78), s(52), s(100), s(52));
  line(s(100), s(52), s(112), s(68));
  /* Sección de nombre de ventana */
  fillsqrect(s(20), s(50), s(45), s(12), s(2), bluec);
  setcolor(14);
  char toolstx[] = "TOOLS";
  outtextxy(s(27), s(54), toolstx);
  /* Opciónes de herramienta */
  setcolor(bgck);
  for (int i = 1; i <= 6; i++)
    rectangle(s(17), s(73+(30*(i-1))), s(114), s(73+(30*i)));
  /* Versión de revisión */
  setcolor(bgc3);
  line(s(14), s(258), s(118), s(258));
  char desrevtx[] = "DESIGN REVISION";
  outtextxy(s(26), s(262), desrevtx);
  setcolor(bgck);
  rectangle(s(17), s(272), s(115), s(290));
  line(s(49), s(272), s(49), s(290));
  line(s(84), s(272), s(84), s(290));
  setcolor(bgc3);
  rectangle(s(19), s(274), s(47), s(288));
  setcolor(15);
  char uno[] = "1";
  char dos[] = "2";
  char tres[] = "3";
  outtextxy(s(30), s(279), uno);
  outtextxy(s(65), s(279), dos);
  outtextxy(s(96), s(279), tres);
  setcolor(bgc3);
  rectangle(s(25), s(81), s(38), s(95));
  rectangle(s(25), s(111), s(38), s(124));
  rectangle(s(25), s(141), s(38), s(152));
  rectangle(s(25), s(171), s(38), s(183));
  rectangle(s(25), s(201), s(38), s(213));
  rectangle(s(25), s(231), s(38), s(244));
  /* Teclas de herramientas */
  char qtx[] = "Q";
  char wtx[] = "W";
  char etx[] = "E";
  char atx[] = "A";
  char stx[] = "S";
  char dtx[] = "D";
  outtextxy(s(29), s(84),  qtx);
  outtextxy(s(29), s(115), wtx);
  outtextxy(s(29), s(145), etx);
  outtextxy(s(29), s(174), atx);
  outtextxy(s(29), s(204), stx);
  outtextxy(s(29), s(234), dtx);
  /* Herramientas */
  fillrect(s(49), s(77), s(60), s(22), bgck);
  fillrect(s(49), s(107), s(60), s(22), bgck);
  fillrect(s(49), s(137), s(60), s(22), bgck);
  fillrect(s(49), s(167), s(60), s(22), 1, 5);
  fillrect(s(49), s(197), s(60), s(22), 4, 4);
  fillrect(s(49), s(227), s(60), s(22), 2, 8);
  setcolor(bgc2);
  char selecttx[] = "SELECT";
  char metaltx[] = "METAL";
  char viatx[] = "VIA []";
  char ntypetx[] = "N-TYPE";
  char ptypetx[] = "P-TYPE";
  char captx[] = "CAPACITOR";
  outtextxy(s(64), s(86), selecttx);
  outtextxy(s(65), s(116), metaltx);
  outtextxy(s(64), s(146), viatx);
  setcolor(15);
  outtextxy(s(64), s(176), ntypetx);
  outtextxy(s(64), s(206), ptypetx);
  outtextxy(s(56), s(236), captx);
}

/* Ventana de especificaciónes del problema */
void dspecwin() {
  /* Ventana */
  fillsqrect(s(598+3), s(285+3), s(190), s(150), s(3), 0);
  fillsqrect(s(598), s(285), s(190), s(150), s(3), bgc2);
  /* Lineas de decoración */
  setcolor(bgck);
  line(s(598), s(304), s(788), s(304));
  line(s(694), s(285), s(704), s(292));
  line(s(704), s(292), s(768), s(292));
  line(s(768), s(292), s(780), s(304));
  /* Sección de nombre de la ventana */
  fillsqrect(s(608), s(289), s(85), s(10), s(2), bluec);
  setcolor(14);
  char spectx[] = "SPECIFICATION";
  outtextxy(s(614), s(292), spectx);
  fillrect(s(600), s(308), s(186), s(125), bgc3);
  /* Sub ventana */
  setcolor(bgck);
  line(s(600), s(314), s(785), s(314));
  fillrect(s(607), s(318), s(174), s(110), 0);
  fillrect(s(609), s(340), s(170), s(86), 15);
  /* Texto de la especificación */
  setcolor(15);
  line(s(693), s(319), s(693), s(340));
  char intx[] = "Inputs";
  outtextxy(s(632), s(328), intx);
  char outtx[] = "Outputs";
  outtextxy(s(714), s(328), outtx);
  setcolor(bgc2);
  line(s(693), s(340), s(693), s(354));
  line(s(609), s(354), s(778), s(354));
  setcolor(0);
  char readtx[] = "READ";
  outtextxy(s(640), s(345), readtx);
  char datatx[] = "DATA";
  outtextxy(s(726), s(345), datatx);
  /* Rectangulos que simulan texto */
  for(int i = 0; i < 5; i++)
    fillrect(s(615), s(365 + (8*i)), s(155), s(5), 0);
}

/* Ventana de layout */
void dlayoutwin() {
  /* Ventana */
  fillsqrect(s(128+3), s(45+3), s(382), s(252), s(3), 0);
  fillsqrect(s(128), s(45), s(382), s(252), s(3), bgc2);
  /* Lineas de decoración */
  setcolor(bgck);
  line(s(128), s(68), s(510), s(68));
  line(s(195), s(45), s(202), s(55));
  line(s(202), s(55), s(490), s(55));
  line(s(490), s(55), s(500), s(68));
  /* Sección de nombre de la ventana */
  fillsqrect(s(138), s(50), s(50), s(12), s(2), bluec);
  setcolor(14);
  char layouttx[] = "LAYOUT";
  outtextxy(s(144), s(54), layouttx);
  /* Entradas y salidas */
  fillrect(s(130), s(75), s(378), s(220), 0);
  fillrect(s(152), s(93), s(50), s(50), 14);
  fillrect(s(152), s(163), s(50), s(50), 14);
  fillrect(s(152), s(233), s(50), s(50), 14);
  fillrect(s(436), s(93), s(50), s(50), 14);
  fillrect(s(436), s(163), s(50), s(50), 14);
  fillrect(s(436), s(233), s(50), s(50), 14);
  /* Cuadrículas de fondo */
  setcolor(bgc3);
  line(s(218), s(104), s(418), s(104));
  line(s(218), s(270), s(418), s(270));
  line(s(218), s(104), s(218), s(270));
  line(s(418), s(104), s(418), s(270));
  line(s(285), s(104), s(285), s(270));
  line(s(320), s(104), s(320), s(270));
  line(s(385), s(104), s(385), s(270));
  line(s(218), s(146), s(418), s(146));
  line(s(218), s(188), s(418), s(188));
  line(s(218), s(230), s(418), s(230));
  /* Layout */
  fillrect(s(260), s(247), s(86), s(19), 4);
  fillrect(s(228), s(181), s(184), s(19), 4, 4);
  fillrect(s(294), s(113), s(34), s(19), 4, 4);
  fillrect(s(345), s(113), s(34), s(19), 4);
  fillrect(s(327), s(113), s(19), s(54), 1, 5);
  fillrect(s(260), s(181), s(19), s(49), 1);
  fillrect(s(294), s(214), s(19), s(52), 1);
  fillrect(s(361), s(148), s(19), s(52), 1);
  fillrect(s(228), s(113), s(19), s(19), 2, 8);
  fillrect(s(228), s(147), s(19), s(19), 2, 8);
  fillrect(s(261), s(147), s(19), s(19), 2, 8);
  fillrect(s(292), s(147), s(19), s(19), 2, 8);
  fillrect(s(328), s(214), s(19), s(19), 2, 8);
  fillrect(s(361), s(247), s(19), s(19), 2, 8);
  /* Camino amarillo */
  int trail[] = {
    s(202), s(175),
    s(225), s(175),
    s(225), s(108),
    s(311), s(108),
    s(311), s(128),
    s(278), s(128),
    s(278), s(142),
    s(344), s(142),
    s(344), s(174),
    s(377), s(174),
    s(377), s(260),
    s(354), s(260),
    s(354), s(241),
    s(358), s(241),
    s(358), s(193),
    s(326), s(193),
    s(326), s(161),
    s(258), s(161),
    s(258), s(128),
    s(243), s(128),
    s(243), s(193),
    s(202), s(193)
  };
  setcolor(14);
  setfillstyle(9, 14);
  fillpoly(22, trail);
  /* Vias */
  fillrect(s(392), s(175), s(44), s(19), 14, 9);
  fillrect(s(258), s(209), s(19), s(51), bgc3);
  fillrect(s(359), s(109), s(19), s(51), bgc3);
  fillrect(s(292), s(209), s(52), s(19), bgc3);
  fillrect(s(326), s(218), s(19), s(42), bgc3);
  fillrect(s(326), s(242), s(28), s(19), bgc3);
  fillrect(s(231), s(179), s(8), s(8), 4);
  fillrect(s(298), s(113), s(8), s(8), 4);
  fillrect(s(363), s(113), s(8), s(8), 4);
  fillrect(s(263), s(247), s(8), s(8), 4);
  fillrect(s(331), s(247), s(8), s(8), 4);
  fillrect(s(397), s(180), s(8), s(8), 4);
  fillrect(s(263), s(213), s(8), s(8), 1);
  fillrect(s(299), s(213), s(8), s(8), 1);
  fillrect(s(331), s(147), s(8), s(8), 1);
  fillrect(s(365), s(147), s(8), s(8), 1);
  /* Textos */
  char vptx[] = "+V";
  setcolor(0);
  outtextxy(s(172), s(116), vptx);
  outtextxy(s(172), s(258), vptx);
  outtextxy(s(456), s(116), vptx);
  outtextxy(s(456), s(258), vptx);
  char readtx[] = "READ";
  outtextxy(s(165), s(183), readtx);
  char datatx[] = "DATA";
  outtextxy(s(449), s(183), datatx);
}

/* Ventana del simulador */
void dsimwin(int tt) {
  /* Ventana */
  fillsqrect(s(12+3), s(308+3), s(578), s(125), s(3), 0);
  fillsqrect(s(12), s(308), s(578), s(125), s(3), bgc2);
  /* Lineas de decoración */
  setcolor(bgck);
  line(s(12), s(325), s(590), s(325));
  line(s(91), s(308), s(101), s(314));
  line(s(101), s(314), s(566), s(314));
  line(s(566), s(314), s(582), s(325));
  /* Sección de nombre de la ventana */
  fillsqrect(s(21), s(311), s(64), s(11), s(2), bluec);
  setcolor(14);
  char simtx[] = "SIMULATOR";
  outtextxy(s(27), s(314), simtx);
  /* Botones de simulador */
  fillsqrect(s(18), s(328), s(58), s(100), s(2), 0);
  for (int i = 0; i < 3; i++)
    sqrect(s(24), s(335 + (22*i)), s(45), s(18), s(1), 2, 0);
  sqrect(s(24), s(335 + (22*3)), s(45), s(20), s(1), 2, 0);
  /* Simbolo de repetir */
  setcolor(2);
  line(s(46), s(350), s(52), s(344));
  line(s(52), s(344), s(46), s(337));
  line(s(46), s(337), s(40), s(344));
  line(s(40), s(344), s(42), s(346));
  /* Simbolo de play */
  int tri[] = {
    s(42), s(346),
    s(44), s(344),
    s(45), s(347)
  };
  setcolor(2);
  setfillstyle(1, 2);
  fillpoly(3, tri);
  /* Simbolo de pausa */
  fillrect(s(42), s(359), s(2), s(14), 2);
  fillrect(s(48), s(359), s(2), s(14), 2);
  /* Simbolo de fastforward */
  int tri2[] = {
    s(42), s(381),
    s(49), s(388),
    s(42), s(394)
  };
  fillpoly(3, tri2);
  int tri3[] = {
    s(37), s(404),
    s(44), s(411),
    s(37), s(417)
  };
  fillpoly(3, tri3);
  int tri4[] = {
    s(44), s(404),
    s(51), s(411),
    s(44), s(417)
  };
  fillpoly(3, tri4);
  int tri5[] = {
    s(51), s(404),
    s(58), s(411),
    s(51), s(417)
  };
  fillpoly(3, tri5);
  /* Sección de funciones */
  setcolor(bgc3);
  line(s(82), s(325), s(82), s(433));
  for (int i = 0; i < 6; i++)
    fillrect(s(86), s(332 + (16 * i)), s(28), s(12), bgc3);
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
    line(s(82), s(y), s(570), s(y));
    setcolor(15);
    outtextxy(s(90), s(332 + (16 * i) + 4), textos[i]);
    int y2 = 332 + (16 * i);
    fillrect(s(122), s(y2), s(444), s(12), 0);
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
  line(s(82), s(426), s(570), s(426));
  line(s(118), s(330), s(118), s(426));
  line(s(570), s(330), s(570), s(426));
  line(s(580), s(325), s(580), s(433));
}

/* Ventana de visualizador */
void dvizwin() {
  /* Ventana */
  fillsqrect(s(517+3), s(45+3), s(270), s(228), s(3), 0);
  fillsqrect(s(517), s(45), s(270), s(228), s(3), bgc2);
  /* Lineas de decoración */
  setcolor(bgck);
  line(s(517), s(67), s(787), s(67));
  line(s(600), s(45), s(608), s(54));
  line(s(608), s(54), s(768), s(54));
  line(s(768), s(54), s(780), s(67));
  /* Sección de nombre de la ventana */
  fillsqrect(s(527), s(49), s(64), s(12), s(2), bluec);
  setcolor(14);
  char vistx[] = "VISUALIZER";
  outtextxy(s(532), s(53), vistx);
  /* Visualización */
  fillrect(s(519), s(72), s(267), s(199), 0);
  /* Poligonos de colores que se supone son una visualización 3d pero pierden un poco de dimensión por la falta de colores
   * y también para no tener otras 300 lineas de código */
  int rojo1[] = {
    s(671), s(122),
    s(680), s(142),
    s(613), s(151),
    s(606), s(137)
  };
  setcolor(4);
  setfillstyle(1, 4);
  fillpoly(4, rojo1);
  int rojo2[] = {
    s(575), s(209),
    s(738), s(172),
    s(729), s(154),
    s(568), s(189)
  };
  fillpoly(4, rojo2);
  int rojo3[] = {
    s(620), s(243),
    s(698), s(226),
    s(690), s(206),
    s(614), s(224)
  };
  fillpoly(4, rojo3);
  int verde1[] = {
    s(551), s(150),
    s(569), s(146),
    s(575), s(162),
    s(558), s(166)
  };
  setcolor(2);
  setfillstyle(1, 2);
  fillpoly(4, verde1);
  int verde2[] = {
    s(560), s(171),
    s(577), s(164),
    s(583), s(179),
    s(567), s(184)
  };
  fillpoly(4, verde2);
  int verde3[] = {
    s(587), s(163),
    s(610), s(157),
    s(618), s(175),
    s(594), s(182)
  };
  fillpoly(4, verde3);
  int verde4[] = {
    s(616), s(157),
    s(637), s(151),
    s(645), s(170),
    s(623), s(175)
  };
  fillpoly(4, verde4);
  int verde5[] = {
    s(661), s(192),
    s(678), s(187),
    s(685), s(203),
    s(668), s(209)
  };
  fillpoly(4, verde5);
  int verde6[] = {
    s(697), s(205),
    s(717), s(199),
    s(726), s(219),
    s(704), s(224)
  };
  fillpoly(4, verde6);
  int azul1[] = {
    s(637), s(129),
    s(655), s(124),
    s(669), s(163),
    s(650), s(169)
  };
  setcolor(1);
  setfillstyle(1, 1);
  fillpoly(4, azul1);
  int azul2[] = {
    s(600), s(181),
    s(616), s(178),
    s(628), s(214),
    s(613), s(221)
  };
  fillpoly(4, azul2);
  int azul3[] = {
    s(633), s(198),
    s(652), s(194),
    s(668), s(226),
    s(651), s(233)
  };
  fillpoly(4, azul3);
  int azul4[] = {
    s(671), s(147),
    s(695), s(143),
    s(708), s(172),
    s(689), s(179)
  };
  fillpoly(4, azul4);
  int amarillo1[] = {
    s(519), s(134),
    s(539), s(128),
    s(551), s(163),
    s(519), s(168)
  };
  setcolor(14);
  setfillstyle(1, 14);
  fillpoly(4, amarillo1);
  int amarillo2[] = {
    s(532), s(218),
    s(573), s(209),
    s(586), s(242),
    s(544), s(252)
  };
  fillpoly(4, amarillo2);
  int amarillo3[] = {
    s(519), s(176),
    s(556), s(168),
    s(560), s(178),
    s(573), s(174),
    s(558), s(142),
    s(558), s(133),
    s(628), s(119),
    s(632), s(132),
    s(605), s(139),
    s(609), s(145),
    s(663), s(133),
    s(671), s(153),
    s(700), s(147),
    s(721), s(201),
    s(700), s(206),
    s(696), s(192),
    s(702), s(191),
    s(690), s(165),
    s(662), s(170),
    s(653), s(150),
    s(598), s(163),
    s(589), s(143),
    s(578), s(145),
    s(593), s(185),
    s(566), s(192),
    s(569), s(202),
    s(527), s(212),
    s(519), s(195)
  };
  fillpoly(28, amarillo3);
  int amarillo4[] = {
    s(720), s(88),
    s(762), s(78),
    s(775), s(111),
    s(733), s(122),
    s(720), s(90)
  };
  fillpoly(4, amarillo4);
  int amarillo5[] = {
    s(779), s(118),
    s(785), s(137),
    s(785), s(154),
    s(750), s(162),
    s(747), s(152),
    s(718), s(158),
    s(713), s(145),
    s(739), s(138),
    s(737), s(128),
  };
  fillpoly(9, amarillo5);
  int amarillo6[] = {
    s(754), s(169),
    s(785), s(161),
    s(785), s(197),
    s(768), s(202),
    s(754), s(169)
  };
  fillpoly(4, amarillo6);
  int gris1[] = {
    s(611), s(190),
    s(624), s(186),
    s(638), s(221),
    s(623), s(223)
  };
  setcolor(bgc3);
  setfillstyle(1, bgc3);
  fillpoly(4, gris1);
  int gris2[] = {
    s(639), s(184),
    s(680), s(174),
    s(687), s(193),
    s(696), s(193),
    s(699), s(207),
    s(679), s(209),
    s(670), s(189),
    s(643), s(197)
  };
  fillpoly(8, gris2);
  int gris3[] = {
    s(669), s(110),
    s(682), s(107),
    s(696), s(141),
    s(681), s(143)
  };
  fillpoly(4, gris3);
}

