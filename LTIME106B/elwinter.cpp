#include <cstdio>
#include <set>
#include <vector>

struct node {
  bool frozen = false;
  std::set<int> neighbors;
};

void printFringe(std::set<int> S) {
  printf("Fringe: ");
  for (auto s : S)
    printf("%d ", s + 1);
  printf("\n");
}

void printGraph(std::vector<node> G, std::set<int> fringe) {
  
  for (int i = 0; i < G.size(); i++) {
    if (G[i].frozen)
      printf("%d (Frozen = T): ", i + 1);
    else
      printf("%d (Frozen = F): ", i + 1);
    for (auto n : G[i].neighbors)
      printf("%d ", n + 1);
    printf("\n");
  }
  printFringe(fringe);
}

// https://www.codechef.com/LTIME106B/problems/ELWINTER
int main() {

  int N, M, Q, u, v, t, type;
  std::vector<node> G;
  std::set<int> fringe;
  bool allFrozen = false;

  scanf("%d %d %d", &N, &M, &Q);

  // Create nodes
  G = std::vector<node>(N);
  fringe = std::set<int>();

  // Build the graph
  for (int edge = 0; edge < M; edge++) {
    scanf("%d %d", &u, &v);
    G[u-1].neighbors.insert(v-1);
    G[v-1].neighbors.insert(u-1);
  }

  // printGraph(G, fringe);

  // Answer queries
  for (int query = 0; query < Q; query++) { 
    scanf("%d", &type);

    // Freeze u
    if (type == 1) {
      scanf("%d", &u);
      // printf("Freeze %d\n", u);

      // DFS starting a u, scheduling future freeze times
      G[u-1].frozen = true;

      // Add unfrozen neighbors to fringe
      for (auto neighbor : G[u-1].neighbors) {
        if (!G[neighbor].frozen)
          fringe.insert(neighbor);
      }

      // This node no longer needs to be in G
      G[u-1].neighbors.clear();
    } 
    
    // Let t units of time pass
    else if (type == 2) {
      scanf("%d", &t);
      if (t > G.size()) {
        allFrozen = true;
        continue;
      }

      // printf("%d time passed\n", t);

      // While time still remains, and nodes are still able to be frozen
      while ((t > 0) && fringe.size() > 0) {

        // For each time step, the next node on the fringe will freeze
        std::set<int> newFringe;
        for (auto& nextNode : fringe) {

          // Freeze the fringe
          G[nextNode].frozen = true;

          // Add new nodes to fringe
          for (auto& neighbor : G[nextNode].neighbors) {
            if (!G[neighbor].frozen)
              newFringe.insert(neighbor);
          }
        }

        fringe = newFringe;

        t--;
      }
      // printGraph(G, fringe);
    } 
    
    // Check if v is frozen
    else if (type == 3) {
      scanf("%d", &v);
      if (allFrozen) {
        printf("YES\n");
        continue;
      }
      // printf("Query %d\n", v);
      if (G[v-1].frozen)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
