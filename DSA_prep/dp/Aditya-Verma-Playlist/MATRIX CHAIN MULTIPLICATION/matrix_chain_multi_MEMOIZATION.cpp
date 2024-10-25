//****BOTTOM UP DP****



int static t[1000][1000];
int solve(int arr[],int i,int j)
{
    if(i>=j)return 0;

    if(t[i][j]!=-1)
    return t[i][j];

    int mn=INT_MAX;
    for(int k=i;k<=j-1;++k)
    {
        tempans=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]+arr[k]+arr[j];
        if(tempsum<mn)
        {
            mn=tempsum;
        }
    }


    return t[i][j]=mn;
}

int main()
{
    memset(t,-1,sizeof(t));
    solve(arr,1,size-1);
}


void kmp(string s,string t,set<int> &stt){
    int n=s.size();
    int m=t.size();
    vector<int> lps(m);
    int i=1,j=0;
    while(i<m){
        if(t[i]==t[j]){
            lps[i]=j+1;
            i++;
            j++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    i=0,j=0;
    while(i<n){
        if(s[i]==t[j]){
            i++;
            j++;
        }
        if(j==m){
            stt.insert(i-t.size());
            j=lps[j-1];
        }
        else if(i<n && s[i]!=t[j]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
}