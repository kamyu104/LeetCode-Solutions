// Time:  O(n)
// Space: O(1)

// freq table
class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int> result(2);
        for (const auto& x : events) {
            if (x == "W") {
                if (++result[1] == 10) {
                    break;
                }
            } else if (x == "WD" || x == "NB") {
                ++result[0];
            } else {
                result[0] += x[0] - '0';
            }
        }
        return result;
    }
};
