#include "main.h"

using namespace std;

namespace {
    class MyQueue {
    public:
        MyQueue()
        {

        }

        void push(int x)
        {
            s.push_back(x);
        }

        int pop()
        {
            int ret = s.front();
            s.erase(s.begin());
            return ret;
        }

        int peek()
        {
            return s.front();
        }

        bool empty()
        {
            return s.empty();
        }
    private:
        vector<int> s;
    };
};

TEST(LeetCodeEnv, Q232_1)
{
    MyQueue myQueue;

}