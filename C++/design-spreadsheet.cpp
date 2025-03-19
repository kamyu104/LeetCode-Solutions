// Time:  ctor:      O(1)
//        setCell:   O(1)
//        resetCell: O(1)
//        getValue:  O(1)
// Space: O(n)

// hash table
class Spreadsheet {
public:
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        lookup_[cell] = value;
    }
    
    void resetCell(string cell) {
        lookup_.erase(cell);
    }
    
    int getValue(string formula) {
        const int i = formula.find('+');
        const auto& left = formula.substr(1, i - 1);
        const auto& right = formula.substr(i + 1);
        return value(left) + value(right);
    }

private:
    int value(const string& k) {
        return isalpha(k[0]) ? (lookup_.count(k) ? lookup_[k] : 0) : stoi(k);
    }

    unordered_map<string, int> lookup_;
};
