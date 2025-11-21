

// fn narcissistic(num: u64) -> bool {
//     let num_str = num.to_string();
//     let len = num_str.len();
//
//     let mut total: u64 = 0;
//     for letter in num_str.as_bytes() {
//         total += u64::pow(*letter as u64 -  48, len as u32);
//     }
//
//     return total == num;
// }

// fn narcissistic(num: u64) -> bool {
//     num == (num.to_string()
//         .chars()
//         .map(|x| x.to_digit(10).unwrap() as u64)
//         .map(|x| x.pow((num.to_string().len()) as u32)))
//         .sum::<u64>()
//
// }


// fn digital_root(n: i64) -> i64 {
//     let mut res: i64 = n;
//     while res > 9 {
//         res = res.to_string().chars()
//             .map(|x| x.to_digit(10).unwrap() as i64).sum();
//     }
//
//     res
// }


// fn get_count(string: &str) -> usize {
//     let chars = vec!['a', 'e', 'i', 'o', 'u'];
//     let mut vowels_count = string.chars()
//         .map(|x| { if chars.contains(&x) {1} else { 0 }}).sum();
//
//     vowels_count
// }

// string longDivision(string number, int divisor)
// {
//     // As result can be very large store it in string
//     string ans;
//
//     // Find prefix of number that is larger
//     // than divisor.
//     int idx = 0;
//     int temp = number[idx] - '0';
//     while (idx<(number.size()-1)&&temp < divisor)
//         temp = temp * 10 + (number[++idx] - '0');
//
//     // Repeatedly divide divisor with temp. After
//     // every division, update temp to include one
//     // more digit.
//     while ((number.size()-1 )> idx) {
//         // Store result in answer i.e. temp / divisor
//         ans += (temp / divisor) + '0';
//
//         // Take next digit of number
//         temp = (temp % divisor) * 10 + number[++idx] - '0';
//     }
//
//     // If divisor is greater than number
//     if (ans.length() == 0)
//         return "0";
//
//     // else return ans
//     return ans;
// }


// fn string_multiplication(n1: Vec<u8>, n2: Vec<u8>) -> Vec<u8> {
//     let mut result: Vec<u8> = vec![0; n1.len() + n2.len()];
//
//     if result.len() > 6 {
//         println!("Normunds");
//     }
//
//     let mut i_n1 = 0usize;
//     let mut i_n2 = 0usize;
//     for i2 in (0..n2.len()).rev() {
//         let mut reminder = 0u8;
//         i_n2 = 0;
//         for i1 in (0..n1.len()).rev() {
//             let val = (n2[i2] - 48) * (n1[i1] - 48) + result[i_n1 + i_n2] + reminder;
//             reminder = val / 10;
//             result[i_n1 + i_n2] = val % 10;
//             i_n2 += 1;
//         }
//
//         if reminder > 0 {
//             result[i_n1 + i_n2] += reminder;
//         }
//
//         i_n1 += 1;
//     }
//
//     let mut remove_num = 0usize;
//     for i in (0..result.len()).rev() {
//         if result[i] == 0 {
//             remove_num += 1;
//         } else {
//             break
//         }
//     }
//
//     result = result[0..result.len()-remove_num].to_vec();
//     result.reverse();
//     for x in result.iter_mut() {
//         *x += 48;
//     };
//     if result.len() > 6 {
//         println!("Normunds2");
//     }
//     result
// }
//
// fn num_to_binary(number: Vec<u8>) -> Vec<u8> {
//     let div: i64 = 2;
//     let mut answer: String = String::new();
//     // let mut reminder: i64 = 0;
//
//     let mut idx = 0;
//     let mut temp = (number[idx] - 48) as i64;
//
//     while idx < number.len() - 1 && temp < div {
//         idx += 1;
//         temp = temp * 10 + (number[idx] as i64 - 48);
//     }
//
//     while number.len() > idx {
//         answer.push(char::from((temp % div) as u8 + 49));
//         idx += 1;
//         if idx < number.len() {
//             temp = (temp % div) * 10 + ((number[idx] - 48) as i64);
//         }
//     }
//
//     let mut number = temp;
//     while number != 0 {
//         answer.push(char::from((number % div) as u8));
//         number /= div;
//     }
//
//     if answer.len() == 0 {
//         return String::from("").as_bytes().to_vec();
//     }
//
//     let mut answer = answer.as_bytes().to_vec();
//     answer.reverse();
//     answer
// }
//
// fn str_to_binary(str1: Vec<u8>) -> Vec<u8> {
//     let mut str1 = str1.clone();
//     let mut binary1: Vec<u8> = vec![];
//     let mut reminder;
//     while str1.len() > 1 {
//         (str1, reminder) = long_division(str1, 2);
//         binary1.push(reminder.to_be_bytes().as_slice()[0])
//     }
//
//     let mut number = str1[0] - 48;
//     while number != 0 {
//         binary1.push(number % 2);
//         number /= 2;
//     }
//
//     binary1
// }
//
// fn binpow(a: Vec<u8>, b: Vec<u8>) -> Vec<u8> {
//     if b.len() == 1 && b[0] - 48 == 0 {
//         return vec![1+48];
//     }
//     let b_divided: Vec<u8>;
//     let remainder: i64;
//     (b_divided, remainder) = long_division(b.clone(), 2);
//     let res = binpow(a.clone(), b_divided.clone());
//     if remainder > 0 {
//         let tmp = string_multiplication(res.clone(), res.clone());
//         string_multiplication(tmp.clone(), a.clone())
//         // res * res * a
//     } else {
//         // res * res
//         string_multiplication(res.clone(), res.clone())
//     }
// }
//
//
// fn long_division(number: Vec<u8>, div: i64) -> (Vec<u8>, i64) {
//     let mut answer: String = String::new();
//     let mut reminder: i64 = 0;
//
//     let mut idx = 0;
//     let mut temp = (number[idx] - 48) as i64;
//
//     while idx < number.len() - 1 && temp < div {
//         idx += 1;
//         temp = temp * 10 + (number[idx] as i64 - 48);
//     }
//
//     while number.len() > idx {
//         answer.push(char::from((temp / div + 48) as u8));
//         reminder = temp % div;
//         idx += 1;
//         if idx < number.len() {
//             temp = (temp % div) * 10 + ((number[idx] - 48) as i64);
//         }
//     }
//
//     if answer.len() == 0 {
//         return (String::from("").as_bytes().to_vec(), 0);
//     }
//
//     (answer.as_bytes().to_vec(), reminder)
// }
//
//
// fn last_digit(str1: &str, str2: &str) -> i32 {
//     // let bin0 = binpow(str1.as_bytes().to_vec(), str2.as_bytes().to_vec());
//     // bin0[bin0.len()-1] as i32 - 48
//     // let bin1 = str_to_binary(str1.as_bytes().to_vec());  // Big endian
//     // let bin2 = str_to_binary(str2.as_bytes().to_vec());
//     // println!("{} {}", bin0[0], bin2[0]);
//     let str2 = str2.as_bytes().to_vec();
//     if str2.len() == 1 && str2[0] - 48 == 0 {
//         return 1;
//     }
//     let remainder: i64;
//     let div = 4;
//     (_, remainder) = long_division(str2, div);
//
//     let mapping = vec![
//         vec![0, 0, 0, 0],
//         vec![1, 1, 1, 1],
//         vec![4, 8, 6, 2],
//         vec![9, 7, 1, 3],
//         vec![6, 4, 6, 4],
//         vec![5, 5, 5, 5],
//         vec![6, 6, 6, 6],
//         vec![9, 3, 1, 7],
//         vec![4, 2, 6, 8],
//         vec![1, 9, 1, 9],
//     ];
//
//     let last_digit = (str1.as_bytes().to_vec()[str1.len()- 1usize] - 48) as usize;
//     let reminder2 = ((remainder + 2) % 4) as usize;
//     mapping[last_digit][reminder2]
// }



// fn main() {
//     // assert_eq!(long_division(vec![50], 2), (vec![49u8], 0));
//     // assert_eq!(long_division(vec![49], 2), (vec![48u8], 1));
//     // let res = string_multiplication(vec![49], vec![49, 48]);
//     // assert_eq!(get_count("abracadabra"), 5);
//     // last_digit("15", "23");
//     assert_eq!(last_digit("4", "0"), 1);
//     assert_eq!(last_digit("4", "1"), 4);
//     assert_eq!(last_digit("4", "2"), 6);
//     assert_eq!(last_digit("9", "7"), 9);
//     assert_eq!(last_digit("10","100000"), 0);
//     assert_eq!(last_digit("10","10000000000"), 0);
//     assert_eq!(last_digit("1606938044258990275541962092341162602522202993782792835301376",
//                           "2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376"), 6);
//     assert_eq!(last_digit("3715290469715693021198967285016729344580685479654510946723",
//                           "68819615221552997273737174557165657483427362207517952651"), 7);
//     println!("Hello, world!");
// }


// fn digitize(n: u64) -> Vec<u8> {
//     let mut n1 = n.to_string().as_bytes().to_vec();
//     n1.iter_mut().for_each(|x| { *x-=48 } );
//     n1.reverse();
//     n1
// }
//
// fn main() {
//     assert_eq!(digitize(348597), vec![7,9,5,8,4,3]);
//     assert_eq!(digitize(35231), vec![1,3,2,5,3]);
//     assert_eq!(digitize(0), vec![0]);
// }

