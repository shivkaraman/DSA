/*
1. You are given a number.
2. You have to print all the numbers from 1 to n in lexicographical order.

n = 1000
1                               2      
10   11   12 ..........19       20
100  110  120..........190      200
101  111  121..........191      .   
102  112  122..........192      .
103  113  123..........193      .
104  114  124..........194      SO ON
104  115  125..........195
106  116  126..........196
107  117  127..........197
108  118  128..........198
109  119  129..........199

                                -
                            / //  \\
                          / / /    \ \
                        /  / /      \  \
                       1  2  3.......8  9
                    // \
                  / /   \
                10 11...19
              // \
            / /   \
         100 101 ..109
*/
#include<iostream>
using namespace std;

// Expectation -> print 1 and family of 1
// faith : lo already knows to print family of 10
// E-F : print 1 and call func to print family of 10
void lo(int i, int n){
	if(i > n)
        return;
    cout << i << endl;
	for(int x = 0; x < 10; x++){
		lo(10 * i + x, n);
	}
}
	
int main(){
	int n;
	cin>>n;
	for(int i = 1; i < 10; i++){
		lo(i, n);
	}
}