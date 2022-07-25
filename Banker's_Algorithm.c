#include<stdio.h>
void read (int a,int b,int x[20][20])                    // a-> no of rows
{                                                        // b-> no of columns
    for(int i=0;i<a;i++)
        for(int j=0;j<b;j++)
            scanf("%d",&x[i][j]);
}
void main()
{
    int n, m, k, y,alloc[20][20],max[20][20],avail[50],ind=0;
    printf("Enter the no of Proceses\t:\t");
    scanf("%d",&n);
    printf("Enter the no of Resources\t:\t");
    scanf("%d",&m);
    printf("Enter the Allocation Matrix\t:\t");
    read(n,m,alloc);
    printf("Enter the Max Matrix\t:\t");
    read(n,m,max);
    printf("Enter the Available Matrix\t:\t");
    for(i=0;i<m;i++)
        scanf("%d",&avail[i]);        
    int finish[n],safesequence[n],work[m],need[n][m],flag=0;
    for (i = 0; i < n; i++)                                       
    {
        finish[i] = 0;                                     //Initializing finish matrix to 0
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];             //calculating NEED matrix
    }
    printf("NEED matrix is");
    for (i = 0; i < n; i++) 
    {
        printf("\n");
        for (j = 0; j < m; j++)
            printf(" %d ",need[i][j]);
    }
    for(i=0;i<m;i++)
    {
        work[i]=avail[i];
    }
    for (k = 0; k < n; k++) 
    {
        for (i = 0; i < n; i++) 
        {
            if (finish[i] == 0) 
            {
                flag = 0;
                for (j = 0; j < m; j++) 
                {
                    if (need[i][j] > work[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) 
                {
                    safesequence[ind++] = i;
                    for (y = 0; y < m; y++)
                        work[y] += alloc[i][y];
                    finish[i] = 1;
                }
            }
        }
    }
    printf("\nFollowing is the SAFE Sequence\n");
    for (i = 0; i <= n - 1; i++)
    printf(" P%d\t", safesequence[i]);
    printf("\n");
}
//0 1 0 2 0 0 3 0 2 2 1 1 0 0 2
// 7 5 3 3 2 2  9 0 2 2 2 2 4 3 3 