#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    bool static comp(Item a,Item b){
        double x = (double)a.value/(double)a.weight;
        double y = (double)b.value/(double)b.weight;
        return x>y;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comp);
        int curWeight =0;
        double finalValue=0.0;
        
        
        for(int i=0;i<n;i++){
            if(curWeight+arr[i].weight<W){
                curWeight +=arr[i].weight;
                finalValue += arr[i].value;
            }
            else{
                int remain = W-curWeight;
                finalValue +=((arr[i].value)/(double)arr[i].weight)*(double)remain;
                break;
            }
            
        }
        return finalValue;
    }
        
};