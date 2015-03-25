#include <iostream>
#include "imp_NasiString.h"


using namespace std;

int main()
{
    nik::NasiString nastaran{"She's falling in love"};

    cout << "Nasi String Size is :" << nastaran.get_size() << "\n";

    nastaran = nastaran + " with Hamid";

    for(int i=0; i<nastaran.get_size();i++){
            cout << nastaran[i] << "\n";
    }

    return 0;
}
