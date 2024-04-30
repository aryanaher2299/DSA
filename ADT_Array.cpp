#include<stdio.h>
#include<iostream>
using namespace std;


//Creating a class of my Array with the following parameters
class myArray{
    private:
    int totalSize;
    int usedSize;
    int* ptr;

//Constructor and defining some methods
    public:
    myArray(int givenSize){
        totalSize = givenSize;
        ptr = new int[totalSize];
        for(int i = 0; i< totalSize; i++){
            ptr[i] = 0;
        }
    };

//getSize() returns the total size of the array
    int getsize();

//insert() adds the element at the given index 
    void insert(int index, int num);

//displayArray() displays the entire array elements
    void displayArray();

//getValueatIndex returns the value at given index
    int getValueatIndex(int index);

//searchIndexofValue() returns value of index for given value
    int searchIndexofValue(int value);

//deleteByIndex() deletes the value at given index
    void deleteByIndex(int index){
        ptr[index] = 0;
        this->adjustArray(index);
    }

//deleteByValue deletes the element by searching its index and deleting the given element value
    void deleteByValue(int value){
        int index = this->searchIndexofValue(value);
        ptr[index] = 0;
        this->adjustArray(index);
    }

//adjustArray() adjusts the ith deleted element spot by shifting elements to fill ith position.
    void adjustArray(int index){
        for(int i=index; i<totalSize-1; i++){
            ptr[i] = ptr[i+1];
        }
        this->insert(totalSize-1, 0);
    }

};


int myArray :: getsize(){
    return totalSize;
}

void myArray :: insert(int index, int num){
    ptr[index] = num;
}

int myArray :: getValueatIndex(int index){
    return ptr[index];
}

void myArray :: displayArray(){
    for(int i = 0; i< totalSize; i++){
            cout<<ptr[i]<<endl;
        }
}

int myArray :: searchIndexofValue(int value){
    for(int i = 0; i<totalSize; i++){
        if(ptr[i] == value){
            return i;
        }
    }
    return -1;
}


int main(){

    myArray newArray(4);
    newArray.insert(0, 10);
    newArray.insert(1, 90);
    newArray.insert(2, 190);
    newArray.insert(3, 20);
    //newArray.displayArray();
    
    newArray.displayArray();
    cout<<endl;
    newArray.deleteByIndex(2);
   // cout<<newArray.getValueatIndex(2)<<endl;

    //newArray.deleteByValue(20);
    //cout<<newArray.getValueatIndex(3)<<endl;

    newArray.displayArray();
    //cout<<newArray.getValueatIndex(3)<<endl;
    //cout<<newArray.searchIndexofValue(20);
    
    return 0;
    
}