#include"lista.h"
#include"lista.cpp" 

int main(){
    cout<<"Suma de la Lista A & B"<<endl;
    vector<int> a= {1,2,3,4};
    Lista<int> A;
    A.setLista(a);
    vector<int> b= {3,4,5,6,7};
    Lista<int> B;
    B.setLista(b);
    cout<<A<<endl;
    cout<<B<<endl;
    Lista<int> C;
    C=A+B;
    cout<<C<<endl;
    cout<<"........................"<<endl;
    cout<<"Resta de la lista Y sobre X"<<endl;
    vector<int> p= {1,2,3,4,5};
    Lista<int> X;
    X.setLista(p);
    vector<int> q= {4,5,6,7};
    Lista<int> Y;
    Y.setLista(q);
    Lista<int> Z;
    cout<<X<<endl;
    cout<<Y<<endl;
    Z=X-Y;
    cout<<Z<<endl;
    cout<<"........................"<<endl;
    cout<<"iteracion de la Lista C"<<endl;
    Iterador<int> *it = C.crearIterador();
    for(it->inicio();it->isDone(); ++(*it) )
        cout<< *(*it) <<"->";
    cout<<endl;
    for(it->fin();it->isDone();--(*it))
        cout<<"<-"<< *(*it);
    cout<<endl;
    cout<<"........................"<<endl;
    cout<<"Personalizado"<<endl;
    it->inicio();
    int answer;
    cout<<"salir(0) Adelante(1) Atras(2) Imprimir(3)"<<endl;
    cout<<"inicio(4) y  fin(5) de la lista"<<endl;
    cin>>answer;
    while(answer){
        it->testIterador(answer);
        if(!it->isDone()){
            cout<<"NULL pointer"<<endl;
            break;
        }
        cout<<"salir(0) Adelante(1) Atras(2) Imprimir(3)"<<endl;
        cout<<"inicio(4) y  fin(5) de la lista"<<endl;
        cin>>answer;
    }
    return 0;
}
