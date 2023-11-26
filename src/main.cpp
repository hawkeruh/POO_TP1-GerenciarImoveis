#include "objetos.hpp"
#include "functions.hpp"

int main (){

    int intAux;
    int v[5];
    float floatAux;
    string tipo, linha, strAux;
    Imovel temp;

    //Somente UMA coleção polimorfica dentro do main
    set<shared_ptr<Imovel>> colecao;
    set<shared_ptr<Imovel>>::iterator iter;

    //Arquivo texto com o banco de dados VERIFICAR EM QUAL PASTA O ARQUIVO TEXTO DEVE SE ENCONTRAR
    ifstream arquivo("database_imoveis.txt");
    
    if (!arquivo.is_open()){
        cout << "Erro ao abrir banco de dados." << endl;
        return 0;
    }

    //Começa a leitura do arquivo até não encontrar mais linhas
    while (getline(arquivo,linha)) {

        stringstream ss(linha); //Extrair palavras de linhas
        getline(ss, tipo, ';'); //Extrai uma palavra separada por ; e coloca na string tipo

        //Armazenar propriedades não especificas em imovel temporario. Palavra por palavra.
        //Valor
        getline(ss, strAux, ';');
        floatAux = stof(strAux);
        temp.setValor(floatAux);
        //Proprietario
        getline(ss, strAux, ';');
        temp.setProprietario(strAux);
        //Rua
        getline(ss, strAux, ';');
        temp.setRua(strAux);
        //Bairro
        getline(ss, strAux, ';');
        temp.setBairro(strAux);
        //Cidade
        getline(ss, strAux, ';');
        temp.setCidade(strAux);
        //Numero
        getline(ss, strAux, ';');
        intAux = stoi(strAux);
        temp.setNumero(intAux);
        //Quartos
        getline(ss, strAux, ';');
        intAux = stoi(strAux);
        temp.setQuartos(intAux);
        //Banheiros
        getline(ss, strAux, ';');
        intAux = stoi(strAux);
        temp.setBanheiros(intAux);

        switch (qualTipoImovel(tipo)) // Seleciona qual tipo de imovel derivado inserir na coleção.
        {
        case 1: //CASA
            
            //Andares
            getline(ss, strAux, ';');
            v[0] = stoi(strAux);

            //Sala de jantar
            getline(ss, strAux, ';');
            v[1] = stoi(strAux);

            //Inserir
            colecao.insert(make_shared<Casa>(temp, v[0], v[1]));

            break;

        case 2: //APARTAMENTO
            
            //Andar
            getline(ss, strAux, ';');
            v[0] = stoi(strAux);

            //Taxa
            getline(ss, strAux, ';');
            floatAux = stof(strAux);

            //Elevador
            getline(ss, strAux, ';');
            v[1] = stoi(strAux);

            //Sacada
            getline(ss, strAux, ';');
            v[2] = stoi(strAux);

            //Inserir
            colecao.insert(make_shared<Apartamento>(temp, v[0], floatAux, v[1], v[2]));

            break;

        case 3: //CHACARA
            
            //Festas
            getline(ss, strAux, ';');
            v[0] = stoi(strAux);
            //Jogos
            getline(ss, strAux, ';');
            v[1] = stoi(strAux);
            //Campo de futebol
            getline(ss, strAux, ';');
            v[2] = stoi(strAux);
            //Churrasqueira
            getline(ss, strAux, ';');
            v[3] = stoi(strAux);
            //Piscina
            getline(ss, strAux, ';');
            v[4] = stoi(strAux);

            //Inserir
            colecao.insert(make_shared<Chacara>(temp, v[0], v[1], v[2], v[3], v[4]));

            break;
        case 99: //ERRO na leitura do tipo
            cout << "Erro na leitura do tipo de imóvel a ser inserido. " << endl;
            return 0;
        }
    }

    arquivo.close();

    // Manipular e transformar a coleção com operações:

    cout << "Selecione a operação que deseja realizar. Para sair, digite 1." << endl; 
    //INSERIR TABELA COM COMANDOS PARA ACESSAR FUNCOES
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