#include <iostream>
#include <conio.h>
#include <iomanip>
#include <thread>
#include <windows.h>
#include <winbase.h>
#include <poclass.h>
#include <powrprof.h>
#include <setupapi.h>
#include <devguid.h>

#pragma comment(lib, "powrprof.lib")
#pragma comment(lib, "setupapi.lib")
using namespace std;

void printInfo();
void batteryPercent(SYSTEM_POWER_STATUS *);
void batteryType();
void powerSupply(SYSTEM_POWER_STATUS *);
void batterySaver(SYSTEM_POWER_STATUS *);
void batteryLifeTime(SYSTEM_POWER_STATUS *);
void batteryFullLifeTime(SYSTEM_POWER_STATUS *);

char usrInput = 0;

int main()
{
	setlocale(LC_ALL, "Russian");
	thread info(printInfo);
	
	while (usrInput != '0')
	{
		usrInput = _getch();
		switch (usrInput)
		{
		case('1'):
		{
			if (IsPwrSuspendAllowed())
				SetSuspendState(FALSE, FALSE, FALSE);
			break;
		}

		case('2'):
		{
			if (IsPwrHibernateAllowed())
				SetSuspendState(TRUE, FALSE, FALSE);
			break;
		}

		case('0'):
			break;

		default:
			break;
		}
	}
	info.join();
}

void printInfo()
{
	while (usrInput != '0')
	{
		SYSTEM_POWER_STATUS *info = new SYSTEM_POWER_STATUS();
		GetSystemPowerStatus(info);

		system("cls");
		cout << "-------------------------" << endl;
		cout << "Меню:" << endl
			<< "1 — Перейти в спящий режим" << endl
			<< "2 — Перейти в режим гибернации" << endl
			<< "0 — Выход" << endl;

		cout << endl;

		cout << "Энергопитание:" << endl;
		batteryPercent(info);
		powerSupply(info);
		batteryType();
		batterySaver(info);
		batteryLifeTime(info);
		batteryFullLifeTime(info);
		cout << "-------------------------" << endl;
		Sleep(3000);
	}
}

void batteryPercent(SYSTEM_POWER_STATUS *info)
{
	cout << "Уровень заряда батареи: ";
	if (info->BatteryLifePercent != 255)
		cout << static_cast<int>(info->BatteryLifePercent) << "%" << endl;
	else
		cout << "неизвестен" << endl;
}

void batteryType()
{
	HDEVINFO DeviceInfoSet;
	DeviceInfoSet = SetupDiGetClassDevs(&GUID_DEVCLASS_BATTERY, NULL, NULL, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);

	SP_DEVICE_INTERFACE_DATA DeviceInterfaceData = { 0 };
	ZeroMemory(&DeviceInterfaceData, sizeof(SP_DEVINFO_DATA));
	DeviceInterfaceData.cbSize = sizeof(SP_DEVINFO_DATA);

	SetupDiEnumDeviceInterfaces(DeviceInfoSet, NULL, &GUID_DEVCLASS_BATTERY, 0, &DeviceInterfaceData);
	DWORD cbRequired = 0;

	SetupDiGetDeviceInterfaceDetail(DeviceInfoSet, &DeviceInterfaceData, NULL, NULL, &cbRequired, NULL);
	PSP_DEVICE_INTERFACE_DETAIL_DATA pdidd = (PSP_DEVICE_INTERFACE_DETAIL_DATA)LocalAlloc(LPTR, cbRequired);
	pdidd->cbSize = sizeof(*pdidd);

	SetupDiGetDeviceInterfaceDetail(DeviceInfoSet, &DeviceInterfaceData, pdidd, cbRequired, &cbRequired, NULL);
	HANDLE hBattery = CreateFile(pdidd->DevicePath, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	BATTERY_QUERY_INFORMATION BatteryQueryInformation = { 0 };
	DeviceIoControl(hBattery, IOCTL_BATTERY_QUERY_TAG, NULL, NULL, &BatteryQueryInformation.BatteryTag,
		sizeof(BatteryQueryInformation.BatteryTag), NULL, NULL) && BatteryQueryInformation.BatteryTag;

	BATTERY_INFORMATION BatteryInfo = { 0 };
	BatteryQueryInformation.InformationLevel = BatteryInformation;

	DeviceIoControl(hBattery, IOCTL_BATTERY_QUERY_INFORMATION, &BatteryQueryInformation, sizeof(BatteryQueryInformation),
		&BatteryInfo, sizeof(BatteryInfo), NULL, NULL);

	cout << "Тип батареи: ";
	for (int i = 0; i < 4; i++)
		cout << BatteryInfo.Chemistry[i];
	cout << endl;

	LocalFree(pdidd);
	SetupDiDestroyDeviceInfoList(DeviceInfoSet);
}

void powerSupply(SYSTEM_POWER_STATUS *info)
{
	cout << "Тип энергопитания: ";
	switch (info->ACLineStatus)
	{
	case(0):
	{
		cout << "от батареи" << endl;
		break;
	}

	case(1):
	{
		cout << "от сети" << endl;
		break;
	}

	default:
		cout << "неизвестен" << endl;
		break;
	}

}

void batterySaver(SYSTEM_POWER_STATUS *info)
{
	cout << "Режим энергосбережения: ";
	if (info->SystemStatusFlag == 0)
		cout << "отключён" << endl;
	else
		cout << "включён" << endl;
}

void batteryLifeTime(SYSTEM_POWER_STATUS* info)
{
	long time = static_cast<long>(info->BatteryLifeTime);
	cout << "Оставшееся время работы от батареи: ";
	if (time != -1)
		cout << setfill('0') << time / 3600 << ":" << setw(2) << (time % 3600) / 60 << ":" << setw(2) << time % 60 << endl;
	else
		cout << "неизвестно (устройство работает от сети)" << endl;
}

void batteryFullLifeTime(SYSTEM_POWER_STATUS* info)
{
	long time = static_cast<long>(info->BatteryFullLifeTime);
	cout << "Полное время работы от батареи: ";
	if (time != -1)
		cout << setfill('0') << time / 3600 << ":" << setw(2) << (time % 3600) / 60 << ":" << setw(2) << time % 60 << endl;
	else
		cout << "неизвестно" << endl;
}
