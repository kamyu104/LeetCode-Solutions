// LeetCode, SFind Minimum in Rotated Sorted Array
// Complexity:
//     O(logn) time
//     O(1) space

class Solution {
public:
    int findMin(vector<int> &num) {
        int start = 0, end = num.size();
        
        while (start < end) {
            if (num[start] <= num[end - 1])
            return num[start];
            
            int mid = start + (end - start)/2;
            
            if (num[mid] >= num[start]) {
                start = mid + 1;
            } else {
                if (mid == end - 1)
                return num[mid];
                else
                end = mid + 1;
            }
        }
        
        return num[start];
    }
};