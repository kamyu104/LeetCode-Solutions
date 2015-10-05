// Time:  O(n)
// Space: O(c), c is unique count of pattern and words

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int cnt = str.empty() ? 0 : 1;
        for (const auto& c : str) {
            if (c == ' ') {
                ++cnt;
            }
        }
        if (pattern.size() != cnt) {
            return false;
        }

        unordered_map<string, char> w2p;
        unordered_map<char, string> p2w;
        int i = 0, j = 0;
        for (const auto& p : pattern) {
            j = str.find(" ", i);
            if (j == string::npos) {
                j = str.length();
            }
            const string word = str.substr(i, j - i);
            if (!w2p.count(word) && !p2w.count(p)) { 
                w2p[word] = p; 
                p2w[p] = word; 
            } else if (w2p[word] != p) {
                return false;
            }
            i = j + 1;
        }
        return true;
    }
};
