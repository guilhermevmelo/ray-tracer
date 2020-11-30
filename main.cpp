#include <iostream>
#include <cstdlib>
#include "Bitmap.h"

using namespace std;

int main() {
    int width, height;
    char* filename = (char *) malloc(100 * sizeof(char));

    // cout << "Width and Height: ";
    // cin >> width;
    // cin >> height;

    // cout << "File name: ";
    // cin >> filename;

    width = 256;
    height = 256;
    filename = (char *) "image.bmp";

    Bitmap * image = new Bitmap(width, height, filename);

    int i, j;
    for (i = height - 1; i >= 0; i--) {
        for (j = 0; j < width; j++) {
            
            short red   = (unsigned char) ( i * 255 / height );             ///red
            short green = (unsigned char) ( j * 255 / width );              ///green
            short blue  = (unsigned char) ( (i+j) * 255 / (height+width) ); ///blue

            image->setPixel(i, j, red, green, blue);
        }
    }

    image->generateBitmapImage();

    return 0;
}