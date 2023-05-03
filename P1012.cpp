#include "iostream"
#include "algorithm"
using namespace std;

bool cmp(string a, string b);

int main(){
    int n;
    cin >> n;
    string numbers[n];
    for(int i = 0;i < n;i++){
        cin >> numbers[i];
    }
    sort(numbers, numbers + n, cmp);
    for(int j = 0;j < n;j++)
        cout << numbers[j];
}

bool cmp(string a, string b){
    return a + b > b + a;
}