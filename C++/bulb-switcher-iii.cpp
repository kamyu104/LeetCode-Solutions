// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int result = 0, right = 0;
        for (int i = 0; i < light.size(); ++i) {
            right = max(right, light[i]);
            result += (i + 1 == right);
        }
        return result;
    }
};
