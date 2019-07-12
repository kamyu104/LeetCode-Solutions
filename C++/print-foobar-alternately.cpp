// Time:  O(n)
// Space: O(1)

class FooBar {
public:
    FooBar(int n) : n_(n) {
        m2_.lock();
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n_; ++i) {
            m1_.lock();
            // printFoo() outputs "foo". Do not change or remove this line.
        	  printFoo();
            m2_.unlock();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n_; ++i) {
            m2_.lock();
            // printBar() outputs "bar". Do not change or remove this line.
          	printBar();
            m1_.unlock();
        }
    }

private:
    int n_;
    mutex m1_, m2_;
};
