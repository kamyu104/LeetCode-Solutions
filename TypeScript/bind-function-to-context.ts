// Time:  O(1)
// Space: O(1)

// symbol
type Fn = (...args) => any

declare global {
    interface Function {
      bindPolyfill(obj: Record<any, any>): Fn;
    }
}

Function.prototype.bindPolyfill = function(obj : any) {
    const symbol = Symbol();
    obj[symbol] = this;
    return (...args) => {
        const result = obj[symbol](...args);
        delete obj[symbol];
        return result;
    }
}
