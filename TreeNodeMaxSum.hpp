//
//  TreeNode.hpp
//  Algorithms
//
//  Created by Xiaorui Zhao on 3/25/16.
//  Copyright © 2016 Xiaorui Zhao. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>

#include <unordered_map>
#include <vector>
#include <map>
#include <unordered_set>
#include <iostream>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v=0, TreeNode*l = nullptr, TreeNode*r = nullptr):val(v),left(l), right(r){}
    
};


class Solution{
    //sum occurrence
    unordered_map<long, long> mp;
    //occurrence     sums
    map<long, unordered_set<long>, greater<long>> mp1;
public:
    int findSum(TreeNode* root){
        if(!root) return 0;
        
        int sum = root->val + findSum(root->left) + findSum(root->right);

        mp[sum]++;
        
        return sum;
    }
    void printTopK(int k){
        //count the occurrence to each sum
        for( auto it =mp.begin(); it!=mp.end(); it++){
            mp1[it->second].insert(it->first);
        }
        //print the top k elements using the new DS
        for(auto it= mp1.begin(); it!=mp1.end(); it++){
            cout<<it->first<<" ";
            for(auto it2=(it->second).begin(); it2!=it->second.end(); it2++)
                cout<<*it2<<" ";
            cout<<endl;
            --k;
            if(k==0) return;
        }
    
    }
};

void test(){
    TreeNode* root= new TreeNode(-9);
    TreeNode* n11 = new TreeNode(2);
    TreeNode* n12 = new TreeNode(1);
    TreeNode* n21 = new TreeNode(3);
    TreeNode* n22 = new TreeNode(3);
    TreeNode* n23 = new TreeNode(3);
    TreeNode* n24 = new TreeNode(1);
    
    root->left = n11;
    root->right = n12;
    n11->left = n21;
    n11->right = n22;
    n12->left = n23;
    n12->right = n24;
    
    Solution s;
    int result = s.findSum(root);
    s.printTopK(1);

}

//       -9
//     2      1
//   3   3  1   1

#endif /* TreeNode_hpp */
