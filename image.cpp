#include "./image.h"
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>   // For time()
#include <memory>
#include <algorithm> // For std::transform

Image::Image(int rows, int columns) : m_rows(rows), m_columns(columns) {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Initialize the image with random values between 0 and 255
    pixels = std::make_unique<std::unique_ptr<int[]>[]>(rows);
    for (int i = 0; i < rows; ++i) {
        pixels[i] = std::make_unique<int[]>(columns);
        InitializeRow(i);
    }
}

void Image::InitializeRow(int x) {
    for (int y = 0; y < m_columns; ++y) {
        pixels[x][y] = std::rand() % 256;
    }
}

bool Image::IsValidIndex(int x, int y) const {
    return x >= 0 && x < m_rows && y >= 0 && y < m_columns;
}

int Image::GetPixel(int x, int y) const {
    if (IsValidIndex(x, y)) {
        return pixels[x][y];
    }
    //  Return a default value if out of bounds
    return 0;
}

void Image::SetPixel(int x, int y, int value) {
    if (IsValidIndex(x, y)) {
        pixels[x][y] = value;
    }
}

bool Image::Validate() const {
    return m_columns <= 1024 && m_rows <= 1024;
}

int Image::BrightenPixel(int x, int y) {
    int pixelValue = GetPixel(x, y);
    if (pixelValue > (255 - 25)) {
        SetPixel(x, y, 255);
        return 1;  // Pixel was attenuated
    } else {
        SetPixel(x, y, pixelValue + 25);
        return 0;  // Pixel was brightened
    }
}

int Image::BrightenRow(int x) {
    int attenuatedPixelCount = 0;
    for (int y = 0; y < m_columns; y++) {
        attenuatedPixelCount += BrightenPixel(x, y);
    }
    return attenuatedPixelCount;
}

int Image::Brighten() {
    if (!Validate()) {
        return -1; //  Indicate invalid image
    }

    int attenuatedPixelCount = 0;
    for (int x = 0; x < m_rows; x++) {
        attenuatedPixelCount += BrightenRow(x);
    }
    return attenuatedPixelCount;
}