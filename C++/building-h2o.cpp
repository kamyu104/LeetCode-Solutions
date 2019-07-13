// Time:  O(n)
// Space: O(1)

class H2O {
public:        
    H2O() {
    }

    void hydrogen(function<void()> releaseHydrogen) {
        {
            unique_lock l(m_);
            if (nH_ == 2) {
                waitH.wait(l, [this]{ return nH_ != 2; });
            }
            ++nH_;
            releaseHydrogen();
        }
        consume();
    }

    void oxygen(function<void()> releaseOxygen) {
        {
            unique_lock l(m_);
            if (nO_ == 1) {
                waitO.wait(l, [this]{ return nO_ != 1; });
            }
            ++nO_;
            releaseOxygen();
        }
        consume();
    }

private:
    void consume() {
        unique_lock l(m_);
        if (nH_ == 2 && nO_ == 1) {
            nH_ = nO_ = 0;
            l.unlock();
            waitH.notify_one();
            waitO.notify_one();
        }
    }

    int nH_, nO_;
    mutex m_;
    condition_variable waitH, waitO;
};

// Time:  O(n)
// Space: O(1)
// this is much like single thread execution
class H2O2 {
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
