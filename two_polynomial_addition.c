#include<stdio.h>
#include<stdlib.h>
struct polynomial
{
	int coeff,exp;
	struct polynomial* llink,*rlink;
	
	
};
typedef struct polynomial* NODE;
NODE poly_1=NULL,poly_2=NULL,cur,temp,res=NULL;


NODE insert_rear(NODE head,int c,int e)
{
	NODE temp,new_node;
	new_node=(NODE)malloc(sizeof(struct polynomial));
	new_node->coeff=c;
	new_node->exp=e;
	
	if(head==NULL)
	{
		head=new_node;
		head->llink=new_node;
		head->rlink=new_node;
		return head;
		
	}
	temp=head->llink;
	head->llink=new_node;
	new_node->rlink=head;
	new_node->llink=temp;
	temp->rlink=new_node;
	return head;
	
	
}

void display(NODE head)
{
	
	NODE temp;
	if(head==NULL)
	{
		printf("Underflow!");
		exit(0);
	}
	temp=head;
	do	
	{
		
		
		printf("%dx^%d ",temp->coeff,temp->exp);
		
		temp=temp->rlink;	
	}while(temp!=head);

	printf("\n");
}



void sort(NODE head)
{
	NODE temp1=head,temp2=head;
	int c,e;
	while(temp1->rlink!=head){	
	
	
		while(temp2->rlink!=head){
			if(temp2->exp<temp2->rlink->exp)
			{
				c=temp2->coeff;
				e=temp2->exp;
				temp2->coeff=temp2->rlink->coeff;
				temp2->exp=temp2->rlink->exp;
				temp2->rlink->coeff=c;
				temp2->rlink->exp=e;
				
	

				
			}
			
			temp2=temp2->rlink;
			
			
		}
		temp2=head;
		temp1=temp1->rlink;
		
	}
}
NODE delete_node(NODE node,NODE head)
{
	NODE temp,next,prev;
	if(node==NULL)
	{
		printf("Cannot delete!\n");
		exit(0);
	}
	else if(node->rlink==node)
	{
		free(node);
		return NULL;
	}
	
	
	
	temp=node->rlink;
	do
	{
		if(node->exp==temp->exp)
		{
			node->coeff=node->coeff+temp->coeff;
			prev=temp->llink;
			next=temp->rlink;
			free(temp);
			prev->rlink=next;
			next->llink=prev;
			
		}
		temp=temp->rlink;
	}
	while(temp!=node);
	return head;
}
void traverse(NODE head)
{
	
	NODE temp,return_val;
	if(head==NULL)
	{
		printf("Underflow!\n");
		exit(0);
	}
	temp=head;
	do	
	{
		{
		
		head=delete_node(temp,poly_1);
		if(head==NULL)
		exit(0);
		}
		
		temp=temp->rlink;	
	}while(temp!=head);

	
}
void concat(NODE head1,NODE head2)
{
	NODE temp1,temp2;
	if(head1==NULL||head2==NULL)
	{
		printf("Cannot Concatenate!\n");
		exit(0);
	}
	temp1=head1->llink;
	temp2=head2->llink;
	head1->llink=temp2;
	temp2->rlink=head1;
	temp1->rlink=head2;
	head2->llink=temp1;
	
	
}
int main()
{
	int choice,c,e;
	printf("\t\t\t\t\tTWO POLYNOMIAL ADDITION PROGRAM\n");
	printf("1.Insert term into polynomial 1\n2.Insert term into polynomial 2\n3.display polynomial 1\n4.Display polynomial 2\n5.Add\n6.Exit\n");
	while(1)
{

	printf("Enter the choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("Enter coefficieent and power of x: ");
				scanf("%d%d",&c,&e);
					poly_1=insert_rear(poly_1,c,e);
					break;
		case 2:printf("Enter coefficieent and power of x: ");
				scanf("%d%d",&c,&e);
					poly_2=insert_rear(poly_2,c,e);
					break;
		case 3:	printf("POLYNOMIAL 1:\n");
				display(poly_1);
				break;
		case 4:	printf("POLYNOMIAL 2:\n");
				display(poly_2);
				break;
		case 5:	printf("ADDITION:\n");
				concat(poly_1,poly_2);
				traverse(poly_1);
				sort(poly_1);
					display(poly_1);
					break;
		case 6: exit(0);
	}
}


	
	
	return 0;
}

