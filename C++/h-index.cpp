// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int h = 0;
        for (const auto& x : citations) {
            if (x >= h + 1) {
                ++h;
            } else {
                break;
            }
        }
        return h;
    }
};
