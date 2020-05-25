// Time:  O(n * m * l + n^2 * m), n is favoriteCompanies.length
//                              , m is the max of favoriteCompanies[i].length
//                              , l is the max of favoriteCompanies[i][j].length
// Space: O(n * m * l)

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<string, int> lookup;
        vector<unordered_set<int>> comps;
        for (const auto& cs : favoriteCompanies) {
            comps.emplace_back();
            for (const auto& c : cs) {
                if (!lookup.count(c)) {
                    const auto id = lookup.size();
                    lookup[c] = id;
                }
                comps.back().emplace(lookup[c]);
            }
        }
        vector<int> result;
        for (int i = 0; i < comps.size(); ++i) {
            bool is_not_subset = true;
            for (int j = 0; j < comps.size(); ++j) {
                if (i == j) {
                    continue;
                }
                if (all_of(cbegin(comps[i]), cend(comps[i]),
                           [&](const auto& a) {
                               return comps[j].count(a);
                           })) {
                    is_not_subset = false;
                    break;
                }
            }
            if (is_not_subset) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};
