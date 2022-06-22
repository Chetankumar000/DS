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

int length(Node * head){
    Node * temp = head;
    if(temp->next == NULL){
        return 1;
    }
    temp = temp->next;
    int a = length(temp);
    return a+1;
}

Node * swap2node(Node * head, int i, int j){
    Node * prev1 = NULL;
    Node * temp1 = head;
    Node * prev2 = NULL;
    Node * temp2 = head;
    for ( int z = 0 ; z< i; z++){
        prev1 = temp1;
        temp1 = temp1->next;
    }
    for( int y =0 ; y < j; y++){
        prev2 = temp2;
        temp2= temp2-> next;
    }
    Node * temp1next = temp1-> next;
    Node * temp2next = temp2 -> next;
    if((i == 0 or j == 0) && abs(i-j) == 1){
        temp2->next = temp1;
        temp1 -> next = temp2next;
        return temp2;
    }
    if(i == 0 || j ==0){
        temp2-> next = temp1next;
        prev2-> next = temp1;
        temp1->next = temp2next;
        return temp2;
    }
    if(i-j == 1 or i- j == -1){
       prev1->next = temp2;
       temp2 -> next = temp1;
       temp1-> next = temp2next;
       return head;
    }else{
    prev1->next = temp2;
    temp2-> next = temp1next;
    prev2->next = temp1;
    temp1-> next = temp2next;
    return head;
    }

}


Node * EvenOdd(Node *head)
{
    Node * ohead = NULL;
    Node * ehead = NULL;
    Node * otail = NULL;
    Node * etail= NULL;

    while(head != NULL){
        if(head-> data % 2 != 0){
            if(ohead == NULL){
                ohead = head ;
                otail =head;
                head = head-> next;
            }
            else {
                otail -> next = head;
                otail = otail -> next ;
                head = head ->next;
            }
        }
        else{
            if(ehead == NULL){
                ehead = head ;
                etail =head;
                head = head-> next;
            }
            else {
                etail -> next = head;
                etail = etail -> next ;
                head = head ->next;
            }
        }
    }
    if(ohead == NULL){
        return ehead;
    }
    else if(ehead == NULL){
        return ohead;
    }
    otail -> next = ehead;
    etail -> next = NULL;
    return ohead;


}

Node* rev (Node*head){
    Node * tail = head;
    if(head->next == NULL){
        return head;
    }
    Node * temp= rev(head->next);
    Node * t = temp;
    while(t->next != NULL){
        t = t->next;
    }
    t->next = head;
    head->next = NULL;
    return temp;
}

void Divideintotwo(Node * head){
    Node * temp = head;
    Node * h1 = NULL;
    Node * h2 = NULL;
    Node * t1 = NULL;
    Node * t2 = NULL;
    int c = 0;
    while(temp != NULL){
        if(c%2 ==0){
            if(h1 == NULL){
                h1 = temp;
                t1 = temp;
                temp = temp -> next;
                c++;
            }
            else{
                t1 -> next = temp;
                t1 = temp;
                temp = temp -> next;
                c++;
            }
        }
        else{
            if(h2 == NULL){
                h2 = temp;
                t2 = temp;
                temp = temp -> next;
                c++;
            }
            else{
                t2 -> next = temp;
                t2 = temp;
                temp = temp -> next;
                c++;
            }

        }
    }
    t1->next = NULL;
    t2->next =  NULL;
    h1 = rev(h1);
    h2 = rev(h2);
    print(h1);
    cout << endl;
    print(h2);
}





Node * lastbethefirst(Node * head){
    Node * temp = head;
    Node * prev = NULL;
    Node * tail = head;
    while( tail->next != NULL){
        prev = tail;
        tail = tail -> next;
    }
    tail -> next = temp;
    prev -> next = NULL;
    return tail;
}

Node * deleterec(Node * head, int i){
    if(head == NULL){
        return head;
    }
    if(i == 0){
        Node * a = head->next;
        delete head;
        return a;
    }
    Node * c = deleterec(head->next, i-1);
    head -> next = c;
    return head;
}

Node * DeleteeveryNode(Node* head,  int m, int n){
    Node * prev = NULL;
    Node * temp = head;
    int c1=0;
    int c2=0;
    while(temp!= NULL){
        c1 = 0;
        while(c1<m && temp!= NULL){
            prev = temp;
            temp = temp ->next;
            c1 ++;
            c2++;
        }
        c1 = 0;
        while(c1 < n && temp!= NULL){
            temp = temp->next;
            head = deleterec(head, c2);
            c1++;
        }

    }
    return head;
}


Node * Union(Node * h1 , Node * h2){
    Node * temp = h1;
    Node* h3 = h1;
    while(h3-> next != NULL){
        h3 = h3 -> next;
    }
    while(h2 != NULL){
        bool flag = false;
        h1 = temp;
        while(h1 != NULL){
            if(h2-> data == h1-> data){
                flag = true;
                break;
            }
            h1 = h1->next;
        }
        if(flag == false){
            Node * newNode = new Node(h2->data);
            h3 -> next = newNode;
            h3 = h3->next;
        }
        h2 = h2-> next;
    }
    return temp;
}







int main()
{

    Node * a = takeInput();
    Node * b =takeInput ();
    a = Union(a,b);
    print(a);


}
