#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <devguid.h>
#include <setupapi.h>

#pragma comment(lib, "setupapi.lib")

using namespace cv;
using namespace std;

void hideConsole();
void takePhoto();
void displayInfo();
LRESULT	CALLBACK keyPress(int, WPARAM, LPARAM);
string makeFileName();

bool hidden = false;
bool cameraReady = true;
bool stop = false;

int main()
{
	setlocale(LC_ALL, "Russian");
	HHOOK hhookSysMsg = SetWindowsHookExW(WH_KEYBOARD_LL, keyPress, NULL, 0);

	displayInfo();
	while (!stop)
	{
		MSG msg;
		PeekMessage(&msg, NULL, 0, 0, 1);
	}

	UnhookWindowsHookEx(hhookSysMsg);
	return 0;
}

LRESULT	CALLBACK keyPress(int code, WPARAM wParam, LPARAM lParam)
{
	KBDLLHOOKSTRUCT* key = (KBDLLHOOKSTRUCT*)lParam;

	switch (key->scanCode)
	{
	case 0x0C:
		hideConsole();
		break;
	case 0x0D:
		if (cameraReady)
			takePhoto();
		break;
	case 0x01:
		stop = true;
		break;
	}

	return CallNextHookEx(NULL, code, wParam, lParam);
}

void hideConsole() 
{
	HWND console = GetConsoleWindow();
	SetForegroundWindow(console);
	ShowWindow(GetForegroundWindow(), hidden == false ? SW_HIDE : SW_SHOW);
	hidden = !hidden;
}

void takePhoto()
{
	cameraReady = false;
	VideoCapture stream(0);
	Mat photo;

	if (!stream.isOpened())
		return;

	if (!stream.read(photo))
	{
		stream.release();
		cameraReady = true;
		return;
	}

	resize(photo, photo, Size(800, 600));
	imwrite(makeFileName(), photo);

	stream.release();
	cameraReady = true;
}

void displayInfo()
{
	HDEVINFO hDevInfo;
	SP_DEVINFO_DATA DeviceInfoData;

	DeviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
	hDevInfo = SetupDiGetClassDevsW(&GUID_DEVCLASS_CAMERA, 0, 0, DIGCF_PRESENT);
	SetupDiEnumDeviceInfo(hDevInfo, 0, &DeviceInfoData);

	WCHAR friendlyName[255];
	if (SetupDiGetDeviceRegistryPropertyW(hDevInfo, &DeviceInfoData, SPDRP_FRIENDLYNAME, NULL, (PBYTE)friendlyName, 255, NULL))
		wcout << L"Название: " << friendlyName << endl;

	WCHAR description[255];
	if (SetupDiGetDeviceRegistryPropertyW(hDevInfo, &DeviceInfoData, SPDRP_DEVICEDESC, NULL, (PBYTE)description, 255, NULL))
		wcout << L"Описание устройства: " << description << endl;

	WCHAR manufacturer[255];
	if (SetupDiGetDeviceRegistryPropertyW(hDevInfo, &DeviceInfoData, SPDRP_MFG, NULL, (PBYTE)manufacturer, 255, NULL))
		wcout << L"Производитель: " << manufacturer << endl;

	WCHAR hardwareID[255];
	if (SetupDiGetDeviceRegistryPropertyW(hDevInfo, &DeviceInfoData, SPDRP_HARDWAREID, NULL, (PBYTE)hardwareID, 255, NULL))
		wcout << L"Hardware ID: " << hardwareID << endl;

	WCHAR instanceId[255];
	if (SetupDiGetDeviceInstanceIdW(hDevInfo, &DeviceInfoData, (PWSTR)instanceId, 255, NULL))
		wcout << L"Instance ID: " << instanceId << endl << endl << endl;

	SetupDiDestroyDeviceInfoList(hDevInfo);
}

string itos(int i)
{
	char buf[255] = { '\0' };
	memset(buf, '\0', sizeof(buf));
	_itoa_s(i, buf, 10);

	return buf;
}

string makeFileName()
{
	string fname;
	ifstream file;
	int i = 0;
	while (true)
	{
		fname = "D:/vas_snimayet_skrytaya_kamera" + (i > 0 ? itos(i) : "") + ".jpg";
		file.open(fname);
		if (!file)
			break;

		file.close();
		i++;
	}

	return fname;
}