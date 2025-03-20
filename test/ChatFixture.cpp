#include "gtest/gtest.h"
#include "../Chat.h"

class ChatSuite : public testing::Test {
    protected:
        virtual void SetUp(){
            c = new Chat(1);
        }
        Chat* c = nullptr;
};

TEST_F(ChatSuite, TestAddRemove){

    User user("testuser");
    c->addMember(user); //addMember uses push_back method
    std::string name = c->getUsers().back().getUsername();
    ASSERT_EQ(user.getUsername(), name);
}



