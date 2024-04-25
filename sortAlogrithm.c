#include<stdlib.h>
#include<stdio.h>

int test_data[9]={4,5,6,7,7,8,1,2,3};
void selectSort(int*,int); // Declare the function prototype

int main(){
    selectSort(&test_data[0],9);
    for(int i=0;i<9;i++)
    {
        printf("%d ",test_data[i]);
    }
    return 0;
}
void selectSort(int* data,int n)
{
    for(int i=0;i<n;i++)
    {
        int min_index=i;
        for(int j=i;j<n;j++)
        {
            if(*(data+j)<*(data+min_index))
                min_index=j;
        }
        int tmp=*(data+min_index);
        *(data+min_index)=*(data+i);
        *(data+i)=tmp;
    }
}
// void selectSort(int* data,int n)
// {
//     for (int i=0;i<n;i++)
//     {
//         int min_index=i;
//         for(int j=i;j<n;j++)
//         {
//             if(data[j]<data[min_index])
//             min_index=j;
//         }
//         int tmp=data[min_index];
//         data[min_index]=data[i];
//         data[i]=tmp;
//     }
// }

