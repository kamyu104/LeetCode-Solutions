// Time:  O(n + 24)
// Space: O(24)

// freq table
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int result = 0;
        vector<int> cnt(24);
        for (const auto& x : hours) {
            result += cnt[((-x % 24) + 24) % 24];
            ++cnt[x % 24];
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(1)
// brute force
class Solution2 {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int result = 0;
        for (int i = 0; i + 1 < size(hours); ++i) {
            for (int j = i + 1; j < size(hours); ++j) {
                if ((hours[i] + hours[j]) % 24 == 0) {
                    ++result;
                }
            }
        }
        return result;
    }
};
