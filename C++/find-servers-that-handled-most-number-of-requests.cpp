// Time:  O(nlogk)
// Space: O(k)

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap_of_endtimes;
        priority_queue<int, vector<int>, greater<int>> min_heap_of_nodes_after_curr;
        priority_queue<int, vector<int>, greater<int>> min_heap_of_nodes_before_curr;
        for (int i = 0; i < k; ++i) {
            min_heap_of_nodes_before_curr.emplace(i);
        }
        vector<int> count(k);
        for (int i = 0; i < size(arrival); ++i) {
            if (i % k == 0) {
                min_heap_of_nodes_after_curr = move(min_heap_of_nodes_before_curr);
            }
            while (!empty(min_heap_of_endtimes) && min_heap_of_endtimes.top().first <= arrival[i]) {
                const auto [_, free] = min_heap_of_endtimes.top(); min_heap_of_endtimes.pop();
                if (free < i % k) {
                    min_heap_of_nodes_before_curr.emplace(free);
                } else {
                    min_heap_of_nodes_after_curr.emplace(free);
                }
            }
            auto& min_heap_of_candidates = !empty(min_heap_of_nodes_after_curr) ? min_heap_of_nodes_after_curr : min_heap_of_nodes_before_curr;
            if (empty(min_heap_of_candidates)) {
                continue;
            }
            const auto node = min_heap_of_candidates.top(); min_heap_of_candidates.pop();
            ++count[node];
            min_heap_of_endtimes.emplace(arrival[i] + load[i], node);
        }
        int max_count = *max_element(cbegin(count), cend(count));
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (count[i] == max_count) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};

// Time:  O(nlogk)
// Space: O(k)
class Solution2 {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap_of_endtimes;
        set<int> availables;
        for (int i = 0; i < k; ++i) {
            availables.emplace(i);
        }
        vector<int> count(k);
        for (int i = 0; i < size(arrival); ++i) {
            while (!empty(min_heap_of_endtimes) && min_heap_of_endtimes.top().first <= arrival[i]) {
                const auto [_, free] = min_heap_of_endtimes.top(); min_heap_of_endtimes.pop();
                availables.emplace(free);
            }
            if (empty(availables)) {
                continue;
            }
            auto it = availables.lower_bound(i % k);
            if (it == end(availables)) {
                it = begin(availables);
            }
            ++count[*it];
            min_heap_of_endtimes.emplace(arrival[i] + load[i], *it);
            availables.erase(it);
        }
        int max_count = *max_element(cbegin(count), cend(count));
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (count[i] == max_count) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};
