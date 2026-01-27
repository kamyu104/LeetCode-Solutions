// Time:  ctor:             O(1)
//        addOrder:         O(1)
//        modifyOrder:      O(1)
//        cancelOrder:      O(1)
//        getOrdersAtPrice: O(n)
// Space: O(n)

// hash table
class OrderManagementSystem {
public:
    OrderManagementSystem() {
        
    }
    
    void addOrder(int orderId, string orderType, int price) {
        orders_[orderId] = {orderType, price, size(type_price_[orderType][price])};
        type_price_[orderType][price].emplace_back(orderId);
    }
    
    void modifyOrder(int orderId, int newPrice) {
        const auto orderType = get<0>(orders_[orderId]);
        cancelOrder(orderId);
        addOrder(orderId, orderType, newPrice);
    }
    
    void cancelOrder(int orderId) {
        const auto [orderType, price, i] = move(orders_[orderId]);
        auto& arr = type_price_[orderType][price];
        get<2>(orders_[arr.back()]) = i;
        swap(arr[i], arr.back());
        arr.pop_back();
        if (empty(type_price_[orderType][price])) {
            type_price_[orderType].erase(price);
            if (empty(type_price_[orderType])) {
                type_price_.erase(orderType);
            }
        }
        orders_.erase(orderId);
    }
    
    vector<int> getOrdersAtPrice(string orderType, int price) {
        return type_price_.count(orderType) && type_price_[orderType].count(price) ? type_price_[orderType][price] : vector<int>();
    }

private:
    unordered_map<int, tuple<string, int, int>> orders_;
    unordered_map<string, unordered_map<int, vector<int>>> type_price_;
};
