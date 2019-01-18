#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next, *pre;
};
class List
{
    private:
        struct node *head;
    public:
        List()
        {
            head=NULL;
        }
        node* cnode(int num)
        {
            struct node *temp;
            temp=new (struct node);
            temp->data=num;
            temp->next=NULL;
            temp->pre=NULL;
            return temp;
        }
        void infirst(int num)
        {
            struct node *temp;
            temp=cnode(num);
            if(head==NULL)
                head=temp;
            else
            {
                temp->next=head;
                head->pre=temp;
                head=temp;
            }
        }
        void inend(int num)
        {
            struct node *temp,*a;
            temp=cnode(num);
            a=head;
            if(head==NULL)
                head=temp;
            else
            {
                while(a->next!=NULL)
                {
                    a=a->next;
                }
                a->next=temp;
                temp->pre=a;
            }
        }
        void inmid(int num,int pos)
        {
            struct node *temp, *a, *b;
            temp=cnode(num);
            a=head;
            int c=1;
            if (pos==1)
            {
                if(head==NULL)
                    head=temp;
                else
                {
                    temp->next=head;
                    head->pre=temp;
                    head=temp;
                }
            }
            else
            {
                while(c!=pos-1)
                {
                    a=a->next;
                    c++;
                }
                temp->next=a->next;
                temp->pre=a;
                a->next=temp;
                temp=temp->next->pre;
            }
        }
        void Delete()
        {
        	struct node *a, *b;
        	int num;
  			a=head;
  			if(head==NULL)
            {
                cout<<"list is empty";
            }
            else
                {
            cout<<"Enter the no. to delete \n";
            cin>>num;
  			if(head->data==num)
  			{
  				head=head->next;
  				head->pre=NULL;
  			}
  			else
  			{
  				while(a->next!=NULL && a->data!=num)
  				{
  					b=a;
  					a=a->next;
  				}
  				if(a->data!=num)
                {
                    cout<<"no element";
                }
                else
  				b->next=a->next;
  				b=a->next->pre;
  			}
                }
        }
        void display()
        {
            struct node *temp;
            temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
};
int main()
{
    List l;
    int ch,a;
    while(1)
    {
    cout<<"Enter the choice \n 1. in beggning 2. in end 3. in mid 4. Delete 5. display \n";
    cin>>ch;
    switch(ch)
    {
    	case 1:
    	cout<<"Enter the element to insert \n";
    	cin>>a;
    	l.infirst(a);
    	break;
    	case 2:
    	cout<<"Enter the element to insert \n";
    	cin>>a;
    	l.inend(a);
    	break;
    	case 3:
    	cout<<"Enter the element to insert \n";
    	cin>>a;
    	cout<<"enter the position \n";
    	int p;
    	cin>>p;
    	l.inmid(a,p);
    	break;
    	case 4:
    	l.Delete();
    	break;
    	case 5:
    	l.display();
    	break;
    	default:
    	return 0;
    }
	}
}

