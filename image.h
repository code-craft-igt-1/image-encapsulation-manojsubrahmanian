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
    bool IsValueWithinBounds(int value, int lowerBound, int upperBound) const;
    bool IsValidIndex(int x, int y) const;
    int BrightenPixel(int x, int y);
    int BrightenRow(int x);
    void InitializeRow(int x);
    std::unique_ptr<std::unique_ptr<int[]>[]> pixels;
};
