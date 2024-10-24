#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

// 测试用
void init() {
  fs::path inFile = "hackdata/data/1.in";
  fs::path outFile = "hackdata/data/1.out";
  if (fs::exists(outFile)) {
    // 复制 .in 文件到 main.in
    string command = "cp " + inFile.string() + " main.in";
    system(command.c_str());

    // 复制 .out 文件到 ./judge/std.out
    command = "cp " + outFile.string() + " ./judge/stds.out";
    system(command.c_str());

    // 运行 main.exe
    command = "./main";
    system(command.c_str());

    // 将运行结果复制到test.out中
    command = "cp main.out ./judge/test.out";
    system(command.c_str());

    // 编译运行./judge/main.cpp,比较输出
    command = "g++ -std=c++17 -Wall -Wextra -ggdb  ./judge/main.cpp "
              "-o ./judge/main";
    system(command.c_str());
    command = "cd ./judge/ && ./main";
    system(command.c_str());
  }
}

string getLastLine(const string &filePath) {
  ifstream file(filePath);
  string line;
  string lastLine;
  while (getline(file, line)) {
    lastLine = line;
  }
  return lastLine;
}

int main() {
  fs::path hackdataPath = "hackdata/data"; // 指定目录路径

  // 编译 ./main.cpp
  system("make");

  // 编译./judge/main.cpp
  system("make judgecmp");
  // 移除上次测试的结果
  fs::path resultFile = "./judge/result.out";
  if (fs::exists(resultFile)) {
    fs::remove(resultFile);
  }

  // init();

  // 遍历目录中的所有文件
  for (const auto &entry : fs::directory_iterator(hackdataPath)) {
    if (entry.path().extension() == ".in") {
      // 获取 .in 文件路径
      fs::path inFile = entry.path();
      fs::path outFile = inFile;
      outFile.replace_extension(".out");

      // 检查 .out 文件是否存在
      if (fs::exists(outFile)) {
        // 复制 .in 文件到 main.in
        string command = "cp " + inFile.string() + " main.in";
        system(command.c_str());

        // 复制 .out 文件到 ./judge/std.out
        command = "cp " + outFile.string() + " ./judge/stds.out";
        system(command.c_str());

        // 运行 main.exe,获得测试程序的结果
        // command = "./main";
        // system(command.c_str());
        system("./main < main.in > main.out");

        // 将运行结果复制到test.out中
        command = "cp main.out ./judge/test.out";
        system(command.c_str());

        command = "cd ./judge/ && ./main";
        system(command.c_str());

        // 获取 judge/result.out 文件的最后一行数据
        string lastLine = getLastLine("./judge/result.out");
        if (lastLine == "Rejected") {
          cout << inFile.string() << endl;
        }

      } else {
        cerr << "Corresponding .out file for " << inFile.filename()
             << " not found." << endl;
      }
    }
  }

  return 0;
}