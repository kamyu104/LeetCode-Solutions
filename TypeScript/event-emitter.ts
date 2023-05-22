// Time:  subscribe:   O(1)
//        unsubscribe: O(1)
//        emit:        O(n)
// Space: O(n)

type Callback = (...args: any[]) => any;
type Subscription = {
    unsubscribe: () => void
}

class EventEmitter {
    #lookup: Map<string, Callback[]>;
    constructor() {
        this.#lookup = new Map<string, Callback[]>();
    }

    subscribe(eventName: string, callback: Callback): Subscription {
        if (!this.#lookup.has(eventName)) {
            this.#lookup.set(eventName, []);
        }
        this.#lookup.get(eventName).push(callback);
        return {
            unsubscribe: () => {
                const i = this.#lookup.get(eventName).indexOf(callback);
                if (i !== -1) {
                    this.#lookup.get(eventName).splice(i, 1);
                }
            }
        };
    }

    emit(eventName: string, args: any[] = []): any {
        if (!this.#lookup.has(eventName)) {
            return [];
        }
        let result = [];
        for (const listener of this.#lookup.get(eventName)) {
            result.push(listener(...args));
        }
        return result;
    }
}
