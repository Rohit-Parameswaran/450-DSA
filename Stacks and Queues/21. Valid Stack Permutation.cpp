bool validStackPermutation(vector<int> &arr, vector<int> &target){
	// Write your code here.
    int i=0, j=0, n=arr.size();
    stack<int> s;
    while(i<n) {
        //insert current element into the stack
        s.push(arr[i]);
        //keep popping from the stack as long as it matches with the corresponding target character
        while(j < n && !s.empty() && s.top() == target[j]) {
            ++j;
            s.pop();
        }
        ++i;
    }
    //if stack is not empty after executing while loop
    //it means that all the array elements weren't matched 
    //and the stack permutation is not valid
    return s.empty();
}