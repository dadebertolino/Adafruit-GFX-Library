#include "dbGraphics.h"


#define BUTTON_THICK	3
/***************************************************************************/

/**************************************************************************/
/*!
   @brief    Create a simple drawn button UI element
*/
/**************************************************************************/
dbSimpleButton::dbSimpleButton(void) {
	_gfx = 0;
}

/**************************************************************************/
/*!
   @brief    Initialize button with our desired color/size/settings, with upper-left coordinates
   @param    gfx     Pointer to our display so we can draw to it!
   @param    x1       The X coordinate of the Upper-Left corner of the button
   @param    y1       The Y coordinate of the Upper-Left corner of the button
   @param    w       Width of the buttton
   @param    h       Height of the buttton
   @param    outline  Color of the outline (16-bit 5-6-5 standard)
   @param    fill  Color of the button fill (16-bit 5-6-5 standard)
   @param    textcolor  Color of the button label (16-bit 5-6-5 standard)
   @param    label  Ascii string of the text inside the button
*/
/**************************************************************************/
void dbSimpleButton::initButton(
	Adafruit_GFX *gfx, int16_t x1, int16_t y1, uint16_t w, uint16_t h,
	uint16_t outline, uint16_t fill, uint16_t textcolor,
	const String & label)
{
	_x1 = x1;
	_y1 = y1;
	_w = w;
	_h = h;
	_outlinecolor = outline;
	_fillcolor = fill;
	_textcolor = textcolor;
	_gfx = gfx;
	strncpy(_label, const_cast<char*>(label.c_str()), 29);
}

/*!
   @brief    Initialize button with our desired color/size/settings, with upper-left coordinates
   @param    gfx     Pointer to our display so we can draw to it!
   @param    x1       The X coordinate of the Upper-Left corner of the button
   @param    y1       The Y coordinate of the Upper-Left corner of the button
   @param    w       Width of the buttton
   @param    h       Height of the buttton
   @param    outline  Color of the outline (16-bit 5-6-5 standard)
   @param    fill  Color of the button fill (16-bit 5-6-5 standard)
   @param    textcolor  Color of the button label (16-bit 5-6-5 standard)
   @param    label  String of the text inside the button
*/
/**************************************************************************/

void dbSimpleButton::DrawButtonLabel(void)
{
	int16_t  x_ct, y_ct;
	uint16_t w_ct, h_ct;
	_gfx->getTextBounds(_label, 0, 0, &x_ct, &y_ct, &w_ct, &h_ct);
	_gfx->setCursor(_x1 + (_w - w_ct) / 2, _y1 + ( _h - h_ct) / 2 - y_ct);
	_gfx->print(_label);
}
/**************************************************************************/
/*!
   @brief    Draw the button on the screen
   @param    inverted Whether to draw with fill/text swapped to indicate 'pressed'
*/
/**************************************************************************/
void dbSimpleButton::drawButton(boolean inverted) {
	uint16_t fill, outline, text;

	if (!inverted) {
		fill = _fillcolor;
		outline = _outlinecolor;
		text = _textcolor;
	}
	else {
		fill = _textcolor;
		outline = _outlinecolor;
		text = _fillcolor;
	}

	uint8_t r = min(_w, _h) / 4; // Corner radius
	_gfx->fillRoundRect(_x1, _y1, _w, _h, r, fill);
	_gfx->drawRoundRect(_x1, _y1, _w, _h, r, outline, BUTTON_THICK);

	DrawButtonLabel();
}

/**************************************************************************/
/*!
	@brief    Helper to let us know if a coordinate is within the bounds of the button
	@param    x       The X coordinate to check
	@param    y       The Y coordinate to check
	@returns  True if within button graphics outline
*/
/**************************************************************************/
boolean dbSimpleButton::contains(int16_t x, int16_t y) {
	return ((x >= _x1) && (x < (int16_t)(_x1 + _w)) &&
		(y >= _y1) && (y < (int16_t)(_y1 + _h)));
}


/**************************************************************************/
/*!
@brief    Sub that set/change the label text
@param    label  String of the text inside the button
@returns  void
*/
/**************************************************************************/
void dbSimpleButton::SetLabel(const String & label)
{
	strncpy(_label, const_cast<char*>(label.c_str()), 29);
}

/**************************************************************************/
/*!
@brief    Return the label text
@returns  String The label text
*/
/**************************************************************************/
String dbSimpleButton::GetLabel(void)
{
	return String(_label);
}

/**************************************************************************/
/*!
@brief    Sub that set/change the extra data for this button
@param    ed Extra data
@returns  void
*/
/**************************************************************************/
void dbSimpleButton::SetExtraData(const String & ed)
{
	strncpy(_extraData, const_cast<char*>(ed.c_str()), 29);
}

/**************************************************************************/
/*!
@brief    Return the extra data
@returns  String The extra data
*/
/**************************************************************************/
String dbSimpleButton::GetExtraData(void)
{
	return String(_extraData);
}

