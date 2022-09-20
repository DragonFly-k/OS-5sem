@echo off
@chcp 1251
echo -- ������ ����������: %1 %2
echo -- �����: %1
echo -- ��� �����: %2

if "%*" equ "" goto help
if "%2" equ "" echo ---+ ����������� ��� ����� & goto exit

if /i "%1" equ "create" goto create
if /i "%1" equ "delete" goto delete
if /i "%1" neq "delete" goto errorRejim else if /i "%1" neq "create" goto errorRejim

:help
echo ---+ z03-06 ����� ����
echo ---++ ����� = {create, delete}
echo ---++ ���� = ��� �����
goto exit

:errorRejim
echo ---+ ����� ����� �� ���������
goto exit

:create
if not exist %2 (echo. > %2 & echo ---+ ���� %2 ������) else (echo ---+ ���� %2 ��� ����)
goto exit

:delete
if not exist %2 (echo ---+ ���� %2 �� ������) else (del %2 & echo ---+ ���� %2 ������)
goto exit

:exit
pause