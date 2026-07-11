#include "Exception.h"

void ExceptionInit()
{
    // TODO: восстановить из оригинального сервера
    // не факт что это ввобще нужно
    /*
    void __cdecl exception_init()
{
  HANDLE hObject; // [esp+0h] [ebp-4h]

  if ( mailServer )
  {
    hObject = CreateFileA(&FileName, 0x80000000, 0, 0, 3u, 0, 0);
    if ( hObject != (HANDLE)-1 )
    {
      CloseHandle(hObject);
      sub_416486(mailServer, (int)aServerNcsoftCo_1, aDarkangelNcsof_1, &FileName);
      DeleteFileA(&FileName);
    }
  }
}
    */
}