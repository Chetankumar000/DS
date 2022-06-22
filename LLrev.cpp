#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node * next;
    Node(int data)
    {
        this -> data =  data;
        next = NULL;
    }
};

Node* insertNode(Node*head, int i,int data)
{
    Node * newNode = new Node(data);
    int c = 0;
    Node * temp = head;

    if(i==0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }


    while(temp != NULL && c < i-1)
    {
        temp = temp-> next;
        c++;
    }
    if(temp != NULL)
    {
        Node* a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }
    temp->next =  newNode;
    return head;
}

Node* deleteNode(Node*head, int i)
{
    int c = 0;
    Node * temp = head;

    if(i==0)
    {
        head = temp->next;
        delete temp;
        return head;
    }


    while(temp != NULL && c < i-1)
    {
        temp = temp-> next;
        c++;
    }
    if(temp != NULL)
    {
        Node* a = temp->next;
        temp->next= a->next;
        delete a;
    }
    return head;
}









Node * takeInput()
{
    int data ;
    cin >> data;
    Node * head = NULL;
    Node * tail = NULL;
    while (data != -1)
    {
        Node * newNode = new Node(data);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail ->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node * head)
{
    Node * temp = head;

    while(temp != NULL)
    {
        cout << temp -> data <<endl;
        temp = temp -> next;
    }
}

int length(Node * head)
{
    Node * temp = head;
    if(temp->next == NULL)
    {
        return 1;
    }
    temp = temp->next;
    int a = length(temp);
    return a+1;
}

Node * insertrec(Node * head, int i, int data)
{
    if(head->next == NULL)
    {
        Node * newNode = new Node(data);
        head->next = newNode;
        return head;
    }
    if(i == 0)
    {
        Node * newNode = new Node(data);
        newNode->next= head;
        return newNode;
    }
    Node *c = insertrec(head->next,i-1,data );
    head-> next= c;
    return head;
}

Node * deleterec(Node * head, int i)
{
    if(head == NULL)
    {
        return head;
    }
    if(i == 0)
    {
        Node * a = head->next;
        delete head;
        return a;
    }
    Node * c = deleterec(head->next, i-1);
    head -> next = c;
    return head;
}

Node* rev (Node*head)
{
    if(head->next == NULL)
    {
        return head;
    }
    Node * temp= rev(head->next);
    Node * tail = head->next;
    tail->next = head;
    head->next = NULL;
    return temp;
}

class Pair
{
public:
    Node * head;
    Node * tail;
};

Pair revhelper(Node * head)
{
    if(head->next == NULL || head == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair sans= revhelper(head->next);
    sans.tail -> next=  head;
    head -> next = NULL;
    Pair ans;
    ans.head = sans.head;
    ans.tail = head;
    return ans;
}

Node * rev2(Node * head)
{
    return revhelper(head).head;
}









void revers (Node*head)
{
    Node * tail = head;
    if(head == NULL)
    {
        return;
    }
    revers(head->next);
    cout << head-> data << endl;
    return;
}





Node * kreverse(Node * head, int k)
{
    Node * h1 = head;
    Node * t1 = head;
    if(h1 == NULL)
    {
        return h1;
    }
    int c = 1;
    while (c<k && t1->next != NULL)
    {
        t1 = t1-> next;
        c++;
    }
    Node *h2 = t1->next;
    t1->next = NULL;
    h1 = rev(head);
    t1 = h1;
    while(t1-> next != NULL)
    {
        t1 = t1->next;
    }
    Node*t2 = kreverse(h2, k);
    t1->next = t2;
    return h1;
}


Node * midNode(Node * head)
{
    Node * temp = head;
    int c = 0;
    while(temp != NULL)
    {
        temp = temp-> next;
        c++;
    }
    int m;
    if(c%2 == 0)
    {
        m = c/2 -1;
    }
    else
    {
        m = c/2;
    }
    int a = 0;
    temp = head;
    while(a<m)
    {
        temp = temp -> next;
        a++;
    }
    Node * mid = new Node(temp->data);
    return mid;
}

Node * mergeLL(Node * head1, Node * head2)
{
    Node * p1 = NULL;
    Node * p2 = NULL;
    Node * h1 = head1;
    Node * h2 = head2;

    while(h1 != NULL && h2 != NULL)
    {
        if(h1->data <= h2->data)
        {
            p1 =  h1;
            h1 = h1->next;
        }
        else
        {
            if(p1 == NULL)
            {
                p2 = h2;
                h2 = h2->next;
                p2->next = h1;
                head1 = p2;
                p1 = p2;
                p2 = NULL;
            }
            else
            {
                p2 = h2;
                h2 = h2->next;
                p1->next = p2;
                p2->next = h1;
                p1 = p1->next;
                p2 = NULL;
            }
        }
    }

    if(h2!= NULL)
    {
        p1->next = h2;
    }
    return head1;

}

Node * rev3(Node * head)
{
    Node * prev = NULL;
    Node * curr = head;
    while(curr != NULL)
    {
        Node * next = curr-> next;
        curr-> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


Node * mergesort(Node * head)
{
    Node * p1 = NULL;
    Node * h1 = head;
    Node * h2 = head;
    if(h1->next == NULL)
    {
        return h1;
    }
    Node * temp = h1;
    int c = 0;
    while(temp != NULL)
    {
        temp = temp-> next;
        c++;
    }
    int m = c/2;
    int a = 0;
    while(a<m)
    {
        p1 = h2;
        h2 = h2 -> next;
        a++;
    }
    p1->next = NULL;
    h1 = mergesort(h1);
    h2 = mergesort(h2);
    h1 = mergeLL(h1,h2);
    return h1;

}

int FindNode(Node * head, int n)
{
    if(head == NULL)
    {
        return -1;
    }
    int a = FindNode(head->next,n);
    if(head->data == n)
    {
        return 0;
    }
    return 1+a;
}

#include<cmath>
int DecimalEqu(Node * head)
{
    Node * t = head;
    int c = 0;
    while( t != NULL)
    {
        t = t-> next;
        c++;
    }
    t = head;
    int s = 0;
    while(t != NULL)
    {
        s += (t->data) * pow(2,c-1);
        t = t->next;
        c--;
    }
    return s;
}

Node * swapevery2nodes(Node * head)
{
    Node * prev = NULL;
    Node * temp = head;
    while(temp != NULL && temp->next != NULL)
    {
        if(prev == NULL)
        {
            Node * next = temp->next;
            temp -> next = next->next;
            next -> next = temp;
            head = next;
            prev = temp;
            temp = temp ->next;
        }
        else
        {
            Node * next = temp->next;
            temp->next = next -> next;
            prev -> next = next;
            next ->next = temp;
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}


Node * bubblesortLL(Node * head)
{
    Node * prev = NULL;
    Node * temp = head;
    int c = 0;
    while(temp != NULL)
    {
        temp = temp-> next;
        c++;
    }
    for(int i =0; i<c; i++)
    {
        prev = NULL;
        temp = head;
        while(temp != NULL && temp->next != NULL)
        {
            Node * next = temp -> next;
            if(temp->data > next -> data)
            {
                if(prev ==NULL)
                {
                    temp -> next = next->next;
                    next -> next = temp;
                    prev = next;
                    head  = prev;
                }
                else
                {
                    temp->next = next -> next;
                    prev -> next = next;
                    next ->next = temp;
                    prev = next;
                }
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
    }
    return head;
}



Node * sorted;
Node * insertedsort(Node * newNode)
{
    if(sorted == NULL || sorted-> data >= newNode->data)
    {
        newNode ->next = sorted;
        sorted = newNode;
        return sorted;
    }
    else
    {
        Node * c = sorted;
        while(c-> next != NULL && c->next->data < newNode->data)
        {
            c = c->next;
        }
        newNode ->next = c->next;
        c->next = newNode;
        return sorted;
    }
}


Node * insertionsort(Node * head)
{
    sorted = NULL;
    Node * curr = head;
    while (curr != NULL)
    {
        Node * next = curr->next;
        sorted = insertedsort(curr);
        curr = next;
    }
    return sorted;

}


Node * nextNum(Node * head)
{
    Node * temp = head;
    int i = 0;
    int j = 0;
    while(temp != NULL)
    {
        i = (i*10) + temp->data;
        j++;
        temp = temp->next;
    }
    i += 1;
    temp = NULL;
    while(i != 0)
    {
        Node * newNode = new Node(i%10);
        newNode->next = temp;
        temp = newNode;
        i /= 10;
    }
    return temp;

}



Node* nextnum(Node* head)
{
    head=rev(head);
    Node*temp=head;
    while(temp!=NULL)
    {
        if(temp->next==NULL&&temp->data==9)
        {
            temp->data=1;
            Node*newnode=new Node(0);
            newnode->next=head;
            head=newnode;
            temp=temp->next;

        }
        else if(temp->data==9)
        {
            temp->data=0;
            temp=temp->next;
        }
        else
        {
            temp->data=temp->data+1;
            temp=temp->next;
            break;
        }
    }
    head=rev(head);
    return head;

}



int main()
{

    Node * a = takeInput();
    a = nextnum(a);
    print(a);
}

