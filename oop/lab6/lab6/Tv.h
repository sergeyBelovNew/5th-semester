#pragma once

#include "Remote.h"
#include <iostream>
#include "TvException.h"

class Tv {


public:
	friend class Remote;
	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { TV, DVD };

	Tv() : state(On), volume(5), channel(1), mode(TV), maxChannel(125) {};

	void onoff() { state ^= On; };
	bool ison() const { return state == On; };
	bool volup();
	bool voldown();
	void channelup();
	void channeldown();

	void set_mode() { mode ^= DVD; };
	void settings() const;
	void switchRemote(Remote& remote);
private:
	int state;
	int volume;
	int channel;
	int mode;
	int maxChannel;
};