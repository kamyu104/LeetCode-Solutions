// Time:  O(n + q)
// Space: O(n)

// prefix sum
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        static const unordered_set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};
        vector<int> prefix(size(words) + 1);
        for (int i = 0; i < size(words); ++i) {
            prefix[i + 1] = prefix[i] + static_cast<int>(VOWELS.count(words[i][0]) && VOWELS.count(words[i].back()));
        }
        vector<int> result;
        for (const auto& q : queries) {
            result.emplace_back(prefix[q[1] + 1] - prefix[q[0]]);
        }
        return result;
    }
};
