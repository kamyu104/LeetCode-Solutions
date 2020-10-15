// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        vector<int> profits;
        vector<pair<int, int>> v_p;
        for (int v = -1, p = -1; p + 1 < size(prices);)  {
            for (v = p + 1; v + 1 < size(prices); ++v) {
                if (prices[v] < prices[v + 1]) {
                    break;
                }
            };
            for (p = v; p + 1 < size(prices); ++p) {
                if (prices[p] > prices[p + 1]) {
                    break;
                }
            };            
            while (!empty(v_p) && (prices[v] < prices[v_p.back().first])) {  // not overlapped
                const auto [v, p] = move(v_p.back()); v_p.pop_back();
                profits.emplace_back(prices[p] - prices[v]);  // count [prices[v], prices[p]] interval
            }
            while (!empty(v_p) && (prices[p] >= prices[v_p.back().second])) {  // overlapped
                // prices[last_v] <= prices[v] <= prices[last_p] <= prices[p],
                // treat overlapped as [prices[v], prices[last_p]], [prices[last_v], prices[p]] intervals due to invariant max profit
                const auto [last_v, last_p] = move(v_p.back()); v_p.pop_back();
                profits.emplace_back(prices[last_p] - prices[v]);  // count [prices[v], prices[last_p]] interval
                v = last_v;  
            }
            v_p.emplace_back(v, p);  // keep [prices[last_v], prices[p]] interval to check overlapped
        }        
        while (!empty(v_p))  {
            const auto [v, p] = move(v_p.back()); v_p.pop_back();
            profits.emplace_back(prices[p] - prices[v]);  // count [prices[v], prices[p]] interval
        }
        if (k > size(profits)) {
            k = size(profits);
        }
        nth_element(begin(profits), begin(profits) + k, end(profits), greater<int>());
        return accumulate(cbegin(profits), cbegin(profits) + k, 0);  // top k intervals
    }
};
