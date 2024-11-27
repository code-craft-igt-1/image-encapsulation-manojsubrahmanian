#include "./image.h"
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <memory>

Image::Image(int rows, int columns) : m_rows(rows), m_columns(columns) {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Initialize the image with random values between 0 and 255
    pixels = std::make_unique<std::unique_ptr<int[]>[]>(rows);
    for (int i = 0; i < rows; ++i) {
        pixels[i] = std::make_unique<int[]>(columns);
        for (int j = 0; j < columns; ++j) {
            pixels[i][j] = std::rand() % 256;
        }
    }
}

int Image::GetPixel(int x, int y) const {
    if (x >= 0 && x < m_rows && y >= 0 && y < m_columns) {
        return pixels[x][y];
    }
    // Return a default value if out of bounds
    return 0;
}

void Image::SetPixel(int x, int y, int value) {
    if (x >= 0 && x < m_rows && y >= 0 && y < m_columns) {
        pixels[x][y] = value;
    }
}

bool Image::Validate() const {
    return m_columns <= 1024 && m_rows <= 1024;
}

int Image::Brighten() {
    if (!Validate()) {
        return -1; // Indicate invalid image
    }

    int attenuatedPixelCount = 0;
    for (int x = 0; x < m_rows; x++) {
        for (int y = 0; y < m_columns; y++) {
            if (GetPixel(x, y) > (255 - 25)) {
                ++attenuatedPixelCount;
                SetPixel(x, y, 255);
            } else {
                SetPixel(x, y, GetPixel(x, y) + 25);
            }
        }
    }
    return attenuatedPixelCount;
}