---
Title: "Wearable 5 axis Robotic Arm"
author: "Yugang Yao"
description: "Fully custom stepper motor robotic arm you can wear on your back, operating like a fully controllable third arm by interacting with a GUI."
created at: 2025-7-4
TOTAL HOURS: 50 Hr 15 Minutes (Not including time spent planning, debugging, or reading datasheets because I didn't record them)
---

$${\color{white}06/15/2025 \space project \space statement \space and \space planning}$$



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

$${\color{white}5/16/2025}$$

Stepper motor possibility (but a few hours later)

The brushed DC motor mentioned earlier is gonna set us back 120 dollars each. We can use a NEMA 23 stepper motor with a large gearbox ratio for the desired torque output instead. Currently thinking 20:1, but I’ll have to see a more experienced engineer later to see if that is possible. Because stepper motors kinda can’t be run using the VNH5019, we’ll instead look into the possibilities of the TMC2226 motor driver. 

Update: We’re going with the NEMA 23 stepper motor with TMC 2226 motor driver

Possibilities of using in revision:
1. harmonic/planatery reducer for motors to extract highest torque instead
2. Using encoders (AS5600, AS5048A) instead of potentiometer for position feedback. Can be a bit more expensive, and we’ll have to learn some things. 


$${\color{white}6/18/2025}$$


Break: Heart project
All that planning for the Robotic arm project is stressing me out. So we’re gonna take a break and make a PCB with LED lights in the shape of a heart, lighting up in sequence. This is the schematics I made. 
Utilizes 2 IC’s:  555 timer to send clock signals in astable mode, and DC4017 to “chase” LEDs in a sequence. Powered by 3 coin batteries, of course. 
<img width="1015" alt="Screenshot 2025-07-01 at 11 36 05 AM" src="https://github.com/user-attachments/assets/4e5c8cf4-46d5-44bd-8911-38d7d5a51a0b" />

I’ll either add this to the robotic arm, or give it as a trinket to my friend. They gave me a heart keychain a few months ago. Regardless, I’ll make the PCB layout for this in my next break. 

I can also possibly modify the design to make it act as an error tester later on the road. 

**1 hour**


$${\color{white}6/22/2026}$$


We’re on vacation, so progress is slow. A wrist-mounted control panel for the arm would be cool as hell, no? We’ll probably have to take on even more disciplines though… Like Embedded UI, power management, and probably ergonomics. Bluetooth for communication, maybe a charge controller for safety, a TFT LCD for affordability and durability, and a MCU for the spi communication; Perhaps an ESP 32 would suit the application. I’ll add this as an idea for next iterations of the arm.

The design for the PCB with the TMC2226-SA motor driver has been commenced, and will probably finish by the end of the day. Moving on next, we’ll figure out the programming and software, and where we can get the mechanical design for the arm. We’ll also tinker around with ROS2, and use Gazebo for simulation (let’s also copy paste the URDF files for the actual arm). My old computer has Ubuntu installed, so let’s do that. 

We can potentially use the 24V battery volt source to power the Nano by using a LM2596 voltage regulator.


Today’s progress (Elbow joint driver and MCU):
<img width="1275" alt="Screenshot 2025-06-27 at 9 21 26 PM" src="https://github.com/user-attachments/assets/9af2c4d6-12c4-4563-8e5a-cb7436273cb4" />

**3 hours**

$${\color{white}7/1/2025}$$


Just came back after climbing Mount HuangShan, it was peak (ahahaha).

Anyways, gonna crank out the basic PID code for the arduino nano and for driving the NEMA 17. Honestly, I am quite inexperienced on implementing PID, even though I know alot about the theory. 

I work in bursts anyways, so hopefully I can get most of it done today.
Today’s code:

<img width="501" alt="Screenshot 2025-07-04 at 8 53 39 AM" src="https://github.com/user-attachments/assets/b23884c0-7346-4f23-baf1-be92a8b5a778" />
**3.5 hours**


$${\color{white}7/2/2025}$$

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


$${\color{white}7/6/2025}$$


Ok, platformIO is acting up.
Not only did I lose the Main.cpp file for the main PCB board, but I literally can’t find the folder itself. The folder is also nowhere to be seen on the project tab of VScode. 

So, we’re gonna ditch platformIO for STM32CubeIDE.

Hip hip hooray! We get to rewrite the ENTIRE code for the main PCB, but this time in HAL =D! I can’t WAIT to basically learn a whole different language =DDDDDDDD. 

Just played around with STM32cubeIDE for a while, and learned from guides/documentations on youtube. Phil’s Lab my GOAT fr

<img width="453" alt="Screenshot 2025-07-06 at 4 02 45 AM" src="https://github.com/user-attachments/assets/636b0ca5-89ad-4304-81e2-7a24d0472c74" />


Ran into some problems with the clock configurations, seems like the APB1 peripheral clock frequency is too low. 

<img width="783" alt="Screenshot 2025-07-06 at 4 02 58 AM" src="https://github.com/user-attachments/assets/4b1cb971-4f16-4976-8131-b0a8ee446c8b" />


After some tweaking and painfully reading the STM32F1 reference manual, this minor speedbump has been remedied. 

<img width="303" alt="Screenshot 2025-07-06 at 4 03 08 AM" src="https://github.com/user-attachments/assets/d12c5c5a-0b27-4c57-9a21-75a65df2ccba" />

Pins are configured, and so are the clocks. Now all we have to do is figure out how to set the STM32 up to receive serial from the Mac, what to do with certain info, and create the GUI. Finally, we’ll create the 3D physical model and we’ll be done. 

**3 hours**

Note: Kinda been dodging a core problem right now, but we gotta confront the fact that carrying around a 24v battery can kinda cause some lowkey agonizing pain if something goes wrong. So we'll have to overload on safety mechanisms when we get to mechanical design. We'll also have to make additions on our PCB to further prevent overheating

$${\color{white}7/17/2025}$$

Just came back from camp, back to the grind. This also means we’ll have to ramp up productivity. A review of the arm:
Shoulder 
1. will have 3 D.O.F.
2. 2 NEMA motors will be driven by main PCB,
3. 3rd one will be driven by Arduino Nano interfaced via I2C 
STM32F1 will be master MCU. We have 48 MHz of processing power and we will use the full 48 MHz of it!
4.Power source: 24 volts, will be placed in a heavily insulated box to prevent shocks
Elbow:
A singular Arduino nano and TMC driver for Nema 17. 
Further iterations might utilize belts to lower torque on elbow
Wrist: Simple MG90 servo. Just use PWM vro 
GUI: will be built in tkinter. Interfaces with the Uart serial to STM32. 
Alright, today we’ll get serial done, and begin on the mechanical design.

This means we'll gonna have to LEARN UART programming, including HAL and serial parsing. Here's the code so far: <img width="528" height="536" alt="Screenshot 2025-07-18 at 9 26 53 PM" src="https://github.com/user-attachments/assets/4b115ff0-7a87-4e16-884a-a468cc88c19a" />

**5 Hours**
 

$${\color{white}7/23/2025-7/25/2025}$$



I have chipped down the DRC more and more on clearance violations, and have connected the pins together finally. We have decided to use GND and power planes for noise and emi reduction, though it will be a bit more expensive. 

We have also finally added PCBway constraints into the settings. Thus, we’ll have to switch from 0402 components to larger ones, because lowk they’re unable to tolerate the close proximity of the components. 

<img width="479" height="574" alt="Screenshot 2025-07-26 at 5 03 54 AM" src="https://github.com/user-attachments/assets/6d06d034-5781-4100-8d05-bf24142a450b" />


<img width="466" height="579" alt="Screenshot 2025-07-26 at 5 04 09 AM" src="https://github.com/user-attachments/assets/015a4279-7657-423b-b9db-b4eabddb3378" />


We WILL add heat pours in the future—after finishing the DRC.

I have also met with a longtime friend, a Umich alumni in robotics about this design. he says it’s good so far, so that’s something to think about =].

