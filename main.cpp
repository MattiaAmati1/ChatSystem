#include <iostream>
#include <limits>

#include "ChatRegister.h"
#include "User.h"

int main() {

    ChatRegister chatRegister;
    User* tmp;
    std::list<User*> users;
    Message* msg;
    std::string messageText;
    Chat* chat;
    int chats = 0;

    //landing screen: sign up or log in (entering username)
    //once in a user profile:
        //create a new chat with some other user
        //send a message to some user (in an already created chat)
        //show the entire chat with a user
        //view all unread messages
        //log out and close
        //change user, when user changes, display the unread messages amount

    std::cout << "Enter username " << std::endl;
    std::string name;
    std::cin >> name;
    User* loggedUser;
    users.push_back(loggedUser);

    int selection;
    bool programTerminated = false;

    while (!programTerminated) {
        std::cout << "Enter 1 to create a new chat, 2 to send a message, 3 to switch to an existing user,"
                     " 4 to create a new user, 5 to show the chat with another user, 6 to view all unread messages,"
                     " 0 to quit" << std::endl;
        std::cout << "Logged in as user: " << loggedUser -> getUsername() << std::endl;

        if(!(std::cin >> selection)) { //checks for non-numeric inputs and prevents fatal errors
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            selection = -1;
        }

        switch (selection) {

            default:
                std::cout << "Invalid selection" << std::endl;
            break;
        }
    }
}


