#include <iostream>
#include <bits/ranges_algo.h>

#include "ChatRegister.h"
#include "User.h"

bool contains(const std::list<User*>& users, User* user);

int main() {

    ChatRegister chatRegister;
    User* loggedUser;
    std::list<User*> users;

    //landing screen: sign up or log in (entering username)
    //once in a user profile:
        //create a new chat with some other user
        //send a message to some user (in an already created chat)
        //log out and close
        //change user, when user changes, display the unread messages amount

    std::cout << "Enter username " << std::endl;
    std::string name;
    std::cin >> name;
    loggedUser = new User(name, &chatRegister);
    users.push_back(loggedUser);

    std::cout << "Enter 1 to create a new chat, 2 to send a message, 3 to logout" << std::endl;


    return 0;
}

bool contains(const std::list<User*>& users, User* user) {
    for(const auto u : users)
        if(*u == *user)
            return true;

    return false;
}

User* login() {
    std::
}
/*
 *
 * Classi che rappresentano chat tra utenti. Si deve rappresentare un utente di un sistema,
 * un messaggio di chat da un utente ad un altro, una classe che rappresenta una chat tra due utenti,
 * un registro di tutte le chat fatte.
 *
 */