#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char *S;
};

void create(struct stack *st){
    st->top = -1;
    st->size = 10;
    st->S = (char *)malloc(st->size*sizeof(char));
};

// void display(char d){
//     int i=0;
//     while(d[i] != '\0'){
//         printf("%c ",d[i++]);
//     }
// }

void push(struct stack *st,char x){
    if (st->top == st->size-1)
    {
        printf("stack overflow");
    }else{
        st->top++;
        st->S[st->top] = x;
    }
};

char pop(struct stack *st){
    char x;
    if (st->top == -1)
    {
        printf("stack is empty");
    }else{
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

bool isEmpty(struct stack st){
    if (st.top == -1)
    {
        return true;
    }else{
        return false;
    }
};

bool isFull(struct stack st){
    if (st.top == st.size-1)
    {
        return true;
    }else{
        return false;
    }
};

char stackTop(struct stack st){
    char x;
    x = st.S[st.top];
    return x;
};

int isOperand(char c){
    if (c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')')
    {
        return 0;
    }else{
        return 1;
    }
}

int preceOut(char c){
    if (c=='+'||c=='-')
    {
        return 1;
    }else if(c=='*'||c=='/'){
        return 3;
    }else if(c=='^'){
        return 6;
    }else if(c=='('){
        return 7;
    }else if(c==')'){
        return 0;
    }
}

int preceIn(char c){
    if (c=='+'||c=='-')
    {
        return 2;
    }else if(c=='*'||c=='/'){
        return 4;
    }else if(c=='^'){
        return 5;
    }else if(c=='('){
        return 0;
    }else if(c==')'){

    }
}



// char * convert(char *infix){
//     struct stack st;
//     push(&st,'#');
//     int i,j;
//     i=j=0;
//     int len = strlen(infix);
//     char* postfix = (char *)malloc((len+2)*sizeof(char));
//     while (infix[i] !='\0')
//     {
//         if (isOperand(infix[i]))
//         {
//             postfix[j++] = infix[i++];
//         }else{
//                 if (prece(infix[i]) > prece(stackTop(st)))
//                 {
//                     push(&st,infix[i++]);
//                 }else{
//                    postfix[j++] = pop(&st);
//                 }
//         }
//     }
    
//     while (!isEmpty(st))
//     {
//         postfix[j++] = pop(&st);
//     }
//     postfix[j] = '\0';
//     return postfix;
// }

char * convert2(char *infix2){
    struct stack st;
    int len = strlen(infix2);
    char* postfix2 = (char *)malloc((len+2)*sizeof(char));
    int i,j;
    i=j=0;
    while (infix2[i] != '\0')
    {
        if (isOperand(infix2[i]))
        {
            postfix2[j++] = infix2[i++];
        }else{
            if (preceOut(infix2[i]) > preceIn(stackTop(st)))
            {
                push(&st,infix2[i++]);
            }else if(preceOut(infix2[i]) < preceIn(stackTop(st)))
            {
                postfix2[j++] = pop(&st);
            }else if(preceOut(infix2[i]) == preceIn(stackTop(st)))
            {
                pop(&st);
                infix2[i++];
            }
        }
        
    }
    
    while (!isEmpty(st))
    {
        postfix2[j++] = pop(&st);
    }
    postfix2[j] = '\0';
    return postfix2;
    
}

int main(){
    struct stack st;
    create(&st);
    push(&st,'#');
    char *infix2 = "((a+b)*c)-d^e^f";
    char *s= convert2(infix2);
    printf("%s ",s);
    return 0;
}
