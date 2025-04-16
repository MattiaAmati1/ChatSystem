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


