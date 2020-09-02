void UMyBPLibrary::USB(bool & usb, FString & location1)
{
	bool tt = false;
	TCHAR drivers[256] = { 0 };			//取得裝置的名稱,一個裝置的名稱會佔4個字元,回傳值會得到所寫入字元陣列的長度
	DWORD len = ::GetLogicalDriveStrings(256, drivers);



	for (int i = 0; i < 256; i += 4)
	{
		if (DRIVE_REMOVABLE == ::GetDriveType(&drivers[i]))
		{
			tt = true;

			FString location;
			location += drivers[i];
			location += ":\\";
			location1 = location;
			break;

			/*
			FString location2;
			location2 += "C:\\Asclepius_Anatomy\\AsclepiusAlpha\\CircularProgressBar";
			location = location2;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, location);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, fileName);
			*/
		}
	}

	if (tt)
	{
		usb = true;
	}
	else
	{
		usb = false;
	}
	/******************************************************************************/
		///*
		//UINT nDevices = 0;   // nDevices = number of devices
		//GetRawInputDeviceList(NULL, &nDevices, sizeof(RAWINPUTDEVICELIST));

		//PRAWINPUTDEVICELIST pRawInputDeviceList;
		//pRawInputDeviceList = new RAWINPUTDEVICELIST[sizeof(RAWINPUTDEVICELIST) * nDevices];

		//int nResult;
		//nResult = GetRawInputDeviceList(pRawInputDeviceList, &nDevices, sizeof(RAWINPUTDEVICELIST));
		//for (UINT i = 0; i < nDevices; i++)
		//{
		//	// Get Character Count For Device Name
		//	UINT nBufferSize = 0;
		//	nResult = GetRawInputDeviceInfo(pRawInputDeviceList[i].hDevice, // Device
		//		RIDI_DEVICENAME,                // Get Device Name
		//		NULL,                           // NO Buff, Want Count!
		//		&nBufferSize);                 // Char Count Here!

		//									   // Got Device Name?
		//	// Allocate Memory For Device Name
		//	WCHAR* wcDeviceName = new WCHAR[nBufferSize + 1];

		//	// Got Memory


		//	// Get Name
		//	nResult = GetRawInputDeviceInfo(pRawInputDeviceList[i].hDevice, // Device
		//		RIDI_DEVICENAME,                // Get Device Name
		//		wcDeviceName,                   // Get Name!
		//		&nBufferSize);                 // Char Count

		//									   // Got Device Name?
		//	if (nResult < 0)
		//	{
		//		// Error
		//		//cout << "ERR: Unable to get Device Name.. Moving to next device." << endl << endl;

		//		// Clean Up
		//		delete[] wcDeviceName;

		//		// Next
		//		continue;
		//	}

		//	// Set Device Info & Buffer Size
		//	RID_DEVICE_INFO rdiDeviceInfo;
		//	rdiDeviceInfo.cbSize = sizeof(RID_DEVICE_INFO);
		//	nBufferSize = rdiDeviceInfo.cbSize;

		//	// Get Device Info
		//	nResult = GetRawInputDeviceInfo(pRawInputDeviceList[i].hDevice,
		//		RIDI_DEVICEINFO,
		//		&rdiDeviceInfo,
		//		&nBufferSize);

		//	
		//	
		//	// Mouse
		//	if (rdiDeviceInfo.dwType == RIM_TYPEMOUSE)
		//	{
		//		// Current Device
		//		/*cout << endl << "Displaying device " << i + 1 << " information. (MOUSE)" << endl;
		//		wcout << L"Device Name: " << wcDeviceName << endl;
		//		cout << "Mouse ID: " << rdiDeviceInfo.mouse.dwId << endl;
		//		cout << "Mouse buttons: " << rdiDeviceInfo.mouse.dwNumberOfButtons << endl;
		//		cout << "Mouse sample rate (Data Points): " << rdiDeviceInfo.mouse.dwSampleRate << endl;
		//	}

		//	// Keyboard
		//	else if (rdiDeviceInfo.dwType == RIM_TYPEKEYBOARD)
		//	{
		//		// Current Device
		//		/*cout << endl << "Displaying device " << i + 1 << " information. (KEYBOARD)" << endl;
		//		wcout << L"Device Name: " << wcDeviceName << endl;
		//		cout << "Keyboard mode: " << rdiDeviceInfo.keyboard.dwKeyboardMode << endl;
		//		cout << "Number of function keys: " << rdiDeviceInfo.keyboard.dwNumberOfFunctionKeys << endl;
		//		cout << "Number of indicators: " << rdiDeviceInfo.keyboard.dwNumberOfIndicators << endl;
		//		cout << "Number of keys total: " << rdiDeviceInfo.keyboard.dwNumberOfKeysTotal << endl;
		//		cout << "Type of the keyboard: " << rdiDeviceInfo.keyboard.dwType << endl;
		//		cout << "Subtype of the keyboard: " << rdiDeviceInfo.keyboard.dwSubType << endl;*/
		//	}

		//	// Some HID
		//	else // (rdi.dwType == RIM_TYPEHID)
		//	{
		//		
		//		FString HappyString = FString(wcDeviceName);
		//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, HappyString);
		//		// Current Device
		//		//cout << endl << "Displaying device " << i + 1 << " information. (HID)" << endl;
		//		//wcout << L"Device Name: " << wcDeviceName << endl;
		//		//cout << "Vendor Id:" << rdiDeviceInfo.hid.dwVendorId << endl;
		//		//cout << "Product Id:" << rdiDeviceInfo.hid.dwProductId << endl;
		//		//cout << "Version No:" << rdiDeviceInfo.hid.dwVersionNumber << endl;
		//		//cout << "Usage for the device: " << rdiDeviceInfo.hid.usUsage << endl;
		//		//cout << "Usage Page for the device: " << rdiDeviceInfo.hid.usUsagePage << endl;
		//	}

		//	// Delete Name Memory!
		//	delete[] wcDeviceName;
		//}

		//// Clean Up - Free Memory
		//delete[] pRawInputDeviceList;
		//*/
	/**************************************************************/
}
