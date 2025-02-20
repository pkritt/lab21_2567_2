#include <windows.h>
#include<cstdlib>
#include<stdio.h>
const char g_szClassName[] = "myWindowClass";

HWND textfield, textbox1, textbox2;
// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {   case WM_CREATE:{
        textfield = CreateWindowA("STATIC","Please input two numbers",WS_VISIBLE | WS_CHILD | WS_BORDER,30,20,180,25,hwnd, NULL,NULL,NULL);
       
        textbox1 = CreateWindow("EDIT", "", WS_BORDER | WS_CHILD | WS_VISIBLE, 60, 50, 120, 25, hwnd, NULL, NULL, NULL);
		textbox2 = CreateWindow("EDIT", "", WS_BORDER | WS_CHILD | WS_VISIBLE, 60, 80, 120, 25, hwnd, NULL, NULL, NULL);
		CreateWindow("BUTTON", "+", WS_BORDER | WS_CHILD | WS_VISIBLE, 40, 110, 25, 25, hwnd, (HMENU) 1, NULL, NULL);
		CreateWindow("BUTTON", "-", WS_BORDER | WS_CHILD | WS_VISIBLE, 80, 110, 25, 25, hwnd, (HMENU) 2, NULL, NULL);
		CreateWindow("BUTTON", "*", WS_BORDER | WS_CHILD | WS_VISIBLE, 120, 110, 25, 25, hwnd, (HMENU) 3, NULL, NULL);
		CreateWindow("BUTTON", "/", WS_BORDER | WS_CHILD | WS_VISIBLE, 160, 110, 25, 25, hwnd, (HMENU) 4, NULL, NULL);

        break;}
       
        case WM_COMMAND:
		    switch (LOWORD(wParam)) {
			case 1:{
                char number[2][10];
                double a, b, result;
                GetWindowText(textbox1, number[0], sizeof(number[0]));
                GetWindowText(textbox2, number[1], sizeof(number[1]));
                a = atof(number[0]);
                b = atof(number[1]);
                result = a + b;
                char str[100];
                sprintf(str, "%f", result);
                MessageBox(hwnd, str , "Result", MB_OK);
                break;}

			case 2: {
            char number[2][10];
            double a, b, result;
            GetWindowText(textbox1, number[0], sizeof(number[0]));
            GetWindowText(textbox2, number[1], sizeof(number[1]));
            a = atof(number[0]);
            b = atof(number[1]);
            result = a - b;
            char str[100];
            sprintf(str, "%f", result);
            MessageBox(hwnd, str , "Result", MB_OK);
            break;}     

			case 3: {
            char number[2][10];
            double a, b, result;
            GetWindowText(textbox1, number[0], sizeof(number[0]));
            GetWindowText(textbox2, number[1], sizeof(number[1]));
            a = atof(number[0]);
            b = atof(number[1]);
            result = a * b;
            char str[100];
            sprintf(str, "%f", result);
            MessageBox(hwnd, str , "Result", MB_OK);
            break;}

			case 4: {
            char number[2][10];
            double a, b, result;
            GetWindowText(textbox1, number[0], sizeof(number[0]));
            GetWindowText(textbox2, number[1], sizeof(number[1]));
            a = atof(number[0]);
            b = atof(number[1]);
            if(b==0){ MessageBox(hwnd, "Division by zero!", "Error", MB_OK);}
            else{result = a / b;
            char str[100];
            sprintf(str, "%f", result);
            MessageBox(hwnd, str , "Result", MB_OK);}
            break;}
            }
            break;
    
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Step 1: Registering the Window Class
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Creating the Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "My Calculator",
        WS_SYSMENU,
        CW_USEDEFAULT, CW_USEDEFAULT, 250, 200,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Step 3: The Message Loop
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}