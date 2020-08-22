#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define repp(i,n) for(int i=(0);i<(n);i++)
#define repr(i,n) for(int i=(n);i>=0;i--)
#define repl(i,a,b) for(ll i=(a);i<(b);i++)
#define newl cout<<'\n'
#define inf INT_MAX
#define repa(i,a) for(auto i=a.begin();i!=a.end();++i)
#define pb push_back 
#define test cout<<"test"<<endl
#define start int t;cin>>t;while(t--)
#define startk int t;cin>>t;for(int kk=1;kk<=t;kk++)
#define mem(v,i) memset(v,i,sizeof(v))
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define sec second
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define dec(v) sort(v.begin(),v.end(),greater<int>());
#define sz(a) (int)(a.size())
typedef long double ld;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef pair<int, int> ip;
typedef pair<ll, ll> il;
ll inf1=1e18;



//-----------------------------------------------------end--------------------------------------//

int move(vi a){
    int n=sz(a);
    int m=n;int t=1;
    int ch=0;
    repp(i,n){
        ch+=a[i]-t;
        m=min(m,ch+n-i-1);
        t=a[i]+1;
    }
    return m;
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    start{
        int n,ans=0;cin>>n;int a[n];
        repp(i,n) //od i do n
            cin>>a[i];
        map<int,int> m;
        
        repp(i,n)m[a[i]]++;
        while(!m.empty()){
            vi x;
            repa(i,m){
                x.pb(i->first);
            }
            repa(i,x){
                if(m[*i]>1)m[*i]--;
                else m.erase(*i);
            }
            ans+=move(x);
        }
        cout<<ans;newl;
    }
}
