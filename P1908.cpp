#include "bits/stdc++.h"

using namespace std;

//int b[500001];
int n;
long long ans = 0;

void mergesort(int a[], int temp[], int start, int end);

int main(){
    scanf("%d", &n);
    int a[n], b[n];
    for(int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    mergesort(a, b, 0, n - 1);
    printf("%lld", ans);
}

void mergesort(int a[], int temp[], int start, int end){
    if(start == end) return;
    int mid = (start + end) / 2;
    int start1 = start; int start2 = mid + 1; int k = start;
    int end1 = mid; int end2 = end;
    mergesort(a, temp, start1, end1);
    mergesort(a, temp, start2, end2);
    while(start1 <= end1 && start2 <= end2){
        if(a[start1] > a[start2]){
            temp[k++] = a[start2++];
            ans += mid + 1 -start1;
        }else{
            temp[k++] = a[start1++];
        }
    }
    while(start1 <= end1)
        temp[k++] = a[start1++];
    while(start2 <= end2)
        temp[k++] = a[start2++];
    for(int i = start;i <= end;i++)
        a[i] = temp[i];
}