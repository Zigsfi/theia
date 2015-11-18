#ifndef PNMIMAGE_H
#define PNMIMAGE_H

#include <cstdio>
#include <inttypes.h>

struct pixel_t {
    long r, g, b;

    pixel_t() : r(0), g(0), b(0)
    {
    }

    pixel_t(long r, long g, long b) : r(r), g(g), b(b)
    {
    }

    pixel_t &operator+=(const pixel_t &other)
    {
        r += other.r;
        g += other.g;
        b += other.b;
        return *this;
    }
};

class PnmImage {
public:
    PnmImage(size_t width, size_t height, long denom);
    PnmImage(size_t width, size_t height);
    ~PnmImage();
    void init(size_t width, size_t height, long denom);
    static PnmImage read(FILE *fp);
    bool write(FILE *fp);
    bool set_pixel(size_t x, size_t y, pixel_t pixel);
    long get_denominator();

private:
    size_t width, height;
    long denominator;
    pixel_t **pixels;
};

#endif
