# Pilha - Menor elemento da pilha
Implemente uma estrutura de dados do tipo pilha com as operações básicas de empilhar e desempilhar. Faça um método adicional que retorne o menor valor da pilha sem que haja quebra da estrutura e sem ordenar seus elementos. Faça um programa com suporte as seguintes operações:

e - empilhar um valor X passado como parâmetro.
d - desempilhar um valor, que deve ser impresso. Se a pilha estiver vazia, imprimir "VAZIA".
m - retornar o menor valor armazenado na pilha. Se a pilha estiver vazia, imprimir "VAZIA".
s - imprimir todos os valores armazenados na pilha e encerrar.
DICA: A solução utiliza duas pilhas: a pilha principal e uma pilha auxiliar para que haja o intercâmbio de elementos entre elas.
Entradas:

    Operações a serem realizadas sobre a estrutura
Saídas:

    Retorno correspondente a cada operação executada

Exemplo de Entrada:

    e 10
    e 3
    e 5
    m
    e 8 
    e 6
    m
    e 1
    e 7
    m
    d
    s

Exemplo de Saída:

    3
    3
    1
    7
    1 6 8 5 3 10

Exemplo de Entrada:

    e 5
    e 4
    e 7
    m
    d 
    e -6
    m  
    d
    d
    m
    e 13
    d
    d
    d
    m
    e 1
    s

Exemplo de Saída:

    4
    7
    -6 
    -6
    4
    5
    13
    5
    VAZIA
    VAZIA
    1