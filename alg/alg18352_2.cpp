#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int N, M, K, X;
const int INF = ((1<<30)-1);   // unsigned int 1로 다 채우고 2칸 밀기
//도시, 도로, 목표 거리, 출발 도시
vector<vector<int>> graph;  // 2차원 연결리스트로 그래프 구현

vector<int> dist;    // 출발도시로부터의 최단거리를 저장할 배열 // check를 재사용하려했는데 뭔가 안된다..?
vector<bool> check;    // 각 노드의 방문여부를 체크할 배열


void bfs(){ //재귀 아니다.
    //queue 위치 변경
    queue<int> q;   // queue를 이용한 BFS로 각 노드를 거리별로 방문함

    dist[X] = 0;   // 자기 자신 거리 0
    check[X] = true;
    q.push(X);  //출발노드부터 일단 큐에 넣고
    

    while(!q.empty()){  //q가 빌 때 까지
        int now = q.front();
        q.pop();    // 꺼내기

        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i];
            if(!check[next]){
                check[next] = true;
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
    
}

int main(){
    // 정보 입력받기
    cin>>N>>M>>K>>X;
    
    // 그래프 초기화
    for(int i=0;i<=N;i++){  // 도시번호를 인덱스로 사용하기 위해 한 칸 더 만듬
        graph.push_back(vector<int>()); // 이차원 벡터의 초기화 방법
    }
    // 그래프 입력
    for(int i=0;i<M;i++){
        int f, t;
        cin>>f>>t;
        graph[f].push_back(t);
    }
    // check배열 초기화
    //check = new bool[N+1]; // 도시번호를 인덱스로 사용하기 위해 한 칸 더 만듬
    for(int i=0;i<N+1;i++){
        check.push_back(false);
    }

    // queue 초기화
    // 는 따로 필요없다네

    // dist 초기화
    // dist = new int[N+1];
    // for(int i=0;i<N+1;i++){
    //     dist.push_back(INF);
    // }
    // dist 초기화 방법 변경
    dist = vector<int>(N+1, -1);

    // vector쓰니까 중간에 배열을 전체 출력해서 확인할 수가 없네?

    // 일단 출발도시부터 queue에 담고 방문체크를 한다.
    // 출발도시에 연결된 도시를 queue에 담는다.
    bfs();
    bool flag = true;
    for(int i=0;i<=N;i++){
        if(dist[i] == K){
            flag = false;
            cout<<i<<endl;
        }
    }
    if(flag){
        cout<<-1;
    }


    //delete[] answer;
    //delete[] check;

    
    
    return 0;
}