#include<stdio.h> 
void main() 
{
    int i, j, k, f, pf=0, count=0, rs[25], m[10], n,g; 
    printf("\nEnter the length of reference string\t:"); 
    scanf("%d",&n); 
    printf("Enter the reference string \t\t:"); 
    for(i=0;i<n;i++) 
    scanf("%d",&rs[i]); 
    printf("Enter no. of frames \t\t\t:"); 
    scanf("%d",&f); 
    for(i=0;i<f;i++) 
        m[i]=-1;
    printf("\n\tThe Page Replacement Process\n_______________________________________________\n");
    printf("\nREFERENCE STRING\t\tPAGE FRAMES\n");
    for(i=0;i<n;i++) 
    { 
        printf("\t%d\t",rs[i]);
        for(k=0;k<f;k++) 
        { 
            if(m[k]==rs[i]) 
                break;         //HIT
        } 
        if(k==f)               //MISS
        { 
            m[count++]=rs[i];
            pf++; 
        }  
        if(count==f) 
            count=0;
        for(j=0;j<f;j++)
            printf("\t%d",m[j]); 
        if(k==f)               //MISS
            printf("\tMISS - %d",pf); 
        else
            printf("\tHIT  - %d",++g); 

        printf("\n"); 
    }    
    printf("\n The number of Page Faults \t: %d\n",pf); 
}
// 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 7 0 1
