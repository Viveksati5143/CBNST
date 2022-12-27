//C Program to Fit a 2nd degree Parabola (y=ax^2 + bx +c ) on given points
#include<stdio.h>

void convertToUpperTriangular(float a[3][4],int n){
    int i,j,x,y,k;
    float ratio;
    for( i=0;i<n;i++){
      for(j=0;j<n;j++){
        if(j>i){
            ratio=a[j][i]/a[i][i];
            printf("Ratio=%f\n ",ratio);
            for(k=0;k<n+1;k++) a[j][k]=a[j][k]-( ratio * a[i][k]); 
            printf("Intermediate forms:\n");
            for(x=0;x<n;x++){
            for(y=0;y<n+1;y++) printf("%.2f ",a[x][y]);
            printf("\n"); 
            }
            printf("\n");
            }
        }
    }
}
void ApplyBackSubstitution(float a[3][4],float value[],int n){
    int i,j;
    float sum;
    value[n-1]=a[n-1][n]/a[n-1][n-1]; 

    for(i=n-2;i>=0;i--){
        sum=0;
        for(j=i+1;j<n;j++) sum+=a[i][j]*value[j];  
        value[i] = (a[i][n]-sum)/a[i][i];
    } 
}
int main(){
    int n;
    float Sx=0,Sy=0,Sxy=0,Sx2y=0,Sx2=0,Sx3=0,Sx4=0,a,b,c;
    float value[3];
    printf("Enter no. of observations\n");
    scanf("%d",&n);
    float x[n],y[n],augmented_matrix[3][4];
    printf("Enter values of x\n");
    for(int i=0;i<n;i++) scanf("%f",&x[i]);
    printf("Enter values of y\n");
    for(int i=0;i<n;i++) scanf("%f",&y[i]); 

    for(int i=0;i<n;i++){
        Sx   += x[i];
        Sy   += y[i];
        Sxy  += x[i]*y[i];
        Sx2y += x[i]*x[i]*y[i];
        Sx2  += x[i]*x[i];
        Sx3  += x[i]*x[i]*x[i];
        Sx4  += x[i]*x[i]*x[i]*x[i];
    }

    augmented_matrix[0][0]=Sx2;
    augmented_matrix[0][1]=Sx;
    augmented_matrix[0][2]=n;
    augmented_matrix[0][3]=Sy;
    augmented_matrix[1][0]=Sx3;
    augmented_matrix[1][1]=Sx2;
    augmented_matrix[1][2]=Sx;
    augmented_matrix[1][3]=Sxy;
    augmented_matrix[2][0]=Sx4;
    augmented_matrix[2][1]=Sx3;
    augmented_matrix[2][2]=Sx2;
    augmented_matrix[2][3]=Sx2y;
    convertToUpperTriangular(augmented_matrix,3);
    ApplyBackSubstitution(augmented_matrix,value,3);

    printf("\nValue of a = %.2f \nValue of b = %.2f\nValue of c = %.2f\n\n",value[0],value[1],value[2]); 
    printf("Equation of The Parabola: y= %.2fx^2 + %.2fx + %.2f",value[0],value[1],value[2]);
}