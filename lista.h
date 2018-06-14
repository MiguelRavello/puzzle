#ifndef LISTA_H
#define LISTA_H

#include"mapa.h"

template<class T>
class Nodo{
private:
    T m_key;
    Nodo<T> *m_next;
    Nodo<T> *m_back;
    template<class U> friend class ListaMapa;
public:
    Nodo(const T val=0):m_key(val), m_next(NULL), m_back(NULL) {}
    Nodo(const Nodo<T> *o):m_key(o->m_key), m_next(o->m_next), m_back(o->m_back) {}
    void setKey(const T val) {  m_key=val;}
    T getKey() {    return this->m_key;}
};

template<class T>
class ListaMapa {
private:
    int m_size;
    //template<class U> friend class Hero;
    Nodo<T> *m_head;
    Nodo<T> *m_cola;
public:
    ListaMapa():m_head(NULL), m_cola(NULL), m_size(0) {}
    ListaMapa(const ListaMapa &m);
    void setListaMapa(vector<T> xs);
    void push(const T);
    void pop_head();
    int getLen(){   return m_size;}
    bool empty();
    T top();
    void xOR(const T); //para la resta
    void sOR(const T); // para la suma
    void operator=(const ListaMapa &o);
    ListaMapa<T> operator+(const ListaMapa &o);
    ListaMapa<T> operator-(const ListaMapa &o);
};

template<class T>
ListaMapa<T>::ListaMapa(const ListaMapa &m){
    Nodo<T> *xs;
    xs=m.m_head;
    while(xs!=NULL){
        this->push(xs->getKey());
        xs=xs->m_next;
    }
    delete xs;
}

template<class T>
void ListaMapa<T>::operator=(const ListaMapa &o){
    Nodo<T> *xs;
    xs=o.m_head;
    while(xs!=NULL){
        this->push(xs->getKey());
        xs=xs->m_next;
    }
    delete xs;
}

template<class T>
void ListaMapa<T>::push(const T val){
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
        xs->m_back=prev;
        m_cola=xs;
        m_size++;
    }
}

template<class T>
void ListaMapa<T>::setListaMapa(vector<T> xs){
    for(int i=0;i<xs.size();i++)
        this->push(xs[i]);
}

template<class T>
void ListaMapa<T>::pop_head(){
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
bool ListaMapa<T>::empty(){
    if(m_head==NULL)
        return true;
    return false;
}

template<class T>
T ListaMapa<T>::top(){
    return m_head->getKey();
}

template<class T>
void ListaMapa<T>::xOR(const T e){
    Nodo<T> *prev, *cur, *victima;
    prev=this->m_head;
    cur=this->m_head->m_next;
    if(prev->getKey()==e){
        m_head=cur;
        delete prev;
        m_size--;
    }
    else{
        while(cur!=NULL){
            if(cur->getKey()==e){
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
void ListaMapa<T>::sOR(const T e){
    Nodo<T> *xs;
    xs=this->m_head;
    bool v=false;
    while(xs!=NULL){
        if(e==xs->getKey()){
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
ListaMapa<T> ListaMapa<T>::operator-(const ListaMapa &o){
    ListaMapa<T> rpta;
    Nodo<T> *xs;
	xs=this->m_head;
	while(xs!=NULL){
		rpta.push(xs->getKey());
		xs=xs->m_next;
	}
    xs=o.m_head;
    while(xs!=NULL){
        rpta.xOR(xs->getKey());
        xs=xs->m_next;
    }
    return rpta;

}

template<class T>
ListaMapa<T> ListaMapa<T>::operator+(const ListaMapa &o){
    ListaMapa<T> rpta; // No me reconoce el constructor copia ListaMapa<T> r=*this;
    Nodo<T> *xs;
    xs=this->m_head;
    while(xs!=NULL){
        rpta.push(xs->getKey());
        xs=xs->m_next;
    }
    xs=o.m_head;
    while(xs!=NULL){
        rpta.sOR(xs->getKey());
        xs=xs->m_next;
    }
    return rpta;
}

#endif
