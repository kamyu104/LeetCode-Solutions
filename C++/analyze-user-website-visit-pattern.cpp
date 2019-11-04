// Time:  O(n^3)
// Space: O(n^3)

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        vector<tuple<int, string, string>> A;
        for (int i = 0; i < username.size(); ++i) {
            A.emplace_back(timestamp[i], username[i], website[i]);
        }
        sort(A.begin(), A.end());
        unordered_map<string, vector<string>> users;
        for (const auto& [t, u, w] : A) {
            users[u].emplace_back(w);
        }

        vector<string> result;
        unordered_map<vector<string>, int, VectorHash<string>> count;
        for (const auto& [u, webs] : users) {
            unordered_set<vector<string>, VectorHash<string>> lookup;
            for (int i = 0; i + 2 < webs.size(); ++i) {
                for (int j = i + 1; j + 1 < webs.size(); ++j) {
                    for (int k = j + 1; k < webs.size(); ++k) {
                        vector<string> pattern = {webs[i], webs[j], webs[k]};
                        if (lookup.count(pattern)) {
                            continue;
                        }
                        lookup.emplace(pattern);
                        ++count[pattern];
                        if (result.empty() ||
                            count[pattern] > count[result] ||
                            (count[pattern] == count[result] && pattern < result)) {
                            result = pattern;
                        }
                    }
                }
            }
        }
        return result;
    }

private:
    template<typename T>
    struct VectorHash {
        size_t operator()(const std::vector<T>& v) const {
            size_t seed = 0;
            for (const auto& i : v) {
                seed ^= std::hash<T>{}(i)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };
};
