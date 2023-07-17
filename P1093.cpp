#include "bits/stdc++.h"

using namespace std;

typedef struct student{
    int id;
    int chinese;
    int sum;
}student;

int n;

bool cmp(student a, student b){
    if(a.sum == b.sum){
        if(a.chinese == b.chinese) return a.id < b.id;
        return a.chinese > b.chinese;
    }
    return a.sum > b.sum;
}


int main(){
    int  tmp1, tmp2;
    cin >> n;
    student a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i].chinese >> tmp1 >> tmp2;
        a[i].sum = a[i].chinese + tmp1 + tmp2;
        a[i].id = i + 1;
    }
    sort(a, a + n, cmp);
    for(int i = 0;i < 5;i++)
        cout << a[i].id << ' ' << a[i].sum << endl;
}