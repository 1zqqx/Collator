#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#include<cassert>
#include<random>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
typedef long long i64;
typedef long double f80;
typedef unsigned int u32;
typedef unsigned long long u64;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int a,b,c,i,j;
int main()
{
	scanf("%d + %d = %d",&a,&b,&c);
	if(a+b==c){
		puts("Yes");
		printf("%d + %d = %d\n",a,b,c);
		return 0;
	}
	for(i=1;;i*=10){
		for(j=!(i<=a);j<=9;j++){
			int na=(a%i)+(a/i*i*10)+(j*i);
			int nb=b;
			int nc=c;
			if(na+nb==nc){
				puts("Yes");
				printf("%d + %d = %d\n",na,nb,nc);
				return 0;
			}
		}
		if(i>a) break;
	}
	for(i=1;;i*=10){
		for(j=!(i<=b);j<=9;j++){
			int na=a;
			int nb=(b%i)+(b/i*i*10)+(j*i);
			int nc=c;
			if(na+nb==nc){
				puts("Yes");
				printf("%d + %d = %d\n",na,nb,nc);
				return 0;
			}
		}
		if(i>b) break;
	}
	for(i=1;;i*=10){
		for(j=!(i<=c);j<=9;j++){
			int na=a;
			int nb=b;
			int nc=(c%i)+(c/i*i*10)+(j*i);
			if(na+nb==nc){
				puts("Yes");
				printf("%d + %d = %d\n",na,nb,nc);
				return 0;
			}
		}
		if(i>c) break;
	}
	puts("No");
	return 0;
}