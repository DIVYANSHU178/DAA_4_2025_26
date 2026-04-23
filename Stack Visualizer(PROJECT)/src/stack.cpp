#include <emscripten.h>
#include <iostream>
#include <string>
#include <sstream>

class Stack {
private:
    int* data;
    int top;
    int maxSize;

public:
    Stack(int size) {
        maxSize = size;
        data = new int[maxSize];
        top = -1;
    }

    ~Stack() {
        delete[] data;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == maxSize - 1;
    }

    void push(int val) {
        if (isFull()) {
            std::cout << "Stack Overflow!" << std::endl;
            return;
        }
        data[++top] = val;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow!" << std::endl;
            return -1; // error code
        }
        return data[top--];
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        return data[top];
    }

    std::string getStackAsString() {
        if (isEmpty()) {
            return ""; 
 }
 std::stringstream ss;
 for (int i = 0; i <= top; ++i) {
 if (i > 0) ss << ",";
 ss << data[i];
 }
 return ss.str();
 }
};

// Global stack instance
Stack* stack = nullptr;

extern "C" {

EMSCRIPTEN_KEEPALIVE
void initStack(int size) {
 if (stack) delete stack;
 stack = new Stack(size);
}

EMSCRIPTEN_KEEPALIVE
bool isEmpty() {
 return stack ? stack->isEmpty() : true;
}

EMSCRIPTEN_KEEPALIVE
bool isFull() {
 return stack ? stack->isFull() : false;
}

EMSCRIPTEN_KEEPALIVE
void push(int val) {
 if (stack) stack->push(val);
}

EMSCRIPTEN_KEEPALIVE
int pop() {
 return stack ? stack->pop() : -1;
}

EMSCRIPTEN_KEEPALIVE
int peek() {
 return stack ? stack->peek() : -1;
}

EMSCRIPTEN_KEEPALIVE
const char* getStack() {
 static std::string str;
 str = stack ? stack->getStackAsString() : ""; 
    return str.c_str();
}

}
