#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE long long
#define OUTPUT_DATA_TYPE long long
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

long long w[40],v[40];
long long dp[210];

int main(){
	#ifdef file
	freopen("knapsack.in", "r", stdin);
	freopen("knapsack.out", "w", stdout);
	#endif

    register int i,j;
    int C=read();
    int n=read();
    for(i=0;i<n;++i) w[i]=read(),v[i]=read();
    for(i=0;i<n;++i)
        for(j=w[i];j<=C;++j)
            dp[j]=std::max(dp[j-w[i]]+v[i],dp[j]);

    printf("max=");
    print(dp[C]);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

