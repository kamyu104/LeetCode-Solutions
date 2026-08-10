fn rom_to_int(s: String) -> u32 {
    let table: Vec<(u32, &'static str)> = vec![
        (1000, "M"),
        (900, "CM"),
        (500, "D"),
        (400, "CD"),
        (100, "C"),
        (90, "XC"),
        (50, "L"),
        (40, "XL"),
        (10, "X"),
        (9, "IX"),
        (5, "V"),
        (4, "IV"),
        (1, "I"),
    ];
    let mut sum = 0;
    let mut i = 0;
    for t in table.iter() {
        while i + t.1.len() <= s.len() && t.1 == &s[i..i + t.1.len()] {
            i += t.1.len();
            sum += t.0;
            if i >= s.len() {
                return sum;
            }
        }
    }
    sum
}

#[test]
fn it_works() {
    assert_eq!(rom_to_int("LVIII".to_string()), 58);
    assert_eq!(rom_to_int("DCXXI".to_string()), 621);
    assert_eq!(rom_to_int("MDXIV".to_string()), 1514);
}
