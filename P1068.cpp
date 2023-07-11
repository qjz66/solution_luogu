#include "bits/stdc++.h"

using namespace std;

typedef struct info{
    int number;
    int score;
}infomation;

bool cmp(infomation a, infomation b){
    if(a.score == b.score) return a.number < b.number;
    return a.score > b.score;
}

int main(){
   int n, m, k, s;//n为报名人数 m为录取人数 k为面试分数线 s为面试人数
    cin >> n >> m;
    infomation a[n];
    for(int i =0 ;i < n;i++)
        cin >> a[i].number >> a[i].score;
    sort(a, a + n, cmp);
    s = m * 3 / 2 - 1;
    k = a[s].score;
    for(int j = s;j < n;j++){
        if(a[j].score >= k)
            s++;
        else break;
    }
    cout << k << ' ' << s << endl;
    for(int t = 0;t < s;t++)
        cout << a[t].number << ' ' << a[t].score << endl;
    return 0;
}