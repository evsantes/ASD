#ifndef STACK_H
#define STACK_H

bool check_brackets(string str) {
    Stack<char> brackets_stack;

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];

        if (c == '(' || c == '[' || c == '{') {
            brackets_stack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            //если в стеке пусто, то ошибка
            if (brackets_stack.empty()) {
                return false;
            }

            char top = brackets_stack.top();

            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                brackets_stack.pop();
            }
            else {
                return false;
            }
        }
    }

    //если в стеке пусто, то все в норме
    return brackets_stack.empty();
}

#endif