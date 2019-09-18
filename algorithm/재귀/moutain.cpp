//#include<stdio.h>
//#include<vector>
//#include<algorithm> 
//#include<iostream>
//#include<queue>
//using namespace std;
//
//int main() {
//
//	queue <pair <int, int>> q;
//	int map[51][51];
//	int visited[51][51];
//	int t, m, n, k;
//
//	int dr[] = { 0,1,0,-1 };
//	int dc[] = { 1,0,-1,0 };
//
//	cin >> t;
//
//	for (int i = 0; i < t; i++) {
//		cin >> m;
//		cin >> n;
//		cin >> k;
//
//		//초기화
//		for (int j = 0; j < n; j++) {
//			for (int s = 0; s < m; s++) {
//				map[j][s] = 0;
//				visited[j][s] = 0;
//			}
//		}
//
//		while (!q.empty()) {
//			q.pop();
//		}
//
//		//넣기
//		for (int j = 0; j < k; j++) {
//
//			int br;
//			int bc;
//			cin >> br;
//			cin >> bc;
//			map[bc][br] = 1;
//
//		}
//
//		//for (int j = 0; j < n; j++) {//맵확인
//		//	for (int s = 0; s < m; s++) {
//		//		cout << map[j][s] << " ";
//		//	}
//		//	cout << " " << endl;
//		//}
//
//
//		//시작
//
//		int num = 0;
//
//		for (int j = 0; j < n; j++) {
//			for (int s = 0; s < m; s++) {
//				if (map[j][s] == 1 && visited[j][s] == 0) {
//					q.push(make_pair(s, j));
//
//					//bfs
//					while (!q.empty()) {
//
//						int now_row = q.front().second;
//						int now_col = q.front().first;
//						visited[now_row][now_col] = 1;
//
//
//
//						//cout << "now " << now_row << "," << now_col  << endl;
//						q.pop();
//
//						for (int j = 0; j < 4; j++) {
//							int nxt_row = now_row + dr[j];
//							int nxt_col = now_col + dc[j];
//
//							if (nxt_col >= 0 && nxt_row >= 0 && nxt_row < n && nxt_col < m) {
//
//								if (map[nxt_row][nxt_col] == 1 && visited[nxt_row][nxt_col] == 0) {
//
//									q.push(make_pair(nxt_col, nxt_row));
//									visited[nxt_row][nxt_col] = 1;
//
//								}
//							}
//
//						}
//
//
//					}
//					num++;
//
//
//				}
//
//			}
//		}
//
//
//		cout << num << endl;
//	}
//
//		
//	
//}
//
///*
//차세대 영농인 한나는 강원도 고랭지에서 유기농 배추를 재배하기로 하였다.
//
//농약을 쓰지 않고 배추를 재배하려면 배추를 해충으로부터 보호하는 것이 중요하기 때문에, 한나는 해충 방지에 효과적인 배추흰지렁이를 구입하기로 결심한다.
//
//이 지렁이는 배추근처에 서식하며 해충을 잡아 먹음으로써 배추를 보호한다. 
//
//특히, 어떤 배추에 배추흰지렁이가 한 마리라도 살고 있으면 이 지렁이는 인접한 다른 배추로 이동할 수 있어, 그 배추들 역시 해충으로부터 보호받을 수 있다.
//
//(한 배추의 상하좌우 네 방향에 다른 배추가 위치한 경우에 서로 인접해있다고 간주한다)
//
//한나가 배추를 재배하는 땅은 고르지 못해서 배추를 군데군데 심어놓았다. 배추들이 모여있는 곳에는 배추흰지렁이가 한 마리만 있으면 되므로 서로 인접해있는 배추들이 몇 군데에 퍼져있는지 조사하면 총 몇 마리의 지렁이가 필요한지 알 수 있다.
//
//예를 들어 배추밭이 아래와 같이 구성되어 있으면 최소 5마리의 배추흰지렁이가 필요하다.
//
//(0은 배추가 심어져 있지 않은 땅이고, 1은 배추가 심어져 있는 땅을 나타낸다.)
//*/