#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    registerTestlibCmd(argc, argv);

    int en = ans.readInt();
    set<pair<int, int>> e;

    for (int i = 0; i < en; ++i)
    {
        int a = ans.readInt(), b = ans.readInt();
        e.emplace(a, b);
    }
    ans.readEof();

    int un = ouf.readInt();

    if (ouf.eof())
    {
        if (un == en) quitp(_pc(1), "Podano poprawną liczbę kwadratów, ale nie podano ich współrzędnych");
        else quitp(_pc(0), "Odpowiedź jest niepoprawna :(");
    }

    int good = 0, bad = 0;

    for (int i = 0; i < un; ++i)
    {
        int a = ouf.readInt(), b = ouf.readInt();

        if (e.count(make_pair(a, b))) ++good;
        else ++bad;
    }
    ouf.readEof();
    
    if (un == en) quitp(_pc(1 + good), "Poprawna liczba kwadratów. Poprawnie podano %d z %d współrzędnych kwadratów", good, en);

    if (good == en && bad == 1)
        quitp(_pc(2), "Podano o jeden kwadrat za dużo");
    else if (good == en && bad == 2)
        quitp(_pc(1), "Podano o 2 kwadraty za dużo");
    else
        quitp(_pc(0), "Odpowiedź jest niepoprawna :(");
}