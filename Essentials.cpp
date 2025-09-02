#include<iostream> // cin , cout , ...
#include<vector> // vectors
#include<iomanip> // input/output format , boolalpha , ...
#include<cmath> // ceil , floor , ...
#include <algorithm> // beging , end , reverse , ...
#include <climits> // INT_MIN , INT_MAX , ...
#include <cctype> // for digit functions
#include <stack> // PUSH , POP , ...
#include <string> // empty() , ...
using namespace std; // Using the standard namespace

//1_ Structure

//collection of diferent data types.
/*
struct Rectangle{
    int length;
    int width;
};
struct student{
    int number;
    string name;
    char letter;
}s1={1,"khaled",'k'},s2;
int main(){
    struct Rectangle r1={11,20};
    r1.length=10;
    cout<<r1.length<<endl; // 10
    cout<<r1.length*r1.width<<endl; // 200
    cout<<s1.name<<endl; // khaled
    cout<<sizeof(s2)<<endl; // 32 -> char will take 4 bytes in structure not 1 except you print just it then it will take 1
    cout<<sizeof(s1.letter)<<endl; // 1
}
*/

               //__________________________________//

//2_ Pointer and Reference

// Pointer is address variable.  
// Pointer is using for accessing :
// 1-Heap 
// 2-Recources(external file,keyboard,...)
// 3-Parameter passing
/*
struct Rectangle{
    int length;
    int width;
};
int main(){

    // Pointer to value
    int a = 10;
    int *b = &a;
    cout<<*b<<endl; // 10
    cout<<a<<endl; // 10

    // Pointer to array
    int arr[] = {1,2,3,4,5};
    int size_arr = sizeof(arr)/sizeof(arr[0]);
    int *s;
    s = arr; // Don't write with array s=&arr;
    for(int i =0;i<size_arr;i++){
        cout<<s[i]<<" "; // 1 2 3 4 5
    }cout<<endl;
    cout<<sizeof(*s)<<endl; // 4 -> Pointer's size is 4

    // Pointer to array in heap
    int value = 3;
    int *p;
    p = new int[5]; // In C language it will be -> p = (int*)malloc(5*sizeof(int));

    for(int i = 0;i<5;i++){ // Initialize the elements of the integer array
        p[i]= value;
        value++;
    }
    for(int i = 0;i<5;i++){ // Display the elements of the dynamically allocated integer array
        cout<<p[i]<<" "; // 3 4 5 6 7 
    }cout<<endl;
    cout<<*p<<endl; // 3
    cout<<sizeof(*p)<<endl; // 4 -> Pointer's size is 4
    delete [ ] p ; // Delete the array after using it

    // Reference
    int &r = a;
    cout<<r<<endl; // 10

    // Pointer to struct
    Rectangle y = {100,200}; // NO need to write struct in c++
    Rectangle *j = &y;
    cout<<j->length<<endl; // 100

    // Pointer to struct in heap
    Rectangle *u;
    u = new Rectangle;
    u->length = 11; // or (*u).length = 11; ... We have to write pointer in only those two ways
    cout<<u->length<<endl; // 11
    delete u;
}
*/

               //__________________________________//

//3_ Functions
/*
// Add two values
int add(int num1,int num2){
    return num1 + num2;
}

// Call By Value
void callByValue(int num1,int num2){
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

// Call By Address
void callByAddress(int *num1,int *num2){
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// Call By Refference
inline void callByReference(int &num1,int &num2){
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

// Function returns array
void arr(int array[],int size){ // array[] <- is always passing by the address not by value
    
    // for(int x:array){} <- We can't use foreach loop upon a pointer 
    
    array[0] = 15; // It will change in the main function because it's a pointer
}

// Function to check the size of the array
void fun(int *array){ // = int array[]
    cout<<sizeof(array)/sizeof(int)<<endl; // size of pointer -> 4 / 4 = 1
}

// Function returns an array in heap
int *p(int size){
    int *ptr;
    ptr = new int[size];
    for(int i=0;i<size;i++){
        ptr[i] = i + 1;
    }return ptr;
}

// Call a structure
struct Rectangle{
    int length;
    int width;
};

// Passing a structure by value
int normalStruct(struct Rectangle r1){
    return r1.length*r1.width;
}

// Passing a structure by value and it's suppose that the value won't change
int structByValue(struct Rectangle r2){
    r2.length++; // ## But here the length will change because the function return int not void ##
    return r2.length*r2.width;
}

// Passing a structure by address and the value will change
int structByAddress(struct Rectangle *r3){
    r3->length++;
    return r3->length*r3->width;
}

// Creat a structure in Heap
struct Rectangle *structInHeap(){
    struct Rectangle *r4;
    r4 = new Rectangle;
    r4->length = 11;
    r4->width = 22;
    return r4;
}
int main(){
    // Add two values
    int a=1,b=2,result;
    result = add(a,b);
    cout<<result<<endl; // 3

    // Call By Value
    callByValue(a,b);
    cout<< a <<" "<< b <<endl; // 1 2

    // Call By Address
    callByAddress(&a,&b);
    cout<< a <<" "<< b <<endl; // 2 1

    // Call By Refference
    callByReference(a,b);
    cout<< a <<" "<< b <<endl; // 2 1

    // The change in the called function will affect in the main function because the array is a pointer
    int array[] = {1, 2, 3, 4, 5};
    int size = 5;
    arr(array,size);
    for(int i : array){
        cout<<i<<" "; // 15 2 3 4 5
    }
    cout<<endl;

    // The difference between the size of array as pointer and array as not a pointer
    fun(array); // 4 / 4 = 1
    cout<<sizeof(array)/sizeof(int)<<endl; // 20 / 4 = 5

    // A function which returns an array in heap
    int *ptr;
    ptr=p(size);
    for(int i=0;i<size;i++){
        cout<<ptr[i]<<" "; // 1 2 3 4 5
    }cout<<endl;
    delete []ptr;

    // Initialize structure
    struct Rectangle r = {10,22};

    // Return structure by value
    cout<<normalStruct(r)<<endl; // 220

    // Return structure by value and the value will not change
    cout<<structByValue(r)<<endl; // 242

    // Return structure by address and the value will change 
    cout<<structByAddress(&r)<<endl; // 242

    // Creat a structure in Heap
    struct Rectangle *ptr_rect =structInHeap();
    cout<< ptr_rect->length<<" "<<ptr_rect->width<<endl; // 11 22
    delete ptr_rect;
}
*/

               //__________________________________//

