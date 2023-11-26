/*
1. You are given a string str.
2. You are required to calculate and print the count of subsequences of the nature a+b+c+.
For abbc -> there are 3 subsequences. abc, abc, abbc
For abcabc -> there are 7 subsequences. abc, abc, abbc, aabc, abcc, abc, abc.
Sample Input
abcabc

Sample Output
7
*/

/*
Storage-& Meaning -> We use 3 arrays a, ab, abc
            a-> No of subsezuences of type a+
            ab-> No of subsezuences of type a+b+
            abc-> No of subsezuences of type a+b+c+
            a[i]-> No of subsequences of type a+ till ith character of original string 
            ab[i]-> No of subsequences of type a+b+ till ith character of original string 
            abc[i]-> No of subsequences of type a+b+c+  till ith character of original string 
Direction -> 0 -> Size
Traverse -> 
    1. If we encoutner an 'a', -> We can append it to only a+ type, and we have three options
        1. To append it to already existing  a+ => Gives a+ no of strings 
        2. Keep already existing a+ as it is    => Gives a+ no of strings 
        3. Start a new sequence with current a  => Gives 1 string
        THEREFORE, no of sequences that can be genereated with already existing a+ is =  2*a+ + 1

    2. If we encoutner a 'b', -> We can append it to only a+ type, and we have two options
        1. To append it to already existion a+b+   => Gives a+b+ no of strings 
        2. Keep already existing a+b+ as it is     => Gives a+b+ no of strings
        3. Append current b to all sequences of a+ => Gives a+ no of strings
        THEREFORE, no of swquences that can be genereated with already existing a+b+ and a+ is =  (2*a+b+) + (a+)

    3. If we encoutner a 'c', -> We can append it to only a+ type, and we have two options
        1. To append it to already existion a+b+c+   => Gives a+b+c+ no of strings 
        2. Keep already existinng a+b+c+ as it is    => Gives a+b+c+ no of strings 
        3. Append current c to all sequences of a+b+ => Gives a+b+ no of strings
        THEREFORE, no of swquences that can be genereated with already existing a+b+c+ and a+b+ is =  2*a+b+c+) + (a+b+)
    
https://www.youtube.com/watch?v=IV9pbZsi5cc&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=21
*/


#include <bits/stdc++.h>
using namespace std;

int count(string s){
    int a = 0, ab = 0, abc = 0;
    for(int i = 1; i <= s.size(); i++){
        if(s[i-1] == 'a')
            a = 2 * a + 1;
        else if(s[i-1] == 'b')
            ab = 2 * ab + a;
        else
            abc = 2 * abc + ab;
    }   
    return abc;
}
int main(){
    string str;
    cin >> str;
    cout << count(str) << endl;
}