#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

node* head=NULL;
node* tail=NULL;
int size;
node* createNode()
{
    node* temp=(node*)malloc(sizeof(node));
    temp->next=NULL;
    return temp;
}
void addFirst()//adds element to the First position of the list
{
    node* temp=createNode();
    printf("Enter the Data :");
    scanf("%d",&temp->data);
    size++;
    if(head==NULL)
    {
        head=temp;
        tail=head;
        return ;
    }
    temp->next=head;
    head=temp;
}
void addLast()//adds element to the last position of the list
{
    node* temp=createNode();
    printf("Enter the Data:");
    scanf("%d",&temp->data);
    size++;
    if(head==NULL)
    {
        head=temp;
        tail=head;
        return;
    }
    tail->next=temp;
    tail=temp;
}
void addRandom()//adding the element in random position, Initial position Starts from 1
{
    node* th=head;
    int position;
    printf("Enter the Position Where the Data should be added :");
    scanf("%d",&position);
    if(position<=1) // if the position entered in less than 1 there is no such position so element will be added to first
    {
        addFirst();
        return;
    }
    else if(position>size)
    {
        addLast();
        return ;
    }
    else
    {
        while(position>2)
        {
            th=th->next;
            --position;
        }
    }
    node *temp=createNode();
    printf("Enter the Data:");
    scanf("%d",&temp->data);
    temp->next=th->next;
    th->next=temp;
}
int main()
{
    size=3;
    head=createNode();
    head->data=1;
    node* temp=head;
    head->next=createNode();
    temp->next->data=2;
    temp->next->next=createNode();
    temp->next->next->data=3;
    tail=temp->next->next;
     printf("Initial List : ");
     while(temp!=NULL)
     {
         printf("%d ",temp->data);
         temp=temp->next;
     }
     int enter=1;
     while(enter)
     {
     printf("\nMenu:");
     printf("\nEnter 1 to add a element at First positon of the List\n");
     printf("Enter 2 to add a element at the last position of the List\n");
     printf("Enter 3 to add a element at the random Position of the list\n");
     
     int option,flag=1;
     
     while(flag)
     {  printf("Enter your Option :");
        scanf("%d",&option);
     switch(option)
     {
         case 1 : addFirst(); flag=0;
                  break;
         case 2 : addLast(); flag=0;
                  break;
         case 3 : addRandom(); flag=0;
                  break;
         default :printf("Invalid Option!Try Again...");
                  flag=1;
     }
     }
     printf("After  Modification the elements of the List :");
     node* t=head;
     while(t!=NULL)
     {
         printf("%d ",t->data);
         t=t->next;
     }
     printf("\n\nIf you Want to continue the Process Enter 5 or else Enter 0 to quit");
     printf("\nEnter your Option:");
     scanf("%d",&enter);
     }
     return 0;
    
}