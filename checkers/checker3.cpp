#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    registerTestlibCmd(argc, argv);

    int en = ans.readInt();
    string es = ans.readString();

    int un = ouf.readInt();
    string us = ouf.readString();
    
    if (un == en && es == us) quitp(_pc(2), "Poprawna liczba i napis");
    else if (un == en) quitp(_pc(1), "Poprawna tylko liczba");
    else if (un == en) quitp(_pc(1), "Poprawny tylko napis");
    else quitp(_pc(0), "Odpowiedź jest niepoprawna :(");
}