#pragma once
#include <memory>

class Image {
 public:
    int m_rows;
    int m_columns;

    Image(int rows, int columns);
    int GetPixel(int x, int y) const;
    void SetPixel(int x, int y, int value);
    int Brighten();

 private:
    bool Validate() const;
    std::unique_ptr<std::unique_ptr<int[]>[]> pixels;
};
