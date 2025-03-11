// Time:  O(r * 2^r)
// Space: O(r * 2^r)

// topological sort
class Solution {
public:
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        unordered_map<string, string> lookup;
        const auto& find_adj = [&](const auto& s) {
            unordered_set<string> result;
            for (int i = 0; i < size(s); ++i) {
                if (s[i] != '%') {
                    continue;
                }
                int j = i + 1;
                for (; j < size(s); ++j) {
                    if (s[j] == '%') {
                        break;
                    }
                }
                result.emplace(s.substr(i + 1, j - (i + 1)));
                i = j;
            }
            return result;
        };

        const auto& replace = [&](const auto& s) {
            string result;
            for (int i = 0; i < size(s); ++i) {
                if (s[i] != '%') {
                    result.push_back(s[i]);
                    continue;
                }
                int j = i + 1;
                for (; j < size(s); ++j) {
                    if (s[j] == '%') {
                        break;
                    }
                }
                result += lookup[s.substr(i + 1, j - (i + 1))];
                i = j;
            }
            return result;
        };

        const auto& topological_sort = [&]() {
            unordered_map<string, unordered_set<string>> adj;
            unordered_map<string, int> in_degree;
            for (const auto& x : replacements) {
                for (const auto& v : find_adj(x[1])) {
                    adj[v].emplace(x[0]);
                    ++in_degree[x[0]];
                }
            }
            vector<string> q;
            for (const auto& x : replacements) {
                if (!in_degree.count(x[0])) {
                    q.emplace_back(x[0]);
                }
            }
            while (!empty(q)) {
                vector<string> new_q;
                for (const auto& u : q) {
                    lookup[u] = replace(lookup[u]);
                    for (const auto& v : adj[u]) {
                        --in_degree[v];
                        if (in_degree[v]) {
                            continue;
                        }
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
        };
    
        for (const auto& x : replacements) {
            lookup[x[0]] = x[1];
        }
        topological_sort();
        return replace(text);
    }
};

// Time:  O(r * 2^r)
// Space: O(r * 2^r)
// memoization
class Solution2 {
public:
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        unordered_map<string, string> lookup, memo;
        const function<string (const string&)> replace = [&](const auto& s) {
            if (!memo.count(s)) {
                string result;
                for (int i = 0; i < size(s); ++i) {
                    if (s[i] != '%') {
                        result.push_back(s[i]);
                        continue;
                    }
                    int j = i + 1;
                    for (; j < size(s); ++j) {
                        if (s[j] == '%') {
                            break;
                        }
                    }
                    result += replace(lookup[s.substr(i + 1, j - (i + 1))]);
                    i = j;
                }
                memo[s] = result;
            }
            return memo[s];
        };

        for (const auto& x : replacements) {
            lookup[x[0]] = x[1];
        }
        return replace(text);
    }
};
