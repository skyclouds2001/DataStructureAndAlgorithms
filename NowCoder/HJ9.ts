const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', function (line: string) {
  const nums: string[] = line.trim().split('').reverse()
  const set = new Set<string>()
  const res: string[] = []
  for (const v of nums) {
    if (!set.has(v)) {
      res.push(v)
      set.add(v)
    }
  }
  console.log(res.join(''))
});
