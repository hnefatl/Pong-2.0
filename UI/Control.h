#ifndef _CONTROL_H
#define _CONTROL_H

#include <SDL.h>

#include <Print.h>
#include <Rect.h>
#include <Point.h>
#include <Colour.h>

class Control
{
public:
	Control();

	virtual bool Load(SDL_Renderer *const Renderer)=0;

	virtual void Update()=0;
	virtual void Render(SDL_Renderer *const Renderer)=0;

	bool Contains(const Point &Location) const;

	Colour GetBaseColour() const;
	void SetBaseColour(const Colour &BaseColour);

	bool IsVisible() const;
	void SetVisible(const bool &Visible);

protected:
	Rect Position;
	Colour BaseColour;
	Colour CurrentColour;

	bool Visible;
};

#endif