#include "functions.hpp"

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