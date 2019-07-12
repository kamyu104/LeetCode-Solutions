// Time:  O(n)
// Space: O(1)

class ZeroEvenOdd {
public:
    ZeroEvenOdd(int n)
      : n_(n)
      , curr_(0)
    {
        m2_.lock();
        m3_.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n_; ++i) {
            m1_.lock();
            printNumber(0);
            if (++curr_ % 2) {
                m2_.unlock();
            } else {
                m3_.unlock();
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 0; i < n_ / 2; ++i) {
            m3_.lock();
            printNumber(curr_);
            m1_.unlock();
        } 
    }

    void odd(function<void(int)> printNumber) {
         for (int i = 0; i < (n_ + 1) / 2; ++i) {
            m2_.lock();
            printNumber(curr_);
            m1_.unlock();
        } 
    }

private:
    int n_;
    int curr_;
    mutex m1_, m2_, m3_;
};
