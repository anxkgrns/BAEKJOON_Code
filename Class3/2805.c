#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int N;
    long long M;
    scanf("%d %lld",&N,&M);
    vector<int> tree(N);
    int max = 0;
    for(int i=0;i<N;i++){
        scanf("%d",&tree[i]);
        if(max<tree[i]) max = tree[i];
    }
    int top = max;
    int bot = 0;
    int ans = 0;
    while(bot <= top){
        long long mid = (top+bot)/2;
        long long sum = 0;
        for(int i = 0 ;i< N;i++){
            if(tree[i] > mid){
                sum = sum + tree[i] - mid;
            }
        }
        if(sum >= M){
            if( ans < mid) ans = mid;
            bot = mid+1;
        }
        else if(sum < M){
            top = mid-1;
        }
    }
    printf("%d",ans);
    
}