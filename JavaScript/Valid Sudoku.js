var isValidSudoku = function(board) {
    const rows = Array.from({ length: 9 }, () => Array(9).fill(false));
    const cols = Array.from({ length: 9 }, () => Array(9).fill(false));
    const boxes = Array.from({ length: 9 }, () => Array(9).fill(false));

    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            if (board[i][j] !== '.') {
                let num = board[i][j].charCodeAt(0) - '1'.charCodeAt(0);
                let boxIndex = Math.floor(i / 3) * 3 + Math.floor(j / 3);

                if (rows[i][num] || cols[j][num] || boxes[boxIndex][num]) {
                    return false;
                }

                rows[i][num] = cols[j][num] = boxes[boxIndex][num] = true;
            }
        }
    }
    return true;
};
