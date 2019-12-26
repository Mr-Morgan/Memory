#ifndef CATEGORIZER_H
#define CATEGORIZER_H

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <strstream>

#define U unsigned

[[noreturn]] inline void error(const std::string& s)
{
        throw std::runtime_error(s);
}//inline void error(const std::string& s)

[[noreturn]] inline void error(const std::string& s, const std::string& s2)
{
        error(s+s2);
}//inline void error(const std::string& s, const std::string& s2)

class pgmAnalysis
{
    std::ifstream *pgm_stream;
    int pgm_width;
    int pgm_height;
    U max_bright_value;
    U *histogram;
public:
    pgmAnalysis(char *filename);
    void setPGMData();
    void checkFormatPGM(char *pgm_file_name);
    void setHistogramSize();
    void analys();
    void getHistogram(U *hist, U &size_hist);
    ~pgmAnalysis();
};//class pgmAnalysis

pgmAnalysis::pgmAnalysis(char *filename) : pgm_width(-1), pgm_height(-1), max_bright_value(256),
    histogram(nullptr)
{
    pgm_stream = new std::ifstream(filename, std::ios::binary);
    if(!pgm_stream->is_open()) error(filename, ": it was not succeeded to open the file.");
    checkFormatPGM(filename);
}//pgmAnalysis::pgmAnalysis(std::ifstream *pgm)

void pgmAnalysis::setPGMData()
{
    pgm_stream->seekg(static_cast<U>(pgm_stream->tellg()) + 1);
    *pgm_stream >> pgm_width >> pgm_height;
    pgm_stream->seekg(static_cast<U>(pgm_stream->tellg()) + 1);
    *pgm_stream >> max_bright_value;
    pgm_stream->seekg(static_cast<U>(pgm_stream->tellg()) + 1);
}//void pgmAnalysis::setPGMData()

void pgmAnalysis::checkFormatPGM(char *pgm_file_name)
{
    char format_symbol = '?';
    *pgm_stream >> format_symbol;
    if (format_symbol == 'P') {
        *pgm_stream >> format_symbol;
        if (format_symbol == '5') return;
        else error(pgm_file_name, ": Incorrect format number!");
    } else error(pgm_file_name, ": Incorrect format character!");
}//void pgmAnalysis::checkFormatPGM(char *pgm_file_name)

void pgmAnalysis::setHistogramSize()
{
    if (max_bright_value != 256)
        histogram = new U[max_bright_value] ();
    for (U i = 0; i < max_bright_value; ++i)
        histogram[i] = 0;
}//void pgmAnalysis::setHistogramSize()

void pgmAnalysis::analys()
{
    setPGMData();
    setHistogramSize();
    char ch = '?';
    for (int i = 0; i < pgm_width*pgm_height; ++i) {
        pgm_stream->read(&ch, 1);
        if(pgm_stream->eof()) return;
        histogram[static_cast<U char>(ch)] += 1;
    }//for (char ch = '?'; *pgm_stream >> ch;)
}//void pgmAnalysis::analys()

void pgmAnalysis::getHistogram(U *hist, U &size_hist)
{
    if (histogram != nullptr) {
        for (U i = 0; i < max_bright_value; ++i)
            hist[i] = histogram[i];
        size_hist = max_bright_value;
    } else error("histogram is null pointer.");
}//void pgmAnalysis::getHistogram(U *hist, U *size_hist)

pgmAnalysis::~pgmAnalysis()
{
    delete [] histogram;
    pgm_stream->close();
    delete pgm_stream;
}//pgmAnalysis::~pgmAnalysis()

#endif // CATEGORIZER_H
