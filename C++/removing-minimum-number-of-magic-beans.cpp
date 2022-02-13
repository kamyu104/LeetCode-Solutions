// Time:  O(nlogn)
// Space: O(1)

// math
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(begin(beans), end(beans));
        int64_t result = 0;
        for (int i = 0; i < size(beans); ++i) {
            result = max(result, beans[i] * (static_cast<int64_t>(size(beans)) - i));
        }
        return accumulate(cbegin(beans), cend(beans), 0ll) - result;
    }
};
