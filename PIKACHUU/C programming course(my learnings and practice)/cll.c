#include<stdio.h>
#include<stdlib.h>
 
 
struct node {
    int data;
    struct node *next;
};
 
struct node *f_road = NULL;
struct node *r_road = NULL;
 
 
struct node *f_garage = NULL;
struct node *r_garage= NULL;
 
 
 
void enterroad(int value)
{
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;
    if((r_road==NULL)&&(f_road==NULL))
    {
        f_road = r_road = n;
        r_road->next = f_road;
    }
    else
    {
        r_road->next = n;
        r_road = n;
        n->next = f_road;
    }
    printf("\nEntered truck(on the road) -> %d", n->data);
}
 
 
void exitroad(int value)
{
   struct node* t;
    t = f_road;
    if((f_road==NULL)&&(r_road==NULL))
        printf("\nNo trucks are there on the road");
    else if(f_road == r_road){
        f_road = r_road = NULL;
        free(t);
    }
    else{
        f_road = f_road->next;
        r_road->next = f_road;
        printf("\nExited truck from the road -> %d", t->data);
        free(t);
    }
    
}
 
 
void enterGarage(int value) {
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;
    if((r_garage==NULL)&&(f_garage==NULL))
    {
        f_garage = r_garage = n;
        r_garage->next = f_garage;
    }
    else
    {
        r_garage->next = n;
        r_garage = n;
        n->next = f_garage;
    }
    printf("\nEntered truck(in the garage) -> %d", n->data);
}
 
void exitGarage() {
    struct node* t;
    t = f_garage;
    if((f_garage==NULL)&&(r_garage==NULL))
        printf("\nNo trucks are present in the garage");
    else if(f_garage == r_garage){
        f_garage = r_garage = NULL;
        free(t);
    }
    else{
        f_garage = f_garage->next;
        r_garage->next = f_garage;
        printf("\nExited truck -> %d", t->data);
        free(t);
    }
}
 
void showTrucksInGarage() {
    struct node* t;
    t = f_garage;
    if((f_garage==NULL)&&(r_garage==NULL))
        printf("\nNo trucks are present in the garage");
    else{
        do{
            printf("\n%d",t->data);
            t = t->next;
        }while(t != f_garage);
    }
}
 
 
void showTrucksOnRoad() {
   struct node* t;
    t = f_road;
    if((f_road==NULL)&&(r_road==NULL))
        printf("\nNo trucks are present on the road");
    else{
        do{
            printf("\n%d",t->data);
            t = t->next;
        }while(t != f_road);
    }
}
 
 
 
int onRoad(int value)
{
    struct node* dup=f_road;
    do{
        if(dup->data==value)
        return 1;
        else
        dup = dup->next;
        }while(dup != f_road);
    return 0;
}
 
 
int closest_to_entry(int value)
{
    if(f_garage->data!=value)
    return 0;
    else
    return 1;
}
 
int main(){
     int n;
     printf("How many cars are in the road\n");
     scanf("%d", &n);
     
     printf("Enter the Trucks present in Road\n");
     for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        enterroad(x);
     }
     int check=1;
     while(check)
     {
     printf("\n\nselect the operation that you want to perform\n");
     printf("1 for onRoad\t\t2 for enterGarage\n3 for exitGarage\t4 for showTrucks\n");
     printf("5 to exit\n");
     
     int op,tNo, tNo2;
     scanf("%d", &op);
    
     switch (op){
         case 1:
            printf("Enter the Truck You want to check: \n");
            int check;
            scanf("%d", &check);
            int flag= onRoad(check);
            if(flag==1){
                printf("\nIt is on Road\n");
            }
            else {
                printf("\nIt is not on Road\n");
            }
            break;
         case 2:
            printf("Enter the Truck You want to enter into the garbage: \n");
            scanf("%d", &tNo);
            enterGarage(tNo);
            exitroad(tNo);
            break;
         case 3:
            printf("Enter the Truck You want to exit from the garbage: \n");
            scanf("%d", &tNo2);
            int chk2=closest_to_entry(tNo2);
            if(chk2==1)
            {
            exitGarage(tNo2);
            enterroad(tNo2);
            }
            else
            printf("Truck %d is not near the garage door",tNo2);
            break;
         case 4:
            printf("1 for garage\t\t for road\n");
            check;
            scanf("%d", &check);
 
            if(check==1){
                showTrucksInGarage(check);
                break;
            }
            else{
                showTrucksOnRoad(check);
                break;
            }
         case 5:
            check=0;
            return 0;
         default:   
            printf("Invalid input");
            break;
     }
    }
     
 
 
}