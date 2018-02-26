# Arduino-On-Ramp-Class
Resources for beginners Arduino/microcontroller class
ARDUINO ON RAMP
Go from ZERO to ONE learning to use the Arduino environment to build electronics projects. Class will review development boards, software and basic electronic components while walking the group through a project.


The goal of this class is to introduce a beginner to the world of micro-electronics' development boards,
get you started with the software, a discuss how to control a few components, put together a straight forward project,  and highlight a few available resources so that each participant has some direction on next actions they can take to learn more, build more, connect more when they leave.

Prerequisites:  1) Bring Own laptop.  No Chromebooks.  
2) Download Arduino IDE: 
go to https://www.arduino.cc/en/Guide/HomePage
Scroll down to "Install the Arduino IDE"
Click on whichever operating system you have: Windows, Linux, Mac
Follow step by step directions
3) download files for this class

Video examples of project - Intruder Alarm!
Blue:  https://youtu.be/giVNOM73hOc
Red:  https://youtu.be/Gdnnvital-8

INTRODUCTION
	Welcome to the Arduino On Ramp class.  We’re going to work on the example project from the video where we use a microcontroller, an Ultrasound sensor to detect something close to the sensor and then respond with an alarm sound and flashing lights.   The focus is going to be on the basics of using the Arduino environment, so everyone will get the software installed, we’ll review how to get the programs into the software, how to download libraries, how to load the program on your board.  Each of three components of this project will be reviewed a little and you’ll be provided a basic program for each so that you can play with it later on your own.  We will review some basic electronics concepts, talk about the components available for microcontrollers, talk about breadboards and discuss your Uno in a little more detail.  Finally, we’ll review your Intruder Alarm as a project  for it’s strengths and weaknesses, discuss other projects you might be interested in and make available some resources so that you can further your learning.
What do you know about Arduino?  Who has worked with one before?
We will be using an Arduino Uno board “clone”.  It is the basic, standard Arduino board and it’s good introduction to the environment.  What you are really being introduced to is the world of development boards and there are hundreds.  A development board is going to be a electronic circuit board with a collection of components that serve the purpose you want them to.  The board will have at least one microprocessor chip, a small amount of memory to store a program and some values, inputs, outputs, a way to program it, a power source.  Many companies produce them: Intel had an Edison board, Texas Instruments makes a Launchpad, Lilypad makes small round wearables, Beagle Bone makes boards, Micro:bit makes boards, Adafruit makes boards, there are mega boards with more memory and more pins, there are tiny boards with smaller power efficient chips and their are ones which are teeny enough you could make a little watch to wear on your wrist.  Many of these are manufactored and sold to hobbiests, as are the sensors and outputs and the whole ‘industry’ has really grown in the last 10-20 years, along with 3-D printing and the whole Maker movement.  They are also used by professionals for prototyping and sometimes in finished commercial products.    Arduino has been a big part of that.
	The Arduino website describes itself as an electronics platform.  The platform has three major aspects.  The first one is the board.  As noted above there are lots of similar and some better boards.  A group of developers got together, selected a chip that was pretty fast but cost efficient, decided what components and parts a general board might need, added lots of connectors and an uncomplicated way to upload programs - the usb cable. The second aspect was the Arduino software, called the Arduino IDE - Integrated Development Environment.  They created some software and made it available to anyone who wants to download it for free.  In the IDE you can write programs, edit programs, upload programs, monitor programs that are running.  The software runs on Windows, Macintosh, and Linux operating systems.  You can import special libraries and access lots of example code - all free and all within the IDE.  The Arduino code is their own version of C++ which they call Arduino code.  Traditionally, code for imbedded circuits was written in the C or C++ programming languages.  The Arduino IDE will compile code written in C++, but it also does some things behind the scenes specific to the Arduino modifications.  This class isn’t going to teach you programming, but there are lots of free online resources to learn programming.  Most of them teach the basics of computational thinking.  Most do not teach C++, but you can learn the fundamentals.  The third aspect about the Arduino that really established it is that it is open source hardware and software.  The term ‘open source’ packs a lot of meaning, but basically all of the source code for the software and the plans of the actual boards are published online.  Hackers can hack them, hobbiests can even build their own, developers can modify them for their projects and products.  They’ve managed to grow a huge community of Makers and learners who contribute to online resources.  So even though there are lots of boards and languages and IDE’s to chose from, this is a good one for a beginner because there are so many resources available to get help and assistance.  Lots of other people posting their projects and making the code available.  Our project today is a modification of one that someone posted online. 
Many people have heard about a little computer called a Raspberry Pi.  For a while, there were some limitations controlling some of the microprocessor sensors with Raspberry Pi, but people are figuing out how to do that now.  A Raspberry Pi is actually a full computer - you can attach a monitor, keyboard, mouse and upload a full operating system that will run a web brower and graphic interface.  The Arduino doesn’t work like that...here, we’ll upload one program and the board will just keep running that one program.  We can change the program and upload the changes.  We can upload a completely different program, but it’s one at a time, one program running over and over.  The Raspberry Pi computer runs many programs, lots of software, the programs communicate with each other, and it’s a whole system with memory.  Big difference, but since the Raspberry PI’s are small and cheap and can run all this other software...more and more people are using them in their projects.    
So, that’s our plan.  Use some sensors, set up an circuit, control it with a program...and along the way learn how we can use the Arduino to create our own projects.


Bring example boards
-resources, handouts, How can we mod this project?  Motion sensor alarm with flashing LEDs?https://www.makeuseof.com/tag/how-to-make-a-simple-arduino-alarm-systemWhat other inputs could we use?  What other outputs?  How about design/case? What projects are you interested in building?  Do you have any ideas
for a different project for this level of class?  Would you be interested in an intermediate level class?

Resources:
Arduino
Adafruit
Element 14
Online programming: GAtech, Udacity, Python for everyone, Edx, Cousera
Codeschool?
Instructables
Make Code
ONline simulatiors - tinkercad
Sparkfun
Microbit

BREAK OUT: CIRCUITS AND COMPONENTS

I = VR
Resistance, current, voltage
Electrons
Resistors, capacitors, diodes, LED’s, batteries, sensors
Discuss the ultrasound sensor - sample code

BREAK OUT: IDE AND SOFTWARE
Download IDE
	The Arduino website has all the instruction needed to get your software installed.  Go to
https://www.arduino.cc/
and on the top horizontal index hover over “RESOURCES” and click on “Getting Started”.  Scroll down to “Install the Arduino Desktop IDE”.  Choose your operating system.  This software works with Windows, MAc’s, and Linux but not with Chromebooks.  Each section gives instructions for downloading and installing the IDE.  Next, return to the getting started page and you will see a menu on the right side of the page.  Under “Instructions for Boards”, find the “UNO” and click on that.  We are going to be using an UNO clone in this class.
	Depending on your operating system, you may need to install drivers (Windows) or enable serial ports (Linux).  The instruction on the Arduino site walk you through all of this.
Install libraries
Board and port
Download programs
Review Piezo buzzer - smple code

BREAK OUT: ARDUINO UNO AND BREADBOARDS
Discuss different parts of the board
Discuss how breadboards work
REview neopixels, power requirements, libraries - sample code

GROUP WRAP-UP

Install Intruder code
Discuss areas to modify ( US, LED’s, PIEZO)

