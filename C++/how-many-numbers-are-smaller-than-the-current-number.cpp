// Time:  O(n + m), m is the max number of nums
// Space: O(m)

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        const auto& m = *max_element(cbegin(nums), cend(nums));
        auto count = counter(nums);
        for (int i = 0; i <= m; ++i) {
            count[i] += count[i - 1];
        }
        vector<int> result;
        for (const auto& i : nums) {
            result.emplace_back(count[i - 1]);
        }
        return result;
    }

private:
    unordered_map<int, int> counter(const vector<int>& nums) const {
        unordered_map<int, int> count;
        for (const auto& num : nums) {
            ++count[num];
        }
        return count;
    }
};

// Time:  O(nlogn)
// Space: O(n)
class Solution2 {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted_nums(nums);
        sort(begin(sorted_nums), end(sorted_nums));
        vector<int> result;
        for (const auto& i : nums) {
            result.emplace_back(distance(cbegin(sorted_nums),
                                         lower_bound(cbegin(sorted_nums), cend(sorted_nums), i)));
        }
        return result;
    }
};
