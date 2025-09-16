// Time:  O(n)
// Space: O(w)

// freq table, two pointers, sliding window
class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int result = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < size(arrivals); ++i) {
            ++cnt[arrivals[i]];
            if (cnt[arrivals[i]] == m + 1) {
                --cnt[arrivals[i]];
                arrivals[i] = 0;
                ++result;
            }
            if (i - w + 1 >= 0) {
                if (arrivals[i - w + 1]) {
                    if (--cnt[arrivals[i - w + 1]] == 0) {
                        cnt.erase(arrivals[i - w + 1]);
                    }
                }
            }
        }
        return result;
    }
};
