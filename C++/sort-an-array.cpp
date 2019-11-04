// Time:  O(nlogn)
// Space: O(n)

// merge sort solution
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size(), &nums);
        return nums;
    }

private:
    void mergeSort(int start, int end, vector<int> *nums) {
        if (end - start <= 1) {
            return;
        }
        const auto& mid = start + (end - start) / 2;
        mergeSort(start, mid, nums);
        mergeSort(mid, end, nums);
        vector<int> tmp;
        for (int left = start, right = mid; left < mid; ++left) {
            while (right < end && (*nums)[right] < (*nums)[left]) {
                tmp.emplace_back((*nums)[right++]);
            }
            tmp.emplace_back((*nums)[left]);
        }
        copy(tmp.cbegin(), tmp.cend(), nums->begin() + start);
    }
};

// Time:  O(nlogn), on average
// Space: O(logn)
// quick sort solution
class Solution2 {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(0, nums.size(), &nums);
        return nums;
    }

private:
    void quickSort(int start, int end, vector<int> *nums) {
        if (end - start <= 1) {
            return;
        }
        const auto& mid = start + (end - start) / 2;
        nth_element(nums->begin() + start,
                    nums->begin() + mid,
                    nums->begin() + end);
        quickSort(start, mid, nums);
        quickSort(mid, end, nums);
    }
};
