// Time:  O(n)
// Space: O(n)

// hash table, prefix sum
class Solution {
private:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };

public:
    int maxBalancedSubarray(vector<int>& nums) {
        int result = 0, total = 0, bal = 0;
        unordered_map<pair<int, int>, int, PairHash<int>> lookup;
        lookup[pair(total, bal)] = -1;
        for (int i = 0; i < size(nums); ++i) {
            total ^= nums[i];
            bal += nums[i] % 2 ? 1 : -1;
            const auto& key = pair(total, bal);
            if (!lookup.count(key)) {
                lookup[key] = i;
            } else {
                result = max(result, i - lookup[key]);
            }
        }
        return result;
    }
};
