// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int total = accumulate(A.cbegin(), A.cend(), 0);
        if (total % 3 != 0) {
            return {-1, -1};
        }
        if (total == 0) {
            return {0, A.size() - 1};
        }

        const auto count = total / 3;
        vector<int> nums(3);
        int c = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == 1) {
                if (c % count == 0) {
                    nums[c / count] = i;
                }
                ++c;
            } 
        }

        while (nums[2] != A.size()) {   
            if (A[nums[0]] != A[nums[1]] ||
                A[nums[0]] != A[nums[2]]) {
                return {-1, -1};
            }
            ++nums[0], ++nums[1], ++nums[2];
        }
        return {nums[0] - 1, nums[1]};
    }
};
