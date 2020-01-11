#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define INITIAL_TOK 0
#define TOK_NUM 1 
#define TOK_X 2
#define TOK_SIN 3
#define TOK_COS 4
#define TOK_TAN 5
#define TOK_LN 6
#define TOK_SH 7
#define TOK_CH 8
#define TOK_SUM 11
#define TOK_MIN 12
#define TOK_MULT 13
#define TOK_DIV 14
#define TOK_POW 15
#define TOK_LPARA 16
#define TOK_RPARA 17
#define PREC_SUM 1
#define PREC_MIN 1
#define PREC_MULT 2
#define PREC_DIV 2
#define PREC_POW 3
#define PREC_PARA 4


int check_for_number(int number){

    if (number >='0' && number <= '9'){
        return 1;
    }
    return 0;
}

int operator_test(char ch){
    if (ch == '+' || ch == '-' || ch == '(' || ch == ')' ){
        return 1;
    }
    return 0;
}

struct tree {
    struct treenode* root;
    struct treenode* lastarm;
};



struct treenode
{
    int type;
    int value;
    int prece;
    struct treenode *next;
};


void push_arms(struct tree* to, int armType, int armValue, int armPrec){
    struct treenode* new_node = (struct treenode*) malloc(sizeof(struct treenode));
    new_node->type = armType;
    new_node->value = armValue; 
    new_node->prece = armPrec;   
    new_node->next = NULL;
    to->lastarm->next = new_node;
    to->lastarm = new_node;
}

struct tree* make_tree() {
    struct tree* ret = (struct tree*) malloc(sizeof(struct tree));
    struct treenode* firstnode = (struct treenode*) malloc(sizeof(struct treenode));

    firstnode->value = 0;
    firstnode->type = INITIAL_TOK;
    firstnode->next = NULL;

    ret->root = firstnode;
    ret->lastarm = firstnode;

    return ret;
}

struct tree* make_stack(){
    struct tree* ret = (struct tree*) malloc(sizeof(struct tree));
    struct treenode* firstnode = (struct treenode*) malloc(sizeof(struct treenode));

    firstnode->value = 0;
    firstnode->type = INITIAL_TOK;
    firstnode->next = NULL;

    ret->root = firstnode;
    ret->lastarm = firstnode;

    return ret;
}



void test_tree(struct treenode* node){
    printf("\nNode TOK(%d) \t VAL(%d) at %p", node->type, node->value, (void *)node);
    if (node->next != NULL) { 
        test_tree(node->next);
    }
}
void push_stack(struct tree* to, int armType, int armValue, int armPrece){
    struct treenode* new_node = (struct treenode*) malloc(sizeof(struct treenode));
    new_node->type = armType;
    new_node->value = armValue; 
    new_node->prece = armPrece;   
    new_node->next = to->root;
    to->root = new_node;
}

void push_qeue(struct treenode* node, struct tree* to, struct tree* stack){

    if (stack->root->type == 0){
        if (node->type >= 1 && node->type <= 8){
            struct treenode* new_node = (struct treenode*) malloc(sizeof(struct treenode));

            new_node->type = node->type;
            new_node->value = node->value;    
            new_node->next = NULL;
            to->lastarm->next = new_node;
            to->lastarm = new_node;
            if(node->next != NULL){
                push_qeue(node->next, to, stack);
            }
        }
        else if( node->type >= 11 && node->type <= 17){
            push_stack(stack, node->type, node->value, node->prece);
            push_qeue(node->next, to, stack);
        }
        else{
            push_qeue(node->next, to, stack);
        }
    } 
    else{
        if (node->type >= 1 && node->type <= 8){
            struct treenode* new_node = (struct treenode*) malloc(sizeof(struct treenode));

            new_node->type = node->type;
            new_node->value = node->value;    
            new_node->next = NULL;
            to->lastarm->next = new_node;
            to->lastarm = new_node;
            if(node->next != NULL){
                push_qeue(node->next, to, stack);
            }
            else{
                if(stack->root->type != 0){
                    push_arms(to, stack->root->type, stack->root->value, stack->root->prece);
                    printf("%d", stack->root->next->type);
                    stack->root = stack->root->next;
                }
            }
        }
        else if (node->type >=11 && node->type <= 17) {
            struct treenode* new_node = (struct treenode*) malloc(sizeof(struct treenode));

            new_node->type = node->type;
            new_node->value = node->value;    
            new_node->next = NULL;
            if (node->prece == stack->root->prece){
                push_stack(stack, node->type, node->value, node->prece);
                push_qeue(node->next, to, stack);
            }
        }
        else{
            push_arms(to, stack->root->type, stack->root->value, stack->root->prece);
            printf("33");
            push_qeue(node->next, to, stack);
        }
    }  
}



int main(){
    char c, input[2000] = {0};
    int i=0, length_of_arr;

    struct tree* arm = make_tree();
    struct tree* qeue = make_tree();
    struct tree* stack = make_stack();

    while(( c = getchar()) != EOF){
        input[i++] = c;
    }
    length_of_arr = i;

    for(i=0; i < length_of_arr; i++){
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t'){
            continue;
        }
        if (check_for_number(input[i])){
            if (arm->lastarm->type == TOK_NUM) {
                arm->lastarm->value = (input[i]-'0') + 10*arm->lastarm->value;
            } else {
                push_arms(arm, 1, input[i] - '0', 0);
            }
        }
        else if(input[i] == 'X'){
            push_arms(arm, 2, 0, 0);
        }
        else if(input[i] == 's'){
            if(input[i+1] == 'i'){
                push_arms(arm, 3, 0, 0);
                i += 2;
            }
            else if (input[i] == 'h'){
                push_arms(arm, 7, 0, 0);
                i++;
            }
        } 
        else if(input[i] == 'c'){
            if (input[i+1] == 'o'){
                push_arms(arm, 4, 0, 0);
                i += 2;
            }
            else if(input[i+2] == 'h'){
                push_arms(arm, 8, 0, 0);
            }
        }
        
        else if (input[i] =='l'){
            push_arms(arm, 6, 0, 0);
            i++;
        }
        else if(input[i] == '+'){
            push_arms(arm, TOK_SUM, 0, PREC_SUM);
        }
        else if(input[i] == '-'){
            push_arms(arm, TOK_MIN, 0, PREC_MIN);
        }
        else if(input[i] == '*'){
            push_arms(arm, TOK_MULT, 0, PREC_MULT);
        }
        else if(input[i] == '/'){
            push_arms(arm, TOK_DIV, 0, PREC_DIV);
        }
        else if(input[i] == '^'){
            push_arms(arm, TOK_POW, 0, PREC_POW);
        }
        else if(input[i] == '('){
            push_arms(arm, TOK_LPARA, 0, PREC_PARA);
        }
        else if(input[i] == ')'){
            push_arms(arm, TOK_RPARA, 0, PREC_PARA);
        }
    }    
    
    test_tree(arm->root);
   

    push_qeue(arm->root, qeue, stack);
    test_tree(qeue->root);


    return 0;
}

