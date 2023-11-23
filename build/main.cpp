#include "objetos.hpp"

int main (){

    //Somente UMA coleção polimorfica de objetos no main.
    Imovel i; 
    Casa casinha; 
    int x;

    cin >> x;
    casinha.setID(x);
    /*
    1 - Arquivo com os imoveis possui 16 linhas, cada linha um imovel
    2 - Inicia programa, ler arquivo para preencher coleção
    3 - Manipular e transformar coleção com operações:
        1 - Sobrecarregar operador de saída
        2 - Dado um proprietario: Função boleana, true se houver algum imovel do proprietario x
        3 - Dado um valor: Retorna uma coleção com os imoveis de valor igual ou abaixo
        4 - Dado numero de quartos: Retorna coleção com todos imoveis com numero de quartos igual ou acima
        5 - 
    */

    return 0;
}