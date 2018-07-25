// Time:  O(1.199), counted by statistics, limit would be O(log10/log7) = O(1.183)
// Space: O(1)

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

// Reference: https://leetcode.com/problems/implement-rand10-using-rand7/discuss/151567/C++JavaPython-Average-1.199-Call-rand7-Per-rand10
class Solution {
public:
    int rand10() {
        while (cache_.empty()) {
            generate();
        }
        auto result = cache_.back(); cache_.pop_back();
        return result;
    }

private:
    void generate() {
        static const int n = 19;
        uint64_t curr = 0, range = static_cast<uint64_t>(pow(7, n));
        for (int i = 0; i < n; ++i) {
            curr += static_cast<uint64_t>(pow(7, i)) * (rand7() - 1);
        }
        while (curr < range / 10 * 10) {
            cache_.emplace_back(curr % 10 + 1);
            curr /= 10;
            range /= 10;
        }
    }
    vector<int> cache_;
};

// Time:  O(2 * (1 + (9/49) + (9/49)^2 + ...)) = O(2/(1-(9/49)) = O(2.45)
// Space: O(1)
class Solution2 {
public:
    int rand10() {
        while (true) {
            int x = (rand7() - 1) * 7 + (rand7() - 1);
            if (x < 40) {
                return x % 10 + 1;
            }
        }
    }
};
