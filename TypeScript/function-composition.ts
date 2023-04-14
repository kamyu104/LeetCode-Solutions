// Time:  O(n)
// Space: O(1)

type F = (x: number) => number;

function compose(functions: F[]): F {
    return (x: number) => functions.reduceRight((total: number, f: F) => f(total), x);
};
