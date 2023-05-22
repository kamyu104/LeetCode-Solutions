// Time:  O(1)
// Space: O(1)

// proxy
type Obj = Array<any> | Record<any, any>;

const forbiddenMethods = new Set(["pop", "push", "shift", "unshift", "splice", "sort", "reverse"]);

function makeImmutable(obj: Obj): Obj {
    return new Proxy(obj, {
        set(target, prop) {
            if (Array.isArray(target) && typeof prop === "string") {
                if (Number(prop) !== undefined) {
                    throw `Error Modifying Index: ${prop}`;
                }
            }
            throw `Error Modifying: ${prop.toString()}`;
        },
        get(target, prop) {
            if (typeof obj[prop] === 'object' && obj[prop] !== null) {
                return makeImmutable(obj[prop]);
            }
            if (forbiddenMethods.has(prop.toString())) {
                return () => {
                    throw `Error Calling Method: ${prop.toString()}`;
                }
            }
            return Reflect.get(target, prop);
        }
    });
};
