#include<stdio.h>

float FindValueat(float x){
    return x*x*x- 2*x -5;
}
float bisect(float x1,float x2){
    return(x1+x2)/2;
}

int main(){
    int maxIteration,i=1;
    float x1,x2,x;
    printf("Enter maximun no. of iterations\n");
    scanf("%d",&maxIteration);

    do{
        printf("Enter the value of x1 and x2(starting boundary");
        scanf("%f%f",&x1,&x2);
        if(FindValueat(x1)*FindValueat(x2)>0){
            printf("Roots are invalid\n");
            continue;
        }
        else{
            printf("Roots lie between %f and %f\n",x1,x2);
            break;
        }
    } while (1);

    while(i<=maxIteration){
        x = bisect(x1,x2);
        if(FindValueat(x)*FindValueat(x1)<0) x2=x;
        else if(FindValueat(x)*FindValueat(x2)<0) x1=x;
        printf("Iteration=%d Roots=%f\n",i,x);
        i++;
    }
    printf("Root=%f Total Iterations=%d\n",x,--i);
    return 0;
}