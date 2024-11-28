#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

// Function to map pixel intensity to an ASCII character
char pixelToAscii(int pixelValue) {
    const string asciiChars = "@%#*+=-:. ";  // Characters from dark to light
    int index = (pixelValue * (asciiChars.size() - 1)) / 255;
    return asciiChars[index];
}

// Function to convert the video frame to ASCII
void frameToAscii(const Mat& frame, int width, int height) {
    Mat resizedFrame;
    // Resize the frame to fit the ASCII output size
    resize(frame, resizedFrame, Size(width, height));

    // Convert the frame to grayscale
    cvtColor(resizedFrame, resizedFrame, COLOR_BGR2GRAY);

    // Iterate over each pixel and convert to ASCII
    for (int y = 0; y < resizedFrame.rows; y++) {
        for (int x = 0; x < resizedFrame.cols; x++) {
            int pixelValue = resizedFrame.at<uchar>(y, x);
            cout << pixelToAscii(pixelValue);
        }
        cout << endl;
    }
}

int main() {
    // Open the video capture (0 for webcam, or replace with a video file path)
    VideoCapture cap("/path/to/your/video.mp4");
    if (!cap.isOpened()) {
        cerr << "Error opening video stream or file" << endl;
        return -1;
    }

    // Set the desired width and height for the ASCII output
    int width = 160;
    int height = 50;

    while (true) {
        Mat frame;
        cap >> frame;  // Capture a new frame
        if (frame.empty()) break;

        // Clear the screen (optional for cleaner output)
        cout << "\033[2J\033[H";

        // Convert and display the current frame as ASCII
        frameToAscii(frame, width, height);

        // Delay for a brief moment (adjust for better control)
        if (waitKey(30) >= 0) break;
    }

    cap.release();  // Release the video capture
    return 0;
}
