//tracks the current minEl of the stack
int minEl = -1;

//Sufficiently large multiplier to encode every element in the stack
int mod = 10001;
void push(stack<int>& s, int a){
	//Encoded element is pushed onto the stack
	//(Stack_value / mod) = original_element and (Stack_value % mod) = nextMinElement
	s.push(a * mod + minEl);
	if(s.size() == 1 || a <= minEl) minEl = a;
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return s.size() == n;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return s.empty();
}

int pop(stack<int>& s){
	// Your code goes here
	int ret = s.top();
	s.pop();

	//if stack is empty assign minEl to -1
	if(s.empty()) minEl = -1;

	//else minEl = nextMinElement decoded using (stack_value % mod)
	else minEl = ret % mod;
	
	return ret / mod;
}

int getMin(stack<int>& s){
	// Your code goes here
	return minEl;
}