#ifndef PNMIMAGE_H
#define PNMIMAGE_H

#include <functional>

#include <cstdio>
#include <inttypes.h>

#include "pixel.h"


class PnmImage {
public:
    PnmImage(size_t width, size_t height, long denom);
    PnmImage(size_t width, size_t height);
    ~PnmImage();
    void init(size_t width, size_t height, long denom);
    static PnmImage read(FILE *fp);
    bool write(std::string filename) const;
    bool write(FILE *fp) const;
    bool set_pixel(size_t x, size_t y, pixel_t pixel);
    pixel_t get_pixel(size_t x, size_t y) const;
    size_t get_width() const;
    size_t get_height() const;
    long get_denominator() const;
    void insert_chunk(pixel_t **chunk,
                      size_t x,
                      size_t y,
                      size_t width,
                      size_t height);
    typedef std::function<pixel_t(const PnmImage *,
                                  pixel_t cur,
                                  size_t x,
                                  size_t y)> map_function;
    void map(map_function f);

private:
    size_t width, height;
    long denominator;
    pixel_t **pixels;
};

#endif
