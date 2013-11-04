#include "Control.h"

Control::Control()
{
	Visible=true;
	memset(&Position, 0x00, sizeof(Position));
	memset(&BaseColour, 0x00, sizeof(BaseColour));

	CurrentColour=BaseColour;
}

bool Control::Contains(const Point &Location) const
{
	return (Position.x<=Location.x &&
		Position.x+Position.w>=Location.x &&
		Position.y<=Location.y &&
		Position.y+Position.h>=Location.y);
}

Colour Control::GetBaseColour() const
{
	return BaseColour;
}
void Control::SetBaseColour(const Colour &BaseColour)
{
	this->BaseColour=BaseColour;
}

bool Control::IsVisible() const
{
	return Visible;
}
void Control::SetVisible(const bool &Visible)
{
	this->Visible=Visible;
}