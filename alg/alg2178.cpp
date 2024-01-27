#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int N, M;
int** map;
int** check;


void bfs(int x, int y){
    pair<int, int> point = make_pair(x,y);
    queue<pair<int, int>> q;
    q.push(point); // 시작위치 삽입

    // 하우상좌 좌표
    int X[4] = {1, 0, -1, 0};
    int Y[4] = {0, 1, 0, -1};

    while(!q.empty()){  //q가 빌때까지
        pair<int, int> now = q.front();//현재 q
        q.pop();    //꺼내

        bool flag = true;
        for(int i=0;i<4;i++){
            int next_x = now.first + X[i];
            int next_y = now.second + Y[i];
            //check[next_x][next_y] == 0 추가   (방문한적 없는 곳이라는 뜻)
            if(next_x>=0 && next_x < N && next_y >= 0 && next_y < M && map[next_x][next_y] == 1 && check[next_x][next_y] == 0){
                q.push(make_pair(next_x, next_y));
                check[next_x][next_y] = check[now.first][now.second] + 1;
                //이걸 못해서 똑바로 거리가 체킹이 안됐다...

                //달성조건
                if(next_x == N-1 && next_y == M-1){
                    cout<<check[next_x][next_y] +1;
                    return;
                }
            } // 맵 안에 있는 1인 경우
        }
        
    }
}

int main (){
    cin>>N>>M;    
    // map 생성
    map = new int* [N];
    for(int i=0;i<N;i++){
        map[i] = new int[M];
    }

    check = new int*[N];
    for(int i=0;i<N;i++){
        check[i] = new int[M];
    }
    for(int i= 0;i<N;i++){
        for(int j=0;j<M;j++){
            check[i][j] = 0;
        }
    }
    
    for(int i=0;i<N;i++){
        string line;
        cin>> line; //한 줄을 문자열로 읽기
        for(int j=0;j<M;j++){
            map[i][j] = line[j] - '0';  //각 문자를 정수로 변환
        }
    }
    
    bfs(0,0);   //시작
    

    //일단 맵을 2차원 int 배열로 입력 받고,
    // 1, 1부터 출발하는데 count변수를 하나씩 늘린다.
    // queue에서 꺼내서
    // 넣을 인접한 녀석이 -1이거나 0이면 queue에 안 넣고 그냥 버린다.
    // -1을 이미 방문한 곳이라고 가정하고 체크, -1이 아닌 인접한 칸들의 인덱스쌍을 queue에 하나씩 넣는다.
    // queue에서 꺼낸 녀석이 목표한 인덱스면 count를 출력.

    //이거는 count로 거리 재는게 아니다!
    //check 배열에 다음칸 까지의 거리를 쭉쭉 저장해가며 최종거리 반환하기
    // 각 노드에 대한 다음거리가 필요하기 때문에 count같은 단일변수 사용은 불편하다.


    // map 지우기
    for(int i=0;i<N;i++){
        delete[] map[i];
    }
    delete[] map;

    
    return 0;
}