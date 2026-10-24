#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
}Node;

typedef struct stack {
    Node*top;
}Stack;

void initStack(Stack* s){
    s->top=NULL;
}

int isEmpty(Stack s){
    return s.top == NULL;
}

void push(Stack* s, char value){
    Node* n = malloc(sizeof(Node));
    if(n == NULL){
        printf("Memory error\n");
        return;
    }
    n->data = value;
    n->next = s->top;
    s->top = n;
}

char pop(Stack* s){
    if (isEmpty(*s)){
        printf("Stack is empty\n");
        return 0;
    }
    Node* t = s->top;
    char v = t->data;
    s->top = t->next;
    free(t);
    return v;
}

char peek(Stack s){
    if (isEmpty(s)){
        return 0;
    }
    return s.top->data;
}

void display(Stack s){
    if(isEmpty(s)){
        printf("stack is empty.\n");
        return;
    }
    printf("top -> ");
    Node* p = s.top;
    while (p != NULL){
       printf("%c", p->data);
       p = p->next; 
    }
    printf("\n");
}


int evalExp(char exp[]){
     stack s;
     initStack(&s);
     int i = 0; 
     int a, b, result;

     while (exp[i] != '\0'){
        char c = exp[i];

        if(c >='0'  &&  c <= '9'){
            push(&s, c - '0');
        }
            else {
                switch (c){
                    case '+':
                        b = pop(&s);
                        a = pop(&s);
                        push(&s, a + b);
                        break;
                    case '-':
                        b = pop(&s);
                        a = pop(&s);
                        push(&s, a - b);
                        break;
                    case '*':
                        b = pop(&s);
                        a = pop(&s);
                        push(&s, a * b);
                        break;
                    case '/':
                        b = pop(&s);
                        a = pop(&s);
                        if(b == 0){
                            printf("error: division by zero!\n");
                            return 0;
                        }
                    result = a / b;
                        break;
                    default:
                        break;
                }
            }
            i++;
     }
     return pop(&s);
}


int main(){
    Stack s;
    initStack(&s);
    int choice = 0;
    char c;
    char exp[100];

    while(choice != 5){
        printf("\n1. Push\n2. pop\n3. Display\n4. Evaluate postfix\n5. Exit\nChoice");
        scanf("%c", &c);

        if(choice == 1){
            printf("Character to push:");
            scanf(" %c",&c);
            push(&s, c);
        }
        else if(choice == 2){
            if(!isEmpty(s)){
                printf("Popped: %c\n", pop(&s));
            }else{
                printf("Stack is empty\n");
            }
        }
        else if(choice == 3){
            display(s);
        }
        else if(choice == 4){
            printf("postfix expression (e.g. 63+2*4/):");
            scanf("%99[^\n]",exp);
            printf("result = %d\n", evalExp(exp));
        }
        else if(choice != 5){
            printf("invalid choice\n");
        }
    }
    return 0;
}