//Humanoid

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        int ans=INT_MAX;

        for(char ch='a';ch<='z';++ch)
        {
            int i=0;
            int j=n-1;
            int ct=0;

            while(i<j)
            {
                if(s[i]==s[j])
                {
                    i++;
                    j--;
                }
                else if(s[i]==ch)
                {
                    i++;
                    ct++;
                }
                else if(s[j]==ch)
                {
                    j--;
                    ct++;
                }
                else break;
            }

            if(i>=j)
            ans=min(ans,ct);
        }


        if(ans==INT_MAX)
        cout<<-1<<endl;
        else
        cout<<ans<<endl;

    }
    return 0;
}