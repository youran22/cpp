@echo off
setlocal enabledelayedexpansion
set titstr=���߻�ȡ˫ɫ�򿪽������ʷ���� By SunTB @ ľ�ӵ���
set site=www.zhcw.com
set kj=kaijiang.zhcw.com
set ssq=http://%kj%/zhcw/html/ssq
set tmpfile=%tmp%\out.txt
set downfile=��������.txt
set output=˫ɫ�򿪽�����.txt

title !titstr!
if exist "%downfile%" del "%downfile%"

ping -n 2 %site% >nul||(
set err=1
echo.&echo �������������⣬�밴������˳���������
pause>nul
exit
)

set vbs=%temp%\getpage.vbs
echo on
for /f "skip=3 delims=[]" %%a in ('find /n "::code" "%~0"') do echo %%a & more +%%a "%~0">"%vbs%"
echo %a%
for /f %%a in ('cscript //NoLogo "%vbs%" %ssq%/list_1.html^|find "ҳ"') do (set n=%%a&set n=!n:~1!)
echo off
pause 
:begin
for /f "skip=1" %%a in (%output%) do (set log_last=%%a&goto :begin2)
:begin2
cls
echo ���������ı���%output%
echo ����������ݣ�%log_last%
echo ����������ҳ��%ssq%/list_1.html
echo ��������ҳ����!n!
echo ��ȡҳ�뷶Χ��[0-!n!] ���˴�������ҳ�뷶Χ����������������ţ�
echo ҳ�뷶Χʾ����[0] �Զ���ȫ����������  [1] ֻ���ص�1ҳ   [1-!n!] ���ص�1-!n!ҳ
echo.&set xy=&set /p xy=������Ҫ��ȡ������ҳ�룺
if "%xy%"=="0" (
  set downfile=%output%
  set x=1&set y=!n!
  goto :down
)
echo "%xy%"|find "-">Nul&&(for /f "tokens=1-2 delims=-" %%a in ("%xy%") do (set x=%%a&set y=%%b))||(set x=%xy%&set y=%xy%)
if %y% leq !n! goto :down
goto :begin2

:down
echo.&echo �������ؿ������ݣ����������鿴������
cd.>"%tmpfile%"
for /l %%i in (!x!,1,!y!) do (
  title [%%i-!y!] !titstr!
  for /f "skip=2 delims=" %%a in ('cscript //NoLogo "%vbs%" %ssq%/list_%%i.html^|find /v "ҳ"') do (
    set str=%%a
    if "%xy%"=="0" if "%log_last%"=="!str:~0,10!" goto :sort
    echo !str:~0,10!   !str:~10,7!    !str:~17,17!   !str:~35,2!
  )>>"%tmpfile%"
)

:sort
if "%xy%"=="0" move /y "%downfile%" "%downfile%.bak" >nul 2>nul
echo>"%downfile%"  ��������      �ں�            ����        ����
type "%tmpfile%">>"%downfile%"
if "%xy%"=="0" more +1 "%downfile%.bak">>"%downfile%"

echo.&echo �����������
start "" "%downfile%"
exit


::code
Set GetPage = WScript.GetObject(Wscript.Arguments(0))
do until GetPage.readyState = "complete"
WScript.sleep 200
loop
WScript.echo GetPage.DocumentElement.InnerText