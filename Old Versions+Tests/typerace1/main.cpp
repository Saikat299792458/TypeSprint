#include<windows.h>
#include"resource.h"
#include<iostream>
using namespace std;
LRESULT CALLBACK windpro(HWND h,UINT u,WPARAM w,LPARAM l)
{
    switch(u)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    case WM_CREATE:
        CreateWindowEx(WS_EX_STATICEDGE,
                       "COMBOBOX","Saikat",
                       CBS_DROPDOWNLIST|CBS_HASSTRINGS|WS_CHILD|WS_VISIBLE,
                       0,0,100,300,h,(HMENU)ID_MB,GetModuleHandle(NULL),NULL);
        SendMessage(GetDlgItem(h,ID_MB),(UINT)CB_ADDSTRING,(WPARAM)0,(LPARAM)"Saikat");
        SendMessage(GetDlgItem(h,ID_MB),(UINT)CB_ADDSTRING,(WPARAM)0,(LPARAM)"Ela");
        SendMessage(GetDlgItem(h,ID_MB),(UINT)CB_ADDSTRING,(WPARAM)0,(LPARAM)"Bisawjit");
        SendMessage(GetDlgItem(h,ID_MB),CB_SETCURSEL,(WPARAM)1,(LPARAM)0);
        break;
    default:
        return DefWindowProc(h,u,w,l);
    }
    return 0;
}
int APIENTRY WinMain(HINSTANCE a,HINSTANCE b,LPSTR c,int d)
{
    WNDCLASSEX e;
    e.cbClsExtra=0;
    e.cbSize=sizeof(WNDCLASSEX);
    e.cbWndExtra=0;
    e.hbrBackground=CreateSolidBrush(RGB(0,255,0));
    e.hCursor=LoadCursor(NULL,IDC_ARROW);
    e.hIcon=LoadIcon(NULL,IDI_APPLICATION);
    e.hIconSm=LoadIcon(NULL,IDI_APPLICATION);
    e.hInstance=a;
    e.lpfnWndProc=windpro;
    e.lpszClassName="Saikat";
    e.lpszMenuName=NULL;
    e.style=0;
    if(!RegisterClassEx(&e))
    {
        MessageBox(NULL,"Class registration failed!","Error",0);
        return 0;
    }
    HWND h=CreateWindowEx(WS_EX_APPWINDOW,
                          "Saikat",
                          "Test Window",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          NULL,NULL,a,NULL);
    if(h==NULL)
    {
        MessageBox(NULL,"Window creation failed!","Error!",0);
        return 0;
    }
    ShowWindow(h,d);
    UpdateWindow(h);
    MSG i;
    while(GetMessage(&i,NULL,0,0)>0)
    {
        TranslateMessage(&i);
        DispatchMessage(&i);
    }
    return 0;
}
