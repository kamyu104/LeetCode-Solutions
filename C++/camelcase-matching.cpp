// Time:  O(n * l), n is number of quries
//                , l is length of query
// Space: O(1)

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for (const auto& query : queries) {
            result.emplace_back(is_matched(query, pattern));
        }
        return result;
    }

private:
    bool is_matched(const string& query, const string& pattern) {
        int i = 0;
        for (const auto& c : query) {
            if (i < pattern.length() && pattern[i] == c) {
                ++i;
            } else if (isupper(c)) {
                return false;
            }
        }
        return i == pattern.length();
    }
    
};
