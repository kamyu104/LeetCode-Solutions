// Time:  O(m + n)
// Space: O(m + n)

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> count;
        istringstream iss(A + " " + B);
        while (iss >> A) {
            ++count[A];
        }
        vector<string> result;
        for (const auto& word : count) {
            if (word.second == 1) {
                result.emplace_back(word.first);
            }
        }
        return result;
    }
};
