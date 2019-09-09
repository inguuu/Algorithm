#include<stdio.h>
#include<vector>
#include<algorithm> 
#include<iostream>
#include<queue>
using namespace std;

int main() {

	int N;
	int K;
	int count = 0;

	cin >> N;
	cin >> K;

	queue <int> q;
	
	int visited[100001] = { 0, };

	q.push(N);
	visited[N] = 1;

	while (!q.empty()) {
		
		int now;
		now = q.front(); 
		q.pop();
		
		//cout << "now: " << now << endl;
		//cout << "visted[now]: " << visited[now] << endl;
		if (now == K) {
			count = visited[now]-1;
			break;
		}

		if (now + 1 < 100001&&visited[now+1]<1) {
			
			q.push(now + 1);
			visited[now + 1] = visited[now] + 1;
		}
		if (now - 1 >=0 && visited[now - 1] < 1) {
			
			q.push(now - 1);
			visited[now - 1] = visited[now] + 1;
		}
		if (now *2 < 100001 && visited[now *2] < 1) {
		
			q.push(now * 2);
			visited[now *2]=visited[now]+1;
		}
	
	}
	
	cout << count;

}

/*
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
*/