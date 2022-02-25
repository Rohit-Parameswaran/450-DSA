class NStack
{
    vector<int> arr;
    vector<int> next;
    vector<int> top;
	int free, n, size;    

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        n = N;
        size = S;
        arr = vector<int> (size);
        next = vector<int> (size);
        for(int i=0;i<size;++i)
            next[i] = i+1;
        top = vector<int> (n+1, size);
        free = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if(free == size) return false;
        int curpos = free;
        arr[curpos] = x;
        free = next[curpos];
        next[curpos] = top[m];
        top[m] = curpos;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if(top[m] == size) return -1;
        int curpos = top[m];
        top[m] = next[curpos];
        next[curpos] = free;
        free = curpos;
        return arr[curpos];
    }
};
