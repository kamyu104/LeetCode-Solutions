// Time:  O(n)
// Space: O(1)

class Foo {
public:
    Foo() {
        m2_.lock();
        m3_.lock();
    }

    void first(function<void()> printFirst) {
        m1_.lock();
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m2_.unlock();
    }

    void second(function<void()> printSecond) {
        m2_.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m3_.unlock();
    }

    void third(function<void()> printThird) {
        m3_.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        m1_.unlock();
    }

private:
    mutex m1_, m2_, m3_;
};
