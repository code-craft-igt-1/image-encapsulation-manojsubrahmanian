#include "./image.h"
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>   // For time()
#include <memory>

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

bool Image::IsValueWithinBounds(int value, int lowerBound, int upperBound) const {
    return value >= lowerBound && value < upperBound;
}

bool Image::IsValidIndex(int x, int y) const {
    return IsValueWithinBounds(x, 0, m_rows) && IsValueWithinBounds(y, 0, m_columns);
}

int Image::GetPixel(int x, int y) const {
    if (IsValidIndex(x, y)) {
        return pixels[x][y];
    }
    // Return a default value if out of bounds
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
