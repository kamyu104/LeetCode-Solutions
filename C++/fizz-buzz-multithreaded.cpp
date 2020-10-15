// Time:  O(n)
// Space: O(1)

class FizzBuzz {
public:
    FizzBuzz(int n) : n_(n) {
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for (int i = 1; i <= n_; ++i) {
            {
                unique_lock<mutex> l(m_);
                cv_.wait(l, [this]() { return curr_ % 4 == 0; });
                ++curr_;
                if (i % 3 == 0 && i % 5 != 0) {
                    printFizz();
                }
            }
            cv_.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (int i = 1; i <= n_; ++i) {
            {
                unique_lock<mutex> l(m_);
                cv_.wait(l, [this]() { return curr_ % 4 == 1; });
                ++curr_;
                if (i % 3 != 0 && i % 5 == 0) {
                    printBuzz();
                }
            }
            cv_.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        for (int i = 1; i <= n_; ++i) {
            {
                unique_lock<mutex> l(m_);
                cv_.wait(l, [this]() { return curr_ % 4 == 2; });
                ++curr_;
                if (i % 3 == 0 && i % 5 == 0) {
                    printFizzBuzz();
                }
            }
            cv_.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (int i = 1; i <= n_; ++i) {
            {
                unique_lock<mutex> l(m_);
                cv_.wait(l, [this]() { return curr_ % 4 == 3; });
                ++curr_;
                if (i % 3 != 0 && i % 5 != 0) {
                    printNumber(i);
                }
            }
            cv_.notify_all();
        }
    }

private:
    int n_;
    int curr_ = 0;
    mutex m_;
    condition_variable cv_;
};
