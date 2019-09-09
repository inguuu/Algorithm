#include<stdio.h>
#include<vector>
#include<algorithm> 
#include<iostream>
#include<queue>
using namespace std;

int main() {

	int n, m;
	queue < pair<int, int >> q;

	int map[1002][1002];
	int visited[1002][1002];

	int dr[] = { 1,0,-1,0 };
	int dc[] = { 0,1,0,-1 };

	cin >> m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			visited[i][j] = 0;
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
				visited[i][j] = 1;

			}
		}
	}

	int now_count = 0;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int now_row = q.front().first;
			int now_col = q.front().second;
			//visited[now_row][now_col] = 1;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nxt_row = now_row + dr[i];
				int nxt_col = now_col + dc[i];
				if (nxt_row < 0 || nxt_col < 0 || nxt_row >= n || nxt_col >= m) continue;
					if (visited[nxt_row][nxt_col] == 0 && map[nxt_row][nxt_col] == 0) {
						//cout <<nxt_row<<", "<<nxt_col << " "<< map[nxt_row][nxt_col] <<endl;
						visited[nxt_row][nxt_col] = 1;
						map[nxt_row][nxt_col] = map[now_row][now_col] + 1;
						q.push(make_pair(nxt_row, nxt_col));

					}
				
			}

		}
		if (q.empty()) 
			break;

		now_count++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {

				cout << "-1" << endl;
				return 0;
				break;
			}

		}
	}


	cout << now_count << endl;

	return 0;
}