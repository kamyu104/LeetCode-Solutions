class Solution {
public:
    
    bool isValid(vector<vector<char>>& board , int row , int col , int num){
        for(int i=0 ; i<9 ; i++){
            if(board[row][i]== '0'+num) return false ;
        }
        // col check
        for(int j=0 ; j<9 ; j++){
            if(board[j][col] == '0'+num) return false ;
        }

        // small 3x3 grid check
        int x = (row/3)*3 ;
        int y = (col/3)*3 ;

        for(int i=x ; i<x+3 ; i++){
            for(int j=y ; j<y+3 ; j++){
                if(board[i][j]=='0'+num) return false ;
            }
        }
        return true ;
    }

    bool helper(vector<vector<char>>& board , int row , int col){
        if(row == 9) return true ;
        if(col == 9) return helper(board , row+1 , 0) ;
        if(board[row][col] != '.') return helper(board , row , col+1) ;

        for(int i=1 ; i<=9 ; i++){
            if(isValid(board , row , col , i)){
                board[row][col] = '0' + i ;
                bool res = helper(board , row , col+1) ;
                if(res) return true ;
                board[row][col] = '.' ;
            }
        }
        return false ;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board , 0 , 0) ;
        return ;
    }
};
