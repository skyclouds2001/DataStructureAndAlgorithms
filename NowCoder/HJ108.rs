use std::io::{self, *};

fn exec(a: i32, b: i32) -> i32 {
    if (a < b) {
        return exec(b, a);
    } else if (a == 1 && b == 1) {
        return 1;
    } else if (a % b == 0) {
        return b;
    } else {
        return exec(b, a % b);
    }
}

fn main() {
    let stdin = io::stdin();
    unsafe {
        for line in stdin.lock().lines() {
            let ll = line.unwrap();
            let numbers: Vec<&str> = ll.split(" ").collect();
            let a = numbers[0].trim().parse::<i32>().unwrap_or(0);
            let b = numbers[1].trim().parse::<i32>().unwrap_or(0);
            print!("{}\n", a * b / exec(a, b));
        }
    }
}
