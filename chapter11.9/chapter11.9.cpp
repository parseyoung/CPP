// ���߻��
// ���̾Ƹ�� ����� ���ϴ� ���� ���� -> ���������� �ذ�
#include <iostream>
using namespace std;

class UsbDevice
{
private:
	long m_id;
public:
	UsbDevice(long id) : m_id(id) {}

	long getID() { return m_id; }

	void plugAndPlay() {}
};

class NetworkDevice
{
private:
	long m_id;
public:
	NetworkDevice(long id)
		: m_id(id)
	{}
	long getID()
	{
		return m_id;
	}
	void networking()
	{}
};

class UsbNetworkDevie : public UsbDevice, public NetworkDevice
{
public:
	UsbNetworkDevie(long usb_id, long net_id)
		: UsbDevice(usb_id), NetworkDevice(net_id)
	{}
};

int main()
{
	UsbNetworkDevie my_device(3.14, 6.022);

	my_device.networking();
	my_device.plugAndPlay();

	// �ߺ��� �̸� ȣ��
	my_device.UsbDevice::getID();
	my_device.NetworkDevice::getID();


	return 0;
}