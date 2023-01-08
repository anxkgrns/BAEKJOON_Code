#include<iostream>
using namespace std;

//bubble sort
int main(){
    int n;
    int* arr = new int[1000];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i; j<n;j++){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
        cout << arr[i] << endl;
    }
}   
//counting sort
// int main(){
//     int n;
//     int* arr = new int[1000];
//     cin >> n;
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     int* pcount = new int[1001];
//     int* mcount = new int[1001];
//     for(int i=0; i<=1000; i++){
//         pcount[i] = 0;
//         mcount[i] = 0;
//     }
//     for(int i=0; i<n; i++){
//         if(arr[i] >= 0){
//             pcount[arr[i]]++;
//         }
//         else{
//             mcount[-arr[i]]++;
//         }
//     }
//     for(int i=1000; i>=0; i--){
//         for(int j=0; j<mcount[i]; j++){
//             cout << -i << endl;
//         }
//     }
//     for(int i=0; i<=1000; i++){
//         for(int j=0; j<pcount[i]; j++){
//             cout << i << endl;
//         }
//     }
// }

//quick sort
// void swap(int& a, int& b){
//     int temp = a;
//     a = b;
//     b = temp;
// }
// int partition(int* arr, int left, int right){
//     int pivot = arr[left];
//     int i = left;
//     int j = right;
//     while(i < j){
//         while(arr[i] <= pivot && i < right){
//             i++;
//         }
//         while(arr[j] > pivot){
//             j--;
//         }
//         if(i < j){
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[left], arr[j]);
//     return j;
// }
// void quickSort(int* arr, int left, int right){
//     if(left < right){
//         int pivot = partition(arr, left, right);
//         quickSort(arr, left, pivot-1);
//         quickSort(arr, pivot+1, right);
//     }
// }
// int main(){
//     int n;
//     int* arr = new int[1000];
//     cin >> n;
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     quickSort(arr, 0, n-1);
//     for(int i=0; i<n; i++){
//         cout << arr[i] << endl;
//     }
// }