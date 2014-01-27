// Time Complexity: O(logn)
//                  O(n) if duplicates are allowed 
// Space Complexity: O(1)

class Solution {
    public:
        bool search(int A[], int n, int target) {
            for(int start = 0, end = n; start < end; ) {
                const int mid = (start + end) / 2;
                if(A[mid] == target)
                    return true;
                if(A[start] <  A[mid]) {
                    if(A[start] <= target && target < A[mid])
                        end = mid;
                    else
                        start = mid + 1;
                }
                else if(A[start] > A[mid]) {
                    if(A[mid] < target && target <= A[end - 1])
                        start = mid + 1;
                    else
                        end = mid;
                }
                else
                    ++start;
            }
            return false;
        }
};
