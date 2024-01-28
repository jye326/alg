#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M;
vector<vector<int>> map;    // 인접리스트 map
bool check[100];

void bfs(){
    queue<int> q;
    q.push(0);
    check[0] = true;
    int count = -1; // 0이면 1번노드를 세버린다.
    while(!q.empty()){
        int now = q.front();
        q.pop();
        count++;    // 방문하지 않은 노드의 수를 세는 것이 목적이기 때문
        for(int next : map[now]){
            if(!check[next]){
                check[next] = true;
                q.push(next);
            }
        }
    }
   
    cout<<count;
    return;
}

int main(){
    cin>>N>>M;
    map.resize(N);  // resize는 뭐야
    

    for(int i=0;i<M;i++){
        int f, t;
        cin>>f>>t;
        // map[f-1][t-1] = 1;
        // map[t-1][f-1] = 1;
        map[f-1].push_back(t-1);
        map[t-1].push_back(f-1);
    }
    

    bfs();

    
}