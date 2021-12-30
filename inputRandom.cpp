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
const l2 L = 100;
const l2 mod = 1000000007;
const l2 MAX = 100;
using namespace std;
/// RANDOM CODE
long long random(l2 l, l2 r)
{
    l2 x = 1LL * rand() * rand() * rand() + 1LL * rand() * rand() + rand();
    return (x % (r - l + 1) + l);
}
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
    freopen(NAME.data(), "w", stdout);
    cin.clear();
    cout.clear();
}
/// MAIN
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    setupConfig();
    setupInOut();

    int n = random(1, 100);
    cout << n;
}
