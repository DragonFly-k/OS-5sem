@echo off
@chcp 1251
echo -- ������ ����������: %1 %2 %3
echo -- �������� 1: %1
echo -- �������� 2: %2
echo -- �������� 3: %3
set /A x = %1 %3 %2
echo  ���������: %x%
pause