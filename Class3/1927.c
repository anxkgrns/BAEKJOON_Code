#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    priority_queue<int,vector<int>,greater<int>> heap;
    for(int i=0;i<N;i++){
        int temp;
        scanf("%d",&temp);
        if(temp == 0){
            if(heap.empty()){
                printf("0\n");
            }
            else{
                printf("%d\n",heap.top());
                heap.pop();
            }
        }
        else{
            heap.push(temp);
        }
    }
    
}