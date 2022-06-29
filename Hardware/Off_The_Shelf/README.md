# Off the Shelf
Instructions and parts list for a full pulse resolution device.

## Parts
See [here.](https://github.com/UCHIC/CIWS-Pulse-Logger/blob/main/Hardware/Off_The_Shelf/Full_Res_Board.csv)

## Instructions
These instructions use the reference names in the parts csv. The hole identifies are printed on the board. Solder each part into the position specified.

1. Attach pin 1 of IC1 to E1 on the Board.
2. Attach IC2 pins GND to E30 and SQW to E26.
3. Attach IC3 pins CS to F24 and CD to F30.
4. Attach X1 to C9 and C10.
5. Attach C1 to A9 and GND.
6. Attach C2 to A10 and GND.
7. Attach two pins on B1 to A11 and A14. The other two should connect to GND. Rotate the button until its pins reach the designated holes.
8. Connect Bat to the positive and negative voltage rails respectively. A connector might additionally be used although it is not included in these instructions.
9. On the bottom of the board connect IC4 pins INT to J23 and VDD to J15.
10. Cut the header pins into a segment of 6. Arbitrarily number the pins. Pull the 5th pin out. Place the first pin into A4 with the last two pins extending off the board. They should sit flush.
11. Attach C3 to B1 and B4.
12. Place B2 into the battery holder on IC2.
13. Connect the following positions with wire.
-GND-J7
-VCC-J9
-GND-J17
-VCC-J15
-GND-J28
-VCC-J26
-J11-I29
-I10-H27
-H1-G19
-H12-G25
-H13-G24
-G2-G18
-F18-D28
-F19-C27
-F22-D6
-F23-C4
-D1-B14
-A7-VCC
-A8-GND
-A29-VCC
-A30-GND
-Connect both positive rails together.
-Connect both negative rails together.
-Connect the pin that's hanging off the board to GND.