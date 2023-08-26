#include <stdio.h>
#include <stdlib.h>

struct list{

struct list *prev;
int data;
struct list *next;

};
struct list *start=NULL;
//node declaration
struct list *getnode(){
struct list *newnode;
newnode=(struct list*)malloc(sizeof(struct list));
printf("Enter the Element ");
scanf("%d",&newnode->data);
newnode->prev=NULL;
newnode->next=NULL;
return newnode;
};
//1 Node creation
void create()
{
int i,n;
printf("\nCreation of DLL");
printf("\nEnter the No. of Elements to Create: ");
scanf("%d",&n);
for(i=1;i<=n;i++)
insert();
}
//insert
void insert(){
    struct list *newnode,*temp;
    newnode=getnode();
if(start==NULL){
    start=newnode;
}
else{
temp=start;
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=newnode;
newnode->prev=temp;
temp=newnode;
}
}
//2 Insert front
void insertfront()
{
 struct list *newnode;
 newnode=getnode();
 if(start==NULL)
 {
     start=newnode;
 }
 else{
    newnode->next=start;
    newnode->prev=newnode;
    start=newnode;
 }
}
//3 insert end
void insertend()
{
struct list*newnode,*temp=start;
newnode=getnode();
if(start==NULL)
{
start=newnode;
}
else
{
while(temp->next!=NULL)
temp=temp->next;
temp->next=newnode;
newnode->prev=temp;
}
}
//4 insert before node
void insertbefnode(){
int val;
struct list *befnode=NULL,*curnode=start,*newnode=getnode();
if(start==NULL){
    start=newnode;
}
printf("Enter the value before which node to be inserted ");
scanf("%d",&val);
if(start->data==val){
   newnode->next=start;
   start->prev=newnode;
   start=newnode;
}
else if(curnode->data!=val){

    while(curnode->data!=val){
        befnode=curnode;
        curnode=curnode->next;
    }
    befnode->next=newnode;
    newnode->prev=befnode;
    newnode->next=curnode;
    curnode->prev=newnode;
}
else{
    printf("Invalid Element");
}

}

//5 insert after node
void insertaftnode(){
int val;
struct list *befnode=NULL,*curnode=start,*aftnode=NULL,*newnode=getnode();
if(start==NULL){
    start=newnode;
}
printf("Enter the value after which node to be inserted ");
scanf("%d",&val);
if(start->data==val)
{
    if(start->next==NULL){
        start->next=newnode;
        newnode->prev=start;
        newnode->next=NULL;
    }else{
    aftnode=curnode->next;
    curnode->next=newnode;
    newnode->prev=curnode;
    newnode->next=aftnode;
    aftnode->prev=newnode;
    }
}
else{
    while(curnode->data!=val){
        befnode=curnode;
        curnode=curnode->next;
        aftnode=curnode->next;
    }
    if(aftnode!=NULL){
        aftnode=curnode->next;
        curnode->next=newnode;
        newnode->prev=curnode;
        newnode->next=aftnode;
        aftnode->prev=newnode;
    }
    else{
        curnode->next=newnode;
        newnode->prev=curnode;
        newnode->next=NULL;
    }
}
}
//6 Insert at Position
void insertatpos( )
{
struct list *temp;
int i, position;
printf("Enter the position:");
scanf("%d",& position);
temp = start;
for(i=1; i<position && temp!=NULL; i++)
{
temp = temp->next;
}
struct list *temp1=temp->next;
if(temp != NULL)
{
 struct list *newnode=getnode();
 temp->next=newnode;
 newnode->prev=temp;
 newnode->next=temp1;
 temp1->prev=newnode;
}
else
{
printf("Invalid position!\n");
}}
//7 Deletion Front
int delfront()
{
    struct list *temp=start;
    if(start==NULL)
    {
        printf("\nDoubly linked list is empty");
        return;
    }
    else if(start->next==NULL)
    {
        start=NULL;
        free(temp);
    }
    else{
        start=start->next;
        start->prev=NULL;
        free(temp);
    }
}
//8 Deletion at end
void delend()
{
struct list*temp=start,*prev=NULL;
if(start==NULL)
{
printf("Doubly linked list is empty");
return;
}
if(start->next==NULL){
start=NULL;
free(temp);
}
else
{
while(temp->next!=NULL){
       prev=temp;
       temp=temp->next;
}
prev->next=NULL;
free(temp);
}
}
//9 Deletion at val
void delatval()
{
    int val;
    struct list*curnode=start,*prevnode=NULL,*nextnode=NULL;
    if(start==NULL)
    {
        printf("\nDoubly linked list is empty");
        return;
    }
    printf("\nEnter the element to delete:");
    scanf("%d",&val);
    if(start->data==val)
    {
        if(start->next==NULL)
          {
            start=NULL;
            free(curnode);
          }
         else{
       start=start->next;
       start->prev=NULL;
       free(curnode);
      }
  }
else
{
while(curnode->data!=val)
{
  prevnode=curnode;
  curnode=curnode->next;
  nextnode=curnode->next;
}
if(nextnode!=NULL){
prevnode->next=nextnode;
nextnode->prev=prevnode;
free(curnode);
}
else{
prevnode->next=NULL;
free(curnode);
}
}
}

