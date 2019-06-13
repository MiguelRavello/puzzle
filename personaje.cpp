#include"personaje.h"

Personaje::Personaje(const Personaje &o){
    this->m_bmp=o.m_bmp;
    this->m_personaje=o.m_personaje;
    this->m_dir=o.m_dir;
    this->m_px=o.m_px;
    this->m_py=o.m_py;
}

Pacman::Pacman(const int dir=2,const int x=10,const int y=10):Personaje(dir,x,y){
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

void Pacman::setPos(){
    if(m_dir==0) m_px -=30; // <-
    else if(m_dir==1) m_px +=30; // ->
    else if(m_dir==2) m_py -=30; // ^up
    else if(m_dir==3) m_py +=30; // v down
    else if(m_dir==-1) ;
}
