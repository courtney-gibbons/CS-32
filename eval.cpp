#include <iostream>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

int evaluate(string infix, string& postfix, bool& result) {
    if (infix == "") {
        return 1;
    }
    
    for (size_t i = 0; i < infix.size(); i++) {
        if (infix.at(i) != ' ') {
            break;
        } else {
            if (i == infix.size()-1) {
                return 1;
            }
        }
    }
    
    int openCount = 0;
    int closedCount = 0;
    
    for (size_t i = 0; i < infix.size(); i++) {
        switch (infix.at(i)) {
            case 'T':
                if (i > 0) {
                    if (infix.at(i-1) == 'T' || infix.at(i-1) == 'F' || infix.at(i-1) == ')') {
                        return 1;
                    }
                }
                if (i < infix.size()-1) {
                    if (infix.at(i+1) == 'T' || infix.at(i+1) == 'F' || infix.at(i+1) == '!' || infix.at(i+1) == '(') {
                        return 1;
                    }
                }
                if (i > 0) {
                    if (infix.at(i-1) == ' ') {
                        for (size_t j = i-1; j > 0; j--) {
                                if (infix.at(j-1) != ' ') {
                                    if (infix.at(j) == 'T' || infix.at(j) == 'F' || infix.at(j) == ')') {
                                        return 1;
                                    }
                                    break;
                                }
                        }
                    }
                }
                if (i < infix.size()-1) {
                    if (infix.at(i+1) == ' ') {
                        for (size_t j = i+1; j < infix.size(); j++) {
                            if (infix.at(j) != ' ') {
                                if (infix.at(j) == 'T' || infix.at(j) == 'F' || infix.at(j) == '!' || infix.at(j) == '(') {
                                    return 1;
                                }
                                break;
                            }
                        }
                    }
                }
                break;
            case 'F':
                if (i > 0) {
                    if (infix.at(i-1) == 'T' || infix.at(i-1) == 'F' || infix.at(i-1) == ')') {
                        return 1;
                    }
                }
                if (i < infix.size()-1) {
                    if (infix.at(i+1) == 'T' || infix.at(i+1) == 'F' || infix.at(i+1) == '!' || infix.at(i+1) == '(') {
                        return 1;
                    }
                }
                if (i > 0) {
                    if (infix.at(i-1) == ' ') {
                        for (size_t j = i-1; j > 0; j--) {
                            if (infix.at(j) != ' ') {
                                if (infix.at(j) == 'T' || infix.at(j) == 'F' || infix.at(j) == ')') {
                                    return 1;
                                }
                                break;
                            }
                        }
                    }
                }
                if (i < infix.size()-1) {
                    if (infix.at(i+1) == ' ') {
                        for (size_t j = i+1; j < infix.size(); j++) {
                            if (infix.at(j) != ' ') {
                                if (infix.at(j) == 'T' || infix.at(j) == 'F' || infix.at(j) == '!' || infix.at(j) == '(') {
                                    return 1;
                                }
                                break;
                            }
                        }
                    }
                }
                break;
            case '!':
                if (i == infix.size()-1) {
                    return 1;
                }
                if (i > 0) {
                    if (infix.at(i-1) == 'T' || infix.at(i-1) == 'F' || infix.at(i-1) == ')') {
                        return 1;
                    }
                }
                if (i < infix.size()-1) {
                    if (infix.at(i+1) == '&' || infix.at(i+1) == '^' || infix.at(i+1) == ')') {
                        return 1;
                    }
                }
                if (i > 0) {
                    if (infix.at(i-1) == ' ') {
                        for (size_t j = i-1; j > 0; j--) {
                            if (infix.at(j) != ' ') {
                                if (infix.at(j) == 'T' || infix.at(j) == 'F' || infix.at(j) == ')') {
                                    return 1;
                                }
                                break;
                            }
                        }
                    }
                }
                if (i < infix.size()-1) {
                    if (infix.at(i+1) == ' ') {
                        for (size_t j = i+1; j < infix.size(); j++) {
                            if (infix.at(j) != ' ') {
                                if (infix.at(j) == '&' || infix.at(j) == '^' || infix.at(j) == ')') {
                                    return 1;
                                }
                                break;
                            }
                        }
                    }
                }
                break;
            case '&':
                if (i == 0) {
                    return 1;
                }
                if (i == infix.size()-1) {
                    return 1;
                }
                if (i > 0) {
                    if (infix.at(i-1) == '!' || infix.at(i-1) == '&' || infix.at(i-1) == '^' || infix.at(i-1) == '(') {
                        return 1;
                    }
                }
                if (i < infix.size()-1) {
                    if (infix.at(i+1) == '&' || infix.at(i+1) == '^' || infix.at(i+1) == ')') {
                        return 1;
                    }
                }
                if (i > 0) {
                    if (infix.at(i-1) == ' ') {
                        for (size_t j = i-1; j > 0; j--) {
                            if (infix.at(j) != ' ') {
                                if (infix.at(j) == '!' || infix.at(j) == '&' || infix.at(j) == '^' || infix.at(j) == '(') {
                                    return 1;
                                }
                                break;
                            }
                        }
                    }
                }
                if (i < infix.size()-1) {
                    if (infix.at(i+1) == ' ') {
                        for (size_t j = i+1; j < infix.size(); j++) {
                            if (infix.at(j) != ' ') {
                                if (infix.at(j) == '&' || infix.at(j) == '^' || infix.at(j) == ')') {
                                    return 1;
                                }
                                break;
                            }
                        }
                    }
                }
                break;
            case '^':
                if (i == 0) {
                    return 1;
                }
                if (i == infix.size()-1) {
                    return 1;
                }
                if (i > 0) {
                    if (infix.at(i-1) == '!' || infix.at(i-1) == '&' || infix.at(i-1) == '^' || infix.at(i-1) == '(') {
                        return 1;
                    }
                }
                if (i < infix.size()-1) {
                    if (infix.at(i+1) == '&' || infix.at(i+1) == '^' || infix.at(i+1) == ')') {
                        return 1;
                    }
                }
                if (i > 0) {
                    if (infix.at(i-1) == ' ') {
                        for (size_t j = i-1; j > 0; j--) {
                            if (infix.at(j) != ' ') {
                                if (infix.at(j) == '!' || infix.at(j) == '&' || infix.at(j) == '^' || infix.at(j) == '(') {
                                    return 1;
                                }
                                break;
                            }
                        }
                    }
                }
                if (i < infix.size()-1) {
                    if (infix.at(i+1) == ' ') {
                        for (size_t j = i+1; j < infix.size(); j++) {
                            if (infix.at(j) != ' ') {
                                if (infix.at(j) == '&' || infix.at(j) == '^' || infix.at(j) == ')') {
                                    return 1;
                                }
                                break;
                            }
                        }
                    }
                }
                break;
            case '(':
                if (i == infix.size()-1) {
                    return 1;
                }
                if (i > 0) {
                    if (infix.at(i-1) == 'T' || infix.at(i-1) == 'F' || infix.at(i-1) == ')') {
                        return 1;
                    }
                }
                if (i < infix.size()-1) {
                    if (infix.at(i+1) == '&' || infix.at(i+1) == '^' || infix.at(i+1) == ')') {
                        return 1;
                    }
                }
                if (i > 0) {
                    if (infix.at(i-1) == ' ') {
                        for (size_t j = i-1; j > 0; j--) {
                            if (infix.at(j) != ' ') {
                                if (infix.at(j) == 'T' || infix.at(j) == 'F' || infix.at(j) == ')') {
                                    return 1;
                                }
                                break;
                            }
                        }
                    }
                }
                if (i < infix.size()-1) {
                    if (infix.at(i+1) == ' ') {
                        for (size_t j = i+1; j < infix.size(); j++) {
                            if (infix.at(j) != ' ') {
                                if (infix.at(j) == '&' || infix.at(j) == '^' || infix.at(j) == ')') {
                                    return 1;
                                }
                                break;
                            }
                        }
                    }
                }
                openCount++;
                break;
            case ')':
                if (i == 0) {
                    return 1;
                }
                if (i > 0) {
                    if (infix.at(i-1) == '!' || infix.at(i-1) == '&' || infix.at(i-1) == '^' || infix.at(i-1) == '(') {
                        return 1;
                    }
                }
                if (i < infix.size()-1) {
                    if (infix.at(i+1) == 'T' || infix.at(i+1) == 'F' || infix.at(i+1) == '!' || infix.at(i+1) == '(') {
                        return 1;
                    }
                }
                if (i > 0) {
                    if (infix.at(i-1) == ' ') {
                        for (size_t j = i-1; j > 0; j--) {
                            if (infix.at(j) != ' ') {
                                if (infix.at(j) == '!' || infix.at(j) == '&' || infix.at(j) == '^' || infix.at(j) == '(') {
                                    return 1;
                                }
                                break;
                            }
                        }
                    }
                }
                if (i < infix.size()-1) {
                    if (infix.at(i+1) == ' ') {
                        for (size_t j = i+1; j < infix.size(); j++) {
                            if (infix.at(j) != ' ') {
                                if (infix.at(j) == 'T' || infix.at(j) == 'F' || infix.at(j) == '!' || infix.at(j) == '(') {
                                    return 1;
                                }
                                break;
                            }
                        }
                    }
                }
                closedCount++;
                if (closedCount > openCount) {
                    return 1;
                }
                break;
            case ' ':
                break;
            default:
                return 1;
        }
    }
    
    if (openCount != closedCount) {
        return 1;
    }
    
    postfix = "";
    stack<char> s;
    for (size_t i = 0; i < infix.size(); i++) {
        char ch = infix.at(i);
        switch (ch) {
            case 'T':
            case 'F':
                postfix += ch;
                break;
            case '(':
                s.push(ch);
                break;
            case ')':
                while (s.top() != '(') {
                    postfix += s.top();
                    s.pop();
                }
                s.pop();
                break;
            case '!':
                while (!s.empty() && s.top() != '(' && s.top() != '&' && s.top() != '^' && s.top() != '!') {
                    postfix += s.top();
                    s.pop();
                }
                s.push(ch);
                break;
            case '&':
                while (!s.empty() && s.top() != '(' && s.top() != '^') {
                    postfix += s.top();
                    s.pop();
                }
                s.push(ch);
                break;
            case '^':
                while (!s.empty() && s.top() != '(') {
                    postfix += s.top();
                    s.pop();
                }
                s.push(ch);
                break;
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    for (size_t i = 0; i < postfix.size(); i++) {
        char ch = postfix.at(i);
        if (ch == 'T' || ch == 'F') {
            s.push(ch);
        }
        else if (ch == '!') {
            char operand = s.top();
            s.pop();
            if (operand == 'T') {
                s.push('F');
            } else {
                s.push('T');
            }
        }
        else {
            char operand2 = s.top();
            s.pop();
            char operand1 = s.top();
            s.pop();
            if (ch == '&') {
                if (operand1 == 'T' && operand2 == 'T') {
                    s.push('T');
                } else {
                    s.push('F');
                }
            }
            if (ch == '^') {
                if ((operand1 == 'T' && operand2 == 'T') || (operand1 == 'F' && operand2 == 'F')) {
                    s.push('F');
                } else {
                    s.push('T');
                }
            }
        }
    }
    char tempResult = s.top();
    s.pop();
    if (!s.empty()) {
        return 1;
    }
    if (tempResult == 'T') {
        result = 1;
    }
    else if (tempResult == 'F') {
        result = 0;
    }
    return 0;
}

int main() {
    string pf;
    bool answer;
    assert(evaluate("T^ F", pf, answer) == 0  &&  pf == "TF^"  &&  answer);
    assert(evaluate("T^", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate("()T", pf, answer) == 1);
    assert(evaluate("T(F^T)", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("(T&(F^F)", pf, answer) == 1);
    assert(evaluate("T|F", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("F  ^  !F & (T&F) ", pf, answer) == 0
           &&  pf == "FF!TF&&^"  &&  !answer);
    assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
    assert(evaluate("T^ F", pf, answer) == 0 && pf == "TF^" && answer);
    assert(evaluate("T^", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate("()T", pf, answer) == 1);
    assert(evaluate("(T", pf, answer) == 1);
    assert(evaluate("T)", pf, answer) == 1);
    assert(evaluate("(", pf, answer) == 1);
    assert(evaluate(")", pf, answer) == 1);
    assert(evaluate("(())", pf, answer) == 1);
    assert(evaluate("T(F^T)", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("(T&(F^F)", pf, answer) == 1);
    assert(evaluate("T|F", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("F  ^  !F & (T&F) ", pf, answer) == 0
           && pf == "FF!TF&&^" && !answer);
    assert(evaluate(" !F  ", pf, answer) == 0 && pf == "F!" && answer);
    assert(evaluate(" !    F  ", pf, answer) == 0 && pf == "F!" && answer);
    assert(evaluate(" !    T  ", pf, answer) == 0 && pf == "T!" && !answer);
    assert(evaluate(" F  ", pf, answer) == 0 && pf == "F" && !answer);
    assert(evaluate("((T))", pf, answer) == 0 && pf == "T" && answer);
    assert(evaluate("((!T))", pf, answer) == 0 && pf == "T!" && !answer);
    assert(evaluate(" T", pf, answer) == 0 && pf == "T" && answer);
    assert(evaluate(" (F)    ", pf, answer) == 0 && pf == "F" && !answer);
    assert(evaluate("  T^(F)", pf, answer) == 0 && pf == "TF^" && answer);
    assert(evaluate(" T ^ !F ", pf, answer) == 0 && pf == "TF!^" && !answer);
    assert(evaluate("  !(T&F)    ", pf, answer) == 0 && pf == "TF&!" && answer);
    assert(evaluate("!T&F", pf, answer) == 0 && pf == "T!F&" && !answer);
    assert(evaluate(" T^F&F", pf, answer) == 0 && pf == "TFF&^" && answer);
    assert(evaluate("T&!(F^T&T^F)^!!!(F&T&F)", pf, answer) == 0 && pf == "TFTT&^F^!&FT&F&!!!^" && answer);
    assert(evaluate("T^F^T", pf, answer) == 0 && pf == "TF^T^" && !answer);
    assert(evaluate("T!", pf, answer) == 1);
    assert(evaluate("!T!", pf, answer) == 1);
    assert(evaluate("T!!", pf, answer) == 1);
    assert(evaluate("T         &", pf, answer) == 1);
    assert(evaluate("T!       !", pf, answer) == 1);
    assert(evaluate("T^ F", pf, answer) == 0  &&  pf == "TF^"  &&  answer);
    assert(evaluate("T^", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate("()T", pf, answer) == 1);
    assert(evaluate("T(F^T)", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("(T&(F^F)", pf, answer) == 1);
    assert(evaluate("T|F", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("F  ^  !F & (T&F) ", pf, answer) == 0
           &&  pf == "FF!TF&&^"  &&  !answer);
    assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
    assert(evaluate("T", pf, answer) == 0 && answer == true);
    assert(evaluate("(F)", pf, answer) == 0 && answer == false);
    assert(evaluate("T ^(F)", pf, answer) == 0 && answer == true);
    assert(evaluate("T ^ !F", pf, answer) == 0 && answer == false);
    assert(evaluate("!(T&!!  !!F)", pf, answer) == 0 && answer == true);
    assert(evaluate("!T&F ", pf, answer) == 0 && answer == false);
    assert(evaluate("T^F&F", pf, answer) == 0 && answer == true);
    assert(evaluate("T&! (F^T&T^F  )^!!!(F&T&F)", pf, answer) == 0 && answer == true);
    assert(evaluate("TS DF:L", pf, answer) == 1);
    assert(evaluate("( F^T&!  F)", pf, answer) == 0 && answer == true);
    assert(evaluate("(( F))&((! T))", pf, answer) == 0 && answer == false);
    assert(evaluate("T^!F&T^T^(!F&T^!!T&F)", pf, answer) == 0 && answer == false);
    assert(evaluate("!!(F^T&F)", pf, answer) == 0 && answer == false);
    assert(evaluate("F^!T&T^!F", pf, answer) == 0 && answer == true);
    assert(evaluate("T&(F^!T&  T^!F)&!!(F^T& !F)", pf, answer) == 0 && answer == true);
    assert(evaluate("T^ F", pf, answer) == 0 && pf == "TF^"  &&  answer);
    assert(evaluate("T^", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate("()T", pf, answer) == 1);
    assert(evaluate("T(F^T)", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("(T&(F^F)", pf, answer) == 1);
    assert(evaluate("T|F", pf, answer) == 1);
    assert(evaluate("T&()F", pf, answer) == 1);
    assert(evaluate("T(&)F", pf, answer) == 1);
    assert(evaluate("T&F^T()", pf, answer) == 1);
    assert(evaluate("T&(F&T))&((T&T)", pf, answer) == 1);
    assert(evaluate("((T))(F)", pf, answer) == 1);
    assert(evaluate("F  ^  !F & (T&F) ", pf, answer) == 0
           && pf == "FF!TF&&^" && !answer);
    assert(evaluate(" F  ", pf, answer) == 0 && pf == "F" && !answer);
    assert(evaluate("((((T))))", pf, answer) == 0 && pf == "T"  &&  answer);
    assert(evaluate("(((T^F)()))", pf, answer) == 1);
    assert(evaluate("T^ F", pf, answer) == 0 && pf == "TF^" && answer);
    assert(evaluate("T^", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate("()T", pf, answer) == 1);
    assert(evaluate("T(F^T)", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("(T&(F^F)", pf, answer) == 1);
    assert(evaluate("T&(F^F))", pf, answer) == 1);
    assert(evaluate("T&(F^F)", pf, answer) == 0 && !answer && pf == "TFF^&");
    assert(evaluate("     T   &     (    F   ^   F   )   ", pf, answer) == 0 && !answer && pf == "TFF^&");
    assert(evaluate("T&(F^(T^(F&T)))", pf, answer) == 0 && answer && pf == "TFTFT&^^&");
    assert(evaluate("!T&(F^(T^(F&T)))", pf, answer) == 0 && !answer && pf == "T!FTFT&^^&");
    assert(evaluate("!T&!(T^F)", pf, answer) == 0 && !answer && pf == "T!TF^!&");
    assert(evaluate("((T))", pf, answer) == 0 && answer && pf == "T");
    assert(evaluate("((F))", pf, answer) == 0 && !answer && pf == "F");
    assert(evaluate("(!)", pf, answer) == 1);
    assert(evaluate("(^)", pf, answer) == 1);
    assert(evaluate("(&)", pf, answer) == 1);
    assert(evaluate("(T!)", pf, answer) == 1);
    assert(evaluate("(T^)", pf, answer) == 1);
    assert(evaluate("(T&)", pf, answer) == 1);
    assert(evaluate("(&T)", pf, answer) == 1);
    assert(evaluate("(^T)", pf, answer) == 1);
    assert(evaluate("((T)", pf, answer) == 1);
    assert(evaluate("(T))", pf, answer) == 1);
    assert(evaluate("T|F", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("    ", pf, answer) == 1);
    assert(evaluate("!", pf, answer) == 1);
    assert(evaluate("^", pf, answer) == 1);
    assert(evaluate("&", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("FT", pf, answer) == 1);
    assert(evaluate("F  ^  !F & (T&F) ", pf, answer) == 0 && pf == "FF!TF&&^" && !answer);
    assert(evaluate(" F  ", pf, answer) == 0 && pf == "F" && !answer);
    assert(evaluate("((T))", pf, answer) == 0 && pf == "T" && answer);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("(sdf)", pf, answer) == 1);
    assert(evaluate("()sdf", pf, answer) == 1);
    assert(evaluate("!", pf, answer) == 1);
    assert(evaluate("(", pf, answer) == 1);
    assert(evaluate("!!!", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("T(F", pf, answer) == 1);
    assert(evaluate("T(F)", pf, answer) == 1);
    assert(evaluate("()()", pf, answer) == 1);
    assert(evaluate("&!", pf, answer) == 1);
    assert(evaluate("^!", pf, answer) == 1);
    assert(evaluate("&()", pf, answer) == 1);
    assert(evaluate("!()", pf, answer) == 1);
    assert(evaluate("F && F", pf, answer) == 1);
    assert(evaluate("T", pf, answer) == 0);
    assert(evaluate("!T", pf, answer) == 0);
    assert(evaluate("(!(T))", pf, answer) == 0);
    assert(evaluate("!(((T&F)))", pf, answer) == 0);
    assert(evaluate("!T", pf, answer) == 0);
    assert(evaluate("!( T & !F ^ T)", pf, answer) == 0);
    assert(evaluate("T & !!F", pf, answer) == 0);
    assert(evaluate("F", pf, answer) == 0);
    assert(evaluate("T", pf, answer) == 0 && pf == "T" && answer);
    assert(evaluate("(!(T))", pf, answer) == 0 && pf == "T!" && !answer);
    assert(evaluate("!(((T&F)))", pf, answer) == 0 && pf == "TF&!" && answer);
    assert(evaluate("!T", pf, answer) == 0 && pf == "T!" && !answer);
    assert(evaluate("F", pf, answer) == 0 && pf == "F" && !answer);
    assert(evaluate("!(T&!F) ^!T& !F", pf, answer) == 0 && pf == "TF!&!T!F!&^" && !answer);
    assert(evaluate("!!!!T", pf, answer) == 0 && pf == "T!!!!" && answer);
    assert(evaluate("!!T", pf, answer) == 0);
    assert(evaluate("!!!!T", pf, answer) == 0);
    assert(evaluate("!!(T) & !F ^ T", pf, answer) == 0);
    assert(evaluate("!!!!T", pf, answer) == 0 && pf == "T!!!!" && answer);
    assert(evaluate("T & !!F", pf, answer) == 0 && pf == "TF!!&" && !answer);
    assert(evaluate("!( T & !F ^ T)", pf, answer) == 0 && pf == "TF!&T^!" && answer);
    assert(evaluate("!!( T & !F ^ T)", pf, answer) == 0 && pf == "TF!&T^!!" && !answer);
    assert(evaluate("!!!( T & !F ^ T)", pf, answer) == 0 && pf == "TF!&T^!!!" && answer);
    assert(evaluate("!!(T) & !F ^ T", pf, answer) == 0 && pf == "T!!F!&T^" && !answer);
    assert(evaluate("(T&T)(T&T)", pf, answer) == 1);
    assert(evaluate("T!T", pf, answer) == 1);
    assert(evaluate("f&t", pf, answer) == 1);
    assert(evaluate("(((T&F)^((T)))", pf, answer) == 1);
    cerr<<"Passed all test cases!"<<endl;
}
