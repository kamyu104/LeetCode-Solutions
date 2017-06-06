// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> lookup;
        for (const auto& candy: candies) {
            lookup.emplace(candy);
        }
        return min(lookup.size(), candies.size() / 2);
    }
};
