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

// Time:  O((logn)^2)
// Space: O((logn)^2)
class Solution2 {
public:
    int minDays(int n) {
        int result = 0;
        vector<int> q = {n};
        unordered_set<int> lookup = {n};
        while (!q.empty()) {
            vector<int> new_q;
            for (const auto& i : q) {
                if (i == 0) {
                    return result;
                }
                if (!lookup.count(i - 1)) {
                    lookup.emplace(i - 1);
                    new_q.emplace_back(i - 1);
                }
                if (i % 2 == 0 && !lookup.count(i / 2)) {
                    lookup.emplace(i / 2);
                    new_q.emplace_back(i / 2);
                }
                if (i % 3 == 0 && !lookup.count(i / 3)) {
                    lookup.emplace(i / 3);
                    new_q.emplace_back(i / 3);
                }
            }
            ++result;
            q = move(new_q);
        }
        return result;
    }
};
