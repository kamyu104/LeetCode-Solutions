// Time:  O(n)
// Space: O(1)

class H2O {
public:        
    H2O() {
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> l(m_);
        releaseHydrogen_ = releaseHydrogen;
        ++nH_;
        output();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> l(m_);
        releaseOxygen_ = releaseOxygen;
        ++nO_;
        output();
    }

private:
    void output() {
        while (nH_ >= 2 && nO_ >= 1) {
            nH_ -= 2;
            nO_ -= 1;
            releaseHydrogen_();
            releaseHydrogen_();
            releaseOxygen_();
        }
    }

    int nH_ = 0;
    int nO_ = 0;
    function<void()> releaseHydrogen_ = nullptr;
    function<void()> releaseOxygen_ = nullptr;
    mutex m_;
};

// Time:  O(n)
// Space: O(1)
class H2O2 {
public:        
    H2O2() {
    }

    void hydrogen(function<void()> releaseHydrogen) {
        {
            unique_lock<mutex> l(m_);
            cv_.wait(l, [this]() { return (nH_ + 1) - 2 * nO_ <= 2; });
            ++nH_;
            // releaseHydrogen() outputs "H". Do not change or remove this line.
            releaseHydrogen();
        }
        cv_.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        {
            unique_lock<mutex> l(m_);
            cv_.wait(l, [this]() { return 2 * (nO_ + 1) - nH_ <= 2; });
            ++nO_;
            // releaseOxygen() outputs "O". Do not change or remove this line.
            releaseOxygen();
        }
        cv_.notify_all();
    }

private:
    int nH_ = 0;
    int nO_ = 0;
    mutex m_;
    condition_variable cv_;
};

// Time:  O(n)
// Space: O(1)
// this is much like single thread execution
class H2O3 {
public:
    H2O3(): curr_(2) {
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
    int curr_ = 0;
    mutex m1_, m2_;
};
