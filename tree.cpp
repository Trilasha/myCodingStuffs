struct Node{
    int data;
    Node* left;
    Node* right;
};

vector<int> numbers={1,2,3,4,5};
int numbersLen=numbers.size();


Node* createBST(vector<int> &numbers,int left,int right){
    if(left>right) return;
    int mid=(left+right)/2;
    Node* root = new Node(numbers[mid]);
    root->left=createBST(numbers,left,mid);
    root->right=createBST(numbers,mid+1,right);
    return root;
}
void createTree(vector<int> &numbers){
    int left=0;
    int right=numbersLen-1;
    createBST(numbers,left,right);
}


// _ _ 21 _ 21 _ _ ............. -X  upto 100th index
vector<int> numbers,duplicate;
vector<int> check(100);
for(int i=0;i<numbers.size();++i){
    // if(numbers[abs(numbers[i])]<0){
    //     duplicate.push_back((numbers[i]));
    // }else{
    //     numbers[numbers[i]]=-(numbers[numbers[i]]);
    // }
    if(!check[numbers[i]]){
        check[numbers[i]]=1;
    }else{
        duplicate.push_back(numbers[i]);
    }
}