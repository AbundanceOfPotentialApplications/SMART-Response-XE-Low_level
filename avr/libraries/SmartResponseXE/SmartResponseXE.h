//
// SMART Response XE support library
// written by Larry Bank
// Copyright (C) 2018 BitBank Software, Inc.
// Project started 8/4/2018
//
#ifndef __SMART_RESPONSE_XE__
#define __SMART_RESPONSE_XE__

// Font sizes (9x8, 6x8, 12x16, 15x16)
#define FONT_NORMAL 0
#define FONT_SMALL 1
#define FONT_MEDIUM 2
#define FONT_LARGE 3

// Keyboard info
#define ROWS 6
#define COLS 10

// Display info
#define LCD_WIDTH 384
#define LCD_HEIGHT 136

// keyboard special keys
#define KEY_MENU 1
#define KEY_LEFT 2
#define KEY_RIGHT 3
#define KEY_UP 4
#define KEY_DOWN 5

//
// Simplified pin numbering scheme uses a hex number to specify the port number
// and bit. Top 4 bits = port (B/D/E/F/G), bottom 3 bits specify the bit of the port
// e.g. 0xB4 = PORTB, bit 4, 0Ax is for port G
//
void mypinMode(uint8_t pin, uint8_t mode);
void mydigitalWrite(uint8_t pin, uint8_t value);
uint8_t mydigitalRead(uint8_t pin);

//
// Power Sleep (low power mode to save battery)
// Wakes up when the "power" button is pressed
//
void SRXESleep(void);

//
// Power on the LCD
//
void SRXEPowerUp(void);

//
// Power off the LCD
//
void SRXEPowerDown(void);
//
// Initializes the LCD controller
// Parameters: GPIO pin numbers used for the CS/DC/RST control lines
//
int SRXEInit(int iCS, int iDC, int iReset);
//
// Send commands to position the "cursor" to the given
// row and column and width and height of the memory window
//
void SRXESetPosition(int x, int y, int cx, int cy);
//
// Write a block of pixel data to the LCD
// Length can be anything from 1 to 17408 (whole display)
//
void SRXEWriteDataBlock(unsigned char *ucBuf, int iLen);

void SRXELoadBitmapRLE(int x, int y, const uint8_t *btmp);

// SRXEIncreaseVop
// increase Vop voltage, so increase contrast
//
void SRXEIncreaseVop(void);

// SRXEDecreaseVop
// decrease Vop voltage, so decrease contrast
//
void SRXEDecreaseVop(void);


//
//  Set Scroll Area
// inputs:
// TA: top fixed area
// SA: scroll area
// BA: bottom fixed area
// TA + SA + BA = 160
//
//  fdufnews 12/2019
//
void SRXEScrollArea(int TA, int SA, int BA);
//
// Scroll the screen N lines vertically (positive or negative)
// The value given represents a delta which affects the current scroll offset
// Returns the current scroll value
//
int SRXEScroll(int iLines);
//
// Reset the scroll position to 0
//
void SRXEScrollReset(void);

void SRXEHorizontalLine(int x, int y, int length,byte color,int thickness);
void SRXEVerticalLine(int x, int y, int height,byte color);

//
// Draw an outline or filled rectangle
// Only draws on byte boundaries (3 pixels wide)
// (display is treated as 128x136)
//
void SRXERectangle(int x, int y, int cx, int cy, byte color, byte bFilled);
//
// Draw a string of normal (9x8), small (6x8) or large (15x16) characters
// At the given col+row
//
int SRXEWriteString(int x, int y, char *szMsg, int iSize, int iFGColor, int iBGColor);
// Fill the frame buffer with a byte pattern
// e.g. all off (0x00) or all on (0xff)
void SRXEFill(byte ucData);
//
// Scan the rows and columns and store the results in the key map
//
void SRXEScanKeyboard(void);
//
// Return a pointer to the internal key map
// (10 bytes with 6 bits each)
//
byte *SRXEGetKeyMap(void);
//
// Return the current key pressed
// includes code to provide shift + sym adjusted output
// internally calls SRXEScanKeyboard()
//
byte SRXEGetKey(void);

//
// Returns the current state of the power key
// 1/TRUE if pressed, 0/FALSE if not.
//
byte SRXEGetPowerKey(void);

//
// Erase a 4k sector
// This is the smallest area that can be erased
// It can take around 60ms
// This function optionally waits until it completes
// returns 1 for success, 0 for failure
//
int SRXEFlashEraseSector(uint32_t ulAddr, int bWait);
//
// Write a 256-byte flash page
// Address must be on a page boundary
// returns 1 for success, 0 for failure
//
int SRXEFlashWritePage(uint32_t ulAddr, uint8_t *pSrc);
//
// Read N bytes from SPI flash
//
int SRXEFlashRead(uint32_t ulAddr, uint8_t *pDest, int iLen);

#define K_NONE 0
#define K_F1 0xf0
#define K_F2 0xf1
#define K_F3 0xf2
#define K_F4 0xf3

#define K_F5 0xf4
#define K_F6 0xf5
#define K_F7 0xf6
#define K_F8 0xf7
#define K_F9 0xf8
#define K_F10 0xf9
#define K_Menu 0x1

#define K_Space 0x32
#define K_Del 0x08
#define K_Backspace 0x7f
#define K_Enter 0x0d
#define K_Up 4
#define K_Down 5
#define K_Left 2
#define K_Right 3

#define K_PgUp 0xe
#define K_PgDown 0xf
#define K_Home 0xa
#define K_End 0xb


#endif // __SMART_RESPONSE_XE__

