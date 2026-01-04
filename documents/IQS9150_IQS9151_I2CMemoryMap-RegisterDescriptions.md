# IQS9150/IQS9151 Datasheet – Markdown conversion (Pages 66–89)

Source: IQS9150_IQS9151_datasheet.pdf (pages 66–89).

Notes:
- This is an automated conversion focused on preserving wording and tables.
- Some figures/diagrams may not be captured if they are embedded as images.



---

## Page 66

IQSwitch®
ProxSense® Series
## 15 I2C Memory Map - Register Descriptions
For a more detailed description please see Appendix A.
Table15.1:
Address Length Description Notes
ReadOnly VersionInformation
0x1000–
### 20 ProductInformation AppendixA.1
0x1013
ReadOnly DeviceData
0x1014 2 RelativeX
Section7.2.2
0x1016 2 RelativeY
0x1018 2 GestureX
Section8.1and8.3
0x101A 2 GestureY
0x101C 2 SingleFingerGestures AppendixA.2
0x101E 2 Two-FingerGestures AppendixA.3
0x1020 2 InfoFlags AppendixA.4
0x1022 2 TrackpadFlags AppendixA.5
0x1024 2 Finger1X-Coordinate
Section7.2.3
0x1026 2 Finger1Y-Coordinate
0x1028 2 Finger1TouchStrength Section7.2.4
0x102A 2 Finger1Area Section7.2.5
Ď 40 Ď Ď
0x1054 2 Finger7X-Coordinate
Section7.2.3
0x1056 2 Finger7Y-Coordinate
0x1058 2 Finger7TouchStrength Section7.2.4
0x105A 2 Finger7Area Section7.2.5
ReadOnly ChannelData
0x105C 88 TouchStatus AppendixA.28
0x10B4 2 ALPChannelCount Section5.4.2
0x10B6 2 ALPChannelLTA Section5.5.2
0x10B8 26 ALPIndividualCounts AppendixA.6
0x10D2 88 SnapStatus AppendixA.28
0x112A 2 ButtonOutput AppendixA.7
0x112C 32 SliderOutput AppendixA.8
0x114C 16 WheelOutput AppendixA.9
Read-Write TrackpadConfiguration
0x115C 26 ALPATICompensation AppendixA.10
0x1176 1 I2CUpdateKey
Section12.2
0x1177 1 I2CSlaveAddress
0x1178 1 SettingsMinorVersion
Section11.1
0x1179 1 SettingsMajorVersion
0x117A 2 TrackpadATIMultiplier/Dividers(Global)
AppendixA.11
0x117C 26 ALPATIMultiplier/Dividers
0x1196 2 TrackpadATITarget Section5.7.1
0x1198 2 ALPATITarget
Section5.7.2
0x119A 2 ALPATIBaseTarget
Continuedonnextpage
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page66of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Address | Length | Description | Notes |
| --- | --- | --- | --- |
| ReadOnly |  | VersionInformation |  |
| 0x1000– 0x1013 | 20 | ProductInformation | AppendixA.1 |
| ReadOnly |  | DeviceData |  |
| 0x1014 | 2 | RelativeX | Section7.2.2 |
| 0x1016 | 2 | RelativeY |  |
| 0x1018 | 2 | GestureX | Section8.1and8.3 |
| 0x101A | 2 | GestureY |  |
| 0x101C | 2 | SingleFingerGestures | AppendixA.2 |
| 0x101E | 2 | Two-FingerGestures | AppendixA.3 |
| 0x1020 | 2 | InfoFlags | AppendixA.4 |
| 0x1022 | 2 | TrackpadFlags | AppendixA.5 |
| 0x1024 | 2 | Finger1X-Coordinate | Section7.2.3 |
| 0x1026 | 2 | Finger1Y-Coordinate |  |
| 0x1028 | 2 | Finger1TouchStrength | Section7.2.4 |
| 0x102A | 2 | Finger1Area | Section7.2.5 |
| Ď | 40 | Ď | Ď |
| 0x1054 | 2 | Finger7X-Coordinate | Section7.2.3 |
| 0x1056 | 2 | Finger7Y-Coordinate |  |
| 0x1058 | 2 | Finger7TouchStrength | Section7.2.4 |
| 0x105A | 2 | Finger7Area | Section7.2.5 |
| ReadOnly |  | ChannelData |  |
| 0x105C | 88 | TouchStatus | AppendixA.28 |
| 0x10B4 | 2 | ALPChannelCount | Section5.4.2 |
| 0x10B6 | 2 | ALPChannelLTA | Section5.5.2 |
| 0x10B8 | 26 | ALPIndividualCounts | AppendixA.6 |
| 0x10D2 | 88 | SnapStatus | AppendixA.28 |
| 0x112A | 2 | ButtonOutput | AppendixA.7 |
| 0x112C | 32 | SliderOutput | AppendixA.8 |
| 0x114C | 16 | WheelOutput | AppendixA.9 |
| Read-Write |  | TrackpadConfiguration |  |
| 0x115C | 26 | ALPATICompensation | AppendixA.10 |
| 0x1176 | 1 | I2CUpdateKey | Section12.2 |
| 0x1177 | 1 | I2CSlaveAddress |  |
| 0x1178 | 1 | SettingsMinorVersion | Section11.1 |
| 0x1179 | 1 | SettingsMajorVersion |  |
| 0x117A | 2 | TrackpadATIMultiplier/Dividers(Global) | AppendixA.11 |
| 0x117C | 26 | ALPATIMultiplier/Dividers |  |
| 0x1196 | 2 | TrackpadATITarget | Section5.7.1 |
| 0x1198 | 2 | ALPATITarget | Section5.7.2 |
| 0x119A | 2 | ALPATIBaseTarget |  |



---

## Page 67

IQSwitch®
ProxSense® Series
Table15.1: (Continued)
0x119C 2 TrackpadNegativeDeltaRe-ATIValue
0x119E 2 TrackpadPositiveDeltaRe-ATIValue
Section5.8
0x11A0 1 TrackpadReferenceDriftLimit
0x11A1 1 ALPLTADriftLimit
Read-Write DeviceConfiguration
0x11A2 2 ActiveModeSamplingPeriod(ms)
0x11A4 2 Idle-TouchModeSamplingPeriod(ms)
0x11A6 2 IdleModeSamplingPeriod(ms) Section6.1
0x11A8 2 LP1ModeSamplingPeriod(ms)
0x11AA 2 LP2ModeSamplingPeriod(ms)
0x11AC 2 StationaryTouchTimeout(s)
0x11AE 2 Idle-TouchModeTimeout(s)
0x11B0 2 IdleModeTimeout(s) Section6.2
0x11B2 2 LP1ModeTimeout(s)
0x11B4 2 ActivetoIdleModeTimeout(ms)
0x11B6 1 Re-ATIRetryTime(s) Section5.8.3
0x11B7 1 ReferenceUpdateTime(s) Section5.5.1
0x11B8 2 I2CTimeout(ms) Section12.6
0x11BA 1 SnapTimeout Section5.6.2
0x11BB 1 Reserved(0x00) -
0x11BC 2 SystemControl AppendixA.12
0x11BE 2 ConfigSettings AppendixA.13
0x11C0 2 OtherSettings AppendixA.14
0x11C2 4 ALPSetup AppendixA.15
0x11C6 6 ALPTxEnable AppendixA.16
0x11CC 1 TouchSetThresholdMultiplier
Section5.6.1
0x11CD 1 TouchClearThresholdMultiplier
0x11CE 1 ALPOutputThreshold(Delta)
Section5.6.3
0x11CF 1 ALPAuto-ProxThreshold(Delta)
0x11D0 1 ALPSetDebounce
Section5.6.4
0x11D1 1 ALPClearDebounce
0x11D2 1 SnapSetThreshold(Delta)
Section5.6.2
0x11D3 1 SnapClearThreshold(Delta)
0x11D4 1 ALPCountFilterBeta-LP1Mode
0x11D5 1 ALPLTAFilterBeta-LP1Mode Section5.4.2and
0x11D6 1 ALPCountFilterBeta-LP2Mode 5.5.2
0x11D7 1 ALPLTAFilterBeta-LP2Mode
0x11D8 3 TrackpadConversionFrequency
AppendixA.17
0x11DB 3 ALPConversionFrequency
0x11DE 2 TrackpadHardwareSettings
AppendixA.18
0x11E0 2 ALPHardwareSettings
Read-Write TrackpadConfiguration
0x11E2 1 TrackpadSettings AppendixA.19
0x11E3 1 TotalRxs
Section7.1.1
0x11E4 1 TotalTxs
0x11E5 1 MaxMulti-Touches Section7.3
Continuedonnextpage
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page67of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| 0x119C | 2 | TrackpadNegativeDeltaRe-ATIValue | Section5.8 |
| --- | --- | --- | --- |
| 0x119E | 2 | TrackpadPositiveDeltaRe-ATIValue |  |
| 0x11A0 | 1 | TrackpadReferenceDriftLimit |  |
| 0x11A1 | 1 | ALPLTADriftLimit |  |
| Read-Write |  | DeviceConfiguration |  |
| 0x11A2 | 2 | ActiveModeSamplingPeriod(ms) | Section6.1 |
| 0x11A4 | 2 | Idle-TouchModeSamplingPeriod(ms) |  |
| 0x11A6 | 2 | IdleModeSamplingPeriod(ms) |  |
| 0x11A8 | 2 | LP1ModeSamplingPeriod(ms) |  |
| 0x11AA | 2 | LP2ModeSamplingPeriod(ms) |  |
| 0x11AC | 2 | StationaryTouchTimeout(s) | Section6.2 |
| 0x11AE | 2 | Idle-TouchModeTimeout(s) |  |
| 0x11B0 | 2 | IdleModeTimeout(s) |  |
| 0x11B2 | 2 | LP1ModeTimeout(s) |  |
| 0x11B4 | 2 | ActivetoIdleModeTimeout(ms) |  |
| 0x11B6 | 1 | Re-ATIRetryTime(s) | Section5.8.3 |
| 0x11B7 | 1 | ReferenceUpdateTime(s) | Section5.5.1 |
| 0x11B8 | 2 | I2CTimeout(ms) | Section12.6 |
| 0x11BA | 1 | SnapTimeout | Section5.6.2 |
| 0x11BB | 1 | Reserved(0x00) | - |
| 0x11BC | 2 | SystemControl | AppendixA.12 |
| 0x11BE | 2 | ConfigSettings | AppendixA.13 |
| 0x11C0 | 2 | OtherSettings | AppendixA.14 |
| 0x11C2 | 4 | ALPSetup | AppendixA.15 |
| 0x11C6 | 6 | ALPTxEnable | AppendixA.16 |
| 0x11CC | 1 | TouchSetThresholdMultiplier | Section5.6.1 |
| 0x11CD | 1 | TouchClearThresholdMultiplier |  |
| 0x11CE | 1 | ALPOutputThreshold(Delta) | Section5.6.3 |
| 0x11CF | 1 | ALPAuto-ProxThreshold(Delta) |  |
| 0x11D0 | 1 | ALPSetDebounce | Section5.6.4 |
| 0x11D1 | 1 | ALPClearDebounce |  |
| 0x11D2 | 1 | SnapSetThreshold(Delta) | Section5.6.2 |
| 0x11D3 | 1 | SnapClearThreshold(Delta) |  |
| 0x11D4 | 1 | ALPCountFilterBeta-LP1Mode | Section5.4.2and 5.5.2 |
| 0x11D5 | 1 | ALPLTAFilterBeta-LP1Mode |  |
| 0x11D6 | 1 | ALPCountFilterBeta-LP2Mode |  |
| 0x11D7 | 1 | ALPLTAFilterBeta-LP2Mode |  |
| 0x11D8 | 3 | TrackpadConversionFrequency | AppendixA.17 |
| 0x11DB | 3 | ALPConversionFrequency |  |
| 0x11DE | 2 | TrackpadHardwareSettings | AppendixA.18 |
| 0x11E0 | 2 | ALPHardwareSettings |  |
| Read-Write |  | TrackpadConfiguration |  |
| 0x11E2 | 1 | TrackpadSettings | AppendixA.19 |
| 0x11E3 | 1 | TotalRxs | Section7.1.1 |
| 0x11E4 | 1 | TotalTxs |  |
| 0x11E5 | 1 | MaxMulti-Touches | Section7.3 |



