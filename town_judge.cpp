#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> indegree(n + 1, 0);
    vector<int> outdegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        outdegree[a]++;
        indegree[b]++;
    }

    int judge = -1;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == n - 1 && outdegree[i] == 0) {
            judge = i;
            break;
        }
    }

    cout << judge << '\n';

    return 0;
}