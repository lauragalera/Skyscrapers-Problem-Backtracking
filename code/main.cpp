//Laura Galera Alfaro
//u1959173
//pràctica 1

/**
 *@file main.cpp
 *@brief part principal del programa
 *@author Laura Galera Alfaro
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "Solucio.h"
#include "Solucionador.h"

using namespace std;

/** @brief Mostra l'ajuda del programa.
 *  @pre   Cert.
 *  @post  Mostra un missatge complet amb quins paràmetres usar al programa i què volen dir cadascun d'ells.  
 */
void mostrarAjuda(char* nomPrograma);

/** @brief Retorna un vector de vectors d'enters amb les dades llegides, provinents del fitxer proporcionat.
 *  @pre   \p nomFitxer conté les dades en el següent format:
 *              \verbatim
                dimensió(n) // dimensió matriu
                vN1 vN2 ... vNn // visibles des del nord
                vS1 vS2 ... vSn // visibles des del sud
                vE1 vE2 ... vEn // visibles des de l’est
                vW1 vW2 ... vWn // visibles des de l’oest
                altura maxima(m) // altura màxima disponible
                a1 a2 ... am // edificis disponibles de cada altura
                \endverbatim
 *  @post  Retorna un vector de mida 5 de vectors d'enters sempre i quan el fitxer s'hagi obert sense problemes, sinó
 *         retorna un vector buit. El vector a retornar conté a la primera posició les visibilitats del nord en un vector
 *         d'enters, en segon lloc les visibilitats del sud i així consecutivament fins les visibilitats de l'oest a la
 *         posició 3. A la última casella s'hi guarden els edificis disponibles de cada altura en un altre vector d'enters.
 *         En aquest cas, l'altura de l'edifici coincideix amb l'índex del vector on s'hi troba la quantitat disponible
 *         d'aquesta mateixa altura.
 */
vector<vector<int>> llegirFitxer(char* nomFitxer);

/** @brief Es llegeixen les dades i s'aplica, depenent de l'opció, un algoritme o un altre per tal de trobar
 *         una/la solució.
 *  @pre   \p opcio és <b>u</b> quan es busca una solució al problema i va acompanyat d'<b>alt</b>, que indica l'altura màxima
 *         d'edificis que es volen usar. Pel contrari, \p opcio és <b>m</b> quan es vol trobar la solució que maximitza les altures.
 *         En aquest cas, el valor d'<b>alt</b> és indiferent.
 *  @post  Es llegeixen les dades del fitxer d'entrada i es mostra un missatge si no s'ha pogut realitzar aquesta acció.
 *         Si les dades s'han llegit sense problemes, depenent d'\p opcio, s'intenta trobar una/la solució que satisfà el problema.
 *         Aquesta es mostra acompanyada del temps d'execució. Si no s'ha trobat cap solució, es mostra un missatge també acompanyat
 *         del temps d'execució.   
 */
void gestionarProblema(char opcio, char* alt, char* nomFitxer);

/** @brief Gestiona les opcions del programa i, si cal, mostra un missatge d'error quan no es compleix el format correcte de paràmetres
 *         per procedir amb l'execució d'aquest.
 *  @pre   Cert.
 *  @post  A partir dels paràmetres d'entrada, s'escull una de les tres opcions disponibles en què es basa el programa: mostrar el menú d'ajuda,
 *         trobar una solució que permeti emplenar una illeta de nxn edificis seguint unes restriccions, o trobar la solució que maximitza l'altura
 *         dels edificis col·locats a la illeta. Depent de quina es tracti, es mostra l'ajuda o es llegeixen les dades d'un fitxer d'entrada i es busca
 *         una/la solució al problema, per així mostrar-la per pantalla posteriorment si és possible. Si els paràmetres entrats no condueixen amb cap
 *         opció es mostra un missatge per alertar perquè no es pot prosseguir amb l'execució del programa.
 */
int main(int argc, char** argv) {
    if(argc < 2){
        cout<<"Falten arguments (\""<<argv[0]<<" --help\" per ajuda) \n\n";
        return 0;
    }
    else{ //dos o mes parametres
        string arg = argv[1];
        if(arg == "--help" or arg == "-h"){
            mostrarAjuda(argv[0]);
            return 0;
        }
        else if(arg == "-u" and argc < 4){
            cout<<"Falta altura màxima tolerada o nom fitxer"<<endl;
            return -1;
        }else if(arg == "-m" and argc < 3){
            cout<<"Falta el nom del fitxer"<<endl;
            return -1;
        }else if(arg!= "-u" and arg!= "-m"){
            cout<<"Opció desconeguda: "<<arg<<endl;
            return -1;
        }else{
            if(arg== "-u")
                gestionarProblema('u', argv[2], argv[3]);
            else gestionarProblema('m',(char*)"-1", argv[2]);
            return 0;
        }
    }
}

/***********************************/
/*FUNCIONS I ACCIONS: IMPLEMENTACIÓ*/
/***********************************/

void mostrarAjuda(char* nomPrograma) {
    
    cout << "*** Distribució de gratacels en una illa d’edificis quadrada ***" << endl;
    cout << "Utilització: " << nomPrograma << " opcio fitxer \n\n";
    cout << "opcio pot ser:" << endl;
    cout << "-h, --help" << setw(45) << ": mostra aquest missatge d’ajuda i surt." << endl;
    cout << "-u alt" << setw(60) << ": cerca una solució que compleixi les restriccions \n";
    cout << setw(82) << "del problema sense fer servir edificis d'una altura superior a alt." << endl;
    cout << "-m" << setw(54) << ": cerca la solució que maximitza la suma \n";
    cout << setw(66) << " de les altures de tots els edificis de la solució." << endl;
    cout << "fitxer" << setw(58) << "ha de ser un fitxer de text amb totes les dades \n";
    cout << setw(40) << "amb el format següent: \n" << right << setw(47) << "dimensió(n) // dimensió matriu" << endl;
    cout << right << setw(55) << "vN1 vN2 ... vNn // visibles des del nord" << endl;
    cout << right << setw(54) << "vS1 vS2 ... vSn // visibles des del sud" << endl;
    cout << right << setw(57) << "vE1 vE2 ... vEn // visibles des de l’est" << endl;
    cout << right << setw(58) << "vW1 vW2 ... vWn // visibles des de l’oest" << endl;
    cout << right << setw(60) << "altura maxima(m) // altura màxima disponible" << endl;
    cout << right << setw(66) << "a1 a2 ... am // edificis disponibles de cada altura" << endl;
}

vector<vector<int>> llegirFitxer(char* nomFitxer) {

    vector<vector<int>> v;
    ifstream f(nomFitxer);
    if (f.is_open()) { //el fitxer s'ha pogut obrir
        v.resize(5);
        int mida;
        f >>mida;
        for (int i = 0; i < 4; i++) { //llegim les vistes de cada punt cardinal (n, s, e, o)
            v[i].reserve(mida);
            for (int j = 0; j < mida; j++) {
                int n;
                f >>n;
                v[i].push_back(n);
            }
        }
        f >>mida;
        v[4].reserve(mida + 1);
        v[4].push_back(0); //sentinella
        for (int i = 0; i < mida; i++) { //llegim les alçades
            int n;
            f >>n;
            v[4].push_back(n);
        }
    }
    return v;
}

void gestionarProblema(char opcio, char* alt, char* nomFitxer) {

    vector<vector<int>> dades = llegirFitxer(nomFitxer);
    if (dades.size() > 0) {
        int altura = atoi(alt);
        if (opcio == 'u' and altura + 1 < int(dades[4].size()))
            dades[4].resize(altura + 1);
        Solucio sIni(opcio, dades[0], dades[1], dades[2], dades[3], dades[4]);
        Solucionador unaSol(sIni);
        using namespace std::chrono;
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        unaSol.solucionar(opcio);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> time_span = duration_cast< duration<double> >(t2 - t1);

        cout << "Temps: " << time_span.count() << " segons" << endl;
    } else cout << "El fitxer [" << nomFitxer << "] no es pot obrir. Revisa el nom o els permisos" << endl;
}