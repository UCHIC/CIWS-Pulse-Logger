EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:GND #PWR0101
U 1 1 61F12513
P 3310 4245
F 0 "#PWR0101" H 3310 3995 50  0001 C CNN
F 1 "GND" H 3315 4072 50  0000 C CNN
F 2 "" H 3310 4245 50  0001 C CNN
F 3 "" H 3310 4245 50  0001 C CNN
	1    3310 4245
	1    0    0    -1  
$EndComp
Wire Wire Line
	2980 3845 3065 3845
$Comp
L MCU_Microchip_ATmega:ATmega328P-AU U1
U 1 1 61F08D4E
P 2380 3545
F 0 "U1" H 2380 1956 50  0000 C CNN
F 1 "ATmega328P-AU" H 2380 1865 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 2380 3545 50  0001 C CIN
F 3 "https://www.digikey.com/en/products/detail/microchip-technology/ATMEGA328P-AU/1832260" H 2380 3545 50  0001 C CNN
	1    2380 3545
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_Dual_x2 SW1
U 1 1 61F0C9EC
P 3310 4045
F 0 "SW1" V 3264 4193 50  0000 L CNN
F 1 "RESET" V 3355 4193 50  0000 L CNN
F 2 "Button_Switch_THT:SW_TH_Tactile_Omron_B3F-10xx" H 3310 4245 50  0001 C CNN
F 3 "https://www.digikey.com/en/products/detail/omron-electronics-inc-emc-div/B3F-1020/44059?utm_adgroup=Switches&utm_source=google&utm_medium=cpc&utm_campaign=Shopping_Supplier_Omron%20EMC_0039_Co-op&utm_term=&utm_content=Switches&gclid=Cj0KCQiAxoiQBhCRARIsAPsvo-xLaLRuc0nxEl4-8aP-8P-m5A10gvuCrbHmQW7Fmg3Fe4HuBPG-VAgaApeeEALw_wcB" H 3310 4245 50  0001 C CNN
	1    3310 4045
	0    1    1    0   
$EndComp
$Comp
L Device:Crystal Y1
U 1 1 61F14BC7
P 3575 2995
F 0 "Y1" V 3529 3126 50  0000 L CNN
F 1 "8Mhz" V 3620 3126 50  0000 L CNN
F 2 "Crystal:Crystal_SMD_TXC_AX_8045-2Pin_8.0x4.5mm" H 3575 2995 50  0001 C CNN
F 3 "https://www.digikey.com/en/products/detail/ndk-america-inc/NX8045GB-8-000M-STD-CSF-4/5022982" H 3575 2995 50  0001 C CNN
	1    3575 2995
	0    1    1    0   
$EndComp
Wire Wire Line
	2980 2945 3430 2945
Wire Wire Line
	3430 2945 3430 2845
Wire Wire Line
	3430 2845 3575 2845
Wire Wire Line
	3575 3145 3430 3145
Wire Wire Line
	3430 3145 3430 3045
Wire Wire Line
	3430 3045 2980 3045
$Comp
L Device:CP1_Small C1
U 1 1 61F18445
P 4125 2795
F 0 "C1" V 4353 2795 50  0000 C CNN
F 1 "16pF" V 4262 2795 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4125 2795 50  0001 C CNN
F 3 "https://www.digikey.com/en/products/detail/kyocera-avx/08051A160JAT2A/1600914" H 4125 2795 50  0001 C CNN
	1    4125 2795
	0    -1   -1   0   
$EndComp
$Comp
L Device:CP1_Small C2
U 1 1 61F19AC7
P 4125 3195
F 0 "C2" V 4353 3195 50  0000 C CNN
F 1 "16pF" V 4262 3195 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4125 3195 50  0001 C CNN
F 3 "https://www.digikey.com/en/products/detail/kyocera-avx/08051A160JAT2A/1600914" H 4125 3195 50  0001 C CNN
	1    4125 3195
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4025 2795 3575 2795
Wire Wire Line
	3575 2795 3575 2845
Connection ~ 3575 2845
Wire Wire Line
	4025 3195 3575 3195
Wire Wire Line
	3575 3195 3575 3145
Connection ~ 3575 3145
Wire Wire Line
	4225 2795 4275 2795
Wire Wire Line
	4225 3195 4275 3195
