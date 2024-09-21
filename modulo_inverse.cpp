long long inverse(long long num) {
  long long val = 0;
  if (num <= 1) {
    val = num;
  }
  else {
    val = (mod - mod / num) * inverse(mod % num) % mod;
  }
  return val;
}
