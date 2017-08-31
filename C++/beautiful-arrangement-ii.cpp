// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        int left = 1, right = n;
        while (left <= right) {
            if (k > 1) {
                result.emplace_back(k-- % 2 ? left++ : right--);
            }
            else {
                result.emplace_back(k % 2 ? left++ : right--);
            }
        }
        return result;
    }
};
