#ifndef LISTA_H
#define LISTA_H

#include"mapa.h"
#include"mapa.cpp"

template<class T>
class Nodo{
private:
    T m_key;
    Nodo<T> *m_next;
    Nodo<T> *m_back;
    template<class U> friend class Lista;
public:
    Nodo(const T val=0):m_key(val), m_next(NULL), m_back(NULL) {}
    Nodo(const Nodo<T> *o):m_key(o->m_key), m_next(o->m_next), m_back(o->m_back) {}
    void setKey(const T val) {  m_key=val;}
    T getKey() {    return this->m_key;}
};

template<class T>
class Lista {
private:
    int m_size;
    Nodo<T> *m_head;
    Nodo<T> *m_cola;
    //template<class U> friend class Hero;
public:
    Lista():m_head(NULL), m_cola(NULL), m_size(0) {}
    Lista(const Lista &m);
    void setLista(vector<T> xs);
    void push(const T);
    void pop_head();
    int getLen(){   return m_size;}
    bool empty();
    T top();
    T tail();
    Nodo<T>* Head(){    return m_head;}
    Nodo<T>* Cola(){    return m_cola;}
    void xOR(T); //para la resta
    void sOR(T); // para la suma

    void operator=(const Lista &o);
    Lista<T> operator+(Lista &o);
    Lista<T> operator-(Lista &o);
};

template<class T>
Lista<T>::Lista(const Lista &m){
    Nodo<T> *xs;
    xs=m.m_head;
    while(xs!=NULL){
        this->push(xs->getKey());
        xs=xs->m_next;
    }
    delete xs;
}

template<class T>
void Lista<T>::operator=(const Lista &o){
    Nodo<T> *xs;
    xs=o.m_head;
    while(xs!=NULL){
        this->push(xs->getKey());
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
        Nodo<T>* prev, *cur;
        prev=m_head;
        cur=m_head->m_next;
        while(cur!=NULL){
            prev=cur;
            cur=cur->m_next;
        }
        prev->m_next=xs;
        m_cola=xs;
        m_size++;
    }
}

template<class T>
void Lista<T>::setLista(vector<T> xs){
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
    else{
        m_head=cur;
        delete prev;
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
    return m_head->getKey();
}

template<class T>
T Lista<T>::tail(){
    return m_cola->getKey();
}

template<class T>
void Lista<T>::xOR(T e){
    Nodo<T> *prev, *cur, *victima;
    prev=this->m_head;
    cur=this->m_head->m_next;
    if(prev->m_key == e){
        m_head=cur;
        delete prev;
        m_size--;
    }
    else{
        while(cur!=NULL){
            if(cur->m_key == e){
                prev->m_next=cur->m_next;
                cur->m_next->m_back=prev;
                victima=cur;
                delete victima;
                m_size--;
                break;
            }
            prev=cur;
            cur=cur->m_next;
        }
    }
}

template<class T>
void Lista<T>::sOR(T e){
    Nodo<T> *xs;
    xs=this->m_head;
    bool v=false;
    while(xs!=NULL){
        if(e == xs->m_key){
            v=true;
            break;
        }
        else
            xs=xs->m_next;
    }
    if(v)
        ;
    else
        this->push(e);
}

template<class T>
Lista<T> Lista<T>::operator-(Lista &o){
    Lista<T> rpta;
    Nodo<T> *xs;
	xs=this->m_head;
	while(xs!=NULL){
		rpta.push(xs->m_key);
		xs=xs->m_next;
	}
    xs=o.m_head;
    while(xs!=NULL){
        rpta.xOR(xs->m_key);
        xs=xs->m_next;
    }
    return rpta;

}

template<class T>
Lista<T> Lista<T>::operator+(Lista &o){
    Lista<T> rpta;
    Nodo<T> *xs;
    xs=this->m_head;
    while(xs!=NULL){
        rpta.push(xs->m_key);
        xs=xs->m_next;
    }
    xs=o.m_head;
    while(xs!=NULL){
        rpta.sOR(xs->m_key);
        xs=xs->m_next;
    }
    return rpta;
}

#endif
