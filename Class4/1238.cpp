#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 1000 * 10000 * 100

using namespace std;

// 거리의 최솟값을 구하는 알고리즘
int find_min(vector<int> dist_start, vector<bool> visited_start){
    int min = MAX;
    int min_index = 0;
    for(int i = 1; i<dist_start.size();i++){
        if(visited_start[i] == false){
            if(dist_start[i] < min){
                min = dist_start[i];
                min_index = i;
            }
        }
    }
    return min_index;
}

int main()
{
    int N,X,M; // N명 X마을에서 M개의 도로
    cin >> N >> M >> X;
    int maps[1005][1005];
    //fill(&maps[0][0],&maps[1004][1005],MAX);
    //fill_n(&maps[0][0],1005*1005,MAX);
    for(int i = 1; i<=N;i++){
        for(int j = 1; j<=N;j++){
            if(i == j){
                maps[i][j] = 0;
            }
            else{
                maps[i][j] = MAX;
            }
        }
    }

    for(int i =0 ; i < M ; i++){
        int sX, eX, T_i;
        cin >> sX >> eX >> T_i;
        maps[sX][eX] = T_i;
    }
    //다익스트라 알고리즘 - X에서 출발
    int start = X;
    vector <int> dist_start(N+1,MAX);
    vector <bool> visited_start(N+1,false);
    for(int i = 1; i<=N;i++){
        dist_start[i] = maps[start][i];
        if( i == start){
            dist_start[i] = 0;
        }
    }
    int min_index = find_min(dist_start,visited_start);
    while(min_index != 0){
        visited_start[min_index] = true;
        for(int i = 1; i<=N;i++){
            if(visited_start[i] == false){
                if(dist_start[i] > dist_start[min_index] + maps[min_index][i])
                {
                    dist_start[i] = dist_start[min_index] + maps[min_index][i];
                }
            }
        }
        min_index = find_min(dist_start,visited_start);
    }
    // 다익스트라 - X로 도착
    int end = X;
    vector <int> dist_end(N+1,MAX);
    vector <bool> visited_end(N+1,false);
    for(int i = 1; i<=N;i++){
        dist_end[i] = maps[i][end];
        if( i == end){
            dist_end[i] = 0;
        }
    }
    min_index = find_min(dist_end,visited_end);
    while(min_index != 0){
        visited_end[min_index] = true;
        for(int i = 1; i<=N;i++){
            if(visited_end[i] == false){
                if(dist_end[i] > dist_end[min_index] + maps[i][min_index])
                {
                    dist_end[i] = dist_end[min_index] + maps[i][min_index];
                }
            }
        }
        min_index = find_min(dist_end,visited_end);
    }

    // 최대값 구하기
    int max = 0;
    for(int i = 1; i<=N;i++){
        int dist = dist_start[i] + dist_end[i];
        if(max < dist){
            max = dist;
        }
    }

    cout << max << endl;
}