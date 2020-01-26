// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        sort(restaurants.begin(), restaurants.end(),
             [](const auto& a, const auto& b) {
                 return vector<int>{-a[1], -a[0], a[2], a[3], a[4]} < vector<int>{-b[1], -b[0], b[2], b[3], b[4]};
             });
        vector<int> result;
        for (const auto& r : restaurants) {
            if (r[2] >= veganFriendly && r[3] <= maxPrice && r[4] <= maxDistance) {
                result.emplace_back(r[0]);
            }
        }
        return result;
    }
};