// fn gcd(mut n: u64, mut m: u64) -> u64 {
//     assert!(n != 0 && m != 0);
//     while m != 0 {
//         if m < n {
//             std::mem::swap(&mut m, &mut n);
//         }
//         m %= n;
//     }
//     n
// }
//
// fn reduce_fraction(fraction: (u32, u32)) -> (u32, u32) {
//     let gcd1;
//     gcd1 = gcd(fraction.0 as u64, fraction.1 as u64) as u32;
//     (fraction.0/gcd1, fraction.1/gcd1)
// }
//
// fn dotest(f: (u32, u32), expected: (u32, u32)) {
//     const ERR_MSG: &str = "\nYour result (left) did not match the expected output (right)";
//     assert_eq!(reduce_fraction(f), expected, "{ERR_MSG} with fraction = {} / {}", f.0, f.1)
// }
//
// fn main() {
//     dotest((60, 20), (3, 1));
//     dotest((80, 120), (2, 3));
//     dotest((4, 2), (2, 1));
//     dotest((45, 120), (3, 8));
//     dotest((1000, 1), (1000, 1));
//     dotest((1, 1), (1, 1));
// }

// fn high_and_low(numbers: &str) -> String {
//     let mut high = i32::MIN;
//     let mut low = i32::MAX;
//     numbers.to_string().split(" ").for_each(
//         |x| {
//             let x_ = str::parse(x).unwrap();
//             if x_ > high {
//                 high = x_;
//             }
//             if x_ < low {
//                 low = x_;
//             }
//         }
//     );
//     String::from(format!("{high} {low}"))
// }
//
// fn main() {
//     assert_eq!("42 -9", high_and_low("8 3 -5 42 -1 0 0 -9 4 7 4 -4"));
//     assert_eq!("3 1", high_and_low("1 2 3"));
// }

// fn max_cost(matrix: &mut [Vec<u32>]) -> u32 {
//     let rows = matrix[0].len();
//     let cols = matrix.len();
//
//     for i in 1..rows {
//         matrix[i][0] += matrix[i - 1][0]
//     }
//
//     for j in 1..cols {
//         matrix[0][j] += matrix[0][j - 1];
//     }
//
//     for i in 1..rows {
//         for j in 1..cols {
//             matrix[i][j] +=
//                 std::cmp::max(matrix[i - 1][j - 1],
//                               std::cmp::max(matrix[i - 1][j], matrix[i][j - 1]));
//         }
//     }
//
//     matrix[rows - 1][cols - 1]
// }
//
//
// fn find_sum(matrix: &[Vec<u32>]) -> u32 {
//     let mut m: Vec<Vec<u32>> = matrix.iter().map(|v| v.clone()).collect();
//     max_cost(&mut m)
// }
//
// fn dotest(matrix: &[Vec<u32>], expected: u32) {
//     let actual = find_sum(matrix);
//     assert_eq!(actual, expected, "With matrix = {matrix:?}\nExpected {expected} but got {actual}")
// }
//
// fn main() {
//     dotest(&[vec![20, 20, 10, 10], vec![10, 20, 10, 10], vec![10, 20, 20, 20], vec![10, 10, 10, 20]], 140);
// }


// Naive solution
// fn elder_age(m: u64, n: u64, l: u64, t: u64) -> u64 {
//     let mut total = 0u64;
//     let mut subtract = 0u64;
//     let mut mx: Vec<u64> = vec![0; (n*m) as usize];
//     let mut tmp: u64;
//     for i in 0..m {
//         tmp = i;
//         mx[i as usize] = i;
//         total += tmp;
//         if tmp >= l {
//             subtract += l
//         }
//         if i < n {
//             mx[(i * m) as usize] = i;
//             tmp = i;
//             total += tmp;
//             if tmp >= l {
//                 subtract += l
//             }
//         }
//     }
//
//     for i in 1..m {
//         for j in 1..m {
//             if i < n {
//                 // println!("i: {} j: {}, {} {}", i, j, mx[j as usize], mx[(i * m) as usize]);
//                 mx[(m * i + j) as usize] = mx[j as usize] ^ mx[(i * m) as usize];
//                 tmp = i^j;
//                 total += tmp;
//                 if tmp >= l {
//                     subtract += l
//                 }
//             }
//         }
//     }
//
//     (mx.iter().sum::<u64>() - subtract) % t
//     // (total - subtract) % t
// }


// // Another naive solution, with recursion
// fn elder_age2(m: u64, n: u64, l: u64, rows: u64) -> u64 {
//     if m == n && n == 0 {
//         println!("{} {} {} ({}) (n==m==0)", m, n, rows, l);
//         return 0;
//     }
//     if n == 0 {
//         if m < l {
//             println!("{} {} {} ({}) (n==0 m<l): {}", m, n, rows, l, 0);
//             return 0;
//         } else {
//             println!("{} {} {} ({}) (n==0 (m-l)*rows): {}", m, n, rows, l, (m - l) * rows);
//             return (m - l) * rows;
//         }
//     }
//     if m == 0 {
//         if n < l {
//             println!("{} {} {} ({}) (m==0 m<l): {}", m, n, rows, l, 0);
//             return 0;
//         } else {
//             println!("{} {} {} ({}) (m==0 (n-l)*rows): {}", m, n, rows, l, (n - l) * rows);
//             return (n - l) * rows;
//         }
//     }
//     if m == n {
//         println!("{} {} {} ({}) (n==m =>> Recursing n-1)", m, n, rows, l);
//         return elder_age2(m, n-1, l, rows);
//     }
//     let mut ret = m^n;
//     if ret < l {
//         println!("{} {} {} ({}) (m^n {} < rows*l {}). Recursing n-1", m, n, rows, l, ret, 0);
//         ret = 0;
//     } else {
//         println!("{} {} {} ({}): {}. Recursing n-1", m, n, rows, l, ret * rows);
//         ret = ret - l;
//     }
//     return elder_age2(m, n-1, l, rows) + ret * rows;
// }
//
// fn elder_age(m: u64, n: u64, l: u64, t: u64) -> u64 {
//     let m2= std::cmp::max(m, n);
//     let n2 = std::cmp::min(m, n);
//     let mut ret2 = 0u64;
//     for mi in 0..n2 {
//         ret2 += elder_age2(mi, mi, l, 2);
//     }
//
//     if m2 > n2 {
//         println!("Additional sections");
//         for mi in n2..m2 {
//             println!("Entry {} {}", mi, n2-1);
//             ret2 += elder_age2(mi, n2-1, l, 1);
//         }
//     }
//     return ret2 % t;
// }

// fn main() {
//     // assert_eq!(elder_age(8, 5, 1, 100), 5);
//     // assert_eq!(elder_age(8, 8, 0, 100007), 224);
//     // assert_eq!(elder_age(25, 31, 0, 100007), 11925);
//     // assert_eq!(elder_age(5, 45, 3, 1000007), 4323);
//     assert_eq!(elder_age(31, 39, 7, 2345), 1586);
//     // assert_eq!(elder_age(545, 435, 342, 1000007), 808451);
//     //
//     // // You need to run this test very quickly before attempting the actual tests :)
//     // assert_eq!(elder_age(28827050410, 35165045587, 7109602, 13719506), 5456283);
// }

// fn summation(n: i32) -> i32 {
//     let mut s = 0i32;
//     for a in 0..=n {
//         s += a;
//     }
//     s
// }
//
// fn main() {
//     assert_eq!(summation(1), 1);
//     assert_eq!(summation(8), 36);
//     assert_eq!(summation(22), 253);
//     assert_eq!(summation(100), 5050);
//     assert_eq!(summation(213), 22791);
// }

// fn sort_numbers(arr: &Vec<i32>) -> Vec<i32> {
//     let mut a = arr.clone();
//     a.sort();
//     a
// }
//
// fn main() {
//     assert_eq!(sort_numbers(&vec![1, 2, 3, 10, 5]), vec![1, 2, 3, 5, 10]);
//     assert_eq!(sort_numbers(&vec![]), vec![]);
//     assert_eq!(sort_numbers(&vec![20, 2, 10]), vec![2, 10, 20]);
//     assert_eq!(sort_numbers(&vec![2, 20, 10]), vec![2, 10, 20]);
//     assert_eq!(sort_numbers(&vec![2, 10, 20]), vec![2, 10, 20]);
// }

// use pathfinding::prelude::astar;
// fn path_finder(maze: &str) -> bool {
//     let mut maze2: Vec<Vec<i32>> = vec![];
//
//     for line in maze.split('\n') {
//         let mut sv = vec![];
//         for c in line.chars() {
//             sv.push(match c {
//                 '.' => 1,
//                 'W' => 100,
//                 _ => {println!("Error matching char {}", c); -1}
//             });
//         }
//         maze2.push(sv);
//     }
//
//     fn successors2(maze2: &Vec<Vec<i32>>, x: i32, y: i32) -> Vec<((i32, i32), i32)> {
//         let mut res: Vec<((i32, i32), i32)> = vec![];
//         if y-1 >= 0 && maze2[x as usize][(y-1) as usize] == 1 {
//             res.push(((x, y-1), 1))
//         }
//         if  x-1 >= 0 && maze2[(x-1) as usize][y as usize] == 1 {
//             res.push(((x-1, y), 1))
//         }
//         if y < maze2[0].len() as i32 - 1 && maze2[x as usize][(y+1) as usize] == 1 {
//             res.push(((x, y+1), 1))
//         }
//         if x < maze2.len() as i32 - 1 && maze2[(x+1) as usize][y as usize] == 1 {
//             res.push(((x+1, y), 1))
//         }
//
//         res
//     }
//
//     let goal: (i32, i32) = (maze2.len() as i32-1, maze2[0].len() as i32-1);
//     let result = astar(&(0, 0),
//                        |&(x, y) | successors2(&maze2, x, y).into_iter(),
//                        |&(x, y)| ((goal.0.abs_diff(x) + goal.1.abs_diff(y)) / 3) as i32,
//                        |&p| p == goal);
//
//     match result {
//         Some(_) => true,
//         None => false
//     }
// }

