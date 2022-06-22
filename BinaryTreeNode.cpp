#include<iostream>
using namespace std;
#include<queue>
#include<string>


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

void print(BinaryTreeNode<int> * root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data<<" : ";
    if(root->left != NULL)
    {
        cout << "L " <<root->left -> data ;
    }
    if(root->right != NULL)
    {
        cout << " R " << root->right->data ;
    }
    cout << endl;
    print(root->left);
    print(root->right);

}


BinaryTreeNode<int> * takeinput()
{
    int data;
    cout << "Enter the data" << endl;
    cin >> data;
    if(data == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(data);
    BinaryTreeNode<int> * left = takeinput();
    BinaryTreeNode<int> * right = takeinput();
    root->left = left;
    root->right = right;
    return root;
}

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


int Numnodes(BinaryTreeNode<int> * root)
{
    if(root == NULL)
    {
        return 0;
    }
    return 1 + Numnodes(root->left) + Numnodes(root->right);
}

bool findNode(BinaryTreeNode<int> * root,int n)
{
    if(root == NULL)
    {
        return false;
    }
    if(root->data == n)
    {
        return true;
    }
    return (findNode(root->left,n) || findNode(root->right,n));
}

int height(BinaryTreeNode<int> * root)
{
    if(root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}


BinaryTreeNode<int> * mirror(BinaryTreeNode<int> * root)
{
    if(root == NULL)
    {
        return NULL;
    }
    BinaryTreeNode<int> * n = mirror(root->left);
    root-> left = mirror(root->right);
    root-> right = n;
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


void preorder(BinaryTreeNode<int> * root){
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(BinaryTreeNode<int> * root){
    if(root == NULL) return;


    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


BinaryTreeNode<int> * treeusingpreinhelper(int * in, int * pre, int inS , int inE, int preS, int preE){
    if (inS > inE ){
        return NULL;
    }
    int r = preS;
    int leftpreS = r +1;
    int leftinS = inS;
    int i = 0;
    while(pre[r] != in[i]){
        i++;
    }
    int leftinE = i-1;
    int leftpreE = leftinE - leftinS + leftpreS;
    int rightpreS = leftpreE + 1;
    int rightinE = inE;
    int rightpreE = preE;
    int rightinS = i+ 1;
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(pre[r]);
    root-> left =treeusingpreinhelper(in,pre,leftinS,leftinE, leftpreS, leftpreE);
    root -> right = treeusingpreinhelper(in,pre, rightinS, rightinE, rightpreS, rightpreE);
    return root;



}

BinaryTreeNode<int> * treeusingprein(int * in, int * pre, int s){
    return treeusingpreinhelper(in, pre, 0, s-1, 0, s-1);
}




int diameter(BinaryTreeNode<int> * root){
    if (root == NULL) return 0;

    int op1 = height(root-> left)+ height(root->right);
    int op2 = diameter(root->left);
    int op3  = diameter(root->right);
    return max(op1, max(op2, op3));
}

pair<int,int> heightdiameter(BinaryTreeNode<int> * root){
    if (root == NULL) {
            pair<int,int> p;
            p.first = 0;
            p.second= 0;
            return p;
    }
    pair<int,int> leftAns = heightdiameter(root-> left);
    pair<int,int> rightAns = heightdiameter(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int h = 1 + max(lh,rh);
    int d = max(lh+rh, max(ld,rd));
    pair<int,int> p;
    p.first = h;
    p.second = d;
    return p;
}


pair<int,int> MinMax(BinaryTreeNode<int> * root){
    if(root == NULL){
        pair<int,int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }
    pair<int,int> leftAns = MinMax(root->left);
    pair<int,int> rightAns = MinMax(root-> right);
    int leftmin = leftAns.first;
    int leftmax = leftAns.second;
    int rightmin = rightAns.first;
    int rightmax = rightAns.second;

    int MIN = min(root->data,min(leftmin,rightmin));
    int MAX = max(root->data, max(rightmax, rightmax));
    pair<int,int> p;
    p.first = MIN;
    p.second = MAX;
    return p;
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

vector<Node*> arrLLTreelevelwise(BinaryTreeNode<int> * root){
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    BinaryTreeNode<int> * Front;
    vector<Node*> v;
    Node *  head = NULL;
    Node *  tail = NULL;
    while(!q.empty()){
        Front = q.front();
        q.pop();
        if(Front == NULL)
        {
            if(!q.empty()){
                q.push(NULL);
            }
            v.push_back(head);
            head = NULL;
            tail = NULL;
        }
        else
        {
            if(Front->left != NULL)
            {
                q.push(Front->left);
            }
            if(Front->right != NULL)
            {
                q.push(Front->right);
            }
            Node * n = new Node(Front->data);
            if(head == NULL){
                head = n;
                tail = n;
            }
            else{
                tail->next = n;
                tail = n;
            }
        }
    }
    return v;
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

int depth(char str[]) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(str[0]=='l')
        return 1;

    int dep=0;
    if(str[1]=='n' && str[2]=='n')
        dep=1+max(depth(str+1),depth(str+2));

    else if(str[1]=='n')
        dep=1+depth(str+1);
    else if(str[2]=='n')
        dep=1+depth(str+2);
    else
        dep=depth(str+1);
    return dep;
}


int heightnl(string a,int root)
{
	if(a[root]=='l')return 0;
	int lheight=0,rheight=0;
	lheight=heightnl(a,root+1)+1;
	rheight=heightnl(a,root+2)+1;
	return max(lheight,rheight);
}


class Pair1{
public:
    int height;
    vector<int> v;
};


Pair1  heightpath(BinaryTreeNode<int> * root){
    if(root == NULL){
        Pair1 p;
        p.height = 0;
        return p;
    }
    int h;
    Pair1 h1 = heightpath(root->left);
    Pair1 h2 = heightpath(root->right);

    vector<int> v1;
    if(h1.height > h2.height){
        h = h1.height+ 1;
        h1.v.push_back(root->data);
        v1 = h1.v;
    }else{
        h = h2.height+1;
        h2.v.push_back(root->data);
        v1 = h2.v;
    }

    Pair1 p;
    p.height = h;
    p.v = v1;

    return p;




}


vector<int>  heightpath1(BinaryTreeNode<int> * root){
    if(root == NULL){
        vector<int> v;
        return v;
    }
    int h;
    vector<int> v1 = heightpath1(root->left);
    vector<int> v2 = heightpath1(root->right);

    if(v1.size() > v2.size()){
        v1.push_back(root->data);
        return v1;
    }else{
        v2.push_back(root->data);
        return v2;
    }
}

void printboundaryleft(BinaryTreeNode<int> * root){
    if(root){
        if(root->left){
            cout << root->data << " ";
            printboundaryleft(root->left);
        }
        else if(root->right){
            cout << root->data << " ";
            printboundaryleft(root->right);
        }
    }
}

void printboundaryright(BinaryTreeNode<int> * root){
    if(root){
        if(root->right){
            printboundaryright(root->right);
            cout << root->data << " ";

        }
        else if(root->left){
            printboundaryright(root->left);
            cout << root->data << " ";
        }
    }
}

void printleaves(BinaryTreeNode<int> * root){
    if(root == NULL){
            return;
    }

    printleaves(root->left);
    if(!(root->left) && !(root->right)){
        cout << root->data<< " ";
    }

    printleaves(root->right);





}


void printboundary(BinaryTreeNode<int> * root){
    if (root == NULL){
        return ;
    }
    cout << root->data << " ";
    printboundaryleft(root->left);
    printleaves(root->left);
    printleaves(root->right);
    printboundaryright(root->right);





}



pair<int,int> maximumsumpathbetweenleaves(BinaryTreeNode<int> * root){
    if(root == NULL ){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    if(!root->left && !root->right ){
        pair<int,int> p;
        p.first = 0;
        p.second = root->data;
        return p;
    }
    pair<int, int>  left = maximumsumpathbetweenleaves(root->left);
    pair<int, int> right = maximumsumpathbetweenleaves(root->right);

    pair<int,int> p;
    if(left.second + root->data > right.second + root->data){
        p.second = left.second+ root->data;
    }
    else{
        p.second = right.second+ root->data;
    }
    if(left.second + right.second + root->data  > max(left.first, right.first)){
        p.first = left.second + right.second + root->data;
    }
    else{
        p.first = max(left.first, right.first);
    }
    return p;
}




void printpattern(BinaryTreeNode<int> * root){
    if(root == NULL){
        return ;
    }
    cout << root->data << " ";
    if(root->left != NULL){
        cout << root->left->data << " " << root->right->data << " ";
    }
    if(root->left->left == NULL){
        return;
    }

    queue<BinaryTreeNode<int>*> pn;
    pn.push(root->left);
    pn.push(root->right);

    BinaryTreeNode<int> * first;
    BinaryTreeNode<int> * second;

    while(!pn.empty()){
        first = pn.front();
        pn.pop();
        second = pn.front();
        pn.pop();

        cout << first->left->data << " " << second->right->data << " ";
        cout << first->right->data << " " << second->left ->data<< " ";

        if(first->left->left != NULL){
            pn.push(first->left);
            pn.push(second->right);
            pn.push(first->right);
            pn.push(second->left);

        }
    }









}

int main()
{
    /*BinaryTreeNode<int> * root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> * node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> * node2= new BinaryTreeNode<int>(3);
    root-> left = node1;
    root-> right = node2;*/
    BinaryTreeNode<int> * root =takeinputlevelwise();
    printpattern(root);
}
