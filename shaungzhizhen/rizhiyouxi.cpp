#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,d,p;
struct node{
    int a,b;
    bool operator <(const node& t){
        if(b!=t.b) return b<t.b;
        return a<t.a;
    }
};
node arr[maxn];
int check(int l,int r){
    int k;
    for(int i=l;i<=r;i++){
        k=i;
        while(arr[k+1].a-arr[i].a<d&&k<r) k++;
        if(k-i+1>=p) return 1;
    }
    return 0;
}
int main(){
    cin>>n>>d>>p;
    for(int i=1;i<=n;i++){
        cin>>arr[i].a>>arr[i].b;
    }
    sort(arr+1,arr+n+1);//这块的sort一定要是arr+n+1
    int r;
    for(int l=1;l<=n;){//这样对l进行增加是错误的，因为比如说l是11，然后这个编号有四个也就是r现在等于16了，我现在希望l=16，结果呢，11+15等于26，跳过了，所以这个只适用于l=1的时候
        r=l;
        while(arr[r].b==arr[l].b) r++;//其实以后像这种要找到r的精准位置的可以这样写arr[r+1].b==arr[l].b,这样就会让r精准的落到你想要的位置
        if(check(l,r-1)){
            cout<<arr[l].b<<endl;
        }
        l=r;
    }
    return 0;
}