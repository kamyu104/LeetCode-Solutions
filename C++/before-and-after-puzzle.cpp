// Time:  O(l * rlogr)  , l is the max length of phrases
//                      , r is the number of result, could be up to O(n^2)
// Space: O(l * (n + r)), n is the number of phrases

class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        unordered_map<string, vector<size_t>> lookup;
        for (int i = 0; i < phrases.size(); ++i) {
            const auto& phrase = phrases[i];
            const auto& right = phrase.rfind(' ');
            const auto& word = (right == string::npos) ? phrase : phrase.substr(right + 1);
            lookup[word].emplace_back(i);
        }
        unordered_set<string> result_set;
        for (int i = 0; i < phrases.size(); ++i) {
            const auto& phrase = phrases[i];
            const auto& left = phrase.find(' ');
            const auto& word = (left == string::npos) ? phrase : phrase.substr(0, left);
            if (!lookup.count(word)) {
                continue;
            }
            for (const auto& j : lookup[word]) {
                if (j == i) {
                    continue;
                }
                result_set.emplace(phrases[j] + phrase.substr(word.length()));
            }
        }
        vector<string> result(result_set.cbegin(), result_set.cend());
        sort(result.begin(), result.end());
        return result;
    }
};
