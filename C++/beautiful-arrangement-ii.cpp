// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        int left = 1, right = n;
        while (left <= right) {
            result.emplace_back(k % 2 ? left++ : right--);
            if (k > 1) {
                --k;
            }
        }
        return result;
    }
};
