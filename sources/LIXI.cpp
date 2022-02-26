/**
darkemeralddd
**/
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define l2 long long
#define st first
#define nd second
#define ll2 pair<l2,l2>
#define ii pair<int,int>
#define iii pair<int,ii>
#define il2 pair<int,l2>
#define l2i pair<l2,int>
#define emerald "LIXI"
#define memset(a,b) memset(a,b,sizeof(a))
#define ladd(a) a=" "+a
#define bit(x,y) (((y)>>(x))&1)
#define infinity() for(;;)
#define cntbit(a) __builtin_popcount((a))
const l2 mod = 1000000007;
using namespace std;
int n,k;
ii a[50005];
void s1() {
    l2 A,B,mt,mm=-1;
    for(int i=1; i<(1<<n); i++) {
        if(cntbit(i)==k) {
            A=B=0;
            for(int j=0; j<n; j++) {
                if(bit(j,i)) {
                    A+=a[j+1].st;
                    B+=a[j+1].nd;
                }
            }

//            cout<<A<<" "<<B<<" "<<mt<<" "<<mm<<endl;

            if(mm==-1||mt*B<mm*A) {
                mt=A;
                mm=B;

                int g=__gcd(mt,mm);

                mt/=g;
                mm/=g;
            }
        }
    }

    cout<<mt<<" "<<mm;
}
int dp[2][105][10005];
void s2() {
    int sum=0;
    for(int i=1; i<=n; i++)
        sum+=a[i].nd;

    memset(dp,-1);

//    cout<<sum<<endl;
    dp[0][0][0]=0;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<min(i,k); j++) {
            for(int s=0; s<=sum-a[i].nd; s++) {
                if(dp[0][j][s]!=-1) dp[1][j+1][s+a[i].nd]=max(dp[1][j+1][s+a[i].nd],dp[0][j][s]+a[i].st);
            }
        }

        for(int j=0; j<=k; j++) {
            for(int s=0; s<=sum; s++) {
                dp[0][j][s]=dp[1][j][s];
//                cout<<i<<" "<<j<<" "<<s<<" "<<dp[1][j][s]<<endl;
            }
        }

        dp[0][0][0]=0;
    }

    for(int j=0; j<=k; j++) {
        for(int s=0; s<=sum; s++) {
            if(dp[0][j][s]==-1) dp[0][j][s]=0;
        }
    }

    int mm=-1,mt;
    for(int i=1; i<=sum; i++) {
        if(mm==-1||mt*i<mm*dp[0][k][i]) {
            mt=dp[0][k][i];
            mm=i;

            int g=__gcd(mt,mm);

            mt/=g;
            mm/=g;
        }
    }

    cout<<mt<<" "<<mm;
}
void s3() {

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(emerald".INP","r",stdin);
    freopen(emerald".OUT","w",stdout);

    cin>>n>>k;
    bool b=1;
    for(int i=1; i<=n; i++) {
        cin>>a[i].st>>a[i].nd;
        if(a[i].nd>100) b=0;
    }

    s2();

//    if(n<=20) s1();
//    else if(n<=100&&b) s2();
//    else s3();
}
