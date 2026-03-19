#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,d,p;
struct node{
    int a,b;
    bool operator <(const node& t){
        //if(b!=t.b) return b<t.b;对于使用滑动窗口来做这个题目，只需要保证这个窗口的时间合法性就可以了即小于d的时候就是合法的，所以不用对帖子编号排序只需要对ts排序，然后有一个cnt数组把每一个帖子在合法区间里面的点赞数记录下来，同时，如果左边界要从这个滑动窗口出去的话，那么这个cnt数组此时要把这个过时的帖子获赞数--
        //只需要保证[T,T+D)的区间里面的真是获赞数即可
        return a<t.a;
    }
};
node arr[maxn];
int cnt[maxn];
bool hot[maxn];//hot数组此时有两个作用，第一个作用就是防止重复输出同一个帖子，因为有可能一个帖子在两个时间段都有可能成为热帖；第二个作用就是让帖子按照从小到大的时间输出出来，因为可能10号帖子比1号帖子先一步成为热帖
int main(){
    cin>>n>>d>>p;
    for(int i=1;i<=n;i++){
        cin>>arr[i].a>>arr[i].b;
    }
    sort(arr+1,arr+n+1);//这块的sort一定要是arr+n+1
    //下面将用双指针和滑动窗口来解决
    for(int i=0,j=0;j<=n;j++){
        int id=arr[j].b;
        cnt[id]++;
        //如果窗口不合法了，就要进行以下操作
        //这个窗口里面永远可以知道这个窗口里面的各个帖子的真实获赞数
        while(arr[j].a-arr[i].a>=d){
            int left=arr[i].b;
            cnt[left]--;
            i++;
        }
        if(cnt[id]>=p){
            hot[id]=true;
        }
    }
    for(int i=0;i<maxn;i++){//一定要注意数组访问千万不能越界
        if(hot[i]==true){
            cout<<i<<endl;
        }
    }
    return 0;
}