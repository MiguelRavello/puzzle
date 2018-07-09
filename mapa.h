#ifndef MAPA_H
#define MAPA_H

#include<allegro.h>
#include<string>
#include"matrix.h"

/*
class Mapa{
protected:
    Mapa *m_next;
public:
    friend class Nodo;
    friend class ListaMapa;

    Mapa():m_next(NULL){}
    void setNext(Mapa *siguiente){  m_next=siguiente;}
    virtual void dibujar_mapa()=0;
    virtual void pantalla()=0;
    virtual void imprimir()=0;
};*/

class Mapa{
private:
    Matrix<char> m_mapa;
    BITMAP *m_buffer;
    BITMAP *m_balla;
    BITMAP *m_piso;
    BITMAP *m_star;
    template<class U> friend class Nodo;
    template<class U> friend class Lista;
public:
    Mapa(const Mapa &m);
    void operator=(const Mapa &o);
    bool operator==(const Mapa &o);
    Mapa(const vector<string> xs);
    void dibujar_mapa();
    void pantalla();
    void imprimir();
};

Mapa::Mapa(const Mapa &m){
    m_mapa=m.m_mapa;
    this->m_buffer=m.m_buffer;
    this->m_balla=m.m_balla;
    this->m_piso=m.m_piso;
    this->m_star=m.m_star;
}

void Mapa::operator=(const Mapa &o){
    m_mapa=o.m_mapa;
    this->m_buffer=o.m_buffer;
    this->m_balla=o.m_balla;
    this->m_piso=o.m_piso;
    this->m_star=o.m_star;
}

bool Mapa::operator==(const Mapa &o){
    return m_mapa==o.m_mapa;
}

Mapa::Mapa(const vector<string> xs){
    Matrix<char> temp(xs);
    this->m_mapa=temp;
    m_buffer = create_bitmap(940,640);
    m_balla = load_bitmap("./soporte/level1/mballa.bmp",NULL);
    m_piso  = load_bitmap("./soporte/level1/mpiso.bmp",NULL);
    m_star  = load_bitmap("./soporte/level1/mstar.bmp",NULL);
}

void Mapa::dibujar_mapa(){
    for(int i=0;i<m_mapa.m_row;i++){
        for(int j=0;j<m_mapa.m_col;j++){
            if(*(*(m_mapa.m_matrix+i)+j)=='X')
                draw_sprite(m_buffer,m_balla,j*30,i*30);
            else if(*(*(m_mapa.m_matrix+i)+j)==' ')
                draw_sprite(m_buffer,m_piso,j*30,i*30);
            else if(*(*(m_mapa.m_matrix+i)+j)=='o')
                draw_sprite(m_buffer,m_star,j*30,i*30);
        }
    }
}

void Mapa::pantalla(){
    blit(m_buffer,screen,0,0,0,0,880,600);
}

void Mapa::imprimir(){
    while(!key[KEY_ESC]){
        dibujar_mapa();
        pantalla();
    }
}

#endif
