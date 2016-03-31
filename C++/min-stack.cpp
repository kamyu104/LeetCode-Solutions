// Time:  O(n)
// Space: O(1)

class MinStack {
public:
    void push(int number) {
        if (elements_.empty()) {
            elements_.emplace(0);
            stack_min_ = number;
        } else {
            elements_.emplace(static_cast<int64_t>(number) - stack_min_);
            if (number < stack_min_) {
                stack_min_ = number; // Update min.
            }
        }
    }

    void pop() {
        auto diff = elements_.top();
        elements_.pop();
        if (diff < 0) {
            stack_min_ -= diff; // Restore previous min.
        }
    }

    int top() {
        if (elements_.top() > 0) {
            return stack_min_ + elements_.top();
        } else {
            return stack_min_;
        }
    }

    int getMin() {
        return stack_min_;
    }

private:
    stack<int64_t> elements_;
    int stack_min_;
};


// Time:  O(n)
// Space: O(n)
class MinStack2 {
public:
    void push(int number) {
        if (cached_min_with_count_.empty() || cached_min_with_count_.top().first > number) {
            cached_min_with_count_.emplace(number, 1);
        } else if (cached_min_with_count_.top().first == number) {
            ++cached_min_with_count_.top().second;
        }
        elements_.emplace(number);
    }

    void pop() {
        if (!elements_.empty()) {
            if (!cached_min_with_count_.empty() &&
                cached_min_with_count_.top().first == elements_.top()) {
                if (--cached_min_with_count_.top().second == 0) {
                    cached_min_with_count_.pop();
                }
            }
            auto number = elements_.top();
            elements_.pop();
        }
    }

    int top() {
        return elements_.top();
    }

    int getMin() {
        if (!cached_min_with_count_.empty()) {
            return cached_min_with_count_.top().first;
        }
    }

private:
    stack<int> elements_;
    stack<pair<int, int>> cached_min_with_count_;
};
