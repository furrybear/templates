int partition(int a[], int start,int end)
{
    int i,j,x;
    x=a[start];
    i=start;
    j=end;
    while(i<j){
        while((a[j]>x)&&i<j) j--;
        if(i<j) a[i++]=a[j];
        while((a[i]<=x)&&i<j) i++;
        if(i<j) a[j--]=a[i];
    }
    a[i]=x;
    return i;
}

void quickSort(int *a, int start, int end){
    if (start >= end)
        return;
    int mid = partition(a, start, end);
    quickSort(a, start, mid-1);
    quickSort(a, mid+1, end);
}
