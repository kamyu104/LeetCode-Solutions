// Time:  O(n * l)
// Space: O(n * l)

// hash table, string
class Solution {
public:
    int minimumGroups(vector<string>& words) {
        const auto& leastRotation = [](const string& s) {
            const auto& n = size(s);
            int i = 0, j = 1, k = 0;
            while (i < n && j < n && k < n) {
                char a = s[(i + k) % n];
                char b = s[(j + k) % n];
                if (a == b) {
                    ++k;
                } else {
                    if (a > b) {
                        i += k + 1;
                    } else {
                        j += k + 1;
                    }
                    if (i == j) {
                        ++j;
                    }
                    k = 0;
                }
            }
            return min(i, j);
        };

        const auto& canonical = [&](const string& s) {
            string result(s);
            rotate(begin(result), begin(result) + leastRotation(s), end(result));
            return result;
        };

        unordered_set<string> lookup;
        for (const auto& w : words) {
            vector<string> s(2);
            s[0].reserve(size(w) / 2);
            s[1].reserve((size(w) + 1) / 2);
            for (int i = 0; i < size(w); ++i) {
                s[i % 2].push_back(w[i]);
            }
            string key = canonical(s[0]);
            key.push_back('#');
            key.append(canonical(s[1]));
            lookup.emplace(key);
        }
        return size(lookup);
    }
};
