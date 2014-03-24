/**
 * @file   FileParser.h
 * @Author Sion Griffiths (sig2@aber.ac.uk)
 * @date   March 2014
 * @brief  FileParser returns lines from file one by one.
 *   
 */
#include <string>
#include <iostream>
#include <fstream>
#ifndef FILEPARSER_H
#define	FILEPARSER_H
using namespace std;

class FileParser {
public:
    /**
     * Constructs a FileParser
     * @param fileName name of input file
     */
    FileParser(string fileName);
    FileParser(const FileParser& orig);
    virtual ~FileParser();

    /**
     * Reads and returns a single line from file
     * @return line from file as string
     */
    string readLine();

private:

    /**
     *file stream instance.
     */
    ifstream in_file;

    /**
     * Sets the current input file
     * @param fileName name of input file
     */
    void setFile(string fileName);
};

#endif	/* FILEPARSER_H */

