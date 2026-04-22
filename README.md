Project: Colour sorting conveyor belt system
 

Overview: I wanted to build a conveyor belt system to learn more about electronics and controls through microcontrollers. I was inspired by my experience of seeing systems like this in action in the meat processing factory that I previously worked at. 

How it works: Once the code is uploaded to the nano microcontroller a “System initialized” signal prints to the screen. Mounted above the conveyor is a colour sensor that has been programmed to identify blue and red colours while ignoring all others. When blue is detected a “Blue detected” signal will print to the screen. Upon detection of a blue object, the microcontroller initiates a 3.5-second transit delay to allow the object to reach the sorting terminal. The servo arm then deploys at a 70-degree angle, creating a physical barrier. As the conveyor remains in motion, the object’s own momentum, guided by the stationary arm, facilitates its diversion off the belt. The sequence concludes with a 0.5-second clearing phase before the system resets for the next operation. Upon detection of a red object, the belt runs for an 11.5 second period until the object has fallen off at the end of the belt.

Challenges faced + solutions:
1.Identifying different colours: I had problems getting the sensor to read the colours consistently while the belt was moving so I decide to have the belt be stationary and only execute commands when it was sure it identified the appropriate colour. A testing programme also had to be created in order to find out what range of data was being output when each colour was under the sensor so appropriate code could be written.
2. Belt traction: I had many issues trying to get traction on the rollers so the belt would move smoothly, I first tried cardboard and wood but realised that these were not sticky enough to give the belt any traction so I came up with a solution of wrapping the wooden rollers in an elastic exercise band material which worked out very well.

Components used:
- Arduino nano microcontroller                                   - 12v motor
- L298N driver module                                                     - TCS230 colour sensor
- B10K potentiometer                                                      - 9v battery
- MG996R servo motor                                                    - pillow case bearings

What I learned: Basic electrical flow, reading and interoperating analog signals, wiring electronics, programming different hardware components, structuring a project.

What I would do differently: I would use actual measurements when crafting the base instead of just going of rough estimates. I would have made the project bigger in order to add an extra colour sorting terminal. Possibly add a HMI in the future.