**12 hours**

May seem like a long time, but trust me, I haven’t done something this complex before so I MUST make sure everything runs as good as possible. 

$${\color{white}7/26/2025}$$


Yayyyy, mechanical design! Woohoo, Yippee.

Constraints:

1. 0.5-1 meters

2. 2 kg payload minimum.

3. Fully covering circuitry

4. Openable via screws to access circuitry and wires

5. Separate compartment for wires and circuitry

6. Hexagonal comb design. Will have one side honeycomb, the other three sides will be solid

7. 25:1 gearboxes, compromise for torque and speed

8. 7075 or 6061 aluminum for linkages. More Carbon fiber towards end of arm. Steel for joints and base.

9. Planetary gearboxes for zero backlash if we can afford it (probably not for the first design. May be employed for future iterations )

10. Modular end factor for different attachable functions. Module will have plugs that attach to end factor to communicate to a microcontroller on what to do. Will also have latches to maintain connection.

Alright, let's get started.

The specs are as follows: shoulder (base) will have 3 degrees of freedom to mimic actual human arm. Will contain the main PCB, alongside slave MCU PCB to drive the additional motor. The motors will all be NEMA 23s.

The elbow joint will be 1 D.O.F. and uses arduino nano + TMC2226SA for the Nema 17. Will also interface with main PCB. Only comment lightly on the fact that we're using I2C protocol for the ~.33m distance between the main mcu and slave mcu.

