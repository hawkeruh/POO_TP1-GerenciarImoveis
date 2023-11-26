    #include "objetos.hpp"
#include "functions.hpp"

int main (){

    int intAux;
    float floatAux;
    string tipo;

    //Somente UMA coleção polimorfica dentro do main
    set<shared_ptr<Imovel>> colecao;
    set<shared_ptr<Imovel>>::iterator iter;

    //Leitura de um arquivo texto e inserção em uma coleção
    colecao = criarBancodeDados();

    // Manipular e transformar a coleção com operações:
    cout << "Selecione a operação que deseja realizar. Para sair, digite 1." << endl; 
    cin >> intAux;

    switch (intAux)
    {
    case 1:

        cout << "Fechando o gerenciador." << endl;
        break;

    case 2: //FUNCAO 2 - EXISTE PROPRIETARIO?
        
        if (existeProprietario(colecao)){
            cout << "Existe esse proprietário." << endl;
        } else {
            cout << "Não existe esse proprietário." << endl;
        }
        
        break;

    case 3: //FUNCAO 3 - DADO VALOR - RETORNE IMOVEIS ABAIXO OU IGUAL

        cout << "Insira o valor. Abaixo será exibido imóveis de valores abaixo ou igual." << endl;
        cin >> floatAux; 

        colecao = pesquisaValor(colecao, floatAux);
        imprimirTodos(colecao, 0);

        break;

    case 4: //FUNCAO 4 - NUMERO DE QUARTOS - IMOVEIS IGUAL OU ACIMA
        
        cout << "Insira o número de quartos. Abaixo será exibido imóveis com o mesmo ou maior número de quartos." << endl;
        cin >> intAux;

        colecao = pesquisaQuarto(colecao, intAux);
        imprimirTodos(colecao, 0);

        break;

    case 5: //FUNCAO 5 - TIPO DE IMOVEL - ORDENADOS POR VALOR
        cout << "Insira o tipo de imóvel que deseja visualizar. (Ordenado por valor)" << endl; 
        cin >> tipo; 

        colecao = pesquisaTipo(colecao, tipo);
        imprimirTodos(colecao, 0);

        break;

    case 6: //FUNCAO 6 - CIDADE - IMOVEIS ORDEM DECRESCENTE POR VALOR

        cout << "Insira o nome da cidade que deseja ver os imóveis diponivéis. (Ordenado decrescentemente por valor)" << endl;
        cin >> tipo; 

        colecao = pesquisaCidade(colecao, tipo);
        imprimirTodos(colecao, 2);

        break;

    case 7: //FUNCAO 7 - PROPRIETARIO - ITERADOR 
/*
        //retorna iterador. se encontrado imprimir com especificos.
        cout << "Insira o nome do proprietário que procura." << endl;
        cin >> tipo;

        iter = pesquisaProprietario<T>(colecao, tipo);

        if (iter != colecao.end()){

            cout << "Proprietário encontrado. " << endl;
            cout << *iter;

            //Imprimir caracteristica especifica
            if (shared_ptr<Casa> casa = dynamic_pointer_cast<Casa>(iter)){
                cout << *casa;
            } else if (shared_ptr<Apartamento> apartamento = dynamic_pointer_cast<Apartamento>(iter)){
                cout << *apartamento;
            } else if (shared_ptr<Chacara> chacara = dynamic_pointer_cast<Chacara>(iter)) {
                cout << *chacara;
            }

        } else {
            cout << "Proprietário não encontrado. " << endl;
        }
*/
        cout << "funcao7" << endl;
        break;

    case 8: //FUNCAO 8 - OUTPUT NO TERMINAL/ARQUIVO - MOSTRAR TODOS OS DADOS

        cout << "Deseja a impressão no terminal ou em um arquivo txt? 1. Terminal, 2. Arquivo texto " << endl; 
        cin >> intAux;

        switch (intAux)
        {
        case 1: //TERMINAL
            imprimirTodos(colecao, 0);
            break;
        
        case 2: //ARQUIVO TEXTO
            imprimirTodos(colecao, 1);
            break;
        }
        
        break;
    }

    return 0;
}