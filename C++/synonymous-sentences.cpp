// Time:  O(p*l * log(p*l)), p is the production of all number of synonyms
//                         , l is the length of a word
// Space: O(p*l)

class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        unordered_map<string, int> lookup;
        unordered_map<int, string> inv_lookup;
        for (const auto& synonym : synonyms) {
            assign_id(synonym[0], &lookup, &inv_lookup);
            assign_id(synonym[1], &lookup, &inv_lookup);
        }
        UnionFind union_find(lookup.size());
        for (const auto& synonym : synonyms) {
            union_find.union_set(lookup[synonym[0]], lookup[synonym[1]]);
        }
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < union_find.set().size(); ++i) {
            groups[union_find.find_set(i)].emplace_back(i);
        }
        vector<vector<string>> result;
        for (const auto& w : split(text, ' ')) {
            if (!lookup.count(w)) {
                result.push_back({w});
                continue;
            }
            result.emplace_back();
            for (const auto& x : groups[union_find.find_set(lookup[w])]) {
                result.back().emplace_back(inv_lookup[x]);
            }
            sort(result.back().begin(), result.back().end());
        }
        return product(result);
    }

private:
    void assign_id(const string& x,
                   unordered_map<string, int> *lookup,
                   unordered_map<int, string> *inv_lookup) {
        if (lookup->count(x)) {
            return;
        }
        (*lookup)[x] = lookup->size();
        (*inv_lookup)[(*lookup)[x]] = x;
    }
    
    vector<string> split(const string& s, const char delim) const {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delim)) {
            if (!token.empty()) {
                tokens.emplace_back(token);
            }
        }
        return tokens;
    }
    
    vector<string> product(const vector<vector<string>>& options) const {
        vector<string> result;
        int total = 1;
        for (const auto& opt : options) {
            total *= opt.size();
        }
        for (int i = 0; i < total; ++i) {
            vector<string> tmp;
            int curr = i;
            for (int j = options.size() - 1; j >= 0; --j) {
                tmp.emplace_back(options[j][curr % options[j].size()]);
                curr /= options[j].size();
            }
            reverse(tmp.begin(), tmp.end());
            result.emplace_back(join(tmp, " "));
        }
        return result;
    }
    
    string join(const vector<string>& strings, const string& delim) const {
        if (strings.empty()) {
            return "";
        }
        ostringstream imploded;
        copy(strings.begin(), prev(strings.end()), ostream_iterator<string>(imploded, delim.c_str()));
        return imploded.str() + *prev(strings.end());
    }
    
    class UnionFind {
        public:
            UnionFind(const int n) : set_(n) {
                iota(set_.begin(), set_.end(), 0);
            }

            int find_set(const int x) {
               if (set_[x] != x) {
                   set_[x] = find_set(set_[x]);  // Path compression.
               }
               return set_[x];
            }

            bool union_set(const int x, const int y) {
                int x_root = find_set(x), y_root = find_set(y);
                if (x_root == y_root) {
                    return false;
                }
                set_[min(x_root, y_root)] = max(x_root, y_root);
                return true;
            }
        
            vector<int> set() const {
                return set_;
            }

        private:
            vector<int> set_;
    };
};