$Comp
L power:GND #PWR0102
U 1 1 61F1C59A
P 4275 2795
F 0 "#PWR0102" H 4275 2545 50  0001 C CNN
F 1 "GND" H 4280 2622 50  0000 C CNN
F 2 "" H 4275 2795 50  0001 C CNN
F 3 "" H 4275 2795 50  0001 C CNN
	1    4275 2795
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 61F1C7B7
P 4275 3195
F 0 "#PWR0103" H 4275 2945 50  0001 C CNN
F 1 "GND" H 4280 3022 50  0000 C CNN
F 2 "" H 4275 3195 50  0001 C CNN
F 3 "" H 4275 3195 50  0001 C CNN
	1    4275 3195
	1    0    0    -1  
$EndComp
$Comp
L Connector:Micro_SD_Card J2
U 1 1 61F04A81
P 5500 2180
F 0 "J2" H 5450 2897 50  0000 C CNN
F 1 "Micro_SD_Card" H 5450 2806 50  0000 C CNN
F 2 "Connector_Card:microSD_HC_Wuerth_693072010801" H 6650 2480 50  0001 C CNN
F 3 "https://www.digikey.com/en/products/detail/w%C3%BCrth-elektronik/693072010801/3124584?s=N4IgTCBcDaIGwE4DMAGA7GFBGFAObIAugL5A" H 5500 2180 50  0001 C CNN
	1    5500 2180
	1    0    0    -1  
$EndComp
$Comp
L Timer_RTC:PCF8523T U2
U 1 1 61F057F1
P 5370 4500
F 0 "U2" H 5914 4546 50  0000 L CNN
F 1 "PCF8523T" H 5914 4455 50  0000 L CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 6170 4150 50  0001 C CNN
F 3 "https://www.digikey.com/en/products/detail/nxp-usa-inc/PCF8523T-1-118/2530422" H 5370 4500 50  0001 C CNN
	1    5370 4500
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 61F0838D
P 5470 3900
F 0 "BT1" H 5352 3904 50  0000 R CNN
F 1 "RTC_Battery" H 5352 3995 50  0000 R CNN
F 2 "Battery:BatteryHolder_Keystone_3000_1x12mm" V 5470 3960 50  0001 C CNN
F 3 "https://www.digikey.com/en/products/detail/keystone-electronics/3000/227440" V 5470 3960 50  0001 C CNN
	1    5470 3900
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 61F9F79D
P 2380 5045
F 0 "#PWR0105" H 2380 4795 50  0001 C CNN
F 1 "GND" H 2385 4872 50  0000 C CNN
F 2 "" H 2380 5045 50  0001 C CNN
F 3 "" H 2380 5045 50  0001 C CNN
	1    2380 5045
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0106
U 1 1 61FA01B4
P 2380 2045
F 0 "#PWR0106" H 2380 1895 50  0001 C CNN
F 1 "+3V3" H 2395 2218 50  0000 C CNN
F 2 "" H 2380 2045 50  0001 C CNN
F 3 "" H 2380 2045 50  0001 C CNN
	1    2380 2045
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0107
U 1 1 61FA0B0A
P 2480 2045
F 0 "#PWR0107" H 2480 1895 50  0001 C CNN
F 1 "+3V3" H 2495 2218 50  0000 C CNN
F 2 "" H 2480 2045 50  0001 C CNN
F 3 "" H 2480 2045 50  0001 C CNN
	1    2480 2045
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0108
U 1 1 61FA14A2
P 1780 2345
F 0 "#PWR0108" H 1780 2195 50  0001 C CNN
F 1 "+3V3" H 1795 2518 50  0000 C CNN
F 2 "" H 1780 2345 50  0001 C CNN
F 3 "" H 1780 2345 50  0001 C CNN
	1    1780 2345
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 61FA3CD0
P 3095 6400
F 0 "#PWR0109" H 3095 6150 50  0001 C CNN
F 1 "GND" H 3100 6227 50  0000 C CNN
F 2 "" H 3095 6400 50  0001 C CNN
F 3 "" H 3095 6400 50  0001 C CNN
	1    3095 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3095 6000 3050 6000
Wire Wire Line
	3050 4145 2980 4145
Wire Wire Line
	3095 6100 3015 6100
Wire Wire Line
	3015 4045 2980 4045
