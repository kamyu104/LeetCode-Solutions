// Time:  O(n)
// Space: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        if (pivot == -1) {
            reverse(begin(nums), end(nums));
            return;
        }
        for (int i = nums.size() - 1; i > pivot; --i) {
            if (nums[i] > nums[pivot]) {
                swap(nums[pivot], nums[i]);
                break;
            }
        }
        reverse(begin(nums) + pivot + 1, end(nums));
    }
};

class Solution2 {
public:
    void nextPermutation(vector<int> &num) {
        nextPermutation(num.begin(), num.end());
    }
    
private:
    template<typename BidiIt>
    bool nextPermutation(BidiIt begin, BidiIt end) {
        const auto rbegin = reverse_iterator<BidiIt>(end);
        const auto rend = reverse_iterator<BidiIt>(begin);
        
        // Find the first element (pivot) which is less than its successor.
        auto pivot = next(rbegin);
        while (pivot != rend && *pivot >= *prev(pivot)) {
            ++pivot;
        }

        bool is_greater = true;
        if (pivot != rend) {
            // Find the number which is greater than pivot, and swap it with pivot
            auto change = find_if(rbegin, pivot, bind1st(less<int>(), *pivot));
            swap(*change, *pivot);
        } else {
            is_greater = false;
        }
        
        // Make the sequence after pivot non-descending
        reverse(rbegin, pivot);
        
        return is_greater;
    }
};

class Solution3 {
public:
    void nextPermutation(vector<int> &num) {
        next_permutation(num.begin(), num.end());
    }
};
