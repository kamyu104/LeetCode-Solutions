// Time:  O(nlogn)
// Space: O(n)

// BIT solution.
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // Get the place (position in the ascending order) of each number.
        vector<int> sorted_nums(nums), places(nums.size());
        sort(sorted_nums.begin(), sorted_nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            places[i] = 
                lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]) -
                sorted_nums.begin();
        }
        // Count the smaller elements after the number.
        vector<int> bit(nums.size() + 1), ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans[i] = query(bit, places[i]);
            add(bit, places[i] + 1, 1);
        }
        return ans;
    }

private:
    void add(vector<int>& bit, int i, int val) {
        for (; i < bit.size(); i += lower_bit(i)) {
            bit[i] += val;
        }
    }

    int query(const vector<int>& bit, int i) {
        int sum = 0;
        for (; i > 0; i -= lower_bit(i)) {
            sum += bit[i];
        }
        return sum;
    }

    int lower_bit(int i) {
        return i & -i;
    }
};