//10 delete at position
void delatpos( )
{
struct list *temp;
int i, position;
printf("Enter the position:");
scanf("%d",& position);
temp = start;
for(i=0; i<position && temp!=NULL; i++)
{
temp = temp->next;
}
if(temp != NULL)
{
temp->prev->next = temp->next;
temp->next->prev = temp->prev;
free(temp);
}
else
{
printf("Invalid position!\n");
}}

//11 Deletion Before node
struct list *delbefnode()
{
struct list *ptr, *temp;
int val;
printf("\n Enter the value before which the node has to deleted:");
scanf("%d", &val);
ptr = start;
while(ptr -> data != val)
 ptr = ptr -> next;
temp = ptr -> prev;
if(temp == start)
 start = delfront();
else
{
 ptr -> prev = temp -> prev;
 temp -> prev -> next = ptr;
}
free(temp);
return start;
}
//12 Deletion after node
struct list *delaftnode()
{
struct list *ptr, *temp;
int val;
printf("\n Enter the value after which the node has to deleted : ");
scanf("%d", &val);
ptr = start;
while(ptr -> data != val)
 ptr = ptr -> next;
temp = ptr -> next;
ptr -> next = temp -> next;
temp -> next -> prev = ptr;
free(temp);
return start;
}

//13 searching sorted
void searchsort(){
int count = 1,val;
struct list *temp=start;
if(start==NULL){
    printf("\nDLL is Empty");
    return;
}
else {
    printf("\nEnter the element to search");
    scanf("%d",&val);
    while(temp->data<=val)
    {
        if(temp->data==val){
            printf("\nElement %d is found at position %d",val,count);
            return;
        }
        else{
            temp = temp->next;
            count++;
        }
    }
printf("\nElement %d is not found",val);
}
}
//14 search unsorted
void searchunsort(){
int count = 1,val;
struct list *temp=start;
if(start==NULL){
    printf("\nDLL is Empty");
    return;
}
else {
    printf("\nEnter the element to search");
    scanf("%d",&val);
    while(temp!=NULL)
    {
        if(temp->data==val){
            printf("\nElement %d is found at position %d",val,count);
            return;
        }
        else{
            temp = temp->next;
            count++;
        }
    }
printf("\nElement %d is not found",val);
}

}
//15 reversing
void reverse()
{
    struct list * ptr1=start;
    struct list *ptr2=ptr1->next;
    ptr1->next=NULL;
    ptr1->prev=ptr2;
    while(ptr2!=NULL)
    {
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    start=ptr1;
    return;
}
//16 Concatenation
struct list *concat(struct list*list1,struct list*list2,struct list*list3){
struct list *temp =list1;
if(list1==NULL)
    list3=list2;
else if(list2==NULL)
    list3=list1;
else {
    list3=list1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = list2;
}
return (list3);
};
//17 Length of DLL
void len(){
struct list *temp = start;
int count = 0;
if (start==NULL){
    printf("\nDLL is Empty");
    return;
}
else{
 while(temp!=NULL){
    count++;
    temp=temp->next;
 }
 printf("\nLength of DLL is %d",count);
}
}
//18 display
void display()
{
struct list *temp=start;
if(start==NULL)
{
printf("\nDoubly linked list is empty");
return;
}
else
{
printf("\nDoubly linked list:");
while(temp!=NULL)
{
printf("\t %d",temp->data);
temp=temp->next;
}
}
}


int main()
{
int ch;
do
{
printf("\n Doubly Linked List (DLL)\n");
printf("\n <1> Creation");
printf("\n <2> Insertion At Front");
printf("\n <3> Insertion At End");
printf("\n <4> Insertion Before Node");
printf("\n <5> Insertion After Node");
printf("\n <6> Insertion At a Position");
printf("\n <7> Deletion At Front");
printf("\n <8> Deletion At End");
printf("\n <9> Deletion At Val");
printf("\n <10> Deletion At Position");
printf("\n <11> Deletion Before Node");
printf("\n <12> Deletion After Node");
printf("\n <13> Searching An Element (sorted list)");
printf("\n <14> Searching An Element (unsorted list)");
printf("\n <15> Reversing The List");
printf("\n <16> Concatenation of Two List");
printf("\n <17> Length Of The List");
printf("\n <18> Display");
printf("\n <19> Exit\n");
printf("\n Enter Your Choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1: create();
display();
break;
case 2: insertfront();
display();
break;
case 3: insertend();
display();
break;
case 4: insertbefnode();
display();
break;
case 5: insertaftnode();
display();
break;
case 6: insertatpos();
display();
break;
case 7: delfront();
display();
break;
case 8:delend();
display();
break;
case 9: delatval();
display();
break;
case 10: delatpos();
display();
break;
case 11: delbefnode();
display();
break;
case 12: delaftnode();
display();
break;
case 13: searchsort();
display();
break;
case 14: searchunsort();
display();
break;
case 15: reverse();
display();
break;
case 16: printf("\nConcatenation of Two Given Lists:");
printf("\nEnter number of elements in First List:");
int i,n,m;
scanf("%d",&n);
for(i=1;i<=n;i++)
    insert();
struct list *list1 = start, *start = NULL;
printf("\nEnter number of elements in Second List:");
scanf("%d",&m);
for(i=1;i<=m;i++)
    insert();
struct list *list2 = start, *list3;
concat(list1, list2, list3);
start = list3;
display(list3);
break;
case 17: len();
display();
break;
case 18: display();
break;
case 19: exit(0);
default : printf("\n\t Invalid Choice ");
break;
}
}while(ch!=19);
return 0;
}
