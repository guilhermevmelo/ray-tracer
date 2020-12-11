#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Bitmap.h"
#include "Point.h"

using namespace std;

int main() {
    int width, height;
    char* filename = (char *) malloc(100 * sizeof(char));

    // cout << "Width and Height: ";
    // cin >> width;
    // cin >> height;

    // cout << "File name: ";
    // cin >> filename;

    width = 500;
    height = 500;
    filename = (char *) "sierpinsky.bmp";

    Bitmap * image = new Bitmap(width, height, filename);

    const int interactions = 100000;
    Point triangle[3] = {Point(floor(width/2), 0), Point(0, height), Point(width,height)};
    Point p = (triangle[0] + triangle[1] + triangle[2]) / 3;

    for(int i = 0; i < interactions; i++) {
        int index = rand() % 3;
        Point q = (p + triangle[index]) / 2;
        // cout << q << endl;
        if (q.x > 0 && q.y > 0) {
            image->setPixel(q.x, q.y, 255 * (index == 0), 255 * (index == 1), 255 * (index == 2));
        }
        p = q;
    }
    

    image->generateBitmapImage();

    return 0;
}