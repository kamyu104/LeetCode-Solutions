// Time:  O(n!)
// Space: O(n)

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1);
        vector<bool> lookup(n + 1);
        backtracking(n, 0, &lookup, &result);
        return result;
    }

private:
    bool backtracking(int n, int i, vector<bool> *lookup, vector<int> *result) {
        if (i == size(*result)) {
            return true;
        }
        if ((*result)[i]) {
            return backtracking(n, i + 1, lookup, result);
        }
        for (int x = n; x >= 1; --x) {
            int j = (x == 1) ? i : i + x;
            if ((*lookup)[x] || j >= size(*result) || (*result)[j]) {
                continue;
            }
            (*result)[i] = (*result)[j] = x, (*lookup)[x] = true;
            if (backtracking(n, i + 1, lookup, result)) {
                return true;
            }
            (*result)[i] = (*result)[j] = 0, (*lookup)[x] = false;
            
        }
        return false;
    }
};
