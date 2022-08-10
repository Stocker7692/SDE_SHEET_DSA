#include<bits/stdc++.h>
using namespace std;

class CustomStack {
    public:
    int arr[1000];
    int count = 0;
    int size = 0;
    

    public:
    CustomStack(){
        size=5;
    }

    CustomStack(int maxSize){
        size=maxSize;
    }

    void push(int x){
        if(count<size){
            arr[count++]=x;
        }
    }

    int pop(){
        if(count>0){
            return arr[--count];
        }
        return -1;
    }

    int top(){
        if(count>0) return arr[count-1];
        return -1;
    }

    void increment(int k,int val){
        for(int i=0;i<min(k,count);i++){
            arr[i]=arr[i]+val;
        }
    }

};

int main(){

    CustomStack st;
    st.push(10);
    st.push(20);
    cout<<st.top()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.top()<<endl;


}