---

## Page 68

IQSwitch®
ProxSense® Series
Table15.1: (Continued)
0x11E6 2 XResolution
Section7.4
0x11E8 2 YResolution
0x11EA 2 XYDynamicFilterBottomSpeed
0x11EC 2 XYDynamicFilterTopSpeed
Section7.8
0x11EE 1 XYDynamicFilterBottomBeta
0x11EF 1 XYStaticFilterBeta
0x11F0 1 StationaryTouchMovementThreshold Section7.5
0x11F1 1 FingerSplitFactor Section7.6
0x11F2 1 XTrimValue
Section7.9
0x11F3 1 YTrimValue
0x11F4 1 JitterFilterDeltaThreshold Section7.8.2
0x11F5 1 FingerConfidenceThreshold Section7.10
Read-Write GestureConfiguration
0x11F6 2 SingleFingerGestureEnable AppendixA.20and
0x11F8 2 Two-FingerGestureEnable A.21
0x11FA 2 TapTime(ms)
0x11FC 2 AirTime(ms) Section8.1
0x11FE 2 TapDistance(pixels)
0x1200 2 HoldTime(ms) Section8.2
0x1202 2 SwipeTime(ms)
0x1204 2 SwipeInitialX-Distance(pixels)
0x1206 2 SwipeInitialY-Distance(pixels)
Section8.3
0x1208 2 SwipeConsecutiveX-Distance(pixels)
0x120A 2 SwipeConsecutiveY-Distance(pixels)
0x120C 1 SwipeAngle(64tan(deg))
0x120D 1 ScrollAngle(64tan(deg)) Section8.6
0x120E 2 ZoomInitialDistance
Section8.7
0x1210 2 ZoomConsecutiveDistance
0x1212 2 ScrollInitialDistance
Section8.6
0x1214 2 ScrollConsecutiveDistance
0x1216 2 PalmGestureThreshold Section8.4
Read-Write TrackpadElectrode&ChannelConfiguration
0x1218 46 RxTxMapping AppendixA.22
0x1246 88 TrackpadChannelDisable
AppendixA.28
0x129E 88 TrackpadSnapChannelEnable
0x12F6 506 IndividualTouchThresholdAdjustments AppendixA.23
Read-Write VirtualSensorConfiguration
0x14F0 2 NumberOfVirtualSensorsEnabled AppendixA.24
Read-Write VirtualButtonConfiguration
0x14F2 2 Button0Top-LeftX
0x14F4 2 Button0Top-LeftY
Section9.3
0x14F6 2 Button0Bottom-RightX
0x14F8 2 Button0Bottom-RightY
Ď 112 Ď Ď
Continuedonnextpage
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page68of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| 0x11E6 | 2 | XResolution | Section7.4 |
| --- | --- | --- | --- |
| 0x11E8 | 2 | YResolution |  |
| 0x11EA | 2 | XYDynamicFilterBottomSpeed | Section7.8 |
| 0x11EC | 2 | XYDynamicFilterTopSpeed |  |
| 0x11EE | 1 | XYDynamicFilterBottomBeta |  |
| 0x11EF | 1 | XYStaticFilterBeta |  |
| 0x11F0 | 1 | StationaryTouchMovementThreshold | Section7.5 |
| 0x11F1 | 1 | FingerSplitFactor | Section7.6 |
| 0x11F2 | 1 | XTrimValue | Section7.9 |
| 0x11F3 | 1 | YTrimValue |  |
| 0x11F4 | 1 | JitterFilterDeltaThreshold | Section7.8.2 |
| 0x11F5 | 1 | FingerConfidenceThreshold | Section7.10 |
| Read-Write |  | GestureConfiguration |  |
| 0x11F6 | 2 | SingleFingerGestureEnable | AppendixA.20and A.21 |
| 0x11F8 | 2 | Two-FingerGestureEnable |  |
| 0x11FA | 2 | TapTime(ms) | Section8.1 |
| 0x11FC | 2 | AirTime(ms) |  |
| 0x11FE | 2 | TapDistance(pixels) |  |
| 0x1200 | 2 | HoldTime(ms) | Section8.2 |
| 0x1202 | 2 | SwipeTime(ms) | Section8.3 |
| 0x1204 | 2 | SwipeInitialX-Distance(pixels) |  |
| 0x1206 | 2 | SwipeInitialY-Distance(pixels) |  |
| 0x1208 | 2 | SwipeConsecutiveX-Distance(pixels) |  |
| 0x120A | 2 | SwipeConsecutiveY-Distance(pixels) |  |
| 0x120C | 1 | SwipeAngle(64tan(deg)) |  |
| 0x120D | 1 | ScrollAngle(64tan(deg)) | Section8.6 |
| 0x120E | 2 | ZoomInitialDistance | Section8.7 |
| 0x1210 | 2 | ZoomConsecutiveDistance |  |
| 0x1212 | 2 | ScrollInitialDistance | Section8.6 |
| 0x1214 | 2 | ScrollConsecutiveDistance |  |
| 0x1216 | 2 | PalmGestureThreshold | Section8.4 |
| Read-Write |  | TrackpadElectrode&ChannelConfiguration |  |
| 0x1218 | 46 | RxTxMapping | AppendixA.22 |
| 0x1246 | 88 | TrackpadChannelDisable | AppendixA.28 |
| 0x129E | 88 | TrackpadSnapChannelEnable |  |
| 0x12F6 | 506 | IndividualTouchThresholdAdjustments | AppendixA.23 |
| Read-Write |  | VirtualSensorConfiguration |  |
| 0x14F0 | 2 | NumberOfVirtualSensorsEnabled | AppendixA.24 |
| Read-Write |  | VirtualButtonConfiguration |  |
| 0x14F2 | 2 | Button0Top-LeftX | Section9.3 |
| 0x14F4 | 2 | Button0Top-LeftY |  |
| 0x14F6 | 2 | Button0Bottom-RightX |  |
| 0x14F8 | 2 | Button0Bottom-RightY |  |
| Ď | 112 | Ď | Ď |



---

## Page 69

IQSwitch®
ProxSense® Series
Table15.1: (Continued)
0x156A 2 Button15Top-LeftX
0x156C 2 Button15Top-LeftY
Section9.3
0x156E 2 Button15Bottom-RightX
0x1570 2 Button15Bottom-RightY
Read-Write VirtualSliderConfiguration
0x1572 2 SliderDeadzone Section9.4.1
0x1574 2 Slider0Top-LeftX
0x1576 2 Slider0Top-LeftY
0x1578 2 Slider0Bottom-RightX Section9.4
0x157A 2 Slider0Bottom-RightY
0x157C 2 Slider0Resolution
Ď 60 Ď Ď
0x15BA 2 Slider7Top-LeftX
0x15BC 2 Slider7Top-LeftY
0x15BE 2 Slider7Bottom-RightX Section9.4
0x15C0 2 Slider7Bottom-RightY
0x15C2 2 Slider7Resolution
Read-Write VirtualWheelConfiguration
0x15C4 2 Wheel0CentreX
0x15C6 2 Wheel0CentreY
0x15C8 2 Wheel0InnerRadius Section9.5
0x15CA 2 Wheel0OuterRadius
0x15CC 2 Wheel0Resolution
Ď 20 Ď Ď
0x15E2 2 Wheel3CentreX
0x15E4 2 Wheel3CentreY
0x15E6 2 Wheel3InnerRadius Section9.5
0x15E8 2 Wheel3OuterRadius
0x15EA 2 Wheel3Resolution
Read-Write EngineeringConfiguration
0x2000 2 EngineeringConfiguration AppendixA.25
0x2002 1 MainOscillatorStepUp
0x2003 1 MainOscillatorStepDown -
0x2004 2 MainOscillatorStepThreshold
ReadOnly TrackpadChannelInformation
0xA000 1012 TrackpadCountValues
0xB000 1012 TrackpadReferenceValues AppendixA.27
0xC000 1012 TrackpadDeltaValues
0xD000 1012 TrackpadATICompensationValues AppendixA.26
0xE000 6 UniqueIdentifier -
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page69of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| 0x156A | 2 | Button15Top-LeftX | Section9.3 |
| --- | --- | --- | --- |
| 0x156C | 2 | Button15Top-LeftY |  |
| 0x156E | 2 | Button15Bottom-RightX |  |
| 0x1570 | 2 | Button15Bottom-RightY |  |
| Read-Write |  | VirtualSliderConfiguration |  |
| 0x1572 | 2 | SliderDeadzone | Section9.4.1 |
| 0x1574 | 2 | Slider0Top-LeftX | Section9.4 |
| 0x1576 | 2 | Slider0Top-LeftY |  |
| 0x1578 | 2 | Slider0Bottom-RightX |  |
| 0x157A | 2 | Slider0Bottom-RightY |  |
| 0x157C | 2 | Slider0Resolution |  |
| Ď | 60 | Ď | Ď |
| 0x15BA | 2 | Slider7Top-LeftX | Section9.4 |
| 0x15BC | 2 | Slider7Top-LeftY |  |
| 0x15BE | 2 | Slider7Bottom-RightX |  |
| 0x15C0 | 2 | Slider7Bottom-RightY |  |
| 0x15C2 | 2 | Slider7Resolution |  |
| Read-Write |  | VirtualWheelConfiguration |  |
| 0x15C4 | 2 | Wheel0CentreX | Section9.5 |
| 0x15C6 | 2 | Wheel0CentreY |  |
| 0x15C8 | 2 | Wheel0InnerRadius |  |
| 0x15CA | 2 | Wheel0OuterRadius |  |
| 0x15CC | 2 | Wheel0Resolution |  |
| Ď | 20 | Ď | Ď |
| 0x15E2 | 2 | Wheel3CentreX | Section9.5 |
| 0x15E4 | 2 | Wheel3CentreY |  |
| 0x15E6 | 2 | Wheel3InnerRadius |  |
| 0x15E8 | 2 | Wheel3OuterRadius |  |
| 0x15EA | 2 | Wheel3Resolution |  |
| Read-Write |  | EngineeringConfiguration |  |
| 0x2000 | 2 | EngineeringConfiguration | AppendixA.25 |
| 0x2002 | 1 | MainOscillatorStepUp | - |
| 0x2003 | 1 | MainOscillatorStepDown |  |
| 0x2004 | 2 | MainOscillatorStepThreshold |  |
| ReadOnly |  | TrackpadChannelInformation |  |
| 0xA000 | 1012 | TrackpadCountValues | AppendixA.27 |
| 0xB000 | 1012 | TrackpadReferenceValues |  |
| 0xC000 | 1012 | TrackpadDeltaValues |  |
| 0xD000 | 1012 | TrackpadATICompensationValues | AppendixA.26 |
| 0xE000 | 6 | UniqueIdentifier | - |



