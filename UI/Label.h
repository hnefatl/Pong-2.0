#ifndef _LABEL_H
#define _LABEL_H

#include "TransitioningControl.h"

class Label
	: public TransitioningControl
{
public:
	Label();

	virtual bool Load(SDL_Renderer *Renderer);

	virtual void Render(SDL_Renderer *Renderer);

protected:

};

#endif