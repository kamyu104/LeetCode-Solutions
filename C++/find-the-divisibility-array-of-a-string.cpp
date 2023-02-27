// Time:  O(n)
// Space: O(1)

// prefix sum
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> result;
        int curr = 0;
        for (const auto& c : word) {
            curr = (curr * 10LL + (c - '0')) % m;
            result.emplace_back(curr == 0 ? 1 : 0);
        }
        return result;
    }
};
