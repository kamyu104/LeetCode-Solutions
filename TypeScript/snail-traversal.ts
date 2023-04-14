// Time:  O(m * n)
// Space: O(1)

declare global {
  interface Array<T> {
    snail(rowsCount: number, colsCount: number): number[][];
  }
}

Array.prototype.snail = function(rowsCount: number, colsCount: number): number[][] {
    if (this.length !==  rowsCount * colsCount) {
        return [];
    }
    let result = Array(rowsCount).fill([]).map(() => []);
    for (let j = 0; j < this.length; j++) {
        const i = Math.floor(j / rowsCount);
        if(i % 2 === 0){
            result[j % rowsCount][i] = this[j];
        } else {
            result[(rowsCount  - 1) - j % rowsCount][i] = this[j];
        }
    }
    return result;
}
