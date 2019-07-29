#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;


bool bucket(int item,vector<int> A,bool used[],int k,int current_bucket_value,int target_bucket_value){
	if(k == 1){
		return true;
	}
	if(current_bucket_value == target_bucket_value){
		return bucket(0,A,used,k-1,0,target_bucket_value);
	}
	
	for(int i = item ; i < A.size() ; i++){
		if(!used[i] && current_bucket_value + A[i] <= target_bucket_value){
			used[i] = true;
			if(bucket(i+1,A,used,k,current_bucket_value + A[i],target_bucket_value)){
				return true;
			}
			else{
				used[i] = false;
			}
		}
	}
	return false;
}


int partition3(vector<int> A){
	int sum = 0; 
    int i, j; 
    
    // Caculcate sun of all elements 
    for (i = 0; i < A.size(); i++) 
      sum += A[i]; 
      
    if (sum%3 != 0)   
       return 0;
    else{
    	bool ans = bucket(0,A, new bool[A.size()],3, 0,sum/3);
    	if(ans == true){
    		return 1;
		}
		else{
			return 0;
		}
	}
	    
}


int main(){
   int n;
   std::cin >> n;
   vector<int> A;
   for (int i = 0; i < n; i++) {
  	  int k;
      std::cin >> k;
      A.push_back(k);
  	}
  	std::cout << partition3(A) << '\n';
}