$Comp
L Switch:SW_SPDT SW2
U 1 1 61FAC42D
P 2475 5885
F 0 "SW2" V 2429 6033 50  0000 L CNN
F 1 "PWR_SW" V 2520 6033 50  0000 L CNN
F 2 "Button_Switch_THT:SW_Slide_1P2T_CK_OS102011MS2Q" H 2475 5885 50  0001 C CNN
F 3 "https://www.digikey.com/en/products/detail/c-k/OS102011MS2QN1/411602" H 2475 5885 50  0001 C CNN
	1    2475 5885
	0    1    1    0   
$EndComp
$Comp
L power:+3V3 #PWR0110
U 1 1 61FAF13C
P 2475 5685
F 0 "#PWR0110" H 2475 5535 50  0001 C CNN
F 1 "+3V3" H 2490 5858 50  0000 C CNN
F 2 "" H 2475 5685 50  0001 C CNN
F 3 "" H 2475 5685 50  0001 C CNN
	1    2475 5685
	1    0    0    -1  
$EndComp
Wire Wire Line
	3015 4045 3015 6100
Wire Wire Line
	3050 4145 3050 6000
$Comp
L power:GND #PWR0111
U 1 1 61FBDDA3
P 5470 3800
F 0 "#PWR0111" H 5470 3550 50  0001 C CNN
F 1 "GND" H 5475 3627 50  0000 C CNN
F 2 "" H 5470 3800 50  0001 C CNN
F 3 "" H 5470 3800 50  0001 C CNN
	1    5470 3800
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 61FBE207
P 5370 4900
F 0 "#PWR0112" H 5370 4650 50  0001 C CNN
F 1 "GND" H 5375 4727 50  0000 C CNN
F 2 "" H 5370 4900 50  0001 C CNN
F 3 "" H 5370 4900 50  0001 C CNN
	1    5370 4900
	1    0    0    -1  
$EndComp
$Comp
L Connector:AVR-ISP-6 J5
U 1 1 61FBEECC
P 3165 1540
F 0 "J5" H 2835 1544 50  0000 R CNN
F 1 "ISP" H 2835 1635 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" V 2915 1590 50  0001 C CNN
F 3 "https://www.digikey.com/en/products/detail/amphenol-icc-(fci)/67996-206HLF/1878485?utm_adgroup=Connectors%20and%20Interconnects&utm_source=google&utm_medium=cpc&utm_campaign=Shopping_Supplier_Amphenol%20FCI_0609_Co-op&utm_term=&utm_content=Connectors%20and%20Interconnects&gclid=CjwKCAjw8sCRBhA6EiwA6_IF4WdhNiqC6ib0S6sQPX_n5eIzo6fjm35xQ_nPJGR1p3m21aTR2Pd50hoCNB0QAvD_BwE" H 1890 990 50  0001 C CNN
	1    3165 1540
	0    1    1    0   
$EndComp
$Comp
L pspice:CAP C3
U 1 1 61FC4433
P 5020 3940
F 0 "C3" V 4705 3940 50  0000 C CNN
F 1 "3.3uF" V 4796 3940 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5020 3940 50  0001 C CNN
F 3 "https://www.digikey.com/en/products/detail/tdk-corporation/C2012JB1C335K125AC/3948680" H 5020 3940 50  0001 C CNN
	1    5020 3940
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 61FC53FF
P 4770 3940
F 0 "#PWR0113" H 4770 3690 50  0001 C CNN
F 1 "GND" H 4775 3767 50  0000 C CNN
F 2 "" H 4770 3940 50  0001 C CNN
F 3 "" H 4770 3940 50  0001 C CNN
	1    4770 3940
	1    0    0    -1  
$EndComp
Wire Wire Line
	5270 4100 5270 3940
$Comp
L Device:R_US R1
U 1 1 61FC6D07
P 5270 3790
F 0 "R1" H 5338 3836 50  0000 L CNN
F 1 "1k" H 5338 3745 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5310 3780 50  0001 C CNN
F 3 "https://www.digikey.com/en/products/detail/yageo/AC0805FR-101KL/14286726" H 5270 3790 50  0001 C CNN
	1    5270 3790
	1    0    0    -1  
