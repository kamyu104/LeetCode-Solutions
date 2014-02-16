// Time Complexity: O((m - n * k) * n * k) ~ O(m * n * k), where m is string length, n is dict size, k is word length
// Space Complexity: O( n * k)
class Solution {
    public:
        vector<int> findSubstring(string s, vector<string> &dict) {
            const size_t wordLength = dict.front().length();
            const size_t catLength = wordLength * dict.size();
            vector<int> result;

            if(s.length() < catLength) return result;

            unordered_map<string, int> wordCount;

            for(auto const & word : dict) ++wordCount[word];

            for(auto i = begin(s); i <= prev(end(s), catLength); ++i) {
                unordered_map<string, int> unused(wordCount);

                for(auto j = i; j != next(i, catLength); j += wordLength) {
                    auto pos = unused.find(string(j, next(j, wordLength)));

                    if(pos == unused.end()) break;

                    if(--pos->second == 0) unused.erase(pos);
                }

                if(unused.size() == 0) result.push_back(distance(begin(s), i));
            }

            return result;
        }
};
