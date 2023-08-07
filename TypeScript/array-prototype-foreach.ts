// Time:  O(n)
// Space: O(1)

// symbol
Array.prototype.forEach = function(callback: Function, context: any): void {
    const symbol = Symbol();
    context[symbol] = callback;
    for (let i = 0; i < this.length; i++) {
        context[symbol](this[i], i, this);
    }
    delete context[symbol];
}

Array.prototype.forEach = function(callback: Function, context: any): void {
    for (let i = 0; i < this.length; i++) {
        callback.call(context, this[i], i, this);
    }
}
