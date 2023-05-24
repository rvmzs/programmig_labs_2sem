#ifndef FILEMAN_H
#define FILEMAN_H

bool CheckFile();

bool fileExists(const std::string& filename);
int FileF(const std::string& filename);
bool isFileEmpty(std::string filename);

#endif FILEMAN_H