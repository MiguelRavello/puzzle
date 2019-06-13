#include"mapa.h"

Mapa1::Mapa1(const Mapa1 &m){
    m_mapa=m.m_mapa;
    m_usuario=m.m_usuario;
    this->m_buffer=m.m_buffer;
    this->m_balla=m.m_balla;
    this->m_piso=m.m_piso;
    this->m_star=m.m_star;
}

void Mapa1::operator=(const Mapa1 &o){
    m_mapa=o.m_mapa;
    m_usuario=o.m_usuario;
    this->m_buffer=o.m_buffer;
    this->m_balla=o.m_balla;
    this->m_piso=o.m_piso;
    this->m_star=o.m_star;
}

bool Mapa1::operator==(const Mapa1 &o){
    return m_mapa==o.m_mapa;
}


Mapa1::Mapa1(const vector<string> xs){
    Matrix<char> temp(xs);
    this->m_mapa=temp;
    this->cargar();
}

void Mapa1::cargar(){
    m_buffer = create_bitmap(940,640);
    m_balla = load_bitmap("./soporte/roca.bmp",NULL);
    m_piso  = load_bitmap("./soporte/level1/mpiso.bmp",NULL);
    m_star  = load_bitmap("./soporte/level1/mstar.bmp",NULL);
    //m_usuario.m_bmp = load_bitmap("./soporte/pacman.bmp",NULL);
    //m_usuario.m_personaje = create_bitmap(33,33);
}

void Mapa1::dibujar_mapa(){
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

void Mapa1::pantalla(){
    blit(m_buffer,screen,0,0,0,0,880,600);
}


void Mapa1::dibujar_personaje(){
    blit(m_usuario.m_bmp, m_usuario.m_personaje ,m_usuario.m_dir*33,0,0,0,33,33);
    draw_sprite(m_buffer,m_usuario.m_personaje,m_usuario.m_px,m_usuario.m_py);
}

void Mapa1::imprimir(){
    while(!key[KEY_ESC]){
        m_usuario.setDir();
        m_usuario.setPos();
        dibujar_mapa();
        dibujar_personaje();
        pantalla();
        rest(140);
    }
}

/************** Mapa 2 *************/
Mapa2::Mapa2(const Mapa2 &m){
    m_mapa=m.m_mapa;
    this->m_buffer=m.m_buffer;
    this->m_balla=m.m_balla;
    this->m_piso=m.m_piso;
    this->m_star=m.m_star;
}

void Mapa2::operator=(const Mapa2 &o){
    m_mapa=o.m_mapa;
    this->m_buffer=o.m_buffer;
    this->m_balla=o.m_balla;
    this->m_piso=o.m_piso;
    this->m_star=o.m_star;
}

bool Mapa2::operator==(const Mapa2 &o){
    return m_mapa==o.m_mapa;
}


Mapa2::Mapa2(const vector<string> xs){
    Matrix<char> temp(xs);
    this->m_mapa=temp;
    this->cargar();
}

void Mapa2::cargar(){
    m_buffer = create_bitmap(940,640);
    m_balla = load_bitmap("./soporte/level1/mballa.bmp",NULL);
    m_piso  = load_bitmap("./soporte/level1/mpiso.bmp",NULL);
    m_star  = load_bitmap("./soporte/level1/mstar.bmp",NULL);
   // m_usuario.m_bmp = load_bitmap("./soporte/pacman.bmp",NULL);
   // m_usuario.m_personaje = create_bitmap(33,33);
}

void Mapa2::dibujar_mapa(){
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

void Mapa2::pantalla(){
    blit(m_buffer,screen,0,0,0,0,880,600);
}

void Mapa2::dibujar_personaje(){
    blit(m_usuario.m_bmp, m_usuario.m_personaje ,(m_usuario.m_dir)*33 ,0,0,0,33,33);
    draw_sprite(m_buffer,m_usuario.m_personaje,m_usuario.m_px,m_usuario.m_py);
}

void Mapa2::imprimir(){
    while(!key[KEY_ESC]){
        m_usuario.setDir();
        m_usuario.setPos();
        clear(m_buffer);
        dibujar_mapa();
        dibujar_personaje();
        pantalla();
        rest(50);
    }
}

