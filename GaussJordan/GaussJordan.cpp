/*
 * Author: Heidy Valdelamar González
 * heidyvaldelamar2406@gmail.com
 * Oct, 01 2021
 */


#include<iostream>

int main()
{
    int n,a,b;
    float A[10][10],B[10],cte,aux;
    //The unknowns and independent terms are requested
    printf("\n\t\tGAUSS-JORDAN METHOD\n");
    printf("\nEnter the number of equations: ");
    scanf("%i",&n);
    printf("Enter coefficients\n");
    for(a=0;a<n;a++)
    {
        for(b=0;b<n;b++)
        {
            printf("Element value. (%i,%i): ",a+1,b+1);
            scanf("%f",&A[a][b]);
        }
        printf("Independent term of Ec. %i: ",a+1);
        scanf("%f",&B[a]);
    }
    //Gauss-Jordan method
    for(int i=0;i<n;i++)
    {
        //It is verified that the pivot is different from zero
        if (A[i][i]==0)
        {
            for(int s=i+1;s<=n+1;s++)
            {
                if (A[s][i]!=0)
                {//Row swap
                    aux=A[i][s-1];
                    A[i][s-1]=A[i+1][s-1];
                    A[i+1][s-1]=aux;

                    aux=B[i];
                    B[i]=B[i+1];
                    B[i+1]=aux;
                }
            }

        }
        //Pivot row is normalized
        cte=A[i][i];
        for(int j=0;j<n;j++)
        {
            A[i][j]=A[i][j]/cte;
        }
        B[i]=B[i]/cte;
        //The Gaussian elimination algorithm continues
        for(int j=i+1;j<n;j++)
        {
            cte=A[j][i];
            for(int k=0;k<n;k++)
            {
                A[j][k]=A[j][k]-cte*A[i][k];
            }
            B[j]=B[j]-cte*B[i];
        }
    }
    //Reverse elimination is performed
    for(int i=n;i>=1;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            cte=A[j][i];
            A[j][i]=A[j][i]-cte*A[i][i];
            B[j]=B[j]-cte*B[i];
        }
    }


    //Printing of results
    printf("\n\n SYSTEM SOLUTION\n ");
    for(int k=0;k<n;k++)
    {
        printf("\n x[%d] = %1.4f",k+1,B[k]);
    }
    printf("\n");
    system("pause");
}
