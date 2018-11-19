/*
Nathan Taylor
11/18/18
Auto Clicker: 90.26cps Average
Start: CTRL
Stop: ALT
Terminate: DELETE
*/
#include <windows.h>

int main()
{
  while (true)
    {
      //start
      if (GetAsyncKeyState(VK_CONTROL))
	{
	  while (true)
	    {
	      mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	      mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	      Sleep(10);
	      //stop
	      if (GetAsyncKeyState(VK_MENU))
		{
		  break;
		}
	    }
	}
      //terminate
      if (GetAsyncKeyState(VK_DELETE))
	{
	  exit(0);
	}
    }
  return 0;
}
