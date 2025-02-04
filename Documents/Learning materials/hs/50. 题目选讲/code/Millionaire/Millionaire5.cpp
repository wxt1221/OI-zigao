/*Millionaire 2008APAC local onsites C
题意：最开始你有X元钱，要进行M轮赌博。
每一轮赢的概率为P，你可以选择赌与不赌，
如果赌也可以将所持的任意一部分钱作为赌注
（可以是整数，也可以是小数）。如果赢了，赌注将翻倍；
输了赌注则没了。在M轮赌博结束后，如果你持有的钱在100万元以上，
就可以把这些钱带回家。问：
当你采取最优策略时，
获得100万元以上的钱并带回家的概率是多少。
限制:P∈[0,1]
X∈[1,1000000]
M∈[1,15]
EG：输入 M=1 P=0.5 X=50000
输出 0.50000 (保留5位小数)
  解:
  分析：由于每一轮的赌注是任意的，不一定为整数，因而有无限种可能
  穷竭搜索是无法实现的。
  但细细的想一下 >>>每个过程采取最优策略  
  在最后一次的赌注时 你有钱数为x
  如果钱数x>100万，则没有必要再赌了即赢的概率为1；
  如果50<= x < 100万，只要参与赌博并且赌注>= 50万则有赢的概率为P；
  如果x< 50万，那么无论是否参与最后一轮的赌博，压的赌注是多少赢的概率必为0。
  图像如下:
  ^概率
  |                                          值
  |
  |                         ___________       1
  |                         .
  |           ______________.                 p
  |           .             .
  |           .             .
  |           .             .
  |           .             .
  0|0_________50万_________100万_______》金额 0
  最后一轮带钱回家的概率
  考虑最后二轮  同理有5种情况
  ^概率                                        值
  1|                          _________        1
  |                          .
  |                  ________.                 p
  |                  .       .
  |            ______.       .                 (p+p*p)/2
  |            .     .       .
  |     _______.     .       .                 p*p
  |     .      .     .       . 
  |     .      .     .       .      
  0|0___25____50万___75万___100万_______》金额  0
  最后两轮带钱回家的概率
  综上，当参与M轮赌博时所需考虑的情况总共有2^m + 1种
  动态规划: 枚举每种情况的期望，找到最优步骤即可
  
*/
# include <stdio.h>
# define QQ 15//最大值
# define max(a,b)((a)>(b)?(a):(b))
# define min(a,b)((a)<(b)?(a):(b))
double DP[2][1<<QQ+1]={0};//因为下一轮的概率只和当前轮的状态有关 所以只定义两行  用DP数组滚动
int main(){
    int m,w,x;
	int i,j,k,n,Flag[2]={0,1};
	double p=0,UU=0;    //1<<M+1=2^M+1=32768
    scanf("%d %lf %d",&m,&p,&x);
	n=1<<m;//n保存2^M 即2^M+1个DP位置
	DP[0][n]=1.0;//第n个位置对应资金大于1000000的概率
    for(i=0;i<m;i++)//共m轮循环
	{
	   for(j=0;j<=n;j++)
	   {
	       w=min(j,n-j);
           UU-=UU;//将UU变为0
		   for(k=0;k<=w;k++)
			   UU=max(UU,p*DP[Flag[0]][j+k]+(1-p)*DP[Flag[0]][j-k]);//UU存储进行下一轮赌博的最大概率
		 DP[Flag[1]][j]=UU;
	   }      //Flag[0]记录的永远是当前状态
      Flag[0]=1-Flag[0];//Flag[0]=0时 改为1  否则为1时改为0
	  Flag[1]=1-Flag[1];//用Flag[0]-[1]变换  降低空间复杂度
	}
	printf("%.5lf",DP[Flag[0]][(__int64)x*n/1000000]);
	return 0;
}
