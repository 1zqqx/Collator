#include <cstdio>
#include <windows.h>
#include <iostream>
#include <direct.h> // 获取路径
#include <cstring>
#include <string>
#include <fstream>

const int FileCount = 4;
const std::string FileName[FileCount] = {"/AC.exe", "/WA.exe", "/data.exe", "/test.exe"};

int CompileFile();
int Run_case();
bool CompareToFile();
bool CheckAllFigure(std::string& s);
bool CheckAllFigure(char s[]);
char* tolower(char s[]);
std::string tolower(std::string& s);
int transToFigure(char s[]);
int transToFigure(std::string& s);
bool isFileExists_ifstream(std::string& fname);
void deleteFileIfExists();

int main(int argc, char* argv[]){
    deleteFileIfExists();

    do{ // 预处理编码格式
        SetConsoleOutputCP(65001);
    }while (false);

    if(argc == 1) {
        // -----
        if(!CompileFile()) {
            return 0;
        }
        // -----
        if(!Run_case()) {
            return 0;
        }

        std::cerr << "\n[=] In Comparison..." << std::endl;
        if (CompareToFile()) {    //当 fc 返回1时，说明这时数据不一样
            std::cerr << "#测试点 1 : Wrong answer!" << std::endl;
        }
        else {
            std::cerr << "#测试点 1 : Accepted!" << std::endl;
        }
    }
    else if(argc == 2) {
        char help[] = "help";
        if(strcmp(tolower(argv[1]), help) == 0) { // 两个字符串相等返回0
            std::cerr << "Help" << std::endl;
        }
        else if(CheckAllFigure(argv[1])) {
            int case_s = transToFigure(argv[1]);
            // -----
            if(!CompileFile()) {
                return 0;
            }
            // -----
            // std::cerr << case_s << std::endl;
            for(int i = 1; i <= case_s; i++) {
                // -----
                Sleep(1000);
                // -----
                if(!Run_case()) {
                    return 0;
                }
                // -----
                std::cerr << "\n[=] In Comparison..." << std::endl;
                if (CompareToFile()) {    //当 fc 返回1时，说明这时数据不一样
                    std::cerr << "#测试点 " + std::to_string(i) + " : Wrong answer!" << std::endl;
                    return 0;
                }
                else {
                    std::cerr << "#测试点 " + std::to_string(i) + " : Accepted!" << std::endl;
                }
            }
        }
    }

    deleteFileIfExists();
    return 0;
}

int CompileFile(){
    // 源文件编译
    if(system("g++ -std=c++17 ./data.cpp -o data.exe")){
        std::cerr << "[-] Compile Error!" << std::endl;
        return 0;
    }
    else {
        std::cerr << "[=] Data compile success!" << std::endl;
    }
    if(system("g++ -std=c++17 ./AC.cpp -o AC.exe")) {
        std::cerr << "[-] Compile Error!" << std::endl;
        return 0;
    }
    else {
        std::cerr << "[=] AC.cpp compile success!" << std::endl;
    }
    if(system("g++ -std=c++17 ./WA.cpp -o WA.exe")){
        std::cerr << "[-] Compile Error!" << std::endl;
        return 0;
    }
    else {
        std::cerr << "[=] WA.cpp compile success!" << std::endl;
    }
    return 1;
}
int Run_case() {
    if(system("data.exe > ./data/in.in")){
        std::cerr << "[-] 执行错误...\n";
        return 0;
    }
    else {
        std::cerr << "[=] 生成数据...\n";
    }
    if(system("WA.exe < ./data/in.in > ./data/WA.out")){
        std::cerr << "[-] 执行错误...\n";
        return 0;
    }
    else {
        std::cerr << "[=] 执行WA.exe...\n";
    }
    if(system("AC.exe < ./data/in.in > ./data/AC.out")){
        std::cerr << "[-] 执行错误...\n";
        return 0;
    }
    else {
        std::cerr << "[=] 执行AC.exe...\n";
    }
    return 1;
}
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

    // std::cout << s_wa << '\n';
    // std::cout << s_ac << '\n';

    // /W 为了比较而压缩空格(tab和空格)
    std::string str = "fc /W " + s_param + " " + s_wa + " " + s_ac;

    // std::cout << str << '\n';
    int d = system(str.c_str());
    return d;
}
bool CheckAllFigure(std::string& s) {
    if(s.length() > 5) return false;
    for(auto& i:s) if(!isdigit(i)) return false;
    return true;
}
bool CheckAllFigure(char s[]){
    if(strlen(s) > 5) return false;
    for(int i = 0; s[i] != 0; i++) if(!isdigit(s[i])) return false;
    return true;
}
char* tolower(char s[]){
    for(int i = 0; s[i] != 0; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] + 32;
    }
    return s;
}
std::string tolower(std::string& s){
    for(auto& i:s) {
        if(i >= 'A' && i <= 'Z') i = i + 32;
    }
    return s;
}
int transToFigure(char s[]){
    int re = 0;
    for(int i = 0; s[i] != 0; i++) re = re * 10 + s[i] - '0';
    return re;
}
int transToFigure(std::string& s){
    return std::stoi(s);
}
bool isFileExists_ifstream(std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}
void deleteFileIfExists(){
    char path_del[256];
    _getcwd(path_del, 256);
    std::string path;
    for(int i = 0; path_del[i] != 0; i++) path += path_del[i];
    
    for(int i = 0; i < FileCount; i++) {
        std::string s_te = path + FileName[i];
        int d = remove(s_te.c_str());
        // std::cout << s_te << ' ' << d << '\n';
    }
}