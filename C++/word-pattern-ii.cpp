// Time:  O(C(n + p - 1, p - 1)), n is length of str, p is length of pattern
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

        if (i == pattern.size() && j == str.length()) {
            return true;
        }

        for (int k = j; k < str.length(); ++k) {
            const char p = pattern[i];
            const string w = str.substr(j, k - j + 1);
            bool build_mapping = false;
            if (!w2p->count(w) && !p2w->count(p)) { 
                // Build mapping. Space: O(n + p)
                (*w2p)[w] = p; 
                (*p2w)[p] = w;
                build_mapping = true;
            } else if (!w2p->count(w) || (*w2p)[w] != p) {
                // Contradict mapping.
                continue;
            }
            if (match(pattern, str, i + 1, k + 1, w2p, p2w)) {
                return true;
            } else if (build_mapping) {
                w2p->erase(w);
                p2w->erase(p);
            }
        }
        return false;
    }
};
