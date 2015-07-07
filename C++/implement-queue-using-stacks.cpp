// Time:  O(1), amortized
// Space: O(n)

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        A_.emplace(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        peek();
        B_.pop();
    }

    // Get the front element.
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

    // Return whether the queue is empty.
    bool empty(void) {
        return A_.empty() && B_.empty();
    }

 private:
  stack<int> A_, B_;
};