---

## Page 70

IQSwitch®
ProxSense® Series
A Memory Map Descriptions
### A.1 Product Information
TableA.1:IQS9150/IQS9151ProductInfo
Address Length Description IQS9150 IQS9151
0x1000 2 Product Number 0x076A 0x09BC
0x1002 2 Product Major Version 0x0001 0x0001
0x1004 2 Product Minor Version 0x0002 0x0000
0x1006 4 Product SHA -
0x100A 2 Library Number 0x037D
0x100C 2 Library Major Version 0x0001
0x100E 2 Library Minor Version 0x0000
0x1010 4 Library SHA -
### A.2 Single Finger Gestures (0x101C)
Bit 15 14 13 12 11 10 9 8
Swipeand Swipeand Swipeand Swipeand
Description SwipeY- SwipeY+ SwipeX- SwipeX+
HoldY- HoldY+ HoldX- HoldX+
Bit 7 6 5 4 3 2 1 0
Palm Press-and-
Description Reserved TripleTap DoubleTap SingleTap
Gesture Hold
> Bit 15: Swipe and Hold Y- - Swipe and hold in negative Y direction
• 0:Nogesture
• 1:SwipeandholdinnegativeYdirectionoccurred
> Bit 14: Swipe and Hold Y+ - Swipe and hold in positive Y direction
• 0:Nogesture
• 1:SwipeandholdinpositiveYdirectionoccurred
> Bit 13: Swipe and Hold X- - Swipe and hold in negative X direction
• 0:Nogesture
• 1:SwipeandholdinnegativeXdirectionoccurred
> Bit 12: Swipe and Hold X+ - Swipe and hold in positive X direction
• 0:Nogesture
• 1:SwipeandholdinpositiveXdirectionoccurred
> Bit 11: Swipe Y- - Swipe in negative Y direction
• 0:Nogesture
• 1:SwipeinnegativeYdirectionoccurred
> Bit 10: Swipe Y+ - Swipe in positive Y direction
• 0:Nogesture
• 1:SwipeinpositiveYdirectionoccurred
> Bit 9: Swipe X- - Swipe in negative X direction
• 0:Nogesture
• 1:SwipeinnegativeXdirectionoccurred
> Bit 8: Swipe X+ - Swipe in positive X direction
• 0:Nogesture
• 1:SwipeinpositiveXdirectionoccurred
> Bit 7-5: Unused
> Bit 4: Palm Gesture - Indicates a Palm gesture
• 0:Nogesture
• 1:Palmgestureoccurred
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page70of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Address | Length | Description | IQS9150 | IQS9151 |
| --- | --- | --- | --- | --- |
| 0x1000 | 2 | Product Number | 0x076A | 0x09BC |
| 0x1002 | 2 | Product Major Version | 0x0001 | 0x0001 |
| 0x1004 | 2 | Product Minor Version | 0x0002 | 0x0000 |
| 0x1006 | 4 | Product SHA | - |  |
| 0x100A | 2 | Library Number | 0x037D |  |
| 0x100C | 2 | Library Major Version | 0x0001 |  |
| 0x100E | 2 | Library Minor Version | 0x0000 |  |
| 0x1010 | 4 | Library SHA | - |  |



### Table 2

| Bit | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Swipeand HoldY- | Swipeand HoldY+ | Swipeand HoldX- | Swipeand HoldX+ | SwipeY- | SwipeY+ | SwipeX- | SwipeX+ |



### Table 3

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Reserved |  |  | Palm Gesture | Press-and- Hold | TripleTap | DoubleTap | SingleTap |



---

## Page 71

IQSwitch®
ProxSense® Series
> Bit 3: Press-and-Hold - Indicates a Press-and-Hold gesture
• 0:Nogesture
• 1:Press-and-Holdoccurred
> Bit 2: Triple Tap - Indicates a triple tap gesture
• 0:Nogesture
• 1:Tripletapoccurred
> Bit 1: Double Tap - Indicates a double tap gesture
• 0:Nogesture
• 1:Doubletapoccurred
> Bit 0: Single Tap - Indicates a single tap gesture
• 0:Nogesture
• 1:Singletapoccurred
### A.3 Two Finger Gestures (0x101E)
Bit 15 14 13 12 11 10 9 8
Description Reserved
Bit 7 6 5 4 3 2 1 0
Horizontal Vertical Press-and-
Description ZoomOut ZoomIn TripleTap DoubleTap SingleTap
Scroll Scroll Hold
> Bit 15-8: Unused
> Bit 7: Horizontal Scroll - Indicates a horizontal scroll gesture
• 0:Nogesture
• 1:Horizontalscrollgestureoccurred
> Bit 6: Vertical Scroll - Indicates a vertical scroll gesture
• 0:Nogesture
• 1:Verticalscrollgestureoccurred
> Bit 5: Zoom Out - Indicates a zoom out gesture
• 0:Nogesture
• 1:Zoomoutgestureoccurred
> Bit 4: Zoom In - Indicates a zoom in gesture
• 0:Nogesture
• 1:Zoomingestureoccurred
> Bit 3: Press-and-Hold - Indicates a Press-and-Hold gesture
• 0:Nogesture
• 1:Press-and-Holdoccurred
> Bit 2: Triple Tap - Indicates a triple tap gesture
• 0:Nogesture
• 1:Tripletapoccurred
> Bit 1: Double Tap - Indicates a double tap gesture
• 0:Nogesture
• 1:Doubletapoccurred
> Bit 0: Single Tap - Indicates a single tap gesture
• 0:Nogesture
• 1:Singletapoccurred
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page71of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Bit | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Reserved |  |  |  |  |  |  |  |



### Table 2

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Horizontal Scroll | Vertical Scroll | ZoomOut | ZoomIn | Press-and- Hold | TripleTap | DoubleTap | SingleTap |



---

## Page 72

IQSwitch®
ProxSense® Series
### A.4 Info Flags (0x1020)
Bit 15 14 13 12 11 10 9 8
Snap Switch TPTouch ALPProx Global Switch GlobalTP ALPProx
Description
Toggled Toggled Toggled Toggled Snap Pressed Touch Status
Bit 7 6 5 4 3 2 1 0
ALPRe-ATI ALPATI Re-ATI
Description ShowReset ATIError ChargingMode
Occurred Error Occurred
> Bit 15: Snap Toggled - Snap detection status of a snap channel toggled
• 0:Snapoutputdidnottoggle
• 1:Snapoutputtoggled
> Bit 14: Switch Toggled - Switch detection status toggled
• 0:Switchinputdidnottoggle
• 1:Switchinputtoggled
> Bit 13: TP Touch Toggled - Touch detection status of a trackpad channel toggled
• 0:Touchstatusdidnottoggle
• 1:Touchstatustoggled
> Bit 12: ALP Prox Toggled - Prox detection status of ALP channel toggled
• 0:ALPProxstatusdidnottoggle
• 1:ALPProxstatustoggled
> Bit 11: Global Snap - Global snap detection status of any snap channel
• 0:Nooutputdetected
• 1:Outputdetected
> Bit 10: Switch Pressed - Switch pressed status
• 0:Noswitchpressdetected
• 1:Switchpressdetected
> Bit 9: Global TP Touch - Touch detection status of any TP channel
• 0:NoTPtouchdetected
• 1:TPtouchdetected
> Bit 8: ALP Prox Status - Prox/Touch detection status of ALP channel
• 0:Nooutputdetected
• 1:Outputdetected
> Bit 7: Show Reset - Indicates a reset
• 0:Resetindicationhasbeenclearedbyhost,writingtoAckReset
• 1:Resethasoccurredandindicationhasnotbeenclearedbyhost
> Bit 6: ALP Re-ATI Occurred - Alternate Low Power channel Re-ATI Status
• 0:Nore-ATI
• 1:Re-ATIhasjustcompletedonalternateLPchannel
> Bit 5: ALP ATI Error - Alternate Low Power ATI error status
• 0:MostrecentATIprocesswassuccessful
• 1:MostrecentATIprocesswasunsuccessful
> Bit 4: Re-ATI Occurred - Trackpad re-ATI status
• 0:Nore-ATI
• 1:Re-ATIhasjustcompletedonthetrackpad
> Bit 3: ATI Error - Error condition seen on latest trackpad ATI procedure
• 0:MostrecentATIprocesswassuccessful
• 1:MostrecentATIprocesswasunsuccessful
> Bit 2-0: Charging Mode - Indicates current mode
• 000:Activemode
• 001:Idle-touchmode
• 010:Idlemode
• 011:LP1mode
• 100:LP2mode
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page72of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Bit | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Snap Toggled | Switch Toggled | TPTouch Toggled | ALPProx Toggled | Global Snap | Switch Pressed | GlobalTP Touch | ALPProx Status |



### Table 2

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | ShowReset | ALPRe-ATI Occurred | ALPATI Error | Re-ATI Occurred | ATIError | ChargingMode |  |  |



---

## Page 73

