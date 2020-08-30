// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int cnt = 0;
        for (int i = 0; i + m < arr.size(); ++i) {
            if (arr[i] != arr[i + m]) {
                cnt = 0;  
                continue;
            }
            if (++cnt == (k - 1) * m) {
                return true;
            }
        }
        return false;
    }
};
