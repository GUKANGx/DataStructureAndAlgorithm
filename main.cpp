#include "main.h"

class LeetCodeEnv : public testing::Test
{
public:
    static void SetUpTestSuite()
    {
        std::cout << "LeetCodeEnv SetUp." << std::endl;
    }

    static void TearDownTestSuite()
    {
        std::cout << "LeetCodeEnv TearDown." << std::endl;
    }
};

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
