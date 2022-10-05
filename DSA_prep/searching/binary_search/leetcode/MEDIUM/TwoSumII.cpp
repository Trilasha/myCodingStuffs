//****************(2 POINTERS APPROACH)**************
class Solution {
public:
   vector<int> twoSum(vector<int>& numbers, int target) {
    
    int l = 0;
    int r = numbers.size() -1;
   
    while(l < r){
        if(numbers[l] + numbers[r] == target){
           
            return {l+1,r+1};
        }
        else if(numbers[l] + numbers[r] > target){
            r--;
        }
        else{
            l++;
        }
    }
       //this return is important(2 pointer technique requires the use of this if no such pair exists)
	return {};
   }
};


//***************(THE UNORDEREDMAPS APPROACH)****************
class Solution {
public:
   vector<int> twoSum(vector<int>& numbers, int target) {
    
  unordered_map<int, int> myMap;
    for (int i=0; i<numbers.size(); i++) {
        if (myMap.find(target-numbers[i]) != myMap.end())
            return {myMap[target-numbers[i]]+1, i+1};
        myMap[numbers[i]] = i;
   }
       //always give the default return value if no such pair or answer exists
       return {};
   }
};