class MyStack {  
    
    queue<int> q1, q2;
    
public:
    
    void push(int x) {
           
        if(q1.empty()) {
            
            q2.push(x);
        } else {
            
            q1.push(x);
        }
    }
    
    int pop() {
        
        if(q1.empty()) {
            
            while(!q2.empty()) {
                
                if(q2.size() == 1) {
                    
                    int top = q2.front();
                    q2.pop();
                    return top;
                } else {
                    
                    q1.push(q2.front());
                    q2.pop();
                }
                
            }
        } else {
            
            while(!q1.empty()) {
                
                if(q1.size() == 1) {
                    
                    int top = q1.front();
                    q1.pop();
                    return top;
                } else {
                    
                    q2.push(q1.front());
                    q1.pop();
                }
                
            }
        }
        
        return -1;
    }
    
    int top() {
        
        int top = this->pop();
        
        if(q1.empty()) {
            
            q2.push(top);
        } else {
            
            q1.push(top);
        }
        
        return top;
    }
    
    bool empty() {
        
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */