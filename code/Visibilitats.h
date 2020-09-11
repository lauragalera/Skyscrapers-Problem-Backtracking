//Laura Galera Alfaro
//u1959173
//practica final

/// @file Visibilitats.h
/// @brief Classe Visibilitats

#ifndef VISIBILITATS_H
#define VISIBILITATS_H

#include <vector>
#include <iostream>

using namespace std;

/** @class Visibilitats
    @brief Classe que gestiona les visibilitats, segons els quatre punts cardinals, de la illeta d'edifics.
    @author Laura Galera Alfaro
 */

class Visibilitats {
public:
    
    ///@brief Constructor per defecte.
    Visibilitats();
    
    /* @brief Constructor per paràmetres
     * @pre   \p mida indica la mida de la illeta, és a dir, quantes visibilitats hi ha a cada punt cardinal.
     * @post  S'inicialitza l'objecte gràcies a \p mida, reservant l'espai pertinent per a la gestió de les
     *        visbilitats d'aquella solució. 
     */
    Visibilitats(int mida);
    
    /* @brief Indica si l'edifici satisfà la visibilitat nord per a ser acceptat.
     * @pre   \p alturaEdi és l'altura -el candidat- que es vol intentar afegir a aquella casella. \p pos és 
     *        la columna a la que fa referència la visibilitat i \p vistMax és la visibilitat que s'intenta 
     *        assolir en aquella columna des del nord. Només funciona quan la casella pertany a una última fila.
     * @post  Retorna cert quan, suposadament, si s'afegis \p alturaEdi en aquella casella, la visibilitat nord de la
     *        columna seria igual a la que s'intenta assolir. Fals altrament. 
     */
    bool finalFilaN(int alturaEdi, int pos, int vistMax) const;
    
    /* @brief Indica si l'edifici satisfà la visibilitat oest per a ser acceptat.
     * @pre   \p alturaEdi és l'altura -el candidat- que es vol intentar afegir a aquella casella. \p pos és 
     *        la fila a la que fa referència la visibilitat i \p vistMax és la visibilitat que s'intenta 
     *        assolir en aquella fila des de l'oest. Només funciona quan la casella pertany a una última columna.
     * @post  Retorna cert quan, suposadament, si s'afegis \p alturaEdi en aquella casella, la visibilitat oest de la
     *        fila seria igual a la que s'intenta assolir. Fals altrament. 
     */
    bool finalColO(int alturaEdi, int pos, int vistMax) const;
    
    /* @brief Indica si l'edifici satisfà la visibilitat sud per a ser acceptat.
     * @pre   \p alturaEdi és l'altura -el candidat- que es vol intentar afegir a aquella casella. \p pos és 
     *        la columna a la que fa referència la visibilitat, \p vistMax és la visibilitat que s'intenta 
     *        assolir en aquella columna des del sud i \p matriu és la illeta amb els edificis.
     *        Només funciona quan la casella pertany a una última fila.
     * @post  Retorna cert quan, suposadament, si s'afegis \p alturaEdi en aquella casella, la visibilitat sud de la
     *        columna seria igual a la que s'intenta assolir. Fals altrament. 
     */
    bool finalFilaS(int alturaEdi, int pos, int vistMax, int ** const matriu) const;
    
    /* @brief Indica si l'edifici satisfà la visibilitat est per a ser acceptat.
     * @pre   \p alturaEdi és l'altura -el candidat- que es vol intentar afegir a aquella casella. \p pos és 
     *        la fila a la que fa referència la visibilitat, \p vistMax és la visibilitat que s'intenta 
     *        assolir en aquella fila des de l'est i \p matriu és la illeta amb els edificis.
     *        Només funciona quan la casella pertany a una última columna.
     * @post  Retorna cert quan, suposadament, si s'afegis \p alturaEdi en aquella casella, la visibilitat est de la
     *        fila seria igual a la que s'intenta assolir. Fals altrament. 
     */
    bool finalColE(int alturaEdi, int pos, int vistMax, int ** const matriu) const;
    
    /* @brief Indica si l'edifici satisfà la visibilitat nord per a ser acceptat.
     * @pre   \p alturaEdi és l'altura -el candidat- que es vol intentar afegir a aquella casella. \p pos és 
     *        la columna a la que fa referència la visibilitat, \p vistMax és la visibilitat que s'intenta 
     *        assolir en aquella columna des del nord i \p fila és la fila on s'intenta afegir \p alturaEdi.
     *        Només funciona quan la casella no pertany a una última fila.
     * @post  Retorna cert quan, suposadament, si s'afegis \p alturaEdi en aquella casella, la visibilitat nord de la
     *        columna seria igual o més petita a la que s'intenta assolir. I a més, acceptant-lo si seria possible arribar 
     *        a la visibilitat desitjada. Fals altrament. 
     */
    bool filaN(int alturaEdi, int pos, int vistMax, int fila) const;
    
