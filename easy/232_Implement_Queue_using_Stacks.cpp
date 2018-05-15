#include "../libstruct.h"

using namespace std;

/*
 * NO.232
 * Implement the following operations of a queue using stacks.
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 */

class MyQueue {
public:
    stack<int> s1, s2;
    
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int h = peek();
        s2.pop();
        return h;
    }
    
    /** Get the front element. */
    int peek() {
        if (s2.empty()) {
            while(!s1.empty()) {
                int t = s1.top();
                s2.push(t);
                s1.pop();
            }
        }
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
