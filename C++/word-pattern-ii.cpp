// Time:  O(n * C(n + p - 1, p - 1)), n is length of str, p is length of pattern
// Space: O(n + p) 

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<string, char> w2p;
        unordered_map<char, string> p2w;
        return match(pattern, str, 0, 0, &w2p, &p2w);
    }

    bool match(const string &pattern, const string &str,
               const int i, const int j,
               unordered_map<string, char>* w2p,
               unordered_map<char, string>* p2w) {
        bool is_match = false;
        if (i == pattern.length() && j == str.length()) {
            is_match = true;
        } else if (i < pattern.length() && j < str.length()) {
            const char p = pattern[i];
            if (p2w->count(p)) {
                if ((*p2w)[p] == str.substr(j, (*p2w)[p].length())) {  // Match pattern.
                    return match(pattern, str, i + 1, j + (*p2w)[p].length(), w2p, p2w);
                }  // Else return false.
            } else {
                for (int k = j; k < str.length() && !is_match; ++k) {
                    const string w = str.substr(j, k - j + 1);
                    if (!w2p->count(w)) {
                        // Build mapping. Space: O(n + p)
                        (*w2p)[w] = p; 
                        (*p2w)[p] = w;
                        is_match = match(pattern, str, i + 1, k + 1, w2p, p2w);
                        w2p->erase(w);
                        p2w->erase(p);
                    }  // Else try longer word.
                }
            }
        }
        return is_match;
    }
};
