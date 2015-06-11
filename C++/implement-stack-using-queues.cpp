// Time:  push: O(n), pop: O(1), top: O(1)
// Space: O(n)

class Stack {
public:
    queue<int> q;
    
    // Push element x onto stack.
    void push(int x) {  // O(n)
        q.emplace(x);
        for (int i = 0; i < q.size() - 1; ++i) {
            q.emplace(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {  // O(1)
        q.pop();
    }

    // Get the top element.
    int top() {  // O(1)
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {  // O(1)
        return q.empty();
    }
};

// Time:  push: O(1), pop: O(n), top: O(n)
// Space: O(n)
class Stack2 {
public:
    queue<int> q, q2;
    
    // Push element x onto stack.
    void push(int x) {  // O(1)
        q.emplace(x);
    }

    // Removes the element on top of the stack.
    void pop() {  // O(n)
        for (int i = 0; i < q.size() - 1; ++i) {
            q.emplace(q.front());
            q.pop();
        }
        q.pop();
    }

    // Get the top element.
    int top() {  // O(n)
        for (int i = 0; i < q.size() - 1; ++i) {
            q.emplace(q.front());
            q.pop();
        }
        int top = q.front();
        q.emplace(q.front());
        q.pop();
        return top;
    }

    // Return whether the stack is empty.
    bool empty() {  // O(1)
        return q.empty();
    }
};
