#ifndef MAPA_H
#define MAPA_H

#include<allegro.h>
#include<string>
#include"matrix.h"
#include"personaje.h"
#include"personaje.cpp"
#include"lista.h"

class Mapa{
protected:
    Matrix<char> m_mapa;
    Pacman m_usuario;
    Bloque m_bloque;
    BITMAP *m_buffer;
    BITMAP *m_balla;
    BITMAP *m_piso;
    BITMAP *m_star;
public:
    virtual void cargar()=0;
    void dibujar_mapa();
    void dibujar_personaje();
    void dibujar_bloque();
    void pantalla();
    void imprimir();
    void setPos();
    void movimiento_bloque();
    void golpear();
};

class Mapa1 : public Mapa{
private:
    template<class U> friend class Nodo;
    template<class U> friend class Lista;
    template<class U> friend class Iterador;
public:
    Mapa1(const Mapa1 &m);
    void operator=(const Mapa1 &o);
    bool operator==(const Mapa1 &o);
    Mapa1(const std::vector<string> xs);

    void cargar();
};

class Mapa2 : public Mapa{
private:
    template<class U> friend class Nodo;
    template<class U> friend class Lista;
    template<class U> friend class Iterador;
public:
    Mapa2(const Mapa2 &m);
    void operator=(const Mapa2 &o);
    bool operator==(const Mapa2 &o);
    Mapa2(const std::vector<string> xs);

    void cargar();
};

#endif
