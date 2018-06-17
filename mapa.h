#ifndef MAPA_H
#define MAPA_H

#include<allegro.h>
#include<string>
#include"matrix.h"

class Mapa{
private:
    Matrix<char> m_mapa;
    BITMAP *m_buffer;
    BITMAP *m_roca;
    friend class Nodo;
    friend class ListaMapa;
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
    this->m_roca=m.m_roca;
}

void Mapa::operator=(const Mapa &o){
    m_mapa=o.m_mapa;
    this->m_buffer=o.m_buffer;
    this->m_roca=o.m_roca;
}

bool Mapa::operator==(const Mapa &o){
    return m_mapa==o.m_mapa;
}

Mapa::Mapa(const vector<string> xs){
    Matrix<char> temp(xs);
    this->m_mapa=temp;
    m_buffer = create_bitmap(928,640);
    m_roca = load_bitmap("./soporte/roca.bmp",NULL);
}

void Mapa::dibujar_mapa(){
    for(int i=0;i<m_mapa.m_row;i++){
        for(int j=0;j<m_mapa.m_col;j++){
            if(*(*(m_mapa.m_matrix+i)+j)=='X')
                draw_sprite(m_buffer,m_roca,j*30,i*30);
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
