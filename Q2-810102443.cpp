#include <iostream>
#include <string>
#include <set>

using namespace std;

set<int> solveTheEquation(string equation) {
    set<int> answers;
    for (int i = 0; i < equation.size(); i++) {
        char op = equation[i];
        if (op == '+' || op == '-' || op == '*'){
            set<int> leftEquation = solveTheEquation(equation.substr(0, i));
            set<int> rightEquation = solveTheEquation(equation.substr(i + 1));
            for (auto left : leftEquation) {
                for (auto right : rightEquation) {
                    if (op == '+') answers.insert(left + right);
                    else if (op == '-') answers.insert(left - right);
                    else if (op == '*') answers.insert(left * right);
                }
            }
        }
    }
    if (answers.empty()) answers.insert(stoi(equation));
    return answers;
}
void displayAnswers(set<int>& answers) {
    for (auto answer : answers){
        cout << answer << endl;
    }
}
int main() {
    int n;
    string equation;
    cin >> n;
    cin >> equation;
    solveTheEquation(equation);
    set<int> answers = solveTheEquation(equation);
    displayAnswers(answers);
    return 1;
}