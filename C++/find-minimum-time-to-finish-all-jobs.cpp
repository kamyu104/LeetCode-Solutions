// Time:  O(k^n * logr), the real complexity shoud be much less, but hard to analyze
// Space: O(n + k)

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(begin(jobs), end(jobs), greater<int>());
        int left = *max_element(cbegin(jobs), cend(jobs));
        int right = accumulate(cbegin(jobs), cend(jobs), 0);
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            vector<int> counts(k);
            if (backtracking(jobs, 0, mid, &counts)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool backtracking(const vector<int>& jobs,
                      int i, int cap,
                      vector<int> *counts) {
        if (i == size(jobs)) {
            return true;
        }
        for (int j = 0; j < size(*counts); ++j) {
            if ((*counts)[j] + jobs[i] <= cap) {
                (*counts)[j] += jobs[i];
                if (backtracking(jobs, i + 1, cap, counts)) {
                    return true;
                }
                (*counts)[j] -= jobs[i];
            }
            if ((*counts)[j] == 0) {
                break;
            }
        }
        return false;
    }
};

// Time:  O(k * k^n), the real complexity shoud be less, but hard to analyze
// Space: O(n + k)
class Solution2 {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(begin(jobs), end(jobs), greater<int>());
        int result = accumulate(cbegin(jobs), cend(jobs), 0);
        vector<int> counts(k);
        backtracking(jobs, 0, &counts, &result);
        return result;
    }

private:
    void backtracking(const vector<int>& jobs,
                      int i,
                      vector<int> *counts,
                      int *result) {
        if (i == size(jobs)) {
            *result = min(*result, *max_element(cbegin(*counts), cend(*counts)));
            return;
        }
        for (int j = 0; j < size(*counts); ++j) {
            if ((*counts)[j] + jobs[i] <= *result) {
                (*counts)[j] += jobs[i];
                backtracking(jobs, i + 1, counts, result);
                (*counts)[j] -= jobs[i];
            }
            if ((*counts)[j] == 0) {
                break;
            }
        }
    }
};
