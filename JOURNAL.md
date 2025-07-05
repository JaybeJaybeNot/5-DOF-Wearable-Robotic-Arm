---
Title: "Wearable 5 axis Robotic Arm"
author: "Yugang Yao"
description: "Fully custom stepper motor robotic arm you can wear on your back, operating like a fully controllable third arm by interacting with a GUI."
created at: 2025-7-4
---

<code style="color : name_color">05/15/2025 project statement and planning</code>

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

6/18/2025
Break: Heart project
All that planning for the Robotic arm project is stressing me out. So we’re gonna take a break and make a PCB with LED lights in the shape of a heart, lighting up in sequence. This is the schematics I made. 
Utilizes 2 IC’s:  555 timer to send clock signals in astable mode, and DC4017 to “chase” LEDs in a sequence. Powered by 3 coin batteries, of course. 
<img width="1015" alt="Screenshot 2025-07-01 at 11 36 05 AM" src="https://github.com/user-attachments/assets/4e5c8cf4-46d5-44bd-8911-38d7d5a51a0b" />

I’ll either add this to the robotic arm, or give it as a trinket to my friend. They gave me a heart keychain a few months ago. Regardless, I’ll make the PCB layout for this in my next break. 

I can also possibly modify the design to make it act as an error tester later on the road. 

**1 hour**

6/22/2026

We’re on vacation, so progress is slow. A wrist-mounted control panel for the arm would be cool as hell, no? We’ll probably have to take on even more disciplines though… Like Embedded UI, power management, and probably ergonomics. Bluetooth for communication, maybe a charge controller for safety, a TFT LCD for affordability and durability, and a MCU for the spi communication; Perhaps an ESP 32 would suit the application. I’ll add this as an idea for next iterations of the arm.

The design for the PCB with the TMC2226-SA motor driver has been commenced, and will probably finish by the end of the day. Moving on next, we’ll figure out the programming and software, and where we can get the mechanical design for the arm. We’ll also tinker around with ROS2, and use Gazebo for simulation (let’s also copy paste the URDF files for the actual arm). My old computer has Ubuntu installed, so let’s do that. 

We can potentially use the 24V battery volt source to power the Nano by using a LM2596 voltage regulator.


Today’s progress (Elbow joint driver and MCU):
<img width="1275" alt="Screenshot 2025-06-27 at 9 21 26 PM" src="https://github.com/user-attachments/assets/9af2c4d6-12c4-4563-8e5a-cb7436273cb4" />

**3 hours**
7/1/2025
Just came back after climbing Mount HuangShan, it was peak (ahahaha).

Anyways, gonna crank out the basic PID code for the arduino nano and for driving the NEMA 17. Honestly, I am quite inexperienced on implementing PID, even though I know alot about the theory. 

I work in bursts anyways, so hopefully I can get most of it done today.
Today’s code:

<img width="501" alt="Screenshot 2025-07-04 at 8 53 39 AM" src="https://github.com/user-attachments/assets/b23884c0-7346-4f23-baf1-be92a8b5a778" />
**3.5 hours**

7/2/2025 
Further project planning + parts selecting

Ok, so, we’re gonna keep the pcb Designs, but there will no longer be any centralized PCB (like as if it’s a critical hit area in a video game). Essentially, the drivers will be placed right next to the motors in the form of small PCB’s, with terminals connecting from the base, which houses the MCU, voltage regulator, and whatnot. Wait, so the 24v power supply to the motors will have a long wire too? I wonder if that’ll introduce even more problems.

To offset this, we’ll make the power supply slightly larger than 24V to compensate for the higher resistance (26v, 28v). We’ll also add a bulk cap (100-470 uF) decoupling capacitor as well as a ceramic cap (0.1-1uF).  right next to Vin of Drivers, as well as ferret beads on the power supply line right before the driver. This is a pretty crude, unelegant method but it’ll probably be enough.

Main reason we’re still using our own design for the motor drivers is because they’re lowk expensive ($30+) and too big to fit in the joints.

Final decision:

Main PCB will sit at base of robotic arm, containing the STM32 Bluepill (STM32F103C8Tx); 2 motor drivers for shoulder yaw and shoulder pitch; and a voltage regulator connected to 24v power source. Elbow joint will have their own motor driver for the TMC2209 NEMA 17

Tmc 2209-LA info:
Footprints and symbol
Datasheet
Finally decided on the specific models:
Nema 17
Nema23
(There are links to these in the original doc)

Reminder, Driver compatibility is about matching current, voltage, and inductance to the driver’s chopping frequency and thermal rating!
Thus, the TCM2226-SA will be used to drive the NEMA 17, while the dual TCM2209-LA will be used to drive the NEMA 23. 
Today's schematic progress (so far):
<img width="920" alt="Screenshot 2025-07-04 at 8 57 01 AM" src="https://github.com/user-attachments/assets/2d6e2721-bcf6-4e3b-b4f0-f074e5bf5a18" />


Iteration for Mark II:
Just watched 稚晖君’s video on his dummy robotic arm, and felt kinda envious when compared to my own design. Thus, I have a wishlist for Mark II in case I build a second robotic arm:
CAN bus
Per-joint MCUs
Force sensors
(Encoders instead of potentiometers)
Sleeker driver IC layouts
Smarter GUI
Power optimization
AI vision 
(optional) glove to control robotic arm movement

For now, we just need to worry about making A robotic arm. 

Taking notes on TMC2209 driver features:

Stealthchop: Silent operation, good for lower velocities

Significantly improved microstepping with low-cost motors - Motor runs smooth and quiet - Absolutely no standby noise - Reduced mechanical resonance yields improved torque

Spreadcycle: Good for higher velocities.


After a few hours, I have finished the schematic FULLY, and have reviewed it to have no errors (so far, I will review it once more when I prepare for PCB layout). Here is the full schematic:<img width="891" alt="Screenshot 2025-07-04 at 2 53 10 PM" src="https://github.com/user-attachments/assets/eb6d9896-19d0-4605-a6ab-b803f6b9ad29" />

I should probably add redundancies for overheating, since running all these on the same PCB will fry it easily. But I feel like moving on to software for now, so that’ll have to wait until I prepare for the PCB layout.

Btw ignore PB5. I've already removed that label; it's just a small error.


**8 hours total**


