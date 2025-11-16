#ifndef INDEX
#define INDEX

#include <iostream>
#include <filesystem>
#include <String>
#include <fstream>
#include <optional>

void printDir(std::filesystem::path root);
std::string formatPath(std::filesystem::path inPath);
std::string formatPath(std::filesystem::path inPath, std::string description);
std::fstream init(std::filesystem::path root, std::string outputName);
void sendFile(std::filesystem::path dir, std::fstream &outputFile);
void makeIndex(std::filesystem::path root);

#endif