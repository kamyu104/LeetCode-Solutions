// Time: O(n)
// Space: O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i;
        bucketSort(&nums);
        for (i = 0; i < nums.size() && nums[i] == i + 1; ++i);
        return i + 1;
    }

private:
    void bucketSort(vector<int> *nums) {
        int i = 0;
        while (i < nums->size()) {
            if ((*nums)[i] > 0 && (*nums)[i] <= nums->size() &&
                (*nums)[i] != (*nums)[(*nums)[i] - 1]) {
                swap((*nums)[i], (*nums)[(*nums)[i] - 1]);
            } else {
                ++i;
            }
        }
    }
};
