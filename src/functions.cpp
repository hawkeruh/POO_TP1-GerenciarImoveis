#include "functions.hpp"
#include "objetos.hpp"

int qualTipoImovel(string palavra){
    if (palavra == "casa"){
        return 1;
    } else if (palavra == "apartamento") {
        return 2;
    } else if (palavra == "chacara"){
        return 3;
    } else {
        return 99;
    }
}

set<shared_ptr<Imovel>> criarBancodeDados(){

    set<shared_ptr<Imovel>> colecao;
    string linha, palavra, tipo;

    //atributos comuns. da classe base
    float valor;
    string proprietario, rua, bairro, cidade;
    int numero, quartos, banheiros, id = 1;

    //atributos especificos
    int v[5];
    float taxa;

    ifstream arquivo("database_imoveis.txt");
    if (!arquivo.is_open()){
        cout << "Erro ao abrir banco de dados." << endl;
        return colecao;
    }

    while (getline(arquivo,linha)) {

        stringstream ss(linha); //Extrair palavras de linhas
        getline(ss, tipo, ';'); //Extrai uma palavra separada por ; e coloca na string 'palavra'

        //Extrair atributos comuns
        //Valor
        getline(ss, palavra, ';');
        valor = stof(palavra);

        //Proprietario
        getline(ss, proprietario, ';');
        
        //Rua
        getline(ss, rua, ';');

        //Bairro
        getline(ss, bairro, ';');

        //Cidade
        getline(ss, cidade, ';');

        //Numero
        getline(ss, palavra, ';');
        numero = stoi(palavra);

        //Quartos
        getline(ss, palavra, ';');
        quartos = stoi(palavra);

        //Banheiros
        getline(ss, palavra, ';');
        banheiros = stoi(palavra);

        //Extrair caracteristicas especiais e inserir na colecao
        switch (qualTipoImovel(tipo)) 
        {
        case 1: //CASA

            //Andares
            getline(ss, palavra, ';');
            v[0] = stoi(palavra);

            //Sala de Jantar
            getline(ss, palavra, ';');
            v[1] = stoi(palavra);

            //Inserir
            colecao.insert(make_shared<Casa>(id, numero, quartos, banheiros, valor, proprietario, rua, bairro, cidade,  v[0], v[1]));

            break;

        case 2: //APARTAMENTO
            //Andar
            getline(ss, palavra, ';');
            v[0] = stoi(palavra);

            //Taxa
            getline(ss, palavra, ';');
            taxa = stof(palavra);

            //Elevador
            getline(ss, palavra, ';');
            v[1] = stoi(palavra);

            //Sacada
            getline(ss, palavra, ';');
            v[2] = stoi(palavra);

            //Inserir
            colecao.insert(make_shared<Apartamento>(id, numero, quartos, banheiros, valor, proprietario, rua, bairro, cidade, v[0], taxa, v[1], v[2]));

            break;

        case 3: //CHACARA

            //Festas
            getline(ss, palavra, ';');
            v[0] = stoi(palavra);
            //Jogos
            getline(ss, palavra, ';');
            v[1] = stoi(palavra);
            //Campo de Futebol
            getline(ss, palavra, ';');
            v[2] = stoi(palavra);
            //Churrasqueira
            getline(ss, palavra, ';');
            v[3] = stoi(palavra);
            //Piscina
            getline(ss, palavra, ';');
            v[4] = stoi(palavra);

            //Inserir
            colecao.insert(make_shared<Chacara>(id, numero, quartos, banheiros, valor, proprietario, rua, bairro, cidade, v[0], v[1], v[2], v[3], v[4]));

            break;

        case 99: //ERRO
            cout << "Erro na leitura do tipo de imóvel a ser inserido. " << endl;
            break;
        }

        id++; //Preencher ID
    }

    arquivo.close();

    set<shared_ptr<Imovel>>::iterator iter;
    for (iter = colecao.begin(); iter != colecao.end(); ++iter){
        cout << (*iter)->getID() << endl;
    }


    return colecao;
}

//FUNCAO 2
bool existeProprietario(set<shared_ptr<Imovel>>& colecao){

    string proprietario;
    set<shared_ptr<Imovel>>::iterator iter;

    cout << "Insira o nome do proprietário: " << endl;
    cin >> proprietario;

    for (iter = colecao.begin(); iter != colecao.end(); ++iter){
            if ((*iter)->getProprietario() == proprietario){
                return true; //TRUE - exite um proprietario com esse nome
            }
        }

    return false;
}

//FUNCAO 3
set<shared_ptr<Imovel>> pesquisaValor (set<shared_ptr<Imovel>>& colecao, float valorPesquisa){
    
    set<shared_ptr<Imovel>> colecaoValor; 
    set<shared_ptr<Imovel>>::iterator iter;

    for (iter = colecao.begin(); iter != colecao.end(); ++iter){
        if ((*iter)->getValor() <= valorPesquisa){ //Inserir valores menores ou iguais ao valor dado
            colecaoValor.insert(*iter);
        }
    }

    return colecaoValor;
}

//FUNCAO 4
set<shared_ptr<Imovel>> pesquisaQuarto (set<shared_ptr<Imovel>>& colecao, int quartos){

    set<shared_ptr<Imovel>> colecaoQuartos; 
    set<shared_ptr<Imovel>>::iterator iter;

    for (iter = colecao.begin(); iter != colecao.end(); ++iter){
        if((*iter)->getQuartos() >= quartos){
            colecaoQuartos.insert(*iter);
        }
    }

    return colecaoQuartos;
}

//FUNCAO 5
set<shared_ptr<Imovel>> pesquisaTipo (set<shared_ptr<Imovel>>& colecao, string palavra){

    int tipo = qualTipoImovel(palavra);
    set<shared_ptr<Imovel>> colecaoTipo;
    set<shared_ptr<Imovel>>::iterator iter;

    switch (tipo)
    {
    case 1: //CASA
        for (const shared_ptr<Imovel>& ptrImovel : colecao){
            if (shared_ptr<Casa> casa = dynamic_pointer_cast<Casa>(ptrImovel)){
                colecaoTipo.insert(ptrImovel);
            }
        }
        break;
    case 2: //APARTAMENTO
        for (const shared_ptr<Imovel>& ptrImovel : colecao){
            if (shared_ptr<Apartamento> apartamento = dynamic_pointer_cast<Apartamento>(ptrImovel)){
                colecaoTipo.insert(ptrImovel);
            }
        }
        break;
    case 3: //CHACARA
        for (const shared_ptr<Imovel>& ptrImovel : colecao){
            if (shared_ptr<Chacara> chacara = dynamic_pointer_cast<Chacara>(ptrImovel)){
                colecaoTipo.insert(ptrImovel);
            }
        }
        break;
    }

    return colecaoTipo;
}

//FUNCAO 6
set<shared_ptr<Imovel>> pesquisaCidade (set<shared_ptr<Imovel>>& colecao, string cidade){

    set<shared_ptr<Imovel>> colecaoCidade; 
    set<shared_ptr<Imovel>>::iterator iter;

    //colocar a string cidade em lower case

    for (iter = colecao.begin(); iter != colecao.end(); ++iter){
        if((*iter)->getCidade() == cidade){
            colecaoCidade.insert(*iter);
        }
    }

    return colecaoCidade;
}

//FUNCAO 7
/*
template <typename T>
typename set<shared_ptr<Imovel>>::iterator pesquisaProprietario(set<shared_ptr<Imovel>>& colecao, string proprietario){

    typename set<shared_ptr<Imovel>>::iterator iter;

    for (iter = colecao.begin(); iter != colecao.end(); ++iter){
        if ((*iter)->getProprietario() == proprietario){
            return iter;
        }
    }

    return colecao.end();
}
*/
//FUNCAO 8
void imprimirTodos (const set<shared_ptr<Imovel>>& colecao, int tipo){

    set<shared_ptr<Imovel>>::reverse_iterator iter;
    string saida = "saida.txt";
    ofstream arquivo(saida.c_str()); 

    switch (tipo)
    {
    case 0: //imprimir a colecao no terminal
        
        for (const shared_ptr<Imovel>& ptrImovel : colecao){

            cout << *ptrImovel; //imprime dados base Imovel

            /* ponteiro errado
            if (typeid(*iter) == typeid(class Casa)){ //imprime dados especificos Casa
                shared_ptr<Casa*> casa = dynamic_cast<Casa*>(iter);
                cout << casa;
            }
            */

            //Usando dynamic pointer cast
            if (shared_ptr<Casa> casa = dynamic_pointer_cast<Casa>(ptrImovel)){
                cout << *casa;
            } else if (shared_ptr<Apartamento> apartamento = dynamic_pointer_cast<Apartamento>(ptrImovel)){
                cout << *apartamento;
            } else if (shared_ptr<Chacara> chacara = dynamic_pointer_cast<Chacara>(ptrImovel)) {
                cout << *chacara;
            }

        }

        break;

    case 1: //imprimir a colecao em um arquivo txt

        if (!arquivo.is_open()){

            cout << "Erro ao criar arquivo de saída. " << endl; 
            return;

        } else {

            for (const shared_ptr<Imovel>& ptrImovel : colecao){

                arquivo << *ptrImovel;

                if (shared_ptr<Casa> casa = dynamic_pointer_cast<Casa>(ptrImovel)){
                    arquivo << *casa;
                } else if (shared_ptr<Apartamento> apartamento = dynamic_pointer_cast<Apartamento>(ptrImovel)){
                    arquivo << *apartamento;
                } else if (shared_ptr<Chacara> chacara = dynamic_pointer_cast<Chacara>(ptrImovel)) {
                    arquivo << *chacara;
                }
            }

            arquivo.close();
        }


        break;

    case 2: //imprimir a colecao em reverso

        for (iter = colecao.rbegin(); iter != colecao.rend(); iter++){

            if (shared_ptr<Casa> casa = dynamic_pointer_cast<Casa>(*iter)){
                cout << *casa;
            } else if (shared_ptr<Apartamento> apartamento = dynamic_pointer_cast<Apartamento>(*iter)){
                cout << *apartamento;
            } else if (shared_ptr<Chacara> chacara = dynamic_pointer_cast<Chacara>(*iter)) {
                cout << *chacara;
            }
        }

        break;
    }

}