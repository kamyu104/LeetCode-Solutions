// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        for (int i = size(pref) - 1; i >= 1; --i) {
            pref[i] ^= pref[i - 1];
        }
        return pref;
    }
};
