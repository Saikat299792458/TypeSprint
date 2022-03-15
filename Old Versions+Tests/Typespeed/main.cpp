#define _WIN32_WINNT 0x0501
#include<windows.h>
#include"resource.h"
#include<iostream>
LRESULT CALLBACK chp(HWND h,UINT u,WPARAM w,LPARAM l)
{
    if(u==WM_LBUTTONDOWN)
    std::cout<<"Yes\n";
    return DefWindowProc(h,u,w,l);
}
LRESULT CALLBACK windpro(HWND h,UINT u,WPARAM w,LPARAM l)
{
    switch(u)
    {
    case WM_CLOSE:
        DestroyWindow(h);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(h,u,w,l);
    }
    return 0;
}
int APIENTRY WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR lpCmdLine,int nCmdShow)
{
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra=0;
    wc.cbWndExtra=0;
    wc.lpfnWndProc = windpro;
    wc.hInstance = hInst;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = "main";
    wc.hCursor = LoadCursor(0, IDC_ARROW);
    wc.hIcon=LoadIcon(NULL,IDI_APPLICATION);
    wc.hIconSm=LoadIcon(NULL,IDI_APPLICATION);
    wc.lpszMenuName=NULL;
    RegisterClassEx(&wc);
    HWND MWhwnd = CreateWindowEx(WS_EX_LAYERED,"main","Saikat",
       WS_OVERLAPPEDWINDOW| WS_CLIPCHILDREN,
       CW_USEDEFAULT,CW_USEDEFAULT, CW_USEDEFAULT,CW_USEDEFAULT,
       NULL, NULL, hInst, NULL);
    wc.lpfnWndProc =chp;
    wc.lpszClassName ="CPanel";
    wc.style =0;
    wc.hIcon=NULL;
    wc.hIconSm=NULL;
    RegisterClassEx(&wc);
    HWND Panelhwnd = CreateWindowEx(WS_EX_LAYERED,"CPanel","",
       WS_VISIBLE | WS_CHILD | WS_CLIPSIBLINGS| WS_CLIPCHILDREN,
       0,0, 400, 400, MWhwnd, NULL, hInst, NULL);
    SetLayeredWindowAttributes(Panelhwnd,0, 255, LWA_ALPHA);
    ShowWindow(MWhwnd, nCmdShow);
    UpdateWindow(MWhwnd);
    MSG i;
    while(GetMessage(&i,NULL,0,0)>0)
    {
        TranslateMessage(&i);
        DispatchMessage(&i);
    }
    return 0;
}
