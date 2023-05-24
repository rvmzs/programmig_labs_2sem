#ifndef FILE_HEADER
#define FILE_HEADER
float* ArrayFile();
void WriteFile(float* array, int n);
bool fileExists(const std::string& filename);
bool is_file_empty(std::string filename);
#endif FILE_HEADER
