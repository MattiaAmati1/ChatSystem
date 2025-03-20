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
    const std::string name = "testname";
    User user(name);


    c -> addMember(user); //elements are always added in the back
    ASSERT_EQ(c -> getMembersNumber(), 1); //tests if size has been increased
    ASSERT_EQ(c -> getUserList().last() -> getValue().getUsername(), name);

    c -> removeMember(user);
    ASSERT_EQ(c -> getMembersNumber(), 0);
    ASSERT_EQ(c -> getUserList().last(), nullptr);

}



