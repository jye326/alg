#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int N, M;
int** map;
int count;


void bfs(int x, int y){
    pair<int, int> point = make_pair(x,y);
    queue<pair<int, int>> q;
    q.push(point);//시작위치 삽입
    while(!q.empty()){  //q가 빌때까지
        pair<int, int> now = q.front();//현재 q
        //아래부터 순서대로 경계가 아니면서 1인칸을 pair로 만들어서 q에 넣자.
        
    }

}

int main (){
    cin>>N>>M;    
    // map 생성
    map = new int* [N];
    for(int i=0;i<N;i++){
        map[i] = new int[M];
    }
    
    
    for(int i=0;i<N;i++){
        string line;
        cin>> line; //한 줄을 문자열로 읽기
        for(int j=0;j<M;j++){
            map[i][j] = line[j] - '0';  //각 문자를 정수로 변환
        }
    }
    
    
    //출력
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<map[i][j];
        }cout<<endl;
    }

    // 탐색시작하기 전 count 초기화
    count = 1;
    
    bfs(0,0);   //시작
    

    //일단 맵을 2차원 int 배열로 입력 받고,
    // 1, 1부터 출발하는데 count변수를 하나씩 늘린다.
    // queue에서 꺼내서
    // 넣을 인접한 녀석이 -1이거나 0이면 queue에 안 넣고 그냥 버린다.
    // -1을 이미 방문한 곳이라고 가정하고 체크, -1이 아닌 인접한 칸들의 인덱스쌍을 queue에 하나씩 넣는다.
    // queue에서 꺼낸 녀석이 목표한 인덱스면 count를 출력.


    // map 지우기
    for(int i=0;i<N;i++){
        delete[] map[i];
    }
    delete[] map;

    system("pause");
    return 0;
}