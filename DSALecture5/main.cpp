//
//  main.cpp
//  DSALecture5
//
//  Created by Laura Walsh on 09/02/2019.
//  Copyright © 2019 Laura Walsh. All rights reserved.
//

#include <iostream>
using namespace std;
#include <time.h>
#include <unistd.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include "treeNode.h"



int linearSearch(vector<int>& A, int N, int Key)
{
    int i=0;
    while((i<N) && (A[i]!=Key)){
        usleep(1000);
         i++;
    }
   if (i<=N && A[i] == Key) return i;
    return -1;
}

int linearSearchSorted(vector<int>& A, int N, int Key)
{
    int i=0;
    while((i<N) && (A[i]<Key)){
        usleep(1000);
        i++;
    }
    if (i<=N && A[i] == Key) return i;
    return -1;
}

TreeNode<int>* sortedArray2BST(vector<int>& A, int start, int end)
{
    if (start>end) return NULL;
    
    int mid = (start + end)/2;
    TreeNode<int>* root = new TreeNode<int>(A[mid]);
    
    root->left = sortedArray2BST(A, start, mid - 1);
    
    root->right = sortedArray2BST(A, mid + 1, end);
    
    return root;
}

// print in-order traversal of a BST
void printTree(TreeNode<int>* tree)
{
    if (tree == NULL)
        return;
    printTree(tree->left);
    cout << tree->item << " ";
    printTree(tree->right);
}

//binary search
bool binarySearch(TreeNode<int>* bst, int Key){
    if(bst == NULL) return 0;
    
    usleep(1000);
    
    if(bst->item == Key) return 1;
    else if(Key<bst->item)
        return binarySearch(bst->left, Key);
    else
        return binarySearch(bst->right, Key);
}




int main1(){
    
    cout << "Array size example.  N = ";
    int N = 0;
    cin >> N;
    
    // create array, populated with random numbers
    vector<int> A;
    for (int i = 0; i < N; i++) A.push_back(rand() % 1000000);
    int key = A[N / 2];    // a random key
    
    cout << "Random array: " << endl;
    for(int i = 0; i<N; i++) cout<< A[i] << ", ";
    
    cout << endl << "Key being searched for: " << key << endl;
    
    // linear search of unsorted array
    clock_t begin = clock();
    cout << linearSearch(A, N, key) << endl;
    clock_t end = clock();
    
    double elapsed = end - begin;
    cout << "Time taken to search unsorted " << N << " values = " << elapsed << " ms = "
    << elapsed / 1000.0 << " s" << endl << endl;
    
    
    vector<int> B = {1,4,67,83,90,101,120,122,150,199};
    
    clock_t begin2 = clock();
    cout << linearSearchSorted(B, N, 199) << endl;
    clock_t end2 = clock();
    double elapsed2 = end2 - begin2;
    cout << "Time taken to search 10 sorted values = " << elapsed2 << " ms = "
    << elapsed2 / 1000.0 << " s" << endl << endl;
    
    return 0;
}

int main(){
    
    
    cout << "Array size example.  N = ";
    int N = 0;
    cin >> N;
    
    // create array, populated with random numbers
    vector<int> A;
    for (int i = 0; i < N; i++) A.push_back(rand() % 1000000);
   int key = A[N / 2];    // a random key
    
    sort(A.begin(), A.end());
    
    cout << "Tree 1" << endl;
    TreeNode<int>* bst= sortedArray2BST(A, 0, N);
    printTree(bst);
    
    cout << endl << endl << "Tree 2" << endl;
    
    TreeNode<int>* bst2= sortedArray2BST(A, 0, N-1);
    printTree(bst2);
    
    cout << endl <<"Is key found in tree: ";
    
    clock_t begin = clock();
    cout << binarySearch(bst2, key) << endl;
    clock_t end = clock();
    
    double elapsed = end - begin;
    cout << "Time taken to binary search " << N << " values = " << elapsed << " ms = "
    << elapsed / 1000.0 << " s" << endl;

    
    
    
    
    
    return 0;
}
