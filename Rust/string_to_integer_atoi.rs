fn atoi(s: String) -> i32 {
    let (i32_min, i32_max) = (-2_i64.pow(31), 2_i64.pow(31) - 1);
    let mut result: i64 = 0;
    let chars = s.chars().into_iter();
    let (mut minus, mut num_matched) = (false, false);
    for c in chars {
        if !num_matched {
            match c {
                ' ' => {}
                '-' => {
                    num_matched = true;
                    minus = true;
                }
                '0'..='9' => {
                    num_matched = true;
                    result = result * 10 + c.to_digit(10).unwrap() as i64;
                }
                '+' => {
                    num_matched = true;
                }
                _ => return 0,
            }
        } else {
            match c {
                '0'..='9' => {
                    result = result * 10 + c.to_digit(10).unwrap() as i64;
                    if result > i32_max {
                        break;
                    }
                }
                _ => break,
            }
        }
    }
    result = if minus { -result } else { result };
    if result > i32_max {
        return i32_max as i32;
    }
    if result < i32_min {
        return i32_min as i32;
    }
    return result as i32;
}

#[test]
fn it_works() {
    assert_eq!(atoi(String::from("32")), 32);
    assert_eq!(atoi("100".to_string()), 100);
    assert_eq!(atoi("bb".to_string()), 0);
    assert_eq!(atoi("-2147483647".to_string()), -2147483647);
    assert_eq!(atoi("2147483648".to_string()), 2147483647);
    assert_eq!(atoi("-2147483649".to_string()), -2147483648);
    assert_eq!(atoi(" ".to_string()), 0);
}
