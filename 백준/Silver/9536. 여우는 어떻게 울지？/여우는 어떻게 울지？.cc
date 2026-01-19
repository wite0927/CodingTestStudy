//B 9536
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <string>

using namespace std;

int T;

void solve()
{
    string recordLine;
    getline(cin, recordLine);

    vector<string> rec;
    stringstream ss(recordLine);
    string w;
    while(ss >> w) rec.push_back(w);

    unordered_set<string> us;
    while(1)
    {
        string s;
        getline(cin, s);

        if(s == "what does the fox say?")
            break;

        int pos = s.find("goes");
        s.erase(0, pos+5);
        us.insert(s);
    }

    bool first = true;
    for(string& w : rec)
    {
        if(us.find(w) == us.end())
        {
            if(!first) cout << ' ';
            cout << w;
            first = false;
        }
    }
    cout << "\n";

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    cin.ignore();

    while(T--)
    {
        solve();
    }
    
    return 0;
}