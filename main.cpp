#include"lista.h"
#include"lista.cpp"

std::vector<string> m={
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  "X           XXXXX           X",
  "X XXX XXXXX XXXXX XXXXX XXX X",
  "X XXX XXXXX XXXXX XXXXX XXX X",
  "X                           X",
  "X XXX XXXXXXXXXXXXXXXXX XXX X",
  "X     XXo  oXXXXXo  oXX     X",
  "X XXX XX XX XXXXX    XX XXX X",
  "X XXX X               X XXX X",
  "X     X     X   X   B X      ",
  "X XXX X  X  B   B   X X XXX X",
  "X XXX XX            X X XXX X",
  "X XXX X   X           X XXX X",
  "X     X            B  X     X",
  "X XXX X               X XXX X",
  "X XXX                   XXX X",
  "X XXX XXXX XXXXXXXX XXX XXX X",
  "X XXX XXXX          XXX XXX X",
  "X          XXXXXXXX         X",
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};

std::vector<string> n={
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  "X           XX XX           X",
  "X XXX XXXXX XX XX XXXXX XXX X",
  "X XXX XXXXX XX XX XXXXX XXX X",
  "X                           X",
  "X XXX XXXXXXXXXXXXXXXXX XXX X",
  "X     Xo        XXX  oX     X",
  "X XXX X               X XXX X",
  "X XXX X  XXXXBB  X    X XXX X",
  "      X   B      X    X      ",
  "X XXX X  XXXX    X    X XXX X",
  "X XXX X          X   XX XXX X",
  "X XXX XX       X      X XXX X",
  "X     X  X            X     X",
  "X XXX X       X   B   X XXX X",
  "X XXX X               X XXX X",
  "X XXX Xo  X        X  oX XXX X",
  "X XXX XXXXXXXX XXXX XXX XXX X",
  "X              XXXX         X",
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};

std::vector<string> o={
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  "X           XX XX           X",
  "X XXX XXXXX XX XX XXXXX XXX X",
  "X XXX XXXXX XX XX XXXXX XXX X",
  "X                           X",
  "X XXX XXXXXXXXXXXXXXXXX XXX X",
  "X     XXXoX       XoXXX     X",
  "X XXX XX             XX XXX X",
  "X XXX XX         B   XX XXX X",
  "      XX    XXXXX    XX     X ",
  "X XXX XX   BXXXXX    XX XXX X",
  "X XXX XX         B   XX XXX X",
  "X XXX XX   B         XX XXX X",
  "X     XX   B         XX     X",
  "X XXX XX XXXXXXXXXXX XX XXX X",
  "X XXX                   XXX X",
  "X XXX XXXX XXXXXXXX XXX XXX X",
  "X XXX XXXX          XXX XXX X",
  "X          XXX XXXX         X",
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};


int main(int argc, char **argv){
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,880,600,0,0);
    Lista<Mapa1> xs;
    //Mapa *A=new Mapa1(m);
    //Mapa *B=new Mapa1(n);
    Mapa1 A(m);
    Mapa1 B(n);
    Mapa1 C(o);
    xs.push(A);
    xs.push(B);
    xs.push(C);
    //xs.top().imprimir();
    Iterador<Mapa1> *it=xs.crearIterador();
    it->inicio();
    it->testIterador();
}
END_OF_MAIN();
