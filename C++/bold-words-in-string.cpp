// Time:  O(n * l), n is the length of S, l is the average length of words
// Space: O(t)    , t is the size of trie

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        TrieNode trie;
        for (const auto& word : words) {
            trie.Insert(word);
        }

        vector<bool> lookup(S.length());
        for (int i = 0; i < S.length(); ++i) {
            auto curr = &trie;
            int k = -1;
            for (int j = i; j < S.length(); ++j) {
                if (!curr->leaves[S[j] - 'a']) {
                    break;
                }
                curr = curr->leaves[S[j] - 'a'];
                if (curr->isString) {
                    k = j;
                }
            }
            for (int j = i; j <= k; ++j) {
                lookup[j] = true;
            }
        }

        string result;
        for (int i = 0; i < S.length(); ++i) {
            if (lookup[i] && (i == 0 || !lookup[i - 1])) {
                result += "<b>";
            }
            result.push_back(S[i]);
            if (lookup[i] && (i == (S.length() - 1) || !lookup[i + 1])) {
                result += "</b>";
            }
        }
        return result;
    }

private:
    struct TrieNode {
        bool isString;
        vector<TrieNode *> leaves;
        
        TrieNode() : isString{false}, leaves(26) {}
        
        void Insert(const string& s) {
            auto* p = this;
            for (const auto& c : s) {
                if (!p->leaves[c - 'a']) {
                    p->leaves[c - 'a'] = new TrieNode;
                }
                p = p->leaves[c - 'a'];
            }
            p->isString = true;
        }
        
        ~TrieNode() {
            for (auto& node : leaves) {
                if (node) {
                    delete node;
                }
            }
        }
    };
};


// Time:  O(n * d * l), l is the average length of words
// Space: O(n)
class Solution2 {
public:
    string boldWords(vector<string>& words, string S) {
        vector<bool> lookup(S.length());
        for (const auto& d: words) {
            auto pos = -1;
            while ((pos = S.find(d, pos + 1)) != string::npos) {
                fill(lookup.begin() + pos, lookup.begin() + pos + d.length(), true);
            }
        }
        string result;
        for (int i = 0; i < S.length(); ++i) {
            if (lookup[i] && (i == 0 || !lookup[i - 1])) {
                result += "<b>";
            }
            result.push_back(S[i]);
            if (lookup[i] && (i == (S.length() - 1) || !lookup[i + 1])) {
                result += "</b>";
            }
        }
        return result;
    }
};
