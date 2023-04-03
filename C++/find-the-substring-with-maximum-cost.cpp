// Time:  O(n)
// Space: O(1)

// greedy, kadane's algorithm
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> lookup;
        for (int i = 0; i < size(chars); ++i) {
            lookup[chars[i]] = vals[i];
        }
        const auto& kadane = [&](const auto& s) {
            int result = 0, curr = 0;
            for (const auto& c : s) {
                curr = max(curr + (lookup.count(c) ? lookup[c] : c - 'a' + 1), 0);
                result = max(result, curr);
            }
            return result;
        };

        return kadane(s);
    }
};
