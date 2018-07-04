#include "../libstruct.h"

using namespace std;

/*
 * NO.155
 * Design a stack that supports push, pop, top, and retrieving the minimum 
 * element in constant time.
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if (min.empty() || x <= min.top())
            min.push(x);
    }
    
    void pop() {
        if (!st.empty())
        {
            if (min.top() == st.top())
                min.pop();
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
    
    stack<int> min, st;
};