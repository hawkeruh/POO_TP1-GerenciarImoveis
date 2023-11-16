#include "objetos.hpp"

//construtor default fica no hpp (int=0)
Imovel::Imovel(int id, int numero, int quartos, int banheiros, float valor, string proprietario, string rua, string bairro, string cidade){}

Casa::Casa(int id, int numero, int quartos, int banheiros, float valor, string proprietario, string rua, string bairro, string cidade) :
    Imovel(id, numero, quartos, banheiros, valor, proprietario, rua, bairro, cidade), andares(andares), sala_jantar(sala_jantar) {}
Casa::~Casa(){}

