#include<stdio.h>

#define max 50

void main(){
	char stk[max], exp[100][max];
	int top=-1, i;
	printf("enter infix: ");

	int j=0,flag=1;

//------------------inputing------------------
	while(flag){
		flag=0;
		scanf("%s",exp[j]);
		j++;
		printf("\ndo you want to enter more? ");
		scanf("%d",&flag);
	}

	int check=1,k,cu=0,sq=0,cr=0;

//--------------checking if exp is balanced----------------([{}])   }]()
	for(k=0;k<j;k++){
		for(i=0; exp[k][i]!='\0'; i++){

			if(exp[k][i] == '(' || exp[k][i] == '[' || exp[k][i] == '{'){
				top++;
				stk[top] = exp[k][i];
			}

			else if(exp[k][i] == ')' ){
				if(stk[top] == '(' )
					top--;
				else
                    cu++;
			}

			else if(exp[k][i] == ']' ){
				if(stk[top] == '[' )
					top--;
				else
                    sq++;
			}

			else if(exp[k][i] == '}' ){
				if(stk[top] == '{' )
					top--;
				else
                    cr++;
            }
		}
	}

//----------------------outputting the result------------------------
	if(cu>0 || sq>0 || cr>0){
        if(cu>0)
            printf("\nthere are %d unbalanced '(' !",cu);
        if(sq>0)
            printf("\nthere are %d unbalanced '[' !",sq);
        if(cr>0)
            printf("\nthere are %d unbalanced '{' !",cr);
	}

	else
        printf("\nexpression is balanced" );

	getch();

}
