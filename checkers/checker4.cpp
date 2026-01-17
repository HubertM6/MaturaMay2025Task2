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

    if (ouf.eof())
    {
        if (un == en) quitp(_pc(1), "Podano poprawnie zapis dzisiętny, niepodano odpowiadającego zapisu");
        else quitp(_pc(0), "Odpowiedź jest niepoprawna :(");
    }

    string us = ouf.readString();

    bool decimalOk = en == un;

    bool symbolOk = true, ternaryOk = true;

    map<char, char> m = {
        {'o', '0'},
        {'+', '1'},
        {'*', '2'}
    };

    if (us.size() == es.size())
    {
        for (int i = 0; i < us.size(); ++i)
        {
            if (us[i] != es[i]) symbolOk = false;
            if (us[i] != m[es[i]]) ternaryOk = false;
        }
    }
    else
    {
        symbolOk = false;
        ternaryOk = false;
    }
    
    if (decimalOk && symbolOk) quitp(_pc(3), "Poprawna liczba w systemie dziesiętnym i z użyciem symboli");
    else if (decimalOk && ternaryOk) quitp(_pc(2), "Poprawna liczba w systemie dziesiętnym i trójkowym");
    else if (decimalOk) quitp(_pc(1), "Poprawna liczba tylko w systemie dziesiętnym");
    else if (symbolOk) quitp(_pc(2), "Poprawna liczba tylko w zapisie z użyciem symboli");
    else if (ternaryOk) quitp(_pc(1), "Poprawna liczba tylko w systemie trójkowym");
    else quitp(_pc(0), "Odpowiedź jest niepoprawna :(");
}