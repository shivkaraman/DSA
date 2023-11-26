#include <iostream>
using namespace std;

//level -> strings
//option-> which would be the first character
void printPermutations(string str, string p){
    if(str.length()==0){
        cout<<p<<endl;
        return;
    }
    for(int i = 0 ; i < str.length(); i++){
        char ch = str[i];
        string ros = str.substr(0,i) + str.substr(i+1);
        printPermutations(ros, p+ch);
    }
    
}

int main(){
    string str; 
    cin>>str;
    printPermutations(str,"");
    return 0;   
}