#include <iostream>
#include "imp_NasiString.h"


using namespace std;

int main()
{
    nik::NasiString nastaran{"She's"};

    cout << "Nasi String init Size is :" << nastaran.get_size() << "\n";

    nastaran = nastaran + " falling";
    nastaran = nastaran + " in love with";
    nastaran = nastaran + " Hamid :D";


    cout << nastaran.c_str() << "\n";

    cout << "Nasi String Size is :" << nastaran.get_size() << "\n";

    return 0;
}
