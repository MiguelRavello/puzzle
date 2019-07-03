#include"personaje.h"

Personaje::Personaje(const Personaje &o){
    this->m_bmp=o.m_bmp;
    this->m_personaje=o.m_personaje;
    this->m_dir=o.m_dir;
    this->m_px=o.m_px;
    this->m_py=o.m_py;
}

Pacman::Pacman(const int dir=2,const int x=30,const int y=30):Personaje(dir,x,y){
    this->load();
}

Pacman::Pacman(const Pacman &m){
    this->m_bmp=m.m_bmp;
    this->m_personaje=m.m_personaje;
    this->m_dir=m.m_dir;
    this->m_px=m.m_px;
    this->m_py=m.m_py;
}

void Pacman::operator=(const Pacman &o){
    this->m_bmp=o.m_bmp;
    this->m_personaje=o.m_personaje;
    this->m_dir=o.m_dir;
    this->m_px=o.m_px;
    this->m_py=o.m_py;
}

void Pacman::load(){
    m_bmp=load_bitmap("./soporte/pacman.bmp",NULL);
    m_personaje=create_bitmap(33,33);
}

void Pacman::setDir(){
    if(key[KEY_LEFT])
        m_dir=0;
    else if(key[KEY_RIGHT])
        m_dir=1;
    else if(key[KEY_UP])
        m_dir=2;
    else if(key[KEY_DOWN])
        m_dir=3;
    else
        m_dir=-1; 
}

Bloque::Bloque(const int dir=2,const int x=120,const int y=120):Personaje(dir,x,y){
    this->load();
}

Bloque::Bloque(const Bloque &m){
    this->m_bmp=m.m_bmp;
    this->m_personaje=m.m_personaje;
    this->m_dir=m.m_dir;
    this->m_px=m.m_px;
    this->m_py=m.m_py;
}

void Bloque::operator=(const Bloque &o){
    this->m_bmp=o.m_bmp;
    this->m_personaje=o.m_personaje;
    this->m_dir=o.m_dir;
    this->m_px=o.m_px;
    this->m_py=o.m_py;
}

void Bloque::load(){
    m_bmp=load_bitmap("./soporte/enemigo.bmp",NULL);
    m_personaje=create_bitmap(30,30);
}

void Bloque::setDir(){
    /*necesita la interaccion del personaje
     * y la matriz del mapa para delimitar sus movimientos
     * por lo que sera implementado en el mapa*/;
}