$EndComp
Connection ~ 5270 3940
$Comp
L power:+3V3 #PWR0114
U 1 1 61FC83F1
P 5270 3640
F 0 "#PWR0114" H 5270 3490 50  0001 C CNN
F 1 "+3V3" H 5285 3813 50  0000 C CNN
F 2 "" H 5270 3640 50  0001 C CNN
F 3 "" H 5270 3640 50  0001 C CNN
	1    5270 3640
	1    0    0    -1  
$EndComp
$Comp
L Device:Crystal Y2
U 1 1 61FC97EA
P 4675 4650
F 0 "Y2" V 4629 4781 50  0000 L CNN
F 1 "32.768kHz" V 4720 4781 50  0000 L CNN
F 2 "Crystal:Crystal_SMD_EuroQuartz_EQ161-2Pin_3.2x1.5mm_HandSoldering" H 4675 4650 50  0001 C CNN
F 3 "https://www.digikey.com/en/products/detail/micro-crystal-ag/CC7V-T1A-32-768KHZ-12-5PF-20PPM-TA-QC/10499064" H 4675 4650 50  0001 C CNN
	1    4675 4650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4675 4500 4870 4500
Wire Wire Line
	4870 4500 4870 4600
Wire Wire Line
	4675 4800 4870 4800
Wire Wire Line
	4870 4800 4870 4700
Wire Wire Line
	2980 3745 3990 3745
Wire Wire Line
	4605 3745 4605 4300
Wire Wire Line
	4605 4300 4870 4300
Wire Wire Line
	2980 3645 4095 3645
Wire Wire Line
	4545 3645 4545 4400
Wire Wire Line
	4545 4400 4870 4400
Wire Wire Line
	5870 4500 5870 5190
Wire Wire Line
	5870 5190 3160 5190
Wire Wire Line
	3160 5190 3160 4345
Wire Wire Line
	3160 4345 2980 4345
$Comp
L power:+3V3 #PWR0115
U 1 1 61FD36B9
P 5270 5540
F 0 "#PWR0115" H 5270 5390 50  0001 C CNN
F 1 "+3V3" H 5285 5713 50  0000 C CNN
F 2 "" H 5270 5540 50  0001 C CNN
F 3 "" H 5270 5540 50  0001 C CNN
	1    5270 5540
	1    0    0    -1  
$EndComp
Wire Wire Line
	5270 5840 4905 5840
Wire Wire Line
	4095 5840 4095 3645
Connection ~ 4095 3645
Wire Wire Line
	4095 3645 4545 3645
Wire Wire Line
	3990 5940 3990 3745
Connection ~ 3990 3745
Wire Wire Line
	3990 3745 4605 3745
Wire Wire Line
	5270 5740 5085 5740
$Comp
L power:GND #PWR0116
U 1 1 61FD6545
P 5085 5740
F 0 "#PWR0116" H 5085 5490 50  0001 C CNN
F 1 "GND" H 5090 5567 50  0000 C CNN
F 2 "" H 5085 5740 50  0001 C CNN
F 3 "" H 5085 5740 50  0001 C CNN
	1    5085 5740
	-1   0    0    1   
$EndComp
Wire Wire Line
	5270 6340 4605 6340
Wire Wire Line
	3675 6340 3675 4550
Wire Wire Line
	3675 4550 3200 4550
Wire Wire Line
	3200 4550 3200 4245
Wire Wire Line
	3200 4245 2980 4245
Wire Wire Line
	2980 4445 3180 4445
Wire Wire Line
	3180 4445 3180 4590
Wire Wire Line
	3180 4590 3625 4590
Wire Wire Line
	3625 4590 3625 6240
Wire Wire Line
	3625 6240 4705 6240
$Comp
L power:GND #PWR0117
U 1 1 61FDB8FA
P 2765 1440
F 0 "#PWR0117" H 2765 1190 50  0001 C CNN
F 1 "GND" H 2770 1267 50  0000 C CNN
F 2 "" H 2765 1440 50  0001 C CNN
F 3 "" H 2765 1440 50  0001 C CNN
	1    2765 1440
	0    1    1    0   
