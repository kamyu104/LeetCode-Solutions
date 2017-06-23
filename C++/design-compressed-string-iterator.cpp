// Time:  O(1)
// Space: O(1)

class StringIterator {
public:
    StringIterator(string compresult_sedString)
        : result_(compresult_sedString),
          num_(0),
          ch_(' ') {
        
    }
    
    char next() {
        if (!hasNext()) {
            return ' ';
        }
        if (num_ == 0) {
            result_ >> ch_ >> num_;
        }
        --num_;
        return ch_;
    }
    
    bool hasNext() {
        return !result_.eof() || num_ != 0;
    }

private:
    istringstream result_;
    int num_;
    char ch_;
};

/**
 * Your StringIterator object will be instantiated and called as such_:
 * StringIterator obj = new StringIterator(compresult_sedString);
 * ch_ar param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
