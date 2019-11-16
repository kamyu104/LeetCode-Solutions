// Time:  O(m * n)
// Space: O(n)

class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parents;
        for (const auto& region : regions) {
            for (int i = 1; i < region.size(); ++i) {
                parents[region[i]] = region[0];
            }
        }
        unordered_set<string> lookup = {region1};
        while (parents.count(region1)) {
            region1 = parents[region1];
            lookup.emplace(region1);
        }
        while (!lookup.count(region2)) {
            region2 = parents[region2];
        }
        return region2;
    }
};
