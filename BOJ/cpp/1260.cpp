#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

void boj1260();
void DFS(int root, vector<vector<int>>& nodes, vector<bool>& visit);
void BFS(int root, vector<vector<int>>& nodes, vector<bool>& visit);

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj1260();

    return 0;
}

void boj1260() {
    int n, m, root, from, to;
    vector<vector<int>> nodes;
    vector<bool> visit;

    cin >> n >> m >> root;
    nodes.resize(n + 1);
    visit.resize(n + 1);
    visit[0] = true;

    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        nodes[from].push_back(to);
        nodes[to].push_back(from);
    }

    for (int i = 1; i <= n; i++) {
        if (nodes[i].size() > 1)
            sort(nodes[i].begin(), nodes[i].end());
    }

    DFS(root, nodes, visit);
    cout << "\n";

    visit.clear();
    visit.resize(n + 1);
    visit[0] = true;

    BFS(root, nodes, visit);

    return;
}

void DFS(int root, vector<vector<int>>& nodes, vector<bool>& visit) {
    int node;
    stack<int> stack;

    stack.push(root);

    while (!stack.empty()) {
        node = stack.top();
        stack.pop();

        if (visit[node])
            continue;

        visit[node] = true;
        cout << node << " ";

        for (int i = nodes[node].size() - 1; i >= 0; i--) {
            if (!visit[nodes[node][i]])
                stack.push(nodes[node][i]);
        }
    }

    return;
}

void BFS(int root, vector<vector<int>>& nodes, vector<bool>& visit) {
    int node;
    queue<int> que;

    que.push(root);

    while (!que.empty()) {
        node = que.front();
        que.pop();

        if (visit[node])
            continue;

        visit[node] = 1;
        cout << node << " ";

        for (int& i : nodes[node]) {
            if (!visit[i])
                que.push(i);
        }
    }

    return;
}