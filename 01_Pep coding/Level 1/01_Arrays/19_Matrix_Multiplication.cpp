//Given two 2d arrays with dimensions n1xn2 n2xn3, multiply the two matrices-->n1xn3

#include <iostream>
using namespace std;

int main(){
    int m1[3][4]={2,4,1,2,
                  8,4,3,6,
                  1,7,9,5};
    int m2[4][3]={1,2,3,
                  4,5,6,
                  7,8,9,
                  4,5,6};
    int m[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int sum=0;
            for(int k=0;k<4;k++)
                sum += m1[i][k]*m2[k][j];
            m[i][j]=sum;
        }
    }
    cout<<"Multiple of two matrices : "<<endl;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}