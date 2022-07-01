#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
} NODE;

NODE *root;

NODE * CreateNode(int x,NODE *t){
    NODE *newn;
    newn=(NODE *)malloc(sizeof(NODE));
    newn->data=x;
    newn->left=NULL;
    newn->right=NULL;
    newn->parent=t;
    return newn;
}

void createbst(int size){
    int i,dta,inp;
    NODE *temp;
    for (i=1;i<(size);i++){
        
        scanf("%d",&inp);
        temp=root;
        while (((temp->left)!=NULL)&&(temp->right)!=NULL){
            dta=temp->data;

            if (inp<=dta){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
        
        dta=temp->data;
        if (inp<=dta){
            if (temp->left==NULL){
                (temp->left)=(CreateNode(inp,temp));
            }
            else if((temp->left)!=NULL){
                while (temp->left!=NULL){
                    temp=temp->left;
                    if (inp>(temp->data)){
                        temp->right=(CreateNode(inp,temp));
                        break;
                    }
                
            if (temp->left==NULL){
                (temp->left)=(CreateNode(inp,temp));
                break;
            }
            
        }}}

        else{
            if ((temp->right)==NULL){
                (temp->right)=(CreateNode(inp,temp));}

            
            else if ((temp->right)!=NULL){
                while (temp->right!=NULL){
                    temp=temp->right;
                    if (inp<(temp->data)){
                        temp->left=(CreateNode(inp,temp));
                        break;
                    }
                if ((temp->right)==NULL){
                    (temp->right)=(CreateNode(inp,temp));
                    break;
}}}}}}


int search(int x,int y){
    int tp;
    NODE *temp=root;
    while (temp!=NULL){
        tp=temp->data;
        if (((x<=tp)&&(y>tp))||((y<=tp)&&(x>tp))){
            return tp;
        }
        else if (tp<x){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }}
    printf("Key does not exist");
    return -100;
}

int lowest(NODE *ptr){
    while ((ptr->left)!=NULL){
        ptr=ptr->left;
    }
    return ptr->data;
}

int highest(NODE *ptr){
    while ((ptr->right)!=NULL){
        ptr=ptr->right;
    }
    return ptr->data;
}

void prereversal(NODE *ptr){
     if (ptr!=NULL){
     printf("%d ",ptr->data);
     prereversal(ptr->left);
     prereversal(ptr->right);   
    }

}


void inorder(NODE *ptr){
    if (ptr!=NULL){
     
     inorder(ptr->left);
     printf("%d ",ptr->data);
     inorder(ptr->right);   
     
    }

}

int deletion(NODE *ptr){
    int x;
    if (ptr!=NULL){
        if (((ptr->left)==NULL)&&((ptr->right)==NULL)){
            x=ptr->data;
            if ((ptr->parent->left)==ptr){
                ptr->parent->left=NULL;
                free(ptr);
            }
            else if ((ptr->parent->right)==ptr){
            
                ptr->parent->right=NULL;
                free(ptr);
            }
            return x;
        }
        else if (ptr->left==NULL){
            x=ptr->data;
            if (ptr->parent!=NULL){
                if ((ptr->parent->left)==ptr){
                    ptr->parent->left=ptr->right;              
                }
                else if ((ptr->parent->right)==ptr){
            
                    ptr->parent->right=ptr->right;
                }
            }
            ptr->right->parent=ptr->parent;
            free(ptr);
            return x;
        }
        else if (ptr->right==NULL){
            x=ptr->data;
            if (ptr->parent!=NULL){
                if ((ptr->parent->left)==ptr){
            
                    ptr->parent->left=ptr->left;
                    
                
                }
                else if ((ptr->parent->right)==ptr){
                    ptr->parent->right=ptr->left;    
            }
            }
            ptr->left->parent=ptr->parent;
            free(ptr);
            return x;
        }
        else{
            x=ptr->data;
            NODE *temp=ptr->right;
            if (temp->left==NULL){
                if (ptr->parent!=NULL){
                    if (ptr->parent->left==ptr){
                        ptr->parent->left=temp;
                    }
                    else if (ptr->parent->right==ptr){
                        ptr->parent->right=temp;
                    }}
                temp->parent=ptr->parent;
                free(ptr);
                return x;
                }
            
            else{
                while (temp->left!=NULL){
                    temp=temp->left;
                }
                temp->parent->left=temp->right;
                if (temp->right!=NULL){
                    temp->right->parent=temp->parent;
                }
                ptr->data=temp->data;
                free(temp);
                return x;
            }
            
        }
    }
    return -1;
}

NODE* searchptr(int val,NODE *ptr){
    while (ptr!=NULL){
        
        if ((ptr->data)==val){
            return ptr;
        }
        else if ((ptr->data)>val){
            ptr=ptr->left;
        }
        else{
            ptr=ptr->right;
        }

    }
    return NULL;
}


int main(){
    root=NULL;
    NODE *ptr;
    int size,inp,i,m;
    scanf("%d",&size);
    scanf("%d",&inp);
    root=CreateNode(inp,NULL);
    createbst(size);
    for (i=0;i<3;i++){
        scanf("%d",&m);
        ptr=searchptr(m,root);
        deletion(ptr);
        
    }
    
    inorder(root);
    
    
    return 0;
}