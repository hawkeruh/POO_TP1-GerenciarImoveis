#include <iostream>
#include <iomanip> 
#include <string>
using namespace std;
#ifndef OBJETOS_HPP
#define OBJETOS_HPP

class Imovel {

    float valor;
    int id, numero, quartos, banheiros;
    string proprietario, rua, bairro, cidade;

public:

    Imovel(float, int, int, int, int, string, string, string, string);
    virtual ~Imovel() = 0;

    void setValor(float);
    float getValor() const; 

    void setID(int);
    void setNumero(int);
    void setQuartos(int);
    void setBanheiros(int);

    int getID() const;
    int getNumero() const;
    int getQuartos() const;
    int getBanheiros() const;

    void setProprietario(string);
    void setRua(string);
    void setBairro(string);
    void setCidade(string);

    string getProprietario() const;
    string getRua() const;
    string getBairro() const;
    string getCidade() const;

    friend ostream& operator<<(ostream& saida, Imovel& imovel);
    bool operator<(const Imovel& comparar) const;

};

class Casa : public Imovel {
    int andares; 
    bool sala_jantar; 

public:

    Casa(float, int, int, int, int, string, string, string, string, int, bool);
    ~Casa();

    void setAndares(int);
    int getAndares() const;

    void setSalaJantar(bool);
    bool getSalaJantar(); 

    friend ostream& operator<<(ostream& saida, Casa& imovel);
 
};

class Apartamento : public Imovel {
    int andar;
    float taxa_condominio;
    bool elevador, sacada;

public:
    
    Apartamento(float, int, int, int, int, string, string, string, string, int, float, bool, bool);
    ~Apartamento();

    void setAndar(int);
    int getAndar() const;

    void setTaxa(float);
    float getTaxa() const; 

    void setElevador(bool);
    void setSacada(bool);

    bool getElevador();
    bool getSacada();

    friend ostream& operator<<(ostream& saida, Apartamento& imovel);

};

class Chacara : public Imovel {

    bool salao_festa, salao_jogos, campo_futebol, churrasqueira, piscina; 

public:
    
    Chacara(float, int, int, int, int, string, string, string, string, bool, bool, bool, bool, bool);
    ~Chacara();

    void setSalaoFesta(bool);
    void setSalaoJogos(bool);
    void setCampoFutebol(bool);
    void setChurrasqueira(bool);
    void setPiscina(bool);

    bool getSalaoFesta();
    bool getSalaoJogos();
    bool getCampoFutebol();
    bool getChurrasqueira();
    bool getPiscina();

    friend ostream& operator<<(ostream& saida, Chacara& imovel);

};

string SimNao(bool);
bool operator<(Imovel& comparar1, Imovel& comparar2);

#endif