// // non recursive solution, uses a Vec as stack
// fn path_finder(maze: &str) -> bool {
//     let mut maze = maze
//         .lines()
//         .map(|l| l.chars().collect())
//         .collect::<Vec<Vec<_>>>();
//     let max_n = maze.len() - 1;
//     let mut tries = vec![(0, 0)];
//     while let Some(pos @ (x, y)) = tries.pop() {
//         if pos == (max_n, max_n) {
//             return true;
//         } else if maze[x][y] == '.' {
//             maze[x][y] = 'B';
//             if x != 0 {
//                 tries.push((x - 1, y));
//             }
//             if x != max_n {
//                 tries.push((x + 1, y));
//             }
//             if y != 0 {
//                 tries.push((x, y - 1));
//             }
//             if y != max_n {
//                 tries.push((x, y + 1));
//             }
//         }
//     }
//     false
// }
//
// fn is_reachable(maze2: &mut Vec<Vec<char>>, i: usize, j: usize, ti: usize, tj: usize) -> bool {
//     println!("{} {}", i, j);
//     if ti == i && tj == j {
//         return true;
//     }
//     if i < maze2.len() - 1 && maze2[i+1][j] == '.' {
//         maze2[i+1][j] = ',';
//         if is_reachable(maze2, i+1, j, ti, tj) {
//             return true;
//         }
//     }
//     if j < maze2[0].len() - 1 && maze2[i][j+1] == '.' {
//         maze2[i][j+1] = ',';
//         if is_reachable(maze2, i, j+1, ti, tj) {
//             return true;
//         }
//     }
//     if i > 0 && maze2[i-1][j] == '.' {
//         maze2[i-1][j] = ',';
//         if is_reachable(maze2, i-1, j, ti, tj) {
//             return true;
//         }
//     }
//     if j > 0 && maze2[i][j-1] == '.' {
//         maze2[i][j-1] = ',';
//         if is_reachable(maze2, i, j-1, ti, tj) {
//             return true;
//         }
//     }
//
//     return false;
// }
//
// fn path_finder2(maze: &str) -> bool {
//     let mut maze2: Vec<Vec<char>> = maze.split('\n')
//         .map(|line| line.chars().collect()).collect();
//
//     let ti = maze2.len() - 1;
//     let tj = maze2[0].len() - 1;
//
//     is_reachable(&mut maze2, 0, 0, ti, tj)
// }
//
// fn test_maze(maze: &str, expect: bool) {
//     let actual = path_finder2(maze);
//
//     assert_eq!(actual, expect, "Test failed!\n\
//              Got:      {}\n\
//              Expected: {}\n\
//              Maze was: \n\
//              {}", actual, expect, maze);
// }
//
// fn main() {
//     test_maze("\
//         .W.\n\
//         .W.\n\
//         .W.\n\
//         ...\
//         ",
//               true,
//     );
//
//     test_maze("\
//         ......\n\
//         ......\n\
//         ......\n\
//         ......\n\
//         ......\n\
//         ......\
//         ",
//               true,
//     );
//
//     test_maze("\
//         ......\n\
//         ......\n\
//         ......\n\
//         ......\n\
//         .....W\n\
//         ....W.\
//         ",
//               false,
//     );
// }

// fn path_finder2(maze: &str) -> Option<u32> {
//     let mut maze: Vec<Vec<char>> = maze.split('\n')
//         .map(|line| line.chars().collect()).collect();
//
//     let mut tries = vec![(0, 0)];
//     let max_n = maze.len() - 1;
//     while let Some(pos @ (x, y)) = tries.pop() {
//         if pos == (max_n, max_n) {
//             return Some(2);
//         } else if maze[x][y] == '.' {
//             maze[x][y] = 'B';
//             if x != 0 {
//                 tries.push((x - 1, y));
//             }
//             if x != max_n {
//                 tries.push((x + 1, y));
//             }
//             if y != 0 {
//                 tries.push((x, y - 1));
//             }
//             if y != max_n {
//                 tries.push((x, y + 1));
//             }
//         }
//     }
//
//     None
//
// }

// Path Finder #2: shortest path
// fn is_reachable(maze2: &mut Vec<Vec<i32>>, i: usize, j: usize, ti: usize, tj: usize, depth: i32) {
//     if maze2[i][j] == -1 {
//         return;
//     }
//     if depth >= maze2[i][j] {
//         return;
//     }
//     if maze2[i][j] > depth {
//         maze2[i][j] = depth;
//     }
//     if i < ti {
//         is_reachable(maze2, i+1, j, ti, tj, depth+1);
//     }
//     if j < tj {
//         is_reachable(maze2, i, j+1, ti, tj, depth+1);
//     }
//     if i > 0 {
//         is_reachable(maze2, i-1, j, ti, tj, depth+1);
//     }
//     if j > 0 {
//         is_reachable(maze2, i, j-1, ti, tj, depth+1);
//     }
// }
// fn path_finder(maze: &str) -> Option<u32> {
//     let mut maze2: Vec<Vec<i32>> = maze.split('\n')
//         .map(|line| line.chars().map(|x| match x {
//             '.' => i32::MAX,
//             'W' => -1,
//             _ => {panic!("Invalid char occurred")}
//         }).collect()).collect();
//
//     let ti = maze2.len() - 1;
//     let tj = maze2[0].len() - 1;
//
//     is_reachable(&mut maze2, 0, 0, ti, tj, 0);
//     if maze2[ti][tj] != i32::MAX {
//         Some(maze2[ti][tj] as u32)
//     } else {
//         None
//     }
// }
// fn main() {
//     assert_eq!(path_finder(".W.\n.W.\n..."), Some(4), "\nYour answer (left) is not the expected answer (right).");
//     assert_eq!(path_finder(".W.\n.W.\nW.."), None, "\nYour answer (left) is not the expected answer (right).");
//     assert_eq!(path_finder("......\n......\n......\n......\n......\n......"), Some(10), "\nYour answer (left) is not the expected answer (right).");
//     assert_eq!(path_finder("......\n......\n......\n......\n.....W\n....W."), None, "\nYour answer (left) is not the expected answer (right).");
// }

// Path Finder #3: the Alpinist
// fn climb(maze2: &Vec<Vec<u32>>, res: &mut Vec<Vec<u32>>,
//                 i: usize, j: usize, max: usize, prev_height: u32, prev_climbed: u32) {
//     let height_diff = prev_height.abs_diff(maze2[i][j]);
//     let current_climbed = prev_climbed + height_diff;
//     if current_climbed >= res[i][j] {
//         return;
//     }
//     res[i][j] = current_climbed;
//     if i < max {
//         climb(maze2, res, i+1, j, max, maze2[i][j], current_climbed);
//     }
//     if j < max {
//         climb(maze2, res, i, j+1, max, maze2[i][j], current_climbed);
//     }
//     if i > 0 {
//         climb(maze2, res,i-1, j, max, maze2[i][j], current_climbed);
//     }
//     if j > 0 {
//         climb(maze2, res, i, j-1, max, maze2[i][j], current_climbed);
//     }
// }
// fn path_finder(maze: &Vec<Vec<u32>>) -> u32 {
//     let mut res: Vec<Vec<u32>> = vec![vec![u32::MAX; maze.len()]; maze.len()];
//     let max = maze.len() - 1;
//
//     climb(&maze, &mut res, 0, 0, max, maze[0][0], 0);
//     res[max][max]
// }
// fn main() {
//     fn test_equal(input: &[Vec<u32>], actual: u32, expected: u32) {
//         assert_eq!(actual, expected, "\nFor the input: {:?}\nYour result (left) did not match the expected output (right)", input);
//     }
//     // let area: Vec<Vec<u32>> = vec![
//     //     vec![0, 0, 0],
//     //     vec![0, 0, 0],
//     //     vec![0, 0, 0]
//     // ];
//     // test_equal(&area, path_finder(&area), 0);
//
//     // let area: Vec<Vec<u32>> = vec![
//     //     vec![0, 1, 0],
//     //     vec![0, 1, 0],
//     //     vec![0, 1, 0]
//     // ];
//     // test_equal(&area,path_finder(&area), 2);
//
//     let area: Vec<Vec<u32>> = vec![
//         vec![0, 1, 0],
//         vec![1, 0, 1],
//         vec![0, 1, 0]
//     ];
//     test_equal(&area,path_finder(&area), 4);
//
//     let area: Vec<Vec<u32>> = vec![
//         vec![0, 7, 0, 7],
//         vec![7, 0, 7, 0],
//         vec![0, 7, 0, 7],
//         vec![7, 0, 7, 0]
//     ];
//     test_equal(&area,path_finder(&area), 42);
//
//     let area: Vec<Vec<u32>> = vec![
//         vec![7, 0, 0, 0, 0, 0],
//         vec![0, 7, 7, 7, 7, 0],
//         vec![0, 7, 7, 7, 7, 0],
//         vec![0, 7, 7, 7, 7, 0],
//         vec![0, 7, 7, 7, 7, 0],
//         vec![0, 0, 0, 0, 0, 7]
//     ];
//     test_equal(&area,path_finder(&area), 14);
//
//     let area: Vec<Vec<u32>> = vec![
//         vec![7, 7, 7, 0, 0, 0],
//         vec![0, 0, 7, 0, 0, 0],
//         vec![0, 0, 7, 0, 0, 0],
//         vec![0, 0, 7, 0, 0, 0],
//         vec![0, 0, 7, 0, 0, 0],
//         vec![0, 0, 7, 7, 7, 7]
//     ];
//     test_equal(&area,path_finder(&area), 0);
//
//     let area: Vec<Vec<u32>> = vec![
//         vec![0, 0, 0, 0, 0, 0],
//         vec![0, 0, 0, 0, 0, 0],
//         vec![0, 0, 0, 0, 0, 0],
//         vec![0, 0, 0, 0, 1, 0],
//         vec![0, 0, 0, 1, 0, 9],
//         vec![0, 0, 1, 0, 1, 0]
//     ];
//     test_equal(&area,path_finder(&area), 4);
// }

