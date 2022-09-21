// Time:  ctor:       O(t), t is the number of tables
//        insertRow:  O(l), l is the number of columns
//        deleteRow:  O(1)
//        selectCell: O(l)
// Space: O(n * l), n is the number of records

// hash table
class SQL {
public:
    SQL(vector<string>& names, vector<int>& columns) {
        for (int i = 0; i < size(names); ++i) {
            table_[names[i]].emplace_back(columns[i]);
        }
    }
    
    void insertRow(string name, vector<string> row) {
        row.emplace_back();  // soft delete
        table_[name].emplace_back(row);
    }
    
    void deleteRow(string name, int rowId) {
        table_[name][rowId].back() = "deleted";  // soft delete
    }
    
    string selectCell(string name, int rowId, int columnId) {
        return table_[name][rowId].back() != "deleted" ? table_[name][rowId][columnId - 1] : "";
    }

private:
    unordered_map<string, vector<vector<string>>> table_;
};
