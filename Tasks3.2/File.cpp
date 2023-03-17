#include "File.h"

File::File(const std::string& name, int size, const std::string& extension)
: Content(name), size(size), extension(extension)
{}

void File::setSize(int size)
{
    this->size = size;
}

int File::getSize() const
{
    return size;
}

void File::setExtension(const std::string& extension)
{
    this->extension = extension;
}

const std::string& File::getExtension() const
{
    return extension;
}
