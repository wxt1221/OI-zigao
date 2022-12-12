#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <stack>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <cassert>
using namespace std;
///#define Online_Judge
#define outstars cout << "***********************" << endl;
#define clr(a,b) memset(a,b,sizeof(a))
#define lson l , mid  , rt << 1
#define rson mid + 1 , r , rt << 1 | 1
#define mk make_pair
#define FOR(i , x , n) for(int i = (x) ; i < (n) ; i++)
#define FORR(i , x , n) for(int i = (x) ; i <= (n) ; i++)
#define REP(i , x , n) for(int i = (x) ; i > (n) ; i--)
#define REPP(i ,x , n) for(int i = (x) ; i >= (n) ; i--)
const int MAXN = 100 + 50;
const int MAXS = 10000 + 50;
const int sigma_size = 26;
const long long LLMAX = 0x7fffffffffffffffLL;
const long long LLMIN = 0x8000000000000000LL;
const int INF = 0x7fffffff;
const int IMIN = 0x80000000;
const int inf = 1 << 30;
#define eps 1e-8
const long long MOD = 1000000000 + 7;
const int mod = 100000;
typedef long long LL;
const double PI = acos(-1.0);
typedef double D;
typedef pair<int , int> pii;
#define Bug(s) cout << "s = " << s << endl;
///#pragma comment(linker, "/STACK:102400000,102400000")
int M , X  ;
double P;
double dp[2][(1 << 15) + 1];
void solve()
{
    int n = 1 << M;
    double *pre = dp[0] , *nxt = dp[1];
    memset(pre , 0 , sizeof(double) * (n + 1));
///    memset(pre , 0 , sizeof(pre)); 这样初始化是不行的，因为pre为一个double型的指针，不是整个数组。
    pre[n] = 1.0;
    for(int r = 0 ; r < M; r++)///枚举第几轮
    {
        for(int i = 0 ; i <= n ; i++)///枚举当前是哪种状态
        {
            int step = min(i , n - i);///如果step大于n / 2 ， 等会儿转移的时候可能会超过n
            double t = 0.0;
            for(int j = 0 ; j <= step ; j++)///枚举当前的所有可能走法
            {
                t = max(t , P * pre[i + j] + (1 - P) * pre[i - j]);///求出期望的最大值
            }
            nxt[i] = t;
        }
        swap(pre , nxt);///交换两个数组的值进行滚动
    }
    int i = (LL)X * n / 1000000;///找到X对应的是第几块
//    for(int i = 0 ; i <= n ; i++)cout << '*' << pre[i] << endl;
    printf("%.6lf\n" , pre[i]);
}
int main()
{
    freopen("C-large-practice.in" , "r" , stdin);
    freopen("C-large-practice.out" , "w" , stdout);
    int t;
    cin >> t;
    FORR(kase ,1 , t)
    {
        scanf("%d%lf%d" , &M , &P , &X);
        printf("Case #%d: " , kase);
        solve();
 
    }
    return 0;
}
