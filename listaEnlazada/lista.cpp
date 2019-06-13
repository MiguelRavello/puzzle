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
void Lista<T>::xOR(T e){
    Nodo<T> *prev, *cur, *victima;
    prev=this->m_head;
    cur=this->m_head->m_next;
    if(prev->m_key == e){
        m_head=cur;
        delete prev;
        m_head->m_back=NULL;
        m_size--;
    }
    else{
        while(cur!=NULL){
            if(cur->m_key == e){
                if(cur->m_next==NULL){
                    prev->m_next=cur->m_next;
                    victima=cur;
                    delete victima;
                    m_size--;
                    break;
                }
                else{
                    prev->m_next=cur->m_next;
                    cur->m_next->m_back=prev;
                    victima=cur;
                    delete victima;
                    m_size--;
                    break;
                }
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

