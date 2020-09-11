//Laura Galera Alfaro
//u1959173
//practica final

#include "Candidats.h"

Candidats::Candidats(int maxAltures) {
    
    altEdifici = 1;
    maxAltEdifici = maxAltures;
}

void Candidats::seguent(){
    altEdifici++;
}

bool Candidats::esFi() const{
   return altEdifici > maxAltEdifici;
}

int Candidats::actual() const{
    return altEdifici;
}
