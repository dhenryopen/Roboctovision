#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

// Set the global variables
String object_cascade_name = "objectcascade.xml"; // Name your cascade objectcascade.xml and place it in the same folder as the exe
CascadeClassifier object_cascade;
String window_name = "Object Detection";

void detectObject(Mat frame);

int main(void)
{
	// Open the default camera
	VideoCapture cap(1);
	if (!cap.isOpened())
		return -1;

	Mat frame;

	// Load the cascade
	if (!object_cascade.load(object_cascade_name)) { printf("--(!)Error loading object cascade\n"); return -1; };

	while (cap.read(frame))
	{
		if (frame.empty())
		{
			printf(" --(!) No captured frame -- Break!");
			break;
		}

		// Apply the classifier to the frame
		detectObject(frame);

		// Close the program if escape is pressed
		int c = waitKey(10);
		if ((char)c == 27) { break; }
	}
	return 0;
}

void detectObject(Mat frame) {
	std::vector<Rect> objects;
	Mat frame_gray;

	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	// Detect the object based off of the cascade
	object_cascade.detectMultiScale(frame_gray, objects, 1.1, 2, 0, Size(80, 80));
	for (size_t i = 0; i < objects.size(); i++)
	{
		Mat faceROI = frame_gray(objects[i]);
		Point center(objects[i].x + objects[i].width / 2, objects[i].y + objects[i].height / 2);
		ellipse(frame, center, Size(objects[i].width / 2, objects[i].height / 2), 0, 0, 360, Scalar(255, 0, 0), 2, 8, 0);
	}

	imshow(window_name, frame);
}