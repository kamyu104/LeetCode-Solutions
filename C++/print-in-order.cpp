// Time:  O(n)
// Space: O(1)

class Foo {
public:
    Foo() {
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
