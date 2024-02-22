#include "etasjeliste.h"

int etasjeliste_opp[] = {0,0,0,0};
int etasjeliste_ned[] = {0,0,0,0};

int etasjeliste_hent(int etasje, int retning){
    if(retning == 1){
        return etasjeliste_opp[etasje];
    }
    else if(retning == -1){
        return etasjeliste_ned[etasje];
    }
    else{
        return -1;
    }
}

void etasjeliste_sett(int etasje, int retning, int verdi){
    if(retning == 1){
        etasjeliste_opp[etasje] = verdi;
    }
    else if(retning == -1){
        etasjeliste_ned[etasje] = verdi;
    }
}

void etasjeliste_reset(int etasje){
    etasjeliste_opp[etasje] = 0;
    etasjeliste_ned[etasje] = 0;
}

void etasjeliste_reset_all(){
    for(int i = 0; i < 4; i++){
        etasjeliste_opp[i] = 0;
        etasjeliste_ned[i] = 0;
    }
}

int etasjeliste_hent_neste(int etasje, int retning){
    if(retning == 1){
        for(int i = etasje; i < 4; i++){
            if(etasjeliste_opp[i] == 1){
                return i;
            }
        }
        for(int i = etasje; i >= 0; i--){
            if(etasjeliste_ned[i] == 1){
                return i;
            }
        }
    }
    else if(retning == -1){
        for(int i = etasje; i >= 0; i--){
            if(etasjeliste_ned[i] == 1){
                return i;
            }
        }
        for(int i = etasje; i < 4; i++){
            if(etasjeliste_opp[i] == 1){
                return i;
            }
        }
    }
    return -1;
}