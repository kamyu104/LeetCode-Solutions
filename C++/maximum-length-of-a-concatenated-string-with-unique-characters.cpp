// Time:  O(n) ~ O(2^n)
// Space: O(1) ~ O(2^n)

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> dp(1);
        for (const auto& x : arr) {
            const auto& x_set = bitset(x);
            if (!x_set) {
                continue;
            }
            const auto curr_size = dp.size();
            for (int i = 0; i < curr_size; ++i) {
                if (dp[i] & x_set) {
                    continue;
                }
                dp.emplace_back(dp[i] | x_set);
            }
        }
        return number_of_one(*max_element(dp.cbegin(), dp.cend(),
                                          [&](const auto& lhs, const auto& rhs) {
                                              return number_of_one(lhs) < number_of_one(rhs);
                                          }));
    }

private:
    int bitset(const string& s) {
        int result = 0;
        for (const auto& c : s) {
            if (result & (1 << (c - 'a'))) {
                return 0;
            }
            result |= 1 << (c - 'a');
        }
        return result;
    }
    
    int number_of_one(int n) {
    	int count = 0;
        for (; n; n &= n - 1) {
            ++count;
        }
        return count;
    }
};

// Time:  O(2^n)
// Space: O(1)
class Solution2 {
public:
    int maxLength(vector<string>& arr) {
        vector<int> bitsets;
        for (const auto& x : arr) {
            bitsets.emplace_back(bitset(x));
        }
        int result = 0;
        for (int i = 0; i < (1 << arr.size()); ++i) {
            bool skip = false;
            int curr_bitset = 0, curr_len = 0;
            for (int j = 0; j < arr.size(); ++j) {
                if (!(i & (1 << j))) {
                    continue;
                }
                if (!bitsets[j] || (curr_bitset & bitsets[j])) {
                    skip = true;
                    break;
                }
                curr_bitset |= bitsets[j];
                curr_len += arr[j].length();
            }
            if (skip) {
                continue;
            }
            result = max(result, curr_len);
        }
        return result;
    }

private:
    int bitset(const string& s) {
        int result = 0;
        for (const auto& c : s) {
            if (result & (1 << (c - 'a'))) {
                return 0;
            }
            result |= 1 << (c - 'a');
        }
        return result;
    }
};
