#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};

struct node* root=NULL;
void append();
// void addAtBegin();
// void addAtAfter();
int  length(); 
void display(); 
// void deleted();
int len;
int main(){
    int ch;
    while (1)
    {
        printf("...................Link List operatio...................\n");
        printf("1.Append\n");
        printf("2.AddAtBegin\n");
        printf("3.AddAtAfter\n");
        printf("4.Length\n");
        printf("5.Display\n");
        printf("6.Delete\n");
        printf("7.Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                append();
                break;
        // case 2:
        //     addAtBegin();
        //     break;
        // case 3:
        //     addAtAfter();
        //     break;
            case 4:
                len=length();
                if (len!=0)
                {
                    printf("Total element: %d\n",len);
                }
                else
                {
                    printf("List is empty\n");
                }
                
                break;
            case 5:
                display();
                break;
            case 6:
                deleted();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice");
                break;
    }
    
    }
    
    return 0;
}

void append(){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: \n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if (root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node* p;
        p=root;
        while (p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
            
    
    }
    
}

int length(){
    int count=0;
    struct node *temp;
    temp=root;
    while (temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    return count;
    
}

void display(){
    struct node* temp;
    temp=root;
    if (temp==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (temp!=NULL)
        {
            printf("%d--->\n",temp->data);
            temp=temp->link;
        }
        
    }
    
}

void deleted(){
    struct node *temp;
    int loc;
    printf("Enter location: \n");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("List is empty \n");
    }
    else if (loc==1)
    {
        temp=root;
        root=temp->link;
        temp->link=NULL;
        free(temp);
    }
    else
    {
        struct node *p,*q;
        int i=0;
        while (i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;
        free(q);

    }
    
}