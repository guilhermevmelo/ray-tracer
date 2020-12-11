#include <iostream>
#include <cstdlib>
#include "Bitmap.h"

using namespace std;

int main() {
    int width, height;
    char* filename = (char *) malloc(100 * sizeof(char));

    cout << "Width and Height: ";
    cin >> width;
    cin >> height;

    cout << "File name: ";
    cin >> filename;

    // width = 512;
    // height = 512;
    // filename = (char *) "image.bmp";

    Bitmap * image = new Bitmap(width, height, filename);

    int i, j;
    for (i = height; i >= 1; i--) {
        for (j = width; j >= 1; j--) {
            
            short red   = (unsigned char) ( (height - i) * 255 / height );             ///red
            short green = (unsigned char) ( (width - j) * 255 / width );              ///green
            short blue  = (unsigned char) ( (i+j) * 255 / (height+width) ); ///blue

            image->setPixel(i, j, red, green, blue);            
        }
    }

    image->generateBitmapImage();

    return 0;
}