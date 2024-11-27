#include "./imageBrightener.h"

ImageBrightener::ImageBrightener(std::shared_ptr<Image> image) : m_image(std::move(image)) {}

int ImageBrightener::BrightenPixel(int x, int y) {
    int pixelValue = m_image->GetPixel(x, y);
    if (pixelValue > (255 - 25)) {
        m_image->SetPixel(x, y, 255);
        return 1;  //  Pixel was attenuated
    } else {
        m_image->SetPixel(x, y, pixelValue + 25);
        return 0;  //  Pixel was brightened
    }
}

int ImageBrightener::BrightenRow(int x) {
    int attenuatedPixelCount = 0;
    for (int y = 0; y < m_image->m_columns; y++) {
        attenuatedPixelCount += BrightenPixel(x, y);
    }
    return attenuatedPixelCount;
}

int ImageBrightener::BrightenWholeImage() {
    if (!m_image->Validate()) {
        return -1;  //  Indicate invalid image
    }

    int attenuatedPixelCount = 0;
    for (int x = 0; x < m_image->m_rows; x++) {
        attenuatedPixelCount += BrightenRow(x);
    }
    return attenuatedPixelCount;
}
