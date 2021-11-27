#pragma once
class TV
{
private:
	bool m_isOn = false;
	int m_volume = 10;
	int m_channel = 5;
public:
	void powerOnOff();
	void setVolume(int volume);
	int getVolume();
	void setChannel(int channel);
	int getChannel();
	void showStatus();
};