// 4A - Watermelon
// use std::io;
// fn main() -> io::Result<()> {
//     let mut buffer = String::new();
//     io::stdin().read_line(&mut buffer)?;
//
//     let num: i32 = buffer.trim().parse().expect("Number required as input");
//
//     if num > 2 && num % 2 == 0 {
//         println!("YES");
//     } else {
//         println!("NO");
//     }
//
//     Ok(())
// }

// A. Way Too Long Words
// fn main() {
//     for line in std::io::stdin().lines() {
//         if line.is_err() {
//             return;
//         }
//         let line = line.unwrap().trim().to_string();
//         if line.len() == 0 {
//             return;
//         } else if line.parse::<u64>().is_ok()  {
//             continue
//         } else if line.len() <= 10 {
//             println!("{}", line);
//         } else {
//             println!("{}{}{}", char::from(line.as_bytes()[0usize]), line.len() - 2, char::from(line.as_bytes()[line.len() - 1]));
//         }
//     }
// }

// 231A	Team
// fn main() {
//     let mut total_completed = 0;
//     let mut total: u64 = 100;
//     let mut tested = 0;
//
//     for line in std::io::stdin().lines() {
//         if line.is_err() {
//             break;
//         }
//
//         let line = line.unwrap().trim().to_string();
//         if line.len() == 0 {
//             break;
//         } else if line.parse::<u64>().is_ok()  {
//             total = line.parse::<u64>().unwrap();
//         } else {
//             let c: u8 = line.split(' ').map(|x| x.parse::<u8>().unwrap()).collect::<Vec<_>>().iter().sum();
//             if c >= 2 {
//                 total_completed += 1;
//             }
//             tested += 1;
//             if tested == total {
//                 break
//             }
//         }
//     }
//
//     println!("{}", total_completed);
// }


// fn long_division(number: Vec<u8>, div: i64) -> (Vec<u8>, i64) {
//     let mut answer: String = String::new();
//     let mut reminder: i64 = 0;
//
//     let mut idx = 0;
//     let mut temp = (number[idx] - 48) as i64;
//
//     while idx < number.len() - 1 && temp < div {
//         idx += 1;
//         temp = temp * 10 + (number[idx] as i64 - 48);
//     }
//
//     while number.len() > idx {
//         answer.push(char::from((temp / div + 48) as u8));
//         reminder = temp % div;
//         idx += 1;
//         if idx < number.len() {
//             temp = (temp % div) * 10 + ((number[idx] - 48) as i64);
//         }
//     }
//
//     if answer.len() == 0 {
//         return (String::from("").as_bytes().to_vec(), 0);
//     }
//
//     (answer.as_bytes().to_vec(), reminder)
// }
//
//
// fn last_digit(str1: &str, str2: &str) -> i32 {
//     let str2 = str2.as_bytes().to_vec();
//     if str2.len() == 1 && str2[0] - 48 == 0 {
//         return 1;
//     }
//     let remainder: i64;
//     let div = 4;
//     (_, remainder) = long_division(str2, div);
//
//     let mapping = vec![
//         vec![0, 0, 0, 0],
//         vec![1, 1, 1, 1],
//         vec![4, 8, 6, 2],
//         vec![9, 7, 1, 3],
//         vec![6, 4, 6, 4],
//         vec![5, 5, 5, 5],
//         vec![6, 6, 6, 6],
//         vec![9, 3, 1, 7],
//         vec![4, 2, 6, 8],
//         vec![1, 9, 1, 9],
//     ];
//
//     let last_digit = (str1.as_bytes().to_vec()[str1.len()- 1usize] - 48) as usize;
//     let reminder2 = ((remainder + 2) % 4) as usize;
//     mapping[last_digit][reminder2]
// }

// https://stackoverflow.com/questions/33818141/how-do-i-pass-disjoint-slices-from-a-vector-to-different-threads
// use std::sync::{Arc, Mutex};
// use std::time::Instant;
// fn max_sum2(arr: &[i32], ranges: &[(usize, usize)]) -> i32 {
//     let num_cpus = std::thread::available_parallelism().unwrap().get();
//     let sums: Arc<Mutex<Vec<i32>>> = Arc::new(Mutex::new(vec![]));
//     let shared = Arc::new(arr);
//     // println!("{} cpus, {}, {}", num_cpus, arr.len(), ranges.len());
//     let time_spent: Arc<Mutex<Vec<u128>>> = Arc::new(Mutex::new(vec![]));  // usize, usize,
//
//     for range in ranges.chunks(num_cpus) {
//         let shared2 = Arc::clone(&shared);
//         let range = Arc::new(range);
//         std::thread::scope(|s| {
//             for (start, end) in *range {
//                 s.spawn(|| {
//                     let st = Instant::now();
//                     let s = shared2[*start..=*end].iter().sum::<i32>();
//                     // println!("{}..{}: {}", *start, *end, s);
//                     sums.lock().unwrap().push(s);
//                     time_spent.lock().unwrap().push(st.elapsed().as_nanos());
//                 });
//             }
//         });
//     }
//
//     let min = *time_spent.lock().unwrap().iter().min().expect("asd");
//     let max = *time_spent.lock().unwrap().iter().max().expect("asd2");
//     println!("{}, {}", min, max);
//     let ret = *sums.lock().unwrap().iter().max().expect("elements");
//     ret
// }


