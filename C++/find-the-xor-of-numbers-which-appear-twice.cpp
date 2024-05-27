// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int result = 0;
        unordered_set<int> lookup;
        for (const auto& x : nums) {
            result ^= x;
            if (lookup.count(x)) {
                continue;
            }
            lookup.emplace(x);
            result ^= x;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// freq table
class Solution2 {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        int result = 0;
        for (const auto& [x, c] : cnt) {
            if (c == 2) {
                result ^= x;
            }
        }
        return result;
    }
};
