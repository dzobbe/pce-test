#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept> 
#include <stack>  
using namespace std;

//funzione pila
template<typename T>
void createStack(stack <T> mystack);
//classe autoveicolo
template <class T> 
class Autoveicolo{
    private:
    T Azienda;
    T Modello;
    public:
    Autoveicolo();
    Autoveicolo(T azienda,T modello);
};
//costruttore
template <class T> Autoveicolo<T>::Autoveicolo(){};
template <class T>
Autoveicolo<T>::Autoveicolo(T azienda,T modello){
    Azienda=azienda;
    Modello=modello;
};
//classe derivate
template <class T> 
class Autobus : public Autoveicolo<T>{
    public:
    T capienza;
};
template <class T> 
class Autocarro: public  Autoveicolo<T>{
    public:
    T Portata;
    Autocarro(T portata); 
    T getportata();
};
//costruttore autocarro
template <class T> 
Autocarro<T>::Autocarro(T portata){Portata=portata;};
//funzione portata
template <class T> 
T Autocarro<T>::getportata(){return Portata;};

int main (){
    Autoveicolo<string> A("opel","corsa");
    Autocarro<string> A2("BO");
    Autocarro<string> A3("o1");
    //operazione pila
    stack <string> st;
    //inserisco i valori della portata
    st.push(A2.getportata());
    st.push(A3.getportata());
    //stampa
    cout << "Pila st : ";
    createStack(st);
    cout << "\n st.size() : " << st.size();//dimensione
    cout << "\n st.top() : " << st.top();//elemento sulla top
    cout << "\n st.pop() : ";
    st.pop();//butta fuori il primo elemento 
    createStack(st);
}
template<typename T>
void createStack(stack <T> mystack)
{
    stack <T> ms = mystack;
    while (!ms.empty())
    {
        cout << '\t' << ms.top();
        ms.pop();
    }
    cout << '\n';
}

