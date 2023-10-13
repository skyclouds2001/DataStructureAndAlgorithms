const rl = require("readline").createInterface({ input: process.stdin });
var iter = rl[Symbol.asyncIterator]();
const readline = async () => (await iter.next()).value;

void (async function () {
    while ((line = await readline())) {
        /**
         * @param jsonObj {object}
         * @param jsonPath {string}
         * @param value {number}
         * @returns {object}
         */
        function setJsonValueByPath(jsonObj, jsonPath, value) {
            // path - a.b[1][1].c | b[1][1].c | [1][1].c | [1].c | c
            const len = jsonPath.length

            let i = 0
            if (jsonPath[0] >= 'a' && jsonPath[0] <= 'z') {
                while(i < len && jsonPath[i] >= 'a' && jsonPath[i] <= 'z') {
                    ++i
                }
                const key = jsonPath.slice(0, i)
                if (jsonPath[i] === '.') {
                    ++i
                    jsonObj[key] = setJsonValueByPath({}, jsonPath.slice(i + 1), value)
                } else if (i === len) {
                    jsonObj[jsonPath] = value
                } else {
                    //
                }
            } else if (jsonPath[i] === '[') {
                let j = 0
                while (jsonPath[j] !== ']') {
                    ++j
                }
                const key = Number.parseInt(jsonPath.slice(1, j))
                const val = Array(key + 1).fill(null)
                setJsonValueByPath(val[key], jsonPath.slice(j + 1), value)
                jsonObj[key] = val
            }

            return jsonObj;
        }

        const arr = line.split("=");
        const result = setJsonValueByPath({}, arr[0], parseInt(arr[1]));

        console.log(JSON.stringify(result));
    }
})();
