// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> lookup;
        for (int i = 0; i < keyboard.length(); ++i) {
            lookup[keyboard[i]] = i;
        }
        int result = 0, prev = 0;
        for (const auto& c : word) {
            result += abs(lookup[c] - prev);
            prev = lookup[c];
        }
        return result;
    }
};
