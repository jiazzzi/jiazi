#include <stdio.h>
// 希尔排序
void shellSort(int arr[],int n)
{
    int gap,i,j,temp;
    for(gap=n/2;gap>0;gap/=2)
	{
        for(i=gap;i<n;i++)
		{
            temp=arr[i];
            for (j=i;j>=gap&&arr[j-gap]>temp;j-=gap)
			{
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
    }
}
// 快速排序
void quickSort(int arr[], int low, int high)
{
    if (low<high) {
        int key=arr[low];
        int i=low,j=high + 1,temp;
        do{
            do{
                i++;
              }while(arr[i]<key);
            do{
                j--;
              } while(arr[j]>key);
            if(i<j)
			{
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
          }while(i<j);
        temp=arr[low];
        arr[low]=arr[j];
        arr[j]=temp;
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
    }
}
// 大根堆排序
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&arr[left]>arr[largest])
	{
        largest=left;
    }
    if(right<n&&arr[right]>arr[largest])
	{
        largest=right;
    }
    if(largest!=i)
	{
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
	{
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--)
	{
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr,i,0);
    }
}
// 归并排序
void merge(int arr[],int left,int mid,int right)
{
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1], R[n2];
    for(i=0;i<n1;i++)
	{
        L[i]=arr[left+i];
    }
    for(j=0;j<n2;j++)
	{
        R[j]=arr[mid+1+j];
    }
    i=0;
    j=0;
    k=left;
    while(i<n1&&j<n2)
	{
        if(L[i]<=R[j])
		{
            arr[k]=L[i];
            i++;
        }
		else
		{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
	{
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
	{
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int left,int right)
{
    if(left<right)
	{
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
// 计数排序
void countSort(int arr[],int n)
{
    int output[n];
    int max=arr[0];
    for(int i=1;i<n;i++)
	{
        if(arr[i]>max)
		{
            max=arr[i];
        }
    }
    int count[max+1];
    for(int i=0;i<=max;i++)
	{
        count[i]=0;
    }
    for(int i=0;i<n;i++)
	{
        count[arr[i]]++;
    }
    for(int i=1;i<=max;i++)
	{
        count[i]+=count[i-1];
    }
    for(int i =n-1;i>=0;i--)
	{
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++)
	{
        arr[i]=output[i];
    }
}
int main()
{
    int arr[]={6,12,458,5,4,28,19,1230,9,47};
    int n=sizeof(arr)/sizeof(arr[0]);
    // 希尔排序
    shellSort(arr, n);
    printf("希尔排序结果：");
    for (int i=0; i<n;i++)
	{
        printf("%d ",arr[i]);
    }
    printf("\n");
    // 快速排序
    quickSort(arr,0,n-1);
    printf("快速排序结果：");
    for (int i=0;i<n;i++)
	{
        printf("%d ",arr[i]);
    }
    printf("\n");
    // 大根堆排序
    heapSort(arr, n);
    printf("大根堆排序结果：");
    for(int i=0;i<n;i++)
	{
        printf("%d ",arr[i]);
    }
    printf("\n");
    // 归并排序
    mergeSort(arr,0,n-1);
    printf("归并排序结果：");
    for (int i=0;i<n;i++)
	{
        printf("%d ",arr[i]);
    }
    printf("\n");
    // 计数排序
    countSort(arr, n);
    printf("计数排序结果：");
    for(int i=0;i<n;i++)
	{
        printf("%d ",arr[i]);
    }
    printf("\n"); 
    return 0;
}
