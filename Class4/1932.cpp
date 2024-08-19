#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector <vector<int> > tri(n);
    vector<int> sum(n,0);
    for(int i=0;i<n;i++){
        vector<int> cpsum(n,0);
        for(int j=0;j<n;j++){
            cpsum[j] = sum[j];
        }
        for(int j=0;j<i+1;j++){
            int temp;
            scanf("%d",&temp);
            tri[i].push_back(temp);
            if(i == 0) sum[0] = tri[0][0];
            else if(j == 0) sum[j] = cpsum[j] + tri[i][j];
            else if(j == i) sum[j] = cpsum[j-1] + tri[i][j];
            else sum[j] = max(cpsum[j-1],cpsum[j]) + tri[i][j];
        }
    }
    int max = 0;
    for(int i=0;i<n;i++){
        if(sum[i] > max) max = sum[i];
    }
    printf("%d",max);

}
