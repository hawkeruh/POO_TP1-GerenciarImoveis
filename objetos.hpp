#ifndef OBJETOS_HPP
#define OBJEOS_HPP

#include <string>
using namespace std; 

class Imovel {
    int id, numero, quartos, banheiros;
    float valor;
    string proprietario, rua, bairro, cidade;

public:
    Imovel();
    ~Imovel();

    void setID(int);
    void setNumero(int);
    void setQuartos(int);
    void setBanheiros(int);

    int getID() const;
    int getNumero() const;
    int getQuartos() const;
    int getBanheiros() const;

    void setValor(float);
    float getValor() const; 

    void setProprietario(string);
    void setRua(string);
    void setBairro(string);
    void setCidade(string);

    string getProprietario() const;
    string getRua() const;
    string getBairro() const;
    string getCidade() const;

};

#endif