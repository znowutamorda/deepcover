#ifndef EXTRACTOR_HPP
#define EXTRACTOR_HPP

#include <fstream>

class AbstractExtractor
{
protected:
    std::ifstream cipher;
    std::ifstream message;
    std::ofstream output;
public:
    AbstractExtractor(const std::string &in, const std::string &code, const std::string &out);
    virtual void decode() = 0;
    virtual ~AbstractExtractor();
};

class GenericExtractor : public AbstractExtractor
{
public:
    GenericExtractor(const std::string &in, const std::string &code, const std::string &out);
    void decode() override;
};

class BMPExtractor : public GenericExtractor
{
public:
    BMPExtractor(const std::string &in, const std::string &code, const std::string &out);
    void decode() override;
};


#endif //EXTRACTOR_HPP
