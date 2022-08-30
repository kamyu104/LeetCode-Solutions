// Time:  O(n * l), l = max(len(g) for g in garbage) = O(10)
// Space: O(1)

// simulation, prefix sum
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int result = 0;
        unordered_map<char, int> lookup;
        for (int i = 0; i < size(garbage); ++i) {
            for (const auto& c : garbage[i]) {
                lookup[c] = i;
            }
            if (i + 1 < size(travel)) {
                travel[i + 1] += travel[i];
            }
            result += size(garbage[i]);
        }
        for (const auto& [_, v] : lookup) {
            if (v - 1 >= 0) {
                result += travel[v - 1];
            }
        }
        return result;
    }
};

// Time:  O(n * l), l = max(len(g) for g in garbage) = O(10)
// Space: O(1)
// simulation, prefix sum
class Solution2 {
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
