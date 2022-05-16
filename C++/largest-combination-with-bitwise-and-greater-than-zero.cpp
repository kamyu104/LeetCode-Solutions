// Time:  O(nlogr), r is the max of candidates
// Space: O(logr)

// bit manipulation, freq table
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> cnt;
        const int mx = *max_element(cbegin(candidates), cend(candidates));
        for (int base = 1; base <= mx; base <<= 1) {
            cnt.emplace_back();
            for (const auto& x : candidates) {
                if (x & base) {
                    ++cnt.back();
                }
            }
        }
        return *max_element(cbegin(cnt), cend(cnt));
    }
};