IQSwitch®
ProxSense® Series
### A.5 Trackpad Flags (0x1022)
Bit 15 14 13 12 11 10 9 8
Finger7 Finger6 Finger5 Finger4 Finger3 Finger2 Finger1
Description Reserved
Confidence Confidence Confidence Confidence Confidence Confidence Confidence
Bit 7 6 5 4 3 2 1 0
MainOsc TooMany Movement
Description Saturation NumberofFingers
Stepped Fingers Detected
> Bit 15: Unused
> Bit 14-8: Finger Confidence - Confidence that the touch detected is a legitimate finger input
• 0:Notconfidentthatthetouchisafingerinput
• 1:Confidentthatthetouchisafingerinput
> Bit 7: Saturation - Saturation detection status
• 0:Nosaturationdetected
• 1:Saturationdetected
> Bit 6: Main Osc Stepped - Frequency adjusted due to detected noise
• 0:Oscillatornotadjusted
• 1:Oscillatoradjusted
> Bit 5: Too Many Fingers - Indicates more than allowed fingers detected
• 0:Numberoffingerswithinmaximumselectedvalue
• 1:Numberoffingersexceedsmaximumselectedvalue
> Bit 4: Movement Detected - Trackpad finger movement detected
• 0:Notouches,oralltouchesstationary(seeSection7.5)
• 1:Movementoffinger(s)detectedontrackpad
> Bit 3-0: Number of Fingers - Number of fingers detected on trackpad
• 0000:Nofingersontrackpad
• 0001:1fingersactive
• 0010:2fingersactive
• 0011:3fingersactive
• 0100:4fingersactive
• 0101:5fingersactive
• 0110:6fingersactive
• 0111:7fingersactive
### A.6 ALP Individual Counts (0x10B8)
Bit
Address
15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
0x10B8 ALPCountsRx0and/orRx13
0x10BA ALPCountsRx1and/orRx14
0x10BC ALPCountsRx2and/orRx15
0x10BE ALPCountsRx3and/orRx16
0x10C0 ALPCountsRx4and/orRx17
0x10C2 ALPCountsRx5and/orRx18
0x10C4 ALPCountsRx6and/orRx19
0x10C6 ALPCountsRx7and/orRx20
0x10C8 ALPCountsRx8and/orRx21
0x10CA ALPCountsRx9and/orRx22
0x10CC ALPCountsRx10and/orRx23
0x10CE ALPCountsRx11and/orRx24
0x10D0 ALPCountsRx12and/orRx25
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page73of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Bit | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Reserved | Finger7 Confidence | Finger6 Confidence | Finger5 Confidence | Finger4 Confidence | Finger3 Confidence | Finger2 Confidence | Finger1 Confidence |



### Table 2

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Saturation | MainOsc Stepped | TooMany Fingers | Movement Detected | NumberofFingers |  |  |  |



### Table 3

| Address | Bit |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
|  | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| 0x10B8 | ALPCountsRx0and/orRx13 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x10BA | ALPCountsRx1and/orRx14 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x10BC | ALPCountsRx2and/orRx15 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x10BE | ALPCountsRx3and/orRx16 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x10C0 | ALPCountsRx4and/orRx17 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x10C2 | ALPCountsRx5and/orRx18 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x10C4 | ALPCountsRx6and/orRx19 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x10C6 | ALPCountsRx7and/orRx20 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x10C8 | ALPCountsRx8and/orRx21 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x10CA | ALPCountsRx9and/orRx22 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x10CC | ALPCountsRx10and/orRx23 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x10CE | ALPCountsRx11and/orRx24 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x10D0 | ALPCountsRx12and/orRx25 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |



---

## Page 74

IQSwitch®
ProxSense® Series
### A.7 Button Output (0x112A)
Bit 15 14 13 12 11 10 9 8
Description Button15 Button14 Button13 Button12 Button11 Button10 Button9 Button8
Bit 7 6 5 4 3 2 1 0
Description Button7 Button6 Button5 Button4 Button3 Button2 Button1 Button0
> Button state for Button 0 - Button 15
• 0:Virtualtouchbuttonnotpressed
• 1:Virtualtouchbuttonpressed
### A.8 Slider Output (0x112C)
Address Length Description
0x112C 2 Slider0outputforFinger1
0x112E 2 Slider0outputforFinger2
0x1130 2 Slider1outputforFinger1
0x1132 2 Slider1outputforFinger2
0x1134 2 Slider2outputforFinger1
0x1136 2 Slider2outputforFinger2
0x1138 2 Slider3outputforFinger1
0x113A 2 Slider3outputforFinger2
0x113C 2 Slider4outputforFinger1
0x113E 2 Slider4outputforFinger2
0x1140 2 Slider5outputforFinger1
0x1142 2 Slider5outputforFinger2
0x1144 2 Slider6outputforFinger1
0x1146 2 Slider6outputforFinger2
0x1148 2 Slider7outputforFinger1
0x114A 2 Slider7outputforFinger2
### A.9 Wheel Output (0x114C)
Address Length Description
0x114C 2 Wheel0outputforFinger1
0x114E 2 Wheel0outputforFinger2
0x1150 2 Wheel1outputforFinger1
0x1152 2 Wheel1outputforFinger2
0x1154 2 Wheel2outputforFinger1
0x1156 2 Wheel2outputforFinger2
0x1158 2 Wheel3outputforFinger1
0x115A 2 Wheel3outputforFinger2
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page74of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Bit | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Button15 | Button14 | Button13 | Button12 | Button11 | Button10 | Button9 | Button8 |



### Table 2

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Button7 | Button6 | Button5 | Button4 | Button3 | Button2 | Button1 | Button0 |



### Table 3

| Address | Length | Description |
| --- | --- | --- |
| 0x112C | 2 | Slider0outputforFinger1 |
| 0x112E | 2 | Slider0outputforFinger2 |
| 0x1130 | 2 | Slider1outputforFinger1 |
| 0x1132 | 2 | Slider1outputforFinger2 |
| 0x1134 | 2 | Slider2outputforFinger1 |
| 0x1136 | 2 | Slider2outputforFinger2 |
| 0x1138 | 2 | Slider3outputforFinger1 |
| 0x113A | 2 | Slider3outputforFinger2 |
| 0x113C | 2 | Slider4outputforFinger1 |
| 0x113E | 2 | Slider4outputforFinger2 |
| 0x1140 | 2 | Slider5outputforFinger1 |
| 0x1142 | 2 | Slider5outputforFinger2 |
| 0x1144 | 2 | Slider6outputforFinger1 |
| 0x1146 | 2 | Slider6outputforFinger2 |
| 0x1148 | 2 | Slider7outputforFinger1 |
| 0x114A | 2 | Slider7outputforFinger2 |



### Table 4

| Address | Length | Description |
| --- | --- | --- |
| 0x114C | 2 | Wheel0outputforFinger1 |
| 0x114E | 2 | Wheel0outputforFinger2 |
| 0x1150 | 2 | Wheel1outputforFinger1 |
| 0x1152 | 2 | Wheel1outputforFinger2 |
| 0x1154 | 2 | Wheel2outputforFinger1 |
| 0x1156 | 2 | Wheel2outputforFinger2 |
| 0x1158 | 2 | Wheel3outputforFinger1 |
| 0x115A | 2 | Wheel3outputforFinger2 |



---

## Page 75

IQSwitch®
ProxSense® Series
### A.10 ALP ATI Compensation (0x115C)
Bit
Address 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
- ALPCompensationDivider ALPCompensation
0x115C Rx0and/orRx13
0x115E Rx1and/orRx14
0x1160 Rx2and/orRx15
0x1162 Rx3and/orRx16
0x1164 Rx4and/orRx17
0x1166 Rx5and/orRx18
0x1168 Rx6and/orRx19
0x116A Rx7and/orRx20
0x116C Rx8and/orRx21
0x116E Rx9and/orRx22
0x1170 Rx10and/orRx23
0x1172 Rx11and/orRx24
0x1174 Rx12and/orRx25
> Bit 15: Unused
> Bit 14-10: ALP Compensation Divider
> Bit 9-0: ALP Compensation
### A.11 Trackpad and ALP Multipliers / Divider (0x117A / 0x117C)
Bit
Address 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
FineMult FineDivider CoarseMultiplier CoarseDivider
0x117A Trackpad
0x117C ALPRx0+Rx13
0x117E ALPRx1+Rx14
0x1180 ALPRx2+Rx15
0x1182 ALPRx3+Rx16
0x1184 ALPRx4+Rx17
0x1186 ALPRx5+Rx18
0x1188 ALPRx6+Rx19
0x118A ALPRx7+Rx20
0x118C ALPRx8+Rx21
0x118E ALPRx9+Rx22
0x1190 ALPRx10+Rx23
0x1192 ALPRx11+Rx24
0x1194 ALPRx12+Rx25
> Bit 15-14: Fine Multiplier
• 2-bitvaluebetween1and2
• Recommendtokeep1
> Bit 13-9: Fine Divider
• 5-bitvaluebetween1and21
• Recommendtokeepabove6
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page75of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Address | Bit |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
|  | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|  | - | ALPCompensationDivider |  |  |  |  | ALPCompensation |  |  |  |  |  |  |  |  |  |
| 0x115C | Rx0and/orRx13 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x115E | Rx1and/orRx14 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x1160 | Rx2and/orRx15 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x1162 | Rx3and/orRx16 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x1164 | Rx4and/orRx17 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x1166 | Rx5and/orRx18 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x1168 | Rx6and/orRx19 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x116A | Rx7and/orRx20 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x116C | Rx8and/orRx21 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x116E | Rx9and/orRx22 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x1170 | Rx10and/orRx23 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x1172 | Rx11and/orRx24 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x1174 | Rx12and/orRx25 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |



### Table 2

| Address | Bit |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
|  | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|  | FineMult |  | FineDivider |  |  |  |  | CoarseMultiplier |  |  |  | CoarseDivider |  |  |  |  |
| 0x117A | Trackpad |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x117C | ALPRx0+Rx13 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x117E | ALPRx1+Rx14 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x1180 | ALPRx2+Rx15 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x1182 | ALPRx3+Rx16 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x1184 | ALPRx4+Rx17 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x1186 | ALPRx5+Rx18 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x1188 | ALPRx6+Rx19 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x118A | ALPRx7+Rx20 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x118C | ALPRx8+Rx21 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x118E | ALPRx9+Rx22 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x1190 | ALPRx10+Rx23 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x1192 | ALPRx11+Rx24 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0x1194 | ALPRx12+Rx25 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |



---

## Page 76

