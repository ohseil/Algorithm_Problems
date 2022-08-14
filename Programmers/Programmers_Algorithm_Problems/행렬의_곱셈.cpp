#include "Çà·ÄÀÇ_°ö¼À.h"
#include <iostream>
#include <vector>

using namespace std;

Çà·ÄÀÇ_°ö¼À_BEGIN

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    
    // Çà·Ä °ö¼À °ø½Ä

    vector<vector<int>> answer;
    
    for (int r1 = 0; r1 < arr1.size(); r1++) {

        vector<int> elementV;

        for (int c2 = 0; c2 < arr2[0].size(); c2++) {
            
            int element = 0;

            for (int c1 = 0; c1 < arr1[0].size(); c1++) {

                element += (arr1[r1][c1] * arr2[c1][c2]);
            }
            
            elementV.push_back(element);
        }

        answer.push_back(elementV);
    }

    return answer;
}

void service() {

    vector<vector<int>> arr1 = { {1,4},{3,2},{4,1} };
    vector<vector<int>> arr2 = { {3,3},{3,3} };

    vector<vector<int>> ans = solution(arr1, arr2);
    for (auto a : ans) {
        for (auto b : a)
            cout << b << " ";
        cout << endl;
    }
    cout << endl;
}

Çà·ÄÀÇ_°ö¼À_END