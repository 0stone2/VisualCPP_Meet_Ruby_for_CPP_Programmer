// RbExt.cpp : DLL ���� ���α׷��� ���� ������ �Լ��� �����մϴ�.
//

#include "stdafx.h"

void Init_RbExt()
{
	OutputDebugStringA("Init_RbExt\n");
}

void DbgString(char *szDbgString)
{
	OutputDebugStringA(szDbgString);
}

int Sum(int nStart, int nEnd)
{
	int nSum{ 0 };

	if (nStart <= nEnd)
	{
		for (int nIndex = nStart; nIndex <= nEnd; nIndex++) nSum += nIndex;
	}
	else
	{
		for (int nIndex = nEnd; nIndex <= nStart; nIndex++) nSum += nIndex;
	}

	return nSum;
}