#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int T;
  long long D, d, P, Q;

  scanf("%d", &T);
  while (T--) {
    scanf("%lld %lld %lld %lld", &D, &d, &P, &Q);
    long long n = D/d;
    long long ps = n*P;
    long long qs = Q*((n)*(n-1)/2);
    long long add = (D % d)*(P + Q*(D/d));
    printf("%lld\n", d*(ps + qs) + add);
  }
  return 0;
}
