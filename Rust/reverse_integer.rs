// Assuming only 32bit range integers.
fn reverse(num: i32) -> i32 {
    let base: i64 = 2;
    let upperbound = base.pow(31) - 1;
    let lowerbound = -base.pow(31);
    let mut input = num as i64;
    let mut result: i64 = 0;
    let mut digit: i64 = 0;
    while input != 0 {
        digit = input % 10;
        result = result * 10 + digit;
        input = input / 10;
    }
    if result > upperbound || result < lowerbound {
        return 0;
    }
    result as i32
}

#[test]
fn it_works() {
    let no = 133;
    assert_eq!(reverse(no), 331);
    assert_eq!(reverse(-65), -56);
    assert_eq!(reverse(1991), 1991);
}
