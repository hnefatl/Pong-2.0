#ifndef _TRANSITIONINGCONTROL_H
#define _TRANSITIONINGCONTROL_H

#include "Control.h"

#include <Colour.h>

class TransitioningControl
	: public Control
{
public:
	TransitioningControl();

	void StartTransitioning(const Colour &To);

	virtual void Update();

	unsigned int GetUpdatesTillFinished() const;
	void SetUpdatesTillFinished(const unsigned int &UpdatesTillFinished);

	void SetVisible(const bool &Visible, const bool &SmoothTransition);

protected:
	Colour TransitioningTo;
	bool TransitioningToVisible;

	unsigned int UpdatesTillFinished;
};

#endif