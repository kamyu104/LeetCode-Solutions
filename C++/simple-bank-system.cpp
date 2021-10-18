// Time:  ctor:     O(1)
//        transer:  O(1)
//        deposit:  O(1)
//        withdraw: O(1)
// Space: O(1)

class Bank {
public:
    Bank(vector<long long>& balance) : balance_(balance) {
        
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (1 <= account2 && account2 <= size(balance_) && withdraw(account1, money)) {
            return deposit(account2, money);
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if (1 <= account && account <= size(balance_)) {
            balance_[account - 1] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if (1 <= account && account <= size(balance_) && balance_[account - 1] >= money) {
            balance_[account - 1] -= money;
            return true;
        }
        return false;
    }

private:
    vector<long long>& balance_;
};
