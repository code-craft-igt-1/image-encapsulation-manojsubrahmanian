#include <iostream>
#include <memory>
#include "./image.h"
#include "./imageBrightener.h"

int main() {
    auto image = std::make_shared<Image>(512, 512);
    std::cout << "Brightening a 512 x 512 image\n";

    ImageBrightener brightener(image);
    int attenuatedCount = brightener.BrightenWholeImage();
    if (attenuatedCount >= 0) {
        std::cout << "Attenuated " << attenuatedCount << " pixels\n";
        std::cout << "... in an image of: " << image->m_rows << " x " << image->m_columns << "\n";
        return 0;
    } else {
        std::cout << "Not a valid image... did nothing\n";
        return 1;
    }
}
