/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
  let s = 0, t = 1;
  let r;
  yield s;
  yield t;
  while(true) {
      r = s + t;
      yield r;
      s = t;
      t = r;
  }
};

/**
* const gen = fibGenerator();
* gen.next().value; // 0
* gen.next().value; // 1
*/
