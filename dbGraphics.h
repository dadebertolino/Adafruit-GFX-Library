#ifndef _DB_GRAPHICS_H
#define _DB_GRAPHICS_H

#if ARDUINO >= 100
#include "Arduino.h"
#include "Print.h"
#else
#include "WProgram.h"
#endif
#include "gfxfont.h"
#include "Adafruit_GFX.h"


/// A simple drawn button UI element
class dbSimpleButton {

public:
	dbSimpleButton(void);
	void initButton(Adafruit_GFX *gfx, int16_t x1, int16_t y1,
		uint16_t w, uint16_t h, uint16_t outline, uint16_t fill,
		uint16_t textcolor, const String & label);
	void drawButton(boolean inverted = false);
	void SetLabel(const String & label);
	String GetLabel(void);
	void SetExtraData(const String & ed);
	String GetExtraData(void);
	boolean contains(int16_t x, int16_t y);

	/**********************************************************************/
	/*!
	  @brief    Sets button state, should be done by some touch function
	  @param    p  True for pressed, false for not.
	*/
	/**********************************************************************/
	void press(boolean p) { laststate = currstate; currstate = p; }

	boolean justPressed();
	boolean justReleased();

	/**********************************************************************/
	/*!
	  @brief    Query whether the button is currently pressed
	  @returns  True if pressed
	*/
	/**********************************************************************/
	boolean isPressed(void) { return currstate; };

private:
	Adafruit_GFX *_gfx;
	int16_t       _x1, _y1; // Coordinates of top-left corner
	uint16_t      _w, _h;
	uint16_t      _outlinecolor, _fillcolor, _textcolor;
	char          _label[30];
	char          _extraData[30];

	boolean currstate, laststate;

	void DrawButtonLabel(void);
};
<<<<<<< HEAD

=======
/*
drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[]),
drawRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap),
*/
>>>>>>> f8d14be81efcef3b371403cc7cc5cba2e367952e
class dbImageButton {

public:
	dbImageButton(void);
<<<<<<< HEAD
	void initButton(Adafruit_GFX *gfx, int16_t x, int16_t y, uint16_t *bitmap, int16_t w, int16_t h);
=======
	void initButton(Adafruit_GFX *gfx, int16_t x1, int16_t y1, const uint16_t bitmap[]);
>>>>>>> f8d14be81efcef3b371403cc7cc5cba2e367952e
	void drawButton(boolean inverted = false);
	void SetExtraData(const String & ed);
	String GetExtraData(void);
	boolean contains(int16_t x, int16_t y);

	/**********************************************************************/
	/*!
	@brief    Sets button state, should be done by some touch function
	@param    p  True for pressed, false for not.
	*/
	/**********************************************************************/
	void press(boolean p) { laststate = currstate; currstate = p; }

	boolean justPressed();
	boolean justReleased();

	/**********************************************************************/
	/*!
	@brief    Query whether the button is currently pressed
	@returns  True if pressed
	*/
	/**********************************************************************/
	boolean isPressed(void) { return currstate; };

private:
<<<<<<< HEAD
	Adafruit_GFX	*_gfx;
	int16_t			_x1, _y1; // Coordinates of top-left corner
	int16_t			_w, _h; // Coordinates of top-left corner
	uint16_t *		img;
	char			_extraData[30];
=======
	Adafruit_GFX *_gfx;
	int16_t       _x1, _y1; // Coordinates of top-left corner
	uint16_t      _w, _h;
	uint16_t      _outlinecolor, _fillcolor, _textcolor;
	const char PROGMEM * img[];
	char          _extraData[30];
>>>>>>> f8d14be81efcef3b371403cc7cc5cba2e367952e

	boolean currstate, laststate;

	void DrawButtonLabel(void);
};

#endif