/**************************************************************************/
/*!
   @brief    Query whether the button was pressed since we last checked state
   @returns  True if was not-pressed before, now is.
*/
/**************************************************************************/
boolean dbSimpleButton::justPressed() { return (currstate && !laststate); }

/**************************************************************************/
/*!
   @brief    Query whether the button was released since we last checked state
   @returns  True if was pressed before, now is not.
*/
/**************************************************************************/
boolean dbSimpleButton::justReleased() { return (!currstate && laststate); }


/***************************************************************************/

/**************************************************************************/
/*!
@brief    Create an image button UI element
*/
/**************************************************************************/
dbImageButton::dbImageButton(void) {
	_gfx = 0;
	//img = 0;
}

/**************************************************************************/
/*!
@brief    Initialize button with our desired color/size/settings, with upper-left coordinates
@param    gfx     Pointer to our display so we can draw to it!
@param    x1       The X coordinate of the Upper-Left corner of the button
@param    y1       The Y coordinate of the Upper-Left corner of the button
@param    w       Width of the buttton
@param    h       Height of the buttton
@param    outline  Color of the outline (16-bit 5-6-5 standard)
@param    fill  Color of the button fill (16-bit 5-6-5 standard)
@param    textcolor  Color of the button label (16-bit 5-6-5 standard)
@param    label  Ascii string of the text inside the button
*/
/**************************************************************************/
void dbImageButton::initButton( 
<<<<<<< HEAD
	Adafruit_GFX *gfx, int16_t x, int16_t y,
	uint16_t *bitmap, int16_t w, int16_t h)
{
	_x1 = x;
	_y1 = y;
	_w = w;
	_h = h;
	_gfx = gfx;
	img = bitmap;
=======
	Adafruit_GFX *gfx, int16_t x1, int16_t y1, const uint16_t bitmap[])
{
	_x1 = x1;
	_y1 = y1;
	_gfx = gfx;
	//img = bitmap;
>>>>>>> f8d14be81efcef3b371403cc7cc5cba2e367952e
}

/**************************************************************************/
/*!
@brief    Draw the button on the screen
@param    inverted Whether to draw with fill/text swapped to indicate 'pressed'
*/
/**************************************************************************/
<<<<<<< HEAD
void dbImageButton::drawButton(boolean inverted) 
{
	_gfx->drawRGBBitmap(_x1, _y1, img, _w, _h);
=======
void dbImageButton::drawButton(boolean inverted) {
	uint16_t fill, outline, text;

	if (!inverted) {
		fill = _fillcolor;
		outline = _outlinecolor;
		text = _textcolor;
	}
	else {
		fill = _textcolor;
		outline = _outlinecolor;
		text = _fillcolor;
	}

	uint8_t r = min(_w, _h) / 4; // Corner radius
	_gfx->fillRoundRect(_x1, _y1, _w, _h, r, fill);
	_gfx->drawRoundRect(_x1, _y1, _w, _h, r, outline, BUTTON_THICK);
>>>>>>> f8d14be81efcef3b371403cc7cc5cba2e367952e
}

/**************************************************************************/
/*!
@brief    Helper to let us know if a coordinate is within the bounds of the button
@param    x       The X coordinate to check
@param    y       The Y coordinate to check
@returns  True if within button graphics outline
*/
/**************************************************************************/
boolean dbImageButton::contains(int16_t x, int16_t y) {
<<<<<<< HEAD
	return ((x >= _x1) && (x < (_x1 + _w)) &&
		(y >= _y1) && (y < (_y1 + _h)));
=======
	return ((x >= _x1) && (x < (int16_t)(_x1 + _w)) &&
		(y >= _y1) && (y < (int16_t)(_y1 + _h)));
>>>>>>> f8d14be81efcef3b371403cc7cc5cba2e367952e
}

/**************************************************************************/
/*!
@brief    Sub that set/change the extra data for this button
@param    ed Extra data
@returns  void
*/
/**************************************************************************/
void dbImageButton::SetExtraData(const String & ed)
{
	strncpy(_extraData, const_cast<char*>(ed.c_str()), 29);
}

/**************************************************************************/
/*!
@brief    Return the extra data
@returns  String The extra data
*/
/**************************************************************************/
String dbImageButton::GetExtraData(void)
{
	return String(_extraData);
}

/**************************************************************************/
/*!
@brief    Query whether the button was pressed since we last checked state
@returns  True if was not-pressed before, now is.
*/
/**************************************************************************/
boolean dbImageButton::justPressed() { return (currstate && !laststate); }

/**************************************************************************/
/*!
@brief    Query whether the button was released since we last checked state
@returns  True if was pressed before, now is not.
*/
/**************************************************************************/
boolean dbImageButton::justReleased() { return (!currstate && laststate); }