The wrist will use SG90S microservo. Optional, actually.

Link length from** shoulder joints to elbow joint will be .33 m**. From** elbow to wrist is .46 m.**

All 3 shoulder motors will be placed closely together at the base to reduce torque

**Joints decisions:**

1. Shoulders:

1. Options:

1. Welded Pivot Bracket joint.

1. Pros:

1. extremely strong and rigid,

2. zero backlash.

2. Cons:

3. Permanent. Make a mistake? Womp womp, you can’t fix it.  You also can’t take them out, so they’re not modular

4. You kinda need to know how to weld, and get welding equipment (DEALBREAKER)

2. **Bolt on bracket system (WE’RE USING THIS ONE)**

3. Pros:

5. Still pretty strong

6. Bolted, not welded (NOT DEALBREAKER)

7. Looks pretty clean

2. Elbow:

2. Clevis + Pin Joint.

3. Pro:

4. Can be laser cutted

5. Pretty compact

6. Strong enough

7. VEX robotics people use it

4. Con:

8. Need retainer clips or shoulder bolts

9. **Needs TIGHT tolerances**

Let’s not talk about end effector for now.

Of course, we’ll also need:

1. Bearings

1. 10 mm bore, 26mm OD Flanged bearing

2. Shaft link hub / coupler

3. Shaft collar

4. Mounting brackets or housing to hold bearings in place and constrain all movements except rotation

2. One side must hold rigidity, (bearing pocket or press-fit)

5. Spacer(s) and Shoulder Bolt / Axle Bolt

3. Prevents axial shrifting, keeps rotations smooth

4. Space prevents the bearing from rubbing against joint arm or frame. Shoulder bolt has a section that fits bearing ID perfectly.

We’ll mount the Nema 17 at elbow. But if we NEED to optimize torque, then we can just place them at the back with a belt loop.


rectangular holes are probably for ventilation and weight \; we’ll employ that.

**1 Hour**

**7/27/2025**

Mechanical design marathon.

