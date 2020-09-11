//Laura Galera Alfaro
//u1959173
//practica final

#include "Visibilitats.h"


Visibilitats::Visibilitats(){}

Visibilitats::Visibilitats(int mida){
    
    midaTauler = mida;
    
    for(int i= 0; i<mida; i++){
        nord.push_back(visibilitatsAct(0,0,0));
        oest.push_back(visibilitatsAct(0,0,0));
    }
}

bool Visibilitats::finalFilaN(int alturaEdi, int pos, int vistMax) const{
    
    if(alturaEdi < nord[pos].maxima){
        return nord[pos].visibilitat == vistMax;
    } else{
        return nord[pos].visibilitat+1 == vistMax;
    }
}

bool  Visibilitats::finalColO(int alturaEdi, int pos, int vistMax) const{
    
    if(alturaEdi < oest[pos].maxima){
        return oest[pos].visibilitat == vistMax;
    } else{
        return oest[pos].visibilitat+1 == vistMax;
    }
}

bool  Visibilitats::finalFilaS(int alturaEdi, int pos, int vistMax, int ** const matriu) const{
    
    if(alturaEdi < nord[pos].maxima){ //no sabem les visibilitats entre l'últim edifici i el màxim
        
        int posMax = nord[pos].indexMaxim;
        int posIni = midaTauler-1;
        int vis = 1; //comptem el primer, que segur es veu
        int darrerVisMesAlt = alturaEdi;
        
        while (posIni > posMax){ //mentre no arribem a la posició del màxim...
            if(darrerVisMesAlt < matriu[posIni-1][pos]){ //si l'actual és més petit que el que ve a continuació...
                vis++;
                darrerVisMesAlt = matriu[posIni-1][pos];
            }
            posIni--;
        }
        
        return vis == vistMax; 
        
    }else //el nou edifici seria el màxim
        return vistMax==1;
}

bool  Visibilitats::finalColE(int alturaEdi, int pos, int vistMax, int ** const matriu) const{
    
    if(alturaEdi < oest[pos].maxima){ //no sabem les visibilitats entre l'últim edifici i el màxim
        
        int posMax = oest[pos].indexMaxim;
        int posIni = midaTauler-1;
        int vis = 1; //comptem el primer, que segur es veu
        int darrerVisMesAlt = alturaEdi;
        
        while(posIni > posMax){ //mentre no arribem a la posició del màxim...
            if(darrerVisMesAlt < matriu[pos][posIni-1]){ //si l'actual és més petit que el que ve a continuació...
                vis++;
                darrerVisMesAlt = matriu[pos][posIni-1];
            }
            posIni--;
        }
        
        return vis == vistMax;
        
    }else //el nou edifici seria el màxim
        return vistMax==1;
}

bool  Visibilitats::filaN(int alturaEdi, int pos, int vistMax, int fila) const{
    
    if(alturaEdi > nord[pos].maxima)
        return (nord[pos].visibilitat+1 <= vistMax and vistMax <= nord[pos].visibilitat+1+(midaTauler-fila-1)); //no sobrepassa la visibilitat esperada i sí és possible igualar-la -si no s'ha fet ja-.
    else return (vistMax <= nord[pos].visibilitat+(midaTauler-fila-1));
}

bool  Visibilitats::colO(int alturaEdi, int pos, int vistMax, int col) const{
    if(alturaEdi > oest[pos].maxima)
        return (oest[pos].visibilitat+1 <= vistMax and vistMax <= oest[pos].visibilitat+1+(midaTauler-col-1)); //no sobrepassa la visibilitat esperada i sí és possible igualar-la -si no s'ha fet ja-.
    else return (vistMax <= oest[pos].visibilitat+(midaTauler-col-1));
}
    
void  Visibilitats::anotarVistes(int alturaEdi, int f, int c){
    
    if(alturaEdi > nord[c].maxima){ //el candidat ocupa el lloc del màxim a la columna
        nord[c].pilaMaxims.push_back(nord[c].maxima);
        nord[c].pilaIndexMaxims.push_back(nord[c].indexMaxim);
        nord[c].visibilitat++;
        nord[c].maxima = alturaEdi;
        nord[c].indexMaxim = f;
    }
    
    if(alturaEdi > oest[f].maxima){ //el candidat ocupa el lloc del màxim a la fila
        oest[f].pilaMaxims.push_back(oest[f].maxima);
        oest[f].pilaIndexMaxims.push_back(oest[f].indexMaxim);
        oest[f].visibilitat++;
        oest[f].maxima = alturaEdi;
        oest[f].indexMaxim = c;
    }
    
}

void  Visibilitats::desanotarVistes(int alturaEdi, int f, int c){
    
    if(alturaEdi == nord[c].maxima){ //el candidat era el màxim de la columna
        nord[c].maxima = nord[c].pilaMaxims.back();
        nord[c].pilaMaxims.pop_back();
        nord[c].indexMaxim = nord[c].pilaIndexMaxims.back();
        nord[c].pilaIndexMaxims.pop_back();
        nord[c].visibilitat--;
    }
    
    if(alturaEdi == oest[f].maxima){ //el candidat era el màxim de la fila
        oest[f].maxima = oest[f].pilaMaxims.back();
        oest[f].pilaMaxims.pop_back();
        oest[f].indexMaxim = oest[f].pilaIndexMaxims.back();
        oest[f].pilaIndexMaxims.pop_back();
        oest[f].visibilitat--;

    }
}