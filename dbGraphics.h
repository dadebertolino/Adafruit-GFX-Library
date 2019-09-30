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


class dbWidget {
public:
		virtual void Draw(void);
		//virtual boolean contains(int16_t x, int16_t y);

};

/// A simple drawn button UI element
class dbSimpleButton:dbWidget {

public:
	virtual void Draw(void) { drawButton(false); };
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
	boolean GetVisible(void);
	void SetVisible(boolean visible);

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
	boolean _visible;

	void DrawButtonLabel(void);
};

class dbImageButton {

public:
	dbImageButton(void);
	void initButton(Adafruit_GFX *gfx, int16_t x, int16_t y, uint16_t *bitmap, int16_t w, int16_t h);
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
	Adafruit_GFX	*_gfx;
	int16_t			_x1, _y1; // Coordinates of top-left corner
	int16_t			_w, _h; // Coordinates of top-left corner
	uint16_t *		img;
	char			_extraData[30];

	boolean currstate, laststate;
	boolean _visible;

	void DrawButtonLabel(void);
};

#endif
