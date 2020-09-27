// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int result = 0;
        for (const auto& log: logs) {
            if (log == "../") {
                if (result > 0) {
                    --result;
                }
            } else if (log != "./") {
                ++result;
            }
        }
        return result;
    }
};
