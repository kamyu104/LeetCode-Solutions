function queryString(s: string, n: number): boolean {
    const reviewedNumber = new Set<number>();
    let current = n;
    while(current > 0) {
        if (!reviewedNumber.has(current)) {
            if (!s.includes(Number(current).toString(2))) {
                return false;
            }
            
            addMultiplesToSet(reviewedNumber, current);
        }
        
        current--;
    }
    return true;
};

function addMultiplesToSet(set: Set<number>, n: number): void {
    console.log(`Given: ${n}`);
    let num = n;
    do {
        console.log(`Adding number ${num}`);
        set.add(num);
        num = num >> 1;

        if (num === 0) {
            break;
        }
    } while(true);
}
