#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, V;
vector<vector<int>> map;	// 각 연결노드를 표시할 맵
bool* check_d;//dfs용 check배열
bool* check_b;//bfs용 check배열
vector<int> dfs_list;

void dfs_s(int start) {
	vector<int> list_d;
	stack<int> s;
	check_d = new bool[N + 1];
	fill_n(check_d, N + 1, false);	// 초기화
	for (int i = 0; i < map.size(); i++) {
		sort(map[i].begin(), map[i].end(), greater<int>());	//역순정렬
		
	}
	s.push(start);
	check_d[start] = true;

	while (!s.empty()) {	// 얘는 스택이 빌때까지가 아니라 원하는 갯수를 뽑으면 종료해야되나?
		int now = s.top();
		s.pop();
		check_d[now] = true;
		list_d.push_back(now);	// 순서기록
		for (int i = 0; i < map[now].size(); i++) {
			if (!check_d[map[now][i]]) {	// 미방문인 연결노드
				s.push(map[now][i]);	//스택에 삽입
				//check_d[map[now][i]] = true;	//이게 있고 없고가 왜 차이가 나지?
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << list_d[i] << " ";
	}
	return;
}

void dfs(int start){
    dfs_list.push_back(start);
    check_d[start] = true;  // 방문처리
    for(int i=0;i<map[start].size();i++){
        if(!check_d[map[start][i]]){    // 미방문인 노드를 방문        
            dfs(map[start][i]); //재귀
        }
    }
    return;
}

void bfs(int start) {
	vector<int> list_b;
	queue<int> q;
	check_b = new bool[N + 1];
	fill_n(check_b, N + 1, false);
	for (int i = 0; i < map.size(); i++) {
		sort(map[i].begin(), map[i].end());
	}
	q.push(start);
    check_b[start] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		list_b.push_back(now);
		for (int i = 0; i < map[now].size(); i++) {
			if (!check_b[map[now][i]]) {	// 미방문인 노드
				q.push(map[now][i]);	//queue에 삽입
				check_b[map[now][i]] = true;
			}
		}
	}
	for (int i = 0; i < list_b.size(); i++) {
		cout << list_b[i] << " ";
	}
	return;
}



int main() {
	cin >> N >> M >> V;
	for (int i = 0; i < N+1; i++) {
		map.push_back(vector<int>());
	}
	for (int i = 0; i < M; i++) {
		int f, t;
		cin >> f >> t;
		map[f].push_back(t);
		map[t].push_back(f);
		//쌍방향 삽입
	}

    check_d = new bool[N+1];
    fill_n(check_d, N+1, false);
    for(int i=0;i<map.size();i++){
        sort(map[i].begin(), map[i].end());
    }

	dfs(V);
    for(int i=0;i<dfs_list.size();i++){
        cout<<dfs_list[i]<<" ";
    }
	cout << "\n";

    
	bfs(V);

    
	return 0;
}