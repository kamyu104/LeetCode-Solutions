// Time:  O(n)
// Space: O(1)

class DiningPhilosophers {
public:
    DiningPhilosophers()
     : m_(5) {

    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        int left = philosopher, right = (philosopher + 4) % 5;
        int first = left, second = right;
        if (philosopher % 2) {
            swap(first, second);
        }

        unique_lock<mutex> lock1(m_[first]);
        unique_lock<mutex> lock2(m_[second]);
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }

private:
    vector<mutex> m_;
};
