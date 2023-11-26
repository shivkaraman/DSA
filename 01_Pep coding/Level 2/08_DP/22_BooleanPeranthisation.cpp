// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

#include <iostream>
#include <vector>
using namespace std;

int solution(string str){
    string oprnd, oper;
    for(char ch : str){
        if(ch == 'T' || ch == 'F')
            oprnd.push_back(ch);
        else    
            oper.push_back(ch);
    }

    int n = oprnd.size();
    vector<vector<int>> dpt(n, vector<int> (n, 0));
    vector<vector<int>> dpf(n, vector<int> (n, 0));

    for(int g = 0; g < n; g++){
        for(int i = 0, j = g; j < n; i++, j++){
            if(g == 0){
                if(oprnd[i] == 'T')
                    dpt[i][j] = 1;
                else    
                    dpf[i][j] = 1;
            }
            else{
                for(int k = i; k < j; k++){
                    char op = oper[k];
                    int ltc = dpt[i][k];
                    int rtc = dpt[k+1][j];
                    int lfc = dpf[i][k];
                    int rfc = dpf[k+1][j];

                    if (op == '&') {
                        dpt[i][j] += ltc * rtc;
                        dpf[i][j] += ltc * rfc + lfc * rtc + lfc * rfc;
                    } 
                    else if (op == '|') {
                        dpt[i][j] += ltc * rtc + ltc * rfc + lfc * rtc;
                        dpf[i][j] += lfc * rfc;
                    } 
                    else if (op == '^') {
                        dpt[i][j] += ltc * rfc + lfc * rtc;
                        dpf[i][j] += ltc * rtc + lfc * rfc;
                    }
                }
            }
        }
    }
    return dpt[0][n-1];
}

int main(){
    string s;
    cin >> s;

    cout << solution(s);
    return 0;
}