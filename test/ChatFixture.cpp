#include "gtest/gtest.h"
#include "../Chat.h"

class ChatSuite : public testing::Test {
    protected:
        virtual void SetUp(){
            User user1("firstuser");
            User user2("seconduser");

            c -> addMember(user1);
            c -> addMember(user2);

        }
        Chat* c = nullptr;
};

TEST_F(ChatSuite, TestAddRemove){

    User testuser("test");
    c -> addMember(testuser);
    ASSERT_EQ(c -> getMembersNumber(), 3);

}



