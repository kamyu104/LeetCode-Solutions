// Time:  O(n)
// Space: O(n)

class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int result = 1;
        while (!s_.empty() && s_.top().first <= price) {
            result += s_.top().second; s_.pop();
        }
        s_.emplace(price, result);
        return result;
    }
    
private:
    stack<pair<int, int>> s_;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
 
