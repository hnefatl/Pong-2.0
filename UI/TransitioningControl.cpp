#include "TransitioningControl.h"

TransitioningControl::TransitioningControl()
{
	UpdatesTillFinished=15;
}

void TransitioningControl::StartTransitioning(const Colour &To)
{
	TransitioningTo=To;
}

void TransitioningControl::Update()
{
	// Red
	int NewR;
	if(CurrentColour.r<TransitioningTo.r)
	{
		NewR=CurrentColour.r+(TransitioningTo.r-BaseColour.r)/UpdatesTillFinished;
	}
	else if(CurrentColour.r>TransitioningTo.r)
	{
		NewR=CurrentColour.r-(TransitioningTo.r-BaseColour.r)/UpdatesTillFinished;
	}

	if(NewR<0)
		NewR=0;
	else if(NewR>255)
		NewR=255;
	CurrentColour.r=NewR;

	// Green 
	int NewG;
	if(CurrentColour.g<TransitioningTo.g)
	{
		NewG=CurrentColour.g+(TransitioningTo.g-BaseColour.g)/UpdatesTillFinished;
	}
	else if(CurrentColour.g>TransitioningTo.g)
	{
		NewG=CurrentColour.g-(TransitioningTo.g-BaseColour.g)/UpdatesTillFinished;
	}

	if(NewG<0)
		NewG=0;
	else if(NewG>255)
		NewG=255;
	CurrentColour.g=NewG;

	// Blue
	int NewB;
	if(CurrentColour.b<TransitioningTo.b)
	{
		NewB=CurrentColour.b+(TransitioningTo.b-BaseColour.b)/UpdatesTillFinished;
	}
	else if(CurrentColour.b>TransitioningTo.b)
	{
		NewB=CurrentColour.b-(TransitioningTo.b-BaseColour.b)/UpdatesTillFinished;
	}

	if(NewB<0)
		NewB=0;
	else if(NewB>255)
		NewB=255;
	CurrentColour.b=NewB;

	int NewA;
	if(TransitioningToVisible)
	{
		NewA=CurrentColour.a+(0xFF-BaseColour.a)/UpdatesTillFinished;
	}
	else
	{
		NewA=CurrentColour.a-(0xFF-BaseColour.a)/UpdatesTillFinished;
	}

	if(NewA<0)
		NewA=0;
	else if(NewA>255)
		NewA=255;
	CurrentColour.a=NewA;
}

unsigned int TransitioningControl::GetUpdatesTillFinished() const
{
	return UpdatesTillFinished;
}
void TransitioningControl::SetUpdatesTillFinished(const unsigned int &UpdatesTillFinished)
{
	this->UpdatesTillFinished=UpdatesTillFinished;
}

void TransitioningControl::SetVisible(const bool &Visible, const bool &SmoothTransition)
{
	Control::SetVisible(Visible);
	if(SmoothTransition)
	{
		TransitioningToVisible=Visible;
	}
}