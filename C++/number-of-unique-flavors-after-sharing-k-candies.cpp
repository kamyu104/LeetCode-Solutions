// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        unordered_map<int, int> cnt;
        int result = 0;
        for (int i = k; i < size(candies); ++i) {
            ++cnt[candies[i]];
        }
        int curr = result = size(cnt);
        for (int i = k; i < size(candies); ++i) {
            curr += (cnt[candies[i - k]]++ == 0) - (--cnt[candies[i]] == 0);
            result = max(result, curr);
        }
        return result;
    }
};
