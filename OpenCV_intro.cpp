#include <iostream>
#include <stdio.h>
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;


int main()
{

    int redPixels;
    int greenPixels;
    int bluePixels;
    int x;

    Mat frame = imread("BlueCar.bmp"); // Open an image file and store in a new matrix variable
    Mat frameHSV;
    while(1)    // Main loop to perform image processing
    {


        Mat red;
        cvtColor(frame,red,COLOR_BGR2HSV);

        Mat green;
        cvtColor(frame,green,COLOR_BGR2HSV);

        Mat blue;
        cvtColor(frame,blue,COLOR_BGR2HSV);


        inRange(red, Scalar(0,50,50), Scalar(10,255,255), red);
        redPixels= countNonZero(red);

        inRange(green, Scalar(40,50,50), Scalar(80,255,255),green);
        greenPixels= countNonZero(green);

        inRange(blue, Scalar(100,50,50), Scalar(140,255,255),blue);
        bluePixels= countNonZero(blue);



        if (redPixels>greenPixels && redPixels>bluePixels)
            x=0;
        else if (greenPixels>redPixels && greenPixels>bluePixels)
            x=1;
        else if (bluePixels>redPixels && bluePixels>greenPixels)
            x=2;

        switch(x)
        {
            case 0:
                printf ("The subject is red");
                imshow("frame",red);
            break;

            case 1:
                printf("The subject is green");
                imshow("frame",green);
            break;

            case 2:
                printf ("The subject is blue");
                imshow("frame",blue);
            break;
        }


        int key = cv::waitKey(1);   // Wait 1ms for a keypress (required to update windows
        key = (key==255) ? -1 : key;    // Check if the esc key has been pressed
        if (key == 27)
            break;

    }

	destroyAllWindows();

    return 0;
}
