#include<iostream>

using namespace std;
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data)
    {
        this-> data = data;
    }
    ~TreeNode(){
        for(int i=0; i< children.size(); i++){
            delete children[i];
        }
    }


};

TreeNode<int>* takeinput()
{
    int r;
    cout << "enter data" << endl;
    cin >> r;
    TreeNode<int> * root= new TreeNode<int>(r);

    int n;
    cout << "enter children of " << r << endl;
    cin >> n;
    for(int i=0; i< n; i++)
    {
        TreeNode<int> * child = takeinput();
        root-> children.push_back(child);
    }
    return root;

}

TreeNode<int> * takeinputlevelwise(){
    int r;
    cout << "enter data of root" << endl;
    cin >> r;
    TreeNode<int> * root= new TreeNode<int>(r);
    queue<TreeNode<int>*> pendingnodes;

    pendingnodes.push(root);
    while(!pendingnodes.empty()){
        TreeNode<int>* Front = pendingnodes.front();
        pendingnodes.pop();
        cout << "Enter no. of children of" << Front->data << endl;
        int nchild;
        cin >> nchild;
        for(int i=0; i< nchild; i++){
            int childdata;
            cout << "Enter the " << i << "th child of " << Front->data<<endl;
            cin >> childdata;
            TreeNode<int>* Child = new TreeNode<int>(childdata);
            pendingnodes.push(Child);
            Front->children.push_back(Child);
        }

    }
    return root;
}

int numNodes(TreeNode<int> * root){
    if(root == NULL){
        return 0;
    }
    int ans = 1;

    for(int i = 0; i < root->children.size(); i++){
        ans += numNodes(root->children[i]);
    }
    return ans;



}





void printlevelwise(TreeNode<int> * root){
    if(root == NULL)
    {
        return ;
    }
    queue<TreeNode<int>*> pendingnodes;
    pendingnodes.push(root);

    while(!pendingnodes.empty()){
        TreeNode<int>* Front = pendingnodes.front();
        pendingnodes.pop();
        cout << Front->data << ":";
        for(int i =0; i< Front->children.size(); i++)
        {
        TreeNode<int>* child = Front->children[i];
        cout << child->data << ",";
        pendingnodes.push(child);
        }
        cout << endl;
    }






}


void printlevelwise2(TreeNode<int> * root){
    if(root == NULL)
    {
        return ;
    }
    queue<TreeNode<int>*> pendingnodes;
    pendingnodes.push(root);

    while(!pendingnodes.empty()){
        TreeNode<int>* Front = pendingnodes.front();
        pendingnodes.pop();
        cout << Front->data  ;
        for(int i =0; i< Front->children.size(); i++)
        {
        TreeNode<int>* child = Front->children[i];
        cout << child->data << " ";
        pendingnodes.push(child);
        }
        cout << endl;
    }






}

void print(TreeNode<int> * root)
{
    if(root == NULL)
    {
        return ;
    }
    cout << root->data << ":";
    for(int i =0; i< root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for(int i=0; i< root ->children.size(); i++)
    {
        print(root->children[i]);
    }

}

int sumNodes(TreeNode<int> * root){
    if(root == NULL)
    {
        return -1;
    }
    int sum = root->data;
    for(int i=0; i< root->children.size() ; i++){
        sum += sumNodes(root->children[i]);
    }
    return sum;

}

int maxNode(TreeNode<int>* root){
    if(root == NULL)
    {
        return -1;
    }
    int ans = INT_MIN;
    if(root->data > ans){
        ans = root->data;
    }
    for(int i = 0; i< root->children.size(); i++){
        int a = maxNode(root->children[i]);
        if(a > ans){
            ans = a;
        }
    }
    return ans;
}

int height(TreeNode<int> * root){
    if(root == NULL){
        return 0;
    }
    int a=0;
    for(int i=0; i< root-> children.size(); i++){
        int h = height(root->children[i]);
        if(h>a){
            a= h;
        }
    }
    return a+1;

}

void printklevelnodes(TreeNode<int> * root,int k){
    if(root== NULL){
        return;
    }
    if(k == 0){
        cout << root-> data << endl;
        return ;
    }
    for(int i=0; i< root-> children.size(); i++){
        printklevelnodes(root->children[i], k-1);
    }

}


int countleafnodes(TreeNode<int> * root ){
    if(root==NULL){
        return 0;
    }
    if(root->children.size() == 0){
        return 1;
    }
    int a = 0;
    for(int i =0; i< root->children.size(); i++){
        a += countleafnodes(root->children[i]);
    }
    return a;
}

void preorder(TreeNode<int> * root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    for (int i=0; i< root-> children.size(); i++){
        preorder(root-> children[i]);
    }

}

void postorder(TreeNode<int> * root){
    if(root == NULL){
        return;
    }
    for(int i=0; i< root-> children.size(); i++){
        postorder(root-> children[i]);
    }
    cout << root-> data<< " ";


}


void deleteTree(TreeNode<int> * root){
    if(root == NULL){
        return;
    }
    for(int i=0; i< root-> children.size();i++){
        deleteTree(root->children[i]);
    }
    cout << root-> data << endl;
    delete root;


}

int nextlarger(TreeNode<int> * root, int n){
    if(root == NULL){
        return 0;
    }
    int a = 0;
    if(root->data > n){
        a = root->data;
    }
    else{
        a = 0;
    }
    for(int i = 0; i< root-> children.size() ; i++){
        int h = nextlarger(root-> children[i],n);
        if(a == 0){
            a =h;
        }
        else if(h< a){
            a = h;
        }
    }
    return a;
}



void replacedeptphNodehelper(TreeNode<int> * root, int d){
    root -> data = d;
    for(int i =0 ; i< root-> children.size(); i++){
        replacedeptphNodehelper(root-> children[i], d+1);
    }


}
void replacedeptphNode(TreeNode<int> * root){
    replacedeptphNodehelper(root,0);


}

class Pair{
    public:
    TreeNode<int> * node;
    int sum;
};

Pair maxsumnode(TreeNode<int> * root){
    Pair p;
    p.sum = root->data;
    p.node = root;
    for(int i=0; i< root->children.size();i++){
        p.sum += root->children[i]->data;
    }
    for(int i=0; i< root->children.size(); i++){
        Pair p2= maxsumnode(root->children[i]);
        if(p2.sum>p.sum){
            p.sum = p2.sum;
            p.node = root->children[i];
        }
    }
    return p;

}
class largest{
    public:
    int l;
    int sl;
};

//l - largest
//sl = secondlargest

largest secondlargesthelper(TreeNode<int> * root){
    largest l1;
    l1.l = root->data;
    l1.sl = 0;
    for(int i=0; i< root->children.size(); i++){
        largest l2= secondlargesthelper(root->children[i]);
        if(l2.l > l1.l){
            int x = l1.l;
            l1.l = l2.l;
            if(x>l2.sl){
                l1.sl = x;
            }
            else{
                l1.sl = l2.sl;
            }
        }
        else{
            if(l2.l > l1.sl){
                l1.sl = l2.l;
            }
        }
    }
    return l1;
}


int secondlargest(TreeNode<int> * root){
    largest l= secondlargesthelper(root);
    return l.sl;


}


int main()
{
    //TreeNode<int> * root= new TreeNode<int>(1);
    //TreeNode<int> * node1= new TreeNode<int>(2);
    //TreeNode<int> * node2= new TreeNode<int>(3);

    //root -> children.push_back(node1);
    //root -> children.push_back(node2);
    TreeNode<int> * root = takeinputlevelwise();
    int l= secondlargest(root);
    cout<< l;

}
