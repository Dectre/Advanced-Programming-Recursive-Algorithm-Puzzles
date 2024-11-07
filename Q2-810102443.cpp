#include <iostream>
#include <string>
#include <set>

using namespace std;

typedef set<int> Answers;

void handleLeftAndRight(Answers& answers, Answers& leftEquation, Answers& rightEquation, char& op){
    for (auto left : leftEquation) {
        for (auto right : rightEquation) {
            if (op == '+') answers.insert(left + right);
            else if (op == '-') answers.insert(left - right);
            else if (op == '*') answers.insert(left * right);
        }
    }
}

Answers solveTheEquation(string equation) {
    Answers answers;
    
    for (int i = 0; i < equation.size(); i++) {
        char op = equation[i];
        if (op == '+' || op == '-' || op == '*'){
            Answers leftEquation = solveTheEquation(equation.substr(0, i));
            Answers rightEquation = solveTheEquation(equation.substr(i + 1));
            handleLeftAndRight(answers, leftEquation, rightEquation, op);
        }
    }

    if (answers.empty()) answers.insert(stoi(equation));
    
    return answers;
}

void displayNumOfAnswers(Answers& answers) {
    cout << answers.size() << endl;
}

int main() {
    int n;
    string equation;

    cin >> n;
    cin >> equation;
    
    Answers answers = solveTheEquation(equation);
    displayNumOfAnswers(answers);

    return 1;
}