// Time Complexity: O(logn)
// Space Complexity: O(1)

class Solution {
    public:
        vector<int> searchRange(int A[], int n, int target) {
            int begin = lower_bound(A, n, target);
            int end = upper_bound(A, n, target);

            if(begin < n && A[begin] == target) 
                return {begin, end - 1};

            return {-1, -1};
        }

    private:
        int lower_bound(int A[], int n, int target) {
            int begin = 0;
            int end = n;
            while(begin < end) {
                int mid = (begin + end) / 2;
                if(A[mid] < target)
                    begin = mid + 1;
                else
                    end = mid;
            }
            return begin;
        }

        int upper_bound(int A[], int n, int target) {
            int begin = 0;
            int end = n;
            while(begin < end) {
                int mid = (begin + end) / 2;
                if(A[mid] <= target)
                    begin = mid + 1;
                else
                    end = mid;
            }
            return begin;
        }
};
