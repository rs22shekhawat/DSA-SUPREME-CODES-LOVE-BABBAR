#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength(Node* &head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}

// Node* getMiddle(Node* &head){
//     if(head==NULL){
//         cout<<"LL is empty "<<endl;
//         return head;
//     }

//     if(head->next==NULL){
//         return head;
//     }

//     Node* slow=head;
//     Node* fast=head;

//     while(slow!=NULL && fast->next!= NULL){
//         fast=fast->next;
//         if(fast->next!=NULL){
//             fast=fast->next;
//             slow=slow->next;
//         }
//             }
//     return slow;
// }

// Node* reverseKNodes(Node* &head,int k){
//     if(head==NULL){
//         cout<<"LL is empty "<<endl;
//         return NULL;
//     }
    
//     int len=getLength(head);
//     if(k>len){
//         cout<<"Enter valid of k: "<<endl;
//         return head;
//     }

//     Node* prev=NULL;
//     Node* curr=head;
//     Node* forward=curr->next;

//     int count=0;
//     while(count<k){
//         forward=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=forward;
//         count++;
//     }
    //}





bool checkForLoop(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL){
       fast= fast->next;
       if(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
       }
       if(fast==slow){
        return true;
       }
    }
    return false;
}



Node* startingPointLoop(Node* &head){
    if(head==NULL){
        return NULL;
    }

    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL){
       fast= fast->next;
       if(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
       }
       if(fast==slow){
        slow=head;
         break;
       }
    }

    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}




Node* removeLoop(Node* &head){
    if(head==NULL){
        return NULL;
    }

    Node* slow=head;
    Node* fast=head;

    while(fast!=NULL){
       fast= fast->next;
       if(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
       }
       if(fast==slow){
        slow=head;
         break;
       }
    }

   Node* prev=fast;
    while(slow!=fast){
        prev=fast;
        slow=slow->next;
        fast=fast->next;
    }
    prev->next=NULL;

    return slow;
}
    


int main(){
//    Node* head=new Node(10);
//    Node* second=new Node(20);
//    Node* third=new Node(30);
//    Node* fourth=new Node(40);
//    Node* fifth=new Node(50);
//    head->next=second;
//    second->next=third;
//    third->next=fourth;
//    fourth->next=fifth;
//    fifth->next=NULL; 

//    print(head);

//    cout<<"Middle Node is: "<<getMiddle(head)->data <<endl;






   Node* head=new Node(10);
   Node* second=new Node(20);
   Node* third=new Node(30);
   Node* fourth=new Node(40);
   Node* fifth=new Node(50);
   Node* sixth=new Node(60);
   Node* seventh=new Node(70);
   Node* eighth=new Node(80);
   Node* ninth=new Node(90);
   head->next=second;
   second->next=third;
   third->next=fourth;
   fourth->next=fifth;
   fifth->next=sixth;
   sixth->next=seventh;
   seventh->next=eighth;
   eighth->next=ninth;
   ninth->next=fifth;

   cout<<"Loop is present or not "<<checkForLoop(head)<<endl;

   cout<<"Starting point of Loop is "<<startingPointLoop(head)->data<<endl;

   removeLoop(head);

   print(head);







   return 0;
}