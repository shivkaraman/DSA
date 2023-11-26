// https://nados.io/question/recurring-sequence-in-a-fraction
// https://www.youtube.com/watch?v=2cRS9dNa780&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=36

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string FractionToDecimal(int numerator, int denominator) {
	if(!numerator) return "0";

	string ans = "";
	if (numerator > 0 ^ denominator > 0) ans += '-';

	long num = labs(numerator), den = labs(denominator);
	long q = num / den;
	long r = num % den;
	ans += to_string(q);
	
	if(r == 0) return ans;
	
	ans += '.';
	unordered_map<long, int> mp;
	while(r != 0){
		if(mp.find(r) != mp.end()){
			int pos = mp[r];
			ans.insert(pos, "(");
			ans += ')';
			break;
		}
		else{
			mp[r] = ans.length();
			r *= 10;
			q = r / den;
			r = r % den;
			ans += to_string(q);
		}
	}
	return ans;
}

int main(){
	int num, den;
	cin >> num;
	cin >> den;

	cout << FractionToDecimal(num, den);
	return 0;
}