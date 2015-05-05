/*
Event Timer library for Arduino
by warhog <warhog@gmx.de>
  
The MIT License (MIT)
Copyright (c) 2015 warhog@gmx.de

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "EventTimer.h"

EventTimer::EventTimer(uint16_t interval) {

	this->interval = interval;
	this->lastRun = 0;
	
}


void EventTimer::setInterval(uint16_t interval) {

	this->interval = interval;

}


bool EventTimer::hasRun() {

	return (this->lastRun > 0);

}


bool EventTimer::check(time_t time) {

	if (time >= (this->lastRun + this->interval)) {
	
		this->lastRun = time;
		return true;
		
	}
	
	return false;

}

void EventTimer::reset(time_t time) {

	this->lastRun = time;

}

