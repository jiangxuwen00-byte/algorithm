#include<iostream>
using namespace std;
const int maxn=100005;
int n;
int arr[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int depth=1;
    long long sum=-1e8;
    int res;
    for(int l=1,r=l;l<=n;){
        int count=1;
        long long  ans=0;
        for(int j=0;j<depth-1;j++){
            count*=2;
        }
        for(int i=r;i<r+count&&i<=n;i++){
            ans+=arr[i];
        }
        if(ans>sum){
            sum=ans;
            res=depth;
        }
        depth++;
        l*=2;
        r=l;
    }
    cout<<res;
    return 0;
}
//同样的代码，洛谷可以通过但是acwing不行，原因就是我把sum的初值设置成了0，没有考虑到ans为负值的情况，就会导致sum一直不被赋值，这样就会产生错误，从而导致res和sum一直不被更新，正确的做法是把其赋值为负无穷大
//其次就是sum和ans的类型应该是longlong类型，如果是int类型的话就会爆掉