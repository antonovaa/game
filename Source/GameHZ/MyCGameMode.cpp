#include "GameHZ.h"
#include "MyCGameMode.h"
#include "Windows.h"


void AMyCGameMode::StartServ(int port)
{
	char *ch = "-log -port=";
	char ch7[5];
	char slovo[16];
	_itoa_s(port, ch7, 10);
	strcpy_s(slovo, ch);
	strcat_s(slovo, ch7);

	ShellExecuteA(
		NULL,
		"open",
		"GameHZServer.exe",
		slovo,
		"E:\\Unreal_About\\GameHZ\\Binaries\\Win64\\",
		SW_SHOWNORMAL);
	//std::ofstream ffout("E:\\dro.txt");
	//ffout << GetLastError;
	//fclose(ffout);
	//MessageBox(NULL,"Error launching Calculator");
	//ShellExecuteA(NULL,"open","LoseRealServer.exe","-log -port="+strName,"G:\\GameFull\\WindowsNoEditor\\LoseReal\\Binaries\\Win64\\",SW_SHOWNORMAL);
}
