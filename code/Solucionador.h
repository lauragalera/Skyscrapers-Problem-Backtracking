//Laura Galera Alfaro
//u1959173
//practica final

/// @file Solucionador.h
/// @brief Classe Solucionador

#ifndef SOLUCIONADOR_H
#define SOLUCIONADOR_H

#include "Solucio.h"
#include "Candidats.h"
#include <string>

using namespace std;

/** @class Solucionador
    @brief Classe que encapsula els algoritmes
    @author Laura Galera Alfaro
 */
class Solucionador {
public:
    
    /* @brief S'inicialitza l'objecte a partir de la Solucio d'entrada.
     * @pre   \p sIni és una Solucio preparada per resoldre un problema.
     * @post  Es crea un objecte Solucionador inicialitzat amb \p sIni,
     *        amb la qual es començarà a treballar.
     */
    Solucionador(const Solucio &sIni);
    
    /* @brief Busca una o la millor solució, depent del paràmetre d'entrada, i la mostra
     *        per pantalla si és que la troba.
     * @pre   \p opcio és <b>u</b> si es vol trobar una solució al problema o <b>m</b> si
     *        es vol trobar la solució que maximitza les altures dels edificis.
     * @post  Mostra una solució al problema o específicament aquella que maximitza
     *        les alçades, això en funcio d'\p opcio. Si no hi ha solució es mostra un
     *        missatge.  
     */
    void solucionar(char opcio);
private:
    
    /* @brief Algorisme de backtracking que busca una solució.
     * @pre   \c Encertat és <b>false</b> i \c sol és parcial.
     * @post  \c Encertat és <b>false</b> o \c encertat és <b>true</b> i \c sol és completa.
     */
    void algBackUnaSol();
    
    /* @brief Algorisme de backtracking que busca la millor solució.
     * @pre   \c sol conté la illeta que es vol omplir.
     * @post  S'omple la illeta de totes les maneres i es guarda la millor opció, és
     *        a dir, aquella en què la suma d'altures dels edificis és la màxima.
     */
    void algBackMillorSol();
    
    bool encertat; ///< Booleà que indica si s'ha trobat una solució, com a mínim.
    Solucio sol; ///< Objecte \c Solucio que guarda la solució que s'intenta completar -completa si es troba solucio-.
    Solucio soptima; ///< Objecte \c Solucio que guarda la millor solució al problema.
};

#endif /* SOLUCIONADOR_H */
