#include <wininet.h>
#include <windows.h>
#include <process.h>



void AMyActor::Download(FString MediaSource)
{
	char szAppname[MAX_PATH] = "FTP";
	char szServer[MAX_PATH] = "ipaddress";
	char szPort[MAX_PATH] = "21";
	char szUsername[MAX_PATH] = "username";
	char szPassword[MAX_PATH] = "password";
	char szFilePath[MAX_PATH] = "FTP_filepath";  //一個反向的斜槓（）或向前斜槓（/）可以用作任何名稱的目錄分隔符
	char szFileName[MAX_PATH] = "FTP_filepath";
	char szNewFileName[MAX_PATH] = "downloadpath";

	char szCurDir[MAX_PATH] ="";
	DWORD dwCurDir = MAX_PATH;

	////cout << "嘗試開啟 hINTSession" << endl;
	HINTERNET hINTSession = InternetOpenA(szAppname, INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);//這個函式初始化一個應用程式對WinInet函式的使用
	if (hINTSession == NULL)
	{
	//	無法開啟
		return; 
	}
	//else
	//{
	//	開啟成功
	//}

	HINTERNET hFTPSession = InternetConnectA(hINTSession, szServer, INTERNET_DEFAULT_FTP_PORT, szUsername, szPassword, INTERNET_SERVICE_FTP, 0, 0); ////這個函式為指定的站點開啟一個FTP或HTTP會話
	if (hFTPSession == NULL)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ftp connect failed !!!!"));
		InternetCloseHandle(hINTSession);  //連線FTP失敗	
		return;
	}


	ZeroMemory(szCurDir, dwCurDir);
	FtpGetCurrentDirectoryA(hFTPSession, szCurDir, &dwCurDir);  //這個函式檢索指定FTP會話的當前目錄
	

	////FtpSetCurrentDirectory 這個函式會更改FTP伺服器上的不同工作目錄
	BOOL bsuccess;
	bsuccess = FtpSetCurrentDirectoryA(hFTPSession, szFilePath);
	if (!bsuccess)
	{
		InternetCloseHandle(hINTSession);
		InternetCloseHandle(hFTPSession);
		//cout << "更改目錄失敗!" << endl;
		return ;
	}


	//cout << "開始獲取檔案" << endl;
	//FtpGetFile 這個函式從FTP伺服器檢索一個檔案，並將其儲存在指定的檔名下，在此過程中建立一個新的本地檔案
	//BOOL bFTPRet = FtpGetFileA(hFTPSession, szFileName, szNewFileName, false, FILE_ATTRIBUTE_NORMAL, FTP_TRANSFER_TYPE_BINARY, 0);
	BOOL bFTPRet = FtpGetFileA(hFTPSession, szFileName, "C:\\Asclepius_Anatomy\\AsclepiusAlpha\\Content\\VTS_18_1.mp4", false, FILE_ATTRIBUTE_NORMAL, FTP_TRANSFER_TYPE_BINARY, 0);
	if (!bFTPRet)
	{
		//cout << "下載檔案失敗!" << endl;
		//cout << GetLastError() << endl;
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("download failed !!!!"));
		return;
	}

	//關閉控制代碼
	InternetCloseHandle(hINTSession);
	InternetCloseHandle(hFTPSession);

	
	return ;
}
