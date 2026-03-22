#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
unordered_set<long long> se;
//将任意进制的字符串转换为十进制函数
long long f1(string s,int base){
    long long res=0;
    for(char ch: s){
        int d;
        if(isdigit(ch)){
            d=ch-'0';
        }else{
            d=toupper(ch)-'A'+10;
        }
        res=res*base+d;
    }
    return res;
}
//将十进制转换为任意进制的字符串
string f2(int n,int base){
    string s="";
    while(n>0){
        int res=n%base;
        if(res<10){
            s+=to_string(res);
        }else{
            s+=res-10+"A";
        }
        n/=base;
    }
    return s;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    for(int i=0;i<n;i++){
        if(s1[i]=='0'){
            s1[i]='1';
            se.insert(f1(s1,2));
            s1[i]='0';
        }else{
            s1[i]='0';
            if(s1[0]!=0||n==1)
            se.insert(f1(s1,2));
            s1[i]='1';
        }
    }
    for(int i=0;i<m;i++){
        long long res;
        if(s2[i]=='0'){
            s2[i]='1';
            res=f1(s2,3);
            if(se.count(res)){
                cout<<res;
                return 0;
            }
            s2[i]='2';
            res=f1(s2,3);
            if(se.count(res)){
                cout<<res;
                return 0;
            }
            s2[i]='0';
        }
                if(s2[i]=='1'){
            s2[i]='2';
            res=f1(s2,3);
            if(se.count(res)){
                cout<<res;
                return 0;
            }
            s2[i]='0';
            if(s2[0]!='0'||m==1){
                     res=f1(s2,3);
            if(se.count(res)){
                cout<<res;
                return 0;
            }
            }
       
            s2[i]='1';
        }
                if(s2[i]=='2'){
            s2[i]='0';
            if(s2[0]!='0'||m==1){//这个题目要特别注意前导0，比如1110，不可能是6，因为6是110，这个人不会让前导零0110出现
                         res=f1(s2,3);//其次还要注意本来就是一个数字的情况，这个情况下可以允许前导0的出现
            if(se.count(res)){
                cout<<res;
                return 0;
             }
            }
   
            s2[i]='1';
            res=f1(s2,3);
            if(se.count(res)||m==1){
                cout<<res;
                return 0;
            }
            s2[i]='2';
        }
    }
    return 0;
}