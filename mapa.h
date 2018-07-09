#ifndef MAPA_H
#define MAPA_H

#include<allegro.h>
#include<string>
#include"matrix.h"


class Mapa{
protected:
    Matrix<char> m_mapa;
    BITMAP *m_buffer;
    BITMAP *m_balla;
    BITMAP *m_piso;
    BITMAP *m_star;
public:
    virtual void cargar()=0;
    virtual void dibujar_mapa()=0;
    virtual void pantalla()=0;
    virtual void imprimir()=0;
};

class Mapa1 : public Mapa{
private:
    template<class U> friend class Nodo;
    template<class U> friend class Lista;
public:
    Mapa1(const Mapa1 &m);
    void operator=(const Mapa1 &o);
    bool operator==(const Mapa1 &o);
    Mapa1(const vector<string> xs);

    void cargar();
    void dibujar_mapa();
    void pantalla();
    void imprimir();
};

class Mapa2 : public Mapa{
private:
    template<class U> friend class Nodo;
    template<class U> friend class Lista;
public:
    Mapa2(const Mapa2 &m);
    void operator=(const Mapa2 &o);
    bool operator==(const Mapa2 &o);
    Mapa2(const vector<string> xs);

    void cargar();
    void dibujar_mapa();
    void pantalla();
    void imprimir();
};

#endif
