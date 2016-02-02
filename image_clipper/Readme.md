Image Clipper
-------------

This is a fork of the [imageclipper](https://code.google.com/p/imageclipper/) program that was originally created by Naotoshi Seo.

This fork was written originally for Team 4918 so we could easily compile all of our vision processing related software using Visual Studio 2016, instead of using tools such as CMAKE. You can either com

From the original description:

> It is often required to crop images manually fast for computer vision researchers
> to gather training and testing image sets, e.g., cropping faces in images.
>
> This simple multi-platform (Windows, OSX and Linux were verified) software helps
> you to clip images manually fast.

## Compiling Prerequisites
To compile, you'll need the following dependencies installed:
1. Visual Studio 2016 Update 1. We've only tested compiling the program on Enterprise Edition, but it should work on Community Edition.
2. Boost (We successfully compiled with boost 1.60.0). If you don't want to use Sourceforge (I don't blame you) you can use the Juxtapose Installer for boost located in the Roboctovision repository.
3. OpenCV 2.4.11. We were unable to compile with version 3, so if someone knows how to do this feel free to tell me how.

## Preparing For Compiling
1. Install OpenCV 2.4.11 to C:\OpenCV (You can install it somewhere else but you'll have to change the reference path in the visual studio project.
2. Install Boost to C:\Boost using the Juxtapose Boost installer (or the sourceforge zip folder if you like causing yourself pain)
3. The next step is to build Boost's libraries so Visual Studio can access them. Open up the visual studio command prompt and CD to C:\Boost. Then run the command bootstrap. This will execute a batch file that will prepare Boost to be compiled. After that batch file runs, run the command b2 to compile boost. This could take awhile, so go downstairs and talk to your family or something.
4. You're now ready to compile Image Clipper!

## Compiling Image Clipper
1. Open up image_clipper.sln in Visual Studio 2015.
2. In Visual Studio's build settings, make sure that your branch is set to "Release" and your platform is set to "x86". We didn't include the .64 libraries by default, but you shouldn't need the x64 version anyway.
3. After you've double checked the settings, go ahead and hit the big green compile arrow next to the build settings. Your compiled exe will be in a folder called "Release" that's located in the src directory.
4. The last step is to copy the required DLL files from OpenCV to the release folder. Go to C:\opencv\build\x86\vc12\bin and copy the following files: "opencv_core2411.dll", "opencv_highgui2411.dll", and "opencv_imgproc2411.dll".

## Running Image Clipper
Running Image Clipper is easy: simply drag your image onto the exe file in windows explorer and it'll open it automatically!