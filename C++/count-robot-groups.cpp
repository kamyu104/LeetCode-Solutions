// Time:  O(n)
// Space: O(1)

// backward simulation, greedy
class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int result = 0, s = numeric_limits<int>::max();
        for (int i = size(position) - 1; i >= 0; --i) {
            if (i + 1 < size(position) && position[i + 1] - position[i] <= distance || speed[i] > s) {
                continue;
            }
            s = speed[i];
            ++result;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// mono stack
class Solution2 {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int result = 0;
        vector<int> stk;
        for (int i = 0; i < size(position); ++i) {
            if (i + 1 < size(position) && position[i + 1] - position[i] <= distance) {
                continue;
            }
            while (!empty(stk) && stk.back() > speed[i]) {
                stk.pop_back();
            }
            stk.emplace_back(speed[i]);
        }
        return size(stk);
    }
};
