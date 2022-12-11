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

bool f(std::string letter, int pos, int num, std::string word){
    int p=word.find(letter,pos);
    switch (num) {
        case 1:
            return word.find(letter)==std::string::npos;
            break;
        case 2:
            return word.find(letter)!=std::string::npos && p!=pos;
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
    int n=4154;
    std::vector<std::string> dict(n);
    for (int i=0; i<n; i++) {
        in>>dict[i];
    }
    
    std::string wor("boo");
    std::vector<int> con(5);
    std::cout<<"Введите слово"<<std::endl;
    std::cin>>wor;
    std::cout<<"Введите условия"<<std::endl;
    for (int j : con) {
        std::cin>>j;
    }

    
    while (wor!="end") {
        int t=0;
        while (t<n) {
            if (f(wor.substr(0,2), 0, con[0], dict[t]) && f(wor.substr(2,2), 2, con[1], dict[t]) && f(wor.substr(4,2), 4, con[2], dict[t]) && f(wor.substr(6,2), 6, con[3], dict[t]) && f(wor.substr(8,2), 8, con[4], dict[t]) ) {
                std::cout<<dict[t]<<' ';
                t+=1;
            } else {
                rem(dict, t);
                n--;
            }
        }
        std::cout<<std::endl;
        std::cout<<"Введите слово"<<std::endl;
        std::cin>>wor;
        if (wor=="end") {
            break;
        }
        std::cout<<"Введите условия"<<std::endl;
        for (int j=0; j<5; j++) {
            std::cin>>con[j];
        }
    }
    std::cout<<std::endl;
}

