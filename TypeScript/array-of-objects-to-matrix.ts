// Time:  O(l * mlogm + m * n)
// Space: O(l * m + m * n)

// iterative dfs
function jsonToMatrix(arr: any[]): (string | number | boolean | null)[][] {
    let row = new Array(arr.length).fill(null).map(() => new Map());
    let keys_set = new Set<string>();
    arr.forEach((x, i) => {
        const iter_dfs = (u: any, lookup: Map<string, (string | number | boolean | null)>) => {
            let stk = [[1, u, undefined]];
            let curr = []
            while (stk.length) {
                const [step, u, v] = stk.pop();
                if (step === 1) {
                    for (const v in u) {
                        stk.push([3, u, v]);
                        stk.push([2, u, v]);
                    }
                } else if (step === 2) {
                    curr.push(v);
                    if (!(u[v] !== null && (typeof u[v] === 'object' || Array.isArray(u[v])))) {
                        lookup.set(curr.join('.'), u[v]);
                    } else {
                        stk.push([1, u[v], null])
                    }
                } else if (step === 3) {
                    curr.pop();
                }
            }
        }

        iter_dfs(x, row[i]);
        for (const [k, _] of row[i].entries()) {
            keys_set.add(k);
        }
    });
    
    let result = [Array.from(keys_set).sort()];
    for (let i = 0; i < row.length; ++i) {
        result.push([])
        for (let j = 0; j < result[0].length; ++j) {
            result[i+1].push(row[i].has(result[0][j]) ? row[i].get(result[0][j]) : '');
        }
    }
    return result;
};

// Time:  O(l * mlogm + m * n)
// Space: O(l * m + m * n)
// dfs
function jsonToMatrix2(arr: any[]): (string | number | boolean | null)[][] {
    let row = new Array(arr.length).fill(null).map(() => new Map());
    let keys_set = new Set<string>();
    arr.forEach((x, i) => {
        const dfs = (u: any, curr: string[], lookup: Map<string, (string | number | boolean | null)>) => {
            for (const v in u) {
                curr.push(v);
                if (!(u[v] !== null && (typeof u[v] === 'object' || Array.isArray(u[v])))) {
                    lookup.set(curr.join('.'), u[v]);
                } else {
                    dfs(u[v], curr, lookup);
                }
                curr.pop();
            }
        };

        dfs(x, [], row[i]);
        for (const [k, _] of row[i].entries()) {
            keys_set.add(k);
        }
    });
    
    let result = [Array.from(keys_set).sort()];
    for (let i = 0; i < row.length; ++i) {
        result.push([])
        for (let j = 0; j < result[0].length; ++j) {
            result[i+1].push(row[i].has(result[0][j]) ? row[i].get(result[0][j]) : '');
        }
    }
    return result;
};
