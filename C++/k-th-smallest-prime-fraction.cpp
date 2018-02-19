// Time:  O(nlogr)
// Space: O(1)

// Another cool O(n) solution by using quick select with median of median could be found here:
// https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115545/O(n)

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        vector<int> result;
        double left = 0.0, right = 1.0;
        while (right - left > 1e-8) {
            double mid = left + (right - left) / 2.0;
            if (check(mid, A, K, &result)) {
                right = mid;
            } else {
                left = mid;
            }
            if (!result.empty()) {
                break;
            }
        }
        return result;
    }

private:
    bool check(double mid, const vector<int>& A, int K, vector<int> *result) {
        vector<int> tmp(2);
        int count = 0;
        for (int i = 0, j = 0; i < A.size(); ++i) {
            for (; j < A.size(); ++j) {
                if (i < j && A[i] < A[j] * mid) {
                    if (tmp[0] == 0 || tmp[0] * A[j] < tmp[1] * A[i]) {
                        tmp[0] = A[i];
                        tmp[1] = A[j];
                    }
                    break;
                }
            }
            count += A.size() - j;
        }
        if (count == K) {
            *result = move(tmp);
        }
        return count >= K;
    }
};
