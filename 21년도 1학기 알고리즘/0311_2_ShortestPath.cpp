#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, K;
int dist[20001] = { 0, };
vector<pair<int, int>> vec[20001];

const int INF = 999999999;

int main() {
	scanf("%d %d %d", &V, &E, &K);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		vec[u].push_back(make_pair(v, w));
	}
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}

	priority_queue<pair<int, int>> pq;
	dist[K] = 0;
	pq.push(make_pair(0, K));

	while (!pq.empty()) {
		int weight = -pq.top().first;
		int loc = pq.top().second;
		pq.pop();
		for (int i = 0; i < vec[loc].size(); i++) {
			int next = vec[loc][i].first; 
			int nweight = vec[loc][i].second;
			int sum = weight + nweight;
			if (dist[next] > sum) { 
				dist[next] = sum; 
				pq.push(make_pair(-dist[next], next)); 
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	}
}