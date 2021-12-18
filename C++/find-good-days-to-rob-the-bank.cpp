// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> right = {0};
        for (int i = size(security) - 1; i >= 1; --i) {
            right.emplace_back(security[i] >= security[i - 1] ? right.back() + 1 : 0);
        }
        reverse(begin(right), end(right));
        vector<int> result;
        for (int i = 0, left = 0; i < size(security); ++i) {
            if (left >= time && right[i] >= time) {
                result.emplace_back(i);
            }
            if (i + 1 < size(security)) {
                left = (security[i] >= security[i + 1]) ? left + 1 : 0;
            }
        }
        return result;
    }
};
