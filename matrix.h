#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include<vector>
#include"mapa.h"

using namespace std;

template<class T>
class Matrix {
private:
    T **m_matrix;
    int m_row;
    int m_col;
    friend class Mapa1;
    template<class U> friend class Lista;
    template<class U> friend class Nodo;
public:
    Matrix():m_row(0),m_col(0){}
    Matrix(int,int);
    Matrix(const vector<vector<T> > xs);
    Matrix(const vector<T> xs); //matrix m_filas x cero;
    Matrix(const Matrix &m);
    ~Matrix(){
        for(int i=0;i<m_row;i++)
            delete[] m_matrix[i];
        delete[] m_matrix;
    }
    Matrix<T> operator+ (const Matrix &o);
    void operator= (const Matrix &o);
    bool operator== (const Matrix &o);

    void resizeCol(int size);
    void insertCol(const vector<T> xs);
    void inicializar();
    void setMatrix(const vector<vector<T> > xs);
    void zerox();
    void identidad();
    void imprimir();
    void swapRow(int fila_1, int fila_2);
    vector<T> getCol(const int pos);
};

template<>
class Matrix<char>{
public:
    char **m_matrix;
    int m_row;
    int m_col;
    friend class Mapa1;
    template<class U> friend class Nodo;
    template<class U> friend class Lista;
public:
    Matrix():m_row(0),m_col(0){}
    Matrix(const vector<string> xs):m_row(xs.size()),m_col(xs[0].length()){
        m_matrix= new char*[m_row];
        for(int k=0;k<m_row;k++)
            m_matrix[k]=new char[m_col];
        for(int i=0;i<m_row;i++){
            for(int j=0;j<m_col;j++){
                *(*(m_matrix+i)+j)=xs[i][j];
            }
        }
    }
    ~Matrix(){
        for(int i=0;i<m_row;i++)
            delete[] m_matrix[i];
        delete[] m_matrix;
    }
    void operator=(const Matrix &o){
        m_row=o.m_row;
        m_col=o.m_col;
        m_matrix=new char*[m_row];
        for(int k=0;k<m_row;k++){
            m_matrix[k]=new char[m_col];
        }
        for(int i=0;i<m_row;i++){
            for(int j=0;j<m_col;j++){
                *(*(m_matrix + i) + j)=*(*(o.m_matrix + i) + j);
            }
        }
    }
    inline bool operator==(const Matrix &o){
        for(int i=0;i<m_row;i++){
            for(int j=0;j<m_col;j++){
                if(*(*(m_matrix + i) + j) != *(*(o.m_matrix + i) + j)){
                    return false;
                }
            }
        }
        return true;
    }
};

template<class T>
Matrix<T>::Matrix(int fila,int col):m_row(fila),m_col(col){
    m_matrix = new T*[m_row];
    for(int i=0;i<m_row;i++){
        m_matrix[i]=new T[m_col];
    }
}

template<class T>
Matrix<T>::Matrix(const vector<vector<T> > xs):m_row(xs.size()),m_col(xs[0].size()){
    m_matrix = new T*[m_row];
    for(int k=0;k<m_row;k++)
        m_matrix[k]=new T[m_col];
    for (int i=0; i < m_row; i++){
        for (int j=0; j < m_col; j++){
            *(*(m_matrix + i) + j)=xs[i][j];
        }
    }
}

template<class T>
Matrix<T>::Matrix(const vector<T> xs):m_row(xs.size()),m_col(0){
    m_matrix = new T*[m_row];
    for(int k=0;k<m_row;k++)
        m_matrix[k]=new T[m_col];
    insertCol(xs);
}
template<class T>
Matrix<T>::Matrix(const Matrix &m):m_row(m.m_row),m_col(m.m_col){
    m_matrix = new T*[m_row];
    for(int k=0;k<m_row;k++){
        m_matrix[k]=new T[m_col];
    }
    for (int i=0; i < m_row; i++){
        for (int j=0; j < m_col; j++){
            *(*(m_matrix + i) + j)=*(*(m.m_matrix + i) + j);
        }
    }
}

template<class T>
void Matrix<T>::inicializar(){
    cout<<"ingrese los valores de la matrix: "<<endl;
    int elem;
    for (int i=0; i < m_row; i++){
        for (int j=0; j < m_col; j++){
            cout << "\nRow " << (i+1) << " Col " << (j+1) << " :";
            cin >> elem;
            m_matrix[i][j]=elem;
        }
    }
}

template<class T>
void Matrix<T>::setMatrix(const vector<vector<T> > xs){
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++)
            this->m_matrix[i][j]=xs[i][j];
    }
}

template<class T>
void Matrix<T>::zerox(){
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++)
            m_matrix[i][j]=0;
    }
}

template<class T>
void Matrix<T>::identidad(){
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            if(i==j)
                m_matrix[i][j]=1;
            else
                m_matrix[i][j]=0;
        }
    }
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix &o){
    Matrix rpta(m_row,m_col);
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            rpta.m_matrix[i][j]=m_matrix[i][j]+o.m_matrix[i][j];
        }
    }
    return rpta;
}

template<class T>
void Matrix<T>::operator=(const Matrix &o){
    m_row=o.m_row;
    m_col=o.m_col;
    m_matrix=new T*[m_row];
    for(int k=0;k<m_row;k++){
        m_matrix[k]=new T[m_col];
    }
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            *(*(m_matrix + i) + j)=*(*(o.m_matrix + i) + j);
        }
    }
}

template<class T>
bool Matrix<T>::operator==(const Matrix &o){
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            if(*(*(m_matrix + i) + j) != *(*(o.m_matrix + i) + j)){
                return false;
            }
        }
    }
    return true;
}

template<class T>
void Matrix<T>::imprimir(){
    for(int i=0;i<m_row;i++){
        for(int j=0;j<m_col;j++){
            cout<<m_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

template<class T>
void Matrix<T>::resizeCol(int nuevo){
    int minsize=(nuevo>m_col ? m_col : nuevo);
    for(int i=0;i<m_row;i++){
        T *xs=new T[nuevo];
        for(int j=0;j<minsize;j++){
            xs[j]=m_matrix[i][j];
        }
        delete[] m_matrix[i];
        m_matrix[i]=xs;
    }
    m_col=nuevo;
}

template<class T>
void Matrix<T>::insertCol(const vector<T> xs){
    resizeCol(m_col+1);
    for(int i=0;i<m_row;i++)
        m_matrix[i][m_col-1]=xs[i];
}

template<class T>
void Matrix<T>::swapRow(int fila_1,int fila_2){
    if(fila_1>m_row || fila_2>m_row){
        cout<<"fila de rango"<<endl;
    }
    else{
        T temp;
        for(int i=0;i<m_col;i++){
            temp=m_matrix[fila_1][i];
            m_matrix[fila_1][i]=m_matrix[fila_2][i];
            m_matrix[fila_2][i]=temp;
        }
    }
}

template<class T>
vector<T> Matrix<T>::getCol(const int pos){
    vector<T> xs;
    for(int i=0;i<m_row;i++)
        xs.push_back(m_matrix[i][pos]);
    return xs;
}

#endif
