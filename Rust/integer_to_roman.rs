fn int_to_rom(num: u32) -> String {
    let table = vec![
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

    let mut num = num;
    let mut s = String::new();
    for t in table.iter() {
        if num >= t.0 {
            for _ in 0..(num / t.0) {
                s.push_str(t.1);
            }
            num = num % t.0;
        }
    }
    s
}

#[test]
fn it_works() {
    assert_eq!(int_to_rom(1), "I");
    assert_eq!(int_to_rom(8), "VIII");
    assert_eq!(int_to_rom(1999), "MCMXCIX");
    assert_eq!(int_to_rom(1994), "MCMXCIV");
    assert_eq!(int_to_rom(320), "CCCXX");
    println!("420: {}", int_to_rom(420));
    println!("3999 {}", int_to_rom(3999));
    println!("5000 {}", int_to_rom(5000));
    println!("4000 {}", int_to_rom(4000));
}
