#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    registerTestlibCmd(argc, argv);

    set<string> expected;
    set<string> user;

    while (!ans.eof()) expected.insert(ans.readLine());
    while (!ouf.eof()) user.insert(ouf.readLine());

    if (expected == user) quitp(_pc(2), "Poprawna odpowiedź");
    
    for (string s : user)
    {
        if (!expected.count(s)) quitp(_pc(0), s + " nie jest palindromem");
    }

    if (user.size() * 2 >= expected.size())
        quitp(_pc(1), "Poprawnie podano %d z %d wymaganych palindromów", user.size(), expected.size());
    else
        quitp(_pc(0), "Poprawnie podano jedynie %d z %d wymaganych palindromów", user.size(), expected.size());
}