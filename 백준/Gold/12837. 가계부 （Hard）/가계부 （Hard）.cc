#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Q;
vector<long long> Fenwick;
vector<int> arr;

void Update_FenWick(int idx, long long value)
{
    while(idx <= N)
    {
        Fenwick[idx] = Fenwick[idx] + value;
        idx = idx + (idx & (-idx));
    }
}

long long Sum_Fenwick(int idx)
{
    long long result = 0;
    while(idx > 0)
    {
        result = result + Fenwick[idx];
        idx = idx - (idx & (-idx));
    }
    return result;
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    Fenwick.assign(N+1, 0);

    for(int i = 0; i < Q; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if(x == 1)
        {
            Update_FenWick(y, (long long)z);
        }
        else if(x == 2)
        {
            cout << Sum_Fenwick(z) - Sum_Fenwick(y - 1) << "\n";
        }
    }

    return 0;
}