// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        static const vector<unordered_set<char>> rows{{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
                                                      {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'}, 
                                                      {'z', 'x', 'c', 'v', 'b' ,'n', 'm'}};

        vector<string> result;
        for (const auto& word : words) {
            int k = 0;
            for (int i = 0; i < rows.size(); ++i) {
                if (rows[i].count(tolower(word[0]))) {
                    k = i;
                    break;
                }
            }
            result.emplace_back(word);
            for (const auto& c: word) {
                if (!rows[k].count(tolower(c))) {
                    result.pop_back();
                    break;
                }
            }
        }
        return result;
    }
};