IQSwitch®
ProxSense® Series
> Bit 8-5: Coarse Multiplier
• 4-bitvaluebetween1and15
• UseAzoteqrecommendedsetsasdefinedinGUIsoftware
> Bit 4-0: Coarse Divider
• 5-bitvaluebetween1and31
• UseAzoteqrecommendedsetsasdefinedinGUIsoftware
### A.12 System Control (0x11BC)
Bit 15 14 13 12 11 10 9 8
TxShort
Description Reserved Suspend Reserved SWReset Reserved
Test
Bit 7 6 5 4 3 2 1 0
ALP
Description AckReset ALPRe-ATI TPRe-ATI TPReseed ModeSelect
Reseed
> Bit 15: Tx Short Test - Tx short test
• 0:Normaloperation
• 1:EnableTxshorttestconfiguration
> Bit 14-12: Unused
> Bit 11: Suspend - Suspend IQS9150/IQS9151
• 0:Noaction
• 1:PlaceIQS9150/IQS9151intosuspendafterthecommunicationwindowterminates
> Bit 10: Unused
> Bit 9: SW Reset - Reset the device
• 0:Noaction
• 1:Resetdeviceaftercommunicationwindowterminates
> Bit 8: Unused
> Bit 7: Ack Reset - Acknowledge a reset
• 0:Noaction
• 1:AcknowledgetheresetbyclearingShowReset flag
> Bit 6: ALP Re-ATI - Queue a re-ATI on ALP channel
• 0:Noaction
• 1:Performre-ATIwhenALPchannelissensedagain
> Bit 5: TP Re-ATI - Queue a re-ATI on trackpad channels
• 0:Noaction
• 1:Performre-ATIwhentrackpadchannelsaresensedagain
> Bit 4: ALP Reseed - Queue a reseed on ALP channel
• 0:Noaction
• 1:ReseedtheLTAoftheALPchannelwhenitissensedagain
> Bit 3: TP Reseed - Queue a reseed on trackpad channels
• 0:Noaction
• 1:Reseedreferencevaluesofthetrackpadchannelswhenitissensedagain
> Bit 2-0: Mode Select - Select mode (only applicable in Manual Mode)
• 000:Activemode
• 001:Idle-Touchmode
• 010:Idlemode
• 011:LP1mode
• 100:LP2mode
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page76of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Bit | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | TxShort Test | Reserved |  |  | Suspend | Reserved | SWReset | Reserved |



### Table 2

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | AckReset | ALPRe-ATI | TPRe-ATI | ALP Reseed | TPReseed | ModeSelect |  |  |



---

## Page 77

IQSwitch®
ProxSense® Series
### A.13 Configuration Settings (0x11BE)
Bit 15 14 13 12 11 10 9 8
Switch TPTouch Re-ATI Gesture
SnapEvent ALPEvent TPEvent
Description Event Event Event Event EventMode
Enable Enable Enable
Enable Enable Enable Enable
Bit 7 6 5 4 3 2 1 0
Terminate Sleep Force
Manual ALPRe-ATI TPRe-ATI ALPATI Sleep
Description Comms DuringCon- Comms
Control Enable Enable Mode Option
Window versions Method
> Bit 15: Snap Event Enable - Enable snap triggering event
• 0:Toggleofsnapstatusdoesnottriggeranevent
• 1:Toggleofsnapstatustriggersanevent
> Bit 14: Switch Event Enable - Enable switch triggering event
• 0:Toggleofswitchstatusdoesnottriggeranevent
• 1:Toggleofswitchstatustriggersanevent
> Bit 13: TP Touch Event Enable - Enable trackpad touch triggering event
• 0:Toggleoftrackpadtouchstatusdoesnottriggeranevent
• 1:Toggleoftrackpadtouchstatustriggersanevent
> Bit 12: ALP Event Enable - Enable alternate LP channel detection triggering event
• 0:Toggleofalternatechannelprox/touchstatusdoesnottriggeranevent
• 1:Toggleofalternatechannelprox/touchstatustriggersanevent
> Bit 11: Re-ATI Event Enable - Enable Re-ATI generating an event
• 0:Re-ATIoccurringdoesnottriggeranevent
• 1:Re-ATIoccurringtriggersanevent
> Bit 10: TP Event Enable - Enable trackpad events
• 0:Trackpadfingermovementorfingerup/downwillnottriggerevent
• 1:Trackpadfingermovementorfingerup/downwilltriggerevent
> Bit 9: Gesture Event Enable - Enable gesture events
• 0:Gestureswillnottriggerevent
• 1:Gestureswilltriggerevent
> Bit 8: Event Mode - Enable event mode communication
• 0:I2Cispresentedeachcycle(exceptauto-proxcycles)
• 1:I2Cisonlyinitiatedwhenanenabledeventoccurs
> Bit 7: Manual Control - Override automatic mode switching
• 0:ModesareautomaticallycontrolledbyIQS9150/IQS9151firmware(recommended)
• 1:Manualcontrolofmodesarehandledbyhost
> Bit6:TerminateCommsWindow -Alternativemethodtoterminatecomms(seeSection12.7)
• 0:I2Cstopendscomms
• 1:TerminateCommsWindow command,followedbyanI2CSTOPendcomms
> Bit 5: Sleep During Conversions - Prevent processing during conversions
• 0:Normal(recommended)
• 1:Sleep(increaseslatencyandcurrentconsumption)
> Bit 4: Force Comms Method - Force comms method selection (while RDY not LOW)
• 0:Forcingcommswillclockstretchuntilacommswindow(NormalI2CoutsideRDYwindow)
• 1:Acommswindowmustberequestedwithacommand(nostretching)outsidecommswindow
> Bit 3: ALP Re-ATI Enable - Automatic Re-ATI on alternate LP channel
• 0:Re-ATIisdisabledforalternateLPchannel
• 1:Re-ATIisenabledforalternateLPchannel(recommended)
> Bit 2: TP Re-ATI Enable - Automatic Re-ATI on trackpad
• 0:Re-ATIisdisabledfortrackpadchannels
• 1:Re-ATIisenabledfortrackpadchannels(recommended)
> Bit 1: ALP ATI Mode - ALP ATI mode
• 0:Compensationonly
• 1:FullATI
> Bit 0: Sleep Option - Internal device sleep selection
• 0:Deepsleep(recommended)
• 1:Lightsleep
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page77of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Bit | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | SnapEvent Enable | Switch Event Enable | TPTouch Event Enable | ALPEvent Enable | Re-ATI Event Enable | TPEvent Enable | Gesture Event Enable | EventMode |



### Table 2

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Manual Control | Terminate Comms Window | Sleep DuringCon- versions | Force Comms Method | ALPRe-ATI Enable | TPRe-ATI Enable | ALPATI Mode | Sleep Option |



---

## Page 78

IQSwitch®
ProxSense® Series
### A.14 Other Settings (0x11C0)
Bit 15 14 13 12 11 10 9 8
Switch Switch
Description ProxOscillatorAdjustment Reserved
Enable Polarity
Bit 7 6 5 4 3 2 1 0
LP2 LP1
Description MainOscillatorSelection Auto-Prox Auto-Prox LP2Auto-ProxCycles LP1Auto-ProxCycles
Enable Enable
> Bit 15: Switch Enable - Enable switch input
• 0:Switchdisabled
• 1:Switchenabled
> Bit 14: Switch Polarity - Switch polarity selection
• 0:Active-low
• 1:Active-high
> Bit 13-12: Prox Oscillator Adjustment - Adjust Prox oscillator frequency
• 00:Nominal(16MHz)
• 01:-10%(MainOsc14MHz)/-20%(MainOsc20MHz/24MHz)
• 10:-20%(MainOsc14MHz)/-30%(MainOsc20MHz/24MHz)
• 11:-30%(MainOsc14MHz)/-40%(MainOsc20MHz/24MHz)
> Bit 11-8: Unused
> Bit 7-6: Main Oscillator Selection - Main oscillator frequency selection
• 00:14MHz
• 01:20MHz
• 10:24MHz
> Bit 5: LP2 Auto-Prox Enable - Enable or disable LP2 Auto-Prox
• 0:LP2Auto-Proxdisabled
• 1:LP2Auto-Proxenabled
> Bit 4: LP1 Auto-Prox Enable - Enable or disable LP1 Auto-Prox
• 0:LP1Auto-Proxdisabled
• 1:LP1Auto-Proxenabled
> Bit 3-2: LP2 Auto-Prox Cycles - Number of LP2 auto-prox cycles
• 00:16
• 01:32
• 10:64
• 11:256
> Bit 1-0: LP1 Auto-Prox Cycles - Number of LP1 auto-prox cycles
• 00:16
• 01:32
• 10:64
• 11:256
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page78of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Bit | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Switch Enable | Switch Polarity | ProxOscillatorAdjustment |  | Reserved |  |  |  |



### Table 2

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | MainOscillatorSelection |  | LP2 Auto-Prox Enable | LP1 Auto-Prox Enable | LP2Auto-ProxCycles |  | LP1Auto-ProxCycles |  |



---

## Page 79

IQSwitch®
ProxSense® Series
### A.15 ALP Setup (0x11C2)
Bit 31 30 29 28 27 26 25 24
ALPCount ALP ActiveTx
Rx25 Rx24
Description ALPEnable Filter Sensing Shield Reserved
Enablea Enablea
Enable Method Enable
Bit 23 22 21 20 19 18 17 16
Rx23 Rx22 Rx21 Rx20 Rx19 Rx18 Rx17 Rx16
Description
Enablea Enablea Enablea Enablea Enablea Enablea Enablea Enablea
Bit 15 14 13 12 11 10 9 8
Rx15 Rx14 Rx13 Rx12 Rx11 Rx10
Description Rx9Enable Rx8Enable
Enablea Enablea Enablea Enable Enable Enable
Bit 7 6 5 4 3 2 1 0
Description Rx7Enable Rx6Enable Rx5Enable Rx4Enable Rx3Enable Rx2Enable Rx1Enable Rx0Enable
aNotapplicabletoIQS9151.Keepsetto‘0’.
> Bit 31: ALP Enable - Enable ALP channel
• 0:ALPchannelisdisabled,trackpadchannelsactiveinLP1andLP2
• 1:ALPchannelisenabled,ALPchannelactiveinLP1andLP2
> Bit 30: ALP Count Filter Enable - ALP count filter
• 0:ALPchannelcountisunfiltered
• 1:ALPcountfilterenabled
> Bit 29: ALP Sensing Method - ALP sensing method
• 0:ALPissetupforself-capacitivesensing
• 1:ALPissetupformutual-capacitivesensing
> Bit 28: Active Tx Shield Enable - Configure Tx behaviour for self cap ALP setup
• 0:Allunusedelectrodesaregrounded
• 1:AllALPenabledTxsmimicRxsignaltoreduceparasiticcapacitancetoGND
> Bit 27-26: Unused
> Bit 25-0: Rx Enable - ALP Rx electrodes
• 0:Rxdisabled(notusedforALP)
• 1:Rxenabled(formspartofALPsensor)
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page79of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Bit | 31 | 30 | 29 | 28 | 27 | 26 | 25 | 24 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | ALPEnable | ALPCount Filter Enable | ALP Sensing Method | ActiveTx Shield Enable | Reserved |  | Rx25 Enablea | Rx24 Enablea |
| Bit | 23 | 22 | 21 | 20 | 19 | 18 | 17 | 16 |
| Description | Rx23 Enablea | Rx22 Enablea | Rx21 Enablea | Rx20 Enablea | Rx19 Enablea | Rx18 Enablea | Rx17 Enablea | Rx16 Enablea |
| Bit | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 |
| Description | Rx15 Enablea | Rx14 Enablea | Rx13 Enablea | Rx12 Enable | Rx11 Enable | Rx10 Enable | Rx9Enable | Rx8Enable |
| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| Description | Rx7Enable | Rx6Enable | Rx5Enable | Rx4Enable | Rx3Enable | Rx2Enable | Rx1Enable | Rx0Enable |



---

## Page 80

IQSwitch®
ProxSense® Series
### A.16 ALP Tx Enable (0x11C6)
Bit 47 46 45 44 43 42 41 40
Tx45 Tx43 Tx42 Tx41 Tx40
Description Reserved Reserved
Enable Enable Enable Enable Enable
Bit 39 38 37 36 35 34 33 32
Tx39 Tx38 Tx37 Tx36 Tx35 Tx34 Tx33 Tx32
Description
Enable Enable Enable Enable Enable Enable Enable Enablea
Bit 31 30 29 28 27 26 25 24
Tx31 Tx30 Tx29 Tx28 Tx27 Tx26 Tx25 Tx24
Description
Enablea Enablea Enablea Enablea Enablea Enablea Enablea Enablea
Bit 23 22 21 20 19 18 17 16
Tx23 Tx22 Tx21 Tx20 Tx19 Tx18 Tx17 Tx16
Description
Enablea Enablea Enablea Enablea Enablea Enablea Enablea Enablea
Bit 15 14 13 12 11 10 9 8
Tx15 Tx14 Tx13 Tx12 Tx11 Tx10
Description Tx9Enable Tx8Enable
Enablea Enablea Enablea Enable Enable Enable
Bit 7 6 5 4 3 2 1 0
Description Tx7Enable Tx6Enable Tx5Enable Tx4Enable Tx3Enable Tx2Enable Tx1Enable Tx0Enable
aNotapplicabletoIQS9151.Keepsetto‘0’.
> Bit 47-46: Unused
> Bit 44: Do not use, keep 0
> Bit 45, 43-0: Tx Enable - ALP Tx electrodes selection
• 0:Txdisabled(notusedforALP)
• 1:Txenabled(formspartofALPsensor)
### A.17 Trackpad and ALP Conversion Frequency (0x11D8 and 0x11DB)
Address Length Description
0x11D8 1 TrackpadFractionValue
0x11D9 1 TrackpadPeriod1Value
0x11DA 1 TrackpadPeriod2Value
0x11DB 1 ALPFractionValue
0x11DC 1 ALPPeriod1Value
0x11DD 1 ALPPeriod2Value
> Please refer to Table A.7 below for the values to configure the desired conversion frequency.
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page80of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Bit | 47 | 46 | 45 | 44 | 43 | 42 | 41 | 40 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Reserved |  | Tx45 Enable | Reserved | Tx43 Enable | Tx42 Enable | Tx41 Enable | Tx40 Enable |
| Bit | 39 | 38 | 37 | 36 | 35 | 34 | 33 | 32 |
| Description | Tx39 Enable | Tx38 Enable | Tx37 Enable | Tx36 Enable | Tx35 Enable | Tx34 Enable | Tx33 Enable | Tx32 Enablea |
| Bit | 31 | 30 | 29 | 28 | 27 | 26 | 25 | 24 |
| Description | Tx31 Enablea | Tx30 Enablea | Tx29 Enablea | Tx28 Enablea | Tx27 Enablea | Tx26 Enablea | Tx25 Enablea | Tx24 Enablea |
| Bit | 23 | 22 | 21 | 20 | 19 | 18 | 17 | 16 |
| Description | Tx23 Enablea | Tx22 Enablea | Tx21 Enablea | Tx20 Enablea | Tx19 Enablea | Tx18 Enablea | Tx17 Enablea | Tx16 Enablea |
| Bit | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 |
| Description | Tx15 Enablea | Tx14 Enablea | Tx13 Enablea | Tx12 Enable | Tx11 Enable | Tx10 Enable | Tx9Enable | Tx8Enable |
| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| Description | Tx7Enable | Tx6Enable | Tx5Enable | Tx4Enable | Tx3Enable | Tx2Enable | Tx1Enable | Tx0Enable |



### Table 2

| Address | Length | Description |
| --- | --- | --- |
| 0x11D8 | 1 | TrackpadFractionValue |
| 0x11D9 | 1 | TrackpadPeriod1Value |
| 0x11DA | 1 | TrackpadPeriod2Value |
| 0x11DB | 1 | ALPFractionValue |
| 0x11DC | 1 | ALPPeriod1Value |
| 0x11DD | 1 | ALPPeriod2Value |



---

## Page 81

IQSwitch®
ProxSense® Series
TableA.7:ConversionFrequencySelections
Conversion
Fraction Period1 Period1
Frequency
Value Value Value
(MHz)
0.25 4 31 31
0.50 8 15 15
0.75 12 9 10
1.00 16 7 7
1.25 20 5 5
1.50 24 4 4
1.75 28 3 4
2.00 32 3 3
2.25 36 2 3
2.50 40 2 2
2.75 44 1 2
3.00 48 1 2
3.25 52 1 1
3.50 56 1 1
4.00 64 1 1
### A.18 Trackpad and ALP Hardware Settings (0x11DE and 0x11E0)
Bit 15 14 13 12 11 10 9 8
Description Initial Cycle Delay SH Bias Count Upper Limit
Bit 7 6 5 4 3 2 1 0
Cs Dis-
NM Out NM In
Description charge RF Filters Global SH Offset
Static Static
Voltage
> Bit 15-14: Initial Cycle Delay - Initial cycles delay
• 00:16
• 01:32
• 10:64
• 11:256
> Bit 13-11: SH Bias - Sample-and-hold opamp bias current
• 000:5µA
• 001:10µA
• 010:15µA
• 011:20µA
• 100:15µA
• 101:20µA
• 110:25µA
• 111:30µA
> Bit 10-8: Count Upper Limit - Count upper limit (count value stops conversion after reaching
this)
• 000:383
• 001:511
• 010:767
• 011:1023
• 100:2047
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page81of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Conversion Frequency (MHz) | Fraction Value | Period1 Value | Period1 Value |
| --- | --- | --- | --- |
| 0.25 | 4 | 31 | 31 |
| 0.50 | 8 | 15 | 15 |
| 0.75 | 12 | 9 | 10 |
| 1.00 | 16 | 7 | 7 |
| 1.25 | 20 | 5 | 5 |
| 1.50 | 24 | 4 | 4 |
| 1.75 | 28 | 3 | 4 |
| 2.00 | 32 | 3 | 3 |
| 2.25 | 36 | 2 | 3 |
| 2.50 | 40 | 2 | 2 |
| 2.75 | 44 | 1 | 2 |
| 3.00 | 48 | 1 | 2 |
| 3.25 | 52 | 1 | 1 |
| 3.50 | 56 | 1 | 1 |
| 4.00 | 64 | 1 | 1 |



### Table 2

| Bit | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Initial Cycle Delay |  | SH Bias |  |  | Count Upper Limit |  |  |



### Table 3

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Cs Dis- charge Voltage | RF Filters | NM Out Static | NM In Static | Global SH Offset |  |  |  |



---

## Page 82

IQSwitch®
ProxSense® Series
> Bit 7: Cs Discharge Voltage - Select internal Cs discharge voltage
• 0:Dischargeto0V(recommendedformostcases)
• 1:Dischargeto0.5V
> Bit 6: RF Filter - Internal RF filters
• 0:RFfiltersdisabled
• 1:RFfiltersenabled
> Bit 5: NM Out Static - NM out static
• 0:Disabled(recommended)
• 1:Enabled
> Bit 4: NM In Static - NM in static
• 0:Disabled(recommended)
• 1:Enabled
> Bit 3-0: Global SH Offset - Global SH offset
• 0000:0mV
• 0001:-2mV
• 0010:-4mV
• 0011:-6mV
• 0100:-8mV
• 0101:-10mV
• 0110:-12mV
• 0111:-14mV
• 1001:+2mV
• 1010:+4mV
• 1011:+6mV
• 1100:+8mV
• 1101:+10mV
• 1110:+12mV
• 1111:+14mV
### A.19 Trackpad Settings (0x11E2)
Bit 7 6 5 4 3 2 1 0
AreaFilter SwitchXY
Description Reserved JitterFilter IIRStatic IIRFilter FlipY FlipX
Disable Axis
> Bit 7: Unused
> Bit 6: Area Filter Disable - Disable area filter
• 0:Areafilterontouchpositionenabled
• 1:Areafilterontouchpositiondisabled
> Bit 5: Jitter Filter - Enable jitter filter
• 0:XYjitterfilterontouchpositiondisabled
• 1:XYjitterfilterontouchpositionenabled
> Bit 4: IIR Static - IIR filtering method for the XY data points
• 0:DampingfactorforIIRfilterisdynamicallyadjustedrelativetoXYmovement(recommended)
• 1:DampingfactorforIIRfilterisfixed
> Bit 3: IIR Filter - IIR filter
• 0:XYIIRfilterdisabled
• 1:XYIIRfilterenabled(recommended)
> Bit 2: Switch XY Axis - Switch X and Y axes
• 0:Rxsarearrangedintrackpadcolumns(X),andTxsinrows(Y)
• 1:Txsarearrangedintrackpadcolumns(X),andRxsinrows(Y)
> Bit 1: Flip Y - Flip Y output values
• 0:KeepdefaultYvalues
• 1:InvertYoutputvalues
> Bit 0: Flip X - Flip X output values
• 0:KeepdefaultXvalues
• 1:InvertXoutputvalues
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page82of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Reserved | AreaFilter Disable | JitterFilter | IIRStatic | IIRFilter | SwitchXY Axis | FlipY | FlipX |



---

## Page 83

IQSwitch®
ProxSense® Series
### A.20 Single Finger Gesture Enable (0x11F6)
Bit 15 14 13 12 11 10 9 8
Swipeand Swipeand Swipeand Swipeand
Description SwipeY- SwipeY+ SwipeX- SwipeX+
HoldY- HoldY+ HoldX- HoldX+
Bit 7 6 5 4 3 2 1 0
Palm Press-and-
Description Reserved TripleTap DoubleTap SingleTap
Gesture Hold
> Bit 15: Swipe and Hold Y- - Swipe and hold in negative Y direction
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 14: Swipe and Hold Y+ - Swipe and hold in positive Y direction
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 13: Swipe and Hold X- - Swipe and hold in negative X direction
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 12: Swipe and Hold X+ - Swipe and hold in positive X direction
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 11: Swipe Y- - Swipe in negative Y direction
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 10: Swipe Y+ - Swipe in positive Y direction
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 9: Swipe X- - Swipe in negative X direction
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 8: Swipe X+ - Swipe in positive X direction
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 7-5: Unused
> Bit 4: Palm Gesture - Palm gesture
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 3: Press-and-Hold - Press-and-Hold gesture
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 2: Triple Tap - Triple tap gesture
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 1: Double Tap - Double tap gesture
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 0: Single Tap - Single tap gesture
• 0:Gesturedisabled
• 1:Gestureenabled
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page83of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Bit | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Swipeand HoldY- | Swipeand HoldY+ | Swipeand HoldX- | Swipeand HoldX+ | SwipeY- | SwipeY+ | SwipeX- | SwipeX+ |



### Table 2

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Reserved |  |  | Palm Gesture | Press-and- Hold | TripleTap | DoubleTap | SingleTap |



---

## Page 84

IQSwitch®
ProxSense® Series
### A.21 Two Finger Gesture Enable (0x11F8)
Bit 15 14 13 12 11 10 9 8
Description Reserved
Bit 7 6 5 4 3 2 1 0
Horizontal Vertical Press-and-
Description ZoomOut ZoomIn TripleTap DoubleTap SingleTap
Scroll Scroll Hold
> Bit 15-8: Unused
> Bit 7: Horizontal Scroll - Indicates a horizontal scroll gesture
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 6: Vertical Scroll - Indicates a vertical scroll gesture
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 5: Zoom Out - Indicates a zoom out gesture
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 4: Zoom In - Indicates a zoom in gesture
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 3: Press-and-Hold - Indicates a Press-and-Hold gesture
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 2: Triple Tap - Indicates a triple tap gesture
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 1: Double Tap - Indicates a double tap gesture
• 0:Gesturedisabled
• 1:Gestureenabled
> Bit 0: Single Tap - Indicates a single tap gesture
• 0:Gesturedisabled
• 1:Gestureenabled
### A.22 RxTx Mapping (0x1218)
Address Length Description
0x1218 1 RxTxMapping0
0x1219 1 RxTxMapping1
0x121A 1 RxTxMapping2
0x121B 1 RxTxMapping3
0x121C 1 RxTxMapping4
0x121D 1 RxTxMapping5
0x121E 1 RxTxMapping6
0x121F 1 RxTxMapping7
0x1220 1 RxTxMapping8
0x1221 1 RxTxMapping9
0x1222 1 RxTxMapping10
0x1223 1 RxTxMapping11
0x1224 1 RxTxMapping12
0x1225 1 RxTxMapping13
0x1226 1 RxTxMapping14
Continuedonnextpage...
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page84of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Bit | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Reserved |  |  |  |  |  |  |  |



### Table 2

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Horizontal Scroll | Vertical Scroll | ZoomOut | ZoomIn | Press-and- Hold | TripleTap | DoubleTap | SingleTap |



### Table 3

| Address | Length | Description |
| --- | --- | --- |
| 0x1218 | 1 | RxTxMapping0 |
| 0x1219 | 1 | RxTxMapping1 |
| 0x121A | 1 | RxTxMapping2 |
| 0x121B | 1 | RxTxMapping3 |
| 0x121C | 1 | RxTxMapping4 |
| 0x121D | 1 | RxTxMapping5 |
| 0x121E | 1 | RxTxMapping6 |
| 0x121F | 1 | RxTxMapping7 |
| 0x1220 | 1 | RxTxMapping8 |
| 0x1221 | 1 | RxTxMapping9 |
| 0x1222 | 1 | RxTxMapping10 |
| 0x1223 | 1 | RxTxMapping11 |
| 0x1224 | 1 | RxTxMapping12 |
| 0x1225 | 1 | RxTxMapping13 |
| 0x1226 | 1 | RxTxMapping14 |



---

## Page 85

IQSwitch®
ProxSense® Series
0x1227 1 RxTxMapping15
0x1228 1 RxTxMapping16
0x1229 1 RxTxMapping17
0x122A 1 RxTxMapping18
0x122B 1 RxTxMapping19
0x122C 1 RxTxMapping20
0x122D 1 RxTxMapping21
0x122E 1 RxTxMapping22
0x122F 1 RxTxMapping23
0x1230 1 RxTxMapping24
0x1231 1 RxTxMapping25
0x1232 1 RxTxMapping26
0x1233 1 RxTxMapping27
0x1234 1 RxTxMapping28
0x1235 1 RxTxMapping29
0x1236 1 RxTxMapping30
0x1237 1 RxTxMapping31
0x1238 1 RxTxMapping32
0x1239 1 RxTxMapping33
0x123A 1 RxTxMapping34
0x123B 1 RxTxMapping35
0x123C 1 RxTxMapping36
0x123D 1 RxTxMapping37
0x123E 1 RxTxMapping38
0x123F 1 RxTxMapping39
0x1240 1 RxTxMapping40
0x1241 1 RxTxMapping41
0x1242 1 RxTxMapping42
0x1243 1 RxTxMapping43
0x1244 1 RxTxMapping44
0x1245 1 Reserved(0x00)
> Byte 44-0: RxTxMapping - Trackpad Rx and Tx mapping, see Section 7.1.4
> Note: The value 44 (0x2C) may not be written to any of the registers
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page85of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| 0x1227 | 1 | RxTxMapping15 |
| --- | --- | --- |
| 0x1228 | 1 | RxTxMapping16 |
| 0x1229 | 1 | RxTxMapping17 |
| 0x122A | 1 | RxTxMapping18 |
| 0x122B | 1 | RxTxMapping19 |
| 0x122C | 1 | RxTxMapping20 |
| 0x122D | 1 | RxTxMapping21 |
| 0x122E | 1 | RxTxMapping22 |
| 0x122F | 1 | RxTxMapping23 |
| 0x1230 | 1 | RxTxMapping24 |
| 0x1231 | 1 | RxTxMapping25 |
| 0x1232 | 1 | RxTxMapping26 |
| 0x1233 | 1 | RxTxMapping27 |
| 0x1234 | 1 | RxTxMapping28 |
| 0x1235 | 1 | RxTxMapping29 |
| 0x1236 | 1 | RxTxMapping30 |
| 0x1237 | 1 | RxTxMapping31 |
| 0x1238 | 1 | RxTxMapping32 |
| 0x1239 | 1 | RxTxMapping33 |
| 0x123A | 1 | RxTxMapping34 |
| 0x123B | 1 | RxTxMapping35 |
| 0x123C | 1 | RxTxMapping36 |
| 0x123D | 1 | RxTxMapping37 |
| 0x123E | 1 | RxTxMapping38 |
| 0x123F | 1 | RxTxMapping39 |
| 0x1240 | 1 | RxTxMapping40 |
| 0x1241 | 1 | RxTxMapping41 |
| 0x1242 | 1 | RxTxMapping42 |
| 0x1243 | 1 | RxTxMapping43 |
| 0x1244 | 1 | RxTxMapping44 |
| 0x1245 | 1 | Reserved(0x00) |



---

## Page 86

IQSwitch®
ProxSense® Series
### A.23 Individual Touch Threshold Adjustments (0x12F6)
Address Length Description
0x12F6 1 CH0TouchThresholdAdjustment
0x12F7 1 CH1TouchThresholdAdjustment
0x12F8 1 CH2TouchThresholdAdjustment
Ď 500 Ď
0x14ED 1 CH503TouchThresholdAdjustment
0x14EE 1 CH504TouchThresholdAdjustment
0x14EF 1 CH505TouchThresholdAdjustment
> CH Touch Threshold Adjustment - Signed 8-bit values, see Section 5.6.1
• 00000000:ThresholdMultiplier+0
• 00000001:ThresholdMultiplier+1
• 00000010:ThresholdMultiplier+2
• 00000011:ThresholdMultiplier+3
Ď
• 01111111:ThresholdMultiplier+127
• 10000000:ThresholdMultiplier-128
• 10000001:ThresholdMultiplier-127
Ď
• 11111101:ThresholdMultiplier-3
• 11111110:ThresholdMultiplier-2
• 11111111:ThresholdMultiplier-1
### A.24 Number Of Virtual Sensors Enabled (0x14F0)
Bit 15 14 13 12 11 10 9 8
Description NumberofWheels NumberofSliders
Bit 7 6 5 4 3 2 1 0
Description NumberofButtons
> Bit 15-12: Number of Wheels - Number of virtual wheels enabled, see Section 9.1
> Bit 11-8: Number of Sliders - Number of virtual sliders enabled
> Bit 7-0: Number of Buttons - Number of virtual buttons enabled
### A.25 Engineering Configuration (0x2000)
Bit 15 14 13 12 11 10 9 8
Description Reserved MainOscStatus Reserved
Bit 7 6 5 4 3 2 1 0
MainOsc
Description Reserved Stepping
Enable
> Bit 15-11: Unused
> Bit 10-9: Main Oscillator Status
> Bit 8-1: Unused
> Bit 0: Main Oscillator Stepping Enable
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page86of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Address | Length | Description |
| --- | --- | --- |
| 0x12F6 | 1 | CH0TouchThresholdAdjustment |
| 0x12F7 | 1 | CH1TouchThresholdAdjustment |
| 0x12F8 | 1 | CH2TouchThresholdAdjustment |
| Ď | 500 | Ď |
| 0x14ED | 1 | CH503TouchThresholdAdjustment |
| 0x14EE | 1 | CH504TouchThresholdAdjustment |
| 0x14EF | 1 | CH505TouchThresholdAdjustment |



### Table 2

| Bit | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | NumberofWheels |  |  |  | NumberofSliders |  |  |  |



### Table 3

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | NumberofButtons |  |  |  |  |  |  |  |



### Table 4

| Bit | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Reserved |  |  |  |  | MainOscStatus |  | Reserved |



### Table 5

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Description | Reserved |  |  |  |  |  |  | MainOsc Stepping Enable |



---

## Page 87

