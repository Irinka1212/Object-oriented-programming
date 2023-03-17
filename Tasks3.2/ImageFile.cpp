#include "ImageFile.h"

ImageFile::ImageFile(const std::string& name,
                     int size,
                     const std::string& deviceName,
                     Resolution resolution,
                     ImageExtension imageExtension) :
File(name, size, imageExtensionToString(imageExtension)),
deviceName(deviceName), resolution(resolution), imageExtension(imageExtension)
{}

void ImageFile::setDeviceName(const std::string& deviceName)
{
    this->deviceName = deviceName;
}

const std::string& ImageFile::getDeviceName() const
{
    return deviceName;
}

void ImageFile::setResolution(Resolution resolution)
{
    this->resolution = resolution;
}

Resolution ImageFile::getResolution() const
{
    return resolution;
}

void ImageFile::setImageExtension(ImageExtension imageExtension)
{
    this->imageExtension = imageExtension;
    setExtension(imageExtensionToString(imageExtension));
}

ImageExtension ImageFile::getImageExtension() const
{
    return imageExtension;
}
