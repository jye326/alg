#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N;  // 노드 수
vector<vector<int>> map;    //간선정보
queue<int> q;   //bfs용
int* check; // 중복조회 방지 & 최종정답저장용
void bfs(){
    q.push(1);  // 시작노드를 삽입
    while(!q.empty()){
        int now = q.front();
        q.pop();
        //앞에거 빼서 연결된 노드들 queue에 삽입
        for(int next : map[now-1]){
            if(check[next-1]==-1){  //미방문이면
                q.push(next);//queue에 삽입 후
                check[next-1] = now;    //루트노드를 기록한다.
            }
        }
    }
    for(int i=1;i<N;i++){
        cout<<check[i]<<"\n";
    }
    return;
}
int main(){
    //c++ 입출력 시간관리 세트
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    //여기에 endl대신 "\n"까지!

    cin>>N;
    map.resize(N);
    for(int i=0;i<N-1;i++){
        int f, t;
        cin>>f>>t;
        map[f-1].push_back(t);
        map[t-1].push_back(f);
        // 무방향이니까 둘다 넣어주고
        // 인덱스니까 1 빼기
    }
    check = new int[N]; //check 동적할당
    for(int i=0;i<N;i++){
        check[i] = -1;  //-1로 초기화(미방문 노드)
    }
    bfs();
    delete[] check;
    //system("pause");
    return 0;
}