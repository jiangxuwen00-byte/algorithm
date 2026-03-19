#include<iostream>
#include<string>
using namespace std;
int n;
string s;
int main(){
    cin>>n>>s;
    int len=s.length();
    int ans=0;
    for(int l=0,r=2;r<len;l++,r++){
        if(s[l]=='x'&&s[r]=='x'){
            if(s[l+1]=='x'){
                ans+=1;
            }
        }
    }
    cout<<ans;
    return 0;
}