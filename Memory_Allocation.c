#include<stdio.h>
#include<stdlib.h>
int mb,n,i,mem[10],mem1[10],pro[10],alloc[10],pmb[10],pmb_p[10];
//  pmb ->possible memory block(storing possible memory block for a particular process)                                        
void copy()
{
    for(i=0;i<mb;i++)
        mem1[i]=mem[i];
}
void print()
{
    
    printf("\n\tMemory allocation\n---------------------------------");
    for( i=0 ; i<n ; i++)
    {
        if(alloc[i]!=-1)
            printf("\n\tP%d:  %d -->  %d",i+1,pro[i],alloc[i]);
        else
            printf("\n\tP%d  Must wait for memory",i+1);
    }
    printf("\n");
}
void main()
{
    int ch,j,temp,k=0,flag=0,ind=0,min_pmb,min_pmb_p;
    char x;
    do{
        printf("\n\t1.New program\n\t2.Display\n\t3.First Fit\n\t4.Best Fit\n\t5.Worest Fit\n\t6.Exit");
        printf("\nEnter your choice\t:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the number of Memory block\t:");  
                scanf("%d",&mb);                                      // Reading Memory block & process size
                printf("Enter %d memory blocks\t\t\t:",mb);
                for(i=0;i<mb;i++)
                    scanf("%d",&mem[i]);
                printf("Enter the number of process\t\t:");
                scanf("%d",&n);
                printf("Enter %d Process size\t\t\t:",n);
                for(i=0;i<n;i++)
                    scanf("%d",&pro[i]);    
            break;
            case 2:
                printf("\n\tProcess Size |\tMemory Block\n");       //Displaying MB & process size 
                for(i=0;i<mb;i++)
                {
                    if(pro[i])
                        printf("\t     %d     |",pro[i]);
                    else
                        printf("\t             |");
                    printf("\t    %d\n",mem[i]);   
                }
                break;
            case 3:
                copy();                                     //First fit
                for(i=0;i<n;i++)
                {
                    for(j=0;j<mb;j++)
                    {
                        flag=0;
                        if(pro[i]<=mem1[j])
                        {
                            alloc[i]=mem1[j];
                            mem1[j] -= pro[i];
                            flag=1;
                            break;
                        }
                    }
                    if(flag != 1)
                        alloc[i]=-1;
                }
                print();
                break;
            case 4:                                     //best fit
                copy();
                for(i=0;i<n;i++)
                {
                    flag=0;
                    for(j=0,ind=0;j<mb;j++)
                    {
                        if(pro[i]<=mem1[j])
                        {
                            pmb[ind]=mem1[j];
                            pmb_p[ind++]= mem1[j]  - pro[i];

                        }
                    }    
                    if(ind==0)
                        alloc[i]=-1;
                    else{
                        min_pmb=pmb[0];
                        min_pmb_p=pmb_p[0];
                        for(k=1;k<ind;k++)
                        {
                            if(min_pmb>pmb[k])             // finding the smallest value
                                min_pmb=pmb[k];
                            if(min_pmb_p>pmb_p[k])
                                min_pmb_p=pmb_p[k];
                        }
                        for(j=0;j<mb;j++)
                        {
                            if(min_pmb==mem1[j] || min_pmb_p==mem1[j])
                            {
                                mem1[j]=min_pmb_p;
                                alloc[i]=min_pmb;
                                break;
                            } 
                        }
                    }
                }
                print();
            break;
            case 5:                                      //worest fit
                copy();
                for(i=0;i<n;i++)
                {
                    flag=0;
                    for(j=0,ind=0;j<mb;j++)
                    {
                        if(pro[i]<=mem1[j])
                        {
                            pmb[ind]=mem1[j];
                            pmb_p[ind++]= mem1[j]  - pro[i];

                        }  
                    }    
                    if(ind==0)
                        alloc[i]=-1;
                    else{
                        min_pmb=pmb[0];
                        min_pmb_p=pmb_p[0];
                        for(k=1;k<ind;k++)
                        {
                            if(min_pmb<pmb[k])             // finding the biggest value
                                min_pmb=pmb[k];
                            if(min_pmb_p<pmb_p[k])
                                min_pmb_p=pmb_p[k];
                        }
                        for(j=0;j<mb;j++)
                        {
                            if(min_pmb==mem1[j] || min_pmb_p==mem1[j])
                            {
                                mem1[j]=min_pmb_p;
                                alloc[i]=min_pmb;
                                break;
                            } 
                        }
                    }
                }
                print();
                break;
            case 6:
                exit(0);
                break;
        }
    }while(1);
}