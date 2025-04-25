#include "gtest/gtest.h"
#include "../User.h"

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

        ChatRegister* getRegister() { return &reg; }

    private:
        ChatRegister reg;
};


TEST_F(RegisterFixture, createChatTest) {

    firstTestUser->createChat(secondTestUser -> getUsername(), "testChat");
    ASSERT_EQ(getRegister() -> containsChatWithUsers(firstTestUser->getUsername(), secondTestUser->getUsername()), true);
    ASSERT_EQ(getRegister() -> getChatWithUsers(firstTestUser->getUsername(), secondTestUser->getUsername()).getName(), "testChat");
}

TEST_F(RegisterFixture, messageSendingTest) {

    firstTestUser -> createChat(secondTestUser -> getUsername());
    const std::string textMessage = "Test Message";
    const Message msg(firstTestUser -> getUsername(), textMessage);
    firstTestUser -> sendMessage(secondTestUser -> getUsername(), msg);

    //the test message has just been sent, it is the last in the chatMessages vector
    Chat& tmp = getRegister() -> getChatWithUsers(firstTestUser -> getUsername(), secondTestUser -> getUsername());
    ASSERT_EQ(tmp.getMessageAtPosition(tmp.getMessagesAmount() - 1), msg);

    firstTestUser -> sendMessage(secondTestUser -> getUsername(), "Second Message");
    ASSERT_EQ(tmp.getMessageAtPosition(tmp.getMessagesAmount() - 1).getText(), "Second Message");
    ASSERT_EQ(tmp.getUnreadMessagesAmount(), 2);
    ASSERT_EQ(tmp.getMessagesAmount(), 2);
}

TEST_F(RegisterFixture, messageReadingTest) {

    firstTestUser -> createChat(secondTestUser -> getUsername());
    const Message msg(firstTestUser -> getUsername(), "Test Message");
    firstTestUser -> sendMessage(secondTestUser -> getUsername(), msg);

    ASSERT_EQ(secondTestUser -> readUnreadMessage(firstTestUser -> getUsername(), 0), msg.toString());
    Chat& tmp = getRegister() -> getChatWithUsers(firstTestUser -> getUsername(), secondTestUser -> getUsername());
    ASSERT_EQ(tmp.getMessageAtPosition(tmp.getMessagesAmount() - 1).isRead(), true);

    secondTestUser -> setMessageToUnread(firstTestUser -> getUsername(), 0);
    ASSERT_EQ(tmp.getMessageAtPosition(tmp.getMessagesAmount() - 1).isRead(), false);

    ASSERT_EQ(secondTestUser -> readUnreadMessagesWithWord(firstTestUser -> getUsername(), "Test"), msg.toString() + "\n");
}


