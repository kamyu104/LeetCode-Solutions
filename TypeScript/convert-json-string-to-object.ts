// Time:  O(n)
// Space: O(h)

// stack
function jsonParse(str: string): any {
    let stk = [];
    let result = null;
    let k = null;
    for (let i = 0; i < str.length; i++) {
        if (str[i] === "," || str[i] === ":") {
            continue;
        }
        if (str[i] === '{' || str[i] === '[') {
            let v = str[i] === '{' ? {} : [];
            if (result !== null) {
                if (k !== null) {
                    result[k] = v;
                    k = null;
                } else {
                    result.push(v);
                }
                stk.push(result);
            }
            result = v;
        } else if (str[i] === '}' || str[i] === ']') {
            if (stk.length !== 0) {
                result = stk.pop();
            }
        } else {
            let v;
            if (str[i] === '-' || ('0' <= str[i] && str[i] <= '9')) {
                let j = i;
                while (i + 1 < str.length && 
                       (str[i + 1] === '-' || ('0' <= str[i + 1] && str[i + 1] <= '9') || str[i + 1] === '.')) {
                    i++;
                }
                v = Number(str.substring(j, i + 1));
            } else if (str[i] === '"') {
                let j = i + 1;
                while (i + 1 < str.length && str[i + 1] !== '"') {
                    i++;
                }
                v = str.substring(j, i + 1);
                i++;
            } else {
                if (i + 3 < str.length && str.substring(i, i + 4) === "true") {
                    v = true;
                    i += 3;
                } else if (i + 4 < str.length && str.substring(i, i + 5) === "false") {
                    v = false;
                    i += 4;
                } else {
                    v = null;
                    i += 3;
                }
            }
            if (result === null) {
                result = v;
            } else if (str[i + 1] === ":") {
                k = v;
            } else if (k !== null) {
                result[k] = v;
                k = null;
            } else {
                result.push(v);
            }
        }
    }
    return result;
};
