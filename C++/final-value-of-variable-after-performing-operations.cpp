// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int result = 0;
        for (const auto& op : operations) {
            if (op[1] == '+') {
                ++result;
            } else {
                --result;
            }
        }
        return result;
    }
};
