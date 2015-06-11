// Time:  push: O(n), pop: O(1), top: O(1)
// Space: O(n)

class Stack {
public:
    queue<int> q;
    
    // Push element x onto stack.
    void push(int x) {
        int n = q.size();
        q.emplace(x);
        for (; n > 0; --n) {
            q.emplace(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};
