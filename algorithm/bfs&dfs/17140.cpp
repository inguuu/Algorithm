//#include<stdio.h>
//#include<vector>
//#include<algorithm> 
//#include<iostream>
//using namespace std;
//
//
//
//
//
//
//int main() {
//
//	int row, col;
//
//	vector<pair<int, int>> v[101];
//
//
//	for (int i = 0; i < 101; i++) {
//		v[i].push_back(make_pair(0,0 ));
//	}
//	int map[101][101] = { 0, };
//	
//
//	//받기 3*3
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			cin >> map[i][j];
//		}
//
//	}
//
//	row = 3;
//	col = 3;
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//
//			cout << map[i][j] ;
//
//
//		}
//		cout << endl;
//	}
//
//
//
//		if (row >= col) {
//
//			int cnt[101] = { 0, }; //갯수 구하기
//			for (int i = 0; i < col; i++) {
//				++cnt[i];
//			
//
//				for (int j = 1; j < 101; j++) {
//					if (cnt[j])
//						v[i].push_back({ cnt[j], j });
//
//				}
//		    }
//
//			for (int i = 0; i < row; i++)
//				sort(v[i].begin(), v[i].end());
//
//			for (int i = 0; i < row; i++)
//			{
//				int tempIdx = 0;
//				for (int j = 0; j < v[i].size(); j++)
//				{
//					map[i][tempIdx++] = v[i][j].second;
//					if (tempIdx == 100)
//						break;
//					map[i][tempIdx++] = v[i][j].first;
//					if (tempIdx == 100)
//						break;
//				}
//				col = max(col, tempIdx);
//			}
//
//			
//
//			for (int i = 0; i < 7; i++) {
//				for (int j = 0; j < 7; j++) {
//
//					cout << map[i][j] << " ";
//
//				}
//				cout << endl;
//			}
//
//
//
//
//
//		}
//
//	
//
//
//}