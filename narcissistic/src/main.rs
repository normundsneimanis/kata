fn narcissistic(num: u64) -> bool {
    let num_str = num.to_string();
    let len = num_str.len();

    let mut total: u64 = 0;
    for letter in num_str.as_bytes() {
        total += u64::pow(*letter as u64 -  48, len as u32);
    }

    return total == num;
}

// fn narcissistic(num: u64) -> bool {
//     num == (num.to_string()
//         .chars()
//         .map(|x| x.to_digit(10).unwrap() as u64)
//         .map(|x| x.pow((num.to_string().len()) as u32)))
//         .sum::<u64>()
//
// }

fn main() {
    print!("{}", narcissistic(153));
}

