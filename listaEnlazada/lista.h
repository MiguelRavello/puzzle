#ifndef LISTA_H
#define LISTA_H

#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Lista;

template<class T>
class Iterador;

template<class T>
ostream& operator<< (ostream&, const Lista<T>&);

template<class T>
class Nodo{
private:
    T m_key;
    Nodo<T> *m_next;
    Nodo<T> *m_back;
    template<class U> friend class Lista;
    template<class U> friend class Iterador;
public:
    Nodo(const T val=0):m_key(val), m_next(NULL), m_back(NULL){}
    Nodo(const Nodo<T> *o):m_key(o->m_key), m_next(o->m_next), m_back(o->m_back){}
    void setKey(const T val) {  m_key=val;}
    T getKey() {    return this->m_key;}
    Nodo<T>* next(){    return this->m_next;}
    Nodo<T>* back(){    return this->m_back;}
};

template<class T>
class Lista {
private:
    int m_size;
    Nodo<T> *m_head;
    Nodo<T> *m_cola;
    template<class U> friend class Iterador;
    friend ostream& operator<< <>(ostream& out, const Lista&);
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
    void xOR(T); //para la resta; remueve el nodo que tenga el valor q le piden;
    void sOR(T); // para la suma

    void operator=(const Lista &o);
    Lista<T> operator+(Lista &o);
    Lista<T> operator-(Lista &o);
    Iterador<T>* crearIterador() const;
};

template<class T>
class Iterador{
private:
    const Lista<T> *m_lista;
    Nodo<T> *m_indice;
    template<class U> friend class Lista;
public:
    enum{
        Nada, Adelante, Atras, Imprimir, Inicio, Fin
    };
    Iterador(const Lista<T> *m);
    Iterador(const Iterador &m);
    void inicio();
    void fin();
    void siguiente();
    void anterior();
    bool isDone();
    T currentItem();
    void testIterador(int);
    void operator++(){  this->m_indice=this->m_indice->m_next; }
    void operator++(int){   this->m_indice=this->m_indice->m_next; }
    void operator--(){  m_indice=m_indice->m_back;}
    void operator--(int){  m_indice=m_indice->m_back;}
    T& operator*(){ return m_indice->m_key;}
};

#endif
