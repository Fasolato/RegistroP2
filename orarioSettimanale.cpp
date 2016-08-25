#ifndef ORARIOSETTIMANALE
#define ORARIOSETTIMANALE

#include"orarioSettimanale.h"


orarioSettimanale::orarioSettimanale(int lun, int mar, int mer, int gio, int ven, int sab)
{
    orario.push_back(lun);
    orario.push_back(mar);
    orario.push_back(mer);
    orario.push_back(gio);
    orario.push_back(ven);
    orario.push_back(sab);
}

void orarioSettimanale::modificaOrario(vector<int> v){
    for(int i=0; i<6; ++i)
        orario[i]=v[i];
}

vector<int> orarioSettimanale::getOrario() const
{
    return orario;
}


#endif // ORARIOSETTIMANALE
