@echo off
@color E0
	title IP设置
:start
	echo "设置IPV4信息"
	echo "1.自动获取IP"
	echo "2.设置静态IP"
	
	set /p var=请输入选项
	echo %var%
	
	if %var% == 1 goto setAuto
	if %var% == 2 goto setStatic
	
	:setAuto
		netsh -f c:\ip_auto.txt
		goto end
	
	:setStatic
		netsh -f c:\ip_static.txt
		goto end
		
		echo "down."
:end
	goto end