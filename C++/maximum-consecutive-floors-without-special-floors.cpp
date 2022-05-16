// Time:  O(nlogn)
// Space: O(1)

// sort
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(begin(special), end(special));
        int result = max(special[0] - bottom, top - special.back());
        for (int i = 1; i < size(special); ++i) {
            result = max(result, special[i] - special[i - 1] - 1);
        }
        return result;
    }
};