// use std::collections::HashMap;
// // Loop unrolling and minimizing amount of ranges to test
// use std::sync::{Arc, Mutex};
// use std::time::Instant;
// fn max_sum(arr: &[i32], ranges: &[(usize, usize)]) -> i32 {
//     let num_cpus = std::thread::available_parallelism().unwrap().get();
//     let sums: Arc<Mutex<Vec<i32>>> = Arc::new(Mutex::new(vec![]));
//     let shared = Arc::new(arr);
//     println!("{} cpus, {}, {}", num_cpus, arr.len(), ranges.len());
//     // let time_spent: Arc<Mutex<Vec<u128>>> = Arc::new(Mutex::new(vec![]));  // usize, usize,
//     let mut ranges2: Vec<(usize, usize)> = ranges.to_vec();
//     ranges2.sort_by(|a, b| (a.1 - a.0).cmp(&(b.1 - b.0)));
//     // if ranges2.len() >= 6000 {
//     //     ranges2 = ranges2[(ranges2.len() as f32 *0.15) as usize..(ranges2.len() as f32 *0.95) as usize].to_owned();
//     // }
//
//
//     // Find ranges that are inside other ranges
//     //let search_start = Instant::now();
//     //let mut inranges: HashMap<(usize, usize), i32> = HashMap::new();
//     //for range1_ in &ranges2[(ranges2.len() as f32 *0.5) as usize..] {
//     //    for range2_ in &ranges2[(ranges2.len() as f32 *0.8) as usize..] {
//     //        if range1_.0 > range2_.0 && range1_.1 < range2_.1 {
//     //            let rn = (range1_.0, range1_.1);
//     //            if !inranges.contains_key(&rn) {
//     //                // println!("range [{}:{}] ({}) elements", range1_.0, range1_.1, range1_.1 - range1_. 0);
//     //                inranges.insert(rn, i32::MIN);
//     //            }
//     //        }
//     //    }
//     //}
//     //println!("Search for {} ranges took {}", inranges.len(), search_start.elapsed().as_secs_f64());
//     // Calculate them first
//     // Calculate all other ranges, but include ranges that are calculated previously.
//
//     for range in ranges2.chunks(num_cpus) {
//         let shared2 = Arc::clone(&shared);
//         let range = Arc::new(range);
//         std::thread::scope(|s| {
//             for (start, end) in *range {
//                 s.spawn(|| {
//                     // let st = Instant::now();
//                     // let s = shared2[*start..=*end].iter().sum::<i32>();
//                     let mut s = 0i32;
//                     // let mut ni = 0;
//                     // let perc = ((*end - *start) as f32 * 0.1) as i32;
//                     for c in shared2[*start..=*end].chunks(128) {
//                         if c.len() == 128 {
//                             // ni += 1;
//                             s += c[0] + c[1] + c[2] + c[3] + c[4]  + c[5] + c[6] + c[7] + c[8] + c[9] + c[10] + c[11] + c[12] + c[13] + c[14] + c[15] + c[16] + c[17] + c[18] + c[19] + c[20] + c[21] + c[22] + c[23] + c[24] + c[25] + c[26] + c[27] + c[28] + c[29] + c[30] + c[31] + c[32] + c[33] + c[34] + c[35] + c[36] + c[37] + c[38] + c[39] + c[40] + c[41] + c[42] + c[43] + c[44] + c[45] + c[46] + c[47] + c[48] + c[49] + c[50] + c[51] + c[52] + c[53] + c[54] + c[55] + c[56] + c[57] + c[58] + c[59] + c[60] + c[61] + c[62] + c[63] + c[64] + c[65] + c[66] + c[67] + c[68] + c[69] + c[70] + c[71] + c[72] + c[73] + c[74] + c[75] + c[76] + c[77] + c[78] + c[79] + c[80] + c[81] + c[82] + c[83] + c[84] + c[85] + c[86] + c[87] + c[88] + c[89] + c[90] + c[91] + c[92] + c[93] + c[94] + c[95] + c[96] + c[97] + c[98] + c[99] + c[100] + c[101] + c[102] + c[103] + c[104]  + c[105] + c[106] + c[107] + c[108] + c[109] + c[110] + c[111] + c[112] + c[113] + c[114] + c[115] + c[116] + c[117] + c[118] + c[119] + c[120] + c[121] + c[122] + c[123] + c[124] + c[125] + c[126] + c[127];
//                     // + c[128] + c[129] + c[130] + c[131] + c[132] + c[133] + c[134] + c[135] + c[136] + c[137] + c[138] + c[139] + c[140] + c[141] + c[142] + c[143] + c[144] + c[145] + c[146] + c[147] + c[148] + c[149] + c[150] + c[151] + c[152] + c[153] + c[154] + c[155] + c[156] + c[157] + c[158] + c[159] + c[160] + c[161] + c[162] + c[163] + c[164] + c[165] + c[166] + c[167] + c[168] + c[169] + c[170] + c[171] + c[172] + c[173] + c[174] + c[175] + c[176] + c[177] + c[178] + c[179] + c[180] + c[181] + c[182] + c[183] + c[184] + c[185] + c[186] + c[187] + c[188] + c[189] + c[190] + c[191] + c[192] + c[193] + c[194] + c[195] + c[196] + c[197] + c[198] + c[199] + c[200] + c[201] + c[202] + c[203] + c[204] + c[205] + c[206] + c[207] + c[208] + c[209] + c[210] + c[211] + c[212] + c[213] + c[214] + c[215] + c[216] + c[217] + c[218] + c[219] + c[220] + c[221] + c[222] + c[223] + c[224] + c[225] + c[226] + c[227] + c[228] + c[229] + c[230] + c[231] + c[232] + c[233] + c[234] + c[235] + c[236] + c[237] + c[238] + c[239] + c[240] + c[241] + c[242] + c[243] + c[244] + c[245] + c[246] + c[247] + c[248] + c[249] + c[250] + c[251] + c[252] + c[253] + c[254] + c[255];
//                     //         if ni > perc && sums.lock().unwrap().len() > 10 &&
//                     //             s < *sums.lock().unwrap().iter().max().unwrap() / 2 {
//                     //             break
//                     //         }
//                         } else {
//                             s += c.iter().sum::<i32>();
//                         }
//                     }
//                     // println!("{}..{}: {}", *start, *end, s);
//                     sums.lock().unwrap().push(s);
//                     // time_spent.lock().unwrap().push(st.elapsed().as_nanos());
//                 });
//             }
//         });
//     }
//
//     // let min = *time_spent.lock().unwrap().iter().min().expect("asd");
//     // let max = *time_spent.lock().unwrap().iter().max().expect("asd2");
//     // println!("{}, {}", min, max);
//     let ret = *sums.lock().unwrap().iter().max().expect("elements");
//     ret
// }
//
//
// use std::sync::{Arc, Mutex};
// // use std::time::Instant;
// fn max_sum(arr: &[i32], ranges: &[(usize, usize)]) -> i32 {
//     let num_cpus = std::thread::available_parallelism().unwrap().get();
//     let sums: Arc<Mutex<Vec<i32>>> = Arc::new(Mutex::new(vec![]));
//     let ranges_search: Arc<Mutex<Vec<(usize, usize, i32)>>> = Arc::new(Mutex::new(vec![]));
//     let shared = Arc::new(arr);
//     println!("{} cpus, {}, {}", num_cpus, arr.len(), ranges.len());
//     // let time_spent: Arc<Mutex<Vec<u128>>> = Arc::new(Mutex::new(vec![]));  // usize, usize,
//     // let mut ranges2: Vec<(usize, usize)> = ranges.to_vec();
//     // ranges2.sort_by(|a, b| (a.1 - a.0).cmp(&(b.1 - b.0)));
//     // if ranges2.len() >= 6000 {
//     //     ranges2 = ranges2[(ranges2.len() as f32 *0.18) as usize..(ranges2.len() as f32 *0.82) as usize].to_owned();
//     // }
//
//     let mut ranges3: Vec<(usize, usize)> = vec![];
//     let search_range = arr.len() / 10  as usize;
//     for i in 0..arr.len()-search_range {
//         ranges3.push((i, i+search_range))
//     }
//
//     println!("ranges3: {}", ranges3.len());
//
//     for range in ranges3.chunks(num_cpus) {
//         let shared2 = Arc::clone(&shared);
//         let range = Arc::new(range);
//         std::thread::scope(|s| {
//             for (start, end) in *range {
//                 s.spawn(|| {
//                     let mut s = 0i32;
//                     for c in shared2[*start..=*end].chunks(128) {
//                         if c.len() == 128 {
//                             s += c[0] + c[1] + c[2] + c[3] + c[4]  + c[5] + c[6] + c[7] + c[8] + c[9] + c[10] + c[11] + c[12] + c[13] + c[14] + c[15] + c[16] + c[17] + c[18] + c[19] + c[20] + c[21] + c[22] + c[23] + c[24] + c[25] + c[26] + c[27] + c[28] + c[29] + c[30] + c[31] + c[32] + c[33] + c[34] + c[35] + c[36] + c[37] + c[38] + c[39] + c[40] + c[41] + c[42] + c[43] + c[44] + c[45] + c[46] + c[47] + c[48] + c[49] + c[50] + c[51] + c[52] + c[53] + c[54] + c[55] + c[56] + c[57] + c[58] + c[59] + c[60] + c[61] + c[62] + c[63] + c[64] + c[65] + c[66] + c[67] + c[68] + c[69] + c[70] + c[71] + c[72] + c[73] + c[74] + c[75] + c[76] + c[77] + c[78] + c[79] + c[80] + c[81] + c[82] + c[83] + c[84] + c[85] + c[86] + c[87] + c[88] + c[89] + c[90] + c[91] + c[92] + c[93] + c[94] + c[95] + c[96] + c[97] + c[98] + c[99] +
//                                 c[100] + c[101] + c[102] + c[103] + c[104]  + c[105] + c[106] + c[107] + c[108] + c[109] + c[110] + c[111] + c[112] + c[113] + c[114] + c[115] + c[116] + c[117] + c[118] + c[119] + c[120] + c[121] + c[122] + c[123] + c[124] + c[125] + c[126] + c[127];
//                         } else {
//                             s += c.iter().sum::<i32>();
//                         }
//                     }
//                     ranges_search.lock().unwrap().push((*start, *end, s));
//                 });
//             }
//         });
//     }
//
//     let max_ = ranges_search.lock().unwrap();
//     let max = max_.iter().max_by_key(|x| x.2).unwrap();
//     return arr[max.0..=max.1].iter().sum::<i32>();
//
//     // for range in ranges2.chunks(num_cpus) {
//     //     let shared2 = Arc::clone(&shared);
//     //     let range = Arc::new(range);
//     //     std::thread::scope(|s| {
//     //         for (start, end) in *range {
//     //             s.spawn(|| {
//     //                 // let st = Instant::now();
//     //                 // let s = shared2[*start..=*end].iter().sum::<i32>();
//     //                 let mut s = 0i32;
//     //                 for c in shared2[*start..=*end].chunks(128) {
//     //                     if c.len() == 128 {
//     //                         s += c[0] + c[1] + c[2] + c[3] + c[4]  + c[5] + c[6] + c[7] + c[8] + c[9] + c[10] + c[11] + c[12] + c[13] + c[14] + c[15] + c[16] + c[17] + c[18] + c[19] + c[20] + c[21] + c[22] + c[23] + c[24] + c[25] + c[26] + c[27] + c[28] + c[29] + c[30] + c[31] + c[32] + c[33] + c[34] + c[35] + c[36] + c[37] + c[38] + c[39] + c[40] + c[41] + c[42] + c[43] + c[44] + c[45] + c[46] + c[47] + c[48] + c[49] + c[50] + c[51] + c[52] + c[53] + c[54] + c[55] + c[56] + c[57] + c[58] + c[59] + c[60] + c[61] + c[62] + c[63] + c[64] + c[65] + c[66] + c[67] + c[68] + c[69] + c[70] + c[71] + c[72] + c[73] + c[74] + c[75] + c[76] + c[77] + c[78] + c[79] + c[80] + c[81] + c[82] + c[83] + c[84] + c[85] + c[86] + c[87] + c[88] + c[89] + c[90] + c[91] + c[92] + c[93] + c[94] + c[95] + c[96] + c[97] + c[98] + c[99] +
//     //                             c[100] + c[101] + c[102] + c[103] + c[104]  + c[105] + c[106] + c[107] + c[108] + c[109] + c[110] + c[111] + c[112] + c[113] + c[114] + c[115] + c[116] + c[117] + c[118] + c[119] + c[120] + c[121] + c[122] + c[123] + c[124] + c[125] + c[126] + c[127];
//     //                         // + c[128] + c[129] + c[130] + c[131] + c[132] + c[133] + c[134] + c[135] + c[136] + c[137] + c[138] + c[139] + c[140] + c[141] + c[142] + c[143] + c[144] + c[145] + c[146] + c[147] + c[148] + c[149] + c[150] + c[151] + c[152] + c[153] + c[154] + c[155] + c[156] + c[157] + c[158] + c[159] + c[160] + c[161] + c[162] + c[163] + c[164] + c[165] + c[166] + c[167] + c[168] + c[169] + c[170] + c[171] + c[172] + c[173] + c[174] + c[175] + c[176] + c[177] + c[178] + c[179] + c[180] + c[181] + c[182] + c[183] + c[184] + c[185] + c[186] + c[187] + c[188] + c[189] + c[190] + c[191] + c[192] + c[193] + c[194] + c[195] + c[196] + c[197] + c[198] + c[199]
//     //                     } else {
//     //                         s += c.iter().sum::<i32>();
//     //                     }
//     //                 }
//     //                 // println!("{}..{}: {}", *start, *end, s);
//     //                 sums.lock().unwrap().push(s);
//     //                 // time_spent.lock().unwrap().push(st.elapsed().as_nanos());
//     //             });
//     //         }
//     //     });
//     // }
//     //
//     // // let min = *time_spent.lock().unwrap().iter().min().expect("asd");
//     // // let max = *time_spent.lock().unwrap().iter().max().expect("asd2");
//     // // println!("{}, {}", min, max);
//     // let ret = *sums.lock().unwrap().iter().max().expect("elements");
//     // ret
// }
//
// // fn max_sum(a: &[i32], ranges: &[(usize, usize)]) -> i32 {
// //     let mut acc = vec![0; a.len() + 1];
// //     for (i, n) in a.iter().enumerate() {
// //         acc[i+1] = acc[i] + n;
// //     }
// //     let mut max = i32::MIN;
// //     for (i, j) in ranges.iter() {
// //         if acc[*j+1] - acc[*i] > max {
// //             max = acc[*j+1] - acc[*i];
// //         }
// //     }
// //
// //     max
// // }
//
// fn max_sum(a: &[i32], ranges: &[(usize, usize)]) -> i32 {
//     let mut acc = vec![0; a.len() + 1];
//     a.iter().enumerate().for_each(|(i, n)| acc[i + 1] = acc[i] + n);
//     ranges.iter().map(|(i, j)| acc[*j + 1] - acc[*i]).max().unwrap()
// }
//
// fn main() {
//     fn dotest(a: &[i32], ranges: &[(usize, usize)], expected: i32) {
//         let actual = max_sum(a, ranges);
//         assert!(actual == expected, "Test failed with arr = {a:?}, ranges = {ranges:?}\nExpected {expected} but got {actual}")
//     }
//
//     dotest(&[1, -2, 3, 4, -5, -4, 3, 2, 1], &[(1, 3), (0, 4), (6, 8)], 6);
//     dotest(&[1, -2, 3, 4, -5, -4, 3, 2, 1], &[(1, 3)], 5);
//     dotest(&[1, -2, 3, 4, -5, -4, 3, 2, 1], &[(1, 4), (2, 5)], 0);
// }

