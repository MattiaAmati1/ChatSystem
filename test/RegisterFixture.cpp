#include "gtest/gtest.h"
#include "../ChatRegister.h"

class RegisterFixture : public ::testing::Test {
    public:
        void SetUp() override {
            firstTestUser = new User("firstTestUser", &reg);
            secondTestUser = new User("secondTestUser", &reg);
        }

        void TearDown() override {
            delete firstTestUser;
            delete secondTestUser;
        }

        User *firstTestUser = nullptr;
        User *secondTestUser = nullptr;

        ChatRegister getRegister() { return reg; }
    private:
        ChatRegister reg;
};


TEST_F(RegisterFixture, CreateChatTest) {

    getRegister().getChatList().clear();
    firstTestUser -> createChat(secondTestUser, 1);
    ASSERT_EQ(getRegister().getChatList().front() -> getID() , 1);
}

TEST_F(RegisterFixture, SendMessageTest) {

    getRegister().getChatList().clear();
    firstTestUser -> createChat(secondTestUser, 2);
    const Message msg("testMessage", firstTestUser -> getUsername());
    firstTestUser -> sendMessage(secondTestUser, msg);
    ASSERT_EQ(getRegister().getChatList().front() -> getLatestMessage(), msg);
    ASSERT_EQ(secondTestUser -> getUnreadMessages(), 1);
}

TEST_F(RegisterFixture, ViewUnreadMessageTest){
    getRegister().getChatList().clear();
    firstTestUser -> createChat(secondTestUser, 2);
    const Message msg("testMessage", firstTestUser -> getUsername());
    firstTestUser -> sendMessage(secondTestUser, msg);
    secondTestUser -> showUnreadMessages(); //should read all unread messages
    ASSERT_EQ(secondTestUser -> getUnreadMessages(), 0);
}