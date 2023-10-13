const rl = require("readline").createInterface({ input: process.stdin });
const readline = async () => (await rl[Symbol.asyncIterator]().next()).value;

void (async function () {
    while ((line = await readline())) {
        const tickets = JSON.parse(line);
        const now = Date.now();

        function parseTime(time) {
            const date = new Date(now);
            const [h, m] = time.split(":").map((v) => Number.parseInt(v));
            date.setHours(h, m);

            return date.getTime();
        }

        tickets.sort((a, b) => {
            if (a.price === b.price) {
                return parseTime(a.time) - parseTime(b.time);
            }
            return a.price - b.price;
        });

        console.log(JSON.stringify(tickets));
    }
})();
