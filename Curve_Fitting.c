//C Program to Fit a straight line on given points
#include<stdio.h>
int main()
{
    int n;
    float sum1=0,sum2=0,sum3=0,sum4=0,a,b;
    printf("Enter no. of observations\n");
    scanf("%d",&n);
    float x[n],y[n],augmented_matrix[2][3];
    printf("Enter values of x\n");
    for(int i=0;i<n;i++) scanf("%f",&x[i]);
    printf("Enter values of y\n");
    for(int i=0;i<n;i++) scanf("%f",&y[i]); 

    for(int i=0;i<n;i++){
        sum1+=x[i];
        sum2+=y[i];
        sum3+=x[i]*y[i];
        sum4+=x[i]*x[i];
    }
    augmented_matrix[0][0]=n;
    augmented_matrix[0][1]=sum1;
    augmented_matrix[0][2]=sum2;
    augmented_matrix[1][0]=sum1;
    augmented_matrix[1][1]=sum4;
    augmented_matrix[1][2]=sum3;

    int ratio=augmented_matrix[1][0]/augmented_matrix[0][0];
    for(int i=0;i<3;i++) augmented_matrix[1][i] -= ratio*augmented_matrix[0][i];
    
    printf("\nThe Upper Triangular Matrix:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++) printf("%.2f ",augmented_matrix[i][j]);
        printf("\n");  
    }
    b=augmented_matrix[1][2]/augmented_matrix[1][1];
    a=(augmented_matrix[0][2]-augmented_matrix[0][1]*b)/augmented_matrix[0][0];
    printf("\nIntercept = %.2f and Slope = %.2f\n\n",a,b); 
    printf("Equation of The line: y= %.2f + %.2fx",a,b);
}