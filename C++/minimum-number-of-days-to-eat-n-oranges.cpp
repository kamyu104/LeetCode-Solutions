// Time:  O((logn)^2)
// Space: O((logn)^2)

// complexity analysis: see https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/discuss/794847/Polylogarithmic-solution
class Solution {
public:
    int minDays(int n) {
        unordered_map<int, int> lookup;
        return memoization(n, &lookup);
    }

private:
    int memoization(int i, unordered_map<int, int> *lookup) {
        if (i <= 1) {
            return i;
        }
        if (!lookup->count(i)) {
            (*lookup)[i] = 1 + min(i % 2 + memoization(i / 2, lookup),
                                   i % 3 + memoization(i / 3, lookup));
        }
        return (*lookup)[i];
    }
};
