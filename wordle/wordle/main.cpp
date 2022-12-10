#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void rem(std::vector<std::string> &v, size_t index)
{
    auto it = v.begin();
    std::advance(it, index);
    v.erase(it);
}

void print(std::string mp[5][2]){
    for (int i=0; i<5; i++) {
        for (int j=0; j<2; j++) {
            std::cout<<mp[i][j]<<' ';
        }
        std::cout<<std::endl;
    }
}

void print(std::vector<std::string> dict){
    for (std::string i : dict) {
        std::cout<<i<<' ';
    }
    std::cout<<std::endl;
}

bool f(char letter, int pos, int num, std::string word){
    int p=word.find(letter);
    switch (num) {
        case 1:
            return word.find(letter)==std::string::npos;
            break;
        case 2:
            return word.find(letter)!=std::string::npos and p!=pos;
            break;
        case 3:
            return pos==p;
        default:
            return true;
            break;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream in("/Users/romburunduk/projects/wordle/wordle/dict.txt");
    std::vector<std::string> dict(4154);
    for (int i=0; i<4154; i++) {
        in>>dict[i];
    }
    
    std::string wor("сталь");
    int con[5]={2,2,1,1,3};

    
    int n=4154, t=0;
    while (t<n) {
        if (f(wor[0], 0, con[0], dict[t]) and f(wor[1], 1, con[1], dict[t]) and f(wor[2], 2, con[2], dict[t]) and f(wor[3], 3, con[3], dict[t]) and f(wor[4], 4, con[4], dict[t]) ) {
            std::cout<<dict[t]<<' ';
            t+=1;
        } else {
            rem(dict, t);
            n--;
        }
    }
    std::cout<<std::endl;
}

