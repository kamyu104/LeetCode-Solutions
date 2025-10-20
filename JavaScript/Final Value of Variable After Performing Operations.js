var finalValueAfterOperations = function (operations) {
    let x = 0;
    for (const op of operations) {
        if ("X++" === op || "++X" === op) {
            x++;
        } else {
            x--;
        }
    }
    return x;
};
