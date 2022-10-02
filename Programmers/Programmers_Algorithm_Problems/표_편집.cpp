#include "표_편집.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

표_편집_BEGIN

class Node {
public:
    int idx;
    int before;
    int next;
    bool isRemoved = false;
    Node(int idx, int  before, int next)
        : idx(idx), before(before), next(next) {}
};

void setTable(vector<Node>& table, int n) {
    for (int i = 0; i < n - 1; i++)
        table.push_back(Node(i, i - 1, i + 1));
    table.push_back(Node(n - 1, n - 2, -1));
}


void runCmd(string cmd, vector<Node>& table, int& cur, stack<Node>& removedRows) {

    if (cmd[0] == 'U') {
        int dist = stoi(cmd.substr(2));
        while (dist--) cur = table[cur].before;
    }
    else if (cmd[0] == 'D') {
        int dist = stoi(cmd.substr(2));
        while (dist--) cur = table[cur].next;
    }
    else if (cmd[0] == 'C') {

        table[cur].isRemoved = true;
        removedRows.push(table[cur]);

        if (table[cur].next != -1) {
            
            if (table[cur].before != -1) {
                table[table[cur].before].next = table[cur].next;
                table[table[cur].next].before = table[cur].before;
            }
            else {
                table[table[cur].next].before = -1;
            }
            
            cur = table[cur].next;
        }
        else {

            if (table[cur].before != -1) {
                
                table[table[cur].before].next = -1;
            }
            else {
                cur = -1;
            }


            cur = table[cur].before;
        }
    }
    else if (cmd[0] == 'Z') {

        if (removedRows.empty() == true)
            return;

        Node row = removedRows.top();
        removedRows.pop();

        table[row.idx].isRemoved = false;

        if (table[row.idx].next != -1) {

            if (table[row.idx].before != -1) {
                table[table[row.idx].before].next = row.idx;
                table[table[row.idx].next].before = row.idx;
            }
            else {
                table[table[row.idx].next].before = row.idx;
            }
        }
        else {

            if (table[row.idx].before != -1) {
                table[table[row.idx].before].next = row.idx;
            }
        }
    }

}

string solution(int n, int k, vector<string> cmd) {
    
    // 표를 배열로 구현한다.
    // 배열의 각 원소는 행의 정보를 담고 있는데,
    // 초기 index, 이전 행 index, 다음 행 index, 현재 상태를 담고 있다.
    
    // 이동할 때는 이전 행 index와 다음 행 index 정보를 통해 이동한다.
    
    // 삭제할 때는 행 상태를 바꾼 후 linkedlist의 노드 삭제 방식으로 정보를 수정해 주고,
    // 삭제 행 정보를 따로 stack을 통해 관리한다.
    
    // 복구할 때는 stack에서 행 정보를 꺼내어 그 정보를 토대로 복구한다.

    string answer = "";
    
    vector<Node> table;
    stack<Node> removedRows;
    int cur = k;

    setTable(table, n);

    for (string command : cmd)
        runCmd(command, table, cur, removedRows);

    for (int i = 0; i < n; i++)
        if (table[i].isRemoved == true)
            answer += 'X';
        else
            answer += 'O';

    return answer;
}

void service() {

    int n = 8;
    int k = 2;
    vector<string> cmds = { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" };

    string ans = solution(n, k, cmds);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

표_편집_END