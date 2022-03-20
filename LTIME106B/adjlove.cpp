#include <cstdio>
#include <vector>

#define vi std::vector<int>

// https://www.codechef.com/LTIME106B/problems/ADJLOVE
int main() {
  int T, N, Ai;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    vi evens;
    vi odds;
    vi answer;
    for (int i = 0; i < N; i++) {
      scanf("%d", &Ai); 
      if ((Ai & 1) == 1)
        odds.push_back(Ai);
      else 
        evens.push_back(Ai);
    }

    // If we don't have any odds, not possible
    if (odds.size() <= 1) {
      printf("-1\n");
      continue;
    }

    // Even number of odds, just throw them on the front
    if ((odds.size() % 2) == 0) {
      for (auto& o : odds)
        answer.push_back(o);
      for (auto& e : evens)
        answer.push_back(e);

      // Print answer
      for (int i=0; i<answer.size(); i++) {
        printf("%d", answer[i]);
        if (i == answer.size() - 1)
          printf("\n");
        else
          printf(" ");
      }
      continue;
    } 
    
    // Second case where we have odd number of odds
    if (evens.size() == 0) {
      printf("-1\n");
      continue;
    }

    // Push back even number of odds
    for (int i = 0; i < odds.size()-1; i++)
      answer.push_back(odds[i]);

    // Push back first even
    answer.push_back(evens[0]);

    // push back last odd
    answer.push_back(odds[odds.size() - 1]);

    // push back the rest of the evens
    for (int i = 1; i < evens.size(); i++)
      answer.push_back(evens[i]);

    // Print answer
    for (int i=0; i<answer.size(); i++) {
      printf("%d", answer[i]);
      if (i == answer.size() - 1)
        printf("\n");
      else
        printf(" ");
    }
  }
  return 0;
}
