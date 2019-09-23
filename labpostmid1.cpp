#include<bits/stdc++.h>
using namespace std;

//utitlities

int findMedian(int arr[], int n) 
{ 
    sort(arr, arr+n);  
    return arr[n/2];   
} 

void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  

int partition(int arr[], int l, int r, int x) 
{ 
    
    int i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
  
    
    i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 

int kthSmallest(int arr[], int l, int r, int k) 
{ 
    
    if (k > 0 && k <= r - l + 1) 
    { 
        int n = r-l+1; 
  
        
        int i, median[(n+4)/5];
        for (i=0; i<n/5; i++) 
            median[i] = findMedian(arr+l+i*5, 5); 
        if (i*5 < n) 
        { 
            median[i] = findMedian(arr+l+i*5, n%5);  
            i++; 
        }     
  
        
        int medOfMed = (i == 1)? median[i-1] : kthSmallest(median, 0, i-1, i/2); 
  
 
        int pos = partition(arr, l, r, medOfMed); 
  
        // If position is same as k 
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  // If position is more, recur for left 
            return kthSmallest(arr, l, pos-1, k); 
  
        // Else recur for right subarray 
        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
  
    
    return INT_MAX; 
} 

int main(){

	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int x,y, arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>x>>y;
			arr[i]=(x*x + y*y);

		}
		int r=kthSmallest(arr,0,n-1, n/2);
		cout<<pow(r,0.5)<<endl;

	}
	return 0;
}

