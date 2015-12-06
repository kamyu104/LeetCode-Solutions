// Time:  O(nlogn)
// Space: O(n)

// BIT solution.
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sorted_nums(nums), nth_smallest(nums.size());
        sort(sorted_nums.begin(), sorted_nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            nth_smallest[i] = 
                lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]) -
                sorted_nums.begin();
        }
        vector<int> bit(nums.size() + 1), ans(nums.size());
        for (int i = nth_smallest.size() - 1; i >= 0; --i) {
            ans[i] = query(bit, nth_smallest[i]);
            add(bit, nth_smallest[i] + 1, 1);
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
