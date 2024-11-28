# Video to ASCII Converter

This project is a **C++ application** that converts videos into ASCII art and displays them in the terminal. It uses **OpenCV** for video processing.

## Features

- Converts any video file into ASCII art.
- Supports customizable terminal dimensions for better resolution.
- Compatible with various video formats supported by OpenCV.

## Requirements

- C++17 or later
- OpenCV 4.x installed
- A terminal that supports ANSI escape codes

## Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/video_to_ascii.git
   cd video_to_ascii
2. Make sure OpenCV is installed on your system. You can install it using:
   ```bash
   sudo apt install libopencv-dev

3. Compile the program:
   ```bash
   g++ -o video_to_ascii main.cpp `pkg-config --cflags --libs opencv4`

## Usage 
1. Run the program with a video file as input:
   ```bash
   ./video_to_ascii /path/to/video.mp4
2. Adjust your terminal width and height for optimal ASCII rendering.
   
## Customization
You can modify the ASCII character set and resolution in the code to tweak the output quality. The default ASCII character set ranges from light (.) to dark (#).

## Troubleshooting
• If your video plays too fast, ensure the delay in the frame display matches the video’s FPS.
• If the program can't find the video file, ensure the path to the file is correct and accessible.

