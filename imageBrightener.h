#pragma once
#include <memory>
#include "./image.h"

class ImageBrightener {
 public:
    explicit ImageBrightener(std::shared_ptr<Image> image);
    int BrightenWholeImage();

 private:
    std::shared_ptr<Image> m_image;
    int BrightenPixel(int x, int y);
    int BrightenRow(int x);
};
