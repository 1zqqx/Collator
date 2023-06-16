#include <iostream>
#include <direct.h>
#include <cstring>
#include <fstream>
#include <string>

// bool CompareToFile() {
//     char path_ac[256], path_wa[256];
//     _getcwd(path_ac, 256);
//     _getcwd(path_wa, 256);
//     std::string s_wa, s_ac;
//     std::string s_param;
//     for(int i = 0; path_ac[i] != 0; i++) s_ac += path_ac[i];
//     for(int i = 0; path_wa[i] != 0; i++) s_wa += path_wa[i];
//     s_ac += "\\data\\AC.out";
//     s_wa += "\\data\\WA.out";
//     std::cout << s_wa << '\n';
//     std::cout << s_ac << '\n';
//     std::string str = "fc " + s_param + " " + s_wa + " " + s_ac;
//     std::cout << str << '\n';
//     return system(str.c_str());
// }
// bool isFileExists_ifstream(std::string& name) {
//     std::ifstream f(name.c_str());
//     return f.good();
// }

const int FileCount = 4;
const std::string FileName[FileCount] = {"/AC.exe", "/WA.exe", "/data.exe", "/test.exe"};

void deleteFileIfExists(){
    char path_del[256];
    _getcwd(path_del, 256);
    std::string path;
    for(int i = 0; path_del[i] != 0; i++) path += path_del[i];
    
    for(int i = 0; i < FileCount; i++) {
        std::string s_te = path + FileName[i];
        int d = remove(s_te.c_str());
        std::cout << s_te << ' ' << d << '\n';
    }
}

int main(){
    deleteFileIfExists();
    return 0;
}