// Time:  O(1), amortized
// Space: O(n)

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        A_.emplace(x);
    }

    int pop(void) {
        peek();
        int result = B_.top();
        B_.pop();
        return result;
    }

    int peek(void) {
        if (B_.empty()) {
          // Transfers the elements in A_ to B_.
          while (!A_.empty()) {
            B_.emplace(A_.top());
            A_.pop();
          }
        }
        if (B_.empty()) {  // B_ is still empty!
          throw length_error("empty queue");
        }
        return B_.top();
    }

    bool empty(void) {
        return A_.empty() && B_.empty();
    }

 private:
    stack<int> A_, B_;
};
