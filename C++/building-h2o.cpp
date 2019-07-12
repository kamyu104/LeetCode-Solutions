// Time:  O(n)
// Space: O(1)

class H2O {
public:
    H2O(): curr_(2) {
        m2_.lock();
    }

    void hydrogen(function<void()> releaseHydrogen) {
        m1_.lock();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        if (--curr_) {
            m1_.unlock();
        } else {
            m2_.unlock();
        }
    }
    
    void oxygen(function<void()> releaseOxygen) {
        m2_.lock();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        curr_ = 2;
        m1_.unlock();
    }

private:
    int curr_;
    mutex m1_, m2_;
};
