/*
1. You are given a string str of digits. (will never start with a 0)
2. You are required to encode the str as per following rules
    1 -> a
    2 -> b
    3 -> c
    ..
    25 -> y
    26 -> z
3. Print all encodings of str.

Use the input-output below to get more understanding on what is required
    123 -> abc, aw, lc
    993 -> iic
    013 -> Invalid input. A string starting with 0 will not be passed.
    103 -> jc
    303 -> No output possible.
*/

#include <iostream>
#include<string>
using namespace std;

//level -> Number(string)
//option-> SINGLE DIGIT OR DOUBLR DIGIT
void printEncoding(string ques, string asf){
    if(ques.length()==0){
        if(asf.size() == 0)
            cout << "No Encodings" << endl;
        else
            cout<<asf<<endl;
        return;
    }
    //Choice 1 --> First one char
    char ch = ques[0];
    string ros = ques.substr(1);
    if(ch == '0')
        return ;
    else{
        int chVal = ch-'0';
        char code = 'a'-1+chVal;
        printEncoding(ros, asf+code);
    }

    //Choice 2 --> First two char's
    if(ques.length() >= 2){
        string ch12 = ques.substr(0,2);
        ros = ques.substr(2);
        int chVal = stoi(ch12);
        if(chVal<=26){
            char code = char('a'-1+chVal);
            printEncoding(ros,asf+code);
        }
    }
}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    return 0;
}