// Time:  O(n * l)
// Space: O(1)

// string
class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int result = 0;
        for (const auto& x : strs) {
            result = max(result, all_of(cbegin(x), cend(x), ::isdigit) ? stoi(x) : static_cast<int>(size(x)));
        }
        return result;
    }
};
