//Default Input Gen for CPP
#include <bits/stdc++.h>
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
/// WRITE INP
void writeINP()
{

}
/// MAIN
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    setupConfig();
    setupInOut();

    writeINP();
}
