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

TEST_F(RegisterFixture, userCreatingTest) {

    User user("username", getRegister());
    ASSERT_EQ(user.getUsername(), "username");
    ASSERT_EQ(UserList::getUserByName(user.getUsername()), user);
}

TEST_F(RegisterFixture, createChatTest) {
    firstTestUser->createChat(secondTestUser -> getUsername());
    ASSERT_EQ(getRegister() -> containsChatWithUsers(firstTestUser->getUsername(), secondTestUser->getUsername()), true);

}