// fn snail2(matrix: &Vec<Vec<i32>>) -> Vec<i32> {
//     let mut result: Vec<i32> = vec![];
//     if matrix.len() == 0 {
//         return result;
//     } else if matrix[0].len() == 0 {
//         return result;
//     } else if matrix.len() == 1 {
//         result.push(matrix[0][0]);
//         return result;
//     }
//     result.extend(matrix[0].iter());
//     for i in 1..matrix.len() - 1 {
//         result.push(matrix[i][matrix[1].len() - 1..][0]);
//     }
//     result.extend(matrix[matrix.len() - 1].iter().rev());
//     for i in (1..matrix.len() - 1).rev() {
//         result.push(matrix[i][0]);
//     }
//
//     if matrix.len() == 2 {
//         // Do nothing
//     } else if matrix.len() == 3 {
//         result.push(matrix[matrix.len()/2][matrix.len()/2]);
//     } else {
//         let mut m2: Vec<Vec<i32>> = vec![];
//         for i in 1..matrix.len()-1 {
//             m2.push(matrix[i][1..matrix.len() - 1].to_vec());
//         }
//         result.extend(snail2(&m2));
//     }
//
//     result
// }
//
// fn snail(matrix: &[Vec<i32>]) -> Vec<i32> {
//     let m: Vec<Vec<i32>> = matrix.to_vec();
//     snail2(&m)
// }
//
// fn main() {
//     let square = &[
//         vec![1,2],
//         vec![4,3],
//     ];
//     let expected = vec![1,2,3,4];
//     assert_eq!(snail(square), expected);
//
//     let square = &[
//         vec![1,2,3],
//         vec![4,5,6],
//         vec![7,8,9],
//     ];
//     let expected = vec![1,2,3,6,9,8,7,4,5];
//     assert_eq!(snail(square), expected);
//
//     let square = &[
//         vec![1, 2, 3,  4],
//         vec![12,13,14, 5],
//         vec![11,16,15, 6],
//         vec![10,9, 8,  7],
//     ];
//     let expected = vec![1,2,3,4,5,6,7,8,9, 10, 11, 12, 13, 14, 15, 16];
//     assert_eq!(snail(square), expected);
//
//     let square = &[
//         vec![1, 2, 3,  4, 5],
//         vec![16,17,18,19, 6],
//         vec![15,24,25,20, 7],
//         vec![14,23,22,21, 8],
//         vec![13,12,11,10, 9],
//     ];
//     let expected = vec![1,2,3,4,5,6,7,8,9, 10, 11, 12, 13, 14, 15, 16,17,18,19,20,21,22,23,24,25];
//     assert_eq!(snail(square), expected);
//
//
//     let square: &[Vec<i32>; 1] = &[Vec::new()];
//     let expected = Vec::new();
//     assert_eq!(snail(square), expected, "Failed with empty input");
//
//
//     let square = &[vec![1]];
//     let expected = vec![1];
//     assert_eq!(snail(square), expected);
// }

// fn sum_intervals(intervals: &[(i32, i32)]) -> i32 {
//     let mut result: Vec<(i32, i32)> = vec![];
//     let mut intervals = intervals.to_vec();
//     intervals.sort_by(|a, b| (a.1-a.0).cmp(&(b.1-b.0)));
//     intervals.reverse();
//     loop {
//         let mut a = match intervals.pop() {
//             Some(a) => a,
//             None=> break
//         };
//
//         let mut skip = false;
//         for i in 0..intervals.len() {
//             let o = intervals[i];
//             if a.0 >= o.0 && a.1 <= o.1 {
//                 skip = true;
//                 break;
//             } else if a.1 >= o.0 && a.1 <= o.1 {
//                 a.1 = o.0;
//             } else if a.0 < o.1 && o.0 <= a.1 {
//                 a.0 = o.1;
//             }
//         }
//
//         if skip {
//             continue
//         } else { result.push(a); }
//
//     }
//
//     result.iter().map(|x| x.1 - x.0).sum()
// }
//
// fn main() {
//     const ERR_MSG: &str = "\nYour result (left) did not match expected output (right).";
//
//     assert_eq!(sum_intervals(&[(1, 5)]), 4, "{}", ERR_MSG);
//     assert_eq!(sum_intervals(&[(1, 5), (6, 10)]), 8, "{}", ERR_MSG);
//
//     assert_eq!(sum_intervals(&[(1, 5), (1, 5)]), 4, "{}", ERR_MSG);
//     assert_eq!(sum_intervals(&[(1, 4), (7, 10), (3, 5)]), 7, "{}", ERR_MSG);
//
//     assert_eq!(sum_intervals(&[(-1_000_000_000, 1_000_000_000)]), 2_000_000_000, "{}", ERR_MSG);
//     assert_eq!(sum_intervals(&[(0, 20), (-100_000_000, 10), (30, 40)]), 100_000_030, "{}", ERR_MSG);
//
//     assert_eq!(sum_intervals(&[(0, 10), (2, 5)]), 10, "{}", ERR_MSG);
// }

