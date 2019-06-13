#include"lista.h"
#include"lista.cpp" 

int main(){
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
    return 0;
}
