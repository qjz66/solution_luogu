#include "bits/stdc++.h"

using namespace std;

int n, r, q;//有2*n名选手 r为轮数 q为关心的名次

typedef struct player{
    int number;
    int score;
    int capility;
}player;

bool cmp(player a, player b){
    if(a.score == b.score) return a.number < b.number;
    return a.score > b.score;
}

void merge(player a[], int start, int end);

int main(){
    cin >> n >> r >> q;
    player a[2 * n];
    for(int i = 0;i < 2 * n;i++)
        a[i].number = i + 1;
    for(int i = 0;i < 2 * n;i++)
        cin >> a[i].score;
    for(int i = 0;i < 2 * n;i++)
        cin >> a[i].capility;
    sort(a, a + 2 * n, cmp);
    for(int j = 0;j < r;j++){
        for(int s = 0;s < 2 * n - 1;s = s + 2){
            if(a[s].capility < a[s + 1].capility)
                a[s + 1].score += 1;
            else a[s].score += 1;
        }
        merge(a, 0, 2 * n - 1);
    }
    sort(a, a + 2 * n, cmp);
    cout << a[q - 1].number;
    return  0;
}

void merge(player a[], int start, int end){
    if(start == end) return;
    int start1, start2, end1, end2, mid, t = start;
    player temp[2 * n];
    mid = (start + end) / 2;
    start1 = start; start2 = mid + 1;
    end1 = mid; end2 = end;
    merge(a, start1, end1);
    merge(a, start2, end2);
    while(start1 <= end1 && start2 <= end2)
        temp[t++] = a[start1].score > a[start2].score?a[start1++]:a[start2++];
    while(start1 <= end1)
        temp[t++] = a[start1++];
    while(start2 <= end2)
        temp[t++] = a[start2++];
    for(int i = start;i < end;i++)
        a[i] = temp[i];
}
