//Laura Galera Alfaro
//u1959173
//practica final

/// @file Solucio.h
/// @brief Classe Solucio

#ifndef SOLUCIO_H
#define SOLUCIO_H

#include <vector>
#include <iostream>
#include "Candidats.h"
#include "Visibilitats.h"

using namespace std;

/** @class Solucio
    @brief Classe que guardar les dades addicionals per trobar la solució i el resultat.
    @author Laura Galera Alfaro
 */

class Solucio {
public:
    
    ///@brief Constructor per defecte.
    Solucio();
    
    /* @brief Es crea un objecte de tipus Solució a partir dels paràmetres d'entrada.
     * @pre   \p opcio és <b>u</b> per indicar si la intenció és buscar una solució o
     *        <b>m</b> si es vol buscar la millor. \p n, \p s, \p e i \p o són els vectors
     *        amb les visibilitats desitjades per cada punt cardinal. Per últim, \p a conté
     *        la disponibilitat d'alçades (la posició 0 del vector no es té en compte).
     * @post  Es crea una solució amb les dades dels paràmetres d'entrada. L'objecte
     *        està preparat per resoldre el problema.
     */
    Solucio(char opcio, const vector<int> & n, const vector<int> & s, const vector<int> & e, const vector<int> & o, const vector<int> & a);
    
    ///@brief Aquesta Solucio és una copia de \p s.
    Solucio(const Solucio &s);
    
    ///@brief Allibera memòria.
    ~Solucio();
    
    ///@brief Aquesta Solucio és una copia de \p s.
    Solucio & operator =(const Solucio &s);
    
    ///@brief
    Candidats inicialitzarCandidats() const;
    
    ///@brief Retorna cert si el candidat es pot afegir a la solució, fals altrament.
    bool acceptable(const Candidats &iCan);
    
    /* @brief S'afegeix el candidat a la solució.
     * @pre   \p iCan és acceptable
     * @post  S'inclou l'edifici a la solució.
     */
    void anotar(const Candidats &iCan);
    
    /* @brief Es treu \p iCan de la solució.
     * @pre   \p iCan és el darrer candidat anotat.
     * @post  Es treu l'edifici de la solució
     */
    void desanotar(const Candidats &iCan);
    
    ///@brief Retorna cert si la solució ja és completa, fals altrament.
    bool completa() const;
    
    ///@brief Retorna cert si és possible que aquesta solució arribi a ser millor que \p optima. 
    bool potSerMillor(const Solucio &optima) const;
    
    ///@brief Retorna cert si aquesta solució és millor que \p optima. 
    bool esMillor(const Solucio &optima) const;
    
    /* @brief Mostra la solució per pantalla.
     * @pre   La solucio és completa.
     * @post  Es mostra la matriu resultant per pantalla, és a dir, la illeta d'edificis, acompanyada de
     *        l'alçada total.
     */
    void mostrar() const;
    
    /* @brief Comprova que es disposen de suficient edificis per obtenir una solució.
     * @pre   Cridar després del constructor per paràmetres de \c Solucio.
     * @post  Retorna cert si es disposa de suficients edificis per emplenar la illeta de nxn, fals altrament.
     */
    bool potTenirSol() const;
private:
    
    bool possibilitatSol; ///< Booleà que indica si la solució té suficients edificis per emplenar la matriu.
    int nivell; ///< Enter que guarda el nivell en cada crida recursiva.
    int alturaTotal; ///< Enter que acumula l'altura dels edificis que es van incloent a matriu resultant.
    int midaTauler; ///< Enter que guarda la mida de la illeta.
    vector<int> alturesDisponibles; ///< Vector d'enters amb la quantitat d'edificis disponibles per cada altura. L'altura de l'edifici coincideix amb l'índex del vector.
    vector<vector<int>> visibilitatsMax; /*< Vector de mida quatre -una casella per cada punt cardinal- on a cadascuna hi ha un vector d'enters amb les visibilitats
                                          *  de les columnes (per nord i sud) i les visibilitats de les files (per est i oest).
                                          */
    vector<vector<bool>> columnes; /*< Vector de midaTauler posicions on cada casella representa una columna de la illeta. Per cada columna hi ha un vector de booleans
                                    *  de mida les alçades disponibles per controlar a quines columnes ja s'ha afegit aquell edifici.
                                    */
    vector<vector<bool>> files; /*< Vector de midaTauler posicions on cada casella representa una fila de la illeta. Per cada fila hi ha un vector de booleans
                                 *  de mida les alçades disponibles per controlar a quines files ja s'ha afegit aquell edifici.
                                 */
    Visibilitats visibilitatsAccum; ///< Objecte de tipus \c Visibilitats per gestionar les visibilitats actuals durant la resolució del problema.
    
    int **mSumes; /*< Matriu de punters de midaTauler*midaTauler. Emmagatzema a cada casella l'alçada que falta sumar a 
                   *  l'alçada actual per tal de tenir una aproximació a l'alçada màxim un cop completada la solució.
                   */  
    int **res;   ///< Matriu de punters de midaTauler*midaTauler on es guarda la solució que es va generant.
    
    ///@brief Reserva espai per a la memòria dinàmica.
    void reserva();
    
    ///@brief Aquesta solució és una copia de \p s.
    void copia(const Solucio &s);
    
    ///@brief Allibera memòria.
    void allibera();
};

#endif /* SOLUCIO_H */