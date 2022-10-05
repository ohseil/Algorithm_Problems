#include "수식_최대화.h"
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <set>

using namespace std;

수식_최대화_BEGIN

void split(string expression, queue<string>& tokens, set<char>& operatorSet) {

    int idx = 0;

    while (idx < expression.length()) {
        
        idx = 0;

        for (int i = idx; i < expression.length(); i++) {

            char ch = expression[i];

            if (ch == '+' || ch == '-' || ch == '*') {
                tokens.push(expression.substr(0, i));
                string oper = "";
                oper += ch;
                tokens.push(oper);
                operatorSet.insert(ch);
                expression = expression.substr(i + 1);
                break;
            }

            idx = i + 1;
        }

    }

    tokens.push(expression);
}

long long runOperator(char op, long long n1, long long n2) {
    if (op == '+') return n1 + n2;
    else if (op == '-') return n1 - n2;
    else if (op == '*') return n1 * n2;
    return -1;
}

void calculate(vector<char>& operators, queue<string> tokens, long long& answer) {

    for (char op : operators) {
        
        queue<string> q;

        long long num1 = 0;

        while (tokens.empty() == false) {

            string token = tokens.front();
            tokens.pop();

            if (token != "+" && token != "-" && token != "*") {
                num1 = stoll(token);
            }
            else {

                if (token[0] == op) {
                    long long num2 = stoll(tokens.front());
                    tokens.pop();
                    num1 = runOperator(op, num1, num2);
                }
                else {
                    q.push(to_string(num1));
                    q.push(token);
                }
            }
        }

        q.push(to_string(num1));

        tokens = q;

    }

    long long result = abs(stoll(tokens.front()));

    if (result > answer)
        answer = result;
}

void permutation(vector<char> operators, queue<string>& tokens, int depth, long long& answer) {

    if (depth == operators.size()) {
        calculate(operators, tokens, answer);
        return;
    }

    for (int i = depth; i < operators.size(); i++) {
        swap(operators[depth], operators[i]);
        permutation(operators, tokens, depth + 1, answer);
        swap(operators[depth], operators[i]);
    }
}

long long solution(string expression) {
    
    // expression에 포함 된 연산자를 리스트로 만들고
    // permutation을 통해 모든 순서를 만들어서 계산한다.

    long long answer = 0;
    
    queue<string> tokens;
    vector<char> operators;
    set<char> operatorSet;

    split(expression, tokens, operatorSet);

    for (char oper : operatorSet)
        operators.push_back(oper);

    permutation(operators, tokens, 0, answer);
    
    return answer;
}

void service() {

    string expression = "100-200*300-500+20";

    cout << solution(expression) << endl;
}

수식_최대화_END