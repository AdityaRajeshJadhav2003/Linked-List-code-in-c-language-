// program for a single linked_list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
// declaration of different fuctions
struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node * start);
void search(struct node *start, int item);
struct node *add_at_beg(struct node *start, int data);
struct node *add_at_end(struct node *start, int data);
struct node *add_after(struct node *start, int data, int item);
struct node *add_before(struct node *start, int data, int item);
struct node *add_at_pos(struct node *start, int data, int pos);
struct node *del(struct node *start, int data);
struct node *reverse(struct node *start);

int main(){
    struct node *start = NULL;
    int choice, data, item, pos;
    while(1){
        printf("1.Create list\n");
        printf("2.Display\n");
        printf("3.Count\n");
        printf("4.Search\n");
        printf("5.Add to empty list\n");
        printf("6.Add at end\n");
        printf("7.Add after node\n");
        printf("8.Add before node\n");
        printf("9.Add at position\n");
        printf("10.Delete\n");
        printf("11.Reverse\n");
        printf("Enter your choice :");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            start = create_list(start);
            break;

            case 2:
            display(start);
            break;
            
            case 3:
            count(start);
            break;

            case 4:
            printf("Enter the element to be searched : ");
            scanf("%d",&item);
            search(start, item);
            break;

            case 5:
            printf("Enter the element be inserted : ");
            scanf("%d",&data);
            start=add_at_beg(start, data);
            break;

            case 6:
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            start = add_at_end(start,data);
            break;

            case 7:
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            printf("Enter the element after which to be inserted : ");
            scanf("%d",&item);
            start = add_after;
            break;

            case 8:
            printf("Enter the element to be insterted : ");
            scanf("%d",&data);
            printf("Enter the element before which to be inserted : ");
            scanf("%d",&item);
            start = add_before;
            break;

            case 9:
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            printf("Enter the position at which to be inserted : ");
            scanf("%d", &pos);
            start = add_at_pos;
            break;

            case 10:
            printf("Enter the element to be deleted : ");
            scanf("%d",&data);
            start = del(start,data);
            break;

            case 11:
            start = reverse(start);
            break;

            default:
            printf("Wrong choice !!!!");

        }
    }
}
// definitions of all the fuctions.
void display(struct node *start){
    struct node *p;
    if(start == NULL){
        printf("List is empty.");
        return;
    }
    p = start;
    printf("List is :\n ");
    while(p != NULL){
        printf("%d",p->info);
        p ->link;
    }
    printf("\n\n");
}
void count(struct node *start){
    struct node *p;
    int cnt = 0;
    p = start;
    while(p!=NULL){
        p = p->link;
        cnt++;
    }
    printf("Number of elements are %d\n", cnt);
}
void search(struct node *start, int item){
    struct node *p;
    int pos = 1;
    while(p != NULL){
        if(p->info == item){
            printf("%d is found at %d position.",item,pos);
            return;
        }
        p = p->link;
        pos++;
    }
    printf("Item not found.");
}
struct node *add_at_beg(struct node *start, int data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = start;
    start = temp;
    return start;
}
struct node *add_at_end(struct node *start, int data){
    struct node *p,*temp;
    p = start;
    temp=(struct node*)malloc(sizeof(struct node));
    while(p->link != NULL){
        p = p->link;
    }
    p->link = temp;
    temp->link = NULL;
    return start;
}
struct node *add_after(struct node *start, int data,int item){
    struct node *p,*temp;
    p = start;
    while(p != NULL){
        if(p->info == item){
            temp = (struct node *)malloc(sizeof(struct node));
            temp->info = data;
            temp->link = p->link;
            p->link = temp;
            return start;
        }
        p = p->link;
    }
    printf("%d is not present in given linked list.",item);
}
struct node *add_before(struct node *start, int data, int item){
    struct node *p, *temp;
    if(start == NULL){
        printf("List is empty.");
        return start;
    }
    if(item == start -> info ){
        temp = (struct node*)malloc(sizeof(struct node));
        temp->info = data;
        temp->link = start;
        start = temp;
        return start;
    }
    p = start;
    while(p!= NULL){
        if(p->link->info == item){
            temp=(struct node*)malloc(sizeof(struct node));
            temp ->info = data;
            temp->link = p->link;
            p->link = temp;
            return start;
        }
        p = p->link;
    }
}
struct node *add_at_pos(struct node *start, int data, int pos){
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info= data;
    if(pos == 1){
        temp ->link = start;
        start = temp;
        return start;
    }
    p = start;
    for(int i = 1; i < pos - 1 && p != NULL; i++){
        p = p->link;
    }
    if(p == NULL){
        printf("There are less than %d elements in the list.", pos);
    }
    else{
        temp ->link = p ->link;
        p ->link = temp;
    }
    return start;
}
struct node *create_list(struct node *start){
    int i,n,data;
    printf("Enter the number of nodes :");
    scanf("%d", &n);
    start = NULL;
    if(n == 0){
        return start;
    }
    printf("Enter the elements - ");
    scanf("%d", &data);
    start = add_at_beg(start,data);
    for (i =2; i <= n; i++){
        printf("Enter the elements - ");
        scanf("%d", &data);
        start = add_at_end(start,data);
    }
    return start;
}
struct node *del(struct node *start,int data){
    struct node *temp,*p;
    if(start == NULL){
        printf("List is empty.");
        return start;
    }
    if(start ->info == data){
        temp = start;
        start = start->link;
        free(temp); 
        return start;
    }
    p = start;
    while(p ->link != NULL){
        if(p->link->info == data){
            temp = p->link;
            p->link=temp->link;
            free(temp);
            return start;
        }
        p = p->link;
    }
    printf("Element %d is not present in list.",data);
    return start;
}
struct node *reverse(struct node *start){
    struct node *prev, *next, *ptr;
    prev = NULL;
    ptr=start;
    while(ptr != NULL){
        next = ptr ->link;
        ptr ->link = prev;
        prev = ptr;
        ptr = next;
    }
    start = prev;
    return start;
}

//sorting of linked list 

/*SORTING 0F LL BY EXCHANGING DATA*/
//selection sort by exchanging data.
struct node *sel(struct node *start){
    struct node *p, *q;
    int tmp;
    for(p = start; p ->link != NULL; p = p->link){
        for(q = p->link; q != NULL; q = q->link){
            if(p->info > q->info){
                tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
}

// bubble sort by exchanging data
struct node *bub(struct node *start){
    struct node *p, *q, *end;
    int tmp;
    for(end = NULL; end != p->link; end = q){
        for(p = start; p->link != end; p = p->link){
            if(p->info > q->info){
                tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
}

/*SORTING OF LL BY REARRANGING LINKS*/
