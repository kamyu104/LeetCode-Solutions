// Time:  O(nlog(logm)), n the length of nums, m is the max value of nums
// Space: O(logm)

class Solution {
public:
    Solution() {
        static const int M = 1e5;
        lookup_.emplace_back(0);
        int i = 10;
        for (; i < M; i *= 10) {
            lookup_.emplace_back(i);
        }
        lookup_.emplace_back(i);
    }

    int findNumbers(vector<int>& nums) {
        return accumulate(nums.cbegin(), nums.cend(), 0,
                          [this](const auto& x, const auto& y) {
                              return x + int(digit_count(y) % 2 == 0);
                          });
    }

private:
    int digit_count(int n) {
        return distance(lookup_.cbegin(),
                        upper_bound(lookup_.cbegin(), lookup_.cend(), n));
    }
    
    vector<int> lookup_;
};

// Time:  O(nlogm), n the length of nums, m is the max value of nums
// Space: O(logm)
class Solution2 {
public:
    int findNumbers(vector<int>& nums) {
        return accumulate(nums.cbegin(), nums.cend(), 0,
                          [this](const auto& x, const auto& y) {
                              return x + int(digit_count(y) % 2 == 0);
                          });
    }

private:
    int digit_count(int n) {
        int result = 0;
        for (; n; n /= 10, ++result);
        return result;
    }
};

// Time:  O(nlogm), n the length of nums, m is the max value of nums
// Space: O(logm)
class Solution3 {
public:
    int findNumbers(vector<int>& nums) {
        return accumulate(nums.cbegin(), nums.cend(), 0,
                          [](const auto& x, const auto& y) {
                              return x + int(to_string(y).length() % 2 == 0);
                          });
    }
};
