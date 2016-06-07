// CsvFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdint.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

enum TestEnum
{
    ZERO  = 0,
    ONE   = 1,
    TWO   = 2,
    THREE = 3
};

struct Data
{
    uint32_t var1;
    uint32_t var2;
    double   var3;
    double   var4;
    bool     var5;
    bool     var6;
    TestEnum var7;
    TestEnum var8;
    void print();
};

void Data::print()
{
    printf("%u, %u, %f, %f, %i, %i, %i, %i\n", var1, var2, var3, var4, var5, var6, var7, var8);
}

int _tmain(int argc, _TCHAR* argv[])
{
    //std::ifstream data("TestData.csv");
    //std::string line;
    //std::string cell;

    //while (std::getline(data, line))
    //{
    //    std::stringstream linestream(line);
    //    while (std::getline(linestream, cell, ','))
    //    {
    //        // Save data?
    //    }
    //}

    Data test;
    FILE* stream = fopen("TestData.csv", "r");
    int retVal = 0;
    if (stream != NULL)
    {
        // Skip the first two lines ot get past the header
        fscanf(stream, "%*[^\n]\n", NULL);
        fscanf(stream, "%*[^\n]\n", NULL);
        while (!feof(stream) && (retVal != EOF))
        {
            // Parse lines
            retVal = fscanf(stream, "%u,%u,%lf,%lf,%i,%i,%i,%i", &test.var1, &test.var2, &test.var3, &test.var4, &test.var5, &test.var6, &test.var7, &test.var8);
            if (retVal != EOF)
            {
                test.print();
            }
        } 
        // Close the file
        fclose(stream);
    }
	return 0;
}

