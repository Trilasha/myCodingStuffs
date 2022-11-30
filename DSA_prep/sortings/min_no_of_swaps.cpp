//tc of swapping --> nlogn
void swap(vector<int> &arr, int i, int j){
        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    int min_Swaps(vector<int> arr){
        int n = arr.size();
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i=0 ; i<n ; i++){
            mp[arr[i]] = i;
        }
        
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        
        for (int i=0 ; i<n ; i++){
            if (arr[i] != temp[i]){
                ans++;
                int init = arr[i];
                swap(arr, i, mp[temp[i]]);
                mp[init] = mp[temp[i]];
                mp[temp[i]] = i;
            }
        }
        return ans;
    }