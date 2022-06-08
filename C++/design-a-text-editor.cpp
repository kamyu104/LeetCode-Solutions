// Time:  ctor:        O(1)
//        addText:     O(l)
//        deleteText:  O(k)
//        cursorLeft:  O(k)
//        cursorRight: O(k)
// Space: O(n)

// design, stack
class TextEditor {
public:
    TextEditor() {
        
    }
    
    void addText(string text) {
        left_ += text;
    }
    
    int deleteText(int k) {
        return move(k, &left_, nullptr);
    }
    
    string cursorLeft(int k) {
        move(k, &left_, &right_);
        return last_characters();
    }
    
    string cursorRight(int k) {
        move(k, &right_, &left_);
        return last_characters();
    }

private:
    int move(const int k, string *src, string *dst) {
        const int cnt = min(k, static_cast<int>(size(*src)));
        for (int _ = 0; _ < cnt; ++_) {
            if (dst) {
                dst->push_back(src->back());
            }
            src->pop_back();
        }
        return cnt;
    }

    string last_characters() {
        return left_.substr(max(static_cast<int>(size(left_)) - LAST_COUNT, 0), LAST_COUNT);
    }

    static const int LAST_COUNT = 10;
    string left_;
    string right_;
};
