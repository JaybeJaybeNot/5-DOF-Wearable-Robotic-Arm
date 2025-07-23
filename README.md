Robotic arms are a common project idea for engineers, providing the opportunity to tackle challenges such as feedback loops, PCB designing, firmware programming, and mechanical designing. The difficulty varies greatly, from using basic Microservos driven by Arduino to using industry-standard MCUs like the STM32 family to achieve impressive torque, precision, accuracy, and speed. 


Our design will lean somewhat to the right (industry-like) side of difficulty, utilizing the STM32F103C8Tx model of MCU's for performance, TMC model motor drivers, the motors will be  2 NEMA 23 (QSH6018) for shoulders, NEMA 17 (QSH6018) for elbow, and 9g SG90 microservo for the wrist. Stepper motors are chosen for their high torque relative to their low costs, possibly getting away with $30 for each NEMA 23, depending on the seller. Gearboxes will be utilized for each motor to increase torque output. 


The "quirk" of our project is that the robotic arm will be wearable. Current design ideas include straps similar to those of a hiking backpack, but will possible change in the future due to ergonomic reasons or if I just came up with better ideas. To control the robotic arm, a GUI will be made with sliders that controls each joint, and activators for motor modes (Stealthchop2, spreadcyckle). 
This is somewhat of an ongoing project, so existing progress will be posted on this page shortly. 
