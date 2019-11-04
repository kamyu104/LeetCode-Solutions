// Time:  O(n) ~ O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        vector<pair<int, int>> min_heap;
        for (const auto& slot : slots1) {
            if (slot[1] - slot[0] >= duration) {
                min_heap.emplace_back(slot[0], slot[1]);
            }
        }
        for (const auto& slot : slots2) {
            if (slot[1] - slot[0] >= duration) {
                min_heap.emplace_back(slot[0], slot[1]);
            }
        }
        make_heap(min_heap.begin(), min_heap.end(), greater<>());  // Time: O(n)
        while (min_heap.size() > 1) {
            pop_heap(min_heap.begin(), min_heap.end(), greater<>());  // Time: O(logn)
            const auto left = min_heap.back();
            min_heap.pop_back();
            pop_heap(min_heap.begin(), min_heap.end(), greater<>());
            const auto right = min_heap.back();
            min_heap.pop_back();
            min_heap.emplace_back(right);
            push_heap(min_heap.begin(), min_heap.end(), greater<>());
            if (left.second - right.first >= duration) {
                return {right.first, right.first + duration};
            }
        }
        return {};
    }
};

// Time:  O(nlogn)
// Space: O(n)
class Solution2 {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (const auto& slot : slots1) {
            if (slot[1] - slot[0] >= duration) {
                min_heap.emplace(slot[0], slot[1]);
            }
        }
        for (const auto& slot : slots2) {
            if (slot[1] - slot[0] >= duration) {
                min_heap.emplace(slot[0], slot[1]);
            }
        }
        while (min_heap.size() > 1) {
            const auto left = min_heap.top();
            min_heap.pop();
            const auto right = min_heap.top();
            if (left.second - right.first >= duration) {
                return {right.first, right.first + duration};
            }
        }
        return {};
    }
};

// Time:  O(nlogn)
// Space: O(n)
class Solution3 {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int i = 0, j = 0;
        while (i < slots1.size() && j < slots2.size()) {
            const auto& left = max(slots1[i][0], slots2[j][0]);
            const auto& right = min(slots1[i][1], slots2[j][1]);
            if (left + duration <= right) {
                return {left, left + duration};
            }
            if (slots1[i][1] < slots2[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        return {};
    }
};
