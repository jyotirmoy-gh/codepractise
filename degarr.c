#include <malloc.h>

int findShortestSubArray(int* nums, int numsSize){

    int i,j;
    int c=0,ct;
    int *n;
    int *p1=(int*)malloc(numsSize*sizeof(int));
    int *p2=(int*)malloc(numsSize*sizeof(int));
    int pt1,pt2;
    int l=0;
    int max=nums[0];
    for (i=1;i<numsSize;i++)
    {
        if(max<=nums[i])
        {
            max=nums[i];
        }
    }
    max++;
    n=(int*)calloc(max,sizeof(int));
    for (i=0;i<numsSize;i++)
    {
        if(n[nums[i]]==0)
        {
            n[nums[i]]=1;
            ct=1;
            for (j=i;j<numsSize;j++)
            {
                pt1=i;
                if(nums[j]==nums[i])
                {
                    ct++;
                    pt2=j;
                }
            }
            if(c<ct)
            {
                c=ct;
                l=0;
                p1[l]=pt1;
                p2[l]=pt2;
            }
            else if(c==ct)
            {
                l++;
                p1[l]=pt1;
                p2[l]=pt2;
            }
        }
    }
    ct=numsSize;
    for (i=0;i<=l;i++)
    {
        j=p2[i]-p1[i]+1;
        if(ct>=j)
        {
            ct=j;
        }
    }
    return ct;
}
