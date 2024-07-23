#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool comp(pair<unsigned int,unsigned int> a1,pair<unsigned int,unsigned int> a2)
{
    if(a1.second == a2.second) return a1.first < a2.first;
    return a1.second < a2.second;
}
int main()
{
    int N;
    scanf("%d",&N);
    vector <pair<unsigned int,unsigned int>> arr;
    for(int i =0;i<N;i++){
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        arr.push_back(make_pair(t1,t2));
    }
    sort(arr.begin(),arr.end(),comp);
    
    int ans = 0;
    unsigned int t = arr[0].second;
    ans ++;
    for(int i = 1;i<N;i++){
        if(t <= arr[i].first){
            t = arr[i].second;
            ans++;
        }
    }
    
    printf("%d",ans);
    
}