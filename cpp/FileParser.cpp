/**
 * @file   FileParser.cpp
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  FileParser returns lines from file one by one.
 *   
 */
#include "FileParser.h"
#include <iostream>
#include <fstream>




using namespace std;

/**
 * Constructs a FileParser
 * @param fileName name of input file
 */
FileParser::FileParser(string fileName) {
    setFile(fileName);

}

FileParser::FileParser(const FileParser& orig) {
}

FileParser::~FileParser() {

}

/**
 * Sets the current input file
 * @param fileName name of input file
 */
void FileParser::setFile(string fileName) {

    in_file.open(fileName.c_str());
}

/**
 * Reads and returns a single line from file
 * @return line from file as string
 */
string FileParser::readLine() {
    
    string line;
    if (!in_file.eof()) {
        in_file >> line;

        return line;
    } else {

        in_file.close();
        return NULL;
    }
}
