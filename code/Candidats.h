//Laura Galera Alfaro
//u1959173
//practica final

/// @file Candidats.h
/// @brief Classe Candidats


#ifndef CANDIDATS_H
#define CANDIDATS_H

#include <iostream>

using namespace std;

/** @class Candidats
    @brief Classe que genera els valors possibles per a la solució.
    @author Laura Galera Alfaro
 */

class Candidats {
public:

    ///@brief Inicialitza el candidat.
    Candidats(int maxAltures);
    
    ///@brief Passa al següent candidat.
    void seguent();

    ///@brief Retorna cert si no queden més candidats a tractar, fals altrament.
    bool esFi() const;
    
    ///@brief Retorna el candidat actual.
    int actual() const;

private:

    int altEdifici; ///< Enter que representa l'altura de l'edifici i és el candidat a ser posat a la solució. 
    int maxAltEdifici; ///< Enter que indica l'altura màxima -o l'edifici més alt- que es pot arribar a incloure a la solució.
};

#endif /* CANDIDATS_H */
