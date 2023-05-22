// Time:  subscribe:   O(1)
//        unsubscribe: O(1)
//        emit:        O(n)
// Space: O(n)

type Callback = (...args: any[]) => any;
type Subscription = {
    unsubscribe: () => void
}

// ordered set
class EventEmitter {
    #lookup: Map<string, Set<Callback>>;
    constructor() {
        this.#lookup = new Map<string, Set<Callback>>();
    }

    subscribe(eventName: string, callback: Callback): Subscription {
        if (!this.#lookup.has(eventName)) {
            this.#lookup.set(eventName, new Set());
        }
        this.#lookup.get(eventName).add(callback);
        return {
            unsubscribe: () => {
                this.#lookup.get(eventName).delete(callback);
            }
        };
    }

    emit(eventName: string, args: any[] = []): any {
        if (!this.#lookup.has(eventName)) {
            return [];
        }
        let result = [];
        for (const callback of this.#lookup.get(eventName)) {
            result.push(callback(...args));
        }
        return result;
    }
}
