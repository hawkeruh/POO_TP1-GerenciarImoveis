#include <iostream>
#include <iomanip> 
#include <string>
using namespace std;
#ifndef OBJETOS_HPP
#define OBJEOS_HPP

class Imovel {
    int id, numero, quartos, banheiros;
    float valor;
    string proprietario, rua, bairro, cidade;

public:
    Imovel(int=0, int=0, int=0, int=0, float=0.0, string="", string="", string="", string="");
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

class Casa : public Imovel {
    int andares; 
    bool sala_jantar; 

public:
    Casa(): Imovel();
    ~Casa();

    void setAndares(int);
    int getAndares() const;

    void setSalaJantar(bool);
    bool getSalaJantar(); 
};

class Apartamento : public Imovel {
    int andar;
    float taxa_condominio;
    bool elevador, sacada;

public:
    Apartamento(): Imovel();
    ~Apartamento();

    void setAndar(int);
    int getAndar() const;

    void setTaxa(float);
    float getTaxa() const; 

    void setElevador(bool);
    void setSacada(bool);

    bool getElevador();
    bool getSacada();
};

class Chacara : public Imovel {
    bool salao_festa, salao_jogos, campo_futebol, churrasqueira, piscina; 

public:
    Chacara(): Imovel();
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
};

#endif