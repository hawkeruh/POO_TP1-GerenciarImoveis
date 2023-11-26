#include "objetos.hpp"

//IMOVEL
Imovel::Imovel(float valor,
                int id, 
                int numero, 
                int quartos, 
                int banheiros, 
                string proprietario, 
                string rua, 
                string bairro, 
                string cidade)
    : valor(valor),
    id(id), 
    numero(numero), 
    quartos(quartos), 
    banheiros(banheiros), 
    proprietario(proprietario), 
    rua(rua), 
    bairro(bairro), 
    cidade(cidade) {}

Imovel::~Imovel() {}

//IMOVEL - setters
void Imovel::setValor(float valor) {
    this->valor = valor;
}

void Imovel::setID(int id) {
    this->id = id;
}

void Imovel::setNumero(int numero) {
    this->numero = numero;
}

void Imovel::setQuartos(int quartos) {
    this->quartos = quartos;
}

void Imovel::setBanheiros(int banheiros) {
    this->banheiros = banheiros;
}

void Imovel::setProprietario(string proprietario) {
    this->proprietario = proprietario;
}

void Imovel::setRua(string rua) {
    this->rua = rua;
}

void Imovel::setBairro(string bairro) {
    this->bairro = bairro;
}

void Imovel::setCidade(string cidade) {
    this->cidade = cidade;
}

//IMOVEL - getters
float Imovel::getValor() const {
    return valor;
}

int Imovel::getID() const {
    return id;
}

int Imovel::getNumero() const {
    return numero;
}

int Imovel::getQuartos() const {
    return quartos;
}

int Imovel::getBanheiros() const {
    return banheiros;
}

string Imovel::getProprietario() const {
    return proprietario;
}

string Imovel::getRua() const {
    return rua;
}

string Imovel::getBairro() const {
    return bairro;
}

string Imovel::getCidade() const {
    return cidade;
}


//CASA
Casa::Casa(float valor,
            int id, 
            int numero, 
            int quartos, 
            int banheiros, 
            string proprietario, 
            string rua, 
            string bairro, 
            string cidade, 
            int andares, 
            bool sala_jantar)
    : Imovel(valor, id, numero, quartos, banheiros, proprietario, rua, bairro, cidade), 
    andares(andares), 
    sala_jantar(sala_jantar){}

Casa::~Casa(){}

//CASA - setters
void Casa::setAndares(int andares) {
    this->andares = andares;
}

void Casa::setSalaJantar(bool sala_jantar) {
    this->sala_jantar = sala_jantar;
}

//CASA - getters
int Casa::getAndares() const {
    return andares;
}

bool Casa::getSalaJantar() {
    return sala_jantar;
}

//APARTAMENTO
Apartamento::Apartamento(float valor,
                        int id, 
                        int numero, 
                        int quartos, 
                        int banheiros, 
                        string proprietario, 
                        string rua, 
                        string bairro, 
                        string cidade,
                        int andar, 
                        float taxa_condominio, 
                        bool elevador, 
                        bool sacada)
    : Imovel(valor, id, numero, quartos, banheiros, proprietario, rua, bairro, cidade), 
    andar(andar), 
    taxa_condominio(taxa_condominio), 
    elevador(elevador), 
    sacada(sacada) {}

Apartamento::~Apartamento() {}

//APARTAMENTO - setters
void Apartamento::setTaxa(float taxa_condominio) {
    this->taxa_condominio = taxa_condominio;
}

void Apartamento::setElevador(bool elevador) {
    this->elevador = elevador;
}

void Apartamento::setSacada(bool sacada) {
    this->sacada = sacada;
}

void Apartamento::setAndar(int andar) {
    this->andar = andar;
}
//APARTAMENTO - getters
float Apartamento::getTaxa() const {
    return taxa_condominio;
}

bool Apartamento::getElevador() {
    return elevador;
}

bool Apartamento::getSacada() {
    return sacada;
}

int Apartamento::getAndar() const {
    return andar;
}

//CHACARA
Chacara::Chacara(float valor,
                    int id, 
                    int numero, 
                    int quartos, 
                    int banheiros, 
                    string proprietario, 
                    string rua, 
                    string bairro, 
                    string cidade,
                    bool salao_festa, 
                    bool salao_jogos, 
                    bool campo_futebol, 
                    bool churrasqueira, 
                    bool piscina)
    : Imovel(valor, id, numero, quartos, banheiros, proprietario, rua, bairro, cidade),
      salao_festa(salao_festa), 
      salao_jogos(salao_jogos), 
      campo_futebol(campo_futebol), 
      churrasqueira(churrasqueira), 
      piscina(piscina) {}

Chacara::~Chacara() {}

//CHACARA - setters
void Chacara::setSalaoFesta(bool salao_festa) {
    this->salao_festa = salao_festa;
}

void Chacara::setSalaoJogos(bool salao_jogos) {
    this->salao_jogos = salao_jogos;
}

void Chacara::setCampoFutebol(bool campo_futebol) {
    this->campo_futebol = campo_futebol;
}

void Chacara::setChurrasqueira(bool churrasqueira) {
    this->churrasqueira = churrasqueira;
}

void Chacara::setPiscina(bool piscina) {
    this->piscina = piscina;
}

//CHACARA - getters
bool Chacara::getSalaoFesta() {
    return salao_festa;
}

bool Chacara::getSalaoJogos() {
    return salao_jogos;
}

bool Chacara::getCampoFutebol() {
    return campo_futebol;
}

bool Chacara::getChurrasqueira() {
    return churrasqueira;
}

bool Chacara::getPiscina() {
    return piscina;
}


//CLASSES AMIGA E/OU SOBRECARGAS

string SimNao (bool x){
    if (x) {
        return "Sim";
    } else {
        return "Não";
    }
}

ostream& operator<<(ostream& saida, Imovel& imovel){

    saida << "-----"
    << "\nProprietario: " << imovel.getProprietario()
    << "\nPreço: " << fixed << setprecision(2) << imovel.getValor()
    << "\nNúmero de Quartos: " << imovel.getQuartos()
    << "\nRua: " << imovel.getRua()
    << "\nBairro: " << imovel.getBairro()
    << "\nCidade: " << imovel.getCidade();

    return saida;
}

ostream& operator<<(ostream& saida, Casa& imovel){

    saida << "\nCaracterística Específica: "
    << "\nAndares: " << imovel.getAndares() << endl;

    return saida;
}

ostream& operator<<(ostream& saida, Apartamento& imovel){

    saida << "\nCaracterística Específica: "
    << "\nElevador: " << SimNao(imovel.getElevador()) << endl;

    return saida;
}

ostream& operator<<(ostream& saida, Chacara& imovel){

    saida << "\nCaracterística Específica: "
    << "\nPiscina: " << SimNao(imovel.getPiscina()) << endl;

    return saida;
}

bool Imovel::operator<(const Imovel& comparar) const {
    return this->getValor() < comparar.getValor();
}

bool Imovel::operator>(const Imovel& comparar) const {
    return this->getValor() > comparar.getValor();   
}

bool Imovel::operator==(const Imovel& comparar) const {
    return this->getID() == comparar.getID();
}