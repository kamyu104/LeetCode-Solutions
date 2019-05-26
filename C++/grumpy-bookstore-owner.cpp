// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int result = 0, max_extra = 0, extra = 0;
        for (int i = 0; i < customers.size(); ++i) {
            result += grumpy[i] ? 0 : customers[i];
            extra += grumpy[i] ? customers[i] : 0;
            if (i >= X) {
                extra -= grumpy[i - X] ? customers[i - X] : 0;
            }
            max_extra = max(max_extra, extra);
        }
        return result + max_extra;
    }
};
