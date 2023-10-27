#include <iostream>

class noh{
    friend class pilha; 
    
    private:
        int mPosicao;
        noh * mProximo; // Aponta para o próximo noh (Topo -> Próximo)
    public:

        // Construtor do noh
        noh(int valor){
            mProximo = NULL;
            mPosicao = valor;
        }
};

class pilha{
    private:
        noh * mTopo;
        int mTamanho; // Número de nohs na pilha
    public:
        pilha();
        ~pilha();
        void empilha(int valor); // Insere o elemento valor no Topo (Head) da pilha
        int desempilha(); // Remove o elemento no Topo (Head) da pilha
        int tamanho(); // Retorna o número de nohs presentes na pilha
        void limpaPilha(); // Remove todos os elementos da pilha
        void imprimeTopo(); // Imprime o elemento no Topo (Head) da pilha
};

pilha::pilha(){
    mTopo = NULL;
    mTamanho = 0;
}

pilha::~pilha(){
    limpaPilha();
}

void pilha::limpaPilha(){
    while(mTamanho>0){
        desempilha();
    }
}

int pilha::tamanho(){
    return this->mTamanho; 
}

void pilha::imprimeTopo(){
    std::cout << this->mTopo->mPosicao;
}

void pilha::empilha(int valor){
    noh * novo = new noh(valor);
    novo->mProximo = mTopo;
    mTopo = novo;
    mTamanho++;
}

int pilha::desempilha(){
    if (this->mTamanho <= 0) 
        return -1;

    int valor = mTopo->mPosicao;

    // Noh temporário que será utilizado para desalocar o espaço do Topo na memória
    noh * temp = mTopo;

    mTopo = mTopo->mProximo;
    delete temp;

    mTamanho--;
    return valor;
}

int main(){
    std::string linha;
    pilha parentesisAberto;

    getline(std::cin, linha);

    const int tam = linha.length();

    for (int i = 0; i < tam; i++){
        if(linha[i] == '('){
            // Empilha apenas os parentesis abertos
            parentesisAberto.empilha(i);
        } else if (linha[i] == ')'){
            // Checa se existe um parentêsis aberto para o que foi fechado, se sim, o remove.
            // Senão, imprime a posição em que o parentêsis fechado foi encontrado
            if(parentesisAberto.desempilha() < 0){
                std::cout << i;
                return 0;
            }
        }
    }
    // Checa se ainda existe algum parentêsis não fechado no texto
    if(parentesisAberto.tamanho() > 0){
        parentesisAberto.imprimeTopo();
    } else {
        std::cout << "correto";
    }
    return 0;
}

