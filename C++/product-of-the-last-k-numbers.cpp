// Time:  ctor: O(1)
//        add : O(1)
//        get : O(1)
// Space: O(n)

class ProductOfNumbers {
public:
    ProductOfNumbers()
      : accu_(1, 1) {
        
    }
    
    void add(int num) {
        if (!num) {
            accu_ = {1};
            return;
        }
        accu_.emplace_back(accu_.back() * num);
    }
    
    int getProduct(int k) {
        if (accu_.size() <= k) {
            return 0;
        }
        return accu_.back() / accu_[accu_.size() - 1 - k];
    }

private:
    vector<int> accu_;
};
