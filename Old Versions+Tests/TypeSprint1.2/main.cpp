#include<windows.h>
#include"resource.h"
#include<bits/stdc++.h>
using namespace std;
HFONT f1,f2,f3,f4;
HWND hm=NULL;
int b=0,v,i=0,k,hv=200,sz[5],pd=200,n,s,wc=0,tc=9,inc=-1,ds=-1,hd,hq,we,wt,wa,wg,t2,line,nb,nc,pm;
int con=0,tuc1,tuc2,ac=1,ind=0,down,bil,knil,ymin=0,ymax=0,ycur=0,tmp,nut;
char ch,wrd[20],gen[]="Test your typing speed anytime, anywhere! Navigate in the main menu \
for your desired options, Hit 'Enter' whenever you're ready to race. Press 'Esc' to terminate an ongoing sprint.\
The average calculation corresponds to a simple equation so keep your initial speed up to get a boost in the average speed. \
Your score of a successful race is automatically recorded. More new fonts and text orientation will be added in the next version. \
The continuum continues.";
char anne[]="Anne Frank(1929-1945)",robins[]="Harold Robbins(1916-1997)",sheldon[]="Sidney Sheldon(1917-2007)";
char fonts[5][30]={"Times New Roman","Ebrima","Chiller","Calibri","IMPACT"};
char scores[6][1000];
POINT cp,rp,wp;
SCROLLINFO si;
TRACKMOUSEEVENT tme;
MINMAXINFO mima;
COLORREF crf1=RGB(240,240,240);
HWND hh=NULL;
float av,dv;
char a[5][200],wn[5]="0",tn[6]="00:09",buf[5];
HDC h1,h2,he;
bool wr=false,cbcon=true,tcont=true,tstart=true,wcb=false,did_race_end=false,meridian=false,mousein=false,pdone=false;
bool rad[2]={true,false};
string mode,f;
const UINT ret=1,strt=2;
RECT rm,re;
HBITMAP hbg=NULL,hb1,hb2,hb3,hb4,hbt,hbw,hcb1,hcb2,hcbw,hback,hanne,hrobins,hsheldon,hlogo,hmod,spe1;
BOOL CALLBACK dlgpro(HWND h,UINT u,WPARAM w,LPARAM l)
{
    switch(u)
    {
    case WM_INITDIALOG:
        {
        char dlgshow[]="Your Average: ";
        strcat(dlgshow,wn);
        strcat(dlgshow,"WPM");
        SetDlgItemText(h,ST2,dlgshow);
        if(did_race_end==false)
        SetDlgItemText(h,ST1,"Time's Up!");
        else
            SetDlgItemText(h,ST1,"Race Ended!");
        }
        return true;
    case WM_COMMAND:
        switch(LOWORD(w))
        {
        case ID_RETRY:
            EndDialog(h,ID_RETRY);
            break;
        case ID_MM:
            EndDialog(h,ID_MM);
            break;
        }
        break;
        default:
            return false;
    }
    return true;
}
LRESULT CALLBACK infpro(HWND h,UINT u,WPARAM w,LPARAM l)
{
    switch(u)
    {
    case WM_PAINT:
        {

            PAINTSTRUCT ps;
            HDC hspe=BeginPaint(h,&ps);
            HDC hg=CreateCompatibleDC(0);
            RECT r1;
            GetClientRect(h,&r1);
            if(pdone==false)
            {
            BITMAP ba,bh,bs;
            down=0;tuc2=0;
            GetObject(hanne,sizeof(ba),&ba);
            GetObject(hrobins,sizeof(bh),&bh);
            GetObject(hsheldon,sizeof(bs),&bs);
            f3=CreateFont(-int(dv),0,0,0,0,0,0,0,0,0,0,0,0,fonts[ind]);
            f4=CreateFont(-int(av),0,0,0,0,0,0,0,0,0,0,0,0,fonts[ind]);
            HDC ha=CreateCompatibleDC(0),hh=CreateCompatibleDC(0),hs=CreateCompatibleDC(0);
            SelectObject(ha,hanne);
            SelectObject(hh,hrobins);
            SelectObject(hs,hsheldon);
            RECT rc;
            rc=r1;
            spe1=CreateCompatibleBitmap(hspe,r1.right,nut);
            SelectObject(hg,spe1);
            SetRect(&r1,0,0,r1.right,nut);
            FillRect(hg,&r1,CreateSolidBrush(crf1));
            SelectObject(hg,f3);
            SetBkMode(hg,TRANSPARENT);
            SetTextColor(hg,RGB(0,0,0));
            SetRect(&r1,0,down,r1.right,r1.bottom);
            DrawText(hg,"General:",8,&r1,DT_LEFT);
            int comb=r1.right-(pm*205/235)-(pm*176/235)-(pm*160/235),div=0;
            down+=nb;
            SelectObject(hg,f1);
            SetRect(&r1,0,down,r1.right,r1.bottom);
            DrawText(hg,gen,sizeof(gen),&r1,DT_WORDBREAK);
            down+=(7*hd);
            SelectObject(hg,f3);
            SetRect(&r1,0,down,r1.right,r1.bottom);
            DrawText(hg,"Dedicated to:",13,&r1,DT_LEFT);
            SelectObject(hg,f4);
            down+=hq;
            div=comb/4;
            StretchBlt(hg,div,down,pm*205/235,pm,ha,0,0,ba.bmWidth,ba.bmHeight,SRCCOPY);
            for(int i=0;anne[i]!='\0';i++)
            {
                GetCharWidth32(hg,(UINT)anne[i],(UINT)anne[i],&tuc1);
                tuc2+=tuc1;
            }
            TextOut(hg,div+(pm*205/235)/2-tuc2/2,down+pm,anne,sizeof(anne));
            div+=pm*205/235;div+=comb/4;
            StretchBlt(hg,div,down,pm*176/235,pm,hh,0,0,bh.bmWidth,bh.bmHeight,SRCCOPY);
            tuc2=0;
            for(int i=0;robins[i]!='\0';i++)
            {
                GetCharWidth32(hg,(UINT)robins[i],(UINT)robins[i],&tuc1);
                tuc2+=tuc1;
            }
            TextOut(hg,div+(pm*176/235)/2-tuc2/2,down+pm,robins,sizeof(robins));
            div+=pm*160/235;div+=comb/4;
            StretchBlt(hg,div,down,pm*160/235,pm,hs,0,0,bs.bmWidth,bs.bmHeight,SRCCOPY);
            tuc2=0;
            for(int i=0;sheldon[i]!='\0';i++)
            {
                GetCharWidth32(hg,(UINT)sheldon[i],(UINT)sheldon[i],&tuc1);
                tuc2+=tuc1;
            }
            TextOut(hg,div+(pm*160/235)/2-tuc2/2,down+pm,sheldon,sizeof(sheldon));
            down+=pm;down+=nc*2;
            SelectObject(hg,f3);
            TextOut(hg,0,down,"Legal:",6);
            down+=nb;
            SelectObject(hg,f4);
            TextOut(hg,0,down,"App version:1.2.0",17);
            down+=nc;
            TextOut(hg,0,down,"Copyright © 2020 Saikat1803005",30);
            down+=nc;
            TextOut(hg,0,down,"saikatchakraborty4444@gmail.com",31);
            down+=nc;
            DeleteDC(ha);
            DeleteDC(hh);
            DeleteDC(hs);
            pdone=true;
            }
            else
                SelectObject(hg,spe1);
            BitBlt(hspe,0,0-ycur,r1.right,nut,hg,0,0,SRCCOPY);
            EndPaint(h,&ps);
            DeleteDC(hg);
        }
        break;
    case WM_MOUSEWHEEL:
        {
            ycur-=(GET_WHEEL_DELTA_WPARAM(w)/2);
            if(ycur<0)
                ycur=0;
            if(ycur>ymax)
                ycur=ymax;
            si.cbSize = sizeof(si);
            si.fMask  = SIF_POS;
            si.nPos   = ycur;
            SetScrollInfo(h, SB_VERT, &si, TRUE);
            InvalidateRect(h,NULL,0);
        }
        break;
    case WM_VSCROLL:
        {
            int xDelta=0;
            int yDelta;
            int yNewPos;
            switch (LOWORD(w))
            {
                case SB_PAGEUP:
                    yNewPos = ycur - 50;
                    break;
                case SB_PAGEDOWN:
                    yNewPos = ycur + 50;
                    break;
                case SB_LINEUP:
                    yNewPos = ycur - 5;
                    break;
                case SB_LINEDOWN:
                    yNewPos = ycur + 5;
                    break;
                case SB_THUMBPOSITION:
                    yNewPos = HIWORD(w);
                    break;
                default:
                    yNewPos=ycur;
            }
            yNewPos=max(0,yNewPos);
            yNewPos=min(ymax, yNewPos);
            if(yNewPos==ycur)
                break;
            yDelta=yNewPos-ycur;
            ycur=yNewPos;
            ScrollWindowEx(h,-xDelta,-yDelta,(CONST RECT*)NULL,
                (CONST RECT *)NULL,(HRGN)NULL,(PRECT)NULL,
                SW_INVALIDATE);
            UpdateWindow(h);
            si.cbSize=sizeof(si);
            si.fMask=SIF_POS;
            si.nPos=ycur;
            SetScrollInfo(h,SB_VERT,&si,TRUE);
            break;
        }
    default:
        return DefWindowProc(h,u,w,l);
    }
    return 0;
}
void SetButtonLayer(int b,HWND h)
{
    HDC hbt=GetDC(h);
    RECT r1,r3;
    GetClientRect(h,&r1);
    r3=r1;
    switch(b)
    {
    case 1:
        FillRect(hbt,&r1,CreateSolidBrush(RGB(255,255,255)));
        break;
    case 0:
        FillRect(hbt,&r1,CreateSolidBrush(RGB(220,220,220)));
        break;
    case 2:
        FillRect(hbt,&r1,CreateSolidBrush(RGB(180,180,180)));
        break;
    case 3:
    case 4:
        FillRect(hbt,&r1,CreateSolidBrush(crf1));
        break;
    }
    if(mode=="mnd")
    {
    HFONT fs=CreateFont(-r1.bottom*2/3,0,0,0,0,0,0,0,0,0,0,0,0,fonts[ind]);
    SelectObject(hbt,fs);
    SetBkMode(hbt,TRANSPARENT);
    SetTextColor(hbt,RGB(0,0,0));
    DrawText(hbt,f.c_str(),f.size(),&r1,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
    }
    else
    {
        if(f=="Back")
        {
            BITMAP bmp,bmp2;
                HDC hd1=CreateCompatibleDC(0),hdbw=CreateCompatibleDC(0),hjn=CreateCompatibleDC(0);
                HBITMAP fjn;
            SelectObject(hd1,hback);
                GetObject(hback,sizeof(bmp),&bmp);
                fjn=CreateCompatibleBitmap(hbt,42,44);
                SelectObject(hjn,fjn);
                StretchBlt(hjn,0,0,r1.right,r1.bottom,hd1,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
            GetObject(fjn,sizeof(bmp2),&bmp2);
                hbw=CreateBitmap(bmp2.bmWidth,bmp2.bmHeight,1,1,NULL);
                SetBkColor(hjn,RGB(0,0,0));
                SelectObject(hdbw,hbw);
                BitBlt(hdbw,0,0,bmp2.bmWidth,bmp2.bmHeight,hjn,0,0,SRCCOPY);
                BitBlt(hbt,0,0,r1.right,r1.bottom,hdbw,0,0,SRCAND);
                BitBlt(hbt,0,0,r1.right,r1.bottom,hjn,0,0,SRCPAINT);
                DeleteDC(hjn);
                DeleteDC(hd1);
                DeleteDC(hdbw);
        }
        if(mode=="Set")
        {
        if(f=="STC")
        {
            HFONT fs=CreateFont(-r1.bottom*2/3,0,0,0,0,0,0,0,0,0,0,0,0,fonts[ind]);
            BITMAP bmp,bmp2;
                HDC hd1=CreateCompatibleDC(0),hdbw=CreateCompatibleDC(0),hjn=CreateCompatibleDC(0);
                HBITMAP fjn;
                if(cbcon==true)
                    SelectObject(hd1,hcb2);
                else
                    SelectObject(hd1,hcb1);
                GetObject(hcb1,sizeof(bmp),&bmp);
                fjn=CreateCompatibleBitmap(hbt,r1.bottom,r1.bottom);
                SelectObject(hjn,fjn);
                StretchBlt(hjn,0,0,r1.bottom,r1.bottom,hd1,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
                GetObject(fjn,sizeof(bmp2),&bmp2);
                hbw=CreateBitmap(bmp2.bmWidth,bmp2.bmHeight,1,1,NULL);
                SetBkColor(hjn,RGB(0,0,0));
                SelectObject(hdbw,hbw);
                BitBlt(hdbw,0,0,bmp2.bmWidth,bmp2.bmHeight,hjn,0,0,SRCCOPY);
                BitBlt(hbt,0,0,r1.bottom,r1.bottom,hdbw,0,0,SRCAND);
                BitBlt(hbt,0,0,r1.bottom,r1.bottom,hjn,0,0,SRCPAINT);
                SetRect(&r1,r1.bottom,0,r1.right,r1.bottom);
                SelectObject(hbt,fs);
                SetBkMode(hbt,TRANSPARENT);
                DrawText(hbt,"Show Text Cursor",16,&r1,DT_SINGLELINE|DT_VCENTER);
                if(b==4)
                DrawFocusRect(hbt,&r3);
                DeleteDC(hjn);
                DeleteDC(hd1);
                DeleteDC(hdbw);
        }
        else if(f=="Single Line"||f=="Multi Line")
        {
            BITMAP bmp,bmp2;
            HBITMAP fjn;
                HDC hd1=CreateCompatibleDC(0),hdbw=CreateCompatibleDC(0),hjn=CreateCompatibleDC(0);
        if(f=="Single Line")
        {
            if(rad[0]==true)
                    SelectObject(hd1,hcb2);
                else
                    SelectObject(hd1,hcb1);
        }
        else
        {
            if(rad[1]==true)
                    SelectObject(hd1,hcb2);
                else
                    SelectObject(hd1,hcb1);
        }
        GetObject(hcb1,sizeof(bmp),&bmp);
                fjn=CreateCompatibleBitmap(hbt,r1.bottom,r1.bottom);
                SelectObject(hjn,fjn);
                StretchBlt(hjn,0,0,r1.bottom,r1.bottom,hd1,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
                GetObject(fjn,sizeof(bmp2),&bmp2);
                hbw=CreateBitmap(bmp2.bmWidth,bmp2.bmHeight,1,1,NULL);
                SetBkColor(hjn,RGB(0,0,0));
                SelectObject(hdbw,hbw);
                BitBlt(hdbw,0,0,bmp2.bmWidth,bmp2.bmHeight,hjn,0,0,SRCCOPY);
                BitBlt(hbt,0,0,r1.bottom,r1.bottom,hdbw,0,0,SRCAND);
                BitBlt(hbt,0,0,r1.bottom,r1.bottom,hjn,0,0,SRCPAINT);
                SetRect(&r1,r1.bottom,0,r1.right,r1.bottom);
        HFONT fs=CreateFont(-r1.bottom*2/3,0,0,0,0,0,0,0,0,0,0,0,0,fonts[ind]);
        SelectObject(hbt,fs);
        SetBkMode(hbt,TRANSPARENT);
        SetTextColor(hbt,RGB(0,0,0));
        DrawText(hbt,f.c_str(),f.size(),&r1,DT_SINGLELINE|DT_VCENTER);
        if(b==4)
            DrawFocusRect(hbt,&r3);
        DeleteDC(hjn);
                DeleteDC(hd1);
                DeleteDC(hdbw);
        }
        }
    }
    ReleaseDC(h,hbt);
}
void destroyer();
void mnd()
{
    mode="mnd";
    CreateWindowEx(WS_EX_APPWINDOW,
                   "BS1","Start",
                   WS_CHILD|WS_VISIBLE,
                   0,0,0,0,hm,(HMENU)ID_B1,GetModuleHandle(NULL),NULL);
    CreateWindowEx(WS_EX_APPWINDOW,
                   "BS2","Settings",
                   WS_CHILD|WS_VISIBLE,
                   0,0,0,0,hm,(HMENU)ID_B2,GetModuleHandle(NULL),NULL);
    CreateWindowEx(WS_EX_APPWINDOW,
                   "BS3","High Scores",
                   WS_CHILD|WS_VISIBLE,
                   0,0,0,0,hm,(HMENU)ID_B3,GetModuleHandle(NULL),NULL);
    CreateWindowEx(WS_EX_APPWINDOW,
                   "BS4","Info",
                   WS_CHILD|WS_VISIBLE,
                   0,0,0,0,hm,(HMENU)ID_B4,GetModuleHandle(NULL),NULL);
    SendMessage(hm,WM_SIZE,0,0);
}
void settings()
{
    CreateWindowEx(WS_EX_APPWINDOW,
                   "Set1","SETTEXTCURSOR",
                   WS_CHILD|WS_VISIBLE,
                   0,0,0,0,hm,(HMENU)ID_TCU,GetModuleHandle(NULL),NULL);
    CreateWindowEx(WS_EX_APPWINDOW,
                   "Back","Back",
                   WS_CHILD|WS_VISIBLE,
                   0,0,0,0,hm,(HMENU)ID_BACK,GetModuleHandle(NULL),NULL);
    CreateWindowEx(WS_EX_APPWINDOW,
                   "radio11","Singleline",
                   WS_CHILD|WS_VISIBLE,
                   0,0,0,0,hm,(HMENU)ID_RAD11,GetModuleHandle(NULL),NULL);
    CreateWindowEx(WS_EX_APPWINDOW,
                   "radio12","multiline",
                   WS_CHILD|WS_VISIBLE,
                   0,0,0,0,hm,(HMENU)ID_RAD12,GetModuleHandle(NULL),NULL);
    SendMessage(hm,WM_SIZE,0,0);
}
void highscore()
{
    CreateWindowEx(WS_EX_APPWINDOW,
                   "Back","Back",
                   WS_CHILD|WS_VISIBLE,
                   0,0,0,0,hm,(HMENU)ID_BACK,GetModuleHandle(NULL),NULL);
    SendMessage(hm,WM_SIZE,0,0);
}
void info()
{
    CreateWindowEx(WS_EX_APPWINDOW,
                   "Back","Back",
                   WS_CHILD|WS_VISIBLE,
                   0,0,0,0,hm,(HMENU)ID_BACK,GetModuleHandle(NULL),NULL);
    CreateWindowEx(WS_EX_APPWINDOW,
                   "InfoScroll","",
                   WS_CHILD|WS_VISIBLE|WS_VSCROLL,
                   0,0,0,0,hm,(HMENU)ID_INFSTAT,GetModuleHandle(NULL),NULL);
    SendMessage(hm,WM_SIZE,0,0);
}
void kick()
{
    int n;
    string spos;
    ifstream d1("pos.txt");
    getline(d1,spos);
    d1.close();
    stringstream(spos)>>n;
        n=0;
    int k=0;
    ifstream d2("Data.txt");
    while(!d2.eof())
    {
        getline(d2,spos);
        if(k<n)
        {
            k++;
            continue;
        }
        if(k>=n+5||spos=="")
            break;
        strcpy(a[k-n],spos.c_str());
        k++;
    }
    d2.close();
    ofstream d3("pos.txt");
    d3<<(k+1);
    line=k-n;
    d3.close();
    for(int q=0;q<line;q++)
            {
                sz[q]=0;
                for(int g=0;a[q][g]!='\0';g++)
                    sz[q]++;
            }
    SendMessage(hm,WM_SIZE,0,0);
    SetTimer(hm,ret,1000,NULL);
}
void kickdlg(HWND h)
{
    KillTimer(h,ret);
    HideCaret(h);
    DestroyCaret();
    int rv=DialogBox(GetModuleHandle(NULL),MAKEINTRESOURCE(ID_DLG),h,dlgpro);
    destroyer();
    b=0;i=0;hv=200;pd=200;wc=0;tc=9;inc=-1;ds=-1,ac=1;
    wn[0]='0';wn[1]='\0';wn[2]='\0';wn[3]='\0';
    strcpy(tn,"00:09");
    cp.x=0;cp.y=0;
    rp.x=0;rp.y=0;
    con=0,wcb=false;
    for(int i=0;wrd[i]!='\0';i++)
    wrd[i]='\0';
    wp.x=-1;wp.y=-1;
    if(rv==ID_RETRY)
    {
        mode="kick";
        kick();
    }
    else
    {
        mnd();
    }
}
void race()
{
    mode="race";
    CreateWindowEx(WS_EX_CLIENTEDGE,
                           "eb","",
                           WS_CHILD|WS_VISIBLE,
                           0,0,0,0,hm,(HMENU)EDIT1,GetModuleHandle(NULL),NULL);
    SendMessage(hm,WM_SIZE,0,0);
}
void draw(COLORREF cr1,COLORREF crp,char x,char y,char z)
{
    int m;
    GetCharWidth32(h1,(UINT)x,(UINT)x,&m);
    SetBkMode(h1,OPAQUE);
    SetBkColor(h1,crf1);
    if(x==' '&&GetRValue(cr1)==255)
    {
        SetBkColor(h1,RGB(255,0,0));
        TextOut(h1,b,pd,&x,1);
    }
    else
    {
    SetTextColor(h1,cr1);
    TextOut(h1,b,pd,&x,1);
    }
    SetBkMode(h1,TRANSPARENT);
    SetTextColor(h1,crp);
    TextOut(h1,b-v,pd,&y,1);
    SetTextColor(h1,RGB(0,0,0));
    TextOut(h1,b+m,pd,&z,1);
}
void dre(HWND h)
{
    he=GetDC(h);
    SelectObject(he,f1);
    GetClientRect(h,&re);
    FillRect(he,&re,(HBRUSH)0);
    DrawText(he,wrd,con,&re,DT_CENTER);
    ReleaseDC(h,he);
}
void destroyer()
{
    DestroyWindow(GetDlgItem(hm,ID_B1));
    DestroyWindow(GetDlgItem(hm,ID_B2));
    DestroyWindow(GetDlgItem(hm,ID_B3));
    DestroyWindow(GetDlgItem(hm,ID_B4));
    DestroyWindow(GetDlgItem(hm,ST1));
    DestroyWindow(GetDlgItem(hm,ST2));
    DestroyWindow(GetDlgItem(hm,EDIT1));
    DestroyWindow(GetDlgItem(hm,ID_BACK));
    DestroyWindow(GetDlgItem(hm,ID_TCU));
    DestroyWindow(GetDlgItem(hm,ID_INFSTAT));
    DestroyWindow(GetDlgItem(hm,ID_COMBO1));
    DestroyWindow(GetDlgItem(hm,ID_RAD11));
    DestroyWindow(GetDlgItem(hm,ID_RAD12));
    SetTextColor(h1,RGB(0,0,0));
    if(mode=="kick")
        kick();
    else if(mode=="Set")
        settings();
    else if(mode=="HS")
        highscore();
    else if(mode=="Info")
        info();
    else if(mode=="mnd")
        mnd();
}
LRESULT CALLBACK BS1(HWND h,UINT u,WPARAM w,LPARAM l)
{
    switch(u)
    {
    case WM_MOUSEMOVE:
        if(mousein==false)
        {
            f="Start";
            SetButtonLayer(0,h);
            tme.hwndTrack=h;
            TrackMouseEvent(&tme);
            mousein=true;
        }
        break;
    case WM_MOUSELEAVE:
        SetButtonLayer(1,h);
        mousein=false;
        break;
    case WM_LBUTTONDOWN:
        SetButtonLayer(2,h);
        break;
    case WM_LBUTTONUP:
        SetButtonLayer(0,h);
        mousein=false;
        mode="kick";
        destroyer();
        break;
    default:
        return DefWindowProc(h,u,w,l);
    }
    return 0;
}
LRESULT CALLBACK BS2(HWND h,UINT u,WPARAM w,LPARAM l)
{
    switch(u)
    {
    case WM_MOUSEMOVE:
        if(mousein==false)
        {
            f="Settings";
            SetButtonLayer(0,h);
            tme.hwndTrack=h;
            TrackMouseEvent(&tme);
            mousein=true;
        }
        break;
    case WM_MOUSELEAVE:
        SetButtonLayer(1,h);
        mousein=false;
        break;
    case WM_LBUTTONDOWN:
        SetButtonLayer(2,h);
        break;
    case WM_LBUTTONUP:
        SetButtonLayer(0,h);
        mousein=false;
        mode="Set";
        destroyer();
        break;
    default:
        return DefWindowProc(h,u,w,l);
    }
    return 0;
}LRESULT CALLBACK BS3(HWND h,UINT u,WPARAM w,LPARAM l)
{
    switch(u)
    {
    case WM_MOUSEMOVE:
        if(mousein==false)
        {
            f="High Scores";
            SetButtonLayer(0,h);
            tme.hwndTrack=h;
            TrackMouseEvent(&tme);
            mousein=true;
        }
        break;
    case WM_MOUSELEAVE:
        SetButtonLayer(1,h);
        mousein=false;
        break;
    case WM_LBUTTONDOWN:
        SetButtonLayer(2,h);
        break;
    case WM_LBUTTONUP:
        SetButtonLayer(0,h);
        mousein=false;
        mode="HS";
        destroyer();
        break;
    default:
        return DefWindowProc(h,u,w,l);
    }
    return 0;
}LRESULT CALLBACK BS4(HWND h,UINT u,WPARAM w,LPARAM l)
{
    switch(u)
    {
    case WM_MOUSEMOVE:
        if(mousein==false)
        {
            f="Info";
            SetButtonLayer(0,h);
            tme.hwndTrack=h;
            TrackMouseEvent(&tme);
            mousein=true;
        }
        break;
    case WM_MOUSELEAVE:
        SetButtonLayer(1,h);
        mousein=false;
        break;
    case WM_LBUTTONDOWN:
        SetButtonLayer(2,h);
        break;
    case WM_LBUTTONUP:
        SetButtonLayer(0,h);
        mousein=false;
        mode="Info";
        destroyer();
        break;
    default:
        return DefWindowProc(h,u,w,l);
    }
    return 0;
}
LRESULT CALLBACK Backpro(HWND h,UINT u,WPARAM w,LPARAM l)
{
    switch(u)
    {
    case WM_MOUSEMOVE:
        if(mousein==false)
        {
            f="Back";
            SetButtonLayer(0,h);
            tme.hwndTrack=h;
            TrackMouseEvent(&tme);
            mousein=true;
        }
        break;
    case WM_MOUSELEAVE:
        SetButtonLayer(3,h);
        mousein=false;
        break;
    case WM_LBUTTONDOWN:
        SetButtonLayer(2,h);
        break;
    case WM_LBUTTONUP:
        SetButtonLayer(0,h);
        mousein=false;
        mode="mnd";
        destroyer();
        break;
    default:
        return DefWindowProc(h,u,w,l);
    }
    return 0;
}
LRESULT CALLBACK Set1(HWND h,UINT u,WPARAM w,LPARAM l)
{
    switch(u)
    {
    case WM_MOUSEMOVE:
        if(mousein==false)
        {
            f="STC";
            SetButtonLayer(4,h);
            tme.hwndTrack=h;
            TrackMouseEvent(&tme);
            mousein=true;
        }
        break;
    case WM_MOUSELEAVE:
        SetButtonLayer(3,h);
        mousein=false;
        break;
    case WM_LBUTTONDOWN:
        SetButtonLayer(2,h);
        break;
    case WM_LBUTTONUP:
        mousein=false;
        if(cbcon==false)
            cbcon=true;
        else
            cbcon=false;
        SetButtonLayer(4,h);
        break;
    default:
        return DefWindowProc(h,u,w,l);
    }
    return 0;
}
LRESULT CALLBACK radio11(HWND h,UINT u,WPARAM w,LPARAM l)
{
    switch(u)
    {
    case WM_MOUSEMOVE:
        if(mousein==false)
        {
            f="Single Line";
            SetButtonLayer(4,h);
            tme.hwndTrack=h;
            TrackMouseEvent(&tme);
            mousein=true;
        }
        break;
    case WM_MOUSELEAVE:
        SetButtonLayer(3,h);
        mousein=false;
        break;
    case WM_LBUTTONDOWN:
        f="Single Line";
        SetButtonLayer(2,h);
        break;
    case WM_LBUTTONUP:
        mousein=false;
        if(!rad[0])
        rad[0]=0;rad[1]=1;
        SetButtonLayer(4,h);
        f="Multi Line";
        SetButtonLayer(3,GetDlgItem(hm,ID_RAD12));
        MessageBox(NULL,"Still Working on it!","Sorry!",MB_OK|MB_ICONASTERISK);
        break;
    default:
        return DefWindowProc(h,u,w,l);
    }
    return 0;
}
LRESULT CALLBACK radio12(HWND h,UINT u,WPARAM w,LPARAM l)
{
    switch(u)
    {
    case WM_MOUSEMOVE:
        if(mousein==false)
        {
            f="Multi Line";
            SetButtonLayer(4,h);
            tme.hwndTrack=h;
            TrackMouseEvent(&tme);
            mousein=true;
        }
        break;
    case WM_MOUSELEAVE:
        SetButtonLayer(3,h);
        mousein=false;
        break;
    case WM_LBUTTONDOWN:
        f="Multi Line";
        SetButtonLayer(2,h);
        break;
    case WM_LBUTTONUP:
        mousein=false;
        if(!rad[1])
        rad[0]=0;rad[1]=1;
        SetButtonLayer(4,h);
        f="Single Line";
        SetButtonLayer(3,GetDlgItem(hm,ID_RAD11));
        MessageBox(NULL,"In the next version, I promise.","Sorry!",MB_OK|MB_ICONASTERISK);
        break;
    default:
        return DefWindowProc(h,u,w,l);
    }
    return 0;
}
LRESULT CALLBACK eb(HWND h,UINT u,WPARAM w,LPARAM l)
{
    switch(u)
    {
    default:
        return DefWindowProc(h,u,w,l);
    }
    return 0;
}
LRESULT CALLBACK windpro(HWND h,UINT u,WPARAM w,LPARAM l)
{
    switch(u)
    {
    case WM_CLOSE:
        ReleaseDC(h,h1);
        {
            ofstream ms("Scores.txt");
            for(int i=0;i<5;i++)
                {
                    ms<<scores[i];
                    ms<<"\n";
                }
            ms.close();
            ofstream ma("Assets.txt");
            ma<<ind<<"\n"<<cbcon<<"\n"<<rad[0];
            ma.close();
        }
        DestroyWindow(h);
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_GETMINMAXINFO:
        {
            LPMINMAXINFO mmi=(LPMINMAXINFO)l;
            mmi->ptMinTrackSize.x=500;
            mmi->ptMinTrackSize.y=300;
        }
        break;
    case WM_CREATE:
        tme.cbSize=sizeof(tme);
        tme.dwFlags=TME_LEAVE;
        tme.dwHoverTime=HOVER_DEFAULT;
        hm=h;
        hbg=LoadBitmap(GetModuleHandle(NULL),MAKEINTRESOURCE(ID_BG));
        hb1=LoadBitmap(GetModuleHandle(NULL),MAKEINTRESOURCE(ID_START));
        hb2=LoadBitmap(GetModuleHandle(NULL),MAKEINTRESOURCE(ID_SETTINGS));
        hb3=LoadBitmap(GetModuleHandle(NULL),MAKEINTRESOURCE(ID_HS));
        hb4=LoadBitmap(GetModuleHandle(NULL),MAKEINTRESOURCE(ID_INFO));
        hcb1=LoadBitmap(GetModuleHandle(NULL),MAKEINTRESOURCE(ID_CB1));
        hcb2=LoadBitmap(GetModuleHandle(NULL),MAKEINTRESOURCE(ID_CB2));
        hback=LoadBitmap(GetModuleHandle(NULL),MAKEINTRESOURCE(ID_BACK));
        hanne=LoadBitmap(GetModuleHandle(NULL),MAKEINTRESOURCE(ID_ANNE));
        hrobins=LoadBitmap(GetModuleHandle(NULL),MAKEINTRESOURCE(ID_ROBINS));
        hsheldon=LoadBitmap(GetModuleHandle(NULL),MAKEINTRESOURCE(ID_SHELDON));
        hlogo=LoadBitmap(GetModuleHandle(NULL),MAKEINTRESOURCE(ID_LOGO));
        hmod=LoadBitmap(GetModuleHandle(NULL),MAKEINTRESOURCE(ID_MOD));
        break;
    case WM_MEASUREITEM:
        {
            LPMEASUREITEMSTRUCT lpm=LPMEASUREITEMSTRUCT(l);
            lpm->itemHeight=hd;
        }
        break;
    case WM_DRAWITEM:
        {
            LPDRAWITEMSTRUCT lpd=LPDRAWITEMSTRUCT(l);
            if(lpd->itemState&&ODS_FOCUS)
                {
                    FillRect(lpd->hDC,&lpd->rcItem,CreateSolidBrush(crf1));
                    DrawFocusRect(lpd->hDC,&lpd->rcItem);
                }
            else
                FillRect(lpd->hDC,&lpd->rcItem,CreateSolidBrush(RGB(255,255,255)));
            HFONT fsp=CreateFont(-hd*2/3,0,0,0,0,0,0,0,0,0,0,0,0,fonts[lpd->itemID]);
            SelectObject(lpd->hDC,fsp);
            SetBkMode(lpd->hDC,TRANSPARENT);
            SetTextColor(lpd->hDC,RGB(0,0,0));
            DrawText(lpd->hDC,fonts[lpd->itemID],string(fonts[lpd->itemID]).size(),&lpd->rcItem,DT_SINGLELINE|DT_VCENTER);
        }
        break;
    case WM_COMMAND:
        if(HIWORD(w)==CBN_SELCHANGE)
            {
                ind=SendMessage(GetDlgItem(h,ID_COMBO1),CB_GETCURSEL,0,0);
                SendMessage(h,WM_SIZE,0,0);
            }
        break;
        case WM_CTLCOLORSTATIC:
            dre(GetDlgItem(h,EDIT1));
            break;
    case WM_SIZE:
        {
            GetClientRect(h,&rm);
            DestroyCaret();
            h1=GetDC(h);
            //FillRect(h1,&rm,(HBRUSH)0);
            FillRect(h1,&rm,CreateSolidBrush(crf1));
            hh=NULL;
            float ad=rm.right/22;
            float as=rm.right/34;
            f1=CreateFont(-int(as),0,0,0,0,0,0,0,0,0,0,0,0,fonts[ind]);
            f2=CreateFont(-int(ad),0,0,0,0,0,0,0,0,0,0,0,0,fonts[ind]);
            ad=(ad*72)/96;
            as=(as*72)/96;
            ad=ceil(ad);
            as=ceil(as);
            hq=ad+(ad/2);
            hd=as+(as/2);
            if(hq<44)
                hq=44;
            if(mode=="beg")
            {
                BITMAP bmp;
                h2=CreateCompatibleDC(0);
                HDC h2w=CreateCompatibleDC(0);
                GetObject(hmod,sizeof(bmp),&bmp);
                HBITMAP h2b=CreateBitmap(bmp.bmWidth,bmp.bmHeight,1,1,NULL);
                SelectObject(h2,hmod);
                SelectObject(h2w,h2b);
                SetBkColor(h2,RGB(0,120,215));
                BitBlt(h2w,0,0,bmp.bmWidth,bmp.bmHeight,h2,0,0,SRCCOPY);
                FillRect(h1,&rm,CreateSolidBrush(RGB(0,120,215)));
                BitBlt(h1,(rm.right-bmp.bmWidth)/2,(rm.bottom-bmp.bmHeight)/2,bmp.bmWidth,bmp.bmHeight,h2w,0,0,SRCAND);
                BitBlt(h1,(rm.right-bmp.bmWidth)/2,(rm.bottom-bmp.bmHeight)/2,bmp.bmWidth,bmp.bmHeight,h2,0,0,SRCPAINT);
                DeleteDC(h2);
                DeleteDC(h2w);
            }
            else if(mode=="mnd")
            {
                RECT r1;
                GetClientRect(h,&r1);
                SetRect(&r1,0,rm.bottom/10,rm.right,rm.bottom);
                HFONT fs=CreateFont(-rm.bottom*17/100,0,0,0,0,0,0,0,0,0,0,0,0,fonts[ind]);
                SelectObject(h1,fs);
                SetBkMode(h1,TRANSPARENT);
                SetTextColor(h1,RGB(0,0,0));
                DrawText(h1,"TypeSprint",10,&r1,DT_CENTER);
                int rx=rm.bottom/10,ry=rm.bottom*2/5;
                SetWindowPos(GetDlgItem(h,ID_B1),NULL,(rm.right-rx*4)/2,ry,rx*4,rx,SWP_NOZORDER);ry+=rx;ry+=2;
                SetWindowPos(GetDlgItem(h,ID_B2),NULL,(rm.right-rx*4)/2,ry,rx*4,rx,SWP_NOZORDER);ry+=rx;ry+=2;
                SetWindowPos(GetDlgItem(h,ID_B3),NULL,(rm.right-rx*4)/2,ry,rx*4,rx,SWP_NOZORDER);ry+=rx;ry+=2;
                SetWindowPos(GetDlgItem(h,ID_B4),NULL,(rm.right-rx*4)/2,ry,rx*4,rx,SWP_NOZORDER);
                f="Start";
                SetButtonLayer(1,GetDlgItem(h,ID_B1));
                f="Settings";
                SetButtonLayer(1,GetDlgItem(h,ID_B2));
                f="High Scores";
                SetButtonLayer(1,GetDlgItem(h,ID_B3));
                f="Info";
                SetButtonLayer(1,GetDlgItem(h,ID_B4));
            }
            else if(mode=="Set")
            {
                tuc1=0;
                DestroyWindow(GetDlgItem(h,ID_COMBO1));
                CreateWindowEx(WS_EX_APPWINDOW,
                   "COMBOBOX","Combo1",
                   WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST|CBS_HASSTRINGS|CBS_OWNERDRAWFIXED,
                   0,0,0,0,hm,(HMENU)ID_COMBO1,GetModuleHandle(NULL),NULL);
                for(int i=0;i<5;i++)
        SendMessage(GetDlgItem(hm,ID_COMBO1),(UINT)CB_ADDSTRING,(WPARAM)0,(LPARAM)fonts[i]);
                SelectObject(h1,f2);
                SetBkMode(h1,TRANSPARENT);
                DrawText(h1,"Settings",8,&rm,DT_CENTER);
                SelectObject(h1,f1);
                char pt[]="Show Text Cursor",pco[]="Font:",prad[]="Text Orientation:";
                for(int i=0;pt[i]!='\0';i++)
                {
                    GetCharWidth32(h1,(UINT)pt[i],(UINT)pt[i],&tuc2);
                    tuc1+=tuc2;
                }
                SetWindowPos(GetDlgItem(h,ID_BACK),NULL,0,0,42,44,SWP_NOZORDER);
                SetWindowPos(GetDlgItem(h,ID_TCU),NULL,0,rm.bottom/5,tuc1+60,hd,SWP_NOZORDER);
                tuc1=0;
                for(int i=0;pco[i]!='\0';i++)
                {
                    GetCharWidth32(h1,(UINT)pco[i],(UINT)pco[i],&tuc2);
                    tuc1+=tuc2;
                }
                TextOut(h1,0,rm.bottom/5+hq,pco,12);
                SetWindowPos(GetDlgItem(h,ID_COMBO1),NULL,tuc1,rm.bottom/5+hq,300,500,SWP_NOZORDER);
                SendMessage(GetDlgItem(h,ID_COMBO1),CB_SETCURSEL,(WPARAM)ind,(LPARAM)0);
                SendMessage(GetDlgItem(h,ID_COMBO1),CB_SETITEMHEIGHT,1,hd);
                InvalidateRect(GetDlgItem(h,ID_COMBO1),0,false);
                TextOut(h1,0,rm.bottom/5+hq*2,prad,sizeof(prad));
                tuc1=0;
                for(int i=0;prad[i]!='\0';i++)
                {
                    GetCharWidth32(h1,(UINT)prad[i],(UINT)prad[i],&tuc2);
                    tuc1+=tuc2;
                }
                SetWindowPos(GetDlgItem(h,ID_RAD11),NULL,tuc1,rm.bottom/5+hq*2,200,hd,SWP_NOZORDER);
                SetWindowPos(GetDlgItem(h,ID_RAD12),NULL,tuc1,rm.bottom/5+hq*2+hd,200,hd,SWP_NOZORDER);
                tstart=true;
                f="Back";
                SetButtonLayer(3,GetDlgItem(h,ID_BACK));
                f="STC";
                SetButtonLayer(3,GetDlgItem(h,ID_TCU));
                f="Single Line";
                SetButtonLayer(3,GetDlgItem(h,ID_RAD11));
                f="Multi Line";
                SetButtonLayer(3,GetDlgItem(h,ID_RAD12));
                InvalidateRect(h,0,false);
            }
            else if(mode=="HS")
            {
                SelectObject(h1,f2);
                SetBkMode(h1,TRANSPARENT);
                DrawText(h1,"High Scores",11,&rm,DT_CENTER);
                int mid=hq;mid+=hq/2;
                SelectObject(h1,f1);
                SetRect(&rm,0,mid,rm.right,rm.bottom);
                if(scores[0][0]=='\0')
                    DrawText(h1,"Get in a race first!",20,&rm,DT_CENTER);
                else
                    for(int i=0;scores[i][0]!='\0';i++)
                {
                    string cod=string(scores[i]);
                    DrawText(h1,scores[i],cod.size(),&rm,DT_CENTER);
                    mid+=hd;
                    SetRect(&rm,0,mid,rm.right,rm.bottom);
                }
                SetWindowPos(GetDlgItem(h,ID_BACK),NULL,0,0,42,44,SWP_NOZORDER);
                f="Back";
                SetButtonLayer(3,GetDlgItem(h,ID_BACK));
                InvalidateRect(h,0,false);
            }
            else if(mode=="Info")
            {
                SelectObject(h1,f2);
                SetBkMode(h1,TRANSPARENT);
                DrawText(h1,"Info",4,&rm,DT_CENTER);
                SetWindowPos(GetDlgItem(h,ID_BACK),NULL,0,0,42,44,SWP_NOZORDER);
                f="Back";
                SetButtonLayer(3,GetDlgItem(h,ID_BACK));
                SetWindowPos(GetDlgItem(h,ID_INFSTAT),NULL,2,hq,rm.right,rm.bottom-hq,SWP_NOZORDER);
                dv=rm.right/28;
                nb=ceil((dv*72)/96);
                nb=nb+(nb/2);
                av=rm.right/50;
                nc=ceil((av*72)/96);
                nc=nc+(nc/2);
                RECT ri;
                GetClientRect(GetDlgItem(h,ID_INFSTAT),&ri);
                pm=ri.right*24/100;
                down=0;
                down+=nb*2;down+=(7*hd);down+=hq;down+=pm;down+=nc*5;
                nut=down;
                ymax=max(down-int(ri.bottom),0);
                ycur=min(ycur,ymax);
                si.cbSize=sizeof(si);
                si.fMask=SIF_RANGE | SIF_PAGE | SIF_POS;
                si.nMin=ymin;
                si.nMax=down;
                si.nPage=ri.bottom;
                si.nPos=ycur;
                SetScrollInfo(GetDlgItem(h,ID_INFSTAT), SB_VERT, &si, TRUE);
                pdone=false;
                InvalidateRect(h,0,false);
            }
            else
            {
            int x,y,m,j=0,hj,hk;
            char red[50],black[70];
            COLORREF rf1;
            hv=hq*3;
            pd=hv;
            HGDIOBJ o1=SelectObject(h1,f1);
            SetTextColor(h1,RGB(0,255,0));
            SetBkMode(h1,TRANSPARENT);
            if(wp.x==-1)
            {
                for(y=0;y<cp.y;y++)
                {
                    TextOut(h1,0,hv,a[y],sz[y]);
                    hv+=hd;
                }
                TextOut(h1,0,hv,a[cp.y],cp.x);
                for(x=0;x<cp.x;x++)
                    {
                        GetCharWidth32(h1,(UINT)a[cp.y][x],(UINT)a[cp.y][x],&m);
                        j+=m;
                    }
                rf1=RGB(0,255,0);
            }
            else
            {
                for(y=0;y<wp.y;y++)
                {
                    TextOut(h1,0,hv,a[y],sz[y]);
                    hv+=hd;
                }
                TextOut(h1,0,hv,a[wp.y],wp.x);
                SetTextColor(h1,RGB(255,0,0));
                    for(x=0;x<wp.x;x++)
                    {
                        GetCharWidth32(h1,(UINT)a[wp.y][x],(UINT)a[wp.y][x],&m);
                        j+=m;
                    }
                    hj=j;
                    hk=hv;
                if(cp.y==wp.y)
                {
                    for(x=wp.x;x<cp.x;x++)
                        red[x-wp.x]=a[wp.y][x];
                    TextOut(h1,j,hv,red,cp.x-wp.x+1);
                    for(x=wp.x;x<cp.x;x++)
                    {
                        GetCharWidth32(h1,(UINT)a[wp.y][x],(UINT)a[wp.y][x],&m);
                        j+=m;
                    }
                }
                else
                {
                    for(x=wp.x;x<sz[wp.y];x++)
                        red[x-wp.x]=a[wp.y][x];
                    TextOut(h1,j,hv,red,sz[wp.y]-wp.x-1);
                    for(x=wp.x;x<sz[wp.y]-1;x++)
                    {
                        GetCharWidth32(h1,(UINT)a[wp.y][x],(UINT)a[wp.y][x],&m);
                        j+=m;
                    }
                    SetBkMode(h1,OPAQUE);
                    SetBkColor(h1,RGB(255,0,0));
                    TextOut(h1,j,hv," ",1);
                    SetBkMode(h1,TRANSPARENT);
                    hv+=hd;
                    j=0;
                    TextOut(h1,0,hv,a[cp.y],cp.x);
                    for(x=0;x<cp.x;x++)
                    {
                        GetCharWidth32(h1,(UINT)a[cp.y][x],(UINT)a[cp.y][x],&m);
                        j+=m;
                    }
                }
                SetTextColor(h1,RGB(0,255,0));
                SetBkMode(h1,TRANSPARENT);
                GetCharWidth32(h1,(UINT)a[wp.y][wp.x-1],(UINT)a[wp.y][wp.x-1],&s);
                TextOut(h1,hj-s,hk,&a[wp.y][wp.x-1],1);
                rf1=RGB(255,0,0);
            }
            for(x=cp.x;x<sz[cp.y];x++)
                black[x-cp.x]=a[cp.y][x];
            SetTextColor(h1,RGB(0,0,0));
            TextOut(h1,j,hv,black,sz[cp.y]-cp.x);
            pd=hv;
            b=j;
            for(y=cp.y+1;y<line;y++)
            {
                hv+=hd;
                TextOut(h1,0,hv,a[y],sz[y]);
            }
            SetBkMode(h1,TRANSPARENT);
            SetTextColor(h1,rf1);
            GetCharWidth32(h1,(UINT)a[cp.y][cp.x-1],(UINT)a[cp.y][cp.x-1],&s);
            TextOut(h1,j-s,pd,&a[cp.y][cp.x-1],1);
            SelectObject(h1,f2);
            char test1[]="Sprint Starts In:Time Left:Average:00:00";//Sprint Starts In:Time Left:Average:00:00
            we=0;wa=0;wt=0;wg=0;
            for(unsigned int w=0;w<sizeof(test1);w++)
            {
                GetCharWidth32(h1,(UINT)test1[w],(UINT)test1[w],&t2);
                if(w>=0&&w<17)
                    we+=t2;
                else if(w>=17&&w<=26)
                    wt+=t2;
                else if(w>26&&w<=34)
                    wa+=t2;
                else if(w>34&&w<=39)
                    wg+=t2;
            }
            if(mode=="kick")
            {
            SetTextColor(h1,RGB(0,0,0));
            SetBkMode(h1,OPAQUE);
            SetBkColor(h1,crf1);
            TextOut(h1,rm.right-wg-we,0,"Sprint starts in:",17);
            TextOut(h1,rm.right-wg,0,tn,5);
            }
            else if(mode=="race")
            {
            SetTextColor(h1,RGB(0,0,0));
            SetBkMode(h1,OPAQUE);
            SetBkColor(h1,crf1);
            TextOut(h1,0,0,"Average:",8);
            TextOut(h1,wa,0,wn,5);
            TextOut(h1,rm.right-wg-wt,0,"Time Left:",10);
            TextOut(h1,rm.right-wg,0,tn,5);
            RECT r2=rm;
            SetRect(&r2,0,rm.bottom*15/100,rm.right,rm.bottom*85/100);
            DrawText(h1,"Type the following words",-1,&r2,DT_CENTER);
            SetWindowPos(GetDlgItem(h,EDIT1),NULL,(rm.right-200)/2,rm.bottom*7/10,200,hd+as/2,SWP_NOZORDER);
            if(cbcon==true)
            {
            CreateCaret(h,(HBITMAP)1,2,hd);
            SetCaretPos(b,pd);
            ShowCaret(h);
            }
            InvalidateRect(h,&rm,false);
            }
            SelectObject(h1,o1);
            ReleaseDC(h,h1);
            DeleteObject(o1);
            }
        }
        break;
        case WM_TIMER:
            if((UINT)w==strt)
            {
                tmp++;
                if(tmp==2)
                {
               KillTimer(h,strt);
               mnd();
                }
            }
            else
            {
            h1=GetDC(h);
                SelectObject(h1,f2);
                SetBkMode(h1,OPAQUE);
                SetBkColor(h1,crf1);
                SetTextColor(h1,RGB(0,0,0));
                tc--;
                if(tc==0&&ds!=0)
                {
                    if(ds==-1)
                    {
                        ds=1;
                        tc=30;
                    }
                    else
                    {
                    tc=59;
                    ds--;
                    }
                }
                    tn[0]='0';
                    if(ds<0)
                        buf[0]='0';
                    else
                sprintf(buf,"%d",ds);
                    tn[1]=buf[0];
                sprintf(buf,"%d",tc);
                tn[2]=':';
                if(tc<10)
                    {
                    tn[3]='0';
                    tn[4]=buf[0];
                    }
                else
                {
                    tn[3]=buf[0];
                    tn[4]=buf[1];
                }
                strcat(tn,"  ");
                TextOut(h1,rm.right-wg,0,tn,7);
                if(tc==30&&ds==1)
                    race();
                if(tc==0&&ds==0)
                    {
                    kickdlg(h);
                    return 0;
                    }
                if(wcb==true)
                {
                knil=(wc*60)/ac;
                sprintf(wn,"%d",knil);
                TextOut(h1,wa,0,wn,5);
                ac++;
                }
                ReleaseDC(h,h1);
            }
        break;
    case WM_CHAR:
        if(mode!="race"&&mode!="mnd")
            break;
        if(mode=="mnd")
        {
            if(w==0x0D)
            {
            SetButtonLayer(0,h);
        mousein=false;
        mode="kick";
        destroyer();
        return 0;
            }
            else
                break;
        }
        h1=GetDC(h);
        SelectObject(h1,f1);
        HideCaret(h);
        switch(w)
        {
        case 0x1B:
            did_race_end=true;
            kickdlg(h);
            return 0;
        case 0x08:
            if(cp.x<=rp.x&&cp.y==rp.y)
                break;
            SetBkColor(h1,RGB(255,255,255));
            if(cp.x==0&&cp.y>0)
            {
                cp.y--;
                cp.x=sz[cp.y]-1;
                pd-=hd;
                b=n;
            }
            else
            cp.x--;
            GetCharWidth32(h1,(UINT)a[cp.y][cp.x],(UINT)a[cp.y][cp.x],&v);
            b-=v;
            GetCharWidth32(h1,(UINT)a[cp.y][cp.x-1],(UINT)a[cp.y][cp.x-1],&v);
            if(wp.x<cp.x||wp.y<cp.y)
                if(wp.x==-1)
                    draw(RGB(0,0,0),RGB(0,255,0),a[cp.y][cp.x],a[cp.y][cp.x-1],a[cp.y][cp.x+1]);
                else
                draw(RGB(0,0,0),RGB(255,0,0),a[cp.y][cp.x],a[cp.y][cp.x-1],a[cp.y][cp.x+1]);
            else if(wp.x==cp.x)
                {
                    wp.x=-1;
                    wp.y=-1;
                    draw(RGB(0,0,0),RGB(0,255,0),a[cp.y][cp.x],a[cp.y][cp.x-1],a[cp.y][cp.x+1]);
                }
                con--;
                wrd[con]='\0';
            break;
        default:
            ch=(char)w;
            GetCharWidth32(h1,(UINT)a[cp.y][cp.x-1],(UINT)a[cp.y][cp.x-1],&v);
            if(a[cp.y][cp.x]==ch&&wp.x==-1)
                    {
                        if(wcb==false)
                            wcb=true;
                        if(a[cp.y][cp.x]==' ')
                            wr=true;
                        if(cp.y==line-1&&cp.x==sz[cp.y]-2)
                        {
                            for(int i=0;i<5;i++)
                            {
                                bil=0;
                                stringstream(scores[i])>>bil;
                                if(knil>bil)
                                {
                                    SYSTEMTIME hj;
                                    GetLocalTime(&hj);
                                    char tbuf[5];
                                    for(int j=4;j>i;j--)
                                        strcpy(scores[j],scores[j-1]);
                                    strcpy(scores[i],wn);
                                    strcat(scores[i],"WPM");
                                    strcat(scores[i],"         ");
                                    sprintf(tbuf,"%d",int(hj.wMonth));
                                    strcat(scores[i],tbuf);
                                    strcat(scores[i],"/");
                                    sprintf(tbuf,"%d",int(hj.wDay));
                                    strcat(scores[i],tbuf);
                                    strcat(scores[i],"/");
                                    sprintf(tbuf,"%d",int(hj.wYear));
                                    strcat(scores[i],tbuf);
                                    strcat(scores[i],"     ");
                                    if(int(hj.wHour)<12)
                                    {
                                        meridian=0;
                                    if(int(hj.wHour==0))
                                        sprintf(tbuf,"%d",12);
                                    else
                                    sprintf(tbuf,"%d",int(hj.wHour));
                                    }
                                    else
                                    {
                                        meridian=1;
                                    if(int(hj.wHour==12))
                                        sprintf(tbuf,"%d",int(hj.wHour));
                                    else
                                        sprintf(tbuf,"%d",int(hj.wHour)-12);
                                    }
                                    strcat(scores[i],tbuf);
                                    strcat(scores[i],":");
                                    sprintf(tbuf,"%d",int(hj.wMinute));
                                    if(int(hj.wMinute)<10)
                                    {
                                        strcat(scores[i],"0");
                                    }
                                    strcat(scores[i],tbuf);
                                    strcat(scores[i],"    ");
                                    if(meridian==0)
                                        strcat(scores[i],"AM");
                                    else
                                        strcat(scores[i],"PM");
                                    break;
                                }
                            }
                            did_race_end=true;
                            kickdlg(h);
                            return 0;
                        }
                        draw(RGB(0,255,0),RGB(0,255,0),a[cp.y][cp.x],a[cp.y][cp.x-1],a[cp.y][cp.x+1]);
                    }
            else
            {
                if(wp.x==-1)
                {
                    wp.x=cp.x;
                    wp.y=cp.y;
                    draw(RGB(255,0,0),RGB(0,255,0),a[cp.y][cp.x],a[cp.y][cp.x-1],a[cp.y][cp.x+1]);
                }
                else
                {
                    draw(RGB(255,0,0),RGB(255,0,0),a[cp.y][cp.x],a[cp.y][cp.x-1],a[cp.y][cp.x+1]);
                }
            }
            GetCharWidth32(h1,(UINT)a[cp.y][cp.x],(UINT)a[cp.y][cp.x],&v);
            b+=v;
            cp.x++;
            if(cp.x==sz[cp.y])
            {
                n=b;
                cp.y++;
                b=0;
                cp.x=0;
                pd+=hd;
            }
            if(wr==true)
            {
                wc++;
                wr=false;
                rp.x=cp.x;
                rp.y=cp.y;
                con=0;
                for(int i=0;wrd[i]!='\0';i++)
                    wrd[i]='\0';
            }
            else
            {
                wrd[con]=ch;
                con++;
            }
        }
        dre(GetDlgItem(h,EDIT1));
        SetCaretPos(b,pd);
        ShowCaret(h);
        ReleaseDC(h,h1);
        break;
    default:
        return DefWindowProc(h,u,w,l);
    }
    return 0;
}
int APIENTRY WinMain(HINSTANCE ar,HINSTANCE b,LPSTR c,int d)
{
    cp.x=0;cp.y=0;
    rp.x=0;rp.y=0;
    wp.x=-1;wp.y=-1;
    WNDCLASSEX e;
    e.cbClsExtra=0;
    e.cbSize=sizeof(WNDCLASSEX);
    e.cbWndExtra=0;
    e.hbrBackground=(HBRUSH)0;
    e.hCursor=LoadCursor(NULL,IDC_ARROW);
    e.hIcon=LoadIcon(GetModuleHandle(NULL),MAKEINTRESOURCE(ID_ICON));
    e.hIconSm=LoadIcon(GetModuleHandle(NULL),MAKEINTRESOURCE(ID_ICON));
    e.hInstance=ar;
    e.lpfnWndProc=windpro;
    e.lpszClassName="Saikat";
    e.lpszMenuName=NULL;
    e.style=0;
    RegisterClassEx(&e);
    e.hCursor=LoadCursor(NULL,IDC_IBEAM);
    e.hIcon=NULL;
    e.hIconSm=NULL;
    e.lpfnWndProc=infpro;
    e.lpszClassName="InfoScroll";
    RegisterClassEx(&e);
    e.lpfnWndProc=eb;
    e.lpszClassName="eb";
    RegisterClassEx(&e);
    e.hbrBackground=HBRUSH(0);
    e.hCursor=LoadCursor(NULL,IDC_HAND);
    e.lpfnWndProc=BS1;
    e.lpszClassName="BS1";
    RegisterClassEx(&e);
    e.lpfnWndProc=BS2;
    e.lpszClassName="BS2";
    RegisterClassEx(&e);
    e.lpfnWndProc=BS3;
    e.lpszClassName="BS3";
    RegisterClassEx(&e);
    e.lpfnWndProc=BS4;
    e.lpszClassName="BS4";
    RegisterClassEx(&e);
    e.lpfnWndProc=Backpro;
    e.lpszClassName="Back";
    RegisterClassEx(&e);
    e.lpfnWndProc=Set1;
    e.lpszClassName="Set1";
    RegisterClassEx(&e);
    e.lpfnWndProc=radio11;
    e.lpszClassName="radio11";
    RegisterClassEx(&e);
    e.lpfnWndProc=radio12;
    e.lpszClassName="radio12";
    RegisterClassEx(&e);
    string asb;
    int w=0,drep;
    ifstream mp("pos.txt");
    ifstream md("Data.txt");
    ifstream ma("Assets.txt");
    while(!ma.eof())
    {
        getline(ma,asb);
        if(w==0)
        stringstream(asb.c_str())>>ind;
        else if(w==1)
        stringstream(asb.c_str())>>cbcon;
        else if(w==2)
        stringstream(asb.c_str())>>drep;
        w++;
    }
    rad[1-drep]=1;
    rad[drep]=0;
    ifstream ms("Scores.txt");
    mp.close();
    md.close();
    ma.close();
    int il=0;
    string paas;
    while(!ms.eof())
    {
        getline(ms,paas);
        strcpy(scores[il],paas.c_str());
        il++;
    }
    ms.close();
    HWND h=CreateWindowEx(WS_EX_APPWINDOW,
                          "Saikat",
                          "TypeSprint Offline",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          NULL,NULL,ar,NULL);
    mode="beg";
    SetTimer(h,strt,1000,NULL);
    ShowWindow(h,d);
    UpdateWindow(h);
    tmp=0;
    MSG i;
    while(GetMessage(&i,NULL,0,0)>0)
    {
        TranslateMessage(&i);
        DispatchMessage(&i);
    }
    return 0;
}
