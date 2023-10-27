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
        void limpaPilha(); // Limpa a pilha, removendo todos os elementos
        int menorValor(); // Retornar o menor valor armazenado na pilha
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
    if (!(this->mTamanho > 0)) {
        throw std::runtime_error("VAZIA");
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

void pilha::limpaPilha(){
    while(this->mTamanho > 0){
        std::cout << desempilha() << " ";
    }
}

int pilha::menorValor(){

    // Testa se a pilha está vazia
    if (!(this->mTamanho > 0)) {
        throw std::runtime_error("VAZIA");
    }

    // Pilha auxiliar utilizada para a busca do menor
    pilha auxPilha;

    // Menor elemento da pilha
    int menor = mTopo->mValor;

    // Busca o menor elemento da pilha, desempilhando a cada comparação
    // para evitar a quebra de estrutura
    while(!(mTopo->mProximo == NULL)){
        if(mTopo->mValor < menor){
            menor = mTopo->mValor;
        }
        auxPilha.empilha(this->desempilha());
    }

    // Empilha novamente os nohs na pilha principal
    while(auxPilha.mTamanho > 0){
        this->empilha(auxPilha.desempilha());
    }

    return menor;
}

int main(){
    pilha objPilha;

    char comando = 's';
    int num;

    do{
        std::cin >> comando;
        switch (comando){
            case 'e':
                std::cin >> num;
                objPilha.empilha(num);
                break;
            case 'd':
                try {
                    std::cout << objPilha.desempilha() << "\n";
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << "\n";
                }
                break;
            case 'm':
                try {
                    std::cout << objPilha.menorValor() << "\n";
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << "\n";
                }
                break;
            case 's':
                objPilha.limpaPilha();
                break;
            default:
                std::cout << "\nDigite um comando válido";
                break;
        }
    } while (!(comando == 's'));

    return 0;
}