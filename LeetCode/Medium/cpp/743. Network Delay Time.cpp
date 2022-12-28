#include <vector>
// #include <climits>
using namespace std;

// https://leetcode.com/problems/network-delay-time/

class Solution_bellman {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // times는 간선들, n은 정점 개수, k는 시작점
    // bellman solution
    int from, to, w;
    int max_w = INT_MIN;
    vector<int> dist(n + 1, 100 * 100 * 10); // 정점 번호가 1부터 시작하는 거리 벡터
    dist[k] = 0; // 시작점은 거리 0
    dist[0] = INT_MIN; // 안 쓰는 정점 표시

    // 최단거리 구하기
    for (int i = 1; i < n; i++) {
        for (int x = 0; x < times.size(); x++) {
        from = times[x][0];
        to = times[x][1];
        w = times[x][2];

        dist[to] = dist[to] > dist[from] + w ? dist[from] + w : dist[to];
        }
    }

    for (auto& i : dist)
    max_w = i > max_w ? i : max_w;

    if (max_w == 100 * 100 * 10)
        return -1;
    return max_w;
    }
};

// other Solution

#include <queue>
#include <vector>
// #include <climits>
using namespace std;

struct cmp { // 다익스트라 우선순위 큐 비교 연산자 : 가중치가 적고 정점 번호가 적은 것을 우선으로 함
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)
			return a.first >= b.first;
		else
			return a.second > b.second;
	}
};

class Solution_dijkstra {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // times는 간선들, n은 정점 개수, k는 시작점
    // dijkstra solution
    int from, to, w, vert;
    int max_w = INT_MIN;
    vector<int> dist(n + 1, 100 * 100 * 10); // 정점 번호가 1부터 시작하는 거리 벡터
    vector<bool> visited(n + 1, false); // 방문 여부 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> next_visit; // 다음에 방문할 정점 : (정점, 거리)

    vert = k; // 이제 방문할 정점 : 아직 시작하지 않았으므로 시작점으로 초기화
    visited[0] = true; // 안 쓰는 인덱스 방문할 일 없게 미리 표시

    dist[k] = 0; // 시작점은 거리 0
    dist[0] = INT_MIN; // 안 쓰는 정점 표시
    next_visit.push(make_pair(k, dist[k]));

    // 1. 시작점 방문
    // 2. 거리 파악
    // 3. 가장 가까운 곳으로 이동
    // 4. 반복

    while (true) {
        if (!visited[vert]) {
        visited[vert] = true; // 정점 방문
        // vector<Edge> v_edge = edges_from(vert); // 지금 방문한 정점에 연결된 간선들 가져오기

        for (int x = 0; x < times.size(); x++) {
            from = times[x][0];
            to = times[x][1];
            w = times[x][2];

            if (from != vert)
            continue;

          if (dist[vert] + w < dist[to]) { // 거리를 업데이트할 필요가 있을 때에만
            dist[to] = dist[vert] + w; // 거리 업데이트
            next_visit.push(make_pair(to, dist[to])); // 다음 방문 정점 큐에 추가
            }
        }
        }

        if (!next_visit.empty()) {
        pair<int, int> next = next_visit.top(); // (정점, 거리)
        next_visit.pop();
        vert = next.first;
        }
      else // 다음 방문 정점 큐가 비어있다면 종료
        break;
    }

    for (auto& i : dist)
    max_w = i > max_w ? i : max_w;

    if (max_w == 100 * 100 * 10)
        return -1;
    return max_w;
    }
};