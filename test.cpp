#include <iostream>
#include <direct.h>
#include <cstring>

bool CompareToFile() {
    char path_ac[256], path_wa[256];
    _getcwd(path_ac, 256);
    _getcwd(path_wa, 256);
    
    std::string s_wa, s_ac;
    std::string s_param;

    for(int i = 0; path_ac[i] != 0; i++) s_ac += path_ac[i];
    for(int i = 0; path_wa[i] != 0; i++) s_wa += path_wa[i];
    s_ac += "\\data\\AC.out";
    s_wa += "\\data\\WA.out";

    std::cout << s_wa << '\n';
    std::cout << s_ac << '\n';

    std::string str = "fc " + s_param + " " + s_wa + " " + s_ac;

    std::cout << str << '\n';
    return system(str.c_str());
}

int main(){
    if(system("g++ A.cpp -o A")) {
        std::cout << "Error!\n";
    }
    else {
        std::cout << "ok\n";
    }
    // else std::cout << "Error!\n";
    return 0;
}