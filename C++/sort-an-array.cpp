// Time:  O(nlogn)
// Space: O(n)

// merge sort solution
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size(),
                  numeric_limits<int>::min(),
                  numeric_limits<int>::max(),
                  &nums);
        return nums;
    }

private:
    void mergeSort(int start, int end, int lower, int upper,
                         vector<int> *nums) {
        if (end - start <= 1) {
            return;
        }
        int mid = start + (end - start) / 2;
        mergeSort(start, mid, lower, upper, nums);
        mergeSort(mid, end, lower, upper, nums);
        int r = mid;
        vector<int> tmp;
        for (int i = start; i < mid; ++i) {
            while (r < end && (*nums)[r] < (*nums)[i]) {
                tmp.emplace_back((*nums)[r++]);
            }
            tmp.emplace_back((*nums)[i]);
        }
        copy(tmp.begin(), tmp.end(), nums->begin() + start);
    }
};
