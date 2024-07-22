#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string binomial) {
    stringstream ss(binomial);
    
    vector<string> words;
    string word;
    while (getline(ss, word, ' ')){
        words.push_back(word);
    }
    
    int num1 = stoi(words[0]);
    string op = words[1];
    int num2 = stoi(words[2]);
    
    if(op == "+") return num1 + num2;
    else if(op == "-") return num1 - num2;
    else if(op == "*") return num1 * num2;
}