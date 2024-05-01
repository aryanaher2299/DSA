//Binary Search
// Best Case O(1), Average and worst is: O(logN)
// [54, 76, 89, 92, 126]
// Binary search only works on sorted arrays like the one above
// We take the low as 0 and high as size of array and calculate mid by taking max of (high+low)/2
// Then if the element we are searching is lesser than the mid then we set the high as mid and carry forward.
// If its greater then we make mid as the new low.


#include<iostream>
#include<stdio.h>
using namespace std;


string iterativeBinarySearch(int myArray[5], int size, int element){
    int low = 0;
    int high = size-1;
    int mid = 0;

    while(low <= high){

        //mid = (low+(high-low))/2;   We can do this line if we dont do high = mid -1 or low = mid +1, because we are taking the higher floor value hence updating mid acordingly by +-1.
        mid = (low+high)/2;

        if(element == myArray[mid]){
                return "match";
                break;
            }
        else if(element<myArray[mid]){
                high = mid -1;
            }
        else{
                low = mid+1;
            }
    }
    return "Not found!!!!";
    
}

void displayArray(int myArray[5], int size){
    for(int i=0; i<size; i++){
        cout<<myArray[i]<<endl;
    }
}

//Recursive Binary Search
string recursiveBinarySearch(int myArray[5], int low, int high, int element){
    int mid = 0;

    while(low<=high){
        mid = (low+high)/2;

        if(element==myArray[mid]){
            return "Match";
            break;
        }
        else if(element<myArray[mid]){
            high = mid - 1;
            recursiveBinarySearch(myArray, low, high, element);
        }
        else{
            low = mid +1 ;
            recursiveBinarySearch(myArray, low, high, element);
        }
    }
    return "Not Found!!!";
}

int main(){
    
    int myArray[5] = {54, 76, 89, 92, 126};
    int n = sizeof(myArray)/sizeof(myArray[0]);
   // displayArray(myArray, 5);
    //cout<<iterativeBinarySearch(myArray, n, 92);
    cout<<recursiveBinarySearch(myArray, 0, n-1, 54);

    return 0;
}