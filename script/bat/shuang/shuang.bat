@echo off
setlocal enabledelayedexpansion
set titstr=在线获取双色球开奖结果历史数据 By SunTB @ 木子电脑
set site=www.zhcw.com
set kj=kaijiang.zhcw.com
set ssq=http://%kj%/zhcw/html/ssq
set tmpfile=%tmp%\out.txt
set downfile=下载数据.txt
set output=双色球开奖数据.txt

title !titstr!
if exist "%downfile%" del "%downfile%"

ping -n 2 %site% >nul||(
set err=1
echo.&echo 网络连接有问题，请按任意键退出检查后重试
pause>nul
exit
)

set vbs=%temp%\getpage.vbs
echo on
for /f "skip=3 delims=[]" %%a in ('find /n "::code" "%~0"') do echo %%a & more +%%a "%~0">"%vbs%"
echo %a%
for /f %%a in ('cscript //NoLogo "%vbs%" %ssq%/list_1.html^|find "页"') do (set n=%%a&set n=!n:~1!)
echo off
pause 
:begin
for /f "skip=1" %%a in (%output%) do (set log_last=%%a&goto :begin2)
:begin2
cls
echo 本地数据文本：%output%
echo 本地最后数据：%log_last%
echo 开奖数据首页：%ssq%/list_1.html
echo 网络数据页数：!n!
echo 获取页码范围：[0-!n!] （此处及以下页码范围均不包含外面的括号）
echo 页码范围示例：[0] 自动补全至最新数据  [1] 只下载第1页   [1-!n!] 下载第1-!n!页
echo.&set xy=&set /p xy=请输入要获取的数据页码：
if "%xy%"=="0" (
  set downfile=%output%
  set x=1&set y=!n!
  goto :down
)
echo "%xy%"|find "-">Nul&&(for /f "tokens=1-2 delims=-" %%a in ("%xy%") do (set x=%%a&set y=%%b))||(set x=%xy%&set y=%xy%)
if %y% leq !n! goto :down
goto :begin2

:down
echo.&echo 正在下载开奖数据，具体进度请查看标题栏
cd.>"%tmpfile%"
for /l %%i in (!x!,1,!y!) do (
  title [%%i-!y!] !titstr!
  for /f "skip=2 delims=" %%a in ('cscript //NoLogo "%vbs%" %ssq%/list_%%i.html^|find /v "页"') do (
    set str=%%a
    if "%xy%"=="0" if "%log_last%"=="!str:~0,10!" goto :sort
    echo !str:~0,10!   !str:~10,7!    !str:~17,17!   !str:~35,2!
  )>>"%tmpfile%"
)

:sort
if "%xy%"=="0" move /y "%downfile%" "%downfile%.bak" >nul 2>nul
echo>"%downfile%"  开奖日期      期号            红球        蓝球
type "%tmpfile%">>"%downfile%"
if "%xy%"=="0" more +1 "%downfile%.bak">>"%downfile%"

echo.&echo 数据下载完毕
start "" "%downfile%"
exit


::code
Set GetPage = WScript.GetObject(Wscript.Arguments(0))
do until GetPage.readyState = "complete"
WScript.sleep 200
loop
WScript.echo GetPage.DocumentElement.InnerText