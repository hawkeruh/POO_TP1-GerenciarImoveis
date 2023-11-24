#include "objetos.hpp"
#include "functions.hpp"
//#include <container>
#include <unordered_set>
#include <memory> //ponteiros inteligentes
#include <fstream> //escrita e leitura de arquivos

int main (){

    int intAux;
    int v[5];
    float floatAux;
    string tipo, linha, strAux;
    Imovel temp;

    //Somente UMA coleção polimorfica de objetos no main.
    unordered_set<shared_ptr<Imovel>> colecao;

    //Arquivo texto com o banco de dados VERIFICAR EM QUAL PASTA O ARQUIVO TEXTO DEVE SE ENCONTRAR
    ifstream arquivo("database_imoveis.txt");
    if (!arquivo.is_open()){
        cout << "Erro ao abrir banco de dados." << endl;
        return 0;
    }


    //Começa a leitura do arquivo até não encontrar mais linhas
    if (getline(arquivo,linha)) {

        stringstream ss(linha); //Extrair palavras de linhas
        getline(ss, tipo, ';'); //Extrai uma palavra separada por ; e coloca na string tipo

        //Armazenar propriedades não especificas em imovel temporario. Palavra por palavra. (fazer em uma função?)
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