// Time:  O(n * 2^n)
// Space: O(n)

// backtracking
class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        string curr;
        const function<void (int)> backtracking = [&](int i) {
            if (i == n) {
                result.push_back(curr);
                return;
            }
            if (empty(curr) || curr.back() == '1') {
                curr.push_back('0');
                backtracking(i + 1);
                curr.pop_back();
            }
            curr.push_back('1');
            backtracking(i + 1);
            curr.pop_back();
        };

        backtracking(0);
        return result;
    }
};

// Time:  O(n * 2^n)
// Space: O(n * 2^n)
// bfs
class Solution2 {
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        vector<string> q = {""};
        for (int _ = 0; _ < n; ++_) {
            vector<string> new_q;
            for (const auto& x : q) {
                if (empty(x) || x.back() == '1') {
                    new_q.push_back(x + '0');
                }
                new_q.push_back(x + '1');
            }
            q = move(new_q);
        }
        return q;
    }
};
