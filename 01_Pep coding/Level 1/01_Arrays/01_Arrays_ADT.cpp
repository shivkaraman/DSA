
#include <iostream>
using namespace std;
class myArray{
        int total_size;
        int used_size;
        int *arr;
    public : 
        myArray (int tsize, int usize);
        void  set();
        int  insert(int value, int index);
        int  Delete(int index);
        void  show();
};

myArray :: myArray (int tsize, int usize){
    total_size = tsize;
    used_size = usize;
    arr = new int [total_size];
}

void myArray :: set(){                                      //Set array
    cout<<"Enter array "<<used_size<<"elements : ";
    for(int i=0;i<used_size;i++){
        cin>>arr[i];
    }
}

int myArray :: insert(int value, int index){                //Array insertion
    if(index>=total_size-1) 
        return 0;
    
    for(int i=used_size-1;i>=index;i--)
        arr[i+1]=arr[i];

    arr[index]=value;
    used_size++;
    return 1;
}

int myArray :: Delete(int index){                           //Array deletion
    if(index>=total_size-1) 
        return 0;

    for(int i = index; i<used_size-1;i++)
        arr[i]=arr[i+1];

    used_size--;
    return 1;
}

void myArray :: show(){                                     //Display array
    for(int i=0;i<used_size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){                                                 //Main function
    int capacity, size, value, index;
    
    cout<<"Enter capacity and size : ";
    cin>>capacity>>size;

    myArray arr(capacity,size);
    arr.set();
    cout<<"Array : "; arr.show();

    cout<<"Enter element to be inserted and index : ";
    cin>>value>>index;

    bool flag = arr.insert(value, index);

    if(flag){
        cout<<"Elemement inserted successfully"<<endl;
        size++;
        cout<<"Array : "; arr.show();
    }

    else    
        cout<<"Array insertion FAILED"<<endl;

    cout<<"Enter index at which element is to be deleted : ";
    cin>>index;

    flag=arr.Delete(index);
    if(flag){
        cout<<"Elemement deleted successfully"<<endl;
        size--;
        cout<<"Array : "; arr.show();
    }

    else    
        cout<<"Array insertion FAILED"<<endl;

    return 0;
}