// Time:  O(n)
// Space: O(n)

// freq table
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
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int result = 0;
        unordered_map<pair<int, int>, int, PairHash<int>> cnt;
        for (int i = 0; i + 1 < size(nums); ++i) {
            if (nums[i] == nums[i + 1]) {
                ++result;
            } else {
                ++cnt[minmax(nums[i], nums[i + 1])];
            }
        }
        if (!empty(cnt)) {
            result += ranges::max_element(cnt, {}, [](const auto& p) { return p.second; })->second;
        }
        return result;
    }
};
