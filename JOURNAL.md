---
Title: "Wearable 5 axis Robotic Arm"
author: "Yugang Yao"
description: "Fully custom stepper motor robotic arm you can wear on your back, operating like a fully controllable third arm by interacting with a GUI."
created at: 2025-7-4
---

05/15/2025 project statement and planning

I have an idea!

Problem statement: Two arms can get everything done. But a third one can be nifty, huh? Even if it’s for simple applications, it can still be vastly useful. What if you’re holding everything in your two arms, and you need to open a door? What if you are typing and want to get a glass of water to your lips without breaking momentum? What if, possibly, you are performing a surgery and need some assistance? What if you’re doing some sort of combat sport, and want to get a bit creative? What if you just wanna show off at parties?

Objectives: wearable Robotic arm that follows the following specifications:  

5 degrees of freedom: wrist, elbow, shoulder roll, shoulder pitch, gripper. 

Graphical User interface that controls arm movements.

minimum payload 100-300 g

Angular accuracy: +/- 2-3 degrees with high-resolution servos or steppers+encoders

Position repeatability: 1-2 mm at full reach. Depends on backlash and compliance

Backlash: <0.5mm. Use zero backlash gearboxes or direct drive.

Delay must be <=500 ms from user input to motor response.

 Should stay relatively still when “attached” to the user’s back
 
Should have a safety mechanism so the user doesn’t get shocked by the 24v battery

I may use the local college’s lab to get some cheap hardware. I doubt they have the exact parts, but they may potentially have potentiometers, resistors, capacitors, Microcontrollers, etc. 

PLANNING:

VNH5019 modules for motor driving have already been designed and are available for $15-20 a pop. You see, we’re kinda budget-tight, so we’re going to design a PCB with 4 of the bare VNH5019A-E ICs–$5 each– to attach to our Maxon EC-i 40 + GP 10 A gearbox. Also note that the VNH5019 only drives brushed motors.

5/16/2025, Stepper motor possibility (but a few hours later)

The brushed DC motor mentioned earlier is gonna set us back 120 dollars each. We can use a NEMA 23 stepper motor with a large gearbox ratio for the desired torque output instead. Currently thinking 20:1, but I’ll have to see a more experienced engineer later to see if that is possible. Because stepper motors kinda can’t be run using the VNH5019, we’ll instead look into the possibilities of the TMC2226 motor driver. 

Update: We’re going with the NEMA 23 stepper motor with TMC 2226 motor driver

Possibilities of using in revision:
1. harmonic/planatery reducer for motors to extract highest torque instead
2. Using encoders (AS5600, AS5048A) instead of potentiometer for position feedback. Can be a bit more expensive, and we’ll have to learn some things. 

