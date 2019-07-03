#include"lista.h"
template<class T>
ostream& operator<<(ostream& out,const Lista<T>& o){
	Nodo<T> *xs;
    xs=o.m_head;
    while(xs!=NULL){
        out<<xs->getKey()<<"->";
        xs=xs->next();
    }
    delete xs;
    return out;
}

template<class T>
Lista<T>::Lista(const Lista &m){
    Nodo<T> *xs;
    xs=m.m_head;
    m_size=0;
    while(xs!=NULL){
        this->push(xs->m_key);
        xs=xs->m_next;
    }
    delete xs;
}

template<class T>
void Lista<T>::operator=(const Lista &o){
    Nodo<T> *xs;
    xs=o.m_head;
    while(xs!=NULL){
        this->push(xs->m_key);
        xs=xs->m_next;
    }
    delete xs;
}

template<class T>
void Lista<T>::push(const T val){
    Nodo<T> *xs=new Nodo<T>(val);
    if(m_head==NULL){
        m_head=xs;
        m_cola=xs;
        m_size++;
    }
    else{
        Nodo<T> *prev, *cur;
        prev=m_head;
        cur=m_head->m_next;
        while(cur!=NULL){
            prev=cur;
            cur=cur->m_next;
        }
        prev->m_next=xs;
        xs->m_back=prev;
        m_cola=xs;
        m_size++;
        delete cur;
    }
}

template<class T>
void Lista<T>::setLista(std::vector<T> xs){
    for(int i=0;i<xs.size();i++)
        this->push(xs[i]);
}

template<class T>
void Lista<T>::pop_head(){
    Nodo<T>* prev, *cur;
    prev=m_head;
    cur=m_head->m_next;
    if(prev==NULL){
        ;
    }
    else if(m_head==m_cola){
        delete prev;
        m_head=NULL;
        m_cola=NULL;
        m_size--;
    }
    else{
        m_head=cur;
        delete prev;
        m_head->m_back=NULL; //
        if(m_head==NULL)
            m_cola=NULL;
        else
            m_size--;
    }
}

template<class T>
bool Lista<T>::empty(){
    if(m_head==NULL)
        return true;
    return false;
}

template<class T>
T Lista<T>::top(){
    return m_head->m_key;
}

template<class T>
T Lista<T>::tail(){
    return m_cola->m_key;
}

template<class T>
Iterador<T>* Lista<T>::crearIterador() const{
    return new Iterador<T>(this);
}
/***********************************************************************/
template<class T>
Iterador<T>::Iterador(const Lista<T> *m){
    this->m_lista=m;
}

template<class T>
void Iterador<T>::inicio(){
    this->m_indice=this->m_lista->m_head;
}

template<class T>
void Iterador<T>::fin(){
    this->m_indice=this->m_lista->m_cola;
}

template<class T>
void Iterador<T>::siguiente(){
    this->m_indice=this->m_indice->m_next;
}

template<class T>
void Iterador<T>::anterior(){
    this->m_indice=this->m_indice->m_back;
}

template<class T>
bool Iterador<T>::isDone(){
    return m_indice!=NULL;
}

template<class T>
T Iterador<T>::currentItem(){
    return m_indice->m_key;
}

template<class T>
void Iterador<T>::testIterador(int ans){
    if(ans==Adelante)
        m_indice=m_indice->m_next;
    else if(ans==Atras)
        m_indice=m_indice->m_back;
    else if(ans==Imprimir)
        cout<<m_indice->m_key<<"<->"<<endl;
    else if(ans==Inicio)
        m_indice=m_lista->m_head;
    else if(ans==Fin)
        m_indice=m_lista->m_cola;
}
/**************************************************************************/
Iterador<Mapa1>::Iterador(const Lista<Mapa1> *m){
    this->m_lista=m;
}

void Iterador<Mapa1>::inicio(){
    this->m_indice=this->m_lista->m_head;
}

void Iterador<Mapa1>::fin(){
    this->m_indice=this->m_lista->m_cola;
}

void Iterador<Mapa1>::siguiente(){
    this->m_indice=this->m_indice->m_next;
}

void Iterador<Mapa1>::anterior(){
    this->m_indice=this->m_indice->m_back;
}

bool Iterador<Mapa1>::isDone(){
    return m_indice!=NULL;
}

Mapa1 Iterador<Mapa1>::currentItem(){
    return m_indice->m_key;
}

void Iterador<Mapa1>::testIterador(){
    while(!key[KEY_ESC]){
        m_indice->m_key.m_usuario.setDir();
        m_indice->m_key.setPos();
        m_indice->m_key.golpear();
        m_indice->m_key.movimiento_bloque();
        if(m_indice->m_key.m_usuario.m_px <= -30){
            m_indice=m_indice->m_back;
            m_indice->m_key.m_usuario.m_px=840;
        }
        else if(m_indice->m_key.m_usuario.m_px >= 870){
            m_indice=m_indice->m_next;
            m_indice->m_key.m_usuario.m_px=30;
        }
        clear(m_indice->m_key.m_buffer);
        m_indice->m_key.dibujar_mapa();
        m_indice->m_key.dibujar_personaje();
        m_indice->m_key.dibujar_bloque();
        m_indice->m_key.pantalla();
        rest(70);
    }
}