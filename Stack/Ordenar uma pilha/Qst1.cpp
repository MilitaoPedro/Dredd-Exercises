#include <iostream>

class noh{
    friend class pilha;
    
    private:
        int mValor;
        noh* mProximo;
    public:
        noh(int valor){
            mValor = valor;
            mProximo = NULL;
        }
};

class pilha{
    private:
        int mTamanho; // Variável que armazena a quantidade de nohs da pilha
        noh* mTopo; // Ponteiro para o Topo (Head) da pilha
    public:
        pilha(); // Construtor da classe
        ~pilha(); // Destrutor da classe
        void empilha(int valor); // Empilha os novos nohs no topo da pilha
        int desempilha(); // Desempilha o elemento no topo da pilha
        void ordena(); // Ordena os nohs da pilha
        void limpaPilha(); // Limpa a pilha, removendo todos os elementos
        int tamanho(); // Retorna a variável privada tamanho
};

pilha::pilha(){
    mTopo = NULL;
    mTamanho = 0;
}

pilha::~pilha(){
    limpaPilha();
}

void pilha::empilha(int valor){

    // Cria o noh a ser inserido no topo da pilha
    noh * novo = new noh(valor);

    // Faz com que o próximo do novo seja o antigo topo
    novo->mProximo = mTopo;
    
    // Faz com que o ponteiro Topo seha o novo
    mTopo = novo;

    mTamanho++;
}

int pilha::desempilha(){

    // Testa se a pilha está vazia
    if (this->mTamanho < 0) {
        throw std::runtime_error("Erro: pilha vazia!");
        return 0;
    }

    int valor = mTopo->mValor;

    // Cria um nó temporário que desalocará a memória do ponteiro Topo
    noh * temp = mTopo;
    mTopo = mTopo->mProximo;

    // Desaloca a memória do ponteiro temp
    delete temp;

    mTamanho--;

    // Retorna o valor contido no noh deletado
    return valor;
}

// Método que ordena a pilha utilizando o conceito de torre de haloi
void pilha::ordena(){

    // Pilha auxiliares utilizadas na ordenação
    pilha auxPilhaOrdenada;
    pilha auxPilha;

    int tamMax = this->mTamanho;
    auxPilhaOrdenada.empilha(this->desempilha());

    // Looping que ordena os elementos da pilha principal (this) ma auxPilhaOrdenada 
    while(auxPilhaOrdenada.mTamanho < tamMax){
        if(this->mTopo->mValor < auxPilhaOrdenada.mTopo->mValor){
            auxPilhaOrdenada.empilha(this->desempilha());
        } else {
            auxPilha.empilha(this->desempilha());
            while(auxPilha.mTamanho > 0){
                while(auxPilhaOrdenada.mTamanho > 0 && auxPilha.mTopo->mValor > auxPilhaOrdenada.mTopo->mValor){
                    this->empilha(auxPilhaOrdenada.desempilha());
                }
                auxPilhaOrdenada.empilha(auxPilha.desempilha());
            }
        }
    }
    // Looping que empilha os elementos da auxPilhaOrdenada em auxPilha na ordem contrária - Base = Topo
    while(auxPilhaOrdenada.mTamanho > 0){
		auxPilha.empilha(auxPilhaOrdenada.desempilha());
	}
    // Looping que empilha os elementos da auxPilha na Pilha principal na ordem correta
    while(auxPilha.mTamanho > 0){
		this->empilha(auxPilha.desempilha());
	}
}

void pilha::limpaPilha(){
    while(this->mTamanho > 0){
        desempilha();
    }
}

int pilha::tamanho(){
    return this->mTamanho;
}

int main(){
    pilha objPilha;

    int tam; // Variável que armazena o número de elementos da pilha
    int num;

    // Requisita a quantidade de elementos a serem armazenados
    std::cin >> tam;

    // Empilha os elementos digitados pelo usuário
    for (int i = 0; i < tam; i++){
        std::cin >> num;
        objPilha.empilha(num);
    }

    // Ordena a pilha
    objPilha.ordena();

    tam = objPilha.tamanho();

    // Desempilha a pilha, imprimindo todos os elementos desempilhados
    while (tam > 0) {
        std::cout << objPilha.desempilha() << " ";
        tam--;
    }
    return 0;
}