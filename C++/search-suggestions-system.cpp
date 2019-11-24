// Time:  ctor: O(n * l), n is the number of products
//                      , l is the average length of product name
//        suggest: O(l^2)
// Space: O(t), t is the number of nodes in trie

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode trie;
        for (int i = 0; i < products.size(); ++i) {
            trie.insert(products, i);
        }
        auto curr = &trie;
        vector<vector<string>> result(searchWord.length());
        for (int i = 0; i < searchWord.length(); ++i) {  // Time: O(l)
            if (!curr->leaves.count(searchWord[i])) {
                break;
            }
            curr = curr->leaves[searchWord[i]];
            for (const auto& j : curr->infos) {
                result[i].emplace_back(products[j]);
            }
        }
        return result;
    }

class TrieNode {
    public:
        static const int TOP_COUNT = 3;

        ~TrieNode() {
            for (auto& kv : leaves) {
                if (kv.second) {
                    delete kv.second;
                }
            }
        }

        // Time:  O(l)
        void insert(const vector<string>& words, int i) {
            auto* curr = this;
            for (const auto& c : words[i]) {
                if (!curr->leaves.count(c)) {
                    curr->leaves[c] = new TrieNode;
                }
                curr = curr->leaves[c];
                curr->add_info(words, i);
            }
        }
        
        // Time:  O(l)
        void add_info(const vector<string>& words, int i) {
            infos.emplace_back(i);
            sort(infos.begin(), infos.end(),
                 [&words](const auto& a, const auto& b) {
                     return words[a] < words[b];
                 });
            if (infos.size() > TOP_COUNT) {
                infos.pop_back();
            }
        }
        
        vector<int> infos;
        unordered_map<char, TrieNode *> leaves;
    };
};

// Time:  ctor: O(n * l * log(n * l)), n is the number of products
//                                   , l is the average length of product name
//        suggest: O(l^2)
// Space: O(t), t is the number of nodes in trie
class Solution2 {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());  // Time: O(n * l * log(n * l))
        TrieNode trie;
        for (int i = 0; i < products.size(); ++i) {
            trie.insert(products, i);
        }
        auto curr = &trie;
        vector<vector<string>> result(searchWord.length());
        for (int i = 0; i < searchWord.length(); ++i) {  // Time: O(l)
            if (!curr->leaves.count(searchWord[i])) {
                break;
            }
            curr = curr->leaves[searchWord[i]];
            for (const auto& j : curr->infos) {
                result[i].emplace_back(products[j]);
            }
        }
        return result;
    }

class TrieNode {
    public:
        static const int TOP_COUNT = 3;

        ~TrieNode() {
            for (auto& kv : leaves) {
                if (kv.second) {
                    delete kv.second;
                }
            }
        }

        // Time:  O(l)
        void insert(const vector<string>& words, int i) {
            auto* curr = this;
            for (const auto& c : words[i]) {
                if (!curr->leaves.count(c)) {
                    curr->leaves[c] = new TrieNode;
                }
                curr = curr->leaves[c];
                curr->add_info(words, i);
            }
        }
        
        // Time:  O(1)
        void add_info(const vector<string>& words, int i) {
            if (infos.size() == TOP_COUNT) {
                return;
            }
            infos.emplace_back(i);
        }
        
        vector<int> infos;
        unordered_map<char, TrieNode *> leaves;
    };
};

// Time:  ctor: O(n * l * log(n * l)), n is the number of products
//                                   , l is the average length of product name
//        suggest: O(l^2 * n)
// Space: O(n * l)
class Solution3 {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());  // Time: O(n * l * log(n * l))
        vector<vector<string>> result;
        string prefix;
        for (int i = 0; i < searchWord.length(); ++i) {  // Time: O(l)
            prefix += searchWord[i];
            int start = distance(products.cbegin(),
                                 lower_bound(products.cbegin(),
                                             products.cend(),
                                             prefix));  // Time: O(log(n * l))
            vector<string> new_products;
            for (int j = start; j < products.size(); ++j) {  // Time: O(n * l)
                if (!(i < products[j].length() && products[j][i] == searchWord[i])) {
                    break;
                }
                new_products.emplace_back(products[j]);
            }
            products = move(new_products);
            result.emplace_back();
            for (int j = 0; j < min(int(products.size()), 3); ++j) {
                result.back().emplace_back(products[j]);
            };
        }
        return result;
    }
};
