// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        const int n = words.size();
        int begin = 0, len = 0;
        for (int i = 0; i < n; ++i) {
            if (len + words[i].size() + (i - begin) > maxWidth) {
                res.emplace_back(connect(words, maxWidth, begin, i, len, false));
                begin = i;
                len = 0;
            }
            len += words[i].size();
        }
        // Last line.
        res.emplace_back(connect(words, maxWidth, begin, n, len, true));
        return res;
    }

private:
    string connect(const vector<string>& words, int maxWidth,
                   int begin, int end, int len,
                   bool is_last) {
        string s;
        int n = end - begin;
        for (int i = 0; i < n; ++i) {
            s += words[begin + i];
            addSpaces(i, n - 1, maxWidth - len, is_last, &s);
        }
        // For only one word in a line.
        if (s.size() < maxWidth) {
            s.append(maxWidth - s.size(), ' ');
        }
        return s;
    }

    void addSpaces(int i, int spaceCnt, int maxWidth, bool is_last, string *s) {
        if (i < spaceCnt) {
            // For the last line of text, it should be left justified,
            // and no extra space is inserted between words.
            int spaces = is_last ? 1 : maxWidth / spaceCnt + (i < maxWidth % spaceCnt);
            s->append(spaces, ' ');
        }
    }
};
