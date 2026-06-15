#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r;
    int scenario = 0;

    while (cin >> n >> r && (n || r)) {
        scenario++;

        map<string, int> cityId;
        int counter = 0;
        vector<vector<pair<int,int>>> graph(n);

        auto getId = [&](const string& name) -> int {
            auto it = cityId.find(name);
            if (it == cityId.end()) {
                cityId[name] = counter++;
                return counter - 1;
            }
            return it->second;
        };

        for (int i = 0; i < r; i++) {
            string a, b;
            int w;
            cin >> a >> b >> w;
            int u = getId(a), v = getId(b);
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        string srcName, dstName;
        cin >> srcName >> dstName;
        int src = getId(srcName), dst = getId(dstName);

        // Modified Dijkstra: maximize minimum edge weight along path
        vector<int> best(n, -1);
        best[src] = INT_MAX;

        // Max-heap: {bottleneck_capacity, node}
        priority_queue<pair<int,int>> pq;
        pq.push({best[src], src});

        while (!pq.empty()) {
            auto [cap, u] = pq.top(); pq.pop();

            if (cap < best[u]) continue;  // stale entry
            if (u == dst) break;

            for (auto [v, w] : graph[u]) {
                int newCap = min(cap, w);
                if (newCap > best[v]) {
                    best[v] = newCap;
                    pq.push({newCap, v});
                }
            }
        }

        cout << "Scenario #" << scenario << "\n";
        cout << best[dst] << " tons\n";
    }

    return 0;
}