// @ts-check
/// <reference path="./template.d.ts" />

export { }

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('line', function (data: string) {
    console.log(data);
});
