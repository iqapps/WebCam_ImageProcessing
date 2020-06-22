# WebCam_ImageProcessing

This code is heavily based on code from David Barr, aka javidx9, �OneLoneCoder 2019

Here's a bit of the introduction comments from the mainfile WebCam_ImageProcessing.cpp

8-Bits Of Image Processing You Should Know
	"Colin, at least you'll always get 700s now..." - javidx9
	License (OLC-3)
	~~~~~~~~~~~~~~~
	Copyright 2018-2019 OneLoneCoder.com
...

Why ?

I have 40+ year of programming, starting from assembler of the 6502 that was used for a product, 
an IBM third party SNA protocol converter, and personally the 8081 that was inside the
Sinclair Spectrum.

I have, through the years, worked professioally with each of the following languages for at least 5 years:

Assembler, Perl, Unix BSD Shell, Visual Basic, Delphi, Javascript, C# and more.

Languages i have avoided on purpose are Phyton, PHP, C and C++. Phyton and PHP are terrible in structure,
but it is quite impressive what can be made with phyton, but this still dont make it attractive to me.

But C++ is the latest language I am learning by this time. I need it to make PLC projects, based on
Arduino mostly. So I need to learn more quirks of C++ to make my work better.

So...I look on youytube for C++...and find mostly uninteresting videos about learning C++ etc.

But I also found jarvidX9, and caught interest immediately because of the hands-on and nice presentation.

Please, keep them coming David.

I immediately subscribed and watched quite a few of the videos from him. But the 8 bit of image processing
video was the one that really caught my interest.

I downloaded the fantastic work by David Barr, and have now added a kind of plugin system so 
image processors are individual and pluggable.

I wanted the image processors to be added after each other, so their input and output must of course
be piped somehow. Also as the processors maybe need previous frame etc, these frames must be local to
the individual processor.

As a user, with this code running, you can:
* Add one processor after another using the ENTER key or you
* Delete the last added with the DEL key.
* The last processor is selectable from all available using the PGUP and PGDN keys.
* The last added processors parameters, can be edited with the arrow keys, while viewing the image change.

As a developer you add new image processors by:
* copy an existing processor file
* Replace the name throughout the file
* Replace the image processing code
* Add the processor with #include at the top of the main cpp file

Thats it.

Have fun...
