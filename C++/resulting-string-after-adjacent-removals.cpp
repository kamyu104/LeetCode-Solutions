// Time:  O(n)
// Space: O(1)

// simulation, stack
class Solution {
public:
    string resultingString(string s) {
        string result;
        for (const auto& x : s) {
            if (!empty(result)) {
                const int diff = abs(x - result.back());
                if (diff == 1 || diff == 25) {
                    result.pop_back();
                    continue;
                }
            }
            result.push_back(x);
        }
        return result;
    }
};
