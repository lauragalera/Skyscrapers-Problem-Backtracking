//Laura Galera Alfaro
//u1959173
//practica final

#include "Solucionador.h"

Solucionador::Solucionador(const Solucio & sIni) {
    
    sol = sIni;
    soptima = sIni;
    encertat = false;
}
void Solucionador::solucionar(char opcio){
    if(sol.potTenirSol()){
        if(opcio=='m'){
            algBackMillorSol();
            if(!encertat) cout<<"No hi ha solució"<<endl;
            else soptima.mostrar();
        }else{
            algBackUnaSol();
            if(!encertat) cout<<"No hi ha solució"<<endl;
            else sol.mostrar();
        }
    }else cout<<"No hi ha solució"<<endl;
}

void Solucionador::algBackUnaSol(){
    Candidats iCan = sol.inicialitzarCandidats();
    while(!iCan.esFi() && !encertat){
        if(sol.acceptable(iCan)){
            sol.anotar(iCan);
            if(!sol.completa()){
                algBackUnaSol();
                if(!encertat)
                    sol.desanotar(iCan);
            } else{
                encertat = true;
            }
        }
        iCan.seguent();
    }
}

void Solucionador::algBackMillorSol(){
    
    Candidats iCan = sol.inicialitzarCandidats();
    while(!iCan.esFi()){
        if(sol.acceptable(iCan) && sol.potSerMillor(soptima)){
            sol.anotar(iCan);
            if(!sol.completa()){
                algBackMillorSol();
            } else if(sol.esMillor(soptima)){
                if(encertat == false) encertat = true;
                soptima = sol;
            }
            sol.desanotar(iCan);
        }
        iCan.seguent();
    }
}
