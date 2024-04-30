#include<stdio.h>
#include<iostream>
using namespace std;

class myArray{
    private:
    int totalSize;
    int usedSize;
    int* ptr;

    public:
    myArray(int givenSize){
        totalSize = givenSize;
        ptr = new int[totalSize];
        for(int i = 0; i< totalSize; i++){
            ptr[i] = 0;
        }
    };

    int getsize();
    void insert(int index, int num);
    void displayArray();
    int getValueatIndex(int index);
    int searchIndexofValue(int value);

    void deleteByIndex(int index){
        ptr[index] = 0;
    }

    void deleteByValue(int value){
        int index = this->searchIndexofValue(value);
        ptr[index] = 0;
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
    newArray.insert(3, 20);
    newArray.insert(0, 10);
    newArray.insert(2, 190);
    newArray.insert(1, 90);
    //newArray.displayArray();
    
    newArray.displayArray();
    cout<<endl;
    newArray.deleteByIndex(2);
    cout<<newArray.getValueatIndex(2)<<endl;

    newArray.deleteByValue(20);
    cout<<newArray.getValueatIndex(3)<<endl;

    newArray.displayArray();
    //cout<<newArray.getValueatIndex(3)<<endl;
    //cout<<newArray.searchIndexofValue(20);

    
    return 0;
    
}