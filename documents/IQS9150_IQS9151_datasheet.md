**IQ Switchfi ![ref1]ProxSensefi Series**

**IQS9150/IQS9151 DATASHEET**

Multi-Function Trackpad IC: Proximity, Touch, Snap, Trackpad, and Gesture Functionality![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.002.png)

<a name="_page0_x56.69_y145.00"></a>**1 Device Overview**

The IQS9150/IQS9151 ProxSensefi IC is a generic and configurable trackpad product aimed to be suitablefornumerousdesignvariationsandrequirements.Thisdevicehasmultitouchhigh-performance (linearity, accuracy, low-noise) trackpad outputs, integrated snap button options, and an on-chip ges- ture recognition engine. The IQS9150/IQS9151 features best in class sensitivity, signal-to-noise ratio and automatic tuning of electrodes. Furthermore there are user configurable virtual buttons, sliders, and wheels that can be superimposed onto the trackpad area, with easy-to-integrate virtual sensor outputs. Low power proximity detection allows extreme low power operation.

1. **Main<a name="_page0_x56.69_y289.14"></a> Features**
- Highly flexible ProxSensefi device
- Self-/Mutual-capacitive sensors configuration for device wake-up
- Ultra Low Power (ULP) wake-up on touch
- RF immunity
- Sensor flexibility:
  - Automatic sensor tuning for optimal sensitivity
  - Internal voltage regulator
  - On-chip noise filtering
  - Detection debounce and hysteresis ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.003.png)
  - Wide range of capacitance detection 
- I2C communication interface with IRQ/RDY, up to Fast-Mode Plus (1MHz) 
- QFN52 (6×6×0.75mm) – 0.40mm pitch 
- Wide input voltage supply range: 2.2V to 3.5V 
- Wide operating temperature range: −40 C to +85 C 
- Trackpad 
- Up to 7 fingers tracking
- High resolution coordinate outputs ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.004.png)
- Fast response 
- Individual touch sensor 
- Snap dome detection 
- Integrated touch size output (area and strength) for touch integrity 
- Multi-finger gesture recognition engine 
- Electrode mapping for optimal PCB layout 
- Configurable coordinate resolution and orientation 
- Compatible with wide range of overlay materials and thicknesses 
- Compatible with multiple 1-and 2-layer sensor patterns
- Adjustable sensing frequency offset for limiting potential interference
- Nocalibrationrequired-systemsautomaticallycompensatedformechan- ical & temperature changes
- Virtual sensors:
- Configurable virtual button, slider and wheel sensors
- Change sensor locations and sizes without electrode changes re- quired
- Up to 16 virtual buttons
- Up to 8 virtual sliders
- Up to 4 virtual wheels![ref2]
- Design and manufacturing support
- Touch pattern layout drawing
- Full FPC layout package (example & customised)
- Test guide for touch pattern
- RFI immunity design support
- Design simplicity
- PC GUI software for debugging and obtaining optimal performance
- Easily obtain setup defaults from GUI header file export
- No production line calibration required
- EEPROM compatibility for default settings storage for auto-startup
2. **Applications**
- <a name="_page1_x56.69_y200.92"></a>Gaming controllers
- Headphones
- Notebooks
- Mobile Devices
- Tablet and notebook accessories
- Point-of-Sale (POS)
- Industrial and Specialised (Control panels, medical devices, aircraft cockpits)
3. **System<a name="_page1_x56.69_y336.05"></a> Overview**

Supply Voltage (VDD)![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.006.png)

VDD

ProxSense® Sensing

Engines

VREG

Rx0 / Tx0 and Rx13 / Tx13 Engine 0 Power

Management

Rx1 / Tx1; Rx14 / Tx14 and Tx26 Engine 1 MCLR / VPP

Rx2 / Tx2; Rx15 / Tx15 and Tx27 Engine 2

Rx3 / Tx3 and Rx16 / Tx16 Engine 3

Rx4 / Tx4; Rx17 / Tx17 and Tx28 Engine 4

24 MHz CPU

Rx5 / Tx5 and Rx18 / Tx18 Engine 5

V

Rx6 / Tx6; Rx19 / Tx19 and Tx29 Engine 6 DD

Rx7 / Tx7 and Rx20 / Tx20 Engine 7

Rx8 / Tx8; Rx21 / Tx21 and Tx30 Engine 8

SDA

Rx9 / Tx9 and Rx22 / Tx22 Engine 9

SCL

Rx10 / Tx10; Rx23 / Tx23 and Tx31 Engine 10 Clock System I2C I2C Interface

Rx11 / Tx11 and Rx24 / Tx24 Engine 11 RDY

Rx12 / Tx12 and Rx25 / Tx25 Engine 12

ProxSense® Driver (Tx) Engine

VSS

Tx32 Tx33 Tx34 Tx35 Tx36 Tx37 Tx38 Tx39 Tx40 Tx41 Tx42 Tx43 Tx45 / SW\_IN GND

*Figure 1.1: IQS9150/IQS9151 Block Diagram![ref2]*

4. **Trackpad<a name="_page2_x56.69_y84.59"></a> Size Summary**
1. **IQS9150**
- <a name="_page2_x56.69_y97.40"></a>Max Rxs: 26
- Max Txs: 22
- Max Channels: 506
- Max Trackpad Electrodes: 45
- Example Configurations:
- Max Rectangular: 26 Rx x 19 Tx (494 channels, 45 electrodes)
- Max Square: 23 Rx x 22 Tx (506 channels, 45 electrodes)
2. **IQS9151**
- <a name="_page2_x56.69_y232.25"></a>Max Rxs: 13
- Max Txs: 22
- Max Channels: 156
- Max Trackpad Electrodes: 25
- Example Configurations:
- Max Rectangular: 10 Rx x 15 Tx (150 channels, 25 electrodes)
- Max Square: 13 Rx x 12 Tx (156 channels, 25 electrodes)![ref2]

**Contents**

[**1 Device Overview**](#_page0_x56.69_y145.00) **1**

1. [Main Features ](#_page0_x56.69_y289.14). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 1
1. [Applications](#_page1_x56.69_y200.92) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 2
1. [System Overview](#_page1_x56.69_y336.05) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 2
1. [Trackpad Size Summary ](#_page2_x56.69_y84.59). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 3
1. [IQS9150 ](#_page2_x56.69_y97.40). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 3
1. [IQS9151 ](#_page2_x56.69_y232.25). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 3

[**2 QFN52 Pinout**](#_page7_x56.69_y84.59) **8**

1. [IQS9150 ](#_page7_x56.69_y101.97). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 8
1. [IQS9151 ](#_page7_x56.69_y626.34). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 9
1. [IQS9150/IQS9151 Pinout Descriptions](#_page8_x56.69_y599.25) . . . . . . . . . . . . . . . . . . . . . . . . . . 9

[**3 Reference Schematics**](#_page11_x56.69_y84.59) **12**

1. [IQS9150 ](#_page11_x56.69_y101.97). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 12
1. [IQS9151 ](#_page11_x56.69_y663.72). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 13

[**4 Electrical Characteristics**](#_page13_x56.69_y84.59) **14**

1. [Absolute Maximum Ratings](#_page13_x56.69_y101.97) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 14
1. [General Operating Conditions ](#_page13_x56.69_y296.18). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 14
1. [Recommended Operating Conditions ](#_page13_x56.69_y487.79). . . . . . . . . . . . . . . . . . . . . . . . . . . 14
1. [ProxSensefi Electrical Characteristics](#_page13_x56.69_y702.51) . . . . . . . . . . . . . . . . . . . . . . . . . . 15
1. [ESD Rating](#_page14_x56.69_y438.47) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 15
1. [Reset Levels](#_page14_x56.69_y574.82) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 15
1. [MCLR Pin Levels and Characteristics ](#_page14_x56.69_y698.56). . . . . . . . . . . . . . . . . . . . . . . . . . . 16
1. [Digital I/O Characteristics](#_page15_x56.69_y413.19) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 16
1. [I2C Characteristics](#_page15_x56.69_y665.65) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 17
1. [Current Consumption ](#_page17_x56.69_y84.59). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 18

[**5 ProxSensefi Module**](#_page20_x56.69_y84.59) **21**

1. [ProxSensefi Engine Consideration](#_page20_x56.69_y174.18) . . . . . . . . . . . . . . . . . . . . . . . . . . . . 21
1. [Trackpad Channels ](#_page20_x56.69_y360.28). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 21

   [5.2.1 Channel Numbers](#_page20_x56.69_y442.03) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 21

3. [Alternate Low-Power Channel (ALP)](#_page21_x56.69_y340.63) . . . . . . . . . . . . . . . . . . . . . . . . . . . 22
4. [Count Value ](#_page21_x56.69_y598.25). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 22
1. [Trackpad Count Values](#_page21_x56.69_y666.45) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 22
1. [ALP Count Values](#_page21_x56.69_y720.70) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 22
1. [Trackpad Delta Value](#_page22_x56.69_y248.58) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 23
5. [Reference Value/Long-Term Average (LTA)](#_page22_x56.69_y338.46) . . . . . . . . . . . . . . . . . . . . . . . 23
1. [Trackpad References](#_page22_x56.69_y422.58) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 23
1. [ALP Long-Term Average ](#_page22_x56.69_y571.68). . . . . . . . . . . . . . . . . . . . . . . . . . . . . 23
1. [Reseed](#_page22_x56.69_y704.85) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 23
6. [Channel Outputs](#_page23_x56.69_y119.14) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 24
1. [Trackpad Touch Output](#_page23_x56.69_y143.47) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 24
1. [Trackpad Snap Output](#_page23_x56.69_y482.66) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 24
1. [ALP Output](#_page24_x56.69_y212.81) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 25
1. [Output Debounce](#_page24_x56.69_y350.73) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 25
7. [Automatic Tuning Implementation (ATI) ](#_page24_x56.69_y481.26). . . . . . . . . . . . . . . . . . . . . . . . . . 25
1. [Trackpad ATI](#_page24_x56.69_y604.63) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 25
1. [ALP ATI](#_page25_x56.69_y373.91) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 26![ref2]
8. [Automatic Re-ATI](#_page25_x56.69_y688.59) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 26
1. [Description](#_page25_x56.69_y712.92) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 26
1. [Conditions for Re-ATI to activate](#_page26_x56.69_y159.79) . . . . . . . . . . . . . . . . . . . . . . . . 27
1. [ATI Error](#_page26_x56.69_y572.50) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 27

[**6 Sensing Modes**](#_page28_x56.69_y84.59) **29**

1. [Sampling Period](#_page29_x56.69_y84.59) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 30
1. [Mode Timeout ](#_page29_x56.69_y271.48). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 30
1. [Manual Control](#_page29_x56.69_y529.98) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 30

[**7 Trackpad**](#_page30_x56.69_y84.59) **31**

1. [Configuration](#_page30_x56.69_y101.97) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 31
1. [Size Selection](#_page30_x56.69_y124.49) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 31
1. [Trackpad Channel and Electrode Limitations](#_page30_x56.69_y202.77) . . . . . . . . . . . . . . . . . 31
1. [Individual Channel Disabling](#_page30_x56.69_y313.60) . . . . . . . . . . . . . . . . . . . . . . . . . . 31
1. [Rx/Tx Mapping](#_page30_x56.69_y408.50) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 31
2. [Trackpad Outputs ](#_page31_x56.69_y131.68). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 32
1. [Number of Fingers](#_page31_x56.69_y196.48) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 32
1. [Relative XY](#_page31_x56.69_y265.64) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 32
1. [Absolute XY ](#_page31_x56.69_y343.59). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 32
1. [Touch Strength](#_page31_x56.69_y426.30) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 32
1. [Area](#_page31_x56.69_y493.08) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 32
1. [Tracking Identification](#_page31_x56.69_y559.86) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 32
3. [Maximum Number of Multi-touches](#_page31_x56.69_y626.65) . . . . . . . . . . . . . . . . . . . . . . . . . . . . 32
4. [XY Resolution ](#_page31_x56.69_y705.00). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 32
4. [Stationary Touch](#_page32_x56.69_y84.59) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 33
4. [Multi-touch Finger Split ](#_page32_x56.69_y230.83). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 33
4. [XY Output Flip & Switch](#_page32_x56.69_y353.23) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 33
4. [XY Position Filtering](#_page32_x56.69_y500.08) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 33
1. [IIR Filter](#_page32_x56.69_y581.83) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 33
1. [Jitter Filter ](#_page33_x56.69_y464.77). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 34
9. [X & Y Trim ](#_page33_x56.69_y558.78). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 34
10. [Finger Confidence](#_page33_x56.69_y680.28) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 34
10. [Saturation](#_page34_x56.69_y84.59) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 35

[**8 Gestures**](#_page35_x56.69_y84.59) **36**

1. [Single, Double and Triple Tap Gesture](#_page35_x56.69_y530.85) . . . . . . . . . . . . . . . . . . . . . . . . . . 36
1. [Press-and-Hold Gesture](#_page39_x56.69_y410.14) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 40
1. [Swipe Gesture](#_page40_x56.69_y300.21) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 41
1. [Single Swipe](#_page40_x56.69_y326.92) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 41
1. [Swipe-and-Hold](#_page41_x56.69_y652.80) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 42
1. [Consecutive Swipe ](#_page42_x56.69_y457.04). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 43
4. [Palm Gesture (Flat Hand Gesture)](#_page43_x56.69_y368.40) . . . . . . . . . . . . . . . . . . . . . . . . . . . . 44
5. [Two-Finger Tap](#_page44_x56.69_y347.36) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 45
5. [Scroll ](#_page44_x56.69_y431.49). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 45
5. [Zoom](#_page44_x56.69_y773.66) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 46

[**9 Virtual Sensors**](#_page46_x56.69_y84.59) **47**

1. [Maximum Virtual Sensors](#_page46_x56.69_y570.86) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 47
1. [Maximum Fingers Per Sensor](#_page46_x56.69_y748.55) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 48
1. [Buttons](#_page47_x56.69_y195.46) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 48
1. [Button Output ](#_page47_x56.69_y331.41). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 48![ref2]
2. [Button Setup](#_page47_x56.69_y411.98) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 48
4. [Sliders](#_page48_x56.69_y388.53) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 49
1. [Slider Output](#_page48_x56.69_y483.83) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 49
1. [Slider Setup ](#_page49_x56.69_y366.21). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 50
5. [Wheels](#_page50_x56.69_y119.14) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 51
1. [Wheel Output ](#_page50_x56.69_y200.89). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 51
1. [Wheel Setup](#_page50_x56.69_y653.00) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 51

[**10 Hardware Settings**](#_page52_x56.69_y84.59) **53**

1. [Main Oscillator](#_page52_x56.69_y187.73) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 53
1. [Charge Transfer Frequency](#_page52_x56.69_y269.48) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 53
1. [Reset](#_page52_x56.69_y351.23) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 53
1. [Reset Indication](#_page52_x56.69_y375.55) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 53
1. [Software Reset](#_page52_x56.69_y507.77) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 53
1. [Hardware Reset](#_page52_x56.69_y588.08) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 53

[**11 Additional Features**](#_page53_x56.69_y84.59) **54**

1. [GUI for Parameter Setup ](#_page53_x56.69_y101.97). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 54

   [11.1.1 Manual Start-up](#_page53_x56.69_y285.03) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 54

2. [Suspend ](#_page53_x56.69_y379.92). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 54
3. [Watchdog Timer (WDT)](#_page53_x56.69_y524.40) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 54
3. [RF Immunity](#_page53_x56.69_y698.09) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 54
3. [Switch Input ](#_page54_x56.69_y157.15). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 55
3. [Additional Non-Trackpad Channels](#_page54_x56.69_y331.10) . . . . . . . . . . . . . . . . . . . . . . . . . . . . 55
3. [Version Information ](#_page54_x56.69_y486.23). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 55

[**12 I2C Interface**](#_page55_x56.69_y84.59) **56**

1. [I2C Module Specification ](#_page55_x56.69_y101.97). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 56
1. [I2C Address](#_page55_x56.69_y274.53) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 56

   [12.2.1 Reserved I2C Address](#_page55_x56.69_y411.67) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 56

3. [Memory Map Addressing](#_page55_x56.69_y569.30) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 56
4. [Memory Map Data](#_page55_x56.69_y626.32) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 56
4. [Read and Write Operations](#_page56_x56.69_y84.59) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 57
1. [I2C Read From Specific Address](#_page56_x56.69_y97.40) . . . . . . . . . . . . . . . . . . . . . . . . 57
1. [I2C Write To Specific Address ](#_page56_x56.69_y439.33). . . . . . . . . . . . . . . . . . . . . . . . . . 57
6. [I2C Timeout](#_page57_x56.69_y184.25) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 58
7. [Terminate Communication](#_page57_x56.69_y281.02) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 58
7. [RDY / IRQ ](#_page57_x56.69_y633.78). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 58
7. [Event Mode Communication ](#_page58_x56.69_y105.57). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 59
1. [Events ](#_page58_x56.69_y252.40). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 59
1. [Force Communication / Polling](#_page58_x56.69_y480.13) . . . . . . . . . . . . . . . . . . . . . . . . . 59

[**13 Ordering Information**](#_page60_x56.69_y84.59) **61**

1. [Ordering Code](#_page60_x56.69_y101.97) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 61
1. [IQS9150 ](#_page60_x56.69_y124.49). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 61
1. [IQS9151 ](#_page60_x56.69_y356.71). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 61
2. [QFN52 Top Markings ](#_page60_x56.69_y572.53). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 61
1. [IQS9150 ](#_page60_x56.69_y596.86). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 61
1. [IQS9151 ](#_page60_x56.69_y779.08). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 62
1. [Generic QFN52 Top Marking](#_page61_x56.69_y256.89) . . . . . . . . . . . . . . . . . . . . . . . . . . 62

[**14 QFN52 Package Information**](#_page62_x56.69_y84.59) **63![ref2]**

1. [QFN52 Package Outline](#_page62_x56.69_y101.97) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 63
1. [QFN52 Recommended Footprint](#_page63_x56.69_y185.61) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 64
1. [Tape and Reel Specifications](#_page63_x56.69_y610.93) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 65

[**15 I2C Memory Map - Register Descriptions**](#_page65_x56.69_y84.59) **66 [**A Memory Map Descriptions**](#_page69_x56.69_y84.59) 70**

[A.1 Product Information ](#_page69_x56.69_y101.97). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 70 [A.2 Single Finger Gestures (0x101C)](#_page69_x56.69_y323.15) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 70 [A.3 Two Finger Gestures (0x101E)](#_page70_x56.69_y225.72) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 71 [A.4 Info Flags (0x1020) ](#_page71_x56.69_y84.59). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 72 [A.5 Trackpad Flags (0x1022) ](#_page71_x56.69_y712.72). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 73 [A.6 ALP Individual Counts (0x10B8)](#_page72_x56.69_y498.09) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 73 [A.7 Button Output (0x112A)](#_page72_x56.69_y764.34) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 74 [A.8 Slider Output (0x112C) ](#_page73_x56.69_y232.49). . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 74 [A.9 Wheel Output (0x114C)](#_page73_x56.69_y537.39) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 74 [A.10 ALP ATI Compensation (0x115C)](#_page73_x56.69_y725.29) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 75 [A.11 Trackpad and ALP Multipliers / Divider (0x117A / 0x117C)](#_page74_x56.69_y403.93) . . . . . . . . . . . . . . . 75 [A.12 System Control (0x11BC)](#_page75_x56.69_y159.97) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 76 [A.13 Configuration Settings (0x11BE)](#_page76_x56.69_y84.59) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 77 [A.14 Other Settings (0x11C0)](#_page76_x56.69_y769.47) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 78 [A.15 ALP Setup (0x11C2)](#_page77_x56.69_y583.81) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 79 [A.16 ALP Tx Enable (0x11C6)](#_page78_x56.69_y522.49) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 80 [A.17 Trackpad and ALP Conversion Frequency (0x11D8 and 0x11DB)](#_page79_x56.69_y498.98) . . . . . . . . . . . 80 [A.18 Trackpad and ALP Hardware Settings (0x11DE and 0x11E0)](#_page80_x56.69_y369.32) . . . . . . . . . . . . . 81 [A.19 Trackpad Settings (0x11E2)](#_page81_x56.69_y399.11) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 82 [A.20 Single Finger Gesture Enable (0x11F6)](#_page81_x56.69_y744.08) . . . . . . . . . . . . . . . . . . . . . . . . . 83 [A.21 Two Finger Gesture Enable (0x11F8) ](#_page83_x56.69_y84.59). . . . . . . . . . . . . . . . . . . . . . . . . . . 84 [A.22 RxTx Mapping (0x1218)](#_page83_x56.69_y485.18) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 84 [A.23 Individual Touch Threshold Adjustments (0x12F6) ](#_page85_x56.69_y84.59). . . . . . . . . . . . . . . . . . . . 86 [A.24 Number Of Virtual Sensors Enabled (0x14F0)](#_page85_x56.69_y397.63) . . . . . . . . . . . . . . . . . . . . . . 86 [A.25 Engineering Configuration (0x2000)](#_page85_x56.69_y563.29) . . . . . . . . . . . . . . . . . . . . . . . . . . . 86 [A.26 Trackpad ATI Compensation (0xD000)](#_page86_x56.69_y84.59) . . . . . . . . . . . . . . . . . . . . . . . . . . 87 [A.27 Count / Delta / Reference Data](#_page86_x56.69_y274.82) . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 87 [A.28 Individual Channel Status / Config Bit Definitions](#_page87_x56.69_y218.69) . . . . . . . . . . . . . . . . . . . . 88

[**B Revision History**](#_page89_x56.69_y84.59) **90![ref2]**

<a name="_page7_x56.69_y84.59"></a>**2 QFN52 Pinout**

1. **IQS9150**

<a name="_page7_x56.69_y101.97"></a>**QFN52 Package (Top View)![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.007.png)**

SCL 1 39 MCLR / VPP SDA 2 38 TX32

VSS 3 37 RX25 / TX25 VDD 4 36 RX12 / TX12 VREG 5 35 RX24 / TX24 RX0 / TX0 6 34 RX11 / TX11

RX13 / TX13 7 TAB 33 TX31

RX1 / TX1 8 32 RX23 / TX23 RX14 / TX14 9 31 RX10 / TX10 TX26 10 30 RX22 / TX22

RX2 / TX2 11 29 RX9 / TX9 RX15 / TX15 12 28 TX30

TX27 13 27 RX21 / TX21

*Figure<a name="_page7_x56.69_y626.34"></a> 2.1: IQS9150 QFN52 Pinout![ref2]*

Copyright ' Azoteq 2024 IQS9150/IQS9151 Datasheet Page 9 of 97 All Rights Reserved Revision v1.1 October 2024
**IQ Switchfi ![ref1]ProxSensefi Series**

2. **IQS9151![ref1]**

**QFN52 Package (Top View)![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.008.png)**

SCL 1 39 MCLR / VPP SDA 2 38 NC

VSS 3 37 NC

VDD 4 36 RX12 / TX12 VREG 5 35 NC

RX0 / TX0 6 34 RX11 / TX11

NC 7 TAB 33 NC

RX1 / TX1 8 32 NC

NC 9 31 RX10 / TX10 NC 10 30 NC

RX2 / TX2 11 29 RX9 / TX9 NC 12 28 NC

NC 13 27 NC

*Figure 2.2: IQS9151 QFN52 Pinout*

3. **IQS9150/IQS9151<a name="_page8_x56.69_y599.25"></a> Pinout Descriptions**

*Table 2.1: QFN52 Pin Descriptions*



|**Pin**|**IQS9150**|**IQS9151**|**Type[**i**](#_page10_x92.69_y171.35)**|**Function**|**Description**|
| - | - | - | - | - | - |
|1|SCL|SCL|I/O|I 2C|I2C data|
|2|SDA|SDA|I/O|I2C|I2C clock|
|3|VSS|VSS|P|Power|Analog/digitalground|
|4|VDD|VDD|P|Power|Power supply input voltage|
|5|VREG|VREG|P|Power|Internally-regulated supply voltage|
|6|RX0 / TX0|RX0 / TX0|I/O|ProxSensefi|Receiver or transmitter electrode|

*Continued on next page...![ref2]*

*Table 2.1: QFN52 Pin Descriptions (Continued)*



|**Pin**|**IQS9150**|**IQS9151**|**Type[**i**](#_page10_x92.69_y171.35)**|**Function**|**Description**|
| - | - | - | - | - | - |
|7|RX13 / TX13|NC|I/O|ProxSensefi|Receiver or transmitter electrode|
|8|RX1 / TX1|RX1 / TX1|I/O|ProxSensefi|Receiver or transmitter electrode|
|9|RX14 / TX14|NC|I/O|ProxSensefi|Receiver or transmitter electrode|
|10|TX26|NC|O|ProxSensefi|Transmitter electrode|
|11|RX2 / TX2|RX2 / TX2|I/O|ProxSensefi|Receiver or transmitter electrode|
|12|RX15 / TX15|NC|I/O|ProxSensefi|Receiver or transmitter electrode|
|13|TX27|NC|O|ProxSensefi|Transmitter electrode|
|14|RX3 / TX3|RX3 / TX3|I/O|ProxSensefi|Receiver or transmitter electrode|
|15|RX16 / TX16|NC|I/O|ProxSensefi|Receiver or transmitter electrode|
|16|RX4 / TX4|RX4 / TX4|I/O|ProxSensefi|Receiver or transmitter electrode|
|17|RX17 / TX17|NC|I/O|ProxSensefi|Receiver or transmitter electrode|
|18|TX28|NC|O|ProxSensefi|Transmitter electrode|
|19|RX5 / TX5|RX5 / TX5|I/O|ProxSensefi|Receiver or transmitter electrode|
|20|RX18 / TX18|NC|I/O|ProxSensefi|Receiver or transmitter electrode|
|21|RX6 / TX6|RX6 / TX6|I/O|ProxSensefi|Receiver or transmitter electrode|
|22|RX19 / TX19|NC|I/O|ProxSensefi|Receiver or transmitter electrode|
|23|TX29|NC|O|ProxSensefi|Transmitter electrode|
|24|RX7 / TX7|RX7 / TX7|I/O|ProxSensefi|Receiver or transmitter electrode|
|25|RX20 / TX20|NC|I/O|ProxSensefi|Receiver or transmitter electrode|
|26|RX8 / TX8|RX8 / TX8|I/O|ProxSensefi|Receiver or transmitter electrode|
|27|RX21 / TX21|NC|I/O|ProxSensefi|Receiver or transmitter electrode|
|28|TX30|NC|O|ProxSensefi|Transmitter electrode|
|29|RX9 / TX9|RX9 / TX9|I/O|ProxSensefi|Receiver or transmitter electrode|
|30|RX22 / TX22|NC|I/O|ProxSensefi|Receiver or transmitter electrode|
|31|RX10 / TX10|RX10 / TX10|I/O|ProxSensefi|Receiver or transmitter electrode|
|32|RX23 / TX23|NC|I/O|ProxSensefi|Receiver or transmitter electrode|
|33|TX31|NC|O|ProxSensefi|Transmitter electrode|
|34|RX11 / TX11|RX11 / TX11|I/O|ProxSensefi|Receiver or transmitter electrode|
|35|RX24 / TX24|NC|I/O|ProxSensefi|Receiver or transmitter electrode|
|36|RX12 / TX12|RX12 / TX12|I/O|ProxSensefi|Receiver or transmitter electrode|
|37|RX25 / TX25|NC|I/O|ProxSensefi|Receiver or transmitter electrode|
|38|TX32|NC|O|ProxSensefi|Transmitter electrode|
|39|MCLR / VPP|MCLR / VPP|I|GPIO|Master clear pin used for HW reset (active low), and VPP input for OTP|
|40|TX33|TX33|O|ProxSensefi|Transmitter electrode|
|41|TX34|TX34|O|ProxSensefi|Transmitter electrode|
|42|TX35|TX35|O|ProxSensefi|Transmitter electrode|
|43|TX36|TX36|O|ProxSensefi|Transmitter electrode|
|44|TX37|TX37|O|ProxSensefi|Transmitter electrode|
|45|TX38|TX38|O|ProxSensefi|Transmitter electrode|
|46|TX39|TX39|O|ProxSensefi|Transmitter electrode|
|47|TX40|TX40|O|ProxSensefi|Transmitter electrode|
|48|TX41|TX41|O|ProxSensefi|Transmitter electrode|
|49|TX42|TX42|O|ProxSensefi|Transmitter electrode|

*Continued on next page...![ref2]*

*Table 2.1: QFN52 Pin Descriptions (Continued)*



|**Pin**|**IQS9150**|**IQS9151**|**Type[**i**](#_page10_x92.69_y171.35)**|**Function**|**Description**|
| - | - | - | - | - | - |
|50|TX43|TX43|O|ProxSensefi|Transmitter electrode|
|51|RDY|RDY|O|GPIO|<p>Ready pin indicates</p><p>communication window (active low)</p>|
|52|TX45 / SW\_IN|TX45 / SW\_IN|I/O|GPIO|Transmit electrode or switch input|

i<a name="_page10_x92.69_y171.35"></a> Pin Types: I = Input, O = Output, I/O = Input or Output, P = Power![ref2]

<a name="_page11_x56.69_y84.59"></a>**3 Reference Schematics![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.009.png)**

1. **IQS9150**

<a name="_page11_x56.69_y101.97"></a>IQS9150 Decoupling Capacitors

U1 VDD

1 53

SSDCLA 2 SSCDLA TX45T A/ BS/WG\_NIDN 52 SW\_IN

3 VSS RDY 51 RDY

5 VDD TX43 49 TX43 C1 C2 C3

4 50

VVDRDEG 6 VREG TX42 48 TX42 100pF 100nF 47uF

RX0 7 RX0 / TX0 TX41 47 TX41 GND

GND RRRXXX13114 11 RRRTRXXXXX2111263 4 //    /T/T  TTXXXX121134 TTXX3367 43 TTTXXX403938 GND

8 TTXX3490 46

9 45

10 TX38 44

RTXX262 12 RX15 / TX15 TX35 42 TTTXXX373635 VREG

RTXX2715 13 TX27 TX34 41 TX34

RX3 14 RX3 / TX3 TX33 40 TX33

RX16 15 RX16 / TX16 MCLR / VPP 39 MCLR C4 C5 C6

RX4 16 RX4 / TX4 TX32 38 TX32 100pF 100nF 22uF

17 37

RX17 18 RX17 / TX17 RX25 / TX25 36 RX25

TX28 19 TX28 RX12 / TX12 35 RX12

RX5 20 RX5 / TX5 RX24 / TX24 34 RX24

RX18 21 RX18 / TX18 RX11 / TX11 33 RX11 GND

RX6 22 RX6 / TX6 TX31 32 TX31

RX19 23 RX19 / TX19 RX23 / TX23 31 RX23 \*Place as close as possible to IC. TX29 24 TX29 RX10 / TX10 30 RX10

RX7 25 RX7 / TX7 RX22 / TX22 29 RX22

RX20 26 RX20 / TX20 RX9 / TX9 28 RX9 I2C Pull-Ups VDD

RX8 RX8 / TX8 RX21 / TTXX3201 27 TRXX3021

IQS9150

R1 R2 R3 4.7k 4.7k 4.7k

SDA

Trackpad Layout

SCL RDY

|||||||||||||||||||||||||||
| :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- |
Reset Circuit

TX43

TX42 MCLR

TX41

TX40 C7 TX39

TX38 100nF TX37

TX36

TX35 GND

TX34

TX33

TX32

TX31 Switch Circuit

TX27

TX29 VDD

TX28

TX30 R4

TX26 4.7K S1

SW\_IN

EVQPLHA15

26 Rx \* 18 Tx GND

* Schematic subject to change without notice

*Figure<a name="_page11_x56.69_y663.72"></a> 3.1: IQS9150 Reference Schematic for 26 by 18 Trackpad Layout (468 Channels)*

2. **IQS9151**

   IQS9151 Decoupling Capacitors![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.010.png)![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.011.png)

VREG VDD VDD

U1

1 53 2 52 3 51 4 50 5 49 6 48 7 47 8 46 9 45 10 44 11 43 12 42 13 41 14 40 15 39 16 38 17 37 18 36 35

C1 C2 C3 100nF

SCL SCL TAB/GND SDA SDA TX45 / SW\_IN VSS RDY

100pF 47uF

|TX45||
| - | :- |
|RDY||
|TX43||
|TX42||
|TX41||
|TX40||
|TX39||
|TX38||
|TX37||
|TX36||
|TX35||
|TX34||
|TX33||
|MCLR/VPP||

GND

VDD TX43 VREG TX42 RX0 / TX0 TX41 NC TX40 RX1 / TX1 TX39 NC TX38 NC TX37 RX2 / TX2 TX36 NC TX35 NC TX34 RX3 / TX3 TX33 NC MCLR / VPP RX4 / TX4 NC NC NC NC RX12 / TX12 RX5 / TX5 NC NC RX11 / TX11 RX6 / TX6 NC NC NC NC RX10 / TX10 RX7 / TX7 NC NC RX9 / TX9 RX8 / TX8 NC NC

GND

GND

RX0 RX1

VREG

RX2

C4 C5 C6 100nF

100pF 22uF

RX3 RX4

GND

19 RX12

RX5 2201 RX11

34

33

RX6 22

32

23

31

24 RX10

30

RX7 25 RX9

29

RX8 26 Pull-up Resistors

28

27

VDD

IQS9151

Trackpad Layout R1 R2 R3

4\.7K 4.7K 4.7K

TX34 Reset Circuit

TX35

MCLR/VPP

TX37

TX38 C7

100nF

TX41

TX42 GND

TX36

TX40

TX43

TX45

TX39

TX33

13 Rx \* 12 Tx

* Schematic subject to change without notice

*Figure 3.2: IQS9151 Reference Schematic for 13 by 12 Trackpad Layout (156 Channels)![ref2]*

<a name="_page13_x56.69_y84.59"></a>**4 Electrical Characteristics**

1. **Absolute<a name="_page13_x56.69_y101.97"></a> Maximum Ratings**

*Table 4.1: Absolute Maximum Ratings*



|**Symbol**|**Rating**||**Min**|**Max**|**Unit**|
| - | - | :- | - | - | - |
|VDD|Voltage applied at VDD pin (referenced to VSS)||−0.3|3\.6|V|
|VIN|Voltage applied to any ProxFusion (referenced to VSS)|fi pin|−0.3|<p>V</p><p>REG</p>|V|
||Voltage applied to any other pin (referenced to VSS)||−0.3|VDD + 0.3 (3.6V max)|V|
|Tstg|Storage temperature||−40|85|` `C|

2. **General<a name="_page13_x56.69_y296.18"></a> Operating Conditions**

*Table 4.2: General Operating Conditions*



|**Symbol**|**Parameter**|**Condition**|**Typ**|**Unit**|
| - | - | - | - | - |
|<p>F</p><p>CLK</p>|Master clock frequency|FCLK = 14MHz|14|MHz|
|||<p>F = 20MHz</p><p>CLK</p>|20||
|||FCLK = 24MHz|24||
|FPROX|<p>fi</p><p>ProxFusion engine clock frequency</p>||16|MHz|
|VREG|Internally-regulated supply output|FCLK = 14MHz|1\.53|V|
|||FCLK e 20MHz|1\.80||
3. **Recommended<a name="_page13_x56.69_y487.79"></a> Operating Conditions**

*Table 4.3: Recommended Operating Conditions*



|**Symbol**|**Parameter**|**Condition**|**Min**|<p>[**a**](#_page13_x60.52_y670.95)</p><p>**Rec**</p>|**Max**|**Unit**|
| - | - | - | - | - | - | - |
|VDD|Standard operating voltage, applied at VDD pin|<p>F = 14MHz</p><p>CLK</p>|1\.71||3\.6|V|
|||FCLK e 20MHz|2\.2||||
|TA|Operating free-air temperature||−20||85|` `C|
|<p>C</p><p>VDD</p>|Recommended capacitor at VDD||<p>C</p><p>VREG</p>|<p>2×C</p><p>VREG</p>||` `F|
|CVREG|<p>Recommended external buffer capacitor at VREG</p><p>(ESR d 200mΩ)</p>||<p>[b](#_page13_x60.52_y681.91)</p><p>10</p>|22|88|` `F|

a<a name="_page13_x60.52_y681.91"></a><a name="_page13_x60.52_y670.95"></a> Recommended value

b<a name="_page13_x56.69_y702.51"></a> Absolute minimum allowed capacitance value is 4.7 F, after derating for voltage, temperature, and worst-case tolerance.![ref2]

Copyright ' Azoteq 2024 IQS9150/IQS9151 Datasheet Page 17 of 97 All Rights Reserved Revision v1.1 October 2024
**IQ Switchfi ![ref1]ProxSensefi Series**

4. **ProxSense**

**fi Electrical Characteristics**

*Table 4.4: Recommended Operating Conditions for ProxFusionfi Pins*

Copyright ' Azoteq 2024 IQS9150/IQS9151 Datasheet Page 18 of 97 All Rights Reserved Revision v1.1 October 2024
**IQ Switchfi ![ref1]ProxSensefi Series**
|**Symbol**|**Parameter**|**Min**|**Typ**|**Max**|**Unit**|
| - | - | - | - | - | - |
|CxSELF–VSS|Capacitance between ground and external electrodes, in self-capacitance mode|1||<p>[a](#_page14_x60.52_y374.05)</p><p>400</p>|pF|
|CmCTx–CRx|Capacitance between transmitting and receiving electrodes, in mutual-capacitance mode|0\.2||<p>[a](#_page14_x60.52_y374.05)</p><p>10</p>|pF|
|<p>Cp</p><p>CRx–VSS</p>|Capacitance between ground and external electrodes, in mutual-capacitance mode||||pF|
||Fxfer = 1MHz|||<p>[a](#_page14_x60.52_y374.05)</p><p>100</p>||
||Fxfer = 4MHz|||20[a](#_page14_x60.52_y374.05)||
|CpCRx–VSS CmCTx–CRx|Capacitance ratio for optimal SNR in mutual-capacitance mode|1||50||
|RCRx, RCTx|Series in-line resistance of Tx and Rx pins in mutual-capacitance mode|0||<p>[b](#_page14_x60.52_y385.01)[,c](#_page14_x60.18_y406.93)</p><p>0\.5</p>|kΩ|
|RCx(SELF)|Series in-line resistance of self-capacitance electrodes|0||<p>[c](#_page14_x60.18_y406.93)</p><p>1</p>|kΩ|

a<a name="_page14_x60.52_y385.01"></a><a name="_page14_x60.52_y374.05"></a> RCx = 0 Ω

b Series resistance of up to 500 Ω is recommended to prevent received and emitted EMI effects. Typical resistance also

<a name="_page14_x60.18_y406.93"></a>adds additional ESD protection.

c Series resistance limit is a function of Fxfer and the circuit time constant, Ďÿ. ĎăÿĎ ×ÿăÿĎ = 1∕(10 ×ĂĎĄăĈ), where ÿ is the

pin capacitance to VSS.

5. **ESD<a name="_page14_x56.69_y438.47"></a> Rating**

*Table 4.5: ESD Rating*



||**Value**|**Unit**|||
| :- | - | - | :- | :- |
|V(ESD)|Electrostatic discharge voltage|<p>Human-body model (HBM), per ANSI/ESDA/JEDEC JS-001</p><p>[a](#_page14_x76.95_y538.99)</p>|–2000|V|

a<a name="_page14_x76.95_y538.99"></a> JEDEC document JEP155 states that 500V HBM allows safe manufacturing with a standard ESD control process.

Pins listed as –2000V may actually have higher performance.

6. **Reset<a name="_page14_x56.69_y574.82"></a> Levels**

*Table 4.6: Reset Levels![ref2]*



|**Parameter**|<a name="_page14_x56.69_y698.56"></a>**Min**|**Typ**|**Max**|**Unit**||
| - | - | - | - | - | :- |
|VDD|Power-up (Reset trigger) – slope > 100V/s|||1\.65|V|
||Power-down (Reset trigger) – slope < −100V/s|0\.9||||
7. **MCLR Pin Levels and Characteristics**

*Table 4.7: MCLR Pin Characteristics*



|**Parameter**|**Min**|**Typ**|**Max**|**Unit**||
| - | - | - | - | - | :- |
|VIL|MCLR input low level voltage|<p>V − 0.3</p><p>SS</p>||0\.25 × VDD|V|
|VIH|MCLR input high level voltage|0\.75 × VDD||VDD + 0.3|V|
|RPU|MCLR pull-up equivalent resistor||210||k Ω|
|tTrig|MCLR input pulse width – ensure trigger|250|||ns|

VDD![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.012.png)

RPU

EXTERNAL MCLR

RESET

CIRCUIT

100nF

*Figure 4.1: MCLR Pin Diagram*

8. **Digital<a name="_page15_x56.69_y413.19"></a> I/O Characteristics**

*Table 4.8: Digital I/O Characteristics![ref2]*



|**Parameter**||<a name="_page15_x56.69_y665.65"></a>**Test Conditions**|**Min**|**Max**||**Unit**||
| - | :- | :- | - | - | :- | - | :- |
|VOL|SDA & SCL output low voltage||<p>I = 20mA</p><p>sink</p>||0\.3||V|
||GPIO output low voltage||<p>I = 10mA</p><p>sink</p>||0\.15||V|
|VOH|Output high voltage||<p>I = 20mA</p><p>source</p>|<p>V − 0.2</p><p>DD</p>|||V|
|VIL|Input low voltage|||<p>V − 0.3</p><p>SS</p>|0\.3 × VDD||V|
|VIH|Input high voltage|||0\.7 × VDD|VDD + 0.3||V|
||Output current sunk by any GPIO pin||||10|||
|IGPIO|Output current sourced by any GPIO pin||||20||mA|
|Cb|SDA & SCL bus capacitance||||550||pF|

9. **I2C Characteristics**

*Table 4.9: I2C Characteristics*



|**Parameter**||**Min**||**Max**|**Unit**||
| - | :- | - | :- | - | - | :- |
|fSCL|SCL clock frequency||||1000|kHz|
|tHD,STA|Hold time (repeated) START condition||0\.26|||` `s|
|tLOW|LOW period of the SCL clock||0\.5|||` `s|
|tHIGH|HIGH period of the SCL clock||0\.26|||` `s|
|tSU,STA|Set-up time for a repeated START condition||0\.26|||` `s|
|tHD,DAT|Data hold time||0|||ns|
|tSU,DAT|Data set-up time||50|||ns|
|tSU,STO|Set-up time for STOP condition||0\.26|||` `s|
|tBUF|Bus free time between a STOP and START condition||0\.5|||` `s|
|tSP|Pulse duration of spikes suppressed by input filter||0||50 ns||
tBUF![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.013.png)

tHD,STA tSU,STA

SDA

tLOW tHIGH tSP

SCL

tSU,DAT tSU,STO

tHD,DAT

*Figure 4.2: I2C Timing Diagram![ref2]*

10. **Current<a name="_page17_x56.69_y84.59"></a> Consumption**

The current consumption of the IQS9150/IQS9151 is highly dependent on the specific parameters configured during initialisation. Therefore, Table[ 4.10 ](#_page17_x122.18_y290.50)provided below serves as an illustration of the expected power consumption for similar configurations[i.](#_page17_x67.60_y768.12) All measurements are taken without I2C com- munication, since the amount of data read via I2C will impact the current consumption and sampling period of the device. The device configurations outlined in the table represent practical setups com- monly encountered in various applications.

**Note:** The 8 x 8 and the 10 x 15 column are applicable to both the IQS9150 and IQS9151.

- Trackpad Configuration:
- Trackpad ATI Target = 250
- Main Oscillator Selection = 24MHz
- Trackpad Conversion Frequency = 2.50MHz
- SH Bias = 5 A

<a name="_page17_x122.18_y290.50"></a>*Table 4.10: Typical Current Consumption for a Range of Trackpad Sizes*



|**Mode**|**Sampling Period [ms]**|**Current Consumption [mA]**|||||
| - | :- | - | :- | :- | :- | :- |
|||**8 x 8**|**10 x 15**|**20 x 14**|**23 x 22**|**26 x 19**|
|<p>[a](#_page17_x126.00_y460.59)</p><p>Active</p>|10|2\.2|3\.7|5\.5|<p>[c](#_page17_x125.67_y482.50)</p><p>9\.1</p>|<p>[c](#_page17_x125.67_y482.50)</p><p>9\.5</p>|
|<p>[a](#_page17_x126.00_y460.59)</p><p>Active</p>|15|1\.5|2\.6|3\.7|6\.3|6\.2|
|<p>[a](#_page17_x126.00_y460.59)</p><p>Active</p>|20|1\.1|1\.9|2\.8|4\.8|4\.7|
||||||||
|<p>[b](#_page17_x126.00_y471.55)</p><p>Idle</p>|30|0\.7|1\.2|1\.8|3\.1|3\.1|
|<p>[b](#_page17_x126.00_y471.55)</p><p>Idle</p>|50|0\.4|0\.7|1\.1|1\.9|1\.9|
|<p>[b](#_page17_x126.00_y471.55)</p><p>Idle</p>|100|0\.2|0\.4|0\.6|0\.9|0\.9|

a<a name="_page17_x126.00_y471.55"></a><a name="_page17_x126.00_y460.59"></a> Continuous movement in touch with a single 8mm stylus.

b<a name="_page17_x125.67_y482.50"></a> No touches in Idle Mode.

c Chosen sampling period was not achieved due to specific configuration.

**Note:** TheLP1/2modeusestheALPchannel,andthetrackpadremainsinactiveduringtheLPmodes. No touches are made in LP1/2 while measurements are taken.

- ALP Configuration 1:
- ALP ATI Target = 300
- Main Oscillator Selection = 24MHz
- Trackpad Conversion Frequency = 1.50MHz
- ALP Sensing Method = Self-capacitive
- Active Tx Shield Enabled
- All Rx and Tx electrodes enabled
- LP1 Auto-Prox Disabled
- LP2 Auto-Prox Enabled (Auto-Prox Cycles = 32)

i<a name="_page17_x67.60_y768.12"></a> These measurements are based on bench testing and have not been characterised over large volumes.![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.014.png)![ref2]

*Table 4.11: Typical Current Consumption for Trackpads in ALP Mode with Configuration 1*



|**Mode**|**Sampling Period [ms]**|**Current Consumption [ A]**|||||
| - | :- | - | :- | :- | :- | :- |
|||**8 x 8**|**10 x 15**|**20 x 14**|**23 x 22**|**26 x 19**|
|ALP LP1|50|115|116|122|123|125|
|ALP LP1|100|59|60|63|63|64|
|ALP LP1|150|40|40|43|43|44|
|ALP LP1|200|31|31|33|33|33|
||||||||
|ALP LP2|50|22|24|31|32|34|
|ALP LP2|100|12|13|16|17|18|
|ALP LP2|150|9|9|12|12|13|
|ALP LP2|200|7|8|9|10|10|
|ALP LP2|300|5|6|7|7|7|
|ALP LP2|400|5|5|6|6|6|
|ALP LP2|500|4|4|5|5|5|

- ALP Configuration 2:
- ALP ATI Target = 300
- Main Oscillator Selection = 24MHz
- Trackpad Conversion Frequency = 1.50MHz
- ALP Sensing Method = Mutual-capacitive
- SH Bias = 5 A
- Every alternate Rx and Tx electrode enabled
- LP1 Auto-Prox Disabled
- LP2 Auto-Prox Enabled (Auto-Prox Cycles = 32)

*Table 4.12: Typical Current Consumption for Trackpads in ALP Mode with Configuration 2![ref2]*



|**Mode**|**Sampling Period [ms]**|**Current Consumption [ A]**|||||
| - | :- | - | :- | :- | :- | :- |
|||**8 x 8**|**10 x 15**|**20 x 14**|**23 x 22**|**26 x 19**|
|ALP LP1|50|122|128|143|152|143|
|ALP LP1|100|62|65|73|78|73|
|ALP LP1|150|42|44|49|53|50|
|ALP LP1|200|32|34|38|40|38|
||||||||
|ALP LP2|50|33|43|58|73|62|
|ALP LP2|100|18|22|30|38|32|
|ALP LP2|150|12|16|21|26|22|
|ALP LP2|200|10|12|16|19|17|
|ALP LP2|300|7|9|12|15|12|
|ALP LP2|400|5|7|9|10|9|
|ALP LP2|500|5|6|7|9|8|

10 8 6 

|||||||||
| :- | :- | :- | :- | :- | :- | :- | :- |
|||||||||
|||||||||
|||||||||
|||||||||
|||||||||
|||||||||
|||||||||
|||||||||
|||||||||
8x8 ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.015.png)![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.016.png)

8x8 10x15 20x14 23x22 26x19

3 

10x15 

20x14 

23x22 2 26x19 

4 2 0

1

0

0 5 10 15 20 0 50 100 Sampling Period [ms] Sampling Period [ms]

*(a) Active Mode (b) Idle Mode*

*Figure 4.3: Typical Trackpad Current Consumption for a Range of Trackpad Sizes*

Copyright ' Azoteq 2024 IQS9150/IQS9151 Datasheet Page 23 of 97 All Rights Reserved Revision v1.1 October 2024
**IQ Switchfi ![ref1]ProxSensefi Series**
||||||
| :- | :- | :- | :- | :- |
||||||
||||||
8x8 10x15 20x14 23x22 26x19![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.017.png)

100 50 0

0 50 100 150 200 Sampling Period [ms]

 

||||
| :- | :- | :- |
||||
||||
||||
8x8 10x15 20x14 23x22![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.018.png)

30 20

26x19

10 0

0 200 400

Sampling Period [ms]

Copyright ' Azoteq 2024 IQS9150/IQS9151 Datasheet Page 24 of 97 All Rights Reserved Revision v1.1 October 2024
**IQ Switchfi ![ref1]ProxSensefi Series**

*(a) ALP LP1 Mode - Config 1 (b) ALP LP2 Mode - Config 1*

*Figure 4.4: Typical ALP Current Consumption for a Range of Trackpad Sizes*

Copyright ' Azoteq 2024 IQS9150/IQS9151 Datasheet Page 25 of 25 All Rights Reserved Revision v1.1 October 2024
**IQ Switchfi ![ref1]ProxSensefi Series**



||||||
| :- | :- | :- | :- | :- |
||||||
||||||
||||||
8x8 10x15 20x14 23x22 26x19![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.019.png)

150 100 50 0

0 50 100 150 200 Sampling Period [ms]

80 ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.020.png)60 40 

||||
| :- | :- | :- |
||||
||||
||||
||||
8x8 10x15 20x14 23x22

26x19

20 0

0 200 400

Sampling Period [ms]

Copyright ' Azoteq 2024 IQS9150/IQS9151 Datasheet Page 25 of 97 All Rights Reserved Revision v1.1 October 2024
**IQ Switchfi ![ref1]ProxSensefi Series**

*(a) ALP LP1 Mode - Config 2 (b) ALP LP2 Mode - Config 2*

*Figure 4.5: Typical ALP Current Consumption for a Range of Trackpad Sizes![ref2]*

<a name="_page20_x56.69_y84.59"></a>**5 ProxSensefi Module**

The IQS9150/IQS9151 contains a ProxSensefi module that uses patented technology to measure and process the capacitive sensor data. The channel touch and snap are the primary sensor outputs. These are processed further to provide secondary trackpad outputs, including finger position, finger size, and on-chip gesture recognition.

1. **ProxSensefi<a name="_page20_x56.69_y174.18"></a> Engine Consideration**

The IQS9150 has 13 ProxSensefi engines. Rx0 – Rx12 sensors are sensed simultaneously for track- pad sensing, and Rx13 – Rx25 simultaneously after that. Thus, if all 26 Rxs are enabled/used in a trackpad design, each Tx will consist of two cycles of sensing conversions, firstly the Rx0 – Rx12 sensors, and then the Rx13 – Rx25 sensors. The IQS9151 only has 13 Rxs, and therefore only one sensing cycle per Tx is needed.

There is thus no need for allocating channels into sensing cycles.

It is, however, advised that if 13 or fewer Rxs are used, that they are all allocated to the Rx0 - Rx12 group; this will allow for faster sampling periods since there will only be one conversion cycle needed per Tx. If more than 13 are used, it is advised to balance them between the two groups.

2. **Trackpad<a name="_page20_x56.69_y360.28"></a> Channels**

On a trackpad sensor (typically a diamond-shaped pattern), each intersection of an Rx and Tx row/- column forms a mutual-capacitive sensing element, which is referred to as a *channel*. Each channel has an associated count value, reference value, touch status, and snap status (if enabled).

<a name="_page20_x56.69_y442.03"></a>**5.2.1 Channel Numbers**

Trackpad channels are numbered from 0 to ([(*Total Rxs* ](#_page66_x285.33_y716.59)×[*Total Txs*)](#_page66_x285.83_y730.93) − 1). They are assigned from the top-left corner, first along the Rxs before stepping to the next Tx. The channel number must be known for some settings, such as configuring snap channels. Table[ 5.1 ](#_page21_x56.69_y77.81)below is an example of an 8x12 trackpad’s channel numbers:![ref2]

<a name="_page21_x56.69_y77.81"></a>*Table 5.1: Channel Number Assignment*



||**Rx0 (Col 0)**|**Rx1 (Col 1)**|**Rx2 (Col 2)**|**Rx3 (Col 3)**|**Rx4 (Col 4)**|**Rx5 (Col 5)**|**Rx6 (Col 6)**|**Rx7 (Col 7)**|
| :- | :- | :- | :- | :- | :- | :- | :- | :- |
|**Tx21 (Row 0)**|0|1|2|3|4|5|6|7|
|**Tx30 (Row 1)**|8|9|10|11|12|13|14|15|
|**Tx9 (Row 2)**|16|17|18|19|20|21|22|23|
|**Tx22 (Row 3)**|24|25|26|27|28|29|30|31|
|**Tx10 (Row 4)**|32|33|34|35|36|37|38|39|
|**Tx23 (Row 5)**|40|41|42|43|44|45|46|47|
|**Tx31 (Row 6)**|48|49|50|51|52|53|54|55|
|**Tx11 (Row 7)**|56|57|58|59|60|61|62|63|
|**Tx24 (Row 8)**|64|65|66|67|68|69|70|71|
|**Tx12 (Row 9)**|72|73|74|75|76|77|78|79|
|**Tx25 (Row 10)**|80|81|82|83|84|85|86|87|
|**Tx32 (Row 11)**|88|89|90|91|92|93|94|95|

3. **Alternate<a name="_page21_x56.69_y340.63"></a> Low-Power Channel (ALP)**

To provide lower power consumption in LP1 and LP2, activity on the trackpad can be monitored by configuring an ALP channel (single combination sensor) instead of sensing the individual channels as done in Active/Idle modes. To utilise this ALP channel, it needs to be enabled in[` `*ALP Setup*.](#_page66_x282.43_y429.66) If however it is not enabled, then the normal trackpad sensing will remain in LP1 and LP2. Since the alternate channel is processed as only a single channel, much less processing is done, allowing for lower overall power consumption. This channel has a lot of setup flexibility:

- *ALP Setup:*
  - *Count value filtering:* Gives reliable proximity detection in noisy environments.
  - *ALP sensing method:* Mutual-capacitive or self-capacitive.
  - *Rx electrode selection:* Which Rxs are active during ALP conversions.
- [*ALP Tx Enable:*](#_page66_x273.91_y444.01)
  - *Tx electrode selection:* Which Txs are active during ALP conversions.
- [*Other Settings:*](#_page66_x275.23_y415.32)
- *Auto-prox:* Autonomous sensing cycles while the core is asleep, giving further power sav- ings but similar wake-up capability.
4. **Count<a name="_page21_x56.69_y598.25"></a> Value**

The capacitive sensing measurement returns a *count value* for each channel. Count values are in- versely proportional to mutual capacitance, and all outputs are derived from this.

1. **Trackpad<a name="_page21_x56.69_y666.45"></a> Count Values**

The individual trackpad channel count values [(*Trackpad Count Values*)](#_page68_x257.64_y601.82) are unfiltered.

2. **ALP<a name="_page21_x56.69_y720.70"></a> Count Values**

A count value will be obtained from all enabled Rxs in the ALP sensor. The combined count values from all engines will form the ALP channel counts. To reduce processing time (and thus decrease![ref2] current consumption), the measurements are added together [(*ALP Channel Count*)](#_page65_x264.19_y495.69) and processed as a single channel. A count value filter is implemented on this channel to give stable proximity output for system wake-up from low-power mode. It is recommended to leave this count filter enabled in the [*ALP Setup* ](#_page66_x282.43_y429.66)register. The amount of filtering can be modified in[` `*ALP Count Filter Beta* ](#_page66_x240.79_y587.47)if required. This beta is used as follows to determine the damping factor of the filter:

(8 ×Beta − 7) Count damping factor =

2048

If the beta is small, the filtering is stronger (filtered count follows raw count slower), and if the beta is larger, the filtering is weaker (filtered count follows raw count faster).

3. **Trackpad<a name="_page22_x56.69_y248.58"></a> Delta Value**

The signed delta values [(*Trackpad Delta Values*)](#_page68_x259.14_y630.51) are simply:

Delta = Count - Reference

5. **Reference<a name="_page22_x56.69_y338.46"></a> Value/Long-Term Average (LTA)**

User interaction is detected by comparing the measured count values to some reference value. The reference value/LTA of a sensor is slowly updated to track changes in the environment and is not updated during user interaction.

1. **Trackpad<a name="_page22_x56.69_y422.58"></a> References**

The[` `*Trackpad Reference Values* ](#_page68_x249.08_y616.16)are a snapshot (identical to a reseed) of the count value, stored dur- ing a time of no user activity, and thus are a non-affected reference. The trackpad reference values are only updated from LP1 and LP2 mode when modes are managed automatically, where no user interaction is assumed. Thus, if the system is controlled manually, the reference must also be man- aged and updated manually by the host (not recommended).

The reference value is updated or refreshed according to a configurable interval [(*Reference Update Time*](#_page66_x249.95_y329.24)), in seconds. The reference update time has a maximum setting of *60 seconds*.

2. **ALP<a name="_page22_x56.69_y571.68"></a> Long-Term Average**

The ALP channel does not have a snapshot reference value as used on the trackpad but utilises a filtered long-term average value[` `*ALP Channel LTA*.](#_page65_x268.83_y510.04) The LTA tracks the environment closely for accurate comparisons to the measured count value and to allow for small proximity deviations to be sensed.

The speed of LTA tracking can be adjusted in the[` `*ALP LTA Filter Beta* ](#_page66_x240.79_y587.47)registers. There is a beta for LP1 and LP2. This is to allow different settings for different sampling periods so that the speed of LTA tracking can remain the same. These beta settings are used in the same way as for the counts; see

Section[ 5.4.2.](#_page21_x56.69_y720.70)

3. **Reseed**

<a name="_page22_x56.69_y704.85"></a>Since the *Reference* (or *LTA* for ALP channel) is critical for the device to operate correctly, there could be known events or situations that would call for a manual reseed. A reseed takes the latest measured counts and seeds the *reference/LTA* with this value, therefore updating the value to the![ref2] latest environment. A reseed command can be given by setting the corresponding bit *TP Reseed* or *ALP Reseed* in the[` `*System Control* ](#_page66_x273.33_y386.62)register.

6. **Channel<a name="_page23_x56.69_y119.14"></a> Outputs**
1. **Trackpad<a name="_page23_x56.69_y143.47"></a> Touch Output**

The trackpad touch output[` `*Touch Status* ](#_page65_x277.83_y481.35)is set when a channel’s count value increases by more than the selected threshold.

The touch threshold for a specific channel is calculated as follows:

Touch Set/Clear Threshold Multiplier

Threshold = Reference ×(1 + )

128

where *Multiplier* is an 8-bit unsigned value for both the[` `*Touch Set Threshold Multiplier* ](#_page66_x243.52_y458.36)and[` `*Touch Clear Threshold Multiplier*,](#_page66_x239.49_y472.70) allowing a hysteresis to provide improved touch detection. A smaller fraction will

thus be a more sensitive threshold.

A trackpad will have optimal XY data if all the channels in the trackpad exhibit similar deltas under similar user inputs. In such a case all the channels will have identical thresholds. In practice, sensor design and hardware restrictions could cause deltas that are not constant over the entire trackpad. It could then be required to select individual multiplier values. These[` `*Individual Touch Threshold Adjust- ments* ](#_page67_x224.60_y601.82)are signed 8-bit values and indicate how much the unsigned 8-bit global value *Touch Set/Clear Threshold Multiplier* must be adjusted. The threshold used for a specificchannel (set and clear) is as follows:

Adjusted Multiplier = Set/Clear Threshold Multiplier**+**Individual Threshold Adjustment

2. **Trackpad<a name="_page23_x56.69_y482.66"></a> Snap Output**

Whenaddingametalsnap-domeoverlaytothetrackpadpattern,anadditionalsnapoutputisavailable in the[` `*Snap Status* ](#_page65_x279.41_y538.73)register. The device is able to distinguish between a normal ‘touch’ on the overlay and an actual button ‘snap’, which depresses the metal dome onto the Rx/Tx pattern. The design must be configured so that a snap on the metal dome will result in a channels count value falling well below the reference for that channel. If required, the function must be enabled in the[` `*Trackpad Snap Channel Enable* ](#_page67_x240.67_y587.47)register for each channel on which snap is designed. Only channels with snap must be marked as such, since channels are handled differently if they are snap channels compared to non-snap channels.

When a snap is performed, a sensor saturation effect causes the deviation to be negative. Because it is only necessary to read the individual snap registers if a state change has occurred, a status bit (*Snap Toggle*) is added to the[` `*Info Flags* ](#_page65_x284.17_y309.19)register to indicate this. This is only set when there is a change of status of any snap channel. A reseed is executed if a snap is sensed for longer than the [*Snap Timeout* ](#_page66_x275.91_y357.93)(in seconds). A setting of ‘0’ will never reseed. The timeout is reset if any snap is set or cleared.

The trackpad snap output *Snap Status* is set when a channel’s snap count value decreases by more than the selected threshold.![ref2]

The threshold for a snap channel is determined as follows:

Threshold = Reference - Snap Threshold

This output is set when a channel’s count value decreases below the selected threshold – thus a delta setting.[` `*Snap Set Threshold* ](#_page66_x249.59_y544.43)is an 8-bit unsigned value for the ‘set’ threshold.[` `*Snap Clear Threshold* ](#_page66_x245.56_y558.78)is an 8-bit unsigned value for the ‘clear’ threshold, allowing a hysteresis to provide improved snap detection.

3. **ALP<a name="_page24_x56.69_y212.81"></a> Output**

The *ALP Prox Status* flag in[` `*Info Flags* ](#_page65_x284.17_y309.19)is set when a channes count value deviates (positive or neg- ative) from the LTA value by more than the selected threshold – thus a delta setting[` `*ALP Output Threshold*.](#_page66_x244.81_y487.05) This can be used to implement proximity or touch detection, depending on the threshold

used. In auto-prox mode, a deviation on any of the individual count values will wake the system from the auto-prox process. Since this is an individual unfiltered reading (compared to the filtered ALP Count value), it has a separate configurable[` `*ALP Auto-Prox Threshold*,](#_page66_x238.56_y501.39) which is also a delta value for positive or negative deviations of the individual count values.

4. **Output<a name="_page24_x56.69_y350.73"></a> Debounce**

There is no debounce on the trackpad touch or snap detection (or release). This is because debounc- ing adds too much delay, and fast movements on the touch panel cannot be debounced fast enough to provide reliable XY output data.

Debounce on the ALP output is, however, done to allow for stable proximity detection if needed. Two 8-bit unsigned values are used for the set and clear debounce parameters,[` `*ALP Set Debounce* ](#_page66_x265.73_y515.74)and [*ALP Clear Debounce*.](#_page66_x261.70_y530.09)

7. **Automatic<a name="_page24_x56.69_y481.26"></a> Tuning Implementation (ATI)**

The ATI is a sophisticated technology implemented in the new ProxSensefi devices to allow optimal performance of the devices for a wide range of sensing electrode capacitances without modification to external components. The ATI settings allow tuning of various parameters.

The main advantage of the ATI is to balance out small variations between trackpad hardware and the IQS9150/IQS9151 variation to give similar performance across devices and temperatures.

1. **Trackpad<a name="_page24_x56.69_y604.63"></a> ATI**

The[` `*Trackpad ATI Multiplier/Dividers* ](#_page65_x223.91_y682.19)can be used to configure the base value for the trackpad chan- nels. There is one global setting parameter for all the active trackpad channels for the coarse divider and one for the coarse multiplier. The coarse divider is a 5-bit setting (0-31) and the coarse multiplier a 4-bit setting (0-15). The coarse divider/multiplier are configured in the Azoteq GUI software in pre- defined sets of divider and multiplier combinations. This helps to simplify the configuration of this ATI parameter, and to help make sure optimal combinations are used.

Thefinedivider/multiplierisalsousedtoconfigurethetrackpadbasevalue.Thereisoneglobalsetting parameter for all the active trackpad channels for the finedivider. The finedivider is a 5-bit setting (0- 31) and the fine multiplier a 2-bit setting (0-2). It is recommended to set the fine multiplier to 1.![ref2] The[` `*ATI Compensation Values* ](#_page68_x232.88_y644.86)for each channel are set by the ATI procedure and are chosen so that each count value is close to the selected[` `*ATI Target*.](#_page65_x264.05_y710.88)

The sensitivity of the trackpad channels increase in direct proportion to the ratio of the trackpad target counts to the trackpad base counts.

Target Counts

Sensitivity ?

Base Counts

The algorithm is queued by setting the *TP Re-ATI* bit in the[` `*System Control* ](#_page66_x273.33_y386.62)register. The *TP Re-ATI* bit clears automatically on chip when the algorithm has completed.

The queued re-ATI routine will execute as soon as the corresponding channels are sensed. For ex- ample, the trackpad re-ATI when the system is in Active, Idle-Touch, or Idle mode.

This routine will only execute after the communication window is terminated, and the I2C communica- tion will only resume once the ATI routine has completed.

*ATICompensation* are10-bitvalues,thus0to1023.The *ATICompensation* canbescaledbymeansof the *Compensation Divider*. The 5-bit *Compensation Divider* values are also automatically configured together with the *ATI Compensation* during the ATI procedure.

2. **ALP<a name="_page25_x56.69_y373.91"></a> ATI**

The *ALP ATI Mode* is configured in the[` `*Config Settings* ](#_page66_x273.46_y400.97)register. Users can choose between two op- tions: *Full ATI* and *Compensation Only* ATI. In contrast to the manual user configuration for trackpad channels’ ATI parameters, when *Full ATI* mode is selected, users set both an[` `*ALP Base Target* ](#_page65_x262.39_y739.58)and an [*ALP ATI Target* ](#_page65_x273.86_y725.23)for the automatic ATI parameter configuration of the ALP channel. The ALP channel

uses both[` `*ALP Coarse and Fine Dividers/Multipliers* ](#_page65_x223.91_y682.19)in its configuration.

The *ALP Base Target* acts as a reference point for the ATI algorithm. The algorithm uses the *Coarse and Fine Dividers/Multipliers* to reach the *Base Target*, from which the[` `*ALP Compensation* ](#_page65_x257.37_y610.46)is incor- porated to reach the *ALP ATI Target*. The *ALP ATI Target* value applies to each of the[` `*ALP Individual Count* ](#_page65_x259.71_y524.38)values configured for the ALP channel, resulting in the combined channel possessing an[` `*ALP Count* ](#_page65_x264.19_y495.69)value larger than the *ALP ATI Target*, as it is a sum of the individual Rx engine count values.

If the user selects *Compensation Only* for the *ALP ATI Mode*, the ATI parameters are configured in

the same manner as those for the trackpad channels.

The ALP channel has individual *ALP Compensation* values and *ALP ATI Compensation Dividers* for each of the 13 ProxSensefi engines.

The algorithm is queued by setting the *ALP Re-ATI* bit in the[` `*System Control* ](#_page66_x273.33_y386.62)register. The *ALP Re-ATI* bit clears automatically on chip when the algorithm has completed. The ALP channel will execute the re-ATI command when the system is in LP1 or LP2.

8. **Automatic<a name="_page25_x56.69_y688.59"></a> Re-ATI**
1. **Description**

<a name="_page25_x56.69_y712.92"></a>When *TP Re-ATI EN* or *ALP Re-ATI EN* are enabled in[` `*Config Settings*,](#_page66_x273.46_y400.97) a re-ATI will be triggered if certain conditions are met. One of the most important features of the re-ATI is that it allows easy![ref2] and fast recovery from an incorrect ATI, such as when performing ATI during user interaction with the sensor. This could cause the wrong ATI Compensation to be configured since the user affectsthe capacitance of the sensor. A re-ATI would correct this. It is recommended to always have this enabled. When a re-ATI is performed on the IQS9150/IQS9151, a status bit (*TP/ALP Re-ATI Occurred*) will set momentarily in[` `*Info Flags* ](#_page65_x284.17_y309.19)to indicate that this has occurred.

2. **Conditions<a name="_page26_x56.69_y159.79"></a> for Re-ATI to activate**
1. **Reference drift**

   A re-ATI is performed when the reference of a channel drifts outside of the acceptable range around the ATI Target. The boundaries where re-ATI occurs for the trackpad channels and for the ALP channels are independently set via the drift threshold value[` `*Reference Drift Limit*](#_page66_x243.48_y128.39)[/*ALP LTA Drift Limit*.](#_page66_x266.48_y142.74) The re-ATI boundaries are calculated from the delta value as follows:

Re-ATI Boundary = ATI target ± Drift limit

For example, assume that the ATI target is configured to 800 and that the reference drift value is set to 50. If re-ATI is enabled, the ATI algorithm will be repeated under the following conditions:

Reference > 850 or Reference < 750

The ATI algorithm executes in a short time, so it goes unnoticed by the user.

2. **Trackpad Negative Delta Re-ATI**

   A considerable decrease in the count value of a trackpad channel is abnormal since user inter- action increases the count value. Therefore, if a decrease larger than the configurable threshold [*Trackpad Negative Delta Re-ATI Value* ](#_page66_x227.61_y99.70)is seen on such a trackpad channel, it is closely moni- tored. If this is continuously seen for 15 cycles, it will trigger a re-ATI.

3. **Trackpad Positive Delta Re-ATI**

   Enabling snap sensors presents an issue where, during an ATI, if a metal dome press occurs, an abnormally large positive delta is detected upon release – much larger than what would be expected from a regular user touch. To address this, if a positive delta exceeding the[` `*Trackpad Positive Delta Re-ATI Value* ](#_page66_x229.69_y114.05)is identified on a trackpad channel, it triggers a re-ATI after 15 consecutive cycles for recovery.

3. **ATI<a name="_page26_x56.69_y572.50"></a> Error**

After the ATI algorithm is performed, a check is done to see if there was any error with the algorithm. An ATI error is reported if one of the following is true for any channel after the ATI has completed:

- ATI Compensation = 0 (min value)
- ATI Compensation = 1023 (max value)
- Count is already outside the re-ATI range upon completion of the ATI algorithm

If any of these conditions are met, the corresponding *ATI Error/ALP ATI Error* flag will be set in the [*Info Flags* ](#_page71_x56.69_y84.59)register. The flag status is only updated again when a new ATI algorithm is performed.

**Note:** Re-ATI will not be repeated immediately if an ATI Error occurs.![ref2]

A configurable time[` `*Re-ATI Retry Time* ](#_page66_x260.45_y314.89)will pass where the re-ATI is momentarily suppressed. This is to prevent the re-ATI repeating indefinitely. An ATI error should, however, not occur under normal circumstances. The Re-ATI retry time has a maximum setting of *60 seconds*.![ref2]

<a name="_page28_x56.69_y84.59"></a>**6 Sensing Modes**

The IQS9150/IQS9151 automatically switches between different charging modes dependent on user interaction and other aspects. This is to allow for fast response and low power consumption when applicable. The current *Charging Mode* can be read from the[` `*Info Flags* ](#_page65_x284.17_y309.19)register.

The modes are best illustrated by means of the following state diagram.

<a name="_page28_x56.69_y182.36"></a>Finger movement detected![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.021.png)

Change in number of fingers

Trackpad movement or  Snap set/cleared

snap toggled

Action: reset stationary 

touch timer Stationary touch timeout

Active  (thus stationary touch) Idle-

Mode Touch (in touch) Mode

Touch & snap released Touch or snap

Action: Start active timeout

No touch & no snap

Idle-touch timeout Active  Action: reseed trackpad

Mode

(no touch)

These modes are always  Idle the trackpad channels  Mode

sensing.  Touch and 

snap are processed.

te

a

d

p

` `u

~~e~~

c

n

re e

fe et

re pl

al  m x n o ro

LP1 and LP2: cas io ate c r  LP p

c pd A These can be either the  O U ch o

trackpad (only touch  d tou processing) or an  ckpa

alternative LP channel  Tra

setup

LP2 LP1 Mode LP1 timeout Mode

*Figure 6.1: System Mode State Diagram![ref2]*

1. **Sampling<a name="_page29_x56.69_y84.59"></a> Period**

The sampling period for each mode can be adjusted as required by the design. A shorter sampling period will have a higher current consumption but will give a faster response to user interaction. *Active mode* typically has the shortest sampling period, and the other modes are configured according to the

power budget of the design and the expected response time.

The sampling period is configured by selecting the cycle time (in milliseconds) for each mode:

- [*Active Mode Sampling Period*](#_page66_x235.05_y171.43)
- [*Idle-Touch Mode Sampling Period*](#_page66_x226.71_y185.78)
- [*Idle Mode Sampling Period*](#_page66_x239.90_y200.12)
- [*LP1 Mode Sampling Period*](#_page66_x239.15_y214.47)
- [*LP2 Mode Sampling Period*](#_page66_x239.15_y228.82)
2. **Mode<a name="_page29_x56.69_y271.48"></a> Timeout**

The timeout values are configurable, and once these durations have passed, the system will transition to the next state as depicted in Figure[ 6.1.](#_page28_x56.69_y182.36) You can adjust these durations by selecting your desired value (in seconds) for each specific timeout.

- [*Stationary Touch Timeout*](#_page66_x246.33_y243.16)
- [*Idle-Touch Mode Timeout*](#_page66_x247.03_y257.51)
- [*Idle Mode Timeout*](#_page66_x260.22_y271.85)
- [*LP1 Mode Timeout*](#_page66_x259.47_y286.20)
- [*Active to Idle Mode Timeout (ms)*](#_page66_x238.22_y300.55)

**Note:** Active Mode includes two timeout settings:

- *Stationary Touch Timeout*, which triggers when the touch is stationary in Active Mode, transi- tioning the mode to Idle-Touch mode.
- *Active to Idle Mode Timeout*, which triggers upon touch/snap release.

A timeout value of ‘0’ will result in a ‘never’ timeout condition.

3. **Manual<a name="_page29_x56.69_y529.98"></a> Control**

The default method (manual control disabled) allows the IQS9150/IQS9151 to automatically switch between modes and update[` `*Trackpad Reference Values* ](#_page68_x249.08_y616.16)as shown in Figure[ 6.1.](#_page28_x56.69_y182.36) This requires no interaction from the master to manage the device and is the recommended option.

The master can manage various states and implement custom power modes when *Manual Control* is enabled in[` `*Config Settings*.](#_page66_x273.46_y400.97) The master needs to control the mode (*Mode Select*) and also manage the reference values by reseeding (*TP Reseed*). Both settings are available in the[` `*System Control* ](#_page66_x273.33_y386.62)register.![ref2]

<a name="_page30_x56.69_y84.59"></a>**7 Trackpad**

1. **Configuration**
1. <a name="_page30_x56.69_y101.97"></a>**Size<a name="_page30_x56.69_y124.49"></a> Selection**

The total number of Rx and Tx channels used for trackpad purposes must be configured as[` `*Total Rxs*](#_page66_x285.33_y716.59)[/*Total Txs*.](#_page66_x285.83_y730.93) This gives a rectangular area of channels, formed by rows and columns of Rx and Tx sensors.

2. **Trackpad<a name="_page30_x56.69_y202.77"></a> Channel and Electrode Limitations**

The IQS9150 product supports up to 506 channels, with a maximum of 45 electrodes. Up to 26 Rxs and up to 22 Txs can be configured, but the total number of Rxs and Txs combined cannot exceed 45 electrodes. The IQS9151 supports up to 156 channels, consisting of a maximum of 25 electrodes, with limitations of up to 13 Rxs and up to 22 Txs. Any trackpad size and configuration that fits into these limits are possible to implement.

3. **Individual<a name="_page30_x56.69_y313.60"></a> Channel Disabling**

If the sensor is not a complete rectangle (this could be due to mechanical cut-outs or trackpad shape), there will be some channels that fall within the[` `*Total Rxs*](#_page66_x285.33_y716.59)[/*Total Txs* ](#_page66_x285.83_y730.93)rectangle but do not exist. The channel numbers are still allocated for the complete rectangle (see Section[ 5.2.1).](#_page20_x56.69_y442.03) However, these channels can be disabled individually using the[` `*Trackpad Channel Disable* ](#_page67_x251.40_y573.12)registers.

4. **Rx/Tx<a name="_page30_x56.69_y408.50"></a> Mapping**

The Rxs and Txs of the trackpad can be assigned to the trackpad in any order to simplify PCB layout and design. The[` `*RxTx Mapping* ](#_page67_x274.92_y558.78)configures which actual Rx and Tx electrodes are used for the track- pad. The Rxs are specified first, up until the number of Rxs as defined by the[` `*Total Rxs* ](#_page66_x285.33_y716.59)register, then the Txs follow immediately.

Following the example in Table[ 5.1,](#_page21_x56.69_y77.81) the *RxTx Mapping* settings will be as follows:

RxTxMapping[0] = 0 RxTxMapping[1] = 1 RxTxMapping[2] = 2 RxTxMapping[3] = 3 RxTxMapping[4] = 4 RxTxMapping[5] = 5 RxTxMapping[6] = 6 RxTxMapping[7] = 7 RxTxMapping[8] = 21 RxTxMapping[9] = 30 RxTxMapping[10] = 9 RxTxMapping[11] = 22 RxTxMapping[12] = 10 RxTxMapping[13] = 23 RxTxMapping[14] = 31 RxTxMapping[15] = 11 RxTxMapping[16] = 24 RxTxMapping[17] = 12![ref2]

RxTxMapping[18] = 25 RxTxMapping[19] = 32 RxTxMapping[20..44] = n/a

2. **Trackpad<a name="_page31_x56.69_y131.68"></a> Outputs**

The channel count variation (deltas) and touch status outputs are used to calculate finger location data.

1. **Number<a name="_page31_x56.69_y196.48"></a> of Fingers**

*Number of Fingers* in the[` `*Trackpad Flags* ](#_page65_x273.32_y323.54)register gives an indication of the number of active finger inputs on the trackpad.

2. **Relative<a name="_page31_x56.69_y265.64"></a> XY**

If there is only one finger active, a[` `*Relative X* ](#_page65_x283.52_y223.11)and[` `*Relative Y* ](#_page65_x283.52_y237.46)value are available. This is a signed 2’s complement 16-bit value. It is a delta of the change in X and Y in the scale of the selected output resolution.

3. **Absolute<a name="_page31_x56.69_y343.59"></a> XY**

Forallmulti-touchinputs,theabsolutefingerpositionsarereportedinthe[` `*FingerX/Y-Coordinate* ](#_page65_x260.01_y337.88)regis- ters, where the coordinate output is based on the selected resolution. This means that the coordinates will range between 0 and the selected[` `*Resolution X/Y*.](#_page67_x278.44_y99.70)

4. **Touch<a name="_page31_x56.69_y426.30"></a> Strength**

This value[` `*Touch Strength* ](#_page65_x255.97_y366.58)indicates the strength of the touch by giving a sum of all the deltas associ- ated with the finger and therefore varies according to the sensitivity setup of the sensors.

5. **Area**

<a name="_page31_x56.69_y493.08"></a>The number of channels associated with a fingeris provided in the[` `*Finger Area* ](#_page65_x276.70_y380.92)registers. This area is usually equal to or smaller than the number of touch channels under the finger.

6. **Tracking<a name="_page31_x56.69_y559.86"></a> Identification**

The fingers are tracked from one cycle to the next, and the same fingerwill be in the same position in the memory map. The memory location thus identifies the finger.

3. **Maximum<a name="_page31_x56.69_y626.65"></a> Number of Multi-touches**

The maximum number of allowed multi-touches is configurable[` `*Max Multi-Touches* ](#_page66_x266.71_y745.28)up to 7 points. If more than the selected value is sensed, the *Too Many Fingers* flag is set in the[` `*Info Flags* ](#_page65_x284.17_y309.19)register, and the XY data is cleared.

4. **XY<a name="_page31_x56.69_y705.00"></a> Resolution**

The output resolution for the X and Y coordinates is configurable[` `*X/Y Resolution*.](#_page67_x278.44_y99.70) The on-chip algo- rithms use 256 points between each row and column. The resolution is definedas the total X and total Y output range across the complete trackpad.![ref2]

5. **Stationary<a name="_page32_x56.69_y84.59"></a> Touch**

A stationary touch is definedas a point that does not move outside a certain boundary within a specific time. This movement boundary or threshold can be configured in the[` `*Stationary Touch Movement Threshold* ](#_page67_x227.11_y185.78)register and is defined as a movement in either X or Y in the configured resolution.

The device will switch to *Idle-Touch* mode when a stationary point is detected for the[` `*Stationary Touch Timeout (s)* ](#_page66_x246.33_y243.16)period, where a lower duty cycle can be implemented to save power in applications where long touches are expected.

If movement is detected, the *Movement Detected* flag is set in[` `*Trackpad Flags*.](#_page65_x273.32_y323.54)

6. **Multi-touch<a name="_page32_x56.69_y230.83"></a> Finger Split**

The position algorithm looks at areas (polygons) of touches and calculates positional data from this. Two fingers near each other could have areas touching, which would merge them incorrectly into a single point. A finger split algorithm is implemented to separate these merged polygons into multiple fingers. The[` `*Finger Split Factor* ](#_page67_x267.39_y200.12)can be adjusted to determine how aggressive this fingersplitting must be implemented. A value of ‘0’ will not split polygons and thus merge any fingers with touch channels adjacent (diagonally also) to each other.

7. **XY<a name="_page32_x56.69_y353.23"></a> Output Flip & Switch**

By default, X positions are calculated from the first column to the last column. Y positions are by default calculated from the first row to the last row. The X and/or Y output can be flipped by setting the relevant bits (*Flip X/Flip Y*) in[` `*Trackpad Settings* ](#_page66_x268.13_y702.24)to allow the [0, 0] coordinate to be defined as desired. The X and Y axes can also be switched (*Switch XY Axis*), allowing X to be the Txs and Y to be along the Rxs.

**Note:** The channel numbers are still assigned the same way, first along the Rxs, then to the next Tx; it is not affected by this setting.

8. **XY<a name="_page32_x56.69_y500.08"></a> Position Filtering**

Stable XY position data is available due to two on-chip filters, namely the Moving Average (MAV) filter and the Infinite Impulse Response (IIR) filter. The filters are applied to the raw positional data. It is recommended to keep both filters enabled for optimal XY data.

1. **IIR<a name="_page32_x56.69_y581.83"></a> Filter**

The *IIR Filter*, if enabled in[` `*Trackpad Settings*,](#_page66_x268.13_y702.24) can be configured to select between a dynamic and a static filter.

Beta Damping factor =

256

1. **Dynamic Filter**

   Relative to the speed of movement of a coordinate, the filter dynamically adjusts the amount of filtering (damping factor) performed. When fast movement is detected and quick response is required, less filtering is done. Similarly, when a coordinate is stationary or moving at a slower speed, more filtering can be applied.![ref2] Thedampingfactorisadjusteddependingonthespeedofmovement.Threeoftheseparameters are adjustable to fine-tune the dynamic filter if required:

- [*XY Dynamic Filter Bottom Speed*](#_page67_x238.45_y128.39)
- [*XY Dynamic Filter Top Speed*](#_page67_x245.24_y142.74)
- [*XY Dynamic Filter Bottom Beta*](#_page67_x242.23_y157.09)

The speed is defined as the distance (in the selected resolution) travelled in one cycle (pixels/- cycle).

No filtering ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.022.png)

Filter damping  

factor (beta) 

Lower Beta (more filtering) 

Bottom Speed Top Speed Speed of 

movement

*Figure 7.1: Dynamic Filter Parameters*

2. **Static Filter**

   Coordinates filtered with a fixed but configurable damping factor [(*XY Static Filter Beta*)](#_page67_x263.83_y171.43) are ob- tained using the static filter *IIR Static*. It is recommended that the dynamic filter is used due to the advantages of a dynamically changing damping value.

2. **Jitter<a name="_page33_x56.69_y464.77"></a> Filter**

To prevent small finger coordinate movements for a stationary finger, a jitter filter is implemented. The *Jitter Filter* can be enabled in the[` `*Trackpad Settings* ](#_page66_x268.13_y702.24)register. The jitter filter will only allow initial movement once the finger has moved an initial configurable distance [(*Jitter Filter Delta Threshold*)](#_page67_x250.18_y243.16) in

either x or y.

9. **X<a name="_page33_x56.69_y558.78"></a> & Y Trim**

Due to boundary conditions at the edges of the trackpad, it is unlikely that the X and Y extreme values will be achievable (0 and X/Y Resolution). To be able to achieve this, the edges can be trimmed with a configurable amount of[` `*X Trim* ](#_page67_x278.58_y214.47)or[` `*Y Trim* ](#_page67_x278.58_y214.47)on-chip. For example, say *X Trim* is set to 0, and a fingeron the left of the trackpad gives a minimum X output of 48 and a maximum of 960 for a finger to the far right (for X resolution set to 1000). Then an X Trim = 50 could be used to trim away the ‘dead’ area, and the full 0 to 1000 range will be achievable.

10. **Finger<a name="_page33_x56.69_y680.28"></a> Confidence**

For each finger on the trackpad, there is a *Finger Confidence* bit in the[` `*Trackpad Flags* ](#_page65_x273.32_y323.54)register to indicate whether there is confidence that this is a legitimate finger input. For normal finger inputs, the bit will be set (1), indicating high confidence that this is an acceptable trackpad input. If the finger area is larger than a configurable[` `*Finger ConfidenceThreshold*,](#_page67_x246.05_y257.51) then the confidencebit related to that finger will clear (0), and it will remain cleared until that finger is removed.![ref2]

11. **Saturation**

<a name="_page34_x56.69_y84.59"></a>Sensor saturation is a non-ideal response from the touchpad to a specific user input. Saturation can be improved with design aspects. For more information, please see[ AZD068.](https://www.azoteq.com/design/application-notes/)

If any touch on the trackpad senses saturation occurring within the touch area, then the saturation bit will become set. Ideally, you would like your design to never have this set.![ref2]

<a name="_page35_x56.69_y84.59"></a>**8 Gestures**

The IQS9150/IQS9151 has an on-chip gesture recognition engine for single and two-fingergestures. The list of[` `*Single Finger Gestures* ](#_page65_x258.04_y280.50)and[` `*Two-Finger Gestures* ](#_page65_x262.25_y294.84)recognised by the device is as follows:

- Single finger gestures:
  - Single tap
  - Double tap
  - Triple tap
  - Press-and-Hold
  - Swipe X+ (with continuous swipe configurable)
  - Swipe X- (with continuous swipe configurable)
  - Swipe Y+ (with continuous swipe configurable)
  - Swipe Y- (with continuous swipe configurable)
  - Swipe and hold X+
  - Swipe and hold X-
  - Swipe and hold Y+
  - Swipe and hold Y-
  - Palm (Flat hand)
- Two-finger gestures:
- Single tap
- Double tap
- Triple tap
- Press-and-Hold
- Zoom in
- Zoom out
- Vertical scroll
- Horizontal scroll

Each gesture can individually be enabled or disabled by setting or clearing the corresponding bits in the relevant register,[` `*Single Finger Gesture Enable* ](#_page67_x245.08_y286.20)or[` `*Two Finger Gesture Enable*.](#_page67_x249.29_y300.55)

Each gesture has parameters that define and configure its functionality.

1. **Single,<a name="_page35_x56.69_y530.85"></a> Double and Triple Tap Gesture**

The tap gestures (*Single Tap, Double Tap, Triple Tap*) require that a touch be made and released in the same location and within a short period of time. Some small amount of movement from the initial coordinate is allowed to compensate for expected finger movement while tapping on the sensor. This bound is defined in register[` `*Tap Distance*,](#_page67_x262.32_y343.59) which specifies the maximum deviation in pixels the touch is allowed to move before the tap gesture is no longer valid.

Similarly, the[` `*Tap Time* ](#_page67_x275.12_y314.89)register defines the maximum touch duration (in milliseconds) that will result in a valid gesture. The period is measured from the moment a touch is registered. The touch should be released before the *Tap Time* has elapsed for the tap to be reported.

The[` `*Air Time* ](#_page67_x276.92_y329.24)parameter definesthe maximum duration (in milliseconds) that is allowed between taps (while the finger is NOT touching the sensors) for double and triple taps to be detected. The next touch must be detected before the *Air Time* has expired, starting at the moment the previous touch is released, to continue the multiple tap sequence.

With double/triple taps enabled, the engine first needs to wait to confirmwhether the current detected![ref2]

tap is part of a multi-tap gesture before the tap output can be provided. If subsequent taps are NOT enabled, the tap gesture will be immediately reported on the release of the tap touch. If subsequent taps ARE enabled, the current tap gesture will only be reported when the time specified by the *Air Time* parameter has elapsed and no further taps have begun. For example, double taps require an *Air Time* waiting period if, and only if, triple taps are enabled.

Since the gesture reports after the finger is removed and no XY data is available, the location of the tap gesture is placed in the[` `*Gesture X* ](#_page65_x283.70_y251.81)and[` `*Gesture Y* ](#_page65_x283.70_y266.15)registers.

The gesture engine will clear relative XY registers[` `*Relative X* ](#_page65_x283.52_y223.11)and[` `*Relative Y* ](#_page65_x283.52_y237.46)to prevent small cursor movement during tap detection.

Below are numerous scenarios illustrating the tap outputs.

Tap time Tap time Tap time![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.023.png)

Air time Air time Air time

Touch (stationary)

st 2nd rd

1 touch 3 touch touch

No touch

(Movedistmaenncet <) Tap  (Movedismtaennct e<) Tap (Movedistmeanncet <) Tap time

Single tap – enabled ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.024.png)Gesture output Triple tap Double tap – enabled

Triple tap - enabled

time

Single tap – enabled Double tap Single tap Double tap – enabled

Gesture output Triple tap - disabled time

Single tap Single tap Single tap SDionugblelet atapp––edniasablbelded Gesture output Triple tap - disabled

time

*Figure 8.1: Three Taps - Output Scenarios![ref2]*

Tap time Tap time![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.025.png)

Air time Air time

Touch (stationary)

1st touch 2nd touch

No touch

(Movedistmeanncet <) Tap  (Movedistmaenncet <) Tap  time

Single tap – enabled ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.026.png)Gesture output Double tap Double tap – enabled

Triple tap - enabled

time

Single tap – enabled Double tap Double tap – enabled

Gesture output Triple tap - disabled time

Single tap Single tap SDionugblelet atapp––edniasablbelded Gesture output Triple tap - disabled

time

*Figure 8.2: Two Taps - Output Scenarios*

Tap time![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.027.png)

Air time

Touch (stationary)

1st touch

No touch

(Movedistmeanncet <) Tap  time

Single tap – enabled ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.028.png)Gesture output Single tap Double tap – enabled

Triple tap - enabled

time

Single tap SDionugblelet atapp––eennaabbleledd Gesture output Triple tap - disabled

time

Single tap – enabled Single tap Double tap – disabled

Gesture output Triple tap - disabled time

*Figure 8.3: Single Tap - Output Scenarios![ref2]*

Tap time Tap time Tap time![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.029.png)

Air time Air time Air time

Touch (stationary)

1st 2nd touch 3rd touch

touch

No touch

(Movement < Tap  (Movement < Tap distance) (Movement < Tap 

distance) distance) time

Tap too long- Single tap – enabled Gesture  gestures reset Single tap Double tap – enabled output Triple tap - enabled

time

Tap too long-

gestures reset Single tap SiDonugblelet atapp––eennaabbleledd

Gesture 

output Triple tap - disabled

time

Tap too long- Single tap – enabled Gesture  Single tap gestures reset Single tap Double tap – disabled output Triple tap - disabled

time

*Figure 8.4: Tap Time Elapsed*

Tap time Tap time Tap time![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.030.png)

Air time Air time Air time

Touch (stationary)

1st 2nd 3rd touch touch touch

No touch

(Movedistmaenncet <) Tap  (Movedismetannct e<) Tap  (Movedismetannct e<) Tap  time

Single tap – enabled Gesture  Single tap Double tap Double tap – enabled

output Triple tap - enabled

time

Single tap – enabled Gesture  Single tap Double tap Double tap – enabled

output Triple tap - disabled

time

Single tap – enabled Gesture  Single tap Single tap Single tap Double tap – disabled

output Triple tap - disabled

time

*Figure 8.5: Air Time Elapsed![ref2]*

Tap time Tap time Tap time![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.031.png)

Air time Air time Air time

Touch

st 2nd rd

1 touch 3 touch

touch

No touch

(Movedismetannct e<) Tap  (Movedistmaenncet <) Tap  time

Touch  ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.032.png)

Gesture output Gesture reset Single tap SDionugblelet atapp––eennaabbleledd

movement

Triple tap - enabled

time 

Single tap – enabled Single tap Double tap – enabled

Gesture output Triple tap - disabled

time 

Single tap – enabled Single tap Single tap Double tap – disabled

Gesture output Triple tap - disabled time

*Figure 8.6: Finger Movement*

2. **Press-and-Hold<a name="_page39_x56.69_y410.14"></a> Gesture**

The same register that defines the bounds for the single tap gesture,[` `*Tap Distance*,](#_page67_x262.32_y343.59) is used for the Press-and-Hold gesture.

If a touch remains within the given bound for longer than the[` `*Hold Time* ](#_page67_x273.18_y357.93)(in milliseconds), a Press- and-Hold gesture will be reported in the[` `*Single Finger Gestures* ](#_page65_x258.04_y280.50)register. The gesture will continue to be reported until the specific touch is released, even if finger movement resumes.

Similarly, there is also a two-finger Press-and-Hold, which requires two fingers in touch and follows the same conditions for activation. The two-fingerPress-and-Hold gesture will be reported in the[` `*Two- Finger Gestures* ](#_page65_x262.25_y294.84)register.

Relative data will be reported in the[` `*Gesture X/Y* ](#_page65_x283.70_y251.81)registers once the gesture has been triggered. This allows for features such as drag-and-drop. For a one-fingerPress-and-Hold gesture, the *Gesture X/Y* values will be exactly the same as the[` `*Relative X/Y* ](#_page65_x283.52_y223.11)register values. For a two-finger Press-and-Hold gesture, it will represent the relative movement of the average position of the fingers.

Once the gesture has triggered, the number of fingers must remain constant. For example, for a one- finger Press-and-Hold, the gesture will clear if there is ever not one finger in touch. Likewise, for a two-finger Press-and-Hold, there must always be two fingers in touch. If the gesture clears and there is still a touch, the *Gesture X/Y* registers will be zeroed, and the user must completely go out of touch before any gestures will be reported again.![ref2]

Hold Time![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.033.png)

Touch

Touch

No touch

time

Stationary  Touch 

touch movement

Gesture 

output Press-and-hold 

gesture

time

*Figure 8.7: Press-and-Hold*

3. **Swipe<a name="_page40_x56.69_y300.21"></a> Gesture**
1. **Single<a name="_page40_x56.69_y326.92"></a> Swipe**

All four swipe gestures (*Swipe X+, Swipe X-, Swipe Y+, Swipe Y-*) work in the same manner and are only differentiated in their direction. The direction is defined with respect to the origin (0, 0) of the trackpad. If the touch is moving away from the origin, it is considered a positive swipe (+). If it is moving towards the origin, it is a negative swipe (-). Whether the swipe is of the type X or Y is defined by which axis the touch is moving approximately parallel to.

Aswipegestureeventisonlyreportedwhenamovingtouchmeetsallthreeofthefollowingconditions:

1. A minimum distance is travelled from its initial coordinates, as defined in pixels by the value in registers[` `*Swipe Initial X-Distance* ](#_page67_x241.42_y386.62)and[` `*Swipe Initial Y-Distance*.](#_page67_x241.58_y400.97)
1. The distance in (1) is covered within the time specified in[` `*Swipe Time* ](#_page67_x270.19_y372.28)(in milliseconds).
1. The angle of the swipe gesture, as determined by its starting coordinate and the coordinate at which conditions (1) and (2) were first met, does not exceed the threshold in[` `*Swipe Angle* ](#_page67_x252.98_y444.01)with regards to at least 1 of the axes.

The respective swipe gesture will be reported for 1 cycle when all these conditions are met. The relative distance travelled each cycle will be reported in the[` `*Relative X/Y* ](#_page65_x283.52_y223.11)registers throughout.

The value in register *Swipe Angle* is calculated as 64 tanā, where ā is the desired angle (in degrees).![ref2]

Swipe Angle (θ) ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.034.png)![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.035.png)

- touch point 

Swipe Angle (θ)

(0, 0)

*Figure 8.8: Illustration of the Swipe Angle Requirement*

The relative X and Y movement used to determine the swipe is available in the[` `*Gesture X/Y* ](#_page65_x283.70_y251.81)registers. The swipe angle and distance can be calculated from the data reported in these registers. This allows customers with orientation-sensing capability to normalise the swipe to the orientation of the product. The *Swipe Angle* parameter should be set to obtain 45 degrees (thus always allowing a swipe), and the master can accept or reject swipes depending on the adjusted swipe angle.

- (Gesture X, Gesture Y) ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.036.png)

θ  = arctan2(−1500,1000) 

(-1500, 1000)

θ

(0, 0)

*Figure 8.9: Swipe Angle Calculation from Gesture X/Y*

Once the initial swipe has been detected, additional swipe outputs can be triggered in one of two ways during the same touch interaction.

2. **Swipe-and-Hold**

<a name="_page41_x56.69_y652.80"></a>With Swipe-and-hold (*Swipe Hold X+, Swipe Hold X-, Swipe Hold Y+, Swipe Hold Y-*) enabled in the [*Single Finger Gesture Enable* ](#_page67_x245.08_y286.20)register, the additional swipe gestures will be triggered by a stationary touch. For a Swipe-and-Hold gesture to be reported, a single swipe must be detected (Section[ 8.3.1),](#_page40_x56.69_y326.92)

and then the finger that performed the swipe must become stationary. To be stationary, the finger’s movement must be less than the[` `*Tap Distance* ](#_page67_x262.32_y343.59)for the duration of the[` `*Hold Time*.](#_page67_x273.18_y357.93) This is similar to the Press-and-Hold gesture. At this point the relevant output (*Swipe Hold X+, Swipe Hold X-, Swipe*

*Hold Y+, Swipe Hold Y-*) will be reported in the[` `*Single Finger Gestures* ](#_page65_x258.04_y280.50)register and will then only clear![ref2]

upon release of the finger. While one of the swipe-and-hold flags is set, relative finger movement will be reported in the[` `*Gesture X/Y* ](#_page65_x283.70_y251.81)registers.

The same termination logic as for the Press-and-Hold gesture is applied once a swipe-and-hold ges- ture is detected. In other words, if another fingerenters touch, the gesture is cleared, and the *Gesture X/Y* values are reset to zero.

Swipe initial distance moved![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.037.png)

Swipe time Hold Time

Touch

Touch

No touch

time

Stationary  Touch 

touch movement

Swipe  Swipe-and-hold gesture gesture

Gesture 

output

time

*Figure 8.10: Swipe-and-Hold Gesture*

3. **Consecutive<a name="_page42_x56.69_y457.04"></a> Swipe**

With Swipe-and-hold disabled, it is possible to generate consecutive swipe gesture events during the same swipe gesture by defining the[` `*Swipe Consecutive X-Distance* ](#_page67_x227.31_y415.32)and[` `*Swipe Consecutive Y- Distance* ](#_page67_x227.46_y429.66)(pixels). Once the initial swipe gesture has been reported, additional swipe outputs will be generated when the movement exceeds the consecutive threshold and the angle satisfies the[` `*Swipe Angle* ](#_page67_x252.98_y444.01)condition, and will continue in this manner until the finger is released. The reference point for

the consecutive swipe distance is the location where the previous swipe was detected.

**Note:** For consecutive swipes, the time limit[` `*Swipe Time* ](#_page67_x270.19_y372.28)is no longer applied.

The *Swipe Consecutive Distance* is used to evaluate consecutive swipes along the same axis. To switch swipe axes, the[` `*Swipe Initial Distance* ](#_page67_x241.42_y386.62)must be met along the axis being switched to. The consecutive threshold is normally a shorter distance than the initial distance, meaning switching the axis is slightly more difficultto achieve, preventing unwanted direction changes.![ref2]

Swipe  Swipe Swipe initial ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.038.png) consecutive  consecutive 

distance moved distance moved distance moved

Swipe time

Touch

Touch

No touch

Stationary touch  time

(has no effect)

Swipe  Swipe  Swipe Gesture  gesture gesture gesture output

time

*Figure 8.11: Consecutive Swipe with Pause*

4. **Palm<a name="_page43_x56.69_y368.40"></a> Gesture (Flat Hand Gesture)**

The palm gesture is used to detect the presence of a flat hand on the trackpad. Since a hand is not a perfectly flat surface, it is not expected that all channels on the trackpad will detect a touch. For this reason, the palm gesture requires a configurable[` `*Palm Gesture Threshold* ](#_page67_x255.48_y530.09)number of channels to detect touch simultaneously for the *Palm Gesture* to be reported in the[` `*Single Finger Gestures* ](#_page65_x258.04_y280.50)register. Normally a high percentage of the total channels, larger than the largest allowed touch, are selected as the *Palm Gesture Threshold*. Once the palm gesture has been detected, it will require a full release (no touches) before the gesture is cleared.

Relative movement in the[` `*Relative X/Y* ](#_page65_x283.52_y223.11)registers will still be reported if it occurs. The user must deter- mine whether the master will ignore the data or not.![ref2]

30 ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.039.png)

25 

Palm threshold = 20

dTeotteacl tchinga ntonuecls h  20

on trackpad

15

10

5

Gesture 

output Palm gesture

time

*Figure 8.12: Palm Gesture*

5. **Two-Finger<a name="_page44_x56.69_y347.36"></a> Tap**

The simultaneous tap gestures require two single-fingertap gestures to occur simultaneously. For this reason, the two-fingertap gestures use the same parameters [(*Tap Time*,](#_page67_x275.12_y314.89)[` `*Air Time*,](#_page67_x276.92_y329.24) and[` `*Tap Distance*) ](#_page67_x262.32_y343.59)as those of the single-finger tap gestures.

6. **Scroll**

<a name="_page44_x56.69_y431.49"></a>A scroll gesture is identifiedby two simultaneous and parallel moving touches. A scroll gesture will be reported in the[` `*Two-Finger Gestures* ](#_page65_x262.25_y294.84)register once the average distance travelled by the two touches

in pixels exceeds the value stored in register[` `*Scroll Initial Distance*.](#_page67_x262.26_y501.39) Once the initial scroll has been detected, a scroll gesture will be reported when the average distance travelled by the two touches in pixels exceeds the value stored in[` `*Scroll Consecutive Distance*,](#_page67_x248.14_y515.74) measured from the point at which the initial scroll was detected.

Similar to the swipe gestures, the scroll gestures are bound by a given angle to the axis [(*Scroll Angle*](#_page67_x254.01_y458.36)). The value in this register is calculated as 64 tanā, where ā is the desired angle (in degrees).

The direction of the scroll gesture is definedby the reported[` `*Gesture X* ](#_page65_x283.70_y251.81)(horizontal scroll) and[` `*Gesture Y* ](#_page65_x283.70_y266.15)(vertical scroll) data. For instance, a positive *Gesture X* value will correspond with the direction of a swipe X+ gesture. A scroll gesture may alternate between a positive and negative direction without requiring the validation of the initial conditions. However, switching between the axes will require the validation.

At any given stage during a scroll gesture, only the axis applicable to the gesture will have a non- zero value in its relative data register. For example, a scroll parallel to the X-axis will have a non-zero *Gesture X* value and a zero *Gesture Y* value. This value relates to the movement/size of the scroll gesture.

Duringascrollgesture,[` `*RelativeX/Y* ](#_page65_x283.52_y223.11)datawillbereportedinaccordancewiththestandardnon-gesture implementation,<a name="_page44_x56.69_y773.66"></a> based on the finger assignments.![ref2]

7. **Zoom**

Zoom gestures require two touches moving toward (zoom out) or away (zoom in) from each other. Similar to the scroll and swipe gestures, the zoom requires that an initial distance threshold in the register[` `*Zoom Initial Distance* ](#_page67_x261.98_y472.70)(pixels) is exceeded before a zoom gesture is reported in the[` `*Two-Finger Gestures* ](#_page65_x262.25_y294.84)register. Thereafter, the register[` `*Zoom Consecutive Distance* ](#_page67_x247.87_y487.05)(pixels) defines the distance threshold for each zoom event that follows the initial event. The direction/axis along which the two touches move is not relevant.

The size of each zoom event will be reported in the[` `*Gesture X* ](#_page65_x283.70_y251.81)register, where the negative sign indicates a zoom out gesture and a positive sign a zoom in gesture.

This gesture will terminate if the two touches ever merge into one.![ref2]

<a name="_page46_x56.69_y84.59"></a>**9 Virtual Sensors**

The IQS9150/IQS9151 possesses the capability to create easy-to-use virtual sensors within the track- pad![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.040.png) sensor area. Adjustable touch buttons, sliders, and wheels with configurable sizes and shapes can be superimposed onto the trackpad sensors. This allows for the creation of easily customisable touch sensors without the need for hardware electrode layout modification or added complexity. The key benefitlies in the ability to reuse the same trackpad PCB (thus no hardware changes) for various designs with different touch sensor requirements, by simply modifying the virtual sensors and their required configuration in firmware.

![ref3]

*Figure 9.1: Virtual Sensors*

For these virtual sensors, it is suggested that the designer should add finger guides to the overlay material/structure, LED sensor indicators, or something similar to help identify the sensor location.

1. **Maximum<a name="_page46_x56.69_y570.86"></a> Virtual Sensors**

The[` `*Number of Virtual Sensors Enabled* ](#_page67_x232.40_y630.51)register specifiesthe count of activated virtual sensors. Each type of virtual sensor has its own configurable number of enabled sensors (*Number of Buttons/Slid- ers/Wheels*). The maximum number of distinct sensors allowed is specified in the table below.

*Table 9.1: Maximum Virtual Sensors![ref2]*



|**Virtual<a name="_page46_x56.69_y748.55"></a> Sensor Type**|**Maximum Allowed**|
| - | - |
|Button|16|
|Slider|8|
|Wheel|4|

2. **Maximum Fingers Per Sensor**

For virtual buttons, only one touch (a finger) is detected. Thus, if more than one trackpad finger is within the button area, it will simply indicate a touch, with no indication there is more than one. For the sliders and wheels, however, two-finger inputs can be detected per sensor, and their corresponding slider or wheel locations reported. This allows for multi-touch control of these virtual two sensor types. InasimilarmannertothetrackpadXYdata,thelocationoftheoutputremainsfixedforaspecificfinger and thus identifies the corresponding finger by report location.

3. **Buttons**

<a name="_page47_x56.69_y195.46"></a>A maximum of sixteen virtual buttons can be implemented on the trackpad. Additionally, any Rx/Tx trackpad channel can function as a standalone touch ‘button’ sensor, with the output simply obtained from the touch bit in the[` `*Touch Status* ](#_page65_x277.83_y481.35)register. However, utilising virtual buttons offers the advan- tage of flexibility in firmware configuration. This includes the ability to easily relocate, resize, or alter the shape of buttons solely through firmware modifications. Also, employing virtual buttons ensures uniform touch sensitivity across the entire button area, eliminating the need for intricate electrode designs.

1. **Button<a name="_page47_x56.69_y331.41"></a> Output**

A virtual button has a touch output bit, indicating whether the button is pressed or not. The touch output can be seen in the[` `*Button Output* ](#_page65_x276.19_y553.08)register, where bit 0 corresponds to Button 0, bit 1 to Button 1, and so forth.

2. **Button<a name="_page47_x56.69_y411.98"></a> Setup**

The location of the virtual button is configured by definingits top-left trackpad X,Y coordinate and also its bottom-right coordinate,[` `*Button Top-Left X/Y* ](#_page67_x265.27_y659.20)and[` `*Button Bottom-Right X/Y*.](#_page67_x255.61_y687.89) Any trackpad touch within this bounding box will activate the corresponding button output. There is no limitation on the size or shape of the button, simply that it must fall within the trackpad coordinate space.![ref2]

(0 ; 0)![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.042.png)![ref3]

(x1 ; y1)

(x1 ; y1)

(x2 ; y2)

(x2 ; y2)

(X\_MAX ; Y\_MAX)

*Figure 9.2: Virtual Button Setup*

4. **Sliders**

<a name="_page48_x56.69_y388.53"></a>The IQS9150/IQS9151 can implement up to eight virtual slider sensors. Unlike the virtual buttons, the sliders provide a position output showing the user location on the virtual slider. Each slider allows for up to 2 touch inputs simultaneously, allowing for innovative user interfaces on the multi-touch slider sensors.

1. **Slider<a name="_page48_x56.69_y483.83"></a> Output**

The[` `*Slider Output* ](#_page65_x277.65_y567.42)is a positional output that ranges from 0 to the configured[` `*Slider Resolution* ](#_page68_x266.24_y243.16)value. This output value can be configured according to the implemented slider requirements. To allow the extremes of the slider to be easily activated by the user near the slider ends, a[` `*Slider Deadzone* ](#_page68_x270.68_y171.43)is configurable, which is an area at the extremes of the slider where an output (either 0 or the slider resolution value) is detected and output. The global parameter (applicable to all the virtual sliders) is also configured in terms of trackpad pixels and defines the trackpad coordinate distance that will provide an unchanged slider output before the slider effectively begins adjusting its output.![ref2]

Deadzone Deadzone![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.043.png)![ref4]

||||
| :- | :- | :- |
Zero Slider Max

Zero Slider Max![ref5]

*Figure 9.3: Virtual Slider Output and Deadzones*

If a slider is not active (no touch on the slider), then in a similar manner to the trackpad X, Y output, it will output a slider position of 65535 (0xFFFF).

2. **Slider<a name="_page49_x56.69_y366.21"></a> Setup**

Thelocation,shape,andsizeofeachsliderareconfiguredinthesamemannerasthevirtualbuttonsby defininga top-left and bottom-right trackpad (X, Y) coordinate,[` `*Slider Top-Left X/Y* ](#_page68_x266.73_y185.78)and[` `*Slider Bottom- Right X/Y*.](#_page68_x257.06_y214.47)

(x1 ; y1)![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.046.png)![ref3]

(x1 ; y1) (x2 ; y2)

(x2 ; y2)

*Figure 9.4: Virtual Slider Setup*

The orientation of each slider (whether it is horizontal or vertical) is determined by the shape of the![ref2]

slider.Ifthesizeinxofthesliderislargerthaniny,thenitisahorizontalslidercalculatedusingtrackpad x-coordinates; otherwise, it is a vertical slider calculated using the y-coordinates of the trackpad.

5. **Wheels**

<a name="_page50_x56.69_y119.14"></a>Up to four-wheel sensors can be enabled on the IQS9150/IQS9151. A wheel sensor is a defined ring/doughnut shape that will output wheel coordinates around the wheel circumference for up to 2 fingers simultaneously.![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.047.png)

1. **Wheel<a name="_page50_x56.69_y200.89"></a> Output**

The[` `*Wheel Output* ](#_page65_x276.40_y581.77)register provides position output ranging from 0 to the configured[` `*Wheel Resolution* ](#_page68_x264.99_y415.32)value, similar to the sliders. The wheel output on an analogue watch starts from 0 at 3 o’clock and increases counter-clockwise. The maximum wheel output is also located at 3 o’clock, where it then wraps back to 0, as depicted in Figure[ 9.5 ](#_page50_x56.69_y294.30)below.

Zero Wheel Max![ref3]

**+**

<a name="_page50_x56.69_y294.30"></a>*Figure 9.5: Virtual Wheel Output*

Again, like the sliders, if no touch is sensed on the wheel, then it will output a wheel position of 65535 (0xFFFF).

2. **Wheel<a name="_page50_x56.69_y653.00"></a> Setup**

The location and size of the wheel are configured by defining3 parameters. Firstly, the[` `*Wheel Centre X/Y* ](#_page68_x268.48_y357.93)centre coordinate of the wheel location is configured. From this centre point, the[` `*Wheel Inner Radius* ](#_page68_x260.78_y386.62)and[` `*WheelOuterRadius* ](#_page68_x259.85_y400.97)mustbedefinedtoindicatethewheel’sinnerandoutercircumference boundaries.

**Note:** Since the trackpad X and Y coordinates are used to determine a virtual wheel, it is crucial to select the X and Y resolution such that they yield identical pixels per mm. This ensures that the![ref2]

calculation of the virtual wheel results in a round shape rather than an elongated oval shape.![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.048.png)

r\_outer![ref3]

r\_inner

Centre point (x1; y1)

*Figure 9.6: Virtual Wheel Setup![ref2]*

Copyright ' Azoteq 2024 IQS9150/IQS9151 Datasheet Page 56 of 97 All Rights Reserved Revision v1.1 October 2024
**IQ Switchfi ProxSensefi Series** 

<a name="_page52_x56.69_y84.59"></a>**10 Hardware Settings![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.049.png)![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.050.png)**

Settings specific to hardware and the ProxSensefi Module charge transfer characteristics can be changed.

**Note:** Below some are described; the other hardware parameters are not discussed as they should only be adjusted under the guidance of Azoteq support engineers.

1. **Main<a name="_page52_x56.69_y187.73"></a> Oscillator**

Themainoscillatorfrequencycanbeconfiguredto14MHz,20MHzor24MHzandisconfiguredinthe [*Other Settings* ](#_page66_x275.23_y415.32)register. When 20 MHz or 24 MHz is selected, the minimum VDD allowed increases; please see Section[ 4.3 ](#_page13_x56.69_y487.79)for details.

2. **Charge<a name="_page52_x56.69_y269.48"></a> Transfer Frequency**

The charge transfer frequency (fxfer) can be configured using the IQS9150/IQS9151 PC GUI software. The charge transfer parameter section can be viewed in Appendix[ A.17.](#_page79_x56.69_y498.98) For high-resistance sensors (such as ITO), it might be needed to decrease fxfer.

3. **Reset**
1. <a name="_page52_x56.69_y351.23"></a>**Reset<a name="_page52_x56.69_y375.55"></a> Indication**

After a reset, the *Show Reset* bit will be set in the[` `*Info Flags* ](#_page65_x284.17_y309.19)register by the system to indicate the reset event occurred. This bit will clear when the master sets the *Ack Reset* in the[` `*System Control* ](#_page66_x273.33_y386.62)register; if it becomes set again, the master will know a reset has occurred and can react appropriately.

**Note:** *Event Mode* will not work until the *Ack Reset* has been used to clear the *Show Reset* bit. This allows I2C to always become active again if an unexpected reset has occurred, allowing the master to

react accordingly to the *Show Reset* flag, such as writing the start-up settings if needed.

2. **Software<a name="_page52_x56.69_y507.77"></a> Reset**

The IQS9150/IQS9151 can be reset through an I2C command by setting the *SW Reset* bit in the [*System Control* ](#_page66_x273.33_y386.62)register. This reset will take effectshortly after the SW Reset bit has been set and the

I2C communication window terminates.

3. **Hardware<a name="_page52_x56.69_y588.08"></a> Reset**

The MCLR pin (active low) can be used to reset the device when outside an I2C communication window. For more details, see Section[ 4.7.](#_page14_x56.69_y698.56)![ref2]

Copyright ' Azoteq 2024 IQS9150/IQS9151 Datasheet Page 57 of 97 All Rights Reserved Revision v1.1 October 2024
**IQ Switchfi ![ref1]ProxSensefi Series**

<a name="_page53_x56.69_y84.59"></a>**11 Additional Features**

1. **GUI<a name="_page53_x56.69_y101.97"></a> for Parameter Setup**

The Azoteq product GUI can configure the optimal settings required for the specific hardware. The device performance can be easily monitored and evaluated in the graphical environment until the optimal configuration is obtained.

Once the optimal configuration is obtained in the GUI, a header file can be exported containing the parameters to configure the IQS9150/IQS9151. To configure it correctly, these parameters need to be written to the device after every power-up.

Two bytes[` `*Settings version number* ](#_page65_x258.99_y653.50)are available so that the designer can label and identify the set- tings version. This allows the master to verify if the device firmware has the intended configuration as required.

<a name="_page53_x56.69_y285.03"></a>**11.1.1 Manual Start-up**

The device will be programmed with defaults not necessarily applicable to the current application. It is recommended that the whole memory map is overwritten with all data from the header file to be sure all settings are as intended. Once this has been done, set the re-ATI bits for the trackpad and ALP channel so that the ATI can be executed on the intended settings.

2. **Suspend**

<a name="_page53_x56.69_y379.92"></a>The IQS9150/IQS9151 can be placed into a suspended state, where no processing is performed, minimal power is consumed (<3 A), and the device retains existing data. This state is entered after the communication session that sets the *Suspend* bit in the[` `*System Control* ](#_page66_x273.33_y386.62)register terminates.

The device can be woken from suspend by forcing I2C communication (see Section[ 12.9.2)](#_page58_x56.69_y480.13) and clear- ing the suspend bit in that communication session. An automatic reseed of the trackpad is triggered after the device is woken from suspend since it cannot be guaranteed that the reference values are still relevant.

3. **Watchdog<a name="_page53_x56.69_y524.40"></a> Timer (WDT)**

A watchdog timer is implemented to improve system reliability. The working of this timer is as follows:

- A software timer tWDT is linked to the LFTMR (Low Frequency Timer) running on the ‘always on’ Low Frequency Oscillator.
- This timer is reset at a strategic point in the main loop.
- Failing to reset this timer will cause the appropriate ISR (interrupt service routine) to run.
- This ISR performs a software-triggered POR (Power on Reset).
- The device will reset, performing a full cold boot.
4. **RF<a name="_page53_x56.69_y698.09"></a> Immunity**

The IQS9150/IQS9151 has immunity to high-power RF noise. To improve the RF immunity, extra decoupling capacitors are suggested on VREG and VDD.![ref2]

Place decoupling capacitors on VREG and VDD according to the reference schematic in Section[ 3.](#_page11_x56.69_y84.59) All decoupling capacitors should be placed as close as possible to the VDD and VREG pads.

If needed, series resistors can be added to Rx electrodes to reduce RF coupling into the sensing pads. Normally these are in the range of 100 Ω – 1kΩ. PCB ground planes also improve noise immunity.

5. **Switch<a name="_page54_x56.69_y157.15"></a> Input**

The switch input feature of the IQS9150/IQS9151 provides designers with the flexibility to implement switch functionality according to specificapplication requirements. The IQS9150/IQS9151 includes a dedicated Switch I/O pin. Developers can control the activation or deactivation of the switch function- ality using the *Switch Enable* setting in the[` `*Other Settings* ](#_page66_x275.23_y415.32)register. The *Switch Polarity* setting allows users to configure the switch as active-high or active-low. For an active-low configuration, a pull-up re- sistor is recommended to ensure proper functionality. However, the behaviour of the switch ultimately depends on the external hardware setup to ensure that the input state (high or low) corresponds correctly to whether the switch is pressed or not pressed.

The *Switch Pressed* flag in the[` `*Info Flags* ](#_page65_x284.17_y309.19)register indicates the current status of the switch.

6. **Additional<a name="_page54_x56.69_y331.10"></a> Non-Trackpad Channels**

Unused mutual capacitive channels can be used to design additional buttons or sliders.

**Note:** The channels will still provide XY data output, which can be ignored (or utilised) by the master.

**Note:** The additional sensors will have to use the same global ATI and sensitivity parameters, so careful sensor design is needed to ensure that these parameters are applicable.

It is suggested that the button sensor design is identical to the trackpad sensor, with the same overlay material and thickness. Please contact Azoteq if you consider this option.

7. **Version<a name="_page54_x56.69_y486.23"></a> Information**

[*VersionInformation* ](#_page65_x261.69_y169.12)issubjecttochangebeforetheproductrelease.Forup-to-dateinformation,please get in touch with Azoteq.![ref2]

<a name="_page55_x56.69_y84.59"></a>**12 I2C Interface**

1. **I2C<a name="_page55_x56.69_y101.97"></a> Module Specification**

The device features a standard two-wire I2C interface, complemented by an RDY (ready interrupt) line, supporting a maximum bit rate of up to 1 Mbps. The memory structures accessible over the

I2C interface are byte-addressable with 16-bit address values. 16-bit or 32-bit values are packed with little-endian byte order and are stored in word-aligned addresses.

- Standard two-wire interface with additional RDY interrupt line
- *Fast-Mode Plus* I2C with up to 1Mbps bit rate
- 7-bit device address
- 16-bit register address
- Little-endian
2. **I2C<a name="_page55_x56.69_y274.53"></a> Address**

The IQS9150/IQS9151 has a default I2C address of 0x56.

Alternatively, the[` `*I2C Slave Address* ](#_page65_x267.54_y639.15)parameter in the memory map can be updated to configure the I2C slave addresses. An[` `*I2C Update Key* ](#_page65_x273.02_y624.81)needs to be written to force the address update and prevent accidental overwriting of this. When the current I2C communication window ends and the *I2C Update Key* is set to 0xA3, the system will update the I2C slave address. The *I2C Update Key* register will automatically go back to 0x00 after the address has been updated.

<a name="_page55_x56.69_y411.67"></a>**12.2.1 Reserved I2C Address**

When communicating with the IQS9150/IQS9151, it will acknowledge (ACK) communication attempts made to an address derived from its slave address. This derived address is obtained by flipping the least significant bit of the slave address.

For example, if the slave address of the IQS9150/IQS9151 is 0x56 (1010110 in binary), the derived address for ACK would be 0x57 (1010111 in binary), obtained by changing the LSB from 0 to 1. However, it’s important to note that this derived address is reserved for internal use and should not be used. Even though the device will acknowledge communication attempts to this address, it will not function as normal and therefore should be avoided.

3. **Memory<a name="_page55_x56.69_y569.30"></a> Map Addressing**

All memory locations are 16-bit addressable in little-endian byte order.

4. **Memory<a name="_page55_x56.69_y626.32"></a> Map Data**

Each16-bitmemorymapaddressaddressesabyte(8bits),makingthememorymapbyte-addressable. Since the data is packed in a little-endian sequence, a 16-bit value starting at, for example, address 0x1014 will have its least significant byte at address 0x1014 and its most significant byte at address 0x1015.![ref2]

5. **Read<a name="_page56_x56.69_y84.59"></a> and Write Operations**
1. **I2C<a name="_page56_x56.69_y97.40"></a> Read From Specific Address**

ThereadoperationisdisplayedinFigure[12.1.](#_page56_x56.69_y258.10)ThemasterdevicewatchesfortheIQS9150’s/IQS9151’s RDY line to drop low, signalling the availability of fresh data and a window for communication. It is al- ways best to hold offon starting I2C transactions until the RDY line goes low. The master starts com- munication by sending a start condition, the device address, and a write command in response to the RDY interrupt. After receiving an acknowledgement from the IQS9150/IQS9151, the master device will send two bytes that specify the register address. The device address and a read command will be sent by the master after a repeated start condition. Then, while the master acknowledges each byte,

the IQS9150/IQS9151 will keep transmitting data from the requested address. The read operation ends when the master generates a stop condition and does not acknowledge the last byte received.

<a name="_page56_x56.69_y258.10"></a>RDY ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.051.png)SCL SDA 

Write Read

0xBC 0x11 0x02 0x56 0x56

+ ACK + ACK + NAK
+ ACK + ACK

*Figure 12.1: I2C Read Example - Read System Control Register 0x11BC Before Modifying*

2. **I2C<a name="_page56_x56.69_y439.33"></a> Write To Specific Address**

The write operation is displayed in Figure[ 12.2.](#_page56_x56.69_y575.76) Similar to the read transaction, when the RDY interrupt is triggered, the master initiates communication by sending a start condition followed by the device address along with a write command. The IQS9150/IQS9151 will respond with an acknowledgement, after which the master device will transmit two bytes definingthe register address. The slave acknowl- edges the register address bytes. The master may then write a series of bytes to the register address and the addresses which follow, with each byte being acknowledged by the slave. The write operation is ended when the master produces a stop condition.

<a name="_page56_x56.69_y575.76"></a>RDY ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.052.png)SCL SDA 

Write 0xBC 0x11 0x82 [0x56] + ACK + ACK + ACK

*Figure 12.2: I2C Write Example - Write 0x82 (Ack Reset bit) to System Control Register 0x11BC*

**Note:** When modifying registers, it’s recommended to read the register first, make the necessary![ref2]

modifications, and then write the updated value back to the IQS9150/IQS9151 register to prevent unintentional bit settings.

- Read the System Control Register (0x11BC) as illustrated in Figure[ 12.1.](#_page56_x56.69_y258.10)
- Set the Ack Reset bit using the bitwise OR operator (Current register value OR 0x80).
- Example: 0x02 OR 0x80 = 0x82.
- Write the value 0x82 to Register 0x11BC as shown in Figure[ 12.2.](#_page56_x56.69_y575.76)
6. **I2C<a name="_page57_x56.69_y184.25"></a> Timeout**

If the communication window is not serviced within the[` `*I2C Timeout* ](#_page66_x269.77_y343.59)period (in milliseconds), the ses- sion is ended (RDY goes HIGH), and processing continues as normal. This allows the system to continue and keep reference values up to date even if the master is not responsive; however, the corresponding data was missed/lost, and this should be avoided.

7. **Terminate<a name="_page57_x56.69_y281.02"></a> Communication**

With the *Terminate Comms Window* setting cleared in the[` `*Config Settings* ](#_page66_x273.46_y400.97)register, a standard I2C STOP ends the current communication window. If multiple I2C transactions need to be done, then they should be strung together using repeated-start conditions instead of giving a STOP. This will allow the communication to occur in the same session. Allowing an I2C STOP to terminate the communication window is the recommended method and is illustrated in Figures[ 12.1 ](#_page56_x56.69_y258.10)and[ 12.2.](#_page56_x56.69_y575.76)

The alternative option with the *Terminate Comms Window* setting set is that an I2C command is needed to terminate the communication window. For this configuration, an I2C STOP will NOT ter- minate the communication window. This can be done by writing 0xEEEE, followed by a STOP as follows:

RDY ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.053.png)SCL SDA 

Write

0xEE 0xEE

[0x56]

+ ACK + ACK
+ ACK

*Figure 12.3: Terminate Comms Diagram*

8. **RDY<a name="_page57_x56.69_y633.78"></a> / IRQ**

The IQS9150/IQS9151 includes an open-drain active-low RDY signal, indicating when updated data and a communication window are ready. While the master can communicate with the device at any time according to the *Force Comms Method* setting, it is recommended to use the RDY signal for optimal power consumption. Integrating the RDY signal as an interrupt input allows the master MCU to efficiently read and write data.

The device provides both streaming and event modes. In streaming mode, the RDY line toggles con- tinuously, whereas in event mode, the RDY toggles only when a specific event occurs. The types of![ref2]

events that trigger the RDY window are configurable in the[` `*Config Settings* ](#_page66_x273.46_y400.97)register.

9. **Event<a name="_page58_x56.69_y105.57"></a> Mode Communication**

The device can be set up to bypass the communication window when no activity is sensed by setting the *Event Mode* bit in the[` `*Config Settings* ](#_page66_x273.46_y400.97)register. This is usually enabled since the master does not want to be interrupted unnecessarily during every cycle if no activity occurs. The communication will resume (RDY will indicate available data) if an enabled event occurs. It is recommended that the RDY be placed on an interrupt-on-pin-change input on the master.

Note that *Event Mode* will only implement if *Show Reset* has been cleared in[` `*Info Flags*;](#_page65_x284.17_y309.19) see Sec- tion[ 10.3.1.](#_page52_x56.69_y375.55) An example of how to do this can be seen in Section[ 12.4.](#_page55_x56.69_y626.32)

1. **Events**

<a name="_page58_x56.69_y252.40"></a>Numerous events can be individually enabled in the[` `*ConfigSettings* ](#_page66_x273.46_y400.97)register to trigger communication; they are:

- Gesture events (*Gesture Event*): Enabled gestures will trigger event.
- Trackpad events (*TP Event* ): Event triggered if there is a change in X/Y value or if a finger is added or removed from the trackpad.
- Touch events (*TP Touch Event*): Event only triggers if a channel has a change in a touch state. This is mostly aimed at channels that are used for traditional buttons, where you want to know only when a status is changed.
- Re-ATI (*Re-ATI Event*): One communication cycle is given to indicate the re-ATI occurred.
- Proximity/Touch on ALP (*ALP Event* ): Event given on state change.
- Switch event (*Switch Event*): With the switch input enabled, if the switch changes state, then this event will trigger.
- Snap events (*Snap Event*): Triggers if a snap channel has a change in state.
2. **Force<a name="_page58_x56.69_y480.13"></a> Communication / Polling**

The master can initiate communication even while RDY is HIGH (inactive). The default method (*Force Comms Method* set to ‘0’) is that the IQS9150/IQS9151 will clock stretch until an appropriate time to complete the I2C transaction. The master firmware will not be affected (if clock stretching is correctly handled).

RDY ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.054.png)SCL SDA 

Write Read

0x00 0x10 0x6A 0x07 [0x56] [0x56]

+ ACK + ACK + ACK + NAK
+ ACK + ACK

*Figure 12.4: Clock Stretch Comms Diagram*

If the associated clock stretching cannot be allowed, then an alternative *Force Comms Method* can![ref2]

be enabled in the[` `*ConfigSettings* ](#_page66_x273.46_y400.97)register. To achieve this, the master will communicate when RDY is not active (thus forcing comms), and it will write a comms request to the device. This comms request is as follows:

RDY ![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.055.png)SCL SDA 

Write Write Read

0xFF 0xBC 0x11 0x00 [0x56] [0x56] [0x56]

+ ACK + ACK + ACK + NAK
+ ACK + ACK + ACK

*Figure 12.5: Force Comms Diagram*

After this request for communication has been sent, the next available communication window will become available as normal (thus RDY going LOW).

Foroptimalprogramflow,itissuggestedthatRDYisusedtosyncnewdata.Theforced/pollingmethod is only recommended if the master must perform I2C and Event Mode is active.![ref2]

<a name="_page60_x56.69_y84.59"></a>**13 Ordering Information**

1. **Ordering<a name="_page60_x56.69_y101.97"></a> Code**
1. **IQS9150**

<a name="_page60_x56.69_y124.49"></a>IQS9150 zzz ppb![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.056.png)![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.057.png)

*Table 13.1: IQS9150 Order Code Description*



|**IC NAME**||IQS9150|
| - | :- | - |
|**CONFIGURATION**|<p>000 zzz =</p><p>001</p>|NRFND|
|||Default I2C Address = 0x56|
|**PACKAGE TYPE**|pp = QF|QFN-52 Package|
|**BULK PACKAGING**|b = R|QFN-52 Reel (3000 pcs/reel)|

Example : IQS9150-001QFR

2. **IQS9151**

<a name="_page60_x56.69_y356.71"></a>IQS9151 zzz ppb![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.058.png)![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.059.png)

*Table 13.2: IQS9151 Order Code Description*



|**IC NAME**||IQS9151|
| - | :- | - |
|**CONFIGURATION**|zzz = 000|Default I2C Address = 0x56|
|**PACKAGE TYPE**|pp = QF|QFN-52 Package|
|**BULK PACKAGING**|b = R|QFN-52 Reel (3000 pcs/reel)|

Example : IQS9151-000QFR

2. **QFN52<a name="_page60_x56.69_y572.53"></a> Top Markings**
1. **IQS9150**

<a name="_page60_x56.69_y596.86"></a>IQS9150 Product Name![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.060.png)![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.061.png)

pppxx “ppp” = Product Code, “xx” = Batch Code

*Figure<a name="_page60_x56.69_y779.08"></a> 13.1: IQS9150-QFN52 Package Top Marking![ref2]*

2. **IQS9151**

IQS9151 Product Name![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.062.png)![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.063.png)

pppxx “ppp” = Product Code, “xx” = Batch Code

*Figure 13.2: IQS9151-QFN52 Package Top Marking*

3. **Generic<a name="_page61_x56.69_y256.89"></a> QFN52 Top Marking**

When purchasing complete sub-assemblies from Azoteq, the IC on the assembly may have this generic top marking.

IQS9xxx Product Name![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.064.png)![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.065.png)

pppxx “ppp” = Product Code, “xx” = Batch Code

*Figure 13.3: QFN52 Generic Package Top Marking![ref2]*

<a name="_page62_x56.69_y84.59"></a>**14 QFN52 Package Information**

1. **QFN52<a name="_page62_x56.69_y101.97"></a> Package Outline**

A![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.066.png)

D B D2

PIN 1

||
| :- |
e 1 CORNER

PIN 1 MARKING

E E2

44×L DETAIL A 52×b bbb C A B

ddd

TOP VIEW BOTTOM VIEW

SEATING PLANE

0\.325 A C

0\.154 A3

DETAIL A eee C A1 SIDE VIEW

NOTES:

1. Drawing is not to scale.
1. Drawing is subject to change without notice.

*Figure 14.1: QFN52 Package Outline Visual Description Table 14.1: QFN52 Package Dimensions [mm]![ref2]*



|**Dimension**|**Millimeters**|||
| - | - | :- | :- |
||**Min**|**Typ**|**Max**|
|A|0\.70|0\.75|0\.80|
|A1|0\.00|0\.02|0\.05|
|A3|0\.20 REF|||
|D|5\.95|6\.00|6\.05|
|E|5\.95|6\.00|6\.05|
|D2|4\.40|4\.50|4\.60|
|E2|4\.40|4\.50|4\.60|
|b|0\.15|0\.20|0\.25|
|e|0\.40 BSC|||
|L|0\.35|0\.40|0\.45|

*Table 14.2: QFN52 Package Tolerances [mm]*



|**Tolerance**|**Millimeters**|
| - | - |
|bbb|0\.10|
|ddd|0\.05|
|eee|0\.08|

2. **QFN52<a name="_page63_x56.69_y185.61"></a> Recommended Footprint**

0\.20![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.067.png)

0\.10×0.10

1

4\.50 7.20

RECOMMENDED FOOTPRINT

NOTES:

1. Dimensions are expressed in millimeters.
1. Drawing is not to scale.
1. Drawing is subject to change without notice.
1. Final dimensions may vary due to manufacturing tolerance considerations.

*Figure<a name="_page63_x56.69_y610.93"></a> 14.2: QFN52 Recommended Footprint![ref2]*

3. **Tape and Reel Specifications**

   **REEL DIMENSIONS TAPE DIMENSIONS**

K0 P1![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.068.png)![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.069.png)

Cavity A0



|A0|Dimension designed to accommodate the component width|
| - | - |
|B0|Dimension designed to accommodate the component length|
|K0|Dimension designed to accommodate the component thickness|
|W|Overall width of the carrier tape|
|P1|Pitch between successive cavity centers|

Reel Width (W1)

**QUADRANT ASSIGNMENTS FOR PIN 1 ORIENTATION IN TAPE**

Sprocket Holes![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.070.png)



|Q1|Q2|||
| - | - | :- | :- |
|Q3|Q4|||
|Q1|Q2|||
|Q3|Q4|||

User Direction of Feed

Pocket Quadrants

*Figure 14.3: Tape and Reel Specification Table 14.3: Tape and Reel Specifications![ref2]*



|**Package Type**|**Pins**|**Dimension [Millimeters]**|**Pin 1 Quadrant**|||||||
| :-: | - | - | :- | :- | :- | :- | :- | :- | :- |
|||**Reel Diameter**|**Reel Width**|**A0**|**B0**|**K0**|**P1**|**W**||
|QFN52|52|330\.0|16\.4|6\.3|6\.3|1\.1|12\.0|1 6.0|Q2|

<a name="_page65_x56.69_y84.59"></a>**15 I2C Memory Map - Register Descriptions**

For a more detailed description please see Appendix[ A.](#_page69_x56.69_y84.59)



|**Address**|**Length**|**Description**|**Notes**|
| - | - | - | - |
|**Read Only**||<a name="_page65_x261.69_y169.12"></a>**Version Information**||
|0x1000 – 0x1013|20|Product Information|Appendix[ A.1](#_page69_x56.69_y101.97)|
|**Read Only**||**Device Data**||
|0x1014|<a name="_page65_x283.52_y223.11"></a>2|Relative X|<a name="_page65_x283.52_y237.46"></a>Section[ 7.2.2](#_page31_x56.69_y265.64)|
|0x1016|2|Relative Y||
|0x1018|<a name="_page65_x283.70_y251.81"></a>2|Gesture X|<a name="_page65_x283.70_y266.15"></a>Section[ 8.1 ](#_page35_x56.69_y530.85)and[ 8.3](#_page40_x56.69_y300.21)|
|0x101A|2|Gesture Y||
|0x101C|<a name="_page65_x258.04_y280.50"></a>2|Single Finger Gestures|Appendix[ A.2](#_page69_x56.69_y323.15)|
|0x101E|<a name="_page65_x262.25_y294.84"></a>2|Two-Finger Gestures|Appendix[ A.3](#_page70_x56.69_y225.72)|
|0x1020|<a name="_page65_x284.17_y309.19"></a>2|Info Flags|Appendix[ A.4](#_page71_x56.69_y84.59)|
|0x1022|<a name="_page65_x273.32_y323.54"></a>2|Trackpad Flags|Appendix[ A.5](#_page71_x56.69_y712.72)|
|0x1024|<a name="_page65_x260.01_y337.88"></a>2|Finger 1 X-Coordinate|Section[ 7.2.3](#_page31_x56.69_y343.59)|
|0x1026|2|Finger 1 Y-Coordinate||
|0x1028|<a name="_page65_x255.97_y366.58"></a>2|Finger 1 Touch Strength|Section[ 7.2.4](#_page31_x56.69_y426.30)|
|0x102A|<a name="_page65_x276.70_y380.92"></a>2|Finger 1 Area|Section[ 7.2.5](#_page31_x56.69_y493.08)|
|Ď|40|Ď|Ď|
|0x1054|2|Finger 7 X-Coordinate|Section[ 7.2.3](#_page31_x56.69_y343.59)|
|0x1056|2|Finger 7 Y-Coordinate||
|0x1058|2|Finger 7 Touch Strength|Section[ 7.2.4](#_page31_x56.69_y426.30)|
|0x105A|2|Finger 7 Area|Section[ 7.2.5](#_page31_x56.69_y493.08)|
|**Read Only**||**Channel Data**||
|0x105C|<a name="_page65_x277.83_y481.35"></a>88|Touch Status|Appendix[ A.28](#_page87_x56.69_y218.69)|
|0x10B4|<a name="_page65_x264.19_y495.69"></a>2|ALP Channel Count|Section[ 5.4.2](#_page21_x56.69_y720.70)|
|0x10B6|<a name="_page65_x268.83_y510.04"></a>2|ALP Channel LTA|Section[ 5.5.2](#_page22_x56.69_y571.68)|
|0x10B8|<a name="_page65_x259.71_y524.38"></a>26|ALP Individual Counts|Appendix[ A.6](#_page72_x56.69_y498.09)|
|0x10D2|<a name="_page65_x279.41_y538.73"></a>88|Snap Status|Appendix[ A.28](#_page87_x56.69_y218.69)|
|0x112A|<a name="_page65_x276.19_y553.08"></a>2|Button Output|Appendix[ A.7](#_page72_x56.69_y764.34)|
|0x112C|<a name="_page65_x277.65_y567.42"></a>32|Slider Output|Appendix[ A.8](#_page73_x56.69_y232.49)|
|0x114C|<a name="_page65_x276.40_y581.77"></a>16|Wheel Output|Appendix[ A.9](#_page73_x56.69_y537.39)|
|**Read-Write**||**Trackpad Configuration**||
|0x115C|<a name="_page65_x257.37_y610.46"></a>26|ALP ATI Compensation|Appendix[ A.10](#_page73_x56.69_y725.29)|
|0x1176|1|<a name="_page65_x273.02_y624.81"></a>I2C Update Key|<a name="_page65_x267.54_y639.15"></a>Section[ 12.2](#_page55_x56.69_y274.53)|
|0x1177|1|I2C Slave Address||
|0x1178|<a name="_page65_x258.99_y653.50"></a>1|Settings Minor Version|Section[ 11.1](#_page53_x56.69_y101.97)|
|0x1179|1|Settings Major Version||
|0x117A|<a name="_page65_x223.91_y682.19"></a>2|Trackpad ATI Multiplier/Dividers (Global)|Appendix[ A.11](#_page74_x56.69_y403.93)|
|0x117C|26|ALP ATI Multiplier/Dividers||
|0x1196|<a name="_page65_x264.05_y710.88"></a>2|Trackpad ATI Target|Section[ 5.7.1](#_page24_x56.69_y604.63)|
|0x1198|<a name="_page65_x273.86_y725.23"></a>2|ALP ATI Target|<a name="_page65_x262.39_y739.58"></a>Section[ 5.7.2](#_page25_x56.69_y373.91)|
|0x119A|2|ALP ATI Base Target||
Continued on next page![ref2]



|0x119C|<a name="_page66_x227.61_y99.70"></a>2|Trackpad Negative Delta Re-ATI Value|<a name="_page66_x243.48_y128.39"></a>Section[ 5.8](#_page25_x56.69_y688.59)|
| - | - | - | - |
|0x119E|<a name="_page66_x229.69_y114.05"></a>2|Trackpad Positive Delta Re-ATI Value||
|0x11A0|1|Trackpad Reference Drift Limit||
|0x11A1|<a name="_page66_x266.48_y142.74"></a>1|ALP LTA Drift Limit||
|**Read-Write**||**Device Configuration**||
|0x11A2|<a name="_page66_x235.05_y171.43"></a>2|Active Mode Sampling Period (ms)|Section[ 6.1](#_page29_x56.69_y84.59)|
|0x11A4|<a name="_page66_x226.71_y185.78"></a>2|Idle-Touch Mode Sampling Period (ms)||
|0x11A6|<a name="_page66_x239.90_y200.12"></a>2|Idle Mode Sampling Period (ms)||
|0x11A8|<a name="_page66_x239.15_y214.47"></a>2|LP1 Mode Sampling Period (ms)||
|0x11AA|<a name="_page66_x239.15_y228.82"></a>2|LP2 Mode Sampling Period (ms)||
|0x11AC|<a name="_page66_x246.33_y243.16"></a>2|Stationary Touch Timeout (s)|Section[ 6.2](#_page29_x56.69_y271.48)|
|0x11AE|<a name="_page66_x247.03_y257.51"></a>2|Idle-Touch Mode Timeout (s)||
|0x11B0|<a name="_page66_x260.22_y271.85"></a>2|Idle Mode Timeout (s)||
|0x11B2|<a name="_page66_x259.47_y286.20"></a>2|LP1 Mode Timeout (s)||
|0x11B4|<a name="_page66_x238.22_y300.55"></a>2|Active to Idle Mode Timeout (ms)||
|0x11B6|<a name="_page66_x260.45_y314.89"></a>1|Re-ATI Retry Time (s)|Section[ 5.8.3](#_page26_x56.69_y572.50)|
|0x11B7|<a name="_page66_x249.95_y329.24"></a>1|Reference Update Time (s)|Section[ 5.5.1](#_page22_x56.69_y422.58)|
|0x11B8|2|<a name="_page66_x269.77_y343.59"></a>I2C Timeout (ms)|Section[ 12.6](#_page57_x56.69_y184.25)|
|0x11BA|<a name="_page66_x275.91_y357.93"></a>1|Snap Timeout|Section[ 5.6.2](#_page23_x56.69_y482.66)|
|0x11BB|1|Reserved (0x00)|-|
|0x11BC|<a name="_page66_x273.33_y386.62"></a>2|System Control|Appendix[ A.12](#_page75_x56.69_y159.97)|
|0x11BE|<a name="_page66_x273.46_y400.97"></a>2|Config Settings|Appendix[ A.13](#_page76_x56.69_y84.59)|
|0x11C0|<a name="_page66_x275.23_y415.32"></a>2|Other Settings|Appendix[ A.14](#_page76_x56.69_y769.47)|
|0x11C2|<a name="_page66_x282.43_y429.66"></a>4|ALP Setup|Appendix[ A.15](#_page77_x56.69_y583.81)|
|0x11C6|<a name="_page66_x273.91_y444.01"></a>6|ALP Tx Enable|Appendix[ A.16](#_page78_x56.69_y522.49)|
|0x11CC|<a name="_page66_x243.52_y458.36"></a>1|Touch Set Threshold Multiplier|<a name="_page66_x239.49_y472.70"></a>Section[ 5.6.1](#_page23_x56.69_y143.47)|
|0x11CD|1|Touch Clear Threshold Multiplier||
|0x11CE|<a name="_page66_x244.81_y487.05"></a>1|ALP Output Threshold (Delta)|<a name="_page66_x238.56_y501.39"></a>Section[ 5.6.3](#_page24_x56.69_y212.81)|
|0x11CF|1|ALP Auto-Prox Threshold (Delta)||
|0x11D0|<a name="_page66_x265.73_y515.74"></a>1|ALP Set Debounce|<a name="_page66_x261.70_y530.09"></a>Section[ 5.6.4](#_page24_x56.69_y350.73)|
|0x11D1|1|ALP Clear Debounce||
|0x11D2|<a name="_page66_x249.59_y544.43"></a>1|Snap Set Threshold (Delta)|<a name="_page66_x245.56_y558.78"></a>Section[ 5.6.2](#_page23_x56.69_y482.66)|
|0x11D3|1|Snap Clear Threshold (Delta)||
|0x11D4|1|ALP Count Filter Beta - LP1 Mode|<p>Section[ 5.4.2 ](#_page21_x56.69_y720.70)and</p><p>[5.5.2](#_page22_x56.69_y571.68)</p>|
|0x11D5|<a name="_page66_x240.79_y587.47"></a>1|ALP LTA Filter Beta - LP1 Mode||
|0x11D6|1|ALP Count Filter Beta - LP2 Mode||
|0x11D7|1|ALP LTA Filter Beta - LP2 Mode||
|0x11D8|3|Trackpad Conversion Frequency|Appendix[ A.17](#_page79_x56.69_y498.98)|
|0x11DB|3|ALP Conversion Frequency||
|0x11DE|2|Trackpad Hardware Settings|Appendix[ A.18](#_page80_x56.69_y369.32)|
|0x11E0|2|ALP Hardware Settings||
|**Read-Write**||**Trackpad Configuration**||
|0x11E2|<a name="_page66_x268.13_y702.24"></a>1|Trackpad Settings|Appendix[ A.19](#_page81_x56.69_y399.11)|
|0x11E3|<a name="_page66_x285.33_y716.59"></a>1|Total Rxs|<a name="_page66_x285.83_y730.93"></a>Section[ 7.1.1](#_page30_x56.69_y124.49)|
|0x11E4|1|Total Txs||
|0x11E5|<a name="_page66_x266.71_y745.28"></a>1|Max Multi-Touches|Section[ 7.3](#_page31_x56.69_y626.65)|

Continued on next page![ref2]



|0x11E6|<a name="_page67_x278.44_y99.70"></a>2|X Resolution|Section[ 7.4](#_page31_x56.69_y705.00)|
| - | - | - | - |
|0x11E8|2|Y Resolution||
|0x11EA|<a name="_page67_x238.45_y128.39"></a>2|XY Dynamic Filter Bottom Speed|<a name="_page67_x242.23_y157.09"></a>Section[ 7.8](#_page32_x56.69_y500.08)|
|0x11EC|<a name="_page67_x245.24_y142.74"></a>2|XY Dynamic Filter Top Speed||
|0x11EE|1|XY Dynamic Filter Bottom Beta||
|0x11EF|<a name="_page67_x263.83_y171.43"></a>1|XY Static Filter Beta||
|0x11F0|<a name="_page67_x227.11_y185.78"></a>1|Stationary Touch Movement Threshold|Section[ 7.5](#_page32_x56.69_y84.59)|
|0x11F1|<a name="_page67_x267.39_y200.12"></a>1|Finger Split Factor|Section[ 7.6](#_page32_x56.69_y230.83)|
|0x11F2|<a name="_page67_x278.58_y214.47"></a>1|X Trim Value|Section[ 7.9](#_page33_x56.69_y558.78)|
|0x11F3|1|Y Trim Value||
|0x11F4|<a name="_page67_x250.18_y243.16"></a>1|Jitter Filter Delta Threshold|Section[ 7.8.2](#_page33_x56.69_y464.77)|
|0x11F5|<a name="_page67_x246.05_y257.51"></a>1|Finger Confidence Threshold|Section[ 7.10](#_page33_x56.69_y680.28)|
|**Read-Write**||**Gesture Configuration**||
|0x11F6|<a name="_page67_x245.08_y286.20"></a>2|Single Finger Gesture Enable|<p>Appendix[ A.20 ](#_page81_x56.69_y744.08)and</p><p><a name="_page67_x249.29_y300.55"></a>[A.21](#_page83_x56.69_y84.59)</p>|
|0x11F8|2|Two-Finger Gesture Enable||
|0x11FA|<a name="_page67_x275.12_y314.89"></a>2|Tap Time (ms)|Section[ 8.1](#_page35_x56.69_y530.85)|
|0x11FC|<a name="_page67_x276.92_y329.24"></a>2|Air Time (ms)||
|0x11FE|<a name="_page67_x262.32_y343.59"></a>2|Tap Distance (pixels)||
|0x1200|<a name="_page67_x273.18_y357.93"></a>2|Hold Time (ms)|Section[ 8.2](#_page39_x56.69_y410.14)|
|0x1202|<a name="_page67_x270.19_y372.28"></a>2|Swipe Time (ms)|<a name="_page67_x227.31_y415.32"></a>Section[ 8.3](#_page40_x56.69_y300.21)|
|0x1204|<a name="_page67_x241.42_y386.62"></a>2|Swipe Initial X-Distance (pixels)||
|0x1206|<a name="_page67_x241.58_y400.97"></a>2|Swipe Initial Y-Distance (pixels)||
|0x1208|2|Swipe Consecutive X-Distance (pixels)||
|0x120A|<a name="_page67_x227.46_y429.66"></a>2|Swipe Consecutive Y-Distance (pixels)||
|0x120C|<a name="_page67_x252.98_y444.01"></a>1|Swipe Angle (64tan(deg))||
|0x120D|<a name="_page67_x254.01_y458.36"></a>1|Scroll Angle (64tan(deg))|Section[ 8.6](#_page44_x56.69_y431.49)|
|0x120E|<a name="_page67_x261.98_y472.70"></a>2|Zoom Initial Distance|<a name="_page67_x247.87_y487.05"></a>Section[ 8.7](#_page44_x56.69_y773.66)|
|0x1210|2|Zoom Consecutive Distance||
|0x1212|<a name="_page67_x262.26_y501.39"></a>2|Scroll Initial Distance|<a name="_page67_x248.14_y515.74"></a>Section[ 8.6](#_page44_x56.69_y431.49)|
|0x1214|2|Scroll Consecutive Distance||
|0x1216|<a name="_page67_x255.48_y530.09"></a>2|Palm Gesture Threshold|Section[ 8.4](#_page43_x56.69_y368.40)|
|**Read-Write**||**Trackpad Electrode & Channel Configuration**||
|0x1218|<a name="_page67_x274.92_y558.78"></a>46|RxTx Mapping|Appendix[ A.22](#_page83_x56.69_y485.18)|
|0x1246|<a name="_page67_x251.40_y573.12"></a>88|Trackpad Channel Disable|<a name="_page67_x240.67_y587.47"></a>Appendix[ A.28](#_page87_x56.69_y218.69)|
|0x129E|88|Trackpad Snap Channel Enable||
|0x12F6|<a name="_page67_x224.60_y601.82"></a>506|Individual Touch Threshold Adjustments|Appendix[ A.23](#_page85_x56.69_y84.59)|
|**Read-Write**||**Virtual Sensor Configuration**||
|0x14F0|<a name="_page67_x232.40_y630.51"></a>2|Number Of Virtual Sensors Enabled|Appendix[ A.24](#_page85_x56.69_y397.63)|
|**Read-Write**||**Virtual Button Configuration**||
|0x14F2|<a name="_page67_x265.27_y659.20"></a>2|Button 0 Top-Left X|<a name="_page67_x255.61_y687.89"></a>Section[ 9.3](#_page47_x56.69_y195.46)|
|0x14F4|2|Button 0 Top-Left Y||
|0x14F6|2|Button 0 Bottom-Right X||
|0x14F8|2|Button 0 Bottom-Right Y||
|Ď|112|Ď|Ď|

Continued on next page![ref2]



|0x156A|2|Button 15 Top-Left X|Section[ 9.3](#_page47_x56.69_y195.46)|
| - | - | - | - |
|0x156C|2|Button 15 Top-Left Y||
|0x156E|2|Button 15 Bottom-Right X||
|0x1570|2|Button 15 Bottom-Right Y||
|**Read-Write**||**Virtual Slider Configuration**||
|0x1572|<a name="_page68_x270.68_y171.43"></a>2|Slider Deadzone|Section[ 9.4.1](#_page48_x56.69_y483.83)|
|0x1574|<a name="_page68_x266.73_y185.78"></a>2|Slider 0 Top-Left X|Section[ 9.4](#_page48_x56.69_y388.53)|
|0x1576|2|Slider 0 Top-Left Y||
|0x1578|<a name="_page68_x257.06_y214.47"></a>2|Slider 0 Bottom-Right X||
|0x157A|2|Slider 0 Bottom-Right Y||
|0x157C|<a name="_page68_x266.24_y243.16"></a>2|Slider 0 Resolution||
|Ď|60|Ď|Ď|
|0x15BA|2|Slider 7 Top-Left X|Section[ 9.4](#_page48_x56.69_y388.53)|
|0x15BC|2|Slider 7 Top-Left Y||
|0x15BE|2|Slider 7 Bottom-Right X||
|0x15C0|2|Slider 7 Bottom-Right Y||
|0x15C2|2|Slider 7 Resolution||
|**Read-Write**||**Virtual Wheel Configuration**||
|0x15C4|<a name="_page68_x268.48_y357.93"></a>2|Wheel 0 Centre X|Section[ 9.5](#_page50_x56.69_y119.14)|
|0x15C6|2|Wheel 0 Centre Y||
|0x15C8|<a name="_page68_x260.78_y386.62"></a>2|Wheel 0 Inner Radius||
|0x15CA|<a name="_page68_x259.85_y400.97"></a>2|Wheel 0 Outer Radius||
|0x15CC|<a name="_page68_x264.99_y415.32"></a>2|Wheel 0 Resolution||
|Ď|20|Ď|Ď|
|0x15E2|2|Wheel 3 Centre X|Section[ 9.5](#_page50_x56.69_y119.14)|
|0x15E4|2|Wheel 3 Centre Y||
|0x15E6|2|Wheel 3 Inner Radius||
|0x15E8|2|Wheel 3 Outer Radius||
|0x15EA|2|Wheel 3 Resolution||
|**Read-Write**||**Engineering Configuration**||
|0x2000|2|Engineering Configuration|Appendix[ A.25](#_page85_x56.69_y563.29)|
|0x2002|1|Main Oscillator Step Up|-|
|0x2003|1|Main Oscillator Step Down||
|0x2004|2|Main Oscillator Step Threshold||
|**Read Only**||**Trackpad Channel Information**||
|0xA000|<a name="_page68_x257.64_y601.82"></a>1012|Trackpad Count Values|Appendix[ A.27](#_page86_x56.69_y274.82)|
|0xB000|<a name="_page68_x249.08_y616.16"></a>1012|Trackpad Reference Values||
|0xC000|<a name="_page68_x259.14_y630.51"></a>1012|Trackpad Delta Values||
|0xD000|<a name="_page68_x232.88_y644.86"></a>1012|Trackpad ATI Compensation Values|Appendix[ A.26](#_page86_x56.69_y84.59)|
|0xE000|6|Unique Identifier|-|

<a name="_page69_x56.69_y84.59"></a>**A Memory Map Descriptions <a name="_page69_x56.69_y101.97"></a>A.1 Product Information**

<a name="_page69_x56.69_y130.67"></a>*Table A.1: IQS9150 / IQS9151 Product Info*



|**Address**|**Length**|**Description**|**IQS9150**|**IQS9151**|
| - | - | - | - | - |
|0x1000|2|Product Number|0x076A|0x09BC|
|0x1002|2|Product Major Version|0x0001|0x0001|
|0x1004|2|Product Minor Version|0x0002|0x0000|
|0x1006|4|Product SHA|-||
|0x100A|2|Library Number|0x037D||
|0x100C|2|Library Major Version|0x0001||
|0x100E|2|Library Minor Version|0x0000||
|0x1010|4|Library SHA|-||

<a name="_page69_x56.69_y323.15"></a>**A.2 Single Finger Gestures (0x101C)**



|**Bit**|**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|
| - | - | - | - | - | - | - | - | - |
|**Description**|<p>Swipe and</p><p>Hold Y-</p>|Swipe and Hold Y+|<p>Swipe and</p><p>Hold X-</p>|Swipe and Hold X+|Swipe Y-|Swipe Y+|Swipe X-|Swipe X+|



|**Bit**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Reserved|Palm Gesture|<p>Press-and-</p><p>Hold</p>|Triple Tap|Double Tap|Single Tap|||

- Bit 15: **Swipe and Hold Y-** - Swipe and hold in negative Y direction
- 0: No gesture
- 1: Swipe and hold in negative Y direction occurred
- Bit 14: **Swipe and Hold Y+** - Swipe and hold in positive Y direction
- 0: No gesture
- 1: Swipe and hold in positive Y direction occurred
- Bit 13: **Swipe and Hold X-** - Swipe and hold in negative X direction
- 0: No gesture
- 1: Swipe and hold in negative X direction occurred
- Bit 12: **Swipe and Hold X+** - Swipe and hold in positive X direction
- 0: No gesture
- 1: Swipe and hold in positive X direction occurred
- Bit 11: **Swipe Y-** - Swipe in negative Y direction
- 0: No gesture
- 1: Swipe in negative Y direction occurred
- Bit 10: **Swipe Y+** - Swipe in positive Y direction
- 0: No gesture
- 1: Swipe in positive Y direction occurred
- Bit 9: **Swipe X-** - Swipe in negative X direction
- 0: No gesture
- 1: Swipe in negative X direction occurred
- Bit 8: **Swipe X+** - Swipe in positive X direction
- 0: No gesture
- 1: Swipe in positive X direction occurred
- Bit 7-5: Unused
- Bit 4: **Palm Gesture** - Indicates a Palm gesture
- 0: No gesture
- 1: Palm gesture occurred![ref2]
- Bit 3: **Press-and-Hold** - Indicates a Press-and-Hold gesture
- 0: No gesture
- 1: Press-and-Hold occurred
- Bit 2: **Triple Tap** - Indicates a triple tap gesture
- 0: No gesture
- 1: Triple tap occurred
- Bit 1: **Double Tap** - Indicates a double tap gesture
- 0: No gesture
- 1: Double tap occurred
- Bit 0: **Single Tap** - Indicates a single tap gesture
- 0: No gesture
- 1: Single tap occurred

<a name="_page70_x56.69_y225.72"></a>**A.3 Two Finger Gestures (0x101E)**



|**Bit**|**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**||
| - | - | - | - | - | - | - | - | - | :- |
|**Description**|Reserved|||||||||



|**Bit**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Horizontal Scroll|Vertical Scroll|Zoom Out|Zoom In|<p>Press-and-</p><p>Hold</p>|Triple Tap|Double Tap|Single Tap|



- Bit 15-8: Unused
- Bit 7: **Horizontal Scroll** - Indicates a horizontal scroll gesture
- 0: No gesture
- 1: Horizontal scroll gesture occurred
- Bit 6: **Vertical Scroll** - Indicates a vertical scroll gesture
- 0: No gesture
- 1: Vertical scroll gesture occurred
- Bit 5: **Zoom Out** - Indicates a zoom out gesture
- 0: No gesture
- 1: Zoom out gesture occurred
- Bit 4: **Zoom In** - Indicates a zoom in gesture
- 0: No gesture
- 1: Zoom in gesture occurred
- Bit 3: **Press-and-Hold** - Indicates a Press-and-Hold gesture
- 0: No gesture
- 1: Press-and-Hold occurred
- Bit 2: **Triple Tap** - Indicates a triple tap gesture
- 0: No gesture
- 1: Triple tap occurred
- Bit 1: **Double Tap** - Indicates a double tap gesture
- 0: No gesture
- 1: Double tap occurred
- Bit 0: **Single Tap** - Indicates a single tap gesture
- 0: No gesture
- 1: Single tap occurred![ref2]

<a name="_page71_x56.69_y84.59"></a>**A.4 Info Flags (0x1020)**



|**Bit**|**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Snap Toggled|Switch Toggled|TP Touch Toggled|ALP Prox Toggled|Global Snap|Switch Pressed|Global TP Touch|ALP Prox Status|



|**Bit**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Show Reset|ALP Re-ATI Occurred|ALP ATI Error|Re-ATI Occurred|ATI Error|Charging Mode|||

- Bit 15: **Snap Toggled** - Snap detection status of a snap channel toggled
- 0: Snap output did not toggle
- 1: Snap output toggled
- Bit 14: **Switch Toggled** - Switch detection status toggled
- 0: Switch input did not toggle
- 1: Switch input toggled
- Bit 13: **TP Touch Toggled** - Touch detection status of a trackpad channel toggled
- 0: Touch status did not toggle
- 1: Touch status toggled
- Bit 12: **ALP Prox Toggled** - Prox detection status of ALP channel toggled
- 0: ALP Prox status did not toggle
- 1: ALP Prox status toggled
- Bit 11: **Global Snap** - Global snap detection status of any snap channel
- 0: No output detected
- 1: Output detected
- Bit 10: **Switch Pressed** - Switch pressed status
- 0: No switch press detected
- 1: Switch press detected
- Bit 9: **Global TP Touch** - Touch detection status of any TP channel
- 0: No TP touch detected
- 1: TP touch detected
- Bit 8: **ALP Prox Status** - Prox/Touch detection status of ALP channel
- 0: No output detected
- 1: Output detected
- Bit 7: **Show Reset** - Indicates a reset
- 0: Reset indication has been cleared by host, writing to *Ack Reset*
- 1: Reset has occurred and indication has not been cleared by host
- Bit 6: **ALP Re-ATI Occurred** - Alternate Low Power channel Re-ATI Status
- 0: No re-ATI
- 1: Re-ATI has just completed on alternate LP channel
- Bit 5: **ALP ATI Error**- Alternate Low Power ATI error status
- 0: Most recent ATI process was successful
- 1: Most recent ATI process was unsuccessful
- Bit 4: **Re-ATI Occurred** - Trackpad re-ATI status
- 0: No re-ATI
- 1: Re-ATI has just completed on the trackpad
- Bit 3: **ATI Error**- Error condition seen on latest trackpad ATI procedure
- 0: Most recent ATI process was successful
- 1: Most recent ATI process was unsuccessful
- Bit 2-0: **Charging Mode** - Indicates current mode
- 000: Active mode
- 001: Idle-touch mode
- 010: Idle mode
- 011: LP1 mode
- 100:<a name="_page71_x56.69_y712.72"></a> LP2 mode![ref2]

**A.5 Trackpad Flags (0x1022)**



|**Bit**|**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Reserved|Finger 7 Confidence|Finger 6 Confidence|Finger 5 Confidence|Finger 4 Confidence|Finger 3 Confidence|Finger 2 Confidence|Finger 1 Confidence|



|**Bit**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Saturation|Main Osc Stepped|Too Many Fingers|Movement Detected|Number of Fingers||||



- Bit 15: Unused
- Bit 14-8: **Finger Confidence** - Confidence that the touch detected is a legitimate finger input
- 0: Not confident that the touch is a finger input
- 1: Confident that the touch is a finger input
- Bit 7: **Saturation** - Saturation detection status
- 0: No saturation detected
- 1: Saturation detected
- Bit 6: **Main Osc Stepped** - Frequency adjusted due to detected noise
- 0: Oscillator not adjusted
- 1: Oscillator adjusted
- Bit 5: **Too Many Fingers** - Indicates more than allowed fingers detected
- 0: Number of fingers within maximum selected value
- 1: Number of fingers exceeds maximum selected value
- Bit 4: **Movement Detected** - Trackpad finger movement detected
- 0: No touches, or all touches stationary (see Section[ 7.5)](#_page32_x56.69_y84.59)
- 1: Movement of finger(s) detected on trackpad
- Bit 3-0: **Number of Fingers** - Number of fingers detected on trackpad
- 0000: No fingers on trackpad
- 0001: 1 fingers active
- 0010: 2 fingers active
- 0011: 3 fingers active
- 0100: 4 fingers active
- 0101: 5 fingers active
- 0110: 6 fingers active
- 0111: 7 fingers active

<a name="_page72_x56.69_y498.09"></a>**A.6 ALP Individual Counts (0x10B8)![ref2]**



|**Address**|<a name="_page72_x56.69_y764.34"></a>**Bit**|||||||||||||||||
| - | - | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- |
||**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**||
|0x10B8|ALP Counts Rx0 and/or Rx13|||||||||||||||||
|0x10BA|ALP Counts Rx1 and/or Rx14|||||||||||||||||
|0x10BC|ALP Counts Rx2 and/or Rx15|||||||||||||||||
|0x10BE|ALP Counts Rx3 and/or Rx16|||||||||||||||||
|0x10C0|ALP Counts Rx4 and/or Rx17|||||||||||||||||
|0x10C2|ALP Counts Rx5 and/or Rx18|||||||||||||||||
|0x10C4|ALP Counts Rx6 and/or Rx19|||||||||||||||||
|0x10C6|ALP Counts Rx7 and/or Rx20|||||||||||||||||
|0x10C8|ALP Counts Rx8 and/or Rx21|||||||||||||||||
|0x10CA|ALP Counts Rx9 and/or Rx22|||||||||||||||||
|0x10CC|ALP Counts Rx10 and/or Rx23|||||||||||||||||
|0x10CE|ALP Counts Rx11 and/or Rx24|||||||||||||||||
|0x10D0|ALP Counts Rx12 and/or Rx25|||||||||||||||||

**A.7 Button Output (0x112A)**



|**Bit**|**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Button 15|Button 14|Button 13|Button 12|Button 11|Button 10|Button 9|Button 8|



|**Bit**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Button 7|Button 6|Button 5|Button 4|Button 3|Button 2|Button 1|Button 0|

- Button state for Button 0 - Button 15
- 0: Virtual touch button not pressed
- 1: Virtual touch button pressed

<a name="_page73_x56.69_y232.49"></a>**A.8 Slider Output (0x112C)**



|**Address**|**Length**|**Description**|
| - | - | - |
|0x112C|2|Slider 0 output for Finger 1|
|0x112E|2|Slider 0 output for Finger 2|
|0x1130|2|Slider 1 output for Finger 1|
|0x1132|2|Slider 1 output for Finger 2|
|0x1134|2|Slider 2 output for Finger 1|
|0x1136|2|Slider 2 output for Finger 2|
|0x1138|2|Slider 3 output for Finger 1|
|0x113A|2|Slider 3 output for Finger 2|
|0x113C|2|Slider 4 output for Finger 1|
|0x113E|2|Slider 4 output for Finger 2|
|0x1140|2|Slider 5 output for Finger 1|
|0x1142|2|Slider 5 output for Finger 2|
|0x1144|2|Slider 6 output for Finger 1|
|0x1146|2|Slider 6 output for Finger 2|
|0x1148|2|Slider 7 output for Finger 1|
|0x114A|2|Slider 7 output for Finger 2|

<a name="_page73_x56.69_y537.39"></a>**A.9 Wheel Output (0x114C)![ref2]**



|**Address**|<a name="_page73_x56.69_y725.29"></a>**Length**|**Description**|
| - | - | - |
|0x114C|2|Wheel 0 output for Finger 1|
|0x114E|2|Wheel 0 output for Finger 2|
|0x1150|2|Wheel 1 output for Finger 1|
|0x1152|2|Wheel 1 output for Finger 2|
|0x1154|2|Wheel 2 output for Finger 1|
|0x1156|2|Wheel 2 output for Finger 2|
|0x1158|2|Wheel 3 output for Finger 1|
|0x115A|2|Wheel 3 output for Finger 2|

**A.10 ALP ATI Compensation (0x115C)**



|**Address**|**Bit**||||||||||||||||
| - | - | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- |
||**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
||**-**|**ALP Compensation Divider**|**ALP Compensation**||||||||||||||
|0x115C|Rx0 and/or Rx13||||||||||||||||
|0x115E|Rx1 and/or Rx14||||||||||||||||
|0x1160|Rx2 and/or Rx15||||||||||||||||
|0x1162|Rx3 and/or Rx16||||||||||||||||
|0x1164|Rx4 and/or Rx17||||||||||||||||
|0x1166|Rx5 and/or Rx18||||||||||||||||
|0x1168|Rx6 and/or Rx19||||||||||||||||
|0x116A|Rx7 and/or Rx20||||||||||||||||
|0x116C|Rx8 and/or Rx21||||||||||||||||
|0x116E|Rx9 and/or Rx22||||||||||||||||
|0x1170|Rx10 and/or Rx23||||||||||||||||
|0x1172|Rx11 and/or Rx24||||||||||||||||
|0x1174|Rx12 and/or Rx25||||||||||||||||



- Bit 15: Unused
- Bit 14-10: **ALP Compensation Divider**
- Bit 9-0: **ALP Compensation**

<a name="_page74_x56.69_y403.93"></a>**A.11 Trackpad and ALP Multipliers / Divider (0x117A / 0x117C)**



|**Address**|**Bit**||||||||||||||||
| - | - | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- |
||**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
||**Fine Mult**|**Fine Divider**|**Coarse Multiplier**|**Coarse Divider**|||||||||||||
|0x117A|Trackpad||||||||||||||||
|0x117C|ALP Rx0 + Rx13||||||||||||||||
|0x117E|ALP Rx1 + Rx14||||||||||||||||
|0x1180|ALP Rx2 + Rx15||||||||||||||||
|0x1182|ALP Rx3 + Rx16||||||||||||||||
|0x1184|ALP Rx4 + Rx17||||||||||||||||
|0x1186|ALP Rx5 + Rx18||||||||||||||||
|0x1188|ALP Rx6 + Rx19||||||||||||||||
|0x118A|ALP Rx7 + Rx20||||||||||||||||
|0x118C|ALP Rx8 + Rx21||||||||||||||||
|0x118E|ALP Rx9 + Rx22||||||||||||||||
|0x1190|ALP Rx10 + Rx23||||||||||||||||
|0x1192|ALP Rx11 + Rx24||||||||||||||||
|0x1194|ALP Rx12 + Rx25||||||||||||||||

- Bit 15-14: **Fine Multiplier**
- 2-bit value between 1 and 2
- Recommend to keep 1
- Bit 13-9: **Fine Divider**
- 5-bit value between 1 and 21
- Recommend to keep above 6![ref2]
- Bit 8-5: **Coarse Multiplier**
- 4-bit value between 1 and 15
- Use Azoteq recommended sets as defined in GUI software
- Bit 4-0: **Coarse Divider**
- 5-bit value between 1 and 31
- Use Azoteq recommended sets as defined in GUI software

<a name="_page75_x56.69_y159.97"></a>**A.12 System Control (0x11BC)**



|**Bit**|**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Tx Short Test|Reserved|Suspend|Reserved|S WReset|Re served|||



|**Bit**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Ack Reset|ALP Re-ATI|TP Re-ATI|ALP Reseed|TP Reseed|Mode Select|||

- Bit 15: **Tx Short Test** - Tx short test
- 0: Normal operation
- 1: Enable Tx short test configuration
- Bit 14-12: Unused
- Bit 11: **Suspend** - Suspend IQS9150/IQS9151
- 0: No action
- 1: Place IQS9150/IQS9151 into suspend after the communication window terminates
- Bit 10: Unused
- Bit 9: **SW Reset** - Reset the device
- 0: No action
- 1: Reset device after communication window terminates
- Bit 8: Unused
- Bit 7: **Ack Reset** - Acknowledge a reset
- 0: No action
- 1: Acknowledge the reset by clearing *Show Reset* flag
- Bit 6: **ALP Re-ATI** - Queue a re-ATI on ALP channel
- 0: No action
- 1: Perform re-ATI when ALP channel is sensed again
- Bit 5: **TP Re-ATI** - Queue a re-ATI on trackpad channels
- 0: No action
- 1: Perform re-ATI when trackpad channels are sensed again
- Bit 4: **ALP Reseed** - Queue a reseed on ALP channel
- 0: No action
- 1: Reseed the LTA of the ALP channel when it is sensed again
- Bit 3: **TP Reseed** - Queue a reseed on trackpad channels
- 0: No action
- 1: Reseed reference values of the trackpad channels when it is sensed again
- Bit 2-0: **Mode Select** - Select mode (only applicable in *Manual Mode)*
- 000: Active mode
- 001: Idle-Touch mode
- 010: Idle mode
- 011: LP1 mode
- 100: LP2 mode![ref2]

<a name="_page76_x56.69_y84.59"></a>**A.13 Configuration Settings (0x11BE)**



|**Bit**|**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Snap Event Enable|Switch Event Enable|TP Touch Event Enable|ALP Event Enable|<p>Re-ATI Event</p><p>Enable</p>|TP Event Enable|Gesture Event Enable|Event Mode|



|**Bit**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Manual Control|<p>Terminate Comms</p><p>Window</p>|Sleep During Con- versions|Force Comms Method|ALP Re-ATI Enable|TP Re-ATI Enable|ALP ATI Mode|Sleep Option|

- Bit 15: **Snap Event Enable** - Enable snap triggering event
- 0: Toggle of snap status does not trigger an event
- 1: Toggle of snap status triggers an event
- Bit 14: **Switch Event Enable** - Enable switch triggering event
- 0: Toggle of switch status does not trigger an event
- 1: Toggle of switch status triggers an event
- Bit 13: **TP Touch Event Enable** - Enable trackpad touch triggering event
- 0: Toggle of trackpad touch status does not trigger an event
- 1: Toggle of trackpad touch status triggers an event
- Bit 12: **ALP Event Enable** - Enable alternate LP channel detection triggering event
- 0: Toggle of alternate channel prox/touch status does not trigger an event
- 1: Toggle of alternate channel prox/touch status triggers an event
- Bit 11: **Re-ATI Event Enable** - Enable Re-ATI generating an event
- 0: Re-ATI occurring does not trigger an event
- 1: Re-ATI occurring triggers an event
- Bit 10: **TP Event Enable** - Enable trackpad events
- 0: Trackpad finger movement or finger up/down will not trigger event
- 1: Trackpad finger movement or finger up/down will trigger event
- Bit 9: **Gesture Event Enable** - Enable gesture events
- 0: Gestures will not trigger event
- 1: Gestures will trigger event
- Bit 8: **Event Mode** - Enable event mode communication
- 0: I2C is presented each cycle (except auto-prox cycles)
- 1: I2C is only initiated when an enabled event occurs
- Bit 7: **Manual Control** - Override automatic mode switching
- 0: Modes are automatically controlled by IQS9150/IQS9151 firmware (recommended)
- 1: Manual control of modes are handled by host
- Bit 6: **Terminate Comms Window** - Alternative method to terminate comms (see Section[ 12.7)](#_page57_x56.69_y281.02)
- 0: I2C stop ends comms
- 1: *Terminate Comms Window* command, followed by an I2C STOP end comms
- Bit 5: **Sleep During Conversions** - Prevent processing during conversions
- 0: Normal (recommended)
- 1: Sleep (increases latency and current consumption)
- Bit 4: **Force Comms Method** - Force comms method selection (while RDY not LOW)
- 0: Forcing comms will clock stretch until a comms window (Normal I2C outside RDY window)
- 1: A comms window must be requested with a command (no stretching) outside comms window
- Bit 3: **ALP Re-ATI Enable** - Automatic Re-ATI on alternate LP channel
- 0: Re-ATI is disabled for alternate LP channel
- 1: Re-ATI is enabled for alternate LP channel (recommended)
- Bit 2: **TP Re-ATI Enable** - Automatic Re-ATI on trackpad
- 0: Re-ATI is disabled for trackpad channels
- 1: Re-ATI is enabled for trackpad channels (recommended)
- Bit 1: **ALP ATI Mode** - ALP ATI mode
- 0: Compensation only
- 1: Full ATI
- Bit 0: **Sleep Option** - Internal device sleep selection
- 0: Deep sleep (recommended)
- 1:<a name="_page76_x56.69_y769.47"></a> Light sleep![ref2]

**A.14 Other Settings (0x11C0)**



|**Bit**|**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Switch Enable|Switch Polarity|Prox Oscillator Adjustment|Reserved|||||



|**Bit**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Main Oscillator Selection|LP2 Auto-Prox Enable|LP1 Auto-Prox Enable|LP2 Auto-Prox Cycles|LP1 Auto-Prox Cycles||||

- Bit 15: **Switch Enable** - Enable switch input
- 0: Switch disabled
- 1: Switch enabled
- Bit 14: **Switch Polarity** - Switch polarity selection
- 0: Active-low
- 1: Active-high
- Bit 13-12: **Prox Oscillator Adjustment** - Adjust Prox oscillator frequency
- 00: Nominal (16 MHz)
- 01: -10% (Main Osc 14 MHz) / -20% (Main Osc 20 MHz/24 MHz)
- 10: -20% (Main Osc 14 MHz) / -30% (Main Osc 20 MHz/24 MHz)
- 11: -30% (Main Osc 14 MHz) / -40% (Main Osc 20 MHz/24 MHz)
- Bit 11-8: Unused
- Bit 7-6: **Main Oscillator Selection** - Main oscillator frequency selection
- 00: 14 MHz
- 01: 20 MHz
- 10: 24 MHz
- Bit 5: **LP2 Auto-Prox Enable** - Enable or disable LP2 Auto-Prox
- 0: LP2 Auto-Prox disabled
- 1: LP2 Auto-Prox enabled
- Bit 4: **LP1 Auto-Prox Enable** - Enable or disable LP1 Auto-Prox
- 0: LP1 Auto-Prox disabled
- 1: LP1 Auto-Prox enabled
- Bit 3-2: **LP2 Auto-Prox Cycles** - Number of LP2 auto-prox cycles
- 00: 16
- 01: 32
- 10: 64
- 11: 256
- Bit 1-0: **LP1 Auto-Prox Cycles** - Number of LP1 auto-prox cycles
- 00: 16
- 01: 32
- 10: 64
- 11:<a name="_page77_x56.69_y583.81"></a> 256![ref2]

**A.15 ALP Setup (0x11C2)**



|**Bit**|**31**|**30**|**29**|**28**|**27**|**26**|**25**|**24**|
| - | - | - | - | - | - | - | - | - |
|**Description**|ALP Enable|ALP Count Filter Enable|ALP Sensing Method|Active Tx Shield Enable|Reserved|<p>Rx25 Enable</p><p>[a](#_page78_x60.52_y313.00)</p>|<p>Rx24 Enable</p><p>[a](#_page78_x60.52_y313.00)</p>||
||||||||||
|**Bit**|**23**|**22**|**21**|**20**|**19**|**18**|**17**|**16**|
|**Description**|<p>Rx23 Enable</p><p>[a](#_page78_x60.52_y313.00)</p>|<p>Rx22 Enable</p><p>[a](#_page78_x60.52_y313.00)</p>|<p>Rx21 Enable</p><p>[a](#_page78_x60.52_y313.00)</p>|<p>Rx20 Enable</p><p>[a](#_page78_x60.52_y313.00)</p>|<p>Rx19 Enable</p><p>[a](#_page78_x60.52_y313.00)</p>|<p>Rx18 Enable</p><p>[a](#_page78_x60.52_y313.00)</p>|<p>Rx17 Enable</p><p>[a](#_page78_x60.52_y313.00)</p>|<p>Rx16 Enable</p><p>[a](#_page78_x60.52_y313.00)</p>|
||||||||||
|**Bit**|**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|
|**Description**|<p>Rx15 Enable</p><p>[a](#_page78_x60.52_y313.00)</p>|<p>Rx14 Enable</p><p>[a](#_page78_x60.52_y313.00)</p>|<p>Rx13 Enable</p><p>[a](#_page78_x60.52_y313.00)</p>|Rx12 Enable|Rx11 Enable|Rx10 Enable|Rx9 Enable|Rx8 Enable|
||||||||||
|**Bit**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
|**Description**|Rx7 Enable|Rx6 Enable|Rx5Enable R|x4Enable Rx|3Enable Rx2|Enable Rx1|Enable Rx0 E|nable|

a<a name="_page78_x60.52_y313.00"></a> Not applicable to IQS9151. Keep set to ‘0’.

- Bit 31: **ALP Enable** - Enable ALP channel
- 0: ALP channel is disabled, trackpad channels active in LP1 and LP2
- 1: ALP channel is enabled, ALP channel active in LP1 and LP2
- Bit 30: **ALP Count Filter Enable** - ALP count filter
- 0: ALP channel count is unfiltered
- 1: ALP count filter enabled
- Bit 29: **ALP Sensing Method** - ALP sensing method
- 0: ALP is setup for self-capacitive sensing
- 1: ALP is setup for mutual-capacitive sensing
- Bit 28: **Active Tx Shield Enable** - Configure Tx behaviour for self cap ALP setup
- 0: All unused electrodes are grounded
- 1: All ALP enabled Txs mimic Rx signal to reduce parasitic capacitance to GND
- Bit 27-26: Unused
- Bit 25-0: **Rx Enable** - ALP Rx electrodes
- 0: Rx disabled (not used for ALP)
- 1:<a name="_page78_x56.69_y522.49"></a> Rx enabled (forms part of ALP sensor)![ref2]

**A.16 ALP Tx Enable (0x11C6)**



|**Bit**|**47**|**46**|**45**|**44**|**43**|**42**|**41**|**40**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Reserved|Tx45 Enable|Reserved|Tx43 Enable|Tx42 Enable|Tx41 Enable|Tx40 Enable||
||||||||||
|**Bit**|**39**|**38**|**37**|**36**|**35**|**34**|**33**|**32**|
|**Description**|Tx39 Enable|Tx38 Enable|Tx37 Enable|Tx36 Enable|Tx35 Enable|Tx34 Enable|Tx33 Enable|<p>Tx32 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|
||||||||||
|**Bit**|**31**|**30**|**29**|**28**|**27**|**26**|**25**|**24**|
|**Description**|<p>Tx31 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|<p>Tx30 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|<p>Tx29 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|<p>Tx28 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|<p>Tx27 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|<p>Tx26 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|<p>Tx25 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|<p>Tx24 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|
||||||||||
|**Bit**|**23**|**22**|**21**|**20**|**19**|**18**|**17**|**16**|
|**Description**|<p>Tx23 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|<p>Tx22 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|<p>Tx21 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|<p>Tx20 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|<p>Tx19 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|<p>Tx18 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|<p>Tx17 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|<p>Tx16 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|
||||||||||
|**Bit**|**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|
|**Description**|<p>Tx15 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|<p>Tx14 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|<p>Tx13 Enable</p><p>[a](#_page79_x60.52_y410.04)</p>|Tx12 Enable|Tx11 Enable|Tx10 Enable|Tx9 Enable|Tx8 Enable|
||||||||||
|**Bit**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
|**Description**|Tx7 Enable|Tx6 Enable|Tx5Enable T|x4Enable Tx|3 Enable Tx|2Enable Tx1|Enable Tx0|Enable|

a<a name="_page79_x60.52_y410.04"></a> Not applicable to IQS9151. Keep set to ‘0’.

- Bit 47-46: Unused
- Bit 44: Do not use, keep 0
- Bit 45, 43-0: **Tx Enable** - ALP Tx electrodes selection
- 0: Tx disabled (not used for ALP)
- 1: Tx enabled (forms part of ALP sensor)

<a name="_page79_x56.69_y498.98"></a>**A.17 Trackpad and ALP Conversion Frequency (0x11D8 and 0x11DB)**



|**Address**|**Length**|**Description**|
| - | - | - |
|0x11D8|1|Trackpad Fraction Value|
|0x11D9|1|Trackpad Period1 Value|
|0x11DA|1|Trackpad Period2 Value|
|0x11DB|1|ALP Fraction Value|
|0x11DC|1|ALP Period1 Value|
|0x11DD|1|ALP Period2 Value|

- Please refer to Table[ A.7 ](#_page80_x56.69_y77.81)below for the values to configure the desired conversion frequency.![ref2]

<a name="_page80_x56.69_y77.81"></a>*Table A.7: Conversion Frequency Selections*



|<p>**Conversion Frequency**</p><p>**(MHz)**</p>|**Fraction Value**|**Period1 Value**|**Period1 Value**|
| - | :-: | :-: | :-: |
|0\.25|4|31|31|
|0\.50|8|15|15|
|0\.75|12|9|10|
|1\.00|16|7|7|
|1\.25|20|5|5|
|1\.50|24|4|4|
|1\.75|28|3|4|
|2\.00|32|3|3|
|2\.25|36|2|3|
|2\.50|40|2|2|
|2\.75|44|1|2|
|3\.00|48|1|2|
|3\.25|52|1|1|
|3\.50|56|1|1|
|4\.00|64|1|1|

<a name="_page80_x56.69_y369.32"></a>**A.18 Trackpad and ALP Hardware Settings (0x11DE and 0x11E0)**



|**Bit**|**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Initial Cycle Delay|SH Bias|Count Upper Limit||||||



|**Bit**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Cs Dis- charge Voltage|RF Filters|NM Out Static|NM In Static|Global SH Offset||||

- Bit 15-14: **Initial Cycle Delay** - Initial cycles delay
- 00: 16
- 01: 32
- 10: 64
- 11: 256
- Bit 13-11: **SH Bias** - Sample-and-hold opamp bias current
- 000: 5 A
- 001: 10 A
- 010: 15 A
- 011: 20 A
- 100: 15 A
- 101: 20 A
- 110: 25 A
- 111: 30 A
- Bit 10-8: **Count Upper Limit** - Count upper limit (count value stops conversion after reaching this)
- 000: 383
- 001: 511
- 010: 767
- 011: 1023
- 100: 2047![ref2]
- Bit 7: **Cs Discharge Voltage** - Select internal Cs discharge voltage
- 0: Discharge to 0 V (recommended for most cases)
- 1: Discharge to 0.5 V
- Bit 6: **RF Filter** - Internal RF filters
- 0: RF filters disabled
- 1: RF filters enabled
- Bit 5: **NM Out Static** - NM out static
- 0: Disabled (recommended)
- 1: Enabled
- Bit 4: **NM In Static** - NM in static
- 0: Disabled (recommended)
- 1: Enabled
- Bit 3-0: **Global SH Offset** - Global SH offset
- 0000: 0 mV
- 0001: -2 mV
- 0010: -4 mV
- 0011: -6 mV
- 0100: -8 mV
- 0101: -10 mV
- 0110: -12 mV
- 0111: -14 mV
- 1001: +2 mV
- 1010: +4 mV
- 1011: +6 mV
- 1100: +8 mV
- 1101: +10 mV
- 1110: +12 mV
- 1111: +14 mV

<a name="_page81_x56.69_y399.11"></a>**A.19 Trackpad Settings (0x11E2)**



|**Bit**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Reserved|Area Filter Disable|Jitter Filter|IIR Static|IIR Filter|Switch XY Axis|Flip Y|Flip X|



- Bit 7: Unused
- Bit 6: **Area Filter Disable** - Disable area filter
- 0: Area filter on touch position enabled
- 1: Area filter on touch position disabled
- Bit 5: **Jitter Filter** - Enable jitter filter
- 0: XY jitter filter on touch position disabled
- 1: XY jitter filter on touch position enabled
- Bit 4: **IIR Static** - IIR filtering method for the XY data points
- 0: Damping factor for IIR filter is dynamically adjusted relative to XY movement (recommended)
- 1: Damping factor for IIR filter is fixed
- Bit 3: **IIR Filter**- IIR filter
- 0: XY IIR filter disabled
- 1: XY IIR filter enabled (recommended)
- Bit 2: **Switch XY Axis** - Switch X and Y axes
- 0: Rxs are arranged in trackpad columns (X), and Txs in rows (Y)
- 1: Txs are arranged in trackpad columns (X), and Rxs in rows (Y)
- Bit 1: **Flip Y** - Flip Y output values
- 0: Keep default Y values
- 1: Invert Y output values
- Bit 0: **Flip X** - Flip X output values
- 0: Keep default X values
- 1:<a name="_page81_x56.69_y744.08"></a> Invert X output values![ref2]

**A.20 Single Finger Gesture Enable (0x11F6)**



|**Bit**|**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|
| - | - | - | - | - | - | - | - | - |
|**Description**|<p>Swipe and</p><p>Hold Y-</p>|Swipe and Hold Y+|<p>Swipe and</p><p>Hold X-</p>|Swipe and Hold X+|Swipe Y-|Swipe Y+|Swipe X-|Swipe X+|



|**Bit**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Reserved|Palm Gesture|<p>Press-and-</p><p>Hold</p>|Triple Tap|Double Tap|Single Tap|||

- Bit 15: **Swipe and Hold Y-** - Swipe and hold in negative Y direction
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 14: **Swipe and Hold Y+** - Swipe and hold in positive Y direction
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 13: **Swipe and Hold X-** - Swipe and hold in negative X direction
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 12: **Swipe and Hold X+** - Swipe and hold in positive X direction
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 11: **Swipe Y-** - Swipe in negative Y direction
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 10: **Swipe Y+** - Swipe in positive Y direction
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 9: **Swipe X-** - Swipe in negative X direction
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 8: **Swipe X+** - Swipe in positive X direction
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 7-5: Unused
- Bit 4: **Palm Gesture** - Palm gesture
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 3: **Press-and-Hold** - Press-and-Hold gesture
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 2: **Triple Tap** - Triple tap gesture
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 1: **Double Tap** - Double tap gesture
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 0: **Single Tap** - Single tap gesture
- 0: Gesture disabled
- 1: Gesture enabled![ref2]

<a name="_page83_x56.69_y84.59"></a>**A.21 Two Finger Gesture Enable (0x11F8)**



|**Bit**|**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**||
| - | - | - | - | - | - | - | - | - | :- |
|**Description**|Reserved|||||||||



|**Bit**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Horizontal Scroll|Vertical Scroll|Zoom Out|Zoom In|<p>Press-and-</p><p>Hold</p>|Triple Tap|Double Tap|Single Tap|



- Bit 15-8: Unused
- Bit 7: **Horizontal Scroll** - Indicates a horizontal scroll gesture
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 6: **Vertical Scroll** - Indicates a vertical scroll gesture
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 5: **Zoom Out** - Indicates a zoom out gesture
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 4: **Zoom In** - Indicates a zoom in gesture
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 3: **Press-and-Hold** - Indicates a Press-and-Hold gesture
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 2: **Triple Tap** - Indicates a triple tap gesture
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 1: **Double Tap** - Indicates a double tap gesture
- 0: Gesture disabled
- 1: Gesture enabled
- Bit 0: **Single Tap** - Indicates a single tap gesture
- 0: Gesture disabled
- 1: Gesture enabled

<a name="_page83_x56.69_y485.18"></a>**A.22 RxTx Mapping (0x1218)**



|**Address**|**Length**|**Description**|
| - | - | - |
|0x1218|1|RxTx Mapping 0|
|0x1219|1|RxTx Mapping 1|
|0x121A|1|RxTx Mapping 2|
|0x121B|1|RxTx Mapping 3|
|0x121C|1|RxTx Mapping 4|
|0x121D|1|RxTx Mapping 5|
|0x121E|1|RxTx Mapping 6|
|0x121F|1|RxTx Mapping 7|
|0x1220|1|RxTx Mapping 8|
|0x1221|1|RxTx Mapping 9|
|0x1222|1|RxTx Mapping 10|
|0x1223|1|RxTx Mapping 11|
|0x1224|1|RxTx Mapping 12|
|0x1225|1|RxTx Mapping 13|
|0x1226|1|RxTx Mapping 14|

*Continued on next page...![ref2]*

|0x1227|1|RxTx Mapping 15|
| - | - | - |
|0x1228|1|RxTx Mapping 16|
|0x1229|1|RxTx Mapping 17|
|0x122A|1|RxTx Mapping 18|
|0x122B|1|RxTx Mapping 19|
|0x122C|1|RxTx Mapping 20|
|0x122D|1|RxTx Mapping 21|
|0x122E|1|RxTx Mapping 22|
|0x122F|1|RxTx Mapping 23|
|0x1230|1|RxTx Mapping 24|
|0x1231|1|RxTx Mapping 25|
|0x1232|1|RxTx Mapping 26|
|0x1233|1|RxTx Mapping 27|
|0x1234|1|RxTx Mapping 28|
|0x1235|1|RxTx Mapping 29|
|0x1236|1|RxTx Mapping 30|
|0x1237|1|RxTx Mapping 31|
|0x1238|1|RxTx Mapping 32|
|0x1239|1|RxTx Mapping 33|
|0x123A|1|RxTx Mapping 34|
|0x123B|1|RxTx Mapping 35|
|0x123C|1|RxTx Mapping 36|
|0x123D|1|RxTx Mapping 37|
|0x123E|1|RxTx Mapping 38|
|0x123F|1|RxTx Mapping 39|
|0x1240|1|RxTx Mapping 40|
|0x1241|1|RxTx Mapping 41|
|0x1242|1|RxTx Mapping 42|
|0x1243|1|RxTx Mapping 43|
|0x1244|1|RxTx Mapping 44|
|0x1245|1|Reserved (0x00)|



- Byte 44-0: **RxTxMapping** - Trackpad Rx and Tx mapping, see Section[ 7.1.4](#_page30_x56.69_y408.50)
- **Note:** The value 44 (0x2C) may not be written to any of the registers![ref2]

<a name="_page85_x56.69_y84.59"></a>**A.23 Individual Touch Threshold Adjustments (0x12F6)**



|**Address**|**Length**|**Description**|
| - | - | - |
|0x12F6|1|CH0 Touch Threshold Adjustment|
|0x12F7|1|CH1 Touch Threshold Adjustment|
|0x12F8|1|CH2 Touch Threshold Adjustment|
|Ď|500|Ď|
|0x14ED|1|CH503 Touch Threshold Adjustment|
|0x14EE|1|CH504 Touch Threshold Adjustment|
|0x14EF|1|CH505 Touch Threshold Adjustment|

- **CH Touch Threshold Adjustment** - Signed 8-bit values, see Section[ 5.6.1](#_page23_x56.69_y143.47)
- 0000 0000: Threshold Multiplier + 0
- 0000 0001: Threshold Multiplier + 1
- 0000 0010: Threshold Multiplier + 2
- 0000 0011: Threshold Multiplier + 3

Ď

- 0111 1111: Threshold Multiplier + 127
- 1000 0000: Threshold Multiplier - 128
- 1000 0001: Threshold Multiplier - 127

Ď

- 1111 1101: Threshold Multiplier - 3
- 1111 1110: Threshold Multiplier - 2
- 1111 1111: Threshold Multiplier - 1

<a name="_page85_x56.69_y397.63"></a>**A.24 Number Of Virtual Sensors Enabled (0x14F0)**



|**Bit**|**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Number of Wheels|Number of Sliders|||||||



|**Bit**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**||
| - | - | - | - | - | - | - | - | - | :- |
|**Description**|Number of Buttons|||||||||



- Bit 15-12: **Number of Wheels** - Number of virtual wheels enabled, see Section[ 9.1](#_page46_x56.69_y570.86)
- Bit 11-8: **Number of Sliders** - Number of virtual sliders enabled
- Bit 7-0: **Number of Buttons** - Number of virtual buttons enabled

<a name="_page85_x56.69_y563.29"></a>**A.25 Engineering Configuration (0x2000)**



|**Bit**|**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|
| - | - | - | - | - | - | - | - | - |
|**Description**|Reserved|Main Osc Status|Reserved||||||



|**Bit**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**||
| - | - | - | - | - | - | - | - | - | :- |
|**Description**|Reserved|<p>Main Osc Stepping</p><p>Enable</p>||||||||



- Bit 15-11: Unused
- Bit 10-9: **Main Oscillator Status**
- Bit 8-1: Unused
- Bit 0: **Main Oscillator Stepping Enable![ref2]**

<a name="_page86_x56.69_y84.59"></a>**A.26 Trackpad ATI Compensation (0xD000)**



|**Address**|**Bit**||||||||||||||||
| - | - | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- |
||**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
||**-**|**Trackpad Compensation Divider**|**Trackpad Compensation**||||||||||||||
|0xD000|CH0||||||||||||||||
|0xD002|CH1||||||||||||||||
|0xD004|CH2||||||||||||||||
|Ď|Ď||||||||||||||||



- Bit 15: Unused
- Bit 14-10: **Trackpad Compensation Divider**
- Bit 9-0: **Trackpad Compensation**

<a name="_page86_x56.69_y274.82"></a>**A.27 Count / Delta / Reference Data**

For the count, delta, and reference values (2 bytes per channel), the structure is defined as shown in thetablebelow.Thedatainthetableisintheformatof Count/Delta/ReferenceValue[*Row/Tx* ][*Column/Rx*]. Table[ A.10 ](#_page86_x56.69_y355.07)is valid for a 26 Rx by 19 Tx trackpad.

<a name="_page86_x56.69_y355.07"></a>*Table A.10: Count / Delta / Reference Value Bytes for a 26 Rx by 19 Tx Trackpad*



|**Byte Number**|**Data**|**Description**|
| - | - | - |
|X|Count/Delta/Reference Value[0][0] - Low Byte|<p>Count, delta or reference at 1st Tx,</p><p>and 1st Rx (thus top left)</p>|
|X+1|Count/Delta/Reference Value[0][0] - High Byte||
|X+2|Count/Delta/Reference Value[0][1] - Low Byte|<p>Count, delta or reference at 1st Tx,</p><p>and 2nd Rx</p>|
|X+3|Count/Delta/Reference Value[0][1] - High Byte||
|Ď|Ď||
|X+986|Count/Delta/Reference Value[18][25] - Low Byte|Count, delta or reference at 19th Tx, and 26th Rx (thus bottom right)|
|X+987|Count/Delta/Reference Value[18][25] - High Byte||
For a trackpad with fewer than 26 Rxs, the values are densely packed based on the setting for *Total Rxs*. Consequently, the subsequent values become available immediately after reaching the specified *Total Rxs* value. For instance, in a 4 Rx by 2 Tx trackpad configuration, the values are packed from address X to X+15, as illustrated in Table[ A.11 ](#_page86_x80.48_y594.53)below:

<a name="_page86_x80.48_y594.53"></a>*Table A.11: Count / Delta / Reference Value Bytes for a 4 Rx by 2 Tx Trackpad*



|**Byte Number**|**Data**|**Description**|
| - | - | - |
|X|Count/Delta/Reference Value[0][0] - Low Byte|<p>Count, delta or reference at 1st Tx,</p><p>and 1st Rx (thus top left)</p>|
|X+1|Count/Delta/Reference Value[0][0] - High Byte||
|X+2|Count/Delta/Reference Value[0][1] - Low Byte|<p>Count, delta or reference at 1st Tx,</p><p>and 2nd Rx</p>|
|X+3|Count/Delta/Reference Value[0][1] - High Byte||
|X+4|Count/Delta/Reference Value[0][2] - Low Byte|<p>Count, delta or reference at 1st Tx,</p><p>and 3rd Rx</p>|
|X+5|Count/Delta/Reference Value[0][2] - High Byte||
|X+6|Count/Delta/Reference Value[0][3] - Low Byte|<p>Count, delta or reference at 1st Tx,</p><p>and 4th Rx</p>|
|X+7|Count/Delta/Reference Value[0][3] - High Byte||
|*Step to next Row/Tx*|||

*Continued on next page...![ref2]*

|X+8|Count/Delta/Reference Value[1][0] - Low Byte|<p>Count, delta or reference at 2nd Tx,</p><p>and 1st Rx</p>|
| - | - | - |
|X+9|Count/Delta/Reference Value[1][0] - High Byte||
|X+10|Count/Delta/Reference Value[1][1] - Low Byte|<p>Count, delta or reference at 2nd Tx,</p><p>and 2nd Rx</p>|
|X+11|Count/Delta/Reference Value[1][1] - High Byte||
|X+12|Count/Delta/Reference Value[1][2] - Low Byte|<p>Count, delta or reference at 2nd Tx,</p><p>and 3rd Rx</p>|
|X+13|Count/Delta/Reference Value[1][2] - High Byte||
|X+14|Count/Delta/Reference Value[1][3] - Low Byte|Count, delta or reference at 2nd Tx, and 4th Rx (thus bottom right)|
|X+15|Count/Delta/Reference Value[1][3] - High Byte||
<a name="_page87_x56.69_y218.69"></a>**A.28 Individual Channel Status / Config Bit Definitions**

For all status outputs or configuration parameters where one bit relates to one channel, the structure is definedas shown in Table[ A.12 ](#_page87_x56.69_y297.14)below. Each row has a 32-bit value where the status/configof each bit corresponds to the status/config of the corresponding column.

<a name="_page87_x56.69_y297.14"></a>*Table A.12: Status Bytes*



|**Byte Number**|**Data**|**Description**|
| - | - | - |
|X|Status/Config [Row0] - Byte 0||
|X+1|Status/Config [Row0] - Byte 1||
|X+2|Status/Config [Row0] - Byte 2||
|X+3|Status/Config [Row0] - Byte 3||
|X+4|Status/Config [Row1] - Byte 0||
|X+5|Status/Config [Row1] - Byte 1||
|X+6|Status/Config [Row1] - Byte 2||
|X+7|Status/Config [Row1] - Byte 3||
|Ď|Ď||
|X+84|Status/Config [Row21] - Byte 0||
|X+85|Status/Config [Row21] - Byte 1||
|X+86|Status/Config [Row21] - Byte 2||
|X+87|Status/Config [Row21] - Byte 3||


||**Byte 3**|**Byte 2**|||||||||||||||
| :- | - | - | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- |
|**Bit**|**31**|**30**|**29**|**28**|**27**|**26**|**25**|**24**|**23**|**22**|**21**|**20**|**19**|**18**|**17**|**16**|
|RowZ|-|-|-|-|-|-|Col25|Col24|Col23|Col22|Col21|Col20|Col19|Col18|Col17|Col16|



||**Byte 1**|**Byte 0**|||||||||||||||
| :- | - | - | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- |
|**Bit**|**15**|**14**|**13**|**12**|**11**|**10**|**9**|**8**|**7**|**6**|**5**|**4**|**3**|**2**|**1**|**0**|
|RowZ|Col15|Col14|Col13|Col12|Col11|Col10|Col9|Col8|Col7|Col6|Col5|Col4|Col3|Col2|Col1|Col0|

**Note:** If the XY axes are switched, these registers do NOT switch. This means that the bits will always link to Rxs, and the registers will always link to Txs.![ref2]

*Table A.13: Channel Status/Config Bit Definitions![ref2]*



|**Parameter**|**Bit = 0**|**Bit = 1**|
| - | - | - |
|Touch Status|Channel does not have a touch|Channel does have a touch|
|Snap Status|Channel does not have a snap|Channel does have a snap|
|Channel Disable|Trackpad channel enabled|Trackpad channel disabled|
|Snap Enable|Snap feature disabled on channel|S napfeature enabled on channel|

<a name="_page89_x56.69_y84.59"></a>**B Revision History![ref2]**



|**Release**|**Date**|**Comments**|
| - | - | - |
|v1.0|2024/04/23|Initial document released|
|v1.1|2024/10/14|<p>Added all IQS9151 product information</p><p>Minor formatting and grammar changes</p><p>IQ9150 FW updated from v1.0 to v1.2 (Table[ A.1) ](#_page69_x56.69_y130.67)Updated IQS9150 ordering codes (Section[ 13.1)](#_page60_x56.69_y101.97)</p>|

Copyright ' Azoteq 2024 IQS9150/IQS9151 Datasheet Page 95 of 97 All Rights Reserved Revision v1.1 October 2024
**IQ Switchfi ![ref1]ProxSensefi Series**

**Contact Information**

**USA China Taiwan South Africa![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.071.png)**

**Physical** 11940 Jollyville Room 501A, Block A Xintai 5th Road, Sec. 1 1 Bergsig Avenue **Address** Suite 120-S T-Share International Centre No. 99, 9F-12C Paarl

Austin Taoyuan Road, Nanshan District Xizhi District 7646

TX 78759 Shenzhen, Guangdong, PRC 221001 New Taipei City South Africa

USA Taiwan

**Postal** 11940 Jollyville Room 501A, Block A Xintai 5th Road, Sec. 1 PO Box 3534 **Address** Suite 120-S T-Share International Centre No. 99, 9F-12C Paarl

Austin Taoyuan Road, Nanshan District Xizhi District 7620 TX 78759 Shenzhen, Guangdong, PRC 221001 New Taipei City South Africa USA Taiwan

**Tel** +1 512 538 1995 +86 755 8303 5294 +886 932 219 444 +27 21 863 0033

ext 808

**Email** <info@azoteq.com> <info@azoteq.com> <info@azoteq.com> <info@azoteq.com>

*Visit[` `*www.azoteq.com*](https://www.azoteq.com)*

*for a list of distributors and worldwide representation.*

Patents as listed on[ www.azoteq.com/patents-trademarks/ ](https://www.azoteq.com/patents-trademarks/)may relate to the device or usage of the device.![](Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.072.png)

Azoteqfi, Crystal Driverfi, IQ Switchfi, ProxSensefi, ProxFusionfi, LightSense™, SwipeSwitch™, Dycal™, TriggerMax™, WearMax™, and the logo are trademarks of Azoteq.

The information in this Datasheet is believed to be accurate at the time of publication. Azoteq uses reasonable effort to maintain the information up-to-date and accurate, but does not warrant the accuracy, completeness or reliability of the information contained herein. All content and information are provided on an “as is” basis only, without any representations or warranties, express or implied, of any kind, including representations about the suitability of these products or information for any purpose. Azoteq disclaims all warranties and conditions with regard to these products and information, including but not limited to all implied warranties and conditions of merchantability, fitness for a particular purpose, title and non-infringement of any third party intellectual property rights. Azoteq assumes no liability for any damages or injury arising from any use of the information or the product or caused by, without limitation, failure of performance, error, omission, interruption, defect, delay in operation or transmission, even if Azoteq has been advised of the possibility of such damages. The applications mentioned herein are used solely for the purpose of illustration and Azoteq makes no warranty or representation that such applications will be suitable without further modification, nor recommends the use of its products for application that may present a risk to human life due to malfunction or otherwise. Azoteq products are not authorized for use as critical components in life support devices or systems. No licenses to patents are granted, implicitly, express or implied, by estoppel or otherwise, under any intellectual property rights. In the event that any of the abovementioned limitations or exclusions does not apply, it is agreed that Azoteq’s total liability for all losses, damages and causes of action (in contract, tort (including without limitation, negligence) or otherwise) will not exceed the amount already paid by the customer for the products. Azoteq reserves the right to alter its products, to make corrections, deletions, modifications, enhancements, improvements and other changes to the content and information, its products, programs and services at any time or to move or discontinue any contents, products, programs or services without prior notification.For the most up-to-date information and binding Terms and Conditions please refer to[ www.azoteq.com.](www.azoteq.com)

info@azoteq.com

[ref1]: Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.001.png
[ref2]: Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.005.png
[ref3]: Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.041.jpeg
[ref4]: Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.044.jpeg
[ref5]: Aspose.Words.441b1bda-cb00-4fcb-9a5e-746262f6175b.045.jpeg
