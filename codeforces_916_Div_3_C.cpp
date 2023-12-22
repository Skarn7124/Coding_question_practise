/*
C. Quests
time limit per test2.5 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Monocarp is playing a computer game. In order to level up his character, he can complete quests. There are n quests in the game, numbered from 1 to n. 
Monocarp can complete quests according to the following rules:
the 1-st quest is always available for completion;
the i-th quest is available for completion if all quests j<i have been completed at least once.
Note that Monocarp can complete the same quest multiple times.

For each completion, the character gets some amount of experience points:

for the first completion of the i-th quest, he gets ai
 experience points;
for each subsequent completion of the i-th quest, he gets bi experience points.Monocarp is a very busy person, so he has free time to complete no more than k
quests. Your task is to calculate the maximum possible total experience Monocarp can get if he can complete no more than k
 quests.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains two integers n
 and k
 (1≤n≤2⋅105
; 1≤k≤2⋅105
) — the number of quests and the maximum number of quests Monocarp can complete, respectively.

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤103
).

The third line contains n
 integers b1,b2,…,bn
 (1≤bi≤103
).

Additional constraint on the input: the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single integer — the maximum possible total experience Monocarp can get if he can complete no more than k
 quests.

Example
inputCopy
4
4 7
4 3 1 2
1 1 1 1
3 2
1 2 5
3 1 8
5 5
3 2 4 1 4
2 3 1 4 7
6 4
1 4 5 4 5 10
1 5 1 2 5 1
outputCopy
13
4
15
15
Note
In the first test case, one of the possible quest completion sequences is as follows: 1,1,2,3,2,4,4
; its total experience is equal to 4–+1+3–+1–+1+2–+1=13
 (the underlined numbers correspond to the instances when we complete a quest for the first time).

In the second test case, one of the possible quest completion sequences is as follows: 1,1
; its total experience is equal to 1–+3=4
.

In the third test case, one of the possible quest completion sequences is as follows: 1,2,2,2,3
; its total experience is equal to 3–+2–+3+3+4–=15
.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll min(ll a,ll b){
    if(a<b)
        return a;
    return b;
}
ll max(ll a,ll b){
    if(a<b)
        return b;
    return a;
}
ll power(ll a,ll b){
    ll res = 1;
    while(b){
        if(b%2!=0){
            res = res*a;
        }
        a = a*a;
        b = b/2;
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n),b(n);
        for(int i = 0;i<n;i++)
            cin>>a[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        int ans1 = 0,ans = a[0],lb = b[0];
        for(int i = 0;i<n&& i<k;i++){
            ans1 += a[i];
            lb = max(lb,b[i]);
            ans = max(ans,ans1+abs(k-i-1)*lb);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
