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
 
long long ncr(long long n, long long k) {
  return factorial[n] * inverse(factorial[k] * factorial[n - k] % mod) % mod;
}
