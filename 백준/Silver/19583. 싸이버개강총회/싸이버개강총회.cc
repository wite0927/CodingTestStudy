#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> time;
    
    string t;
    for(int i = 0; i < 3; i++)
    {
        cin >> t;
        time.push_back(stoi(t.substr(0,2)) * 60 + stoi(t.substr(3,2)));
    }

    unordered_set<string> first;
    unordered_set<string> second;

    string chat, name;
    while(cin >> chat >> name)
    {
        int chatTime;

        chatTime = stoi(chat.substr(0,2)) * 60 + stoi(chat.substr(3,2));

        if(chatTime <= time[0]) first.insert(name);
        else if(chatTime >= time[1] && chatTime <= time[2])
        {
            if(first.find(name) != first.end())
            {
                second.insert(name);
            }
        }
    }

    cout << second.size();
    return 0;
}