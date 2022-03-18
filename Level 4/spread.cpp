#include <vector>
#include <cstdio>
#include <cmath>
#define ll long long

#define RANGE_ADD

template <typename T_t>
class FenwickTree {
 public:
  int N;
  std::vector<T_t> T;

  // Initiate tree, internal tree is 1-based indexing, but external isn't
  FenwickTree(int N) {
    this->N = N + 1;
    this->T = std::vector<T_t>(N + 1, 0);
  }

#if defined(RANGE_ADD)

  void add(int x, T_t v) {
    for (++x; x < this->N; x += x & -x)
      this->T[x] += v;
  }

  void rangeAdd(int l, int r, T_t v) {
    this->add(l, v);
    this->add(r + 1, -v);
  }

  T_t pointQuery(int x) {
    T_t ret = 0;
    for (++x; x > 0; x -= x & -x)
      ret += this->T[x];
    return ret;
  }

#elif defined(POINT_ADD)

  void add(int x, T_t v) {
    for (++x; x < this->N; x += x & -x)
      this->T[x] += v;
  }

  // Sums [0 - r] inclusive
  T_t sum(int r) {
    T_t ret = 0;
    for (++r; r > 0; r -= r & -r) {
      ret += this->T[r];
    return ret;
  }

  // Sums [l - r] inclusive
  T_t sumRange(int l, int r) {
    return this->sum(r) - this->sum(l - 1);
  }

#endif

  // For debugging
  void printTree(void) {
    printf("T = { ");
    for (int i = 1; i <= this->N; i++)
      printf("%lld ", (ll)this->T[i]); 
    printf("}\n");
  }
};

// https://www.codechef.com/problems/SPREAD
int main() {
  int n, m, c, u, v, k, p;
  char type[1];
  scanf("%d %d %d", &n, &m, &c);
  FenwickTree<ll> f = FenwickTree<ll>(n);
  f.rangeAdd(0, n-1, c);

  for (int ops = 0; ops < m; ops++) {
    scanf("%s", type);
    if (type[0] == 'S') {
      scanf("%d %d %d", &u, &v, &k);
      f.rangeAdd(u-1, v-1, k);
    } else {
      scanf("%d", &p);
      printf("%lld\n", f.pointQuery(p-1));
    }
  }
  return 0;
}
