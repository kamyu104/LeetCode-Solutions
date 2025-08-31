var solveSudoku = function(board) {
    const isValid = (board, row, col, c) => {
        for (let i = 0; i < 9; i++) {
            if (board[row][i] === c) return false;
            if (board[i][col] === c) return false;
            if (board[3 * Math.floor(row / 3) + Math.floor(i / 3)]
                  [3 * Math.floor(col / 3) + (i % 3)] === c) return false;
        }
        return true;
    };

    const solve = (board) => {
        for (let i = 0; i < 9; i++) {
            for (let j = 0; j < 9; j++) {
                if (board[i][j] === ".") {
                    for (let c = 1; c <= 9; c++) {
                        let ch = c.toString();
                        if (isValid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (solve(board)) return true;
                            board[i][j] = ".";
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    };

    solve(board);
};
