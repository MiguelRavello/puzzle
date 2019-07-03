#include"mapa.h"

Mapa1::Mapa1(const Mapa1 &m){
    m_mapa=m.m_mapa;
    m_usuario=m.m_usuario;
    m_bloque=m.m_bloque;
    this->m_buffer=m.m_buffer;
    this->m_balla=m.m_balla;
    this->m_piso=m.m_piso;
    this->m_star=m.m_star;
}

void Mapa1::operator=(const Mapa1 &o){
    m_mapa=o.m_mapa;
    m_usuario=o.m_usuario;
    m_bloque=o.m_bloque;
    this->m_buffer=o.m_buffer;
    this->m_balla=o.m_balla;
    this->m_piso=o.m_piso;
    this->m_star=o.m_star;
}

bool Mapa1::operator==(const Mapa1 &o){
    return m_mapa==o.m_mapa;
}


Mapa1::Mapa1(const std::vector<string> xs){
    Matrix<char> temp(xs);
    this->m_mapa=temp;
    this->cargar();
}

void Mapa1::cargar(){
    m_buffer = create_bitmap(940,640);
    m_balla = load_bitmap("./soporte/roca.bmp",NULL);
    m_piso  = load_bitmap("./soporte/level1/mpiso.bmp",NULL);
    m_star  = load_bitmap("./soporte/level1/mstar.bmp",NULL);
}

/************** Mapa 2 *************/
Mapa2::Mapa2(const Mapa2 &m){
    m_mapa=m.m_mapa;
    m_usuario=m.m_usuario;
    m_bloque=m.m_bloque;
    this->m_buffer=m.m_buffer;
    this->m_balla=m.m_balla;
    this->m_piso=m.m_piso;
    this->m_star=m.m_star;
}

void Mapa2::operator=(const Mapa2 &o){
    m_mapa=o.m_mapa;
    m_bloque=o.m_bloque;
    this->m_buffer=o.m_buffer;
    this->m_balla=o.m_balla;
    this->m_piso=o.m_piso;
    this->m_star=o.m_star;
}

bool Mapa2::operator==(const Mapa2 &o){
    return m_mapa==o.m_mapa;
}


Mapa2::Mapa2(const std::vector<string> xs){
    Matrix<char> temp(xs);
    this->m_mapa=temp;
    this->cargar();
}

void Mapa2::cargar(){
    m_buffer = create_bitmap(940,640);
    m_balla = load_bitmap("./soporte/level1/mballa.bmp",NULL);
    m_piso  = load_bitmap("./soporte/level1/mpiso.bmp",NULL);
    m_star  = load_bitmap("./soporte/level1/mstar.bmp",NULL);
}

/*************************************************/
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

void Mapa::dibujar_personaje(){
    blit(m_usuario.m_bmp, m_usuario.m_personaje ,(m_usuario.m_dir)*33 ,0,0,0,33,33);
    draw_sprite(m_buffer,m_usuario.m_personaje,m_usuario.m_px,m_usuario.m_py);
}

void Mapa::dibujar_bloque(){
    blit(m_bloque.m_bmp,m_bloque.m_personaje,0,0,0,0,30,30);
    draw_sprite(m_buffer,m_bloque.m_personaje,m_bloque.m_px,m_bloque.m_py);
}

void Mapa::imprimir(){
    while(!key[KEY_ESC]){
        m_usuario.setDir();
        setPos();
        clear(m_buffer);
        dibujar_mapa();
        dibujar_personaje();
        pantalla();
        rest(50);
    }
}

void Mapa::setPos(){
    if(m_usuario.m_dir==0){
        if(m_mapa.m_matrix[m_usuario.m_py/30][(m_usuario.m_px-30)/30]!='X')
            m_usuario.m_px -=30;
        else
            m_usuario.m_dir=-1;
    }
    else if(m_usuario.m_dir==1){
        if(m_mapa.m_matrix[m_usuario.m_py/30][(m_usuario.m_px+30)/30]!='X')
            m_usuario.m_px +=30;
        else
            m_usuario.m_dir=-1;
    }
    else if(m_usuario.m_dir==2){
        if(m_mapa.m_matrix[(m_usuario.m_py-30)/30][m_usuario.m_px/30]!='X')
            m_usuario.m_py -=30;
        else
            m_usuario.m_dir=-1;
    }
    else if(m_usuario.m_dir==3){
        if(m_mapa.m_matrix[(m_usuario.m_py+30)/30][m_usuario.m_px/30]!='X')
            m_usuario.m_py +=30;
        else
            m_usuario.m_dir=-1;
    }
}

void Mapa::golpear(){
    if(m_usuario.m_dir==0 && key[KEY_SPACE]){
        m_bloque.m_dir=0;
    }
    else if(m_usuario.m_dir==1 && key[KEY_SPACE]){
        m_bloque.m_dir=1;
    }
    else if(m_usuario.m_dir==2 && key[KEY_SPACE]){
        m_bloque.m_dir=2;
    }
    else if(m_usuario.m_dir==3 && key[KEY_SPACE]){
        m_bloque.m_dir=3;
    }
}

void Mapa::movimiento_bloque(){
    if(m_bloque.m_dir==0){
        if(m_mapa.m_matrix[m_bloque.m_py/30][(m_bloque.m_px-30)/30]!='X')
            m_bloque.m_px -=30;
        else
            m_bloque.m_dir=-1;
    }
    else if(m_bloque.m_dir==1){
        if(m_mapa.m_matrix[m_bloque.m_py/30][(m_bloque.m_px+30)/30]!='X')
            m_bloque.m_px +=30;
        else
            m_bloque.m_dir=-1;
    }
    else if(m_bloque.m_dir==2){
        if(m_mapa.m_matrix[(m_bloque.m_py-30)/30][m_bloque.m_px/30]!='X')
            m_bloque.m_py -=30;
        else
            m_bloque.m_dir=-1;
    }
    else if(m_bloque.m_dir==3){
        if(m_mapa.m_matrix[(m_bloque.m_py+30)/30][m_bloque.m_px/30]!='X')
            m_bloque.m_py +=30;
        else
            m_bloque.m_dir=-1;
    }
}
