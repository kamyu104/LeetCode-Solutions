// Time:  O(n)
// Space: O(1)

class Foo {
public:
    Foo() {
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        p1_.set_value();
    }

    void second(function<void()> printSecond) {
        p1_.get_future().wait();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        p2_.set_value();
    }

    void third(function<void()> printThird) {
        p2_.get_future().wait();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    promise<void> p1_;
    promise<void> p2_;
};

// Time:  O(n)
// Space: O(1)
class Foo2 {
public:
    Foo2() {
    }

    void first(function<void()> printFirst) {
        {
            unique_lock<mutex> l(m_);
            has_first_ = true;
            // printFirst() outputs "first". Do not change or remove this line.
            printFirst();
        }
        cv_.notify_all();
    }

    void second(function<void()> printSecond) {
        {
            unique_lock<mutex> l(m_);
            cv_.wait(l, [this]() { return has_first_; });
            has_second_ = true;
            // printSecond() outputs "second". Do not change or remove this line.
            printSecond();
        }
        cv_.notify_all();
    }

    void third(function<void()> printThird) {
        {
            unique_lock<mutex> l(m_);
            cv_.wait(l, [this]() { return has_second_; });
            // printThird() outputs "third". Do not change or remove this line.
            printThird();
        }
        cv_.notify_all();
    }

private:
    bool has_first_ = false;
    bool has_second_ = false;
    mutex m_;
    condition_variable cv_;
};

// Time:  O(n)
// Space: O(1)
class Foo3 {
public:
    Foo3() {
        m1_.lock();
        m2_.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m1_.unlock();
    }

    void second(function<void()> printSecond) {
        m1_.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m1_.unlock();
        m2_.unlock();
    }

    void third(function<void()> printThird) {
        m2_.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        m2_.unlock();
    }

private:
    mutex m1_, m2_;
};
