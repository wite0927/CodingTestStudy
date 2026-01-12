//B 9935
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   string str;
   cin >> str;
   
   string target;
   cin >> target;
   int tSize = (int)target.size();

   string my;

   for(char c : str)
   {
        my.push_back(c);

        if((int)my.size() >= tSize && c == target[tSize-1])
        {
            bool same = true;
            for(int i = 0; i < tSize; i++)
            {
                if(my[my.size() - tSize + i] != target[i])
                {
                    same = false;
                    break;
                }
            }

            if(same)
            {
                for(int i = 0; i < tSize; i++)
                    my.pop_back();
            }
        }
   }

   if(my.empty())
   {
        cout << "FRULA";
   }
   else
   {
        cout << my;
   }


    return 0;
}