#include "°ýÈ£_º¯È¯.h"
#include <iostream>
#include <vector>

using namespace std;

°ýÈ£_º¯È¯_BEGIN

bool isCorrectParenthesisString(string parenthesisString);
string makeCorrectParenthesisString(string w);

string getReverseParenthesisString(string parenthesisString) {

    string str = "";

    for (int i = 1; i < parenthesisString.length() - 1; i++) {
        if (parenthesisString[i] == '(')
            str += ")";
        else
            str += "(";
    }

    return str;
}

string changeBalancedToCorrectParenthesisString(string& u, string& v) {
    string str = "(";
    str += makeCorrectParenthesisString(v);
    str += ")";
    str += getReverseParenthesisString(u);
    return str;
}

void divideToBalancedParenthesisString(string& w, string& u, string& v) {

    int balanceCount = 0;

    for (int i = 0; i < w.length(); i++) {

        if (w[i] == '(')
            balanceCount++;
        else
            balanceCount--;

        if (balanceCount == 0) {
            u = w.substr(0, i + 1);
            if (i + 1 < w.length()) v = w.substr(i + 1);
            else v = "";
            break;
        }
    }
}

string makeCorrectParenthesisString(string w) {

    if (w.length() == 0)
        return w;

    string u, v;

    divideToBalancedParenthesisString(w, u, v);

    if (isCorrectParenthesisString(u) == true)
        return u + makeCorrectParenthesisString(v);
    else
        return changeBalancedToCorrectParenthesisString(u, v);
}

bool isCorrectParenthesisString(string parenthesisString) {

    int validation = 0;

    for (char parenthesis : parenthesisString) {

        if (parenthesis == '(')
            validation++;
        else
            validation--;

        if (validation < 0)
            return false;
    }

    return (validation == 0);
}

string solution(string p) {

    if (isCorrectParenthesisString(p) == true)
        return p;

    string answer = makeCorrectParenthesisString(p);

    return answer;
}

void service() {

    string str = "()))((()";

    cout << solution(str) << endl;
}

°ýÈ£_º¯È¯_END