$EndComp
$Comp
L power:+3V3 #PWR0118
U 1 1 61FDC79B
P 3665 1440
F 0 "#PWR0118" H 3665 1290 50  0001 C CNN
F 1 "+3V3" H 3680 1613 50  0000 C CNN
F 2 "" H 3665 1440 50  0001 C CNN
F 3 "" H 3665 1440 50  0001 C CNN
	1    3665 1440
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R2
U 1 1 61FDD2B5
P 3460 3845
F 0 "R2" V 3255 3845 50  0000 C CNN
F 1 "10k" V 3346 3845 50  0000 C CNN
F 2 "LED_SMD:LED_0805_2012Metric_Castellated" V 3500 3835 50  0001 C CNN
F 3 "https://www.digikey.com/en/products/detail/stackpole-electronics-inc/RNCP0805FTD10K0/2240262" H 3460 3845 50  0001 C CNN
	1    3460 3845
	0    1    1    0   
$EndComp
Connection ~ 3310 3845
$Comp
L power:+3V3 #PWR0119
U 1 1 61FDE25D
P 3610 3845
F 0 "#PWR0119" H 3610 3695 50  0001 C CNN
F 1 "+3V3" V 3625 3973 50  0000 L CNN
F 2 "" H 3610 3845 50  0001 C CNN
F 3 "" H 3610 3845 50  0001 C CNN
	1    3610 3845
	0    1    1    0   
$EndComp
Wire Wire Line
	3065 3845 3065 1940
Connection ~ 3065 3845
Wire Wire Line
	3065 3845 3310 3845
Wire Wire Line
	2980 2745 3365 2745
Wire Wire Line
	4600 2380 4450 2380
Wire Wire Line
	4600 2180 4450 2180
$Comp
L power:GND #PWR0120
U 1 1 61FA05F3
P 4450 2380
F 0 "#PWR0120" H 4450 2130 50  0001 C CNN
F 1 "GND" H 4455 2207 50  0000 C CNN
F 2 "" H 4450 2380 50  0001 C CNN
F 3 "" H 4450 2380 50  0001 C CNN
	1    4450 2380
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0121
U 1 1 61FA0B1B
P 4450 2180
F 0 "#PWR0121" H 4450 2030 50  0001 C CNN
F 1 "+3.3V" H 4465 2353 50  0000 C CNN
F 2 "" H 4450 2180 50  0001 C CNN
F 3 "" H 4450 2180 50  0001 C CNN
	1    4450 2180
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 1980 4315 1980
Wire Wire Line
	3165 1940 3165 2280
Wire Wire Line
	2980 2845 3165 2845
Wire Wire Line
	3365 1940 3365 2480
Wire Wire Line
	3265 1940 3265 2080
Wire Wire Line
	2980 2645 3265 2645
Wire Wire Line
	4315 1980 4315 2545
Wire Wire Line
	4315 2545 2980 2545
Wire Wire Line
	4600 2280 3165 2280
Connection ~ 3165 2280
Wire Wire Line
	3165 2280 3165 2845
Wire Wire Line
	4600 2080 3265 2080
Connection ~ 3265 2080
Wire Wire Line
	3265 2080 3265 2645
Wire Wire Line
	4600 2480 3365 2480
Connection ~ 3365 2480
Wire Wire Line
	3365 2480 3365 2745
$Comp
L power:GND #PWR0122
U 1 1 6201A48F
P 6300 2780
F 0 "#PWR0122" H 6300 2530 50  0001 C CNN
F 1 "GND" H 6305 2607 50  0000 C CNN
F 2 "" H 6300 2780 50  0001 C CNN
F 3 "" H 6300 2780 50  0001 C CNN
	1    6300 2780
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x06_Female J3
U 1 1 62056948
P 3295 6100
F 0 "J3" H 3323 6076 50  0000 L CNN
F 1 "Conn_01x06_Female" H 3323 5985 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 3295 6100 50  0001 C CNN
F 3 "~" H 3295 6100 50  0001 C CNN
	1    3295 6100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x09_Female J4
