#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;
const int INF = ((1<<30)-1);
int N, M, K, X;

vector<vector<int>> graph; //도시정보
vector<int> dist;   // X로부터의 거리를 저장할 vector
vector<int> result; // 거리가 K인 도시를 저장

void bfs(){
    int start = X;  //X번 도시에서 시작
    dist[X] = 0;

    list<int> queue;    //queue 역할이 뭐지?    // 탐색해야 할 도시들을 순서대로 저장하는 데 사용
    queue.push_back(X);

    while(!queue.empty()){
        //now에 queue의 맨 앞을 pop한다.
        int now = queue.front();
        queue.pop_front();
        
        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i];   //다음 도시 번호를 가져옵니다.
            if(dist[next] == -1){   //해당 도시를 아직 탐색하지 않았다면
                dist[next] = dist[now] + 1;// 현재 도시의 거리 +1로 거리를 기록함
                queue.push_back(next);  //그 후 다음 도시를 queue에 삽입후 재탐색? 이건 뭐지?
            }
        }
    }
    for(int i=0;i<=N;i++){
        if(dist[i] == K)    // 거리가 K인 도시 번호를 result 오름차순으로 벡터에 삽입
            result.push_back(i);
    }
}


int main(){
    // 도시 수, 도로 수, 거리정보, 출발 도시 번호
    cin>>N>>M>>K>>X;

    graph = vector<vector<int>>(N+1);   //그래프 생성
    dist = vector<int>(N+1, -1);    // 거리벡터 생성

    for(int i=0;i<M;i++){
        int from, to;
        cin>>from>>to;
        graph[from].push_back(to);
    }

    bfs();
    if(result.size() == 0)
        cout<< -1;
    else{
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<endl;
        }
    }
    
    return 0;
}

