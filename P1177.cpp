#include "bits/stdc++.h"

using namespace std;

void quicksort(int a[], int left, int right);
//int a[100005];
int main(){
    /*int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++)
        cin >> a[i];
    quicksort(a, 0, n - 1);
    for(int j = 0;j < n;j++)
        cout << a[j] << ' ';*/
    for(int i = 1;i <= 100000;i++)
        printf("%d ",i);
    return 0;
}

void quicksort(int a[], int left, int right){
    if(left >= right) return;
    int i = left, j = right, flag = a[left], temp;
    while(true){
        while(a[j] >= flag && j != i)
            j--;
        while(a[i] <= flag && j != i)
            i++;
        if(i >= j) break;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    temp = a[i];
    a[i] = a[left];
    a[left] = temp;
    quicksort(a,left,i - 1);
    quicksort(a,i + 1,right);
}

/*#include<iostream>
using namespace std;
int n,a[100005];
void swap(int &a,int &b){
    int t=a;
    a=b;
    b=t;
}
void sort(int a[],int l,int r){
    int i=l,j=r,flag=a[(l+r)/2];
    do{
        while(a[i]<flag){
            i++;
        }
        while(a[j]>flag){
            j--;
        }
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(l<j){
        sort(a,l,j);
    }
    if(i<r){
        sort(a,i,r);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}*/