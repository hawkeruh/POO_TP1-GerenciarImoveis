#include <iostream>
#include <string>
#include <cctype>
//#include <container>
#include <set>
#include <memory> //ponteiros inteligentes
#include <fstream> //escrita e leitura de arquivos
#include <sstream> //stringstream
#include "objetos.hpp"
using namespace std;
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

int qualTipoImovel(string);
multiset<shared_ptr<Imovel>> criarBancodeDados();

//FUNCAO 2 
bool existeProprietario(multiset<shared_ptr<Imovel>>&);
//FUNCAO 3
multiset<shared_ptr<Imovel>> pesquisaValor (multiset<shared_ptr<Imovel>>&, float);
//FUNCAO 4
multiset<shared_ptr<Imovel>> pesquisaQuarto (multiset<shared_ptr<Imovel>>&, int);
//FUNCAO 5
multiset<shared_ptr<Imovel>> pesquisaTipo (multiset<shared_ptr<Imovel>>&, string);
//FUNCAO 6
multiset<shared_ptr<Imovel>> pesquisaCidade (multiset<shared_ptr<Imovel>>&, string);
//FUNCAO 7 
//template <typename T>
//typename set<shared_ptr<Imovel>>::iterator pesquisaProprietario(set<shared_ptr<Imovel>>&, string);

//FUNCAO 8 - OUTPUT - (int = 0, terminal) (int = 1, arquivo)
void imprimirTodos (const multiset<shared_ptr<Imovel>>&, int); 

#endif