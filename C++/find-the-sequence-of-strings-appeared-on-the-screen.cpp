// Time:  O(n^2)
// Space: O(1)

// string
class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> result;
        for (const auto& x : target) {
            const int i = size(result) - 1;
            for (char c = 'a'; c <= x; ++c) {
                result.emplace_back(i != -1 ? result[i] : "");
                result.back().push_back(c);
            }
        }
        return result;
    }
};
