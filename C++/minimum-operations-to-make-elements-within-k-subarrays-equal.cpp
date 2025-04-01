// Time:  O(nlogx + k * n)
// Space: O(n)

// two bsts, dp
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        static const int64_t INF = numeric_limits<int64_t>::max();

        Slidingsw sw;
        vector<int64_t> cost(size(nums) + 1, INF);
        for (int i = 0; i < size(nums); ++i) {
            if (i - x >= 0) {
                sw.remove(nums[i - x]);
            }
            sw.add(nums[i]);
            if (i >= x - 1) {
                cost[i + 1] = (sw.median() * size(sw.left) - sw.total1) + (sw.total2 - sw.median() * size(sw.right));
            }
        }
        vector<int64_t> dp(size(nums) + 1);
        for (int i = 0; i < k; ++i) {
            vector<int64_t> new_dp(size(nums) + 1, INF);
            for (int j = (i + 1) * x; j <= size(nums); ++j) {
                if (dp[j - x] != INF) {
                    new_dp[j] = min(new_dp[j - 1], dp[j - x] + cost[j]);
                }
            }
            dp = move(new_dp);
        }
        return dp.back();
    }

private:
    struct Slidingsw {
        Slidingsw() {

        }

        void add(int val) {
            if (empty(left) || val <= *begin(left)) {
                left.emplace(val);
                total1 += val;
            } else {
                right.emplace(val);
                total2 += val;
            }
            rebalance();
        }

        void remove(int val) {
            if (val <= *begin(left)) {
                left.erase(left.find(val));
                total1 -= val;
            } else {
                right.erase(right.find(val));
                total2 -= val;
            }
            rebalance();
        }

        void rebalance() {
            if (size(left) < size(right)) {
                total2 -= *begin(right);
                total1 += *begin(right);
                left.emplace(*begin(right));
                right.erase(begin(right));
            } else if (size(left) > size(right) + 1) {
                total1 -= *begin(left);
                total2 += *begin(left);
                right.emplace(*begin(left));
                left.erase(begin(left));
            }
        }

        int median() {
            return *begin(left);
        }

        multiset<int, greater<int>> left;
        multiset<int, less<int>> right;
        int64_t total1 = 0;
        int64_t total2 = 0;
    };
};

// Time:  O(nlogx + k * n)
// Space: O(n)
// two heaps, dp
class Solution2 {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        static const int64_t INF = numeric_limits<int64_t>::max();

        Slidingsw sw;
        vector<int64_t> cost(size(nums) + 1, INF);
        for (int i = 0; i < size(nums); ++i) {
            if (i - x >= 0) {
                sw.remove(nums[i - x]);
            }
            sw.add(nums[i]);
            if (i >= x - 1) {
                cost[i + 1] = (sw.median() * sw.left.size() - sw.total1) + (sw.total2 - sw.median() * sw.right.size());
            }
        }
        vector<int64_t> dp(size(nums) + 1);
        for (int i = 0; i < k; ++i) {
            vector<int64_t> new_dp(size(nums) + 1, INF);
            for (int j = (i + 1) * x; j <= size(nums); ++j) {
                if (dp[j - x] != INF) {
                    new_dp[j] = min(new_dp[j - 1], dp[j - x] + cost[j]);
                }
            }
            dp = move(new_dp);
        }
        return dp.back();
    }

private:
    template<typename T>
    struct LazyHeap {
        LazyHeap() {

        }

        void push(int val) {
            heap.emplace(val);
        }

        void full_remove() {
            priority_queue<int, vector<int>, T> new_heap;
            while (!heap.empty()) {
                const auto x = heap.top(); heap.pop();
                if (!to_remove.empty() && x == to_remove.top()) {
                    to_remove.pop();
                } else {
                    new_heap.emplace(x);
                }
            }
            heap = move(new_heap);
        }

        void remove(int val) {
            to_remove.emplace(val);
            if (to_remove.size() > heap.size() - to_remove.size()) {
                full_remove();
            }
        }

        void pop() {
            remove(top());
        }

        int top() {
            while (!heap.empty() && !to_remove.empty() && heap.top() == to_remove.top()) {
                heap.pop();
                to_remove.pop();
            }
            return heap.top();
        }

        int64_t size() {
            return heap.size() - to_remove.size();
        }

        bool empty() {
            return size() == 0;
        }

        priority_queue<int, vector<int>, T> heap, to_remove;
    };

    struct Slidingsw {
        Slidingsw() {

        }

        void add(int val) {
            if (left.empty() || val <= left.top()) {
                left.push(val);
                total1 += val;
            } else {
                right.push(val);
                total2 += val;
            }
            rebalance();
        }

        void remove(int val) {
            if (val <= left.top()) {
                left.remove(val);
                total1 -= val;
            } else {
                right.remove(val);
                total2 -= val;
            }
            rebalance();
        }

        void rebalance() {
            if (left.size() < right.size()) {
                total2 -= right.top();
                total1 += right.top();
                left.push(right.top());
                right.pop();
            } else if (left.size() > right.size() + 1) {
                total1 -= left.top();
                total2 += left.top();
                right.push(left.top());
                left.pop();
            }
        }

        int median() {
            return left.top();
        }

        LazyHeap<less<int>> left;
        LazyHeap<greater<int>> right;
        int64_t total1 = 0;
        int64_t total2 = 0;
    };
};
