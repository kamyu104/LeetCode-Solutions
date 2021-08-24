// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result;
        for (int i = 0; i < size(nums); ++i) {
            result.push_back((nums[i][i] == '0') ? '1' : '0');
        }
        return result;
    }
};

// Time:  O(k * n) = O(n^2), k is len(nums)
//                         , n is len(nums[0])
// Space: O(k) = O(n)
class Solution2 {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        const int n = size(nums[0]);
        unordered_set<int> lookup;
        for (const auto& x : nums) {  // Time: O(k * n) = O(n^2)
            lookup.emplace(to_decimal(x));
        }
        const int total = 1 << n;
        for (int i = 0; i < total; ++i) {  // Time: O(k + n) = O(n)
            if (!lookup.count(i)) {
                return to_binary(i, n);
            }
        }
        return "";
    }

private:
    int to_decimal(const string& num) {  // Time: O(n)
        return accumulate(cbegin(num), cend(num), 0,
                          [](const auto& total, const auto& x) {
                              return total * 2 + (x - '0');
                          });
    }
    
    string to_binary(int num, int n) {  // Time: O(n)
        string result;
        for (int basis = 1 << (n - 1); basis; basis >>= 1) {
            result.push_back((num & basis) ? '1' : '0');
        }
        return result;
    }
};

// Time:  O(k * n + n * 2^n) = O(n * 2^n), k is len(nums)
//                                       , n is len(nums[0])
// Space: O(k) = O(1) ~ O(2^n)
class Solution_Extra {
public:
    vector<string> findAllDifferentBinaryStrings(vector<string>& nums) {
        const int n = size(nums[0]);
        unordered_set<int> lookup;
        for (const auto& x : nums) {  // Time: O(k * n) = O(n * 2^n)
            lookup.emplace(to_decimal(x));
        }
        vector<string> result;
        const int total = 1 << n;
        for (int i = 0; i < total; ++i) {  // Time: O(2^n + n * (2^n - k))
            if (!lookup.count(i)) {
                result.emplace_back(to_binary(i, n));
            }
        }
        return result;
    }

private:
    int to_decimal(const string& num) {  // Time: O(n)
        return accumulate(cbegin(num), cend(num), 0,
                          [](const auto& total, const auto& x) {
                              return total * 2 + (x - '0');
                          });
    }
    
    string to_binary(int num, int n) {  // Time: O(n)
        string result;
        for (int basis = 1 << (n - 1); basis; basis >>= 1) {
            result.push_back((num & basis) ? '1' : '0');
        }
        return result;
    }
};