// Make a spiral
// fn spiralize_recursive(matrix: &mut Vec<Vec<i8>>) {
//     let mut step = 1;
//     let mut first = 0usize;
//     let mut last = matrix.len()-1;
//     while last > first && last - first > 1 {
//         // step += 1;
//         // Fill the first line
//         matrix[first].iter_mut().enumerate().for_each(|(n, x)| if n >= first && n <= last { *x = step });
//         // step += 1;
//         // Fill the last line
//         matrix[last].iter_mut().enumerate().for_each(|(n, x)| if n >= first && n <= last { *x = step });
//         // step += 1;
//         // matrix.iter_mut().enumerate().for_each(|(n, x)| x[last] = 1);
//         // Fill last vertical line
//         matrix.iter_mut().enumerate().for_each(|(n, x)| {if n >= first && n <= last {x[last] = step}} );
//         // step += 1;
//         // Fill first vertical line
//         matrix.iter_mut().enumerate().for_each(|(n, x)| {if n > first + 1 && n <= last {x[first] = step}} );
//         if matrix[first + 3][first + 1] == 0 {
//             // step += 1;
//             matrix[first + 2][first + 1] = step;
//         }
//         first += 2;
//         last -= 2;
//     }
//     if first == last {
//         matrix[first][first] = step;
//         // step += 1;
//     }
//     if last > first && last - first == 1 {
//         matrix[first][first] = step;
//         matrix[first][first+1] = step;
//         matrix[first+1][first+1] = step;
//     }
// }
//
// fn spiralize(n: usize) -> Vec<Vec<i8>> {
//     (0..n)
//         .map(|i| {
//             (0..n)
//                 .map(|j| {
//                     let min = i.min(j).min(n - i - 1).min(n - j - 1);
//                     (if n % 2 == 0 && i == n / 2 && j == n / 2 - 1 {
//                         0
//                     } else if j == min && i == min + 1 {
//                         min % 2
//                     } else {
//                         1 - min % 2
//                     }) as i8
//                 })
//                 .collect()
//         })
//         .collect()
// }
//
// fn spiralize(size: usize) -> Vec<Vec<i8>> {
//     let mut m: Vec<Vec<i8>> = vec![vec![0i8; size]; size];
//     spiralize_recursive(&mut m);
//     m
// }
//
// fn main() {
//     assert_eq!(
//         spiralize(5),
//         [
//             [1, 1, 1, 1, 1],
//             [0, 0, 0, 0, 1],
//             [1, 1, 1, 0, 1],
//             [1, 0, 0, 0, 1],
//             [1, 1, 1, 1, 1],
//         ],
//     );
//
//     assert_eq!(
//         spiralize(6),
//         [
//             [1, 1, 1, 1, 1, 1],
//             [0, 0, 0, 0, 0, 1],
//             [1, 1, 1, 1, 0, 1],
//             [1, 0, 0, 1, 0, 1],
//             [1, 0, 0, 0, 0, 1],
//             [1, 1, 1, 1, 1, 1],
//         ],
//     );
//
//     assert_eq!(
//         spiralize(7),
//         [
//             [1, 1, 1, 1, 1, 1, 1],
//             [0, 0, 0, 0, 0, 0, 1],
//             [1, 1, 1, 1, 1, 0, 1],
//             [1, 0, 0, 0, 1, 0, 1],
//             [1, 0, 1, 1, 1, 0, 1],
//             [1, 0, 0, 0, 0, 0, 1],
//             [1, 1, 1, 1, 1, 1, 1],
//         ],
//     );
//
//     assert_eq!(
//         spiralize(8),
//         [
//             [1, 1, 1, 1, 1, 1, 1, 1],
//             [0, 0, 0, 0, 0, 0, 0, 1],
//             [1, 1, 1, 1, 1, 1, 0, 1],
//             [1, 0, 0, 0, 0, 1, 0, 1],
//             [1, 0, 1, 0, 0, 1, 0, 1],
//             [1, 0, 1, 1, 1, 1, 0, 1],
//             [1, 0, 0, 0, 0, 0, 0, 1],
//             [1, 1, 1, 1, 1, 1, 1, 1],
//         ],
//     );
// }


// fn balanced_parens(n: u16) -> Vec<String> {
//     (0..n).iter().for_each(|n| {})
// }
//
//
// fn main() {
//     fn do_test(n: u16, expected: Vec<&str>) {
//         let mut actual = balanced_parens(n);
//         actual.sort();
//         assert!(actual == expected, "With n = {n}\nExpected \"{expected:?}\"\nBut got \"{actual:?}\"");
//     }
//
//     #[test]
//     fn sample_tests() {
//         let tests = [
//             (0, vec![""]),
//             (1, vec!["()"]),
//             (2, vec!["(())", "()()"]),
//             (3, vec!["((()))", "(()())", "(())()", "()(())", "()()()"]),
//         ];
//         for (n, exp) in tests.iter() {
//             do_test(*n, exp.to_vec())
//         }
//     }
// }

// struct Node {
//     value: u32,
//     left: Option<Box<Node>>,
//     right: Option<Box<Node>>
// }
//
//
// use std::collections::VecDeque;
// fn tree_by_levels(root: &Node) -> Vec<u32> {
//     let mut result = vec![];
//     let mut queue: VecDeque<&Node> = VecDeque::from([root]);
//     while let Some(n) = queue.pop_front() {
//         result.push(n.value);
//         if let Some(ref l) = n.left {
//             queue.push_back(&*l);
//         }
//         if let Some(ref r) = n.right {
//             queue.push_back(&*r);
//         }
//     }
//     result
// }
//
//
// fn tree_by_levels_my(root: &Node) -> Vec<u32> {
//     let mut ret: Vec<u32> = vec![];
//     let mut curlevel: Vec<&Node> = vec![root];
//     let mut nextlevel: Vec<&Node> = vec![];
//     loop {
//         curlevel.iter().for_each(|x| {
//             ret.push(x.value);
//             match &x.left { Some(a) => nextlevel.push(&a), _ => () };
//             match &x.right { Some(a) => nextlevel.push(&a), _ => () }
//         });
//         curlevel.clear();
//         if nextlevel.len() == 0 {
//             break
//         }
//         curlevel = nextlevel.clone();
//         nextlevel.clear();
//     }
//
//     ret
// }
//
//
// fn main() {
//     assert_eq!(tree_by_levels(&Node::new(42)),
//                [42],
//                "\nYour result (left) didn't match the expected output (right).");
//     let root = Node::new(1)
//         .left(Node::new(2)
//             .left(Node::new(4))
//             .right(Node::new(5)))
//         .right(Node::new(3)
//             .left(Node::new(6)));
//     assert_eq!(tree_by_levels(&root),
//                [1,2,3,4,5,6],
//                "\nYour result (left) didn't match the expected output (right).");
// }


// use std::collections::HashSet;
// fn solve(puzzle: &mut [[u8; 9]; 9]) -> bool {
//     // Find next available number to test
//     let mut i = 99usize;
//     let mut j = 0usize;
//     for i_ in 0..9usize {
//         if let Some(j_) = puzzle[i_].iter().position(|x| *x == 0) {
//             i = i_;
//             j = j_;
//             break
//         }
//     }
//     if i == 99 {
//         return true;
//     }
//     let mut used_numbers: HashSet<u8> = HashSet::new();
//     // Pick number seen in current row/column/3x3 patch.
//     for n in 0..9 {
//         used_numbers.insert(puzzle[n][j]);
//         used_numbers.insert(puzzle[i][n]);
//     }
//
//     // let current_3x3_cell_i = i/3;
//     // let current_3x3_cell_j = j/3;
//
//     for i in (i/3)*3..(i/3)*3+3 {
//         for j in (j/3)*3..(j/3)*3+3 {
//             used_numbers.insert(puzzle[i][j]);
//         }
//     }
//
//     if used_numbers.contains(&0u8) {
//         used_numbers.remove(&0u8);
//     }
//
//     for t in 1..=9u8 {
//         if !used_numbers.contains(&t) {
//             puzzle[i][j] = t;
//             // println!("Trying {} in {}:{}", t, i, j);
//             if solve(puzzle) == true {
//                 return true;
//             }
//             puzzle[i][j] = 0;
//         }
//     }
//
//     false
// }
//
// fn sudoku(puzzle: &mut [[u8; 9]; 9]) {
//     solve(puzzle);
// }
//
// fn main() {
//     // Testing on "hard" from sudoku.com
//     let mut puzzle = [
//         [0, 0, 0, 0, 0, 0, 0, 0, 0],
//         [0, 0, 9, 6, 0, 0, 5, 0, 0],
//         [0, 0, 3, 0, 0, 1, 0, 2, 0],
//         [3, 0, 0, 1, 0, 0, 0, 0, 4],
//         [7, 4, 0, 0, 0, 0, 0, 0, 0],
//         [0, 0, 5, 8, 0, 0, 3, 0, 0],
//         [0, 0, 0, 0, 0, 7, 4, 0, 0],
//         [0, 9, 7, 0, 0, 2, 0, 0, 5],
//         [0, 0, 1, 0, 0, 9, 6, 0, 0],
//     ];
//     sudoku(&mut puzzle);
//
//     let mut puzzle = [
//         [6, 0, 5, 7, 2, 0, 0, 3, 9],
//         [4, 0, 0, 0, 0, 5, 1, 0, 0],
//         [0, 2, 0, 1, 0, 0, 0, 0, 4],
//         [0, 9, 0, 0, 3, 0, 7, 0, 6],
//         [1, 0, 0, 8, 0, 9, 0, 0, 5],
//         [2, 0, 4, 0, 5, 0, 0, 8, 0],
//         [8, 0, 0, 0, 0, 3, 0, 2, 0],
//         [0, 0, 2, 9, 0, 0, 0, 0, 1],
//         [3, 5, 0, 0, 6, 7, 4, 0, 8],
//     ];
//     let solution = [
//         [6, 1, 5, 7, 2, 4, 8, 3, 9],
//         [4, 8, 7, 3, 9, 5, 1, 6, 2],
//         [9, 2, 3, 1, 8, 6, 5, 7, 4],
//         [5, 9, 8, 4, 3, 2, 7, 1, 6],
//         [1, 3, 6, 8, 7, 9, 2, 4, 5],
//         [2, 7, 4, 6, 5, 1, 9, 8, 3],
//         [8, 4, 9, 5, 1, 3, 6, 2, 7],
//         [7, 6, 2, 9, 4, 8, 3, 5, 1],
//         [3, 5, 1, 2, 6, 7, 4, 9, 8],
//     ];
//
//     sudoku(&mut puzzle);
//     assert_eq!(puzzle, solution, "\nYour solution (left) did not match the correct solution (right)");
//
//     let mut puzzle = [
//         [0, 0, 8, 0, 3, 0, 5, 4, 0],
//         [3, 0, 0, 4, 0, 7, 9, 0, 0],
//         [4, 1, 0, 0, 0, 8, 0, 0, 2],
//         [0, 4, 3, 5, 0, 2, 0, 6, 0],
//         [5, 0, 0, 0, 0, 0, 0, 0, 8],
//         [0, 6, 0, 3, 0, 9, 4, 1, 0],
//         [1, 0, 0, 8, 0, 0, 0, 2, 7],
//         [0, 0, 5, 6, 0, 3, 0, 0, 4],
//         [0, 2, 9, 0, 7, 0, 8, 0, 0],
//     ];
//     let solution = [
//         [9, 7, 8, 2, 3, 1, 5, 4, 6],
//         [3, 5, 2, 4, 6, 7, 9, 8, 1],
//         [4, 1, 6, 9, 5, 8, 3, 7, 2],
//         [8, 4, 3, 5, 1, 2, 7, 6, 9],
//         [5, 9, 1, 7, 4, 6, 2, 3, 8],
//         [2, 6, 7, 3, 8, 9, 4, 1, 5],
//         [1, 3, 4, 8, 9, 5, 6, 2, 7],
//         [7, 8, 5, 6, 2, 3, 1, 9, 4],
//         [6, 2, 9, 1, 7, 4, 8, 5, 3],
//     ];
//
//     sudoku(&mut puzzle);
//     assert_eq!(puzzle, solution, "\nYour solution (left) did not match the correct solution (right)");
// }

