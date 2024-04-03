#include <opencv2/core.hpp>
#include<string>
#include <opencv2/imgcodecs.hpp>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include<vector>

using namespace cv;


// convert pixel intensit to ASCII
char inttoascii(int intensity, const std::string& asciiVal) {

    int index = intensity * (asciiVal.size() - 1) / 255;
    return asciiVal[index];


}

int main()
{
    Mat img = cv::imread("C:\\imG\\images.jpeg"); //reading an imput img

    if (img.empty()) {
        std::cerr << "Failed to load image";
        std::cout << "\n";
        return EXIT_FAILURE;
    }

    imshow("input image",img);
    waitKey(0);

    GaussianBlur(img, img, cv::Size(5, 5), 0);

    int desiredWidth = 120; // Decrease desired width to make the ASCII art smaller
    int desiredHeight = static_cast<int>(desiredWidth * static_cast<float>(img.rows) / img.cols);


    // Resize the input image to match the desired aspect ratio
    cv::resize(img, img, cv::Size(desiredWidth, desiredHeight));


    std::vector<Mat> channels;
    split(img, channels);


    const std::string redASCIIChars = "@#mw&:-',. ";
    const std::string greenASCIIChars = "@#wm&%8B$*";
    const std::string blueASCIIChars = "@%#*+=-:. ";

    std::string art;

    
    for ( int i = 0; i < img.rows; ++i) {
        for (int j = 0; j < img.cols; ++j) {
            int redintensity = static_cast<int>(channels[2].at<uchar>(i, j));
            int greenintensity = static_cast<int>(channels[1].at<uchar>(i, j));
            int blueintensity = static_cast<int>(channels[0].at<uchar>(i, j));
            char redASCII = inttoascii(redintensity,redASCIIChars);
            char greenASCII = inttoascii(greenintensity,greenASCIIChars);
            char blueASCII = inttoascii(blueintensity,blueASCIIChars);

            char artChars = redASCII > greenASCII ? (redASCII > blueASCII ? redASCII : blueASCII) : (greenASCII > blueASCII ? greenASCII : blueASCII);
            art += artChars;
        }
            art += '\n';

    }

    std::cout << art;
    std::cout << "\n";
    

    return EXIT_SUCCESS;
}