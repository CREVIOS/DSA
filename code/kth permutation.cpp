#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    //function to generate all possible permutations of a string
    void permutationHelper(string & s, int index, vector < string > & res) {
      if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        permutationHelper(s, index + 1, res);
        swap(s[i], s[index]);
      }
    }

  string getPermutation(int n, int k) {
    string s;
    vector < string > res;
    //create string
    for (int i = 1; i <= n; i++) {
      s.push_back(i + '0');
    }
    permutationHelper(s, 0, res);
    //sort the generated permutations
    sort(res.begin(), res.end());
    //make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;
  }
};

int main() {
  int n = 3, k = 3;
  Solution obj;
  string ans = obj.getPermutation(n, k);
  cout << "The Kth permutation sequence is " << ans << endl;

  return 0;
}


/*
#include <algorithm>
#include <iostream>
#include <vector>

std::string findKthPermutation(std::vector<int>& sequence, int k) {
    // Ensure the sequence is in the first permutation
    std::sort(sequence.begin(), sequence.end());

    // Apply next_permutation k-1 times to reach the kth permutation
    for (int i = 0; i < k - 1; ++i) {
        std::next_permutation(sequence.begin(), sequence.end());
    }

    // Convert sequence to a string or any other format if needed
    std::string result = "";
    for (int num : sequence) {
        result += std::to_string(num);
    }

    return result;
}

int main() {
    std::vector<int> sequence = {1, 2, 3};
    int k = 3; // Change this to the kth permutation you want to find
    std::string kthPermutation = findKthPermutation(sequence, k);
    std::cout << "The " << k << "th permutation is: " << kthPermutation << std::endl;
    return 0;
}

*/

/*

class Solution {
public:  
  void generate_combination( int id, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
    if(id==arr.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    if(arr[id]<= target){
        ds.push_back(arr[id]);
        generate_combination(id,target-arr[id],arr,ans,ds);
        ds.pop_back();

    }
      generate_combination(id+1,target,arr,ans,ds);
   }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        generate_combination(0,target,candidates,ans,ds);
        return ans;
    }
};




class Solution {
public:
    void generate_ans(int id, int target, vector<int>&arr, vector<vector<int>>&ans, vector<int>&ds){

        if(target==0){
        ans.push_back(ds);
        return;
    }
     for(int i = id; i < arr.size();i++){
        if(i>id && arr[i]==arr[i-1]) continue;
        if(arr[i]>target ) break;
        ds.push_back(arr[i]);
        generate_ans(i+1,target-arr[i],arr,ans,ds);
        ds.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        generate_ans(0,target,candidates,ans,ds);
        return ans;
    }
};

*/