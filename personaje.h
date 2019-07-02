#ifndef PERSONAJE_H
#define PERSONAJE_H

#include<iostream>
using namespace std;
#include<allegro.h>
//include"mapa.h"
//temporal
class Personaje{
public:
    BITMAP *m_bmp;
    BITMAP *m_personaje;
    int m_dir; // direccion up down left right
    int m_px;  // posicion x
    int m_py; // posicion y
public:
    //me pedia Personaje();
    Personaje(const int dir=2,const int x=30,const int y=30):m_dir(dir),m_px(x),m_py(y){}
    Personaje(const Personaje &o);
    virtual void load()=0;
  //virtual void dibujar_personaje()=0;
    virtual void setDir()=0;
};

//clase prueba
class Pacman : public Personaje{
private:
//    friend class Mapa1;
//    friend class Mapa2;
public:
    Pacman(const int dir,const int x,const int y);
    Pacman(const Pacman &m);
    void operator=(const Pacman &o);
    void load();
  //void dibujar_personaje();
    void setDir();
};

#endif
