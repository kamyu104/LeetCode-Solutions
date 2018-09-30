// Time:  O(m + n)
// Space: O(1)

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> count(26);
        for (const auto& b : B) {
            const auto& tmp = counter(b);
            for (int i = 0; i < 26; ++i) {
                count[i] = max(count[i], tmp[i]);
            }
        }
        vector<string> result;
        for (const auto& a : A) {
            const auto& tmp = counter(a);
            int i = 0;
            for (; i < 26; ++i) {
                if (tmp[i] < count[i]) {
                    break;
                }
            }
            if (i == 26) {
                result.emplace_back(a);
            }
        }
        return result;
    }

private:
    vector<int> counter(const string& word) {
        vector<int> count(26);
        for (const auto& c : word) {
            ++count[c - 'a'];
        }
        return count;
    }
};
