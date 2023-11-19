// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    long long minimumSteps(string s) {
        int64_t result = 0;
        for (int right = 0, left = 0; right < size(s); ++right) {
            if (s[right] != '0') {
                continue;
            }
            result += right - left++;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// two pointers
class Solution2 {
public:
    long long minimumSteps(string s) {
        int64_t result = 0;
        for (int left = 0, right = size(s) - 1; left < right;) {
            if (left < size(s) && s[left] != '1') {
                ++left;
                continue;
            }
            if (right >= 0 && s[right] != '0') {
                --right;
                continue;
            }
            result += right - left;
            ++left, --right;
        }
        return result;
    }
};
