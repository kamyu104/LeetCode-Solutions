// Time:  O(n * l)
// Space: O(1)

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> count(26, numeric_limits<int>::max());
        vector<string> result;
        for (const auto& a : A) {
            vector<int> tmp_count(count.size());
            for (const auto& c : a) {
                ++tmp_count[c - 'a'];
            }
            for (int i = 0; i < count.size(); ++i) {
                count[i] = min(count[i], tmp_count[i]);
            }
        }
        for (int i = 0; i < count.size(); ++i) {
            for (auto j = 0; j < count[i]; ++j) {
                result.emplace_back(1, i + 'a');
            }
        }
        return result;
    }
};
