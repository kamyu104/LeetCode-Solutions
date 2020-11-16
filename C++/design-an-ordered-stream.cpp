// Time:  O(1), amortized
// Space: O(n)

class OrderedStream {
public:
    OrderedStream(int n)
     : i_(0)
     , values_(n) {
        
    }
    
    vector<string> insert(int id, string value) {
        --id;
        values_[id] = value;
        vector<string> result;
        if (id != i_) {
            return result;
        }
        while (i_ < size(values_) && !empty(values_[i_])) {
            result.emplace_back(values_[i_++]);
        }
        return result;
    }

private:
    int i_;
    vector<string> values_;
};
