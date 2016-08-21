// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // sort numbers
        sort(nums.begin(), nums.end(), [](const int &i, const int &j) {
            return to_string(i) + to_string(j) > to_string(j) + to_string(i);
        });

        // combine the numbers
        string max_num;
        for (const auto& i : nums) {
            max_num.append(to_string(i));
        }

        // special case: start with zero (e.g. [0, 0])
        if (!max_num.empty() && max_num[0] == '0')  {
            return "0";
        }

        return max_num;
    }
};
