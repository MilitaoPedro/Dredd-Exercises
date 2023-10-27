#include <iostream>
using namespace std;

class noh{

    friend class pilha;

    private:
        int mValor;
        noh * mProximo;

    public: 
        noh(int valor){
            mProximo = NULL;
            mValor = valor;
        }

};

class pilha{

    private:
        noh * mTopo;
        int mTamanho;

    public:
        pilha();
        ~pilha();
        void empilha(int valor); // Insere o elemento valor no Topo (Head) da pilha
        int desempilha(); // Remove o elemento no Topo (Head) da pilha
        void limpaPilha(); // Remove todos os elementos da pilha
        void inverter(); // Inverte a pilha principal (Topo -> Base)

};

pilha::pilha(){
    mTopo = NULL;
    mTamanho = 0;

}

pilha::~pilha(){
    limpaPilha();
}

void pilha::limpaPilha(){
    while(mTamanho > 0){
        desempilha();
    }
}

void pilha::empilha(int valor){
    noh * novo = new noh(valor);
    novo->mProximo = mTopo;
    mTopo = novo;
    mTamanho++;
}

int pilha::desempilha(){
    int valor = mTopo->mValor;

    // Noh temporário utilizado para desalocar memória
    noh * temp = mTopo;

    mTopo = mTopo->mProximo;
    delete temp;

    // Ajuste da variavek tamanho e retorno do elemento removido
    mTamanho--;
    return valor;
}

void pilha::inverter(){

    // Pilhas auxiliares utilizadas na inversão
    pilha auxPilha;
    pilha auxPilha1;

    // Pilha Principal -> AuxPilha (Topo principal -> Base principal)
    while (this->mTamanho > 0){
        auxPilha.empilha(this->desempilha());
    }

    // AuxPilha -> AuxPilha1 (Base principal -> Topo principal)
    while (auxPilha.mTamanho > 0){
        auxPilha1.empilha(auxPilha.desempilha());
    }

    // AuxPilha1 -> PilhaPrincipal (Topo principal -> Base principal) - Pilha invertida
    while (auxPilha1.mTamanho > 0){
        this->empilha(auxPilha1.desempilha());
    }

    // Remove todos os elementos da pilha principal, imprimindo-os
    while(this->mTamanho > 0){
        cout << mTopo->mValor << " ";
        desempilha();
    }

}

 int main(){
    pilha p1;

    // Varíaveis que armaazenam o número de elementos e o elementos, respectivamente.
    int tam, entradas;
    cin >> tam;

    // Looping para inserção dos elementos pelo usuário
    for (int i = 0; i < tam; i++){
        cin >> entradas;
        p1.empilha(entradas);
    }

    p1.inverter();
    
    return 0;
 }