#pragma once

#include "Tv.h"

class Tv;

class Remote {

public:
	friend class Tv;
	enum RemoteMode {
		normal,
		interactive
	};
	Remote() : mode(0) {};
	bool volup(Tv t);
	bool voldown(Tv t);
	void onoff(Tv t);
	void channelup(Tv t);
	void channeldown(Tv t);
	void set_channel(Tv t, int ch);
	void set_mode(Tv t);
	void showMode() const;
private:
	int mode;
	RemoteMode remoteMode;
};