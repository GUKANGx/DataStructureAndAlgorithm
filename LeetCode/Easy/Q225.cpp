#include "main.h"

using namespace std;

namespace {
    class MyStack {
    public:
        MyStack()
        {

        }

        void push(int x)
        {
            q.push_back(x);
        }

        int pop()
        {
            int ret = q.back();
            q.pop_back();
            return ret;
        }

        int top()
        {
            return q.back();
        }

        bool empty()
        {
            return q.empty();
        }
    private:
        deque<int> q;
    };

};

TEST(LeetCodeEnv, Q225_1)
{
    MyStack myStack;

}