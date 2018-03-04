// Time:  O(n + w), n is the size of S, w is the size of words
// Space: O(1)

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<char, vector<pair<int, int>>> waiting;
        for (int i = 0; i < words.size(); ++i) {
            waiting[words[i][0]].emplace_back(i, 1);
        }
        for (const auto& c : S) {
            auto advance = move(waiting[c]);
            waiting.erase(c);
            for (const auto& kvp : advance) {
                int i = kvp.first, j = kvp.second;
                int next = (j != words[i].length()) ? words[i][j] : 0;
                waiting[next].emplace_back(i, j + 1);
            }
        }
        return waiting[0].size();
    }
};