IQSwitch®
ProxSense® Series
### A.26 Trackpad ATI Compensation (0xD000)
Bit
Address 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
- TrackpadCompensationDivider TrackpadCompensation
0xD000 CH0
0xD002 CH1
0xD004 CH2
Ď Ď
> Bit 15: Unused
> Bit 14-10: Trackpad Compensation Divider
> Bit 9-0: Trackpad Compensation
### A.27 Count / Delta / Reference Data
Forthecount,delta,andreferencevalues(2bytesperchannel),thestructureisdefinedasshownin
thetablebelow.ThedatainthetableisintheformatofCount/Delta/ReferenceValue[Row/Tx][Column/Rx].
Table A.10 is valid for a 26 Rx by 19 Tx trackpad.
TableA.10:Count/Delta/ReferenceValueBytesfora26Rxby19TxTrackpad
ByteNumber Data Description
X Count/Delta/ReferenceValue[0][0]-LowByte Count,deltaorreferenceat1stTx,
X+1 Count/Delta/ReferenceValue[0][0]-HighByte and1stRx(thustopleft)
X+2 Count/Delta/ReferenceValue[0][1]-LowByte Count,deltaorreferenceat1stTx,
X+3 Count/Delta/ReferenceValue[0][1]-HighByte and2ndRx
Ď Ď
X+986 Count/Delta/ReferenceValue[18][25]-LowByte Count,deltaorreferenceat19thTx,
X+987 Count/Delta/ReferenceValue[18][25]-HighByte and26thRx(thusbottomright)
For a trackpad with fewer than 26 Rxs, the values are densely packed based on the setting for Total
Rxs.Consequently,thesubsequentvaluesbecomeavailableimmediatelyafterreachingthespecified
Total Rxs value. For instance, in a 4 Rx by 2 Tx trackpad configuration, the values are packed from
address X to X+15, as illustrated in Table A.11 below:
TableA.11: Count/Delta/ReferenceValueBytesfora4Rxby2TxTrackpad
ByteNumber Data Description
X Count/Delta/ReferenceValue[0][0]-LowByte Count,deltaorreferenceat1stTx,
X+1 Count/Delta/ReferenceValue[0][0]-HighByte and1stRx(thustopleft)
X+2 Count/Delta/ReferenceValue[0][1]-LowByte Count,deltaorreferenceat1stTx,
X+3 Count/Delta/ReferenceValue[0][1]-HighByte and2ndRx
X+4 Count/Delta/ReferenceValue[0][2]-LowByte Count,deltaorreferenceat1stTx,
X+5 Count/Delta/ReferenceValue[0][2]-HighByte and3rdRx
X+6 Count/Delta/ReferenceValue[0][3]-LowByte Count,deltaorreferenceat1stTx,
X+7 Count/Delta/ReferenceValue[0][3]-HighByte and4thRx
SteptonextRow/Tx
Continuedonnextpage...
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page87of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Address | Bit |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
|  | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|  | - | TrackpadCompensationDivider |  |  |  |  | TrackpadCompensation |  |  |  |  |  |  |  |  |  |
| 0xD000 | CH0 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0xD002 | CH1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| 0xD004 | CH2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| Ď | Ď |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |



### Table 2

| ByteNumber | Data | Description |
| --- | --- | --- |
| X | Count/Delta/ReferenceValue[0][0]-LowByte | Count,deltaorreferenceat1stTx, and1stRx(thustopleft) |
| X+1 | Count/Delta/ReferenceValue[0][0]-HighByte |  |
| X+2 | Count/Delta/ReferenceValue[0][1]-LowByte | Count,deltaorreferenceat1stTx, and2ndRx |
| X+3 | Count/Delta/ReferenceValue[0][1]-HighByte |  |
| Ď | Ď |  |
| X+986 | Count/Delta/ReferenceValue[18][25]-LowByte | Count,deltaorreferenceat19thTx, and26thRx(thusbottomright) |
| X+987 | Count/Delta/ReferenceValue[18][25]-HighByte |  |



### Table 3

| ByteNumber | Data | Description |
| --- | --- | --- |
| X | Count/Delta/ReferenceValue[0][0]-LowByte | Count,deltaorreferenceat1stTx, and1stRx(thustopleft) |
| X+1 | Count/Delta/ReferenceValue[0][0]-HighByte |  |
| X+2 | Count/Delta/ReferenceValue[0][1]-LowByte | Count,deltaorreferenceat1stTx, and2ndRx |
| X+3 | Count/Delta/ReferenceValue[0][1]-HighByte |  |
| X+4 | Count/Delta/ReferenceValue[0][2]-LowByte | Count,deltaorreferenceat1stTx, and3rdRx |
| X+5 | Count/Delta/ReferenceValue[0][2]-HighByte |  |
| X+6 | Count/Delta/ReferenceValue[0][3]-LowByte | Count,deltaorreferenceat1stTx, and4thRx |
| X+7 | Count/Delta/ReferenceValue[0][3]-HighByte |  |
| SteptonextRow/Tx |  |  |



---

## Page 88

IQSwitch®
ProxSense® Series
X+8 Count/Delta/ReferenceValue[1][0]-LowByte Count,deltaorreferenceat2ndTx,
X+9 Count/Delta/ReferenceValue[1][0]-HighByte and1stRx
X+10 Count/Delta/ReferenceValue[1][1]-LowByte Count,deltaorreferenceat2ndTx,
X+11 Count/Delta/ReferenceValue[1][1]-HighByte and2ndRx
X+12 Count/Delta/ReferenceValue[1][2]-LowByte Count,deltaorreferenceat2ndTx,
X+13 Count/Delta/ReferenceValue[1][2]-HighByte and3rdRx
X+14 Count/Delta/ReferenceValue[1][3]-LowByte Count,deltaorreferenceat2ndTx,
X+15 Count/Delta/ReferenceValue[1][3]-HighByte and4thRx(thusbottomright)
### A.28 Individual Channel Status / Config Bit Definitions
For all status outputs or configuration parameters where one bit relates to one channel, the structure
isdefinedasshowninTableA.12below.Eachrowhasa32-bitvaluewherethestatus/configofeach
bit corresponds to the status/config of the corresponding column.
TableA.12:StatusBytes
ByteNumber Data Description
X Status/Config[Row0]-Byte0
X+1 Status/Config[Row0]-Byte1
X+2 Status/Config[Row0]-Byte2
X+3 Status/Config[Row0]-Byte3
X+4 Status/Config[Row1]-Byte0
X+5 Status/Config[Row1]-Byte1
X+6 Status/Config[Row1]-Byte2
X+7 Status/Config[Row1]-Byte3
Ď Ď
X+84 Status/Config[Row21]-Byte0
X+85 Status/Config[Row21]-Byte1
X+86 Status/Config[Row21]-Byte2
X+87 Status/Config[Row21]-Byte3
Byte3 Byte2
Bit 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16
RowZ - - - - - - Col25 Col24 Col23 Col22 Col21 Col20 Col19 Col18 Col17 Col16
Byte1 Byte0
Bit 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
RowZ Col15 Col14 Col13 Col12 Col11 Col10 Col9 Col8 Col7 Col6 Col5 Col4 Col3 Col2 Col1 Col0
Note:IftheXYaxesareswitched,theseregistersdoNOTswitch.Thismeansthatthebitswillalways
link to Rxs, and the registers will always link to Txs.
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page88of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| X+8 | Count/Delta/ReferenceValue[1][0]-LowByte | Count,deltaorreferenceat2ndTx, and1stRx |
| --- | --- | --- |
| X+9 | Count/Delta/ReferenceValue[1][0]-HighByte |  |
| X+10 | Count/Delta/ReferenceValue[1][1]-LowByte | Count,deltaorreferenceat2ndTx, and2ndRx |
| X+11 | Count/Delta/ReferenceValue[1][1]-HighByte |  |
| X+12 | Count/Delta/ReferenceValue[1][2]-LowByte | Count,deltaorreferenceat2ndTx, and3rdRx |
| X+13 | Count/Delta/ReferenceValue[1][2]-HighByte |  |
| X+14 | Count/Delta/ReferenceValue[1][3]-LowByte | Count,deltaorreferenceat2ndTx, and4thRx(thusbottomright) |
| X+15 | Count/Delta/ReferenceValue[1][3]-HighByte |  |



### Table 2

| ByteNumber | Data | Description |
| --- | --- | --- |
| X | Status/Config[Row0]-Byte0 |  |
| X+1 | Status/Config[Row0]-Byte1 |  |
| X+2 | Status/Config[Row0]-Byte2 |  |
| X+3 | Status/Config[Row0]-Byte3 |  |
| X+4 | Status/Config[Row1]-Byte0 |  |
| X+5 | Status/Config[Row1]-Byte1 |  |
| X+6 | Status/Config[Row1]-Byte2 |  |
| X+7 | Status/Config[Row1]-Byte3 |  |
| Ď | Ď |  |
| X+84 | Status/Config[Row21]-Byte0 |  |
| X+85 | Status/Config[Row21]-Byte1 |  |
| X+86 | Status/Config[Row21]-Byte2 |  |
| X+87 | Status/Config[Row21]-Byte3 |  |



### Table 3

|  | Byte3 |  |  |  |  |  |  |  | Byte2 |  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Bit | 31 | 30 | 29 | 28 | 27 | 26 | 25 | 24 | 23 | 22 | 21 | 20 | 19 | 18 | 17 | 16 |
| RowZ | - | - | - | - | - | - | Col25 | Col24 | Col23 | Col22 | Col21 | Col20 | Col19 | Col18 | Col17 | Col16 |



### Table 4

|  | Byte1 |  |  |  |  |  |  |  | Byte0 |  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Bit | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| RowZ | Col15 | Col14 | Col13 | Col12 | Col11 | Col10 | Col9 | Col8 | Col7 | Col6 | Col5 | Col4 | Col3 | Col2 | Col1 | Col0 |



---

## Page 89

IQSwitch®
ProxSense® Series
TableA.13:ChannelStatus/ConfigBitDefinitions
Parameter Bit=0 Bit=1
TouchStatus Channeldoesnothaveatouch Channeldoeshaveatouch
SnapStatus Channeldoesnothaveasnap Channeldoeshaveasnap
ChannelDisable Trackpadchannelenabled Trackpadchanneldisabled
SnapEnable Snapfeaturedisabledonchannel Snapfeatureenabledonchannel
Copyright©Azoteq2024 IQS9150/IQS9151Datasheet Page89of91
AllRightsReserved Revisionv1.1 October2024


### Table 1

| Parameter | Bit=0 | Bit=1 |
| --- | --- | --- |
| TouchStatus | Channeldoesnothaveatouch | Channeldoeshaveatouch |
| SnapStatus | Channeldoesnothaveasnap | Channeldoeshaveasnap |
| ChannelDisable | Trackpadchannelenabled | Trackpadchanneldisabled |
| SnapEnable | Snapfeaturedisabledonchannel | Snapfeatureenabledonchannel |
