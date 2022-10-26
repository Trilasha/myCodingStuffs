#include<stdio.h>
int main(){
    long long int num1=0;
    long long int num2=0;
    scanf("%lld %lld",&num1,&num2);
    long long int i=30;
    long long int q=0;
    long long int temp=0;
    
    while(num1>=num2){
        temp= 1<<i;
        if(num1>=num2*temp){
            num1 -= num2*temp;
            q += temp;
        }
        i--;
    }
    printf("The quotient is : %lld and Remainder is : %lld",q,num1);
    return 0;
}