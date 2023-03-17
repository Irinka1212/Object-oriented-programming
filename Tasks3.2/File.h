#pragma once

#include "Content.h"

class File: public Content
{
public:
    File(const std::string& name, int size, const std::string& extension);
    
    void setSize(int size);
    int getSize() const;
    
    void setExtension(const std::string& extension);
    const std::string& getExtension() const;
    
private:
    int size; // Size measured in megabytes
    std::string extension;
};
