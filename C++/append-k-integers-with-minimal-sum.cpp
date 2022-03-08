// Time:  O(nlogn)
// Space: O(n)

// greedy
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        int64_t result = static_cast<int64_t>(k) * (k + 1) / 2, curr = k + 1;
        for (const auto& x : set<int>(cbegin(nums), cend(nums))) {
            if (x < curr) {
                result += curr++ - x;
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// greedy
class Solution2 {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        int64_t result = 0, prev = 0;
        nums.emplace_back(numeric_limits<int>::max());
        for (const auto& x : set<int>(cbegin(nums), cend(nums))) {
            if (!k) {
                break;
            }
            const int cnt = min((x - 1) - prev, static_cast<int64_t>(k));
            k -= cnt;
            result += ((prev + 1) + (prev + cnt)) * cnt / 2;
            prev = x;
        }
        return result;
    }
};
