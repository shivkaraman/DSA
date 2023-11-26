/*
1. You are given N strings which represents N different skills related to I.T field.
2. You are working on a project and you want to hire a team of software developers for that project.
3. There are N applicants. Every applicant has mentioned his/her skills in resume.
4. You have to select the minimum number of developers such that for every required skill, there is 
     at least one person in the team who has that skill.
5. It is guaranteed that you can form a team which covers all the required skills.

Sample Input
    3
    java nodejs reactjs
    3
    1
    java
    1
    nodejs
    2
    nodejs
    reactjs

Sample Output
[0, 2]
*/

#include<bits/stdc++.h>
using namespace std;

/*
    skill set- > a b c d e
    person      skills
      1 -> a c
      2 -> b d
      0 -> a b c d
      3 -> e
    
    we represent skill set using bits
    a -> 0th bit, b - 1st bit .......... e - 4th bit
    ie 11111
    For person, we turn on correcponnding bit
        e d c b a
    a-> 0 0 1 0 1 
    b-> 0 1 0 1 0
    c-> 0 1 1 1 1
    d-> 1 0 0 0 0

    We gererate substring of people
    if selected set of persons satisfy given cindition, bitwise OR operation btw
    skills of each selected person would give 11111
*/

string sol;
void solution(vector<int>& people,int nskills,int person,string oneSol,int smask){
   if(person == people.size()){
        if(smask == (1 << nskills)-1){
            if(sol.size() == 0 || oneSol.size() <= sol.size())
                sol = oneSol;
        }
        return;
   }
   //Person ayega
   solution(people, nskills, person + 1, oneSol + to_string(person) + ", ", (smask | people[person]));
   //Person nahi ayega
   solution(people, nskills, person + 1, oneSol, smask);
}


int main(){
    int n;
    cin>>n;

    //Maping bit no to skill
    unordered_map<string ,int>smap;
    for(int i=0;i<n;i++){
        string x;
        cin >> x;
        smap[x] = i;
    }

    int np;
    cin >> np;

    vector<int> people(np);

    for(int i = 0; i < np; i++){
        int noOfSkills;
        cin >> noOfSkills;

        for(int j = 0; j < noOfSkills; j++){
            string skill;
            cin >> skill;

            int snum = smap[skill]; //Getting bit no of current skill
            people[i] = people[i]|(1<<snum);  //Turning on bit of current skill
        }
    }

    solution(people, n, 0, "", 0);

    sol.pop_back();
    sol.pop_back();
    cout << "[" << sol << "]" << endl;

}