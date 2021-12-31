//Default Output Gen for CPP
#include <bits/stdc++.h>
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
void solve()
{

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