U 1 1 6205BF55
P 5470 5940
F 0 "J4" H 5498 5966 50  0000 L CNN
F 1 "Conn_01x09_Female" H 5498 5875 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x09_P2.54mm_Vertical" H 5470 5940 50  0001 C CNN
F 3 "https://www.digikey.com/en/products/detail/w%C3%BCrth-elektronik/61301611121/4846854?utm_adgroup=Rectangular%20Connectors%20-%20Headers%2C%20Male%20Pins&utm_source=google&utm_medium=cpc&utm_campaign=Shopping_Product_Connectors%2C%20Interconnects&utm_term=&utm_content=Rectangular%20Connectors%20-%20Headers%2C%20Male%20Pins&gclid=CjwKCAjw8sCRBhA6EiwA6_IF4QIyq7tvweOHD4ZxKWrC-QYRubXGeTv1Tm1ChI4jTWYohvBzQXjItRoCXQ4QAvD_BwE" H 5470 5940 50  0001 C CNN
	1    5470 5940
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x06 J6
U 1 1 622EAA5A
P 4905 6835
F 0 "J6" V 4777 7115 50  0000 L CNN
F 1 "Screw_Terminal_01x06" V 4868 7115 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-6-2.54_1x06_P2.54mm_Horizontal" H 4905 6835 50  0001 C CNN
F 3 "https://www.digikey.com/en/products/detail/phoenix-contact/1725698/267466" H 4905 6835 50  0001 C CNN
	1    4905 6835
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR0125
U 1 1 622F2CCC
P 5105 6635
F 0 "#PWR0125" H 5105 6485 50  0001 C CNN
F 1 "+3.3V" H 5120 6808 50  0000 C CNN
F 2 "" H 5105 6635 50  0001 C CNN
F 3 "" H 5105 6635 50  0001 C CNN
	1    5105 6635
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0126
U 1 1 622F32BE
P 5005 6635
F 0 "#PWR0126" H 5005 6385 50  0001 C CNN
F 1 "GND" H 5010 6462 50  0000 C CNN
F 2 "" H 5005 6635 50  0001 C CNN
F 3 "" H 5005 6635 50  0001 C CNN
	1    5005 6635
	-1   0    0    1   
$EndComp
Wire Wire Line
	4905 6635 4905 5840
Connection ~ 4905 5840
Wire Wire Line
	5270 5940 4805 5940
Wire Wire Line
	4095 5840 4905 5840
Wire Wire Line
	4805 6635 4805 5940
Connection ~ 4805 5940
Wire Wire Line
	4805 5940 3990 5940
Wire Wire Line
	4705 6635 4705 6240
Connection ~ 4705 6240
Wire Wire Line
	4705 6240 5270 6240
Wire Wire Line
	4605 6635 4605 6340
Connection ~ 4605 6340
Wire Wire Line
	4605 6340 3675 6340
$Comp
L power:GND #PWR0104
U 1 1 61F9E2AC
P 2235 6190
F 0 "#PWR0104" H 2235 5940 50  0001 C CNN
F 1 "GND" H 2240 6017 50  0000 C CNN
F 2 "" H 2235 6190 50  0001 C CNN
F 3 "" H 2235 6190 50  0001 C CNN
	1    2235 6190
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 61F0991A
P 2035 6190
F 0 "J1" H 2115 6182 50  0000 L CNN
F 1 "POWER_Terminal" H 2115 6091 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-2-2.54_1x02_P2.54mm_Horizontal" H 2035 6190 50  0001 C CNN
F 3 "https://www.digikey.com/en/products/detail/phoenix-contact/1725656/267462" H 2035 6190 50  0001 C CNN
	1    2035 6190
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0123
U 1 1 622CE202
P 2375 6390
F 0 "#PWR0123" H 2375 6140 50  0001 C CNN
F 1 "GND" H 2380 6217 50  0000 C CNN
F 2 "" H 2375 6390 50  0001 C CNN
F 3 "" H 2375 6390 50  0001 C CNN
	1    2375 6390
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT2
U 1 1 622BD815
P 2375 6290
F 0 "BT2" H 2493 6386 50  0000 L CNN
F 1 "Battery_Cell" H 2493 6295 50  0000 L CNN
F 2 "Battery:BatteryHolder_MPD_BH-18650-PC2" V 2375 6350 50  0001 C CNN
F 3 "https://www.digikey.com/en/products/detail/mpd-memory-protection-devices/BK-18650-PC2/2079908" V 2375 6350 50  0001 C CNN
	1    2375 6290
	1    0    0    -1  
$EndComp
Wire Wire Line
	2375 6085 2375 6090
Wire Wire Line
	2375 6090 2235 6090
Connection ~ 2375 6090
$EndSCHEMATC
