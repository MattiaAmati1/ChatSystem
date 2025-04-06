#include <iostream>
#include <limits>

#include "ChatRegister.h"
#include "User.h"

User* getUserByName(const std::list<User*>& users, const std::string& name);

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
        //show the entire chat with an user
        //log out and close
        //change user, when user changes, display the unread messages amount

    std::cout << "Enter username " << std::endl;
    std::string name;
    std::cin >> name;
    User* loggedUser = new User(name, &chatRegister);
    users.push_back(loggedUser);


    int selection;
    bool programTerminated = false;

    while (!programTerminated) {
        std::cout << "Enter 1 to create a new chat, 2 to send a message, 3 to change user, 4 to create a new user, "
                     "5 to show the chat with another user, 0 to quit" << std::endl;
        std::cout << "Logged in as user: " << loggedUser -> getUsername() << std::endl;

        if(!(std::cin >> selection)) { //checks for non-numeric inputs and prevents fatal errors
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            selection = -1;
        }

        switch (selection) {
            case 1:
                std::cout << "Enter username: " << std::endl;
                std::cin >> name;
                if(name == loggedUser -> getUsername()) {
                    std::cout << "Cannot create a chat with yourself" << std::endl;
                    break;
                }
                tmp = getUserByName(users, name);
                if(tmp == nullptr)
                    std::cout << "User " << name << " does not exist" << std::endl;
                else {
                    loggedUser -> createChat(tmp, chats);
                    chats++;
                }
                break;
            case 2:
                std::cout << "Enter username: " << std::endl;
                std::cin >> name;
                if(name == loggedUser -> getUsername()) {
                    std::cout << "Cannot send messages to yourself" << std::endl;
                    break;
                }
                tmp = getUserByName(users, name);
                if(tmp == nullptr) {
                    std::cout << "User " << name << " does not exist" << std::endl;
                    break;
                }

                if(chatRegister.getChatWithUsers(loggedUser, tmp) == nullptr) {
                    std::cout << "A chat with user " << name << " does not exist" << std::endl;
                    break;
                }

                std::cout << "Enter message contents: " << std::endl;
                std::cin >> messageText;
                msg = new Message(messageText, loggedUser -> getUsername());
                loggedUser -> sendMessage(tmp, *msg);
                delete msg;
                break;
            case 3:

                std::cout << "Enter username: " << std::endl;
                std::cin >> name;

                if(getUserByName(users, name) == nullptr) {
                    std::cout << "User " << name << " does not exist" << std::endl;
                    break;
                }

                loggedUser = getUserByName(users, name);
                std::cout << "User " << name << " has " << loggedUser -> getUnreadMessages() << " unread messages" << std::endl;

                break;
            case 4:
                std::cout << "Enter username: " << std::endl;
                std::cin >> name;
                if(getUserByName(users, name) != nullptr) {
                    std::cout << "User " << name << " already exists" << std::endl;
                    break;
                }

                loggedUser = new User(name, &chatRegister);
                users.push_back(loggedUser);
                break;
            case 5:
                std::cout << "Enter username: " << std::endl;
                std::cin >> name;
                tmp = getUserByName(users, name);
                if(tmp == nullptr) {
                    std::cout << "User " << name << " does not exist" << std::endl;
                    break;
                }

                chat = chatRegister.getChatWithUsers(loggedUser, tmp);
                if(chat == nullptr) {
                    std::cout << "A chat with user " << name << " does not exist" << std::endl;
                    break;
                }

                chat -> showChatContent();
                break;

            case 0:
                programTerminated = true;
                break;
            default:
                std::cout << "Invalid selection" << std::endl;
            break;
        }
    }
}

User* getUserByName(const std::list<User*>& users, const std::string& name) {
    for(const auto user : users)
        if(user -> getUsername() == name)
            return user;

    return nullptr;
}

/*
 *
 * Classi che rappresentano chat tra utenti. Si deve rappresentare un utente di un sistema,
 * un messaggio di chat da un utente ad un altro, una classe che rappresenta una chat tra due utenti,
 * un registro di tutte le chat fatte.
 *
 */
