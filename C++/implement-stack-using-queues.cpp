// Time:  push: O(n), pop: O(1), top: O(1)
// Space: O(n)

class Stack {
public:
    queue<int> q_;
    
    // Push element x onto stack.
    void push(int x) {  // O(n)
        q_.emplace(x);
        for (int i = 0; i < q_.size() - 1; ++i) {
            q_.emplace(q_.front());
            q_.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {  // O(1)
        q_.pop();
    }

    // Get the top element.
    int top() {  // O(1)
        return q_.front();
    }

    // Return whether the stack is empty.
    bool empty() {  // O(1)
        return q_.empty();
    }
};

// Time:  push: O(1), pop: O(n), top: O(1)
// Space: O(n)
class Stack2 {
public:
    queue<int> q_;
    int top_;
    
    // Push element x onto stack.
    void push(int x) {  // O(1)
        q_.emplace(x);
        top_ = x;
    }

    // Removes the element on top of the stack.
    void pop() {  // O(n)
        for (int i = 0; i < q_.size() - 1; ++i) {
            top_ = q_.front();
            q_.emplace(top_);
            q_.pop();
        }
        q_.pop();
    }

    // Get the top element.
    int top() {  // O(1)
        return top_;
    }

    // Return whether the stack is empty.
    bool empty() {  // O(1)
        return q_.empty();
    }
};

