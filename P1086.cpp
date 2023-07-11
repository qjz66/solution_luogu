#include "bits/stdc++.h"

using namespace std;

typedef struct peannut{
    int x;
    int y;
    int num;
}peanut;

#define maxn 400

peanut a[maxn], now;
int row, column, maxtime;

void mergesort(peanut a[], peanut temp[], int start, int end);

int main(){
    int tmp, k = 0, len = 0, sum = 2, ans = 0;
    cin >> row  >> column >> maxtime;
    for(int i = 0;i < row;i++)
        for(int j = 0;j < column;j++){
            cin >> tmp;
            if(tmp > 0){
                a[k].y = i;
                a[k].x = j;
                a[k++].num = tmp;
            }
        }
    while(a[len + 1].num != 0)
        len++;
    peanut b[len + 1];
    mergesort(a, b, 0, len);
    now.y = 0; 
    for(int i = 0;i <= len;i++){
        if(i == 0) now.x = a[i].x;
        if(sum + abs(now.x - a[i].x) + abs(now.y - a[i].y) + a[i].y + 1 <= maxtime){
            ans += a[i].num;
            sum += 1;
        }
        sum += abs(now.x - a[i].x) + abs(now.y - a[i].y);
        now = a[i];
    }
    cout << ans << endl;
    return 0;
}

void mergesort(peanut a[], peanut temp[], int start, int end){
    if(start == end) return;
    int mid = (start + end) / 2;
    int start1 = start; int start2 = mid + 1; int k = start;
    int end1 = mid; int end2 = end;
    mergesort(a, temp, start1, end1);
    mergesort(a, temp, start2, end2);
    while(start1 <= end1 && start2 <= end2)
        temp[k++] = a[start1].num < a[start2].num ? a[start2++] : a[start1++];
    while(start1 <= end1)
        temp[k++] = a[start1++];
    while(start2 <= end2)
        temp[k++] = a[start2++];
    for(int i = start;i <= end;i++)
        a[i] = temp[i];
}