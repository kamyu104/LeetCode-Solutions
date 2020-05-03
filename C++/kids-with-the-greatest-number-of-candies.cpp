// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        const auto& max_num = *max_element(cbegin(candies), cend(candies));
        vector<bool> result;
        transform(cbegin(candies), cend(candies), back_inserter(result),
                  [&extraCandies, &max_num](const auto& x) {
                      return x + extraCandies >= max_num;
                  });
        return result;
    }
};
