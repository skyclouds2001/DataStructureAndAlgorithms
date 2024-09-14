use std::io::{self, *};

fn main() {
  let stdin = io::stdin();
  unsafe {
    for line in stdin.lock().lines() {
      println!("{}", line.unwrap());
    }
  }
}