fn read_i32() -> Result<i32, String> {
    let mut num_lines_string = String::new();
    std::io::stdin().read_line(&mut num_lines_string).expect("Could not determine number of test cases");
    let parsed = num_lines_string.trim().parse::<i32>();
    return match parsed {
        Ok(r) => Ok(r),
        Err(e) => {
            Err(format!("Could not read singular i32: {}", e))
        }
    }
}

fn read_line_i32(array_len: Option<i32>) -> Result<Vec<i32>, String> {
    let mut num_lines_string = String::new();
    std::io::stdin().read_line(&mut num_lines_string).expect("Could not determine number of test cases");
    let res = num_lines_string.trim().split(" ").map(|x| x.parse::<i32>()).filter(|x| x.is_ok())
        .map(|x| x.unwrap()).collect::<Vec<i32>>();
    if array_len.is_none() {
        return Ok(res);
    }
    if res.len() == array_len.unwrap() as usize {
        Ok(res)
    } else {
        Err(format!("Could not read/parse required number of elements from line {:?}", res))
    }
}

fn read_line_strings() -> Result<Vec<String>, String> {
    let mut num_lines_string = String::new();
    std::io::stdin().read_line(&mut num_lines_string).expect("Could not determine number of test cases");
    let res = num_lines_string.trim().split(" ").map(|x| x.to_string()).collect::<Vec<String>>();
    if res.len() > 0 {
        Ok(res)
    } else {
        Err(format!("Could not read/parse required number of elements from line {:?}", res))
    }
}

// Beautiful average, codeforces
// fn main() -> Result<(), Box<dyn std::error::Error>> {
//     let num_tests = read_i32()?;
//     for _test_n in 0..num_tests {
//         let array_len = read_i32()?;
//         let elements = read_line_i32(array_len)?;
//         let max = elements.into_iter()
//             .reduce(i32::max)
//             .unwrap_or(0);
//         println!("{}", max)
//     }
//     Ok(())
// }

// Reverse XOR
// https://codeforces.com/problemset/problem/2160/C
// fn main() -> Result<(), Box<dyn std::error::Error>> {
//     let num_tests = read_i32()?;
//     for _test_n in 0..num_tests {
//         let number = read_i32()?;
//         let mut found = false;
//         if number == 0 {
//             println!("yes");
//             continue
//         }
//         let test_n = number;
//         let s = format!("{:b}", test_n);
//         let reversed =  i32::from_str_radix(s.chars().rev().into_iter().collect::<String>().as_str(), 2).unwrap();
//         if test_n ^ reversed == number {
//             found = true;
//             println!("1yes, {} ^ {} == {}. {:b} => {:b} {:b}", test_n, reversed, number, number, test_n, reversed);
//             // println!("yes");
//         } else {
//             println!("no");
//         }
//         for test_n in 0..number<<1 {
//             let s = format!("{:b}", test_n);
//             let reversed = i32::from_str_radix(s.chars().rev().into_iter().collect::<String>().as_str(), 2).unwrap();
//             if test_n ^ reversed == number {
//                 found = true;
//                 println!("2yes, {} ^ {} == {}. {:b} => {:b} {:b}", test_n, reversed, number, number, test_n, reversed);
//                 // println!("yes");
//                 break
//             }
//         }
//         if !found {
//             println!("no")
//         }
//     }
//     Ok(())
// }

// 2167B - Your Name
// fn main() -> Result<(), Box<dyn std::error::Error>> {
//     let num_tests = read_i32()?;
//     'outer: for _test_n in 0..num_tests {
//         let _number = read_i32()?;
//         let mut found = false;
//         let mut strings = read_line_strings()?;
//         if strings.len() != 2 {
//             return Err(format!("Invalid number of words red: {:?}", strings).into());
//         }
//         let str1 = strings.pop().unwrap();
//         let str2 = strings.pop().unwrap();
//         let mut chars1: Vec<char> = str1.chars().collect();
//         chars1.sort_by(|a, b| b.cmp(a));
//         let mut chars2: Vec<char> = str2.chars().collect();
//         chars2.sort_by(|a, b| b.cmp(a));
//         for n in 0..chars1.len() {
//             if chars1[n] != chars2[n] {
//                 println!("no");
//                 continue 'outer
//             }
//         }
//         println!("yes")
//     }
//     Ok(())
// }

// 2149D - A and B
// fn main() -> Result<(), Box<dyn std::error::Error>> {
//     fn is_final(s: &Vec<u8>) -> bool {
//         let mut num_changes = 0;
//         let mut current_char = s[0];
//         for n in 1..s.len() {
//             if s[n] != current_char {
//                 current_char = s[n];
//                 num_changes += 1;
//                 if num_changes == 3 {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
//
//     let num_tests = read_i32()?;
//     for _test_n in 0..num_tests {
//         let _number = read_i32()?;
//         let mut found = false;
//         let mut strings = read_line_strings()?;
//         if strings.len() != 1 {
//             return Err(format!("Invalid number of words red: {:?}", strings).into());
//         }
//         let mut s = strings.pop().unwrap().into_bytes();
//         let mut num_swipes_a = 0;
//         let mut st = s.clone();
//         while !is_final(&st) {
//             for n in 2..st.len() {
//                 if st[n - 2] != st[n - 1] && st[n - 1] != st[n] {
//                     num_swipes_a += 1;
//                     st.swap(n - 1, n);
//                 }
//             }
//         }
//
//         println!("{} {} {:?}", is_final(&st), num_swipes_a, st)
//     }
//     Ok(())
// }


// 6 A Triangle
// fn main() -> Result<(), Box<dyn std::error::Error>> {
//     let mut nums = read_line_i32(None)?;
//     fn triangle(a: i32, b: i32, c:i32) -> bool {
//         a+b>c && a+c>b && b+c>a
//     }
//
//     fn segment(a: i32, b: i32, c:i32) -> bool {
//         a+b==c || a+c==b || b+c==a
//     }
//
//     if triangle(nums[0], nums[1], nums[2]) || triangle(nums[0], nums[1], nums[3])
//     || triangle(nums[0], nums[2], nums[3]) || triangle(nums[1], nums[2], nums[3])  {
//         println!("TRIANGLE");
//         return Ok(());
//     }
//     if segment(nums[0], nums[1], nums[2]) || segment(nums[0], nums[1], nums[3])
//         || segment(nums[0], nums[2], nums[3]) || segment(nums[1], nums[2], nums[3]) {
//         println!("SEGMENT");
//         return Ok(());
//     }
//     println!("IMPOSSIBLE");
//     Ok(())
// }

// 9 A Die Roll
// fn main() -> Result<(), Box<dyn std::error::Error>> {
//     let mut nums = read_line_i32(None)?;
//
//     if nums.contains(&6) {
//         println!("1/6");
//     } else if nums.contains(&5) {
//         println!("1/3");
//     } else if nums.contains(&4) {
//         println!("1/2");
//     } else if nums.contains(&3) {
//         println!("2/3");
//     } else if nums.contains(&2) {
//         println!("5/6");
//     } else {
//         println!("1/1");
//     }
//     Ok(())
// }


// // 10/A Power Consumption Calculation
// fn main() -> Result<(), Box<dyn std::error::Error>> {
//     let mut nums = read_line_i32(None)?;
//
//     let (n, p1, p2, p3, t1, t2) = (nums[0], nums[1],nums[2], nums[3], nums[4],nums[5]);
//
//     let mut total = 0;
//     for _test_n in 0..n {
//         let work = read_line_i32(Some(2))?;
//         let (l_i, r_i) = (work[0], work[1]);
//         total += (r_i - l_i) * p1;
//         total +=
//     }
//     Ok(())
// }

// 12/A Super Agent
fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut nums_l1 = read_line_strings()?;
    let mut nums_l2 = read_line_strings()?;
    let mut nums_l3 = read_line_strings()?;



    if nums_l1[0].chars().nth(0) != nums_l3[0].chars().nth(2) ||
        nums_l1[0].chars().nth(1) != nums_l3[0].chars().nth(1) ||
        nums_l1[0].chars().nth(2) != nums_l3[0].chars().nth(0) ||
        nums_l2[0].chars().nth(0) != nums_l2[0].chars().nth(2) {
        println!("NO");
    } else {
        println!("YES");
    }

    Ok(())
}