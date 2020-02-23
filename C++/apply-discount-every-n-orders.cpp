// Time:  ctor:    O(m), m is the number of all products
//        getBill: O(p), p is the number of products to bill
// Space: O(m)

class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices)
      : n_{n}
      , discount_{discount}
      , curr_{0}
    {
        for (int i = 0; i < products.size(); ++i) {
            lookup_[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        curr_ = (curr_ + 1) % n_;
        double result = 0.0;
        for (int i = 0; i < product.size(); ++i) {
            result += lookup_[product[i]] * amount[i];
        }
        return curr_ == 0 ? result * (1.0 - discount_ / 100.0) : result;
    }

private:
    int n_;
    int discount_;
    int curr_;
    unordered_map<int, int> lookup_;
};
