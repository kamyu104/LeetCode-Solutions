// Time:  O(C(m * n, i) * C(m * n - i, e))
// Space: O(min(m * n, i + e))

// iterative solution, 660 ms
class Solution {
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        return iter_backtracking(m, n, introvertsCount, extrovertsCount);
    }

private:
    int iter_backtracking(int m, int n, int i, int e) {
        int result = 0;
        vector<int> curr;
        vector<tuple<int, int, int, int, int>> stk = {{2, i, e, 0, 0}};
        while (!empty(stk)) {
            const auto [step, i, e, total, x] = stk.back(); stk.pop_back();
            if (step == 2) {
                if ((size(curr) == m * n) || (i == 0 && e == 0)) {
                    result = max(result, total);
                    continue;
                }
                if (total + (i + e) * 120 < result) {  // pruning
                    continue;
                }
                if (e > 0) {
                    int new_total = count_total(n, curr, 2, total);
                    stk.emplace_back(3, 0, 0, 0, 0);
                    stk.emplace_back(2, i, e - 1, new_total, 0);
                    stk.emplace_back(1, 0, 0, 0, 2);
                }
                if (i > 0) {
                    int new_total = count_total(n, curr, 1, total);
                    stk.emplace_back(3, 0, 0, 0, 0);
                    stk.emplace_back(2, i - 1, e, new_total, 0);
                    stk.emplace_back(1, 0, 0, 0, 1);
                }
                if (left(n, curr) || up(n, curr)) {  // leave unoccupied iff left or up is occupied
                    stk.emplace_back(3, 0, 0, 0, 0);
                    stk.emplace_back(2, i, e, total, 0);
                    stk.emplace_back(1, 0, 0, 0, 0);
                }
            } else if (step == 1) {
                curr.emplace_back(x);
            } else if (step == 3) {
                curr.pop_back();
            }
        }
        return result;
    }
    
    int left(int n, const vector<int>& curr) {
        return (size(curr) % n) ? curr[size(curr) - 1] : 0;
    }

    int up(int n, const vector<int>& curr) {
        return (size(curr) >= n) ? curr[size(curr) - n] : 0;
    }

    int count_total(int n, const vector<int>& curr, int t, int total) {
        return (total
	        - 30 * ((left(n, curr) == 1) + (up(n, curr) == 1))
                + 20 * ((left(n, curr) == 2) + (up(n, curr) == 2))
                + (120 - 30 * ((left(n, curr) != 0) + (up(n, curr) != 0))) * (t == 1)
                + ( 40 + 20 * ((left(n, curr) != 0) + (up(n, curr) != 0))) * (t == 2));
    }
};

// Time:  O(C(m * n, i) * C(m * n - i, e))
// Space: O(min(m * n, i + e))
// recursive solution, 104 ms
class Solution2 {
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        int result = 0;
        vector<int> curr;
        backtracking(m, n, introvertsCount, extrovertsCount, 0, &curr, &result);
        return result;
    }

private:
    void backtracking(int m, int n, int i, int e, int total,
                      vector<int> *curr, int *result) {
        if ((size(*curr) == m * n) || (i == 0 && e == 0)) {
            *result = max(*result, total);
            return;
        }
        if (total + (i + e) * 120 < *result) {  // pruning
            return;
        }
        if (left(n, *curr) || up(n, *curr)) {  // leave unoccupied iff left or up is occupied
            curr->emplace_back(0);
            backtracking(m, n, i, e, total, curr, result);
            curr->pop_back();
        }
        if (i > 0) {
            int new_total = count_total(n, *curr, 1, total);
            curr->emplace_back(1);
            backtracking(m, n, i - 1, e, new_total, curr, result);
            curr->pop_back();
        }
        if (e > 0) {
            int new_total = count_total(n, *curr, 2, total);
            curr->emplace_back(2);
            backtracking(m, n, i, e - 1, new_total, curr, result);
            curr->pop_back();
        }
    }
    
    int left(int n, const vector<int>& curr) {
        return (size(curr) % n) ? curr[size(curr) - 1] : 0;
    }

    int up(int n, const vector<int>& curr) {
        return (size(curr) >= n) ? curr[size(curr) - n] : 0;
    }

    int count_total(int n, const vector<int>& curr, int t, int total) {
        return (total
	        - 30 * ((left(n, curr) == 1) + (up(n, curr) == 1))
                + 20 * ((left(n, curr) == 2) + (up(n, curr) == 2))
                + (120 - 30 * ((left(n, curr) != 0) + (up(n, curr) != 0))) * (t == 1)
                + ( 40 + 20 * ((left(n, curr) != 0) + (up(n, curr) != 0))) * (t == 2));
    }
};
