#include "../libstruct.h"

using namespace std;

/*
 * NO.225
 * Implement the following operations of a stack using queues.

 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 */

class MyStack {
public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t, s = q.size();
        for (int i = 0; i < s - 1; i++) {
            t = q.front();
            q.pop();
            q.push(t);
        }
        t = q.front();
        q.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        int t = pop();
        q.push(t);
        return t;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
