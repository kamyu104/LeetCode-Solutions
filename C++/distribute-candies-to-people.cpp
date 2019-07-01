// Time:  O(sqrt(n)), n is the number of candies
// Space: O(1)

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people);
        for (int i = 0; candies; ++i) {
            result[i % num_people] += min(candies, i + 1);
            candies -= min(candies, i + 1);
        }
        return result;
    }
};
