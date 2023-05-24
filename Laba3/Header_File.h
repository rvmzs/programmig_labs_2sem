#ifndef FILEHEADER_H
#define FILEHEADER_H
bool fileExists(const std::string& filename);
void WriteToFile(float** matrix, int n, int m);
float** matrixfromfile();
bool is_file_empty(std::string filename);
#endif FILEHEADER_H 
