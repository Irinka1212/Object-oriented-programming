#pragma once

#include "File.h"
#include "Resolution.h"

enum ImageExtension { jpg, png };

std::string imageExtensionToString(ImageExtension extension)
{
    switch (extension) {
        case jpg:
            return "jpg";
        case png:
            return "png";
    }
}

class ImageFile: public File
{
public:
    ImageFile(const std::string& name,
              int size,
              const std::string& deviceName,
              Resolution resolution,
              ImageExtension imageExtension);
    
    void setDeviceName(const std::string& deviceName);
    const std::string& getDeviceName() const;

    void setResolution(Resolution resolution);
    Resolution getResolution() const;

    void setImageExtension(ImageExtension imageExtension);
    ImageExtension getImageExtension() const;
    
private:
    std::string deviceName;
    Resolution resolution;
    ImageExtension imageExtension;
};
