
// RubySample.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CRubySampleApp:
// �� Ŭ������ ������ ���ؼ��� RubySample.cpp�� �����Ͻʽÿ�.
//

class CRubySampleApp : public CWinApp
{
public:
	CRubySampleApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CRubySampleApp theApp;