#include <string>
#include "StackType.h"
#include "QueType.h"

std::string decode(std::string exp, std::string code) {
    QueType<char> normalQueue;   
    StackType<char> codeStack;  
    for (int i = 0; i < static_cast<int>(exp.length()); i++) {
        char ch = exp.at(i);
        if (code.find(ch) == std::string::npos) {
            normalQueue.Enqueue(ch);
        } else {
            codeStack.Push(ch);
        }
    }

    std::string output = "";
    while (!normalQueue.IsEmpty()) {
        char ch;
        normalQueue.Dequeue(ch);
        output += ch;
    }
    while (!codeStack.IsEmpty()) {
        char ch = codeStack.Pop();
        output += ch;
    }

    return output;
}
