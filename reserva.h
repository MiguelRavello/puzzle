/* #ifndef LISTA_H
#define LISTA_H

#include"mapa.h"

class Nodo{
private:
    Mapa m_key;
    Nodo *m_next;
    Nodo *m_back;
    friend class ListaMapa;
public:
    Nodo(const Mapa val):m_key(val), m_next(NULL), m_back(NULL) {}
    Nodo(const Nodo *o):m_key(o->m_key), m_next(o->m_next), m_back(o->m_back) {}
    void setKey(const Mapa val) {  m_key=val;}
    Mapa getKey() {    return this->m_key;}
};

class ListaMapa {
private:
    int m_size;
    //template<class U> friend class Hero;
    Nodo *m_head;
    Nodo *m_cola;

public:
    ListaMapa():m_head(NULL), m_cola(NULL), m_size(0) {}
    ListaMapa(const ListaMapa &m);
    void setListaMapa(vector<Mapa> xs);
    void push(const Mapa);
    void pop_head();
    int getLen(){   return m_size;}
    bool empty();

    Mapa top();
    Mapa tail();
    Nodo* Head(){   return m_head;}
    Nodo* Cola(){   return m_cola;}
    void xOR(Mapa); //para la resta   error con const
    void sOR(Mapa); // para la suma
    void operator=(const ListaMapa &o);
    ListaMapa operator+(ListaMapa &o);
    ListaMapa operator-(ListaMapa &o);
};

ListaMapa::ListaMapa(const ListaMapa &m){
    Nodo *xs;
    xs=m.m_head;
    while(xs!=NULL){
        this->push(xs->m_key);
        xs=xs->m_next;
    }
    delete xs;
}

void ListaMapa::operator=(const ListaMapa &o){
    Nodo *xs;
    xs=o.m_head;
    while(xs!=NULL){
        this->push(xs->m_key);
        xs=xs->m_next;
    }
    delete xs;
}

void ListaMapa::push(const Mapa val){
    Nodo *xs=new Nodo(val);
    if(m_head==NULL){
        m_head=xs;
        m_cola=xs;
        m_size++;
    }
    else{
        Nodo* prev, *cur;
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

void ListaMapa::setListaMapa(vector<Mapa> xs){
    for(int i=0;i<xs.size();i++)
        this->push(xs[i]);
}

void ListaMapa::pop_head(){
    Nodo* prev, *cur;
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

bool ListaMapa::empty(){
    if(m_head==NULL)
        return true;
    return false;
}

Mapa ListaMapa::top(){
    return m_head->getKey();
}

Mapa ListaMapa::tail(){
    return m_cola->getKey();
}

void ListaMapa::xOR(Mapa e){
    Nodo *prev, *cur, *victima;
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

void ListaMapa::sOR(Mapa e){
    Nodo *xs;
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

ListaMapa ListaMapa::operator-(ListaMapa &o){
    ListaMapa rpta;
    Nodo *xs;
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

ListaMapa ListaMapa::operator+(ListaMapa &o){
    ListaMapa rpta; // No me reconoce el constructor copia ListaMapa r=*this;
    Nodo *xs;
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

#endif */
