// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(begin(properties), end(properties),
             [](const auto& a, const auto& b) {
                 return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
             });
        int result = 0, max_d = 0;
        for (int i = size(properties) - 1; i >= 0; --i) {
            if (properties[i][1] < max_d) {
                ++result;
            }
            max_d = max(max_d, properties[i][1]);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// faster in sort by using more space
class Solution2 {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        unordered_map<int, vector<int>> lookup;
        for (const auto& p : properties) {
            lookup[p[0]].emplace_back(p[1]);
        }
        vector<int> sorted_as;
        for (const auto& [a, _] : lookup) {
            sorted_as.emplace_back(a);
        }
        sort(begin(sorted_as), end(sorted_as), greater<int>());
        int result = 0, max_d = 0;
        for (const auto& a : sorted_as) {
            for (const auto& d : lookup[a]) {
                if (d < max_d) {
                    ++result;
                }
            }
            for (const auto& d : lookup[a]) {
                max_d = max(max_d, d);
            }
        }
        return result;
    }
};
