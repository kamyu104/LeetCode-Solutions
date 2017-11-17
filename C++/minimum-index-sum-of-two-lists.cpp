// Time:  O(m + n), m is the size of list1, n is the size of list2
// Space: O(m * l), l is the average string length

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> lookup;
        for (int i = 0; i < list1.size(); ++i) {
            lookup[list1[i]] = i;
        }
        vector<string> result;
        int min_sum = numeric_limits<int>::max();
        for (int j = 0; j < list2.size() && j <= min_sum; ++j) {
            if (lookup.count(list2[j])) {
                auto sum = j + lookup[list2[j]];
                if (sum < min_sum) {
                    result.clear();
                    result.emplace_back(list2[j]);
                    min_sum = sum;
                } else if (sum == min_sum)
                    result.emplace_back(list2[j]);
            }
        }
        return result;
    }
};
