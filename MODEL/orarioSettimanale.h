#ifndef ORARIOSETTIMANALEH
#define ORARIOSETTIMANALEH


#include<QString>
#include<vector>

using namespace std;

class orarioSettimanale
{
private:
    vector<int> orario;

public:
    orarioSettimanale(int lun=0, int mar=0, int mer=0, int gio=0, int ven=0, int sab=0);
    vector<int> getOrario() const;
    void modificaOrario(vector<int> v);
};


#endif // ORARIOSETTIMANALEH
