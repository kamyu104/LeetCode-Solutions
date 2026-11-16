// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        const auto& f = [&](int i) {
            return s1[i] != s2[i];
        };

        vector<vector<string>> result;
        for (int i = 0, l = 0; i < size(s1); ++i) {
            ++l;
            if (!(i + 1 == size(s1) || f(i + 1) != f(i))) {
                continue;
            }
            if (f(i)) {
                result.push_back({s1.substr(i + 1 - l, l), s2.substr(i + 1 - l, l)});
            }
            l = 0;
        }
        return result;
    }
};