Aluminum 6061 is very expensive, [datasheet](https://asm.matweb.com/search/specificmaterial.asp?bassnum=ma6061t6) . So here’s the plan:

1. At the base, we’ll use some sort of steel alloy. Cheaper, but 3 times the density

2. Aluminum 5052 could be a substitute.

I feel the plan right now is model a rough diagram of the arm on paper, create a multidimensional function of stress, strain, load, and torque in terms of density of the material selected, and the width/girth of the arm. THEN we'll choose the components based on our application.

Alright, we’ve finished the analysis of the arm at it’s worst scenario: Perfectly horizontal.

<img width="507" height="696" alt="Screenshot 2025-07-30 at 5 43 59 PM" src="https://github.com/user-attachments/assets/7f07bb46-c8ee-4496-afdc-06cf655dd61a" />

**30 minutes**

Not gonna do other angles, because we’ve already accounted for worst case scenario. Also, it’s probably not likely that it’ll just collapse on itself if i raise it perfectly vertical even if the axial stress is at its strongest.

Time for parts selection!

Code for calculations:

import math

==== Inputs ====
Geometry (in meters)
L1 = 0.33      # Length of Link 1

L2 = 0.46      # Length of Link 2

w = 0.1     # Width of rectangular cross-section

h = 0.1       # Height (thickness) of rectangular cross-section

Material (Aluminum 6061-T6)
E = 68.9e9             # Modulus of Elasticity (Pa)

sigma_y = 276e6        # Yield Strength (Pa)

tau_y = 207e6          # Shear Strength (Pa)

fatigue_strength = 96.5e6 # Fatigue Strength (Pa)

Density = 2700 #kg/m^3

Masses (kg)
m1 = L1 * Density * w * h       # Mass of Link 1

m2 = L2 * Density * w * h       # Mass of Link 2

payload = 4200                 # force from punch or weight (Newtons)

Angle of payload force relative to the link axis (in degrees)
theta_deg = 0

theta = math.radians(theta_deg)

Safety Factor
FoS = 1.5

Gravity
g = 9.81  # m/s^2

==== Derived geometric properties ====
A = w * h                         # Cross-sectional area

I = (w * h**3) / 12               # Second moment of area

c = h / 2                         # Distance from neutral axis

==== Forces ====
P_parallel = payload * math.cos(theta) # Axial component

P_perp = payload * math.sin(theta)     # Transverse (bending) component

==== Torques ====
tau_elbow = m2 * g * (L2 / 2) + P_perp * L2

tau_shoulder = (m1 * g * (L1 / 2) +m2 * g * (L1 + L2 / 2) +P_perp * (L1 + L2))

==== Stresses ====
sigma_axial = P_parallel / A

sigma_bending = ((P_perp * (L1 + L2) + (m1 * g * L1/2) + (m2*g*(L1 + L2/2)))  * c) / I

sigma_total = sigma_axial + sigma_bending

AFoS = 276e6 / sigma_total

==== Strain ====
strain = sigma_total / E

==== Deflection ====
Tip deflection of link 2 under end load only
delta = (P_perp * L2**3) / (3 * E * I)

==== Checks ====
print("=== ROBOTIC ARM STRESS REPORT ===")

print(f"Axial Stress:      {sigma_axial/1e6:.2f} MPa")

print(f"Bending Stress:    {sigma_bending/1e6:.2f} MPa")

print(f"Total Stress:      {sigma_total/1e6:.2f} MPa")

print(f"Strain:            {strain:.5e}")

print(f"Deflection (L2):   {delta*1000:.2f} mm")

print(f"Elbow Torque:      {tau_elbow:.2f} Nm")

print(f"Shoulder Torque:   {tau_shoulder:.2f} Nm")

print(f"factor of safety:   {AFoS}")

print("\n=== SAFETY CHECK ===")

print(f"Yield Limit ({sigma_y/FoS/1e6:.2f} MPa) : {'Yessir!' if sigma_total < sigma_y / FoS else 'No =['}")

print(f"Fatigue Limit ({fatigue_strength/FoS/1e6:.2f} MPa): {'Yessir!' if sigma_total < fatigue_strength / FoS else 'No =['}")

print(f"Deflection Check (< {L2/250:.2e} m): {'Yessir!' if delta < L2/250 else 'No =['}")

We’ll play around with the variables until we find something desirable.

****15 minutes****

Ok so, it turns out that if we were to go with a 0.1 m x 0.1 m approximate cross sectional area of the arm using aluminum 6061, we’ll need 28 Nm of torque… Nema 17 can only produce 0.14-0.75 nm max. We’ll have to redo the PCB to change the Nema 17 to a Nema 23. On top of that, aluminum 6061 is frick-ton expensive even if hollow(~$200 for one link), so we’ll have to find other materials and compromise.

Material alternatives:

1. [Steel 1018](https://www.mwcomponents.com/uploads/Resource-Center/Elgin-Material-Sheets/Carbon-Steel-Grade-1018-Data-Sheet_Elgin.pdf?srsltid=AfmBOooK469iR5Xtp-ZQE9jj60D0VX96fD20AT3H7HLhAtuWL9PXZEUr)

1. 370 MPa yield

2. [A36 steel](https://www.ryerson.com/metal-resources/metal-market-intelligence/a36-steel-plate)

2. 248.2 MPa yield

Material selection later. Let’s just design the arm now.

We’ll begin with the joint, constraint definitions: \
1. Houses Nema 23 motor

2. Houses the gearbox along the Nema 23 motor

3. Rotate well

4. Holes for wires to connect with motor

There will be 2 type of joints; the shoulder joint, and elbow joint.

That’s basically it honestly

We originally considered HTD5 timing pulleys, but that’s too mechanically advanced for me. So we’re going to use **NEMA23 ****<span style="text - decoration: underline;">worm**</span>** gearbox (50:1)** as simple add ons to the motor. Cheaper than planetory, and we don’t need industrial level precision so we may get away with $150 total. 

[Nema 23 sizes](http://www.piclist.com/techref/io/stepper/nemasizes.htm)

*Just learned the method is called a **Euler angle joint** chain mimicking the **glenohumeral (shoulder) joint**

The first base will be larger than the second base to compensate for having to carry extra weight. We might have to “overengineer: the coupling between the bases to prevent backlash and slippage. Of course the final rotational joint will just be bolt on bracket.

![Enter image alt description](Images/U9n_Image_2.png)
[example image](https://www.researchgate.net/figure/The-iCub-arm-A-CAD-view-of-the-arm-of-the-iCub-robot-with-superimposed-joint-labels-th_fig3_229010855)

![Enter image alt description](Images/y3I_Image_3.png)
[inexpensive planetory gearboxes](https://www.omc-stepperonline.com/nema-23-stepper-motor-l-56mm-gear-ratio-50-1-high-precision-planetary-gearbox-23hs22-2804s-hg50?srsltid=AfmBOorzKo3zYEa1jqBecvxOFDW23BkeehO4uh2gfFv6ItN-vEymc9Z2) 

<span style="text - decoration: underline;">**7/29/2025**</span>

(TORQUE POTENTIALLY TOO LOW)

Ugh, it seems we’ll have to go searching for gearboxes again.

We’ll use **Aliexpress** if we need to. 


<img width="599" height="373" alt="Screenshot 2025-07-30 at 5 45 40 PM" src="https://github.com/user-attachments/assets/69eb8d59-e307-40a5-a765-c2e23022cf8f" />


We’ll add bearings to this sliding point later to both reduce stress on the main motor and to reduce friction. Oh, and the lid for this part will be honeycomb pattern for aesthetics and saving on material.

I’m back with the design, and I just realized.

LOOK AT THE SIZE OF THAT THING HOLY C- BANANA FOR SCALE BY THE WAY.


<img width="598" height="369" alt="Screenshot 2025-07-30 at 5 45 59 PM" src="https://github.com/user-attachments/assets/cdb7e4fe-97a2-4628-b88d-421828d5630c" />

Realistically, we have 2 options:

1. Redesign the shoulder from scratch

2. Severely cut down on the container size for each motors.

If we go with number 2, which is the most alluring option by far, we might just have the motors exposed. Cuts back on cost and torque too, I guess.

Main issue comes from the motor + gearbox, which is 0.15 m by itself. Holy-

[Direct motor mount](https://www.omc-stepperonline.com/nema-23-bracket-for-stepper-motor-and-geared-stepper-motor-alloy-steel-bracket-st-m2?language=en&currency=USD&srsltid=AfmBOooK8qa6g0IWq9fvevblhgD680OPMLwRSRrIZ5VgKmFI16Q3KWzENZg&gQT=1), we’ll be using this 

<img width="593" height="470" alt="Screenshot 2025-07-30 at 5 46 28 PM" src="https://github.com/user-attachments/assets/1eac011d-3679-4bb1-8c70-aabdb777cb1a" />

Alright, much more manageable now. (Banana for scale)

**5 hours**

7/29/2025

Continued with the mechanical design. We had to dig through various sources to get semi fluent. In short, we’ve decided to use **bracket mounts** to hold the motors in place and **flanged couplers** to get it attached to stuff, ball bearings and honeycomb pattern pending. Of course, there are holes for the I2C wires to go through. 

Finally, we’re finished.

<img width="636" height="330" alt="Screenshot 2025-07-30 at 5 46 51 PM" src="https://github.com/user-attachments/assets/1c678f0d-0a21-4c7d-9cf3-de1c596dce6f" />

Now all we have to do is provide the wiring diagram, and BOM.
<img width="890" height="476" alt="Screenshot 2025-07-30 at 4 51 13 PM" src="https://github.com/user-attachments/assets/3d5edfff-f85d-4ccd-a31d-5025f6356ae3" />
<img width="498" height="449" alt="Screenshot 2025-07-30 at 4 46 00 PM" src="https://github.com/user-attachments/assets/b1cffdd4-8008-4603-93e3-fc3be4be52d9" />
<img width="822" height="669" alt="Screenshot 2025-07-30 at 4 37 42 PM" src="https://github.com/user-attachments/assets/a6bea0f9-dece-4872-adee-ffca338e360e" />
<img width="720" height="632" alt="Screenshot 2025-07-30 at 4 36 12 PM" src="https://github.com/user-attachments/assets/4bde6352-ae98-4f2d-a9ad-8d6c41d2ec75" />
<img width="784" height="755" alt="Screenshot 2025-07-30 at 4 31 14 PM" src="https://github.com/user-attachments/assets/56fd983e-5d60-4fae-ab3d-d86bf6e82065" />

This is the wiring for now. Of course, **We will add clips during assembly to hold the wires down. **

*****8 hours***** (I didn’t know much about mechanical design)

Even if there are many flaws in the design; Ngl, this has been a wild month, and a wild ride. I’ll never forget the 15 hour PCB marathon on the plane. Oh, and I hope my journals entertained somebody.