    /* @brief Indica si l'edifici satisfà la visibilitat oest per a ser acceptat.
     * @pre   \p alturaEdi és l'altura -el candidat- que es vol intentar afegir a aquella casella. \p pos és 
     *        la fila a la que fa referència la visibilitat, \p vistMax és la visibilitat que s'intenta 
     *        assolir en aquella fila des de l'oest i \p col és la columna on s'intenta afegir \p alturaEdi.
     *        Només funciona quan la casella no pertany a una última columna.
     * @post  Retorna cert quan, suposadament, si s'afegis \p alturaEdi en aquella casella, la visibilitat oest de la
     *        fila seria igual o més petita a la que s'intenta assolir. I a més, acceptant-lo si seria possible arribar 
     *        a la visibilitat desitjada. Fals altrament. 
     */
    bool colO(int alturaEdi, int pos, int vistMax, int col) const;
    
    /* @brief Modifica, si cal, la visibilitat, el màxim i l'índex de \c nord i \c oest quan s'anota
     *        un edifici a la illeta.
     * @pre   \p alturaEdi és l'altura -el candidat- que s'ha afegit a la illeta. \p f correspon a la fila
     *        i \p c a la columna per representar la casella de la matriu d'edificis.
     * @post  Els valors dels vectors \c nord i \c oest, segons \p f i \p c, queden modificats si
     *        \p alturaEdi passa a ser el nou màxim.
     */
    void anotarVistes(int alturaEdi, int f, int c);
    
    /* @brief Restaura, si cal, la visibilitat, el màxim i l'índex de \c nord i \c oest quan es desanota
     *        un edifici de la illeta.
     * @pre   \p alturaEdi és l'altura -el candidat- que s'ha desanotat de la illeta. \p f correspon a la fila
     *        i \p c a la columna per representar la casella de la matriu d'edificis.
     * @post  Els valors dels vectors \c nord i \c oest, segons \p f i \p c, queden modificats si
     *        \p alturaEdi coincideix amb el màxim i per tant cal restaurar els valors que hi havia
     *        prèviament.
     */
    void desanotarVistes(int alturaEdi, int f, int c);
private:

    struct visibilitatsAct {
        int maxima; ///< Enter que representa l'edifici més alt d'aquella fila o columna.
        int indexMaxim; ///< Enter que guarda l'índex de l'edifici més alt d'aquella fila o columna.
        int visibilitat; ///< Enter que indica les visibilitats fins el moment en aquella fila o columna.
        vector<int> pilaMaxims; ///< Vector d'enters que actua com a pila per controlar l'historial de màxims.
        vector<int> pilaIndexMaxims; ///< Vector d'enters que actua com a pila per controlar l'historial d'índexs dels màxims.

        ///@brief Constructor per paràmetres.
        visibilitatsAct(int m, int v, int i) {
            maxima = m;
            visibilitat = v;
            indexMaxim = i;
        }
    }; ///< Tupla que conté l'edifici més alt, el seu índex i les visibilitats que hi ha des d'aquella fila o columna.
    
    vector<visibilitatsAct> nord; /*< vector de visibilitats pel Nord, on l'índex coincideix amb la columna de la illeta.
                                   *  Per tant, la posició 0 del vector representa les visibilitats de la primera columna de la illeta
                                   *  d'edificis, on hi ha una tupla amb l'edifici d'altura màxima de la columna, el seu índex -la fila- 
                                   *  i les visibilitats actuals des del nord.
                                   */ 
    vector<visibilitatsAct> oest; /*< vector de visibilitats per l'Oest, on l'índex coincideix amb la fila de la illeta.
                                   *  Per tant, la posició 0 del vector representa les visibilitats de la primera fila de la illeta
                                   *  d'edificis, on hi ha una tupla amb l'edifici d'altura màxima de la fila, el seu índex -la columna- 
                                   *  i les visibilitats actuals des de l'oest.
                                   */ 
    
    int midaTauler; //Enter que guarda la mida de la illeta, és a dir, la mida dels vectors de visibilitats.

};

#endif /* VISIBILITATS_H */