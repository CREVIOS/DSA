
/*

int missingK(vector < int > vec, int n, int k) {
int low = 0, high = n-1;
while(low<=high){
    int mid = (high+low)/2;
    int element = vec[mid] - (mid+1);
    if(element<k){
        low = mid + 1;
    }
    else{
        high = mid - 1;
    }
}
return k + high + 1;
}


*/


/*
// search in rotated array

int search(vector<int>& arr, int n, int k)
{
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==k) return mid;
        if(arr[low] <= arr[mid]){
            if(arr[low]<=k && k <= arr[mid]){
                high = mid -1;
            }
            else{
                low = mid  + 1;
            }
        }
        else{
            
            if(arr[mid]<=k && k <= arr[high]){
                low = mid +1;
            }
            else{
                high = mid  - 1;
            }
        
        }
    }
    return -1;
}



*/