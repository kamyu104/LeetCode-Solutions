// Time:  O(n * d * l), l is the average string length
// Space: O(n)

// 16ms
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<bool> lookup(s.length());
        for (const auto& d: dict) {
            auto pos = -1;
            while ((pos = s.find(d, pos + 1)) != string::npos) {
                fill(lookup.begin() + pos, lookup.begin() + pos + d.length(), true);
            }
        }
        string result;
        for (int i = 0; i < s.length(); ++i) {
            if (lookup[i] && (i == 0 || !lookup[i - 1])) {
                result += "<b>";
            }
            result.push_back(s[i]);
            if (lookup[i] && (i == (s.length() - 1) || !lookup[i + 1])) {
                result += "</b>";
            }
        }
        return result;
    }
};

// Time:  O(n * l), l is the average string length
// Space: O(t)    , t is the size of trie
// 142ms
class Solution2 {
public:
    string addBoldTag(string s, vector<string>& dict) {
        TrieNode trie;
        for (const auto& word : dict) {
            trie.Insert(word);
        }

        vector<bool> lookup(s.length());
        for (int i = 0; i < s.length(); ++i) {
            auto curr = &trie;
            int k = i - 1;
            for (int j = i; j < s.length(); ++j) {
                if (!curr->leaves.count(s[j])) {
                    break;
                }
                curr = curr->leaves[s[j]];
                if (curr->isString) {
                    k = j;
                }
            }
            fill(lookup.begin() + i, lookup.begin() + k + 1, true);
        }

        string result;
        for (int i = 0; i < s.length(); ++i) {
            if (lookup[i] && (i == 0 || !lookup[i - 1])) {
                result += "<b>";
            }
            result.push_back(s[i]);
            if (lookup[i] && (i == (s.length() - 1) || !lookup[i + 1])) {
                result += "</b>";
            }
        }
        return result;
    }

private:
    struct TrieNode {
        bool isString;
        unordered_map<char, TrieNode *> leaves;
        
        TrieNode() : isString{false} {}
        
        void Insert(const string& s) {
            auto* p = this;
            for (const auto& c : s) {
                if (!p->leaves[c]) {
                    p->leaves[c] = new TrieNode;
                }
                p = p->leaves[c];
            }
            p->isString = true;
        }
        
        ~TrieNode() {
            for (auto& kvp : leaves) {
                if (kvp.second) {
                    delete kvp.second;
                }
            }
        }
    };
};
