// Time:  O(n * l), l = max(g for g in garbage) = O(10)
// Space: O(1)

// simulation
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int result = 0;
        for (const auto& t : "MPG") {
            int curr = 0;
            for (int i = 0; i < size(garbage); ++i) {
                const int cnt = count(cbegin(garbage[i]), cend(garbage[i]), t);
                if (cnt) {
                    result += curr + cnt;
                    curr = 0;
                }
                if (i < size(travel)) {
                    curr += travel[i];
                }
            }
        }
        return result;
    }
};
