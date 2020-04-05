// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> max_heap;
        if (a) {
            max_heap.emplace(a, 'a');
        }
        if (b) {
            max_heap.emplace(b, 'b');
        }
        if (c) {
            max_heap.emplace(c, 'c');
        }
        string result;
        while (!max_heap.empty()) {
            auto [count1, c1] = max_heap.top(); max_heap.pop();
            if (result.length() >= 2 &&
                result[result.length() - 2] == c1 &&
                result[result.length() - 1] == c1) {
                if (max_heap.empty()) {
                    return result;
                }
                auto [count2, c2] = max_heap.top(); max_heap.pop();
                result.push_back(c2);
                --count2;
                if (count2) {
                    max_heap.emplace(count2, c2);
                }
                max_heap.emplace(count1, c1);
                continue;
            }
            result.push_back(c1);
            --count1;
            if (count1) {
                max_heap.emplace(count1, c1);
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> choices = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        string result;
        for (int i = 0; i < a + b + c; ++i) {
            sort(begin(choices), end(choices), greater<pair<int, int>>());
            bool is_found = false;
            for (auto& kvp :choices) {
                if (kvp.first &&
                    (result.length() < 2 ||
                     result[result.length() - 2] != kvp.second ||
                     result[result.length() - 1] != kvp.second)) {
                    result.push_back(kvp.second);
                    --kvp.first;
                    is_found = true;
                    break;
                }
            }
            if (!is_found) {
                break;
            }
        }
        return result;
    }
};
