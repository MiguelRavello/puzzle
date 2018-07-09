#include"lista.h"

vector<string> m={
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  "X           XXXXX           X",
  "X XXX XXXXX XXXXX XXXXX XXX X",
  "X XXX XXXXX XXXXX XXXXX XXX X",
  "X                           X",
  "X XXX XX XXXXXXXXXXX XX XXX X",
  "X     XX     XXX     XX     X",
  "X XXX XXXXXX XXX XXXXXX XXX X",
  "X XXX XX             XX XXX X",
  "      XX XXXXXXXXXXX XX      ",
  "X XXX XX XXXXXXXXXXX XX XXX X",
  "X XXX XX             XX XXX X",
  "X XXX XXXXXX XXX XXXXXX XXX X",
  "X     XX     XXX     XX     X",
  "X XXX XX XXXXXXXXXXX XX XXX X",
  "X XXX                   XXX X",
  "X XXX XXXX XXXXXXXX XXX XXX X",
  "X XXX XXXX          XXX XXX X",
  "X          XXXXXXXX         X",
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};

vector<string> n={
  "XXXXXXXXXXXXXX XXXXXXXXXXXXXX",
  "X           XX XX           X",
  "X XXX XXXXX XX XX XXXXX XXX X",
  "X XXX XXXXX XX XX XXXXX XXX X",
  "X                           X",
  "X XXX XX XXXXXXXXXXX XX XXX X",
  "X     XX     XXX     XX     X",
  "X XXX XXXXXX XXX XXXXXX XXX X",
  "X XXX XXo           oXX XXX X",
  "      XX             XX      ",
  "X XXX XX             XX XXX X",
  "X XXX XXo           oXX XXX X",
  "X XXX XXXXXX XXX XXXXXX XXX X",
  "X     XX     XXX     XX     X",
  "X XXX XX XXXXXXXXXXX XX XXX X",
  "X XXX                   XXX X",
  "X XXX XXXX XXXXXXXX XXX XXX X",
  "X XXX XXXX          XXX XXX X",
  "X          XXX XXXX         X",
  "XXXXXXXXXXXXXX XXXXXXXXXXXXXX",
};

int main(int argc, char **argv){
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,880,600,0,0);
    Lista<Mapa> xs;
    //Mapa *A=new Mapa1(m);
    //Mapa *B=new Mapa1(n);
    Mapa A(m);
    Mapa B(n);
    xs.push(A);
    xs.push(B);
    xs.tail().imprimir();
    //Nodo *pt=xs.Head();
    //pt->m_next->m_key.imprimir();
    //A.imprimir();
}
END_OF_MAIN();
