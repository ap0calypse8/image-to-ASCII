## Image to ASCII
This is a simple C++ program that converts an image into ASCII art. The program reads an input image, processes it, and generates ASCII art based on the intensity of the pixels in the image.
## Input Image
![](https://www.haydnsymons.com/wp-content/uploads/2019/01/girl-with-a-pearl-earring.jpg)
## Output ASCII Art
![](https://github.com/ap0calypse8/image-to-ASCII/blob/master/outt.png)
## Features
- Converts images to ASCII art
- Supports different ASCII characters for red, green, and blue channels
- Allows customization of ASCII character sets for better output clarity
## Dependencies
- OpenCV: This project requires OpenCV library to read and process images.
## Installation
1. Clone this repository to your local machine.
2. Make sure you have OpenCV installed. If not, you can install it using your package manager or download it from the official OpenCV website.
3. Compile the `main.cpp` file using a C++ compiler.

## Usage
1. Run the compiled executable.
2. Provide the path to the input image when prompted.
3. The program will process the image and display the corresponding ASCII art in the console.

## Customization
- You can customize the ASCII characters used for the red, green, and blue channels by modifying the `redASCIIChars`, `greenASCIIChars`, and `blueASCIIChars` strings in the code.
- Adjust the desired width and height of the output ASCII art by modifying the `desiredWidth` and `desiredHeight` variables in the code.

