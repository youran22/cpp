@echo off
@color E0
	title IP����
:start
	echo "����IPV4��Ϣ"
	echo "1.�Զ���ȡIP"
	echo "2.���þ�̬IP"
	
	set /p var=������ѡ��
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