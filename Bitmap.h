#include <iostream>
#include <cstdlib>

class Bitmap {
private:
    int width, height, widthInBytes;
    unsigned char* image;
    char* filename;

    unsigned char* createBitmapFileHeader(int, int);
    unsigned char* createBitmapInfoHeader(int, int);

public:
    Bitmap(int, int, char*);
    ~Bitmap();
    void generateBitmapImage();
    void setPixel(int, int, unsigned char, unsigned char, unsigned char);

    static const int BYTES_PER_PIXEL = 3; // red, green, & blue
    static const int FILE_HEADER_SIZE = 14;
    static const int INFO_HEADER_SIZE = 40; 
};

