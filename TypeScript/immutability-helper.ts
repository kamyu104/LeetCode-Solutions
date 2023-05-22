// Time:  O(1)
// Space: O(1)

// proxy
type InputObj = Record<any, any> | Array<any>;

var makeMutations = (obj, lookup) => {
    return new Proxy(obj, {
        set(_, prop, value) {
            lookup[prop] = value;
            return true;
        },
        get(target, prop) {
            if (typeof obj[prop] === 'object' && obj[prop] !== null) {
                if (lookup[prop] === undefined) {
                    lookup[prop] = {};
                }
                return makeMutations(obj[prop], lookup[prop]);
            }
            return lookup[prop] !== undefined ? lookup[prop] : Reflect.get(target, prop);
        }
    });
};

class ImmutableHelper {
    #obj: InputObj;
    constructor(obj: InputObj) {
        this.#obj = obj;
    }
    
    produce(mutator: (obj: InputObj) => void) {
        var lookup = {};
        mutator(makeMutations(this.#obj, lookup));
        return lookup;
    }
}
