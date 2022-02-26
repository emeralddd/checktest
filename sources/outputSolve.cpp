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
#define ll2 pair<l2, l2>
#define ii pair<int, int>
#define emerald ""
#define memset(a, b) memset(a, b, sizeof(a))
#define ladd(a) a = " " + a
#define bit(x, y) (((y) >> (x)) & 1)
using namespace std;
string NAME;
/// CONFIG CODE
void setupConfig()
{
    srand(time(NULL));
    freopen("config.txt", "r", stdin);
    cin >> NAME;
}
/// IO
void setupInOut()
{
    NAME += ".INP";
    freopen(NAME.data(), "r", stdin);
    freopen("sampleOutput.txt", "w", stdout);

    cin.clear();
    cout.clear();
}
/// SOLVE
#define     ll      long long
#define     ld      long double
#define     ull     unsigned long long
#define     fi      first
#define     se      second
#define     ii      pair<int,int>
#define     li      pair<ll,int>
#define     il      pair<ll,ll>
#define     spei    pair<il,il>
#define     iii     pair<int,ii>
#define cntbit(a) __builtin_popcount((a))
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
void solve()
{
    cin>>n>>k;
    bool b=1;
    for(int i=1; i<=n; i++) {
        cin>>a[i].st>>a[i].nd;
        if(a[i].nd>100) b=0;
    }

    s1();
}
/// MAIN
int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    setupConfig();
    setupInOut();

    solve();
}
