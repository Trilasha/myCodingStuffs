#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *next;
};

struct node* top = NULL;
struct node* onroad = NULL;


void enterroad(int value)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value; 
    if (onroad == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = onroad; 
    }
    onroad = newNode; 
}


void exitroad(int value)
{
    if (onroad == NULL) {
       return;
    } else {
        struct node *temp = onroad;
        int temp_data = onroad->data;
        onroad = onroad->next;
        free(temp);
        return;
    }
    
}


void enterGarage(int value) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value; 
    if (top == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = top; 
    }
    top = newNode; 
}

void exitGarage() {
    if (top == NULL) {
       return;
    } else {
        struct node *temp = top;
        int temp_data = top->data;
        top = top->next;
        free(temp);
        return;
    }
}

void showTrucksInGarage() {
    if (top == NULL) {
      return;
    } else {
        printf("The trucks present in the garage are: \n");
        struct node *temp = top;
        while (temp->next != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n\n", temp->data);
    }
}


void showTrucksOnRoad() {
    if (onroad == NULL) {
      return;
    } else {
        printf("The trucks present on the road are: \n");
        struct node *temp = onroad;
        while (temp->next != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n\n", temp->data);
    }
}



int onRoad(int value)
{
    struct node* dup=onroad;
    while(dup!=NULL)
    {
        if(dup->data==value)
        return 1;
        else
        dup=dup->next;
    }
    return 0;
}


int closest_to_entry(int value)
{
    if(top->data!=value)
    return 0;
    else
    return 1;
}

int main(){
     int n;
     printf("How many cars are in the road\n");
     scanf("%d", &n);
     
     printf("Enter the Trucks present in Road\n");
    // int mxx=0;

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


//what if we want to exit a car from the garage which is not there only? 
//any special message to be shown for that?