//4_ C Style Programming
/*
// There are several ways to write a program
// Monolithic program : you write every thing in the main function (functions,...)
// Modular program (C Style Programming): You write the important functions above the main function
// (C++ Style Programming): support oop (objects, classes, ...)


// C style programing

struct Rectangle{
    int length;
    int width;
};
void initialize(Rectangle *r,int l,int w){
        r->length = l;
        r->width = w;
}
void changeLength1(struct Rectangle r,int l){
        r.length = l; // The length won't change cuz it's calling by value
}void changeLength2(struct Rectangle *r,int l){
        r->length = l;
}
int area(struct Rectangle r){
        return r.length*r.width;
}
int main (){
    struct Rectangle r;
    initialize(&r,10,20);
    cout << area(r)<<endl; // 200
    changeLength1(r,30);
    cout << area(r)<<endl; // 200
    changeLength2(&r,30);
    cout << area(r); // 600
}
*/

               //__________________________________//

//5_ C++ Style Programming
/*
class Rectangle{

    private:
    int length;
    int width;

    public :
    // Constructor
    Rectangle(){
    length = 0;
    width = 0;
    }

    // A function accepts parameters
    Rectangle(int l,int w){
    length = l;
    width = w;
    }
    int area(){
        return length*width;
    }
    int perimeter(){
        return 2*(length+width);
    }
    void setLength(int l){
    length = l;
    }
    void setWidth(int w){
    width = w;
    }
    int getLenth(){
    return length;
    }
    int getWidth(){
    return width;
    }
    void changeLength(int l){
        length = l;
    }

    // Destractor
    ~Rectangle(){
    cout<<"The end of the program";
    }
};
int main(){
    Rectangle r(10,5); // if you don't write parameters it will take 0 and 0
    cout << r.area() << endl; // 50
    r.changeLength(30);
    cout << r.area() << endl; // 150
    return 0;
}
*/

               //__________________________________//

//6_ C++ Style Programming using templates
/*
template<class T>
class Rectangle{

    private:
    T length;
    T width;

    public:
    Rectangle(T length,T width);
    T area();
    T perimeter();
    void setLength(T l);
    void setWidth(T w);
    T getLength();
    T getWidth();
    ~Rectangle();
};

template<class T>
Rectangle<T>::Rectangle(T length,T width){
    this->length=length;
    this->width=width;
}

// Mutator Functions(Setters)
template<class T>
void Rectangle<T>::setLength(T l){
    if(l > 0){
        length = l;
    }else{
        cout << "Length cannot be less than 0";
    }
}
template<class T>
void Rectangle<T>::setWidth(T w){
    if(w > 0){
        width = w;
    }else{
        cout << "Width cannot be less than 0";
    }
}

// Accessor Functions(Getters)
template<class T>
T Rectangle<T>::getLength(){
    return length;
}
template<class T>
T Rectangle<T>::getWidth(){
    return width;
}
template<class T>
T Rectangle<T>::area(){
    return length*width;
}
template<class T>
T Rectangle<T>::perimeter(){
    return 2*(length+width);
}
// After the main function ends the destructor will be executed
template<class T>
Rectangle<T>::~Rectangle()
{
    cout << endl<<"the end of the program" << endl;
}
int main(){
    Rectangle<int>r(20,10);
    r.setLength(4); 
    cout<<r.area()<<endl; // 40
    cout<<r.perimeter(); // 28
}
*/

               //__________________________________//

//7_ Some Basics

// Each varible or function we declare in main funcion : it takes the same memory (so it's static) and allocated in the stack (that memory depends on the compiler or os or divice etc..)

// To allocate memory in heap : we must use a pointer which will be declared in the stack and after that we must delete or release that memory so it's dynamic

// There are two types of data structure : physycal like arrays and linked lists 2_ logical(which use physycal to implement) ,like Stack,Queue,Tree,Graph,Hash table

// ADT (Abstract Data Type) : is something which has the data and the operations on that data ,like class,stack,queue,etc..

// Time complexity : we must search each line, if one line -> (o(n)) / all the array -> (o(n^2)) cuz we need two loops / dividing the array by 2 -> (o(log2n))