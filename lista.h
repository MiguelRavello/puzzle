#ifndef LISTA_H
#define LISTA_H

#include"mapa.h"
#include"mapa.cpp"

using std::ostream;

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
    void setLista(std::vector<T> xs);
    void push(const T);
    void pop_head();
    int getLen(){   return m_size;}
    bool empty();
    T top();
    T tail();
    Nodo<T>* Head(){    return m_head;}
    Nodo<T>* Cola(){    return m_cola;}
    void operator=(const Lista &o);
    Iterador<T>* crearIterador() const;
};

template<class T>
class Iterador{
private:
    const Lista<T> *m_lista;
    Nodo<T> *m_indice;
public:
    enum{
        Nada, Adelante, Atras, Imprimir, Inicio, Fin
    };
    Iterador(const Lista<T> *m);
    void inicio();
    void fin();
    void siguiente();
    void anterior();
    bool isDone();
    T currentItem();
    void testIterador(int);
};

template<>
class Iterador<Mapa1>{
private:
    const Lista<Mapa1> *m_lista;
    Nodo<Mapa1> *m_indice;
public:
    Iterador(const Lista<Mapa1> *m);
    void inicio();
    void fin();
    void siguiente();
    void anterior();
    bool isDone();
    Mapa1 currentItem();
    void testIterador();
};

#endif