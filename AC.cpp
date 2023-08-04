#include<bits/stdc++.h>
#define ll   long long
using namespace std;
ll n;
ll ans;
void F(ll x){
	ll k=1;
	while(k*5<=x){
		k*=5;
		ll o=x/k;
		ans+=(ll)o*(x+1);
		ans-=(ll)o*(o+1)/2*k;
	}
}
void G(ll x){
	ll k=1;
	while((k*5+1)/2<=x){
		k*=5;
		ll o=(x+k/2)/k;
		ans+=(ll)o*(x+k/2+1);
		ans-=(ll)o*(o+1)/2*k;
	}
}
int b[50],k;
int main(){
	cin>>n;
	if(n>1)F(n/2);
	G((n+1)/2);
	if(ans==0){
		printf("0\n");
		return 0;
	}
	while(ans)b[++k]=ans%10,ans/=10;
	while(k)printf("%c",48+b[k--]);
	printf("\n");
    return 0;
}
