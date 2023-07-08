// Time:  O(n)
// Space: O(n)

class QueryBatcher {
    #queryMultiple : (keys: string[]) => Promise<string[]>
    #t : number
    #last : number
    #pending : any[]

    constructor(queryMultiple: (keys: string[]) => Promise<string[]>, t: number) {
        this.#queryMultiple = queryMultiple;
        this.#t = t;
        this.#last = 0;
        this.#pending = [];
    }

    async getValue(key: string): Promise<string> {
        return new Promise((resolve) => {
            const curr = Date.now();
            const remain = Math.max((this.#t + this.#last) - curr, 0);
            this.#last = curr + remain;
            this.#pending.push({key, resolve});
            if (this.#pending.length === 1) {
                setTimeout(() => this.#processPending(), remain);
            }
        });
    }

    async #processPending() {
        this.#last = Date.now();
        const pending = this.#pending;
        this.#pending = [];

        const result = await this.#queryMultiple(pending.map((obj) => obj.key));
        pending.map((obj, i) => obj.resolve(result[i]));
    }
};
