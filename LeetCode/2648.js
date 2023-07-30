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
