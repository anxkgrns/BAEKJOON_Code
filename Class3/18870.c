#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second; // 정확한 비교를 위해 '<' 사용
}

int main() {
    int N;
    scanf("%d", &N);
    vector<pair<int, int>> v;
    vector<int> v1;
    vector<int> ans(N); // 벡터 크기 수정
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        v.push_back(make_pair(i, temp));
        v1.push_back(temp);
    }
    sort(v.begin(), v.end(), cmp);
    int temp = -1; // 초기화
    int num = 0;
    for (int i = 0; i < N; i++) {
        if (i > 0 && temp == v[i].second) {
            ans[v[i].first] = ans[v[i - 1].first];
        }
        else {
            ans[v[i].first] = num;
            num++;
        }
        temp = v[i].second;
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}
