// Time:  O(n * logr + q), r = max(a^b for a, b in queries)
// Space: O(min(n * logr, r))

// hash table
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        const int i = distance(cbegin(queries), max_element(cbegin(queries), cend(queries), [](const auto& a, const auto& b) {
            return (a[0] ^ a[1]) < (b[0] ^ b[1]);
        }));
        const int mx = queries[i][0] ^ queries[i][1];
        unordered_map<int, vector<int>> lookup;
        for (int i = 0; i < size(s); ++i) {
            int curr = 0;
            for (int j = i; j < size(s); ++j) {
                curr = (curr << 1) + (s[j] - '0');
                if (curr > mx) {
                    break;
                }
                if (!lookup.count(curr)) {
                    lookup[curr] = {i, j};
                }
                if (s[i] == '0') {
                    break;
                }
            }
        }
        vector<vector<int>> result;
        for (const auto& q : queries) {
            result.emplace_back(lookup.count(q[0] ^ q[1]) ? lookup[q[0] ^ q[1]] : vector<int>(2, -1));
        }
        return result;
    }
};
