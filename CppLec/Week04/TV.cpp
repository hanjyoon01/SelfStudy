#include "TV.h"
#include <iostream>

using std::cout;
using std::endl;

void TV::powerOnOff()
{
	m_isOn = !m_isOn;
}

void TV::setVolume(int volume)
{
	if(m_isOn)
		m_volume = volume;
	showStatus();
}

int TV::getVolume()
{
		return m_volume;
}

void TV::setChannel(int channel)
{
	if (m_isOn)
		m_channel = channel;
	showStatus();
}

int TV::getChannel()
{
	return m_channel;
}

void TV::showStatus()
{
	if (m_isOn) {
		cout << "채널 : " << m_channel << ", 볼륨 : " << m_volume << " 시청중" << endl;
	}
	else {
		cout << "전원이 꺼져있음" << endl;
	}
}
