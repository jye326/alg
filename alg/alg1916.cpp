#include <iostream>
#include <algorithm>

using namespace std;

const int INF = (1<<30)-1;

int N, M; //N 도시 수, M 버스 수
int** map;  // 2차원배열 map 동적할당
bool* check;    // 방문여부 체크    //1차원으로 충분한가?
int start, dest; // 최종 출발지, 목적지
int* answer;    // 최소거리배열


int getSmallIndex(){    // answer 중에 미방문 최소거리 인덱스를 반환한다.
    int min = INF;
    int minIdx = -1;
    for(int i=0;i<N;i++){
        if(!check[i] && answer[i]<min){
            min = answer[i];
            minIdx = i;
        }
    }
    return minIdx;
}

int main (){
    cin>>N>>M;
    
    map = new int*[N];  //행 할당
    for (int i=0;i<N;i++){
        map[i] = new int[N];    // 열 할당
    }



    check = new bool[N];    //방문여부 체크
    //초기화
    for (int i = 0; i < N; i++) {
        check[i] = false;
    }
    
    //맵 생성
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            map[i][j] = INF;
        }
    }
    //자기 자신으로의 거리는 0으로 설정, 생각보다 중요함
    for(int i=0;i<N;i++){
        map[i][i] =0;
    }

    //버스정보 입력받기
    for(int i=0;i<M;i++){
        int f, to, cost;
        cin>> f >> to>>cost;
        if(map[f-1][to-1]>cost)
            map[f-1][to-1] = cost;
    }

    // 최종 출발지, 목적지 입력
    cin>>start>>dest;
    
    // 정답 배열 연결
    //answer = map[start-1];    //이렇게 하면 왜 안돼?
    answer = new int[N];    //초기화 해야지
    for(int i=0;i<N;i++){
        answer[i] = map[start-1][i];
    }



    //출력
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         if(map[i][j] == 200000){
    //             cout<<"INF"<<" ";
    //         }else{
    //             cout<<map[i][j]<<" ";
    //         }
    //     }cout<<endl;
    // }
    // 최단거리 갱신하기
    // 목표 배열에서 비용이 작은 순서대로 방문, 방문하지 않은 도시들만
    // 방문한 도시를 통해서 가는 비용이 기존 비용보다 작은 경우 해당 비용을 갱신함
    for(int i=0;i<N;i++){
        int t = getSmallIndex();
        if(t != -1){
            check[t] = true;
            for(int j = 0;j<N;j++){
                answer[j] = min(answer[j], answer[t]+ map[t][j]);
                // 정답 교체되면 map도 교체를 해야되나?
            }
        }else{
            break;  // 루프 종료
        }
    }
    //출력
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         if(map[i][j] == 200000){
    //             cout<<"INF"<<" ";
    //         }else{
    //             cout<<map[i][j]<<" ";
    //         }
    //     }cout<<endl;
    // }
    //최종 결과 출력
    printf("%d", answer[dest-1]);

    //memory 누수방지
    for (int i = 0; i < N; i++) {
        delete[] map[i];
    }
    delete[] map;
    delete[] check;
    delete[] answer;


    system("pause");    //외부터미널 사용으로 인한 자동종료를 방지하기 위해 필요함
    return 0;
}


