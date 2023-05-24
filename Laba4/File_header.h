#ifndef FILE_H
#define FILE_H
bool fileExists(const std::string& filename);
bool is_file_empty(std::string filename);
std::string getfilename();
std::string reading_from_file(std::string filename);
void writing_to_file(std::string s1,std::string s2, std::string s3,std::string s4);
#endif FILE_H
