#include <iostream>
#include "List.h"

int main() {

    int* p = nullptr;
    int n = 10;
    List<int> l (n);
    l.add((int) 15);
    l.add((int) 20);

    l.remove((int )15);
    l.remove((int) 111);



    return 0;
}

/*
 *
 * Classi che rappresentano chat tra utenti. Si deve rappresentare un utente di un sistema,
 * un messaggio di chat da un utente ad un altro, una classe che rappresenta una chat tra due utenti,
 * un registro di tutte le chat fatte.
 *
 */