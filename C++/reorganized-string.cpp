// Time:  O(nloga) = O(n), a is the size of alphabet
// Space: O(a) = O(1)

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> counts;
        for (const auto& c : S) {
            ++counts[c];
        }
        if (any_of(counts.cbegin(), counts.cend(),
                  [&](const pair<char, int>& kvp) { 
                      return kvp.second > (S.length() + 1) / 2;
                  })) {
            return "";
        }

        string result;
        priority_queue<pair<int, char>> max_heap;
        for (const auto& kvp : counts) {
            max_heap.emplace(kvp.second, kvp.first);
        }
        while (max_heap.size() > 1) {
            char c1, c2;
            int count1, count2;
            tie(count1, c1) = max_heap.top(); max_heap.pop();
            tie(count2, c2) = max_heap.top(); max_heap.pop();
            if (result.empty() || c1 != result.back()) {
                result.push_back(c1);
                result.push_back(c2);
                if (count1 - 1 > 0) {
                    max_heap.emplace(count1 - 1, c1);
                }
                if (count2 - 1 > 0) {
                    max_heap.emplace(count2 - 1, c2);
                }
            }
        }
        return max_heap.empty() ? result : result + max_heap.top().second;
    }
};
