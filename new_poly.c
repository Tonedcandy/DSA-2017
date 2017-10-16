#include<stdio.h>
#include<stdlib.h>
struct polynomial
{
	int coeff,exp;
	struct polynomial* llink,*rlink;
	
	
};
typedef struct polynomial* NODE;
NODE poly_1=NULL,poly_2=NULL,cur,temp;

////poly_1=(NODE)malloc(sizeof(struct polynomial));
//poly_1->llink=poly_1;
//poly_1->rlink=poly_1;
NODE insert_rear(NODE head,int c,int e)
{
	NODE temp,new_node;
	new_node=(NODE)malloc(sizeof(struct polynomial));
	new_node->coeff=c;
	new_node->exp=e;
	
	if(head==NULL)
	{
	//	printf("got here!");
		head=new_node;
		head->llink=new_node;
		head->rlink=new_node;
		//new_node->rlink=head;
	//	new_node->llink=head;
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
	temp=head;
	do	
	{
		printf("%d^%d ",temp->coeff,temp->exp);
		temp=temp->rlink;
	}
	while(temp!=head);
	
}

int main()
{
	//poly_1=NULL,poly_2=NULL;
	poly_1=insert_rear(poly_1,7,6);
	poly_1=insert_rear(poly_1,5,2);
	poly_1=insert_rear(poly_1,17,765);
	poly_2=insert_rear(poly_2,23,26);
		//NODE temp;haed
//	temp=poly_1;
//	do	
//	{
//		printf("%d^%d ",temp->coeff,temp->exp);
//		temp=temp->rlink;
//	}
//	while(temp!=poly_1);
	display(poly_1);
	display(poly_2);
	
	
	return 0;
}
