/*
Nathan Taylor
11/18/18
1 Key Auto Clicker
On/Off: CAPSLOCK
Terminate: DELETE
 */
#include <windows.h>

int main()
{
  bool status;
  bool previous;
  while (true)
    {
      if (!previous && GetAsyncKeyState(VK_CAPITAL))
	{
	  status = !status;
	}
      previous = GetAsyncKeyState(VK_CAPITAL);

      if (status)
	{
	  mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	  mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	  Sleep(10);
	}
      //terminate
      if (GetAsyncKeyState(VK_DELETE))
	{
	  exit(0);
	}
    }
  return 0;
}
