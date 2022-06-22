#include<iostream>
using namespace std;
#include<queue>
#include<string>
#include <bits/stdc++.h>


template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode * left;
    BinaryTreeNode * right;

    BinaryTreeNode(T data)
    {
        this-> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};



BinaryTreeNode<int> * takeinputlevelwise()
{
    int data;
    cout << "Enter the data" << endl;
    cin >> data;
    if(data == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(!pendingnodes.empty())
    {
        BinaryTreeNode<int> * Front = pendingnodes.front();
        pendingnodes.pop();
        cout << "Enter left of " << Front->data << endl;
        int leftchild;
        cin >> leftchild;
        if(leftchild != -1)
        {
            BinaryTreeNode<int> * child = new BinaryTreeNode<int>(leftchild);
            Front->left = child;
            pendingnodes.push(child);
        }
        cout << "Enter right of " << Front->data << endl;
        int rightchild;
        cin >> rightchild;
        if(rightchild != -1)
        {
            BinaryTreeNode<int> * child = new BinaryTreeNode<int>(rightchild);
            Front->right = child;
            pendingnodes.push(child);
        }
    }
    return root;
}


void printlevelwise(BinaryTreeNode<int> * root)
{
    if(root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(!pendingnodes.empty())
    {
        BinaryTreeNode<int> * Front = pendingnodes.front();
        pendingnodes.pop();
        cout << Front->data << ":" ;
        if(Front->left != NULL)
        {
            pendingnodes.push(Front->left);
            cout << "L " <<Front->left->data << " " ;
        }
        if(Front->right != NULL)
        {
            pendingnodes.push(Front->right);
            cout << "R " << Front->right->data;
        }
        cout<< endl;
    }
}


bool Search(BinaryTreeNode<int> * root,int n){
    if (root == NULL){
        return 0;
    }

    if(root->data == n){
        return 1;
    }
    else if(n > root->data){
        return Search(root->right,n);
    }
    else{
        return Search(root->left,n);
    }
}

void printrangenodes(BinaryTreeNode<int> * root, int s, int b){
    if (root== NULL)
        return;
    if(s < root->data){
        printrangenodes(root->left,s,b);
    }
    if(root->data >= s  && root->data <= b){
       cout << root->data <<endl;
    }
    if(b > root->data)
        printrangenodes(root->right,s,b);
}

bool checkBST(BinaryTreeNode<int> * root){
    if (root== NULL)
        return true;
    if(root->left->data >= root->data){
        return false;
    }
    if(root->right->data < root->data){
        return  false;
    }
    bool c = checkBST(root->left);
    bool b = checkBST(root->right);
    return (c&&b);

}


int minimum(BinaryTreeNode<int> * root){
    if (root== NULL){
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(BinaryTreeNode<int> * root){
    if (root== NULL){
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool checkBST1(BinaryTreeNode<int> * root){
    if (root == NULL){
        return true;
    }
    int lmax =  maximum(root->left);
    int rmin = minimum(root->right);

    return (root->data > lmax) && (root->data <= rmin) && (checkBST1(root->left)) && (checkBST1(root->right));
}

class BSTreturn{
public:
    bool IsBST;
    int mi;
    int ma;
};

BSTreturn IsBST(BinaryTreeNode<int> * root){
    if (root== NULL){
        BSTreturn output;
        output.IsBST = true;
        output.mi = INT_MAX;
        output.ma = INT_MIN;
        return output;
    }

    BSTreturn leftoutput = IsBST(root->left);
    BSTreturn rightoutput = IsBST(root->right);

    int minimum = min(root->data, min(leftoutput.mi,rightoutput.mi ));
    int maximum = max(root->data, max(leftoutput.ma,rightoutput.ma ));

    bool IsBstfinal = (root->data > leftoutput.ma) && (root->data <= rightoutput.mi) && (leftoutput.IsBST) && (rightoutput.IsBST);
    BSTreturn output;
    output.IsBST = IsBstfinal;
    output.mi = minimum;
    output.ma = maximum;
    return output;

}

bool isBST(BinaryTreeNode<int> * root, int mi = INT_MIN, int ma = INT_MAX){
    if(root==NULL){
        return true;
    }

    if(root->data < mi || root->data > ma ){
        return false;
    }

    bool isleftok = isBST(root->left, mi, root->data -1);
    bool isrightok = isBST(root->right, root->data, ma);

    return (isleftok && isrightok);


}

BinaryTreeNode<int> * constructBST(int * arr, int s, int e){
    if(s>e){
        return NULL;
    }

    int m = (s+e)/2;
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(arr[m]);
    BinaryTreeNode<int> * left = constructBST(arr, s, m-1);
    BinaryTreeNode<int> * right =constructBST(arr,m+1, e);

    root->left = left;
    root->right = right;
    return root;
}

class Node{
public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

pair<Node*,Node*> LLBST(BinaryTreeNode<int>* root) {
    if(root == NULL){
        pair<Node*,Node*> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    pair<Node*,Node*> left = LLBST(root->left);
    pair<Node*, Node*> right = LLBST(root->right);

    Node * newNode = new Node(root->data);
    if(left.first != NULL && right.first != NULL){
        left.second->next = newNode;
        newNode ->next = right.first;
    }
    else if(left.first == NULL && right.first != NULL){
        left.first  = newNode;
        newNode->next = right.first;

    }
    else if(right.first == NULL && left.first != NULL){
        left.second->next = newNode;
        right.second = newNode;
    }
    else{
        left.first = newNode;
        right.second = newNode;

    }
    pair<Node*,Node*> output;
    output.first = left.first;
    output.second = right.second;
    return output;

}

void printnode(Node * head)
{
    Node * temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}


vector<int> * getpathfrombst(BinaryTreeNode<int> * root, int k){
    if (root == NULL){
        return NULL;
    }

    if(root->data == k){
        vector<int> * v = new vector<int>;
        v->push_back(root->data);
        return v;
    }
        if(root->data > k){
        vector<int> * vl = getpathfrombst(root->left,k);
        if(vl!= NULL){
        vl->push_back(root->data);
        return vl;
        }
    }
        if(root->data < k){
          vector<int> * vr = getpathfrombst(root->right,k);
        if(vr != NULL){
        vr->push_back(root->data);
        return vr;
        }
    }
    else{
        return NULL;
    }
}

BinaryTreeNode<int> * insertduplicate(BinaryTreeNode<int> * root){
    if (root== NULL){
        return NULL;
    }
    BinaryTreeNode<int> * r = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> * rl = insertduplicate(root->left);
    BinaryTreeNode<int> * rr = insertduplicate(root->right);
    root->left = r;
    root->right = rr;
    r->left = rl;
    return root;
}
void print2(BinaryTreeNode<int> * root)
{
    if(root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int>*> pendingnodes;
    BinaryTreeNode<int> * Front;
    pendingnodes.push(root);
    pendingnodes.push(NULL);
    while(pendingnodes.size() > 1)
    {
        Front = pendingnodes.front();
        pendingnodes.pop();
        if(Front == NULL)
        {
            pendingnodes.push(NULL);
            cout << "\n";
        }
        else
        {
            if(Front->left != NULL)
            {
                pendingnodes.push(Front->left);
            }
            if(Front->right != NULL)
            {
                pendingnodes.push(Front->right);
            }
            cout << Front->data << " ";
        }
    }


}

void insertduplicate1(BinaryTreeNode<int> * root){
    if (root== NULL){
        return;
    }
    BinaryTreeNode<int> * d = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> * l = root->left;

    root->left = d;
    d->left = l;

    insertduplicate1(d->left);
    insertduplicate1(root->right);
}

vector<int> v;
vector<int> converttovector(BinaryTreeNode<int> * root){
    if(root==NULL){
        return v;
    }
    v.push_back(root->data);
    converttovector(root->left);
    converttovector(root->right);
    return v;
}



void printpair(BinaryTreeNode<int> * root , int k){
    vector<int> v = converttovector(root) ;
    sort(v.begin(), v.end());
    int i = 0, j = v.size() - 1;
    while(i<j){
        if(v[i]+v[j] == k){
            cout << v[i] << " " << v[j] << endl;
            i++;
            j--;
        }
        else if(v[i]+v[j] < k){
            i++;
        }
        else if(v[i] + v[j] > k){
            j--;
        }
    }
}



int LCA(BinaryTreeNode<int> * root, int n1,int n2){
    if(root == NULL){
        return -1;
    }
    if(root->data == n1 || root->data == n2){
        return root->data;
    }
    int l = LCA(root->left, n1,n2);
    int r = LCA(root->right,n1,n2);
    if(l== -1 && r ==-1){
        return -1;
    }
    if(l == -1 || r==-1){
        return max(l,r);
    }
    else{
        return root->data;
    }
}

class pair2{
public:
    int mi;
    int ma;
    bool isbst;
    int lheight;
};

pair2 largestbst(BinaryTreeNode<int> * root){
    if(root==NULL){
        pair2 p;
        p.mi= INT_MAX;
        p.ma = INT_MIN;
        p.isbst = true;
        p.lheight = 0;
        return p;
    }
    pair2 left = largestbst(root->left);
    pair2 right = largestbst(root->right);

    pair2 p;
    if(root->data > left.ma && root->data < right.ma){
        p.mi = min(left.mi,right.mi);
        p.ma = max(left.ma, right.ma);
        p.isbst = (left.isbst && right.isbst);
        p.lheight = max(left.lheight,right.lheight) + 1;
        return p;
    }
    else{
        p.mi = min(root->data,min(left.mi,right.mi));
        p.ma = max(root->data,max(left.ma, right.ma));
        p.isbst = false;
        p.lheight = max(left.lheight,right.lheight);
        return p;

    }
}

int replacE(BinaryTreeNode<int> * root, int sum){
    if(root == NULL){
        return 0;
    }

    int right = replacE(root->right, sum);
    int r = root->data;
    root->data = root->data +sum + right;

    int left = replacE(root->left,root->data);
    return  r + right+ left;
}



int main(){
    BinaryTreeNode<int> * root = takeinputlevelwise();
    replacE(root, 0);
    print2(root);
}
