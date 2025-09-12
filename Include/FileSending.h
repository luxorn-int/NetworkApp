#ifndef FILE_SENDING_H
#define FILE_SENDING_H

#include <boost/crc.hpp>
#include <fstream>
#include <vector>

namespace FileSending
{
    uint32_t checkSum(const std::string& FilePath)
    {
        std::ifstream file(FilePath, std::ios::binary);

        if (!file) {throw std::runtime_error("can't open file: " + FilePath);}

        boost::crc_32_type crc_checker;
        std::vector<char> buffer(65536);
    }
}

#endif // FILE_SENDING_H