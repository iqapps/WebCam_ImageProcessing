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

I have through my 40 year worked professioally with each of the following languages for more than 2 years:

Assembler, Perl, Unix BSD Shell, Visual Basic, Delphi, Javascript, C# and more.

Languages i have avoided on purpose are Phyton, PHP, C and C++. Phyton and PHP are terrible in structure,
but it is quite impressive what can be made from phyton, but this still dont make it attractive to me.

But C++ is the latest language I am learning by this time. I need it to make PLC projects, based on
Arduino mostly. So I need to learn more quirks of C++ to make my work better.

So...

I downloaded the fantastic work by David Barr, and have now added a kind of plugin system so 
image processors are individual and pluggable.

As a user  you can add one processor after another and delete the last added also.

The last processor is selectable from all available, and its parameters can be edited with
the keyboard, while viewing the image change.

As a developer you just copy a processor file, replace the name, replace the image processing code,
and add the processor with #include at the top of the main cpp file. Thats it.

Have fun...
