#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front

char x[10];
char y[10];
bool prime[101];
ll dp[10][100][2];

ll init()
{
	lp(i,0,10)
		lp(l,0,100)
			lp(m,0,2)
				dp[i][l][m]=-1;
}
void find()
{
	// cerr<<"XxX"<<endl;
	lp(i,2,101)
	{

		if(!prime[i])
		{
			for(ll j=i+i;j<=100;j+=i)
			{
				// cerr<<j<<endl;
				prime[j]=1;
			}
			// cout<<i<<endl;
		}	

	}
}

ll solve(char str[],ll n,ll i,ll sum,ll lo)
{
	if(i==n)
	{
		// cout<<sum<<endl;
		if(!prime[sum]) 
		{
			// cout<<sum<<" ";
			return 1;
			
		}
		else return 0;
	}
	ll ul;
	if(dp[i][sum][lo]==-1)
	{
		dp[i][sum][lo]=0;		;
		
		if(lo==0) 	ul=str[i]-'0'+1;
		else ul=10;

		lp(j,0,ul)
		{
			dp[i][sum][lo]+=solve(str,n,i+1,sum+j,lo||j<str[i]-'0');
		}
	}
	return dp[i][sum][lo];
}

int main()
{
	ll t;
	cin >>t;
	lp(i,0,100) prime[i]=0;
	prime[0]=1;
	prime[1]=1;
	find();
	while(t--)
	{
		cin >> x >> y;
		ll lx=strlen(x);
		ll ly=strlen(y);
		rlp(i,lx-1,0)
		{
			if(x[i]=='0')
			{
				if(i!=0) x[i]='9';
			}
			else 
			{
				x[i]=x[i]-1;
				break;
			}
		}
		init();
		ll ans1=solve(x,lx,0,0,0);
		// cout<<endl;
		init();
		ll ans2=solve(y,ly,0,0,0);
		cout<<ans2-ans1<<endl;
	}

	return 0;
}