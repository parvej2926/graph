#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r;
    int tc = 1;

    while (cin >> n >> r && (n || r)) {
        unordered_map<string, int> mp;
        int id = 0;

        vector<vector<pair<int,int>>> adj(n * 2); // safe size

        auto getId = [&](string s) {
            if (mp.count(s)) return mp[s];
            return mp[s] = id++;
        };

        for (int i = 0; i < r; i++) {
            string u, v;
            int w;
            cin >> u >> v >> w;
            int a = getId(u);
            int b = getId(v);

            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }

        string s, t;
        cin >> s >> t;

        int src = getId(s);
        int dst = getId(t);

        vector<int> best(id, 0);

        priority_queue<pair<int,int>> pq;
        pq.push({INT_MAX, src});
        best[src] = INT_MAX;

        while (!pq.empty()) {
            auto [cap, u] = pq.top();
            pq.pop();

            if (u == dst) break;
            if (cap < best[u]) continue;

            for (auto [v, w] : adj[u]) {
                int newCap = min(cap, w);
                if (newCap > best[v]) {
                    best[v] = newCap;
                    pq.push({newCap, v});
                }
            }
        }

        cout << "Scenario #" << tc++ << "\n";
        cout << best[dst] << " tons\n";
    }

    return 0;
}