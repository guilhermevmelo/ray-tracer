#include "Bitmap.h"

Bitmap::Bitmap(int width, int height, char* fileName)
        :width(width), height(height), filename(fileName) {
            image = (unsigned char *) malloc(width * height * BYTES_PER_PIXEL);
            widthInBytes = width * BYTES_PER_PIXEL;

            std::cout << "w: " << width << " h: " << height << " bpp: " << BYTES_PER_PIXEL << std::endl;
            std::cout << "Image buffer size: " << sizeof(image) << std::endl;
        };

Bitmap::~Bitmap() {
    free(image);
}

unsigned char* Bitmap::createBitmapFileHeader(int height, int stride) {
    int fileSize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (stride * height);

    unsigned char* fileHeader = (unsigned char *) malloc(FILE_HEADER_SIZE);

    fileHeader[ 0] = (unsigned char)('B');
    fileHeader[ 1] = (unsigned char)('M');
    fileHeader[ 2] = (unsigned char)(fileSize      );
    fileHeader[ 3] = (unsigned char)(fileSize >>  8);
    fileHeader[ 4] = (unsigned char)(fileSize >> 16);
    fileHeader[ 5] = (unsigned char)(fileSize >> 24);
    fileHeader[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);

    return fileHeader;
}

unsigned char* Bitmap::createBitmapInfoHeader(int height, int width) {
    unsigned char * infoHeader = (unsigned char *) malloc(INFO_HEADER_SIZE);

    infoHeader[ 0] = (unsigned char)(INFO_HEADER_SIZE);
    infoHeader[ 4] = (unsigned char)(width      );
    infoHeader[ 5] = (unsigned char)(width >>  8);
    infoHeader[ 6] = (unsigned char)(width >> 16);
    infoHeader[ 7] = (unsigned char)(width >> 24);
    infoHeader[ 8] = (unsigned char)(height      );
    infoHeader[ 9] = (unsigned char)(height >>  8);
    infoHeader[10] = (unsigned char)(height >> 16);
    infoHeader[11] = (unsigned char)(height >> 24);
    infoHeader[12] = (unsigned char)(1);
    infoHeader[14] = (unsigned char)(BYTES_PER_PIXEL*8);

    return infoHeader;
}

void Bitmap::generateBitmapImage() {
    unsigned char padding[3] = {0, 0, 0};
    int paddingSize = (4 - (widthInBytes) % 4) % 4;

    std::cout << "Padding: " << paddingSize << std::endl;

    int stride = (widthInBytes) + paddingSize;

    FILE* imageFile = fopen(filename, "wb");

    unsigned char* fileHeader = createBitmapFileHeader(height, stride);
    fwrite(fileHeader, 1, FILE_HEADER_SIZE, imageFile);

    unsigned char* infoHeader = createBitmapInfoHeader(height, width);
    fwrite(infoHeader, 1, INFO_HEADER_SIZE, imageFile);

    // int i;
    // for (i = 0; i < height; i++) {
    //     fwrite(image + (i*widthInBytes), BYTES_PER_PIXEL, width, imageFile);
    //     fwrite(padding, 1, paddingSize, imageFile);
    // }

    fwrite(image, BYTES_PER_PIXEL, width * height, imageFile);
    fwrite(padding, 1, paddingSize, imageFile);

    fclose(imageFile);
    std::cout << widthInBytes << std::endl;
    std::cout << filename << " saved." << std::endl;
}

void Bitmap::setPixel(int i, int j, unsigned char red, unsigned char green, unsigned char blue) {
    image[i * widthInBytes + j] = red;
    image[i * widthInBytes + j + 1] = green;
    image[i * widthInBytes + j + 2] = blue;
}