#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>


int main(int argc, char** argv)
{
    std::string phrase;// = "Hello world!!";
    std::cout << "[IN]: ";
    std::ifstream fin("data.txt");
    if (fin.is_open()) {
        std::getline(fin, phrase);
    }
    else {
        std::cout << "failed to open file!\n";
        return 1;
    }
    fin.close();
    std::cout << phrase << "\n";
    std::map<char, unsigned> num_of_char;
    std::for_each(phrase.begin(), phrase.end(), [&](char& i) {
        if (num_of_char[i]) {
            num_of_char[i] += 1;
        }
        else { num_of_char[i] = 1; }
        });

    std::vector<std::pair<char, unsigned>> vec_map;
    for (auto m: num_of_char) {
        vec_map.push_back(std::make_pair(m.first, m.second));
    }
    std::sort(vec_map.begin(), vec_map.end(),
        [](const std::pair<char, unsigned>& left, const std::pair<char, unsigned>& right) {
            return left.second > right.second;
        });
   
    std::cout << "[OUT]:" << std::endl;
    std::for_each(vec_map.begin(), vec_map.end(), [](const auto& i) {
        std::cout << i.first << ": " << i.second << std::endl;
        });
    return 0;
}

