#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> parent(n);
    vector<int> sz(n, 1);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    };

    int answer = 0;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        // a의 루트 찾기
        int ra = a;
        while (parent[ra] != ra) ra = parent[ra];
        int cur = a;
        while (parent[cur] != cur) {
            int nxt = parent[cur];
            parent[cur] = ra;
            cur = nxt;
        }

        // b의 루트 찾기
        int rb = b;
        while (parent[rb] != rb) {
            rb = parent[rb];
        }
        cur = b;
        while (parent[cur] != cur) {
            int nxt = parent[cur];
            parent[cur] = rb;
            cur = nxt;
        }

        if (ra == rb) {
            if (answer == 0) answer = i;
            continue;
        }

        if (sz[ra] < sz[rb]) swap(ra, rb);
        parent[rb] = ra;
        sz[ra] += sz[rb];
    }

    cout << answer;
    return 0;
}