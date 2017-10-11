/*
	TWO POLYNOMIAL ADDITION PROGRAM v1.0
	Auth: Monish SS	

*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct polynomial //This Structure is defined to hold the values of the coefficient and the power of 'x' for each term in the polynomial
{
	int c,exp;
	char sign;
	
	
}polynomial;
int main()
{
	int i,j,n1,n2,x,sum=0,*flag,k=0,count=0,fl=0;
	polynomial *p,*q,*res,temp;
	printf("-----------------TWO POLYNOMIAL ADDITION AND EVALUTION PROGRAM-----------------\n");
	printf("Enter the number of coefficiets for the first polynomial: ");
	scanf("%d",&n1);	
	p=(polynomial* )malloc(n1*sizeof(polynomial)); // Memory is dynamically allocated for storing a polynomial with n1 terms
	printf("COEFFECIENT  POWER OF X\n");// Lists the format for input
	
	for(i=0;i<n1;i++)	//Loop to input the coefficient as well as the power of x for each term
	{
		getchar();		//Used to absorb the new line character left by the previous scanf statement in the input stream; causes fatal errors if 							  not included
		scanf("%d%d",&p[i].c,&p[i].exp);

	}
	printf("Enter the number of coefficiets for the second polynomial: ");
	scanf("%d",&n2);
	q=(polynomial* )malloc(n2*sizeof(polynomial));// Memory is dynamically allocated for storing a polynomial with n2 terms
	
	for(i=0;i<n2;i++)//Loop to input the coefficient as well as the power of x for each term
	{
		getchar();//Used to absorb the new line character left by the previous scanf statement in the input stream; causes fatal errors if not included
		scanf("%d%d",&q[i].c,&q[i].exp);

	}
	flag=(int *)calloc(sizeof(int),n2);
	res=(polynomial*)malloc((n1+n2)*sizeof(polynomial));// Memory is dynamically allocated for storing the result polynomial with a maximum of n1+n2 terms
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			
			if(p[i].exp==q[j].exp)//Checks for like terms in polynomial 1 and polynomial 2
			{

				p[i].c=p[i].c+q[j].c;//If true overwrites previous coefficient of the term in polynomial 1 with the new coefficient
				flag[j]=1;// flag to keep track of what terms have been matched from polynomial 2
				count++;// counter for the flag array

			}
		
		}
			
			//The following statements are used to copy polynomial 1 into the result polynomial
			res[k].exp=p[i].exp;
			res[k].c=p[i].c;
			k++;

	}

	for(i=0;i<n2;i++)

	for(i=0;i<n2;i++)
	{

		if(flag[i]==0)// This is used to copy the unmatched terms in polynomial 2 into the result polynomial
		{
		
		res[k].c=q[i].c;
		res[k].exp=q[i].exp;
		k++;
	}
	}
	for(i=0;i<n1+n2-count-1;i++)// Bubble-sort to sort the result polynomial from the highest to the lowest power of x (Sorting of result polynomial)
	{
		for(j=0;j<n1+n2-count-i-1;j++)
		{
			if(res[j].exp<res[j+1].exp)
			{
				temp.exp=res[j+1].exp;
				temp.c=res[j+1].c;
				res[j+1].exp=res[j].exp;
				res[j+1].c=res[j].c;
				res[j].exp=temp.exp;
				res[j].c=temp.c;
			}
		}
	}



printf("f(x)= ");	
for(i=0;i<n1+n2-count;i++)//Loop to display the the result of the addition
{
	if(res[i].c<0)
		printf("%dx^%d ",res[i].c,res[i].exp);
	else 
{
	if(i!=0)	
	printf("+");		
	printf("%dx^%d ",res[i].c,res[i].exp);
}
}
	printf("\nEnter the value of x: ");//x is input for the evaluation of the result polynomial
	scanf("%d",&x);
	for(i=0;i<n1+n2-count;i++)//Loop to Evaluate the result polynomial for a given value x
	{

	sum=sum+res[i].c*pow(x,res[i].exp);
	
	}

printf("f(%d)= %d ",x,sum);
printf("\n");
	
	return 0;
	
}
