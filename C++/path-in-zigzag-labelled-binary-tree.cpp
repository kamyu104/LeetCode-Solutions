// Time:  O(logn)
// Space: O(logn)

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int count = 1;
        while (count <= label) {
          count *= 2;
        }
        vector<int> result;
        for (; label >= 1; label /= 2, count /= 2) {
            result.emplace_back(label);
            label = (count / 2) + ((count - 1) - label);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
