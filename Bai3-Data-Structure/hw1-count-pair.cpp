//1.	Given a list A of n integer numbers, your task is to write a program to count the number of pairs (i,j) that A[i]=A[j].
//Input: 
//−	The first line contains an integer number n 
//−	The second line contains n integer numbers separated by spaces.   

//Output:  Write to the screen an integer number (i.e., the number of pairs (i,j) that A[i]=A[j])
//Example
//Keyboard	   | Screen
//------------------------
//6            | 4
//5 2 4 2 2 5  |	

#include <iostream>
#include <iterator>
#include <unordered_map>
using namespace std;

int countPair(int* arr, int n) {
    unordered_map<int,int> m;
    for(int i = 0; i < n; i++)
    {
        m[arr[i]] += 1;
    }
     
    int count = 0;
    for(unordered_map<int,int>::iterator it=m.begin();it!=m.end();it++)
    {
        count+=(it->second)*((it->second-1))/2;
    }
     
    return count;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    cout << countPair(arr, n);
    return 0;
}