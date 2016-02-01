// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) {
            return false;
        }
        Tokenizer tokens(preorder);
        int depth = 0; 
        for (int i = 0; i < tokens.size() - 1; ++i) {
            if (tokens.get_next() == "#") {
                --depth;
                if (depth < 0) {
                    return false;
                }
            } else {
                ++depth;
            }
        }
        return depth == 0 && tokens.get_next() == "#";  
    }

class Tokenizer {
    public:
        Tokenizer(const string& str) : str_(str), i_(0), cnt_(0) {
            size_ = count(str_.cbegin(), str_.cend(), ',') + 1;
        }

        string get_next() {
            string next;
            if (cnt_ < size_) {
                size_t j =  str_.find(",", i_);
                next = str_.substr(i_, j - i_);
                i_ = j + 1;
                ++cnt_;
            }
            return next;
        }

        size_t size() {
            return size_;
        }

    private:
        const string& str_;
        size_t size_;
        size_t cnt_;
        size_t i_;
    };
};
