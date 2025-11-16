#include "index.hpp"

void printDir(std::filesystem::path root) {
    for(auto const& path : std::filesystem::directory_iterator{root}) {
        if(path.path().filename().string()[0] != '.') {
            if(std::filesystem::is_directory(path)) {
                printDir(path);
            }
            std::cout << path.path().filename() << "\n";
        }
    }
}
std::string addDirHeading( std::filesystem::path dir) {
    return "## " + dir.filename().string();
}
std::string formatPath(std::filesystem::path inPath) {
    return "- [[" + inPath.filename().string() + "]]";
}
std::fstream init(std::filesystem::path root, std::string outputName) {
    return std::fstream (root.append(outputName), std::ios::out);
}
void sendFile(std::filesystem::path dir, std::fstream &outputFile) {
    for(const auto& path : std::filesystem::directory_iterator{dir}) {
        if(path.path().filename().string()[0] != '.') {
            if(std::filesystem::is_directory(path)) {
                outputFile << addDirHeading(path) << "\n";
                sendFile(path, outputFile);
            }
            if(!path.is_directory())
                outputFile << formatPath(path.path()) << "\n";

        }
    }
}
void makeIndex(std::filesystem::path root) {
    std::fstream outputFile = init(root, "Table of Contents.md");
    
    sendFile(root, outputFile);

    outputFile.close();
    

}
