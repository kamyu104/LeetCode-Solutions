// Time:  O(1)
// Space: O(1)

// symbol
declare global { 
    interface Function {
      callPolyfill(context: Record<any, any>, ...args: any[]): any;
	}
}

Function.prototype.callPolyfill = function(context: any, ...args): any {
    const symbol = Symbol();
    context[symbol] = this;
    const result = context[symbol](...args);
    delete context[symbol];
    return result;
}
