#include<stdio.h>
#define STACK_SIZE 15

void push(char s[],int *top,char item){
*top++;
s[*top]=item;
}

char pop(char s[],int *top){
return (s[*top--]);
}

int pr(char op){
switch(op)
{
case '#': return 0;
case '(': return 1;
case '+': return 2;
case '-': return 2;
case '*': return 3;
case '/': return 3;
default: return 0;

}
}

void main(){
    char s[STACK_SIZE];
    int top,item;
    char str[30],postfix[30];
    top=-1;
    int i=0,j=0,k=0,count=0;
    push(s,&top,'#');
    printf("Enter infix expression:");
    scanf("%s",&str);
    while(str[i]!='\0'){
        count++;
        i++;
    }
    for(int i=0;i<count;i++){
        if(str[i]!= '+' || str[i]!= '-' || str[i]!= '*' || str[i]!= '/'){
            postfix[j]=str[i];
            j++;
        }
        else{
            if(pr(str[i])>pr(s[top])){
                push(s,&top,str[i]);
            }
            else if(pr(str[i])<=pr(s[top])){
                postfix[j]=s[top];
                pop(s,&top);
                push(s,&top,str[i]);
            }
            else if(str[i]=='('){
                postfix[j]=s[top];
                push(s,&top,'(');
            }
            else if(str[i]==')'){
                while(s[top]!='('){
                postfix[j]=s[top];
                }
                while(s[top]!='('){
                    pop(s,&top);
                }
                pop(s,&top);
            }
            else{
                continue;
            }

        }
    }
    printf("%s",postfix);    
}
