// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> result;
        first.push_back(' ');
        second.push_back(' ');
        string third;
        int i = 0, j = 0, k = 0;
        while (k < text.length()) {
            auto c = text[k++];
            if (i != first.length()) {
                if (c == first[i]) {
                    ++i;
                } else {
                    i = 0;
                }
                continue;
            }
            if (j != second.length()) {
                if (c == second[j]) {
                    ++j;
                } else {
                    k -= j + 1;
                    i = 0, j = 0;
                }
                continue;
            }
            if (c != ' ') {
                third.push_back(c);
                continue;
            }
            k -= second.length() + third.length() + 1;
            i = 0, j = 0;
            result.emplace_back(move(third));
        }
        if (!third.empty()) {
            result.emplace_back(move(third));
        }
        return result;
    }
};
