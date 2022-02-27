// 1.Push the first half elements of queue to stack.
// 2.Enqueue back the stack elements.
// 3.Dequeue the first half elements of the queue and enqueue them back.
// 4.Again push the first half elements into the stack.
// 5.Interleave the elements of queue and stack.

void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    stack<int> s;
    int n = q.size();
    for(int i=0;i<n/2;++i) {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    for(int i=0;i<n/2;++i) {
        q.push(q.front());
        q.pop();
    }
    for(int i=0;i<n/2;++i) {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}