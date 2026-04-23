fn is_pair(open: char, close: char) -> bool {
    (open == '{' && close == '}') || (open == '[' && close == ']') || (open == '(' && close == ')')
}

fn is_valid(s: String) -> bool {
    let chars = s.chars().into_iter();
    let mut stack = Vec::new();
    for c in chars {
        match stack.last() {
            None => {}
            Some(&last) => {
                if is_pair(last, c) {
                    stack.pop();
                    continue;
                }
            }
        }
        stack.push(c);
    }
    stack.is_empty()
}

#[test]
fn it_works() {
    assert_eq!(is_valid("{}".to_string()), true);
    assert_eq!(is_valid("[]".to_string()), true);
    assert_eq!(is_valid("()".to_string()), true);
    assert_eq!(is_valid("".to_string()), true);
}
