#include<cstdio>
#define file

int read();

int main(){
	#ifdef file
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	#endif

	register char a=0;
	a+=getchar()-'0';
	a+=getchar()-'0';
	a+=getchar()-'0';
	a+=getchar()-'0';
	a+=getchar()-'0';
	a+=getchar()-'0';
	a+=getchar()-'0';
	a+=getchar()-'0';
	
	putchar(a+'0');

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

int read(){
    int x=0;char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}
