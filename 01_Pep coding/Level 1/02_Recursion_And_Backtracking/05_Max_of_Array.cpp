#include <iostream>
#include <climits>
using namespace std;


int Max(int arr[], int idx, int n){
    if(n == 0)
        return arr[0];
    int nm1 = Max(arr, idx+1, n-1); //Faith --> the function knows to find maximum of arr[1]-arr[n-1]
    return max(nm1, arr[idx]);      //Returning max of zeroth element and rest of array
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int p = Max(arr, 0, n);
    cout << p << endl;
    return 0;
}
