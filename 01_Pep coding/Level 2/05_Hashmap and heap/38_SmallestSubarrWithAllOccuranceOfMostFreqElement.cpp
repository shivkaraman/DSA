#include<iostream>
#include<unordered_map>
#include<vector>
#include<cmath>
using namespace std;

class myPair{
public: 
    int freq, si, ei;
     myPair(){
        freq = 0;
        si = -1;
        ei = -1;
     }
    myPair(int f, int s, int e){
        freq = f;
        si = s;
        ei = e;
    }
};

void solution(vector<int> arr) {
	unordered_map<int, myPair> mp;
    int mxfreq = 0;
    // 1. Find most frequent element and its starting and ending index
    for(int i = 0; i < arr.size(); i++){
        int num = arr[i];
        auto it = mp.find(num);
        if(it == mp.end()){
            myPair p(1, i, i);
            mp.insert({num, p});
        }
        else{
            it->second.freq++;
            it->second.ei = i;
        }
        mxfreq = max(mxfreq, mp[num].freq);
    }

    //2. If there are multiple elements with same max freq, the element with smallest substr ie ei-si+1 is selected
    int minNum = 0, minSi = 0, minEi = arr.size();
    for(int i = 0; i < arr.size(); i++){
        auto p = mp.find(arr[i]);
        if(p->second.freq != mxfreq) continue;

        int si = p->second.si;
        int ei = p->second.ei;

        if((ei - si) < (minEi - minSi)){
            minSi = si;
            minEi = ei;
            minNum = p->first;
        }
    }
    cout << minNum << endl;
    cout << minSi << endl;
    cout << minEi << endl;
}


int main() {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0 ; i < n; i++){
		cin >> arr[i];
	}
	solution(arr);
}