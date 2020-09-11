//Laura Galera Alfaro
//u1959173
//practica final

#include "Solucio.h"

Solucio::Solucio(){
    midaTauler=0;
    mSumes = res = NULL;
    reserva();
}

Solucio::Solucio(const Solucio &s){
    copia(s);
}

Solucio::~Solucio(){
    //allibera();
}

Solucio & Solucio::operator =(const Solucio &s){
    
    if(this != &s){
        allibera();
        copia(s);
    }    
    return *this;
}

Solucio::Solucio(char opcio, const vector<int> & n, const vector<int>  & s, const vector<int> & e, const vector<int> & o, const vector<int> & a){
    
    midaTauler = n.size();
    nivell = alturaTotal = 0;
    alturesDisponibles = a;
    vector<int> aux = a;
    possibilitatSol = true;
    vector<int> v[] = {n, s, e, o};
    for(int i=0; i<4; i++){
        visibilitatsMax.push_back(v[i]);
    }

    reserva();
    for(int i=0; i<midaTauler; i++){
        for(int j=0; j<midaTauler; j++){
            res[i][j] = 0;
        }
    }
    for(int i=0; i<midaTauler; i++){
        columnes.push_back(vector<bool>(a.size()+1, false));
        files.push_back(vector<bool>(a.size()+1, false));
    }

    visibilitatsAccum = Visibilitats(midaTauler);
    
    int suma = 0;
    for(int i=1; i< int(aux.size()); i++){
        suma += aux[i];
    }
    possibilitatSol = (suma >= midaTauler*midaTauler);
    
    if(possibilitatSol and opcio == 'm'){ //per la millor solució, generem la matriu d'acumulacions.
        for(int i=midaTauler-1; i>= 0; i--){ //primer intentem emplenar la matriu amb els edificis més alts.
            int j = midaTauler-1;
            int edi = aux.size()-1;
            while(j>=0){
                if(aux[edi]!= 0){ //queden edificis d'aquesta altura
                    mSumes[i][j] = edi;
                    aux[edi]--;
                    j--;
                }
                edi--;
                if(edi<1 and j>-1){ //no es poden posar més en seqüència decreixent, tornem a començar
                    edi = aux.size()-1; 
                }
            }
        }
        
        suma = 0;
        for(int i=midaTauler-1; i>=0; i--){ //substituim els edificis per la suma acumulada
            for(int j=midaTauler-1; j>=0; j--){
                suma += mSumes[i][j];
                mSumes[i][j] = suma;
            }
        }
    }
}

Candidats Solucio::inicialitzarCandidats() const{
    return Candidats(alturesDisponibles.size()-1);
}

bool Solucio::acceptable(const Candidats &iCan){
    bool acceptable = true;
    if(alturesDisponibles[iCan.actual()] == 0) acceptable = false; //no queden edificis
    else{
        int fila = nivell/midaTauler;
        int columna = nivell%midaTauler;
        if(columnes[columna][iCan.actual()] == true || files[fila][iCan.actual()] == true){
          acceptable = false; //ja esta en aquesta fila o columna
        } 
        else{
             if(columna < midaTauler-1 && fila < midaTauler-1){ //ni a la ultima fila ni a la ultima columna
                 if(!visibilitatsAccum.filaN(iCan.actual(), columna, visibilitatsMax[0][columna], fila) || !visibilitatsAccum.colO(iCan.actual(), fila, visibilitatsMax[3][fila], columna))
                    acceptable = false;
            }else if(columna == midaTauler-1 && fila < midaTauler-1){ //ultima columna pero no ultima fila
                if(!visibilitatsAccum.filaN(iCan.actual(), columna, visibilitatsMax[0][columna], fila) || !visibilitatsAccum.finalColO(iCan.actual(), fila, visibilitatsMax[3][fila]) ||
                    !visibilitatsAccum.finalColE(iCan.actual(), fila, visibilitatsMax[2][fila], res))
                    acceptable = false;
            }else if(fila == midaTauler-1 && columna < midaTauler-1){ //ultima fila pero no ultima columna
                if(!visibilitatsAccum.finalFilaN(iCan.actual(), columna, visibilitatsMax[0][columna]) || !visibilitatsAccum.colO(iCan.actual(), fila, visibilitatsMax[3][fila], columna) ||
                    !visibilitatsAccum.finalFilaS(iCan.actual(), columna, visibilitatsMax[1][columna], res))
                    acceptable = false;
            }else{ //ultima fila i ultima columna
                if(!visibilitatsAccum.finalFilaN(iCan.actual(), columna, visibilitatsMax[0][columna]) || !visibilitatsAccum.finalColO(iCan.actual(), fila, visibilitatsMax[3][fila]) ||
                   !visibilitatsAccum.finalFilaS(iCan.actual(), columna, visibilitatsMax[1][columna], res) || !visibilitatsAccum.finalColE(iCan.actual(), fila, visibilitatsMax[2][fila], res))
                    acceptable = false;
            }
        }
    }
    return acceptable;
}

void Solucio::anotar(const Candidats &iCan){
    
    int fila = nivell/midaTauler;
    int columna = nivell%midaTauler;
    visibilitatsAccum.anotarVistes(iCan.actual(), fila, columna);
    alturaTotal+=iCan.actual();
    alturesDisponibles[iCan.actual()]--;
    columnes[columna][iCan.actual()] = files[fila][iCan.actual()] = true;
    res[fila][columna] = iCan.actual();
    nivell++; 
}

void Solucio::desanotar(const Candidats &iCan){
    
    nivell--;
    int fila = nivell/midaTauler;
    int columna = nivell%midaTauler;
    res[fila][columna] = 0;
    columnes[columna][iCan.actual()] = files[fila][iCan.actual()] = false;
    alturesDisponibles[iCan.actual()]++;
    alturaTotal-=iCan.actual();
    visibilitatsAccum.desanotarVistes(iCan.actual(), fila, columna);
}

bool Solucio::potTenirSol() const{
    return possibilitatSol;
}
bool Solucio::completa() const{
    return (nivell == midaTauler*midaTauler);
}

void Solucio::mostrar() const{
    cout<<"  ";
    for(int i=0; i<midaTauler; i++){
        cout<<visibilitatsMax[0][i]<<" ";
    }
    cout<<endl;
    
    for(int i=0; i<midaTauler; i++){
        cout<<visibilitatsMax[3][i]<<" ";
        for(int j=0; j<midaTauler; j++){
            cout<<res[i][j]<<" ";
        }
        cout<<visibilitatsMax[2][i]<<endl;
    }
    cout<<"  ";
    for(int i=0; i<midaTauler; i++){
        cout<<visibilitatsMax[1][i]<<" ";
    }
    cout<<endl;
    cout<<"Alçada total: "<<alturaTotal<<endl;
}

bool Solucio::potSerMillor(const Solucio &optima) const{
    int col = nivell%midaTauler;
    int fila = nivell/midaTauler;
    return (alturaTotal + mSumes[fila][col] >= optima.alturaTotal);
}

bool Solucio::esMillor(const Solucio &optima) const{
    return (alturaTotal > optima.alturaTotal);
}

void Solucio::reserva(){
    res = new int*[midaTauler];
    mSumes = new int*[midaTauler];
    
    for(int i=0; i<midaTauler; i++){
        res[i] = new int[midaTauler];
        mSumes[i] = new int[midaTauler];
    }
}

void Solucio::copia(const Solucio &s){
    midaTauler = s.midaTauler;
    alturaTotal = s.alturaTotal;
    possibilitatSol = s.possibilitatSol;
    nivell = s.nivell;
    alturesDisponibles = s.alturesDisponibles;
    visibilitatsMax = s.visibilitatsMax;
    columnes = s.columnes;
    files = s.files;
    visibilitatsAccum = s.visibilitatsAccum;
    reserva();
    for(int i=0; i<midaTauler; i++){
        for(int j=0; j<midaTauler; j++){
                res[i][j] = s.res[i][j];
                mSumes[i][j] = s.mSumes[i][j];
            
        }
    }
}
    
void Solucio::allibera(){
    
    if(midaTauler >0){
        for(int i=0; i<midaTauler; i++){
            delete [] res[i];
            delete [] mSumes[i];
        }
        delete [] res; 
        delete [] mSumes;
    }
}