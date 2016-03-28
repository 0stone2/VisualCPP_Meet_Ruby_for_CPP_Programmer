
// RubySampleDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "RubySample.h"
#include "RubySampleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(lib, "C:/Script/Ruby/lib/libmsvcrt-ruby220.lib")

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRubySampleDlg ��ȭ ����



CRubySampleDlg::CRubySampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RUBYSAMPLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRubySampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRubySampleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CRubySampleDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRubySampleDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CRubySampleDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CRubySampleDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CRubySampleDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CRubySampleDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CRubySampleDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CRubySampleDlg �޽��� ó����

BOOL CRubySampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CRubySampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CRubySampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CRubySampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// 1 �� - C���� Ruby ȣ���ϱ�
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// ���� 1 - Ruby ��ũ��Ʈ ���� ȣ���ϱ�
//
#define SCRIPT_FILE_1 "./Script/Sample01.rb"

typedef unsigned long VALUE;

extern "C" {
	void	ruby_sysinit(int *, char ***);
	void	ruby_init_stack(volatile VALUE*);
	void	ruby_init(void);
	void	ruby_init_loadpath(void);
	int		ruby_cleanup(volatile int);
	void	ruby_finalize(void);
	void	rb_load(VALUE, int);
	void	rb_load_protect(VALUE, int, int*);

	VALUE	rb_str_new_cstr(const char*);

	void	ruby_stop(int);
}


BOOL InitRuby()
{
	static BOOL	bSuccess { FALSE };

	int		argc{ 0 };
	char *	argv[] = { NULL };
	VALUE	variable_in_this_stack_frame;

	__try {
		if (TRUE == bSuccess) __leave;

		ruby_sysinit(&argc, (char ***)&argv);
		ruby_init_stack(&variable_in_this_stack_frame);
		ruby_init();
		ruby_init_loadpath();

		bSuccess = TRUE;
	}
	__finally {
		if (FALSE == bSuccess)
		{
			ruby_cleanup(0);
		}
	}

	return bSuccess;
}

void CRubySampleDlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BOOL	bSuccess{ FALSE };
	VALUE   ScriptFile{ NULL };

	__try {
		bSuccess = InitRuby();
		if (FALSE == bSuccess) __leave;

		ScriptFile = rb_str_new_cstr(SCRIPT_FILE_1);
		if(NULL == ScriptFile) __leave;

		rb_load(ScriptFile, 0);
	}
	__finally {

	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
// ���� 2 - Ruby ���� ���� �����ϱ�
//
#define SCRIPT_FILE_2 "./Script/Sample02.rb"

typedef unsigned long VALUE;

extern "C" {
	VALUE	rb_gv_set(const char*, VALUE);
	VALUE	rb_gv_get(const char*);

	char *	rb_string_value_ptr(volatile VALUE*);
	long	rb_num2int(VALUE);
}


void CRubySampleDlg::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BOOL	bSuccess{ FALSE };
	char	szDbgString[MAX_PATH]{ 0, };

	VALUE   ScriptFile{ NULL };
	VALUE	WelcomMessage{ NULL };
	char *	szWelcomMessage{ NULL };

	VALUE	WhoamI{ NULL };
	char *	szWhoamI{ NULL };

	VALUE	Version{ NULL };
	int		nVersion{ 0 };

	__try {
		bSuccess = InitRuby();
		if (FALSE == bSuccess) __leave;

		ScriptFile = rb_str_new_cstr(SCRIPT_FILE_2);

		rb_load(ScriptFile, 0);

		WelcomMessage = rb_gv_get("szWelcomMessage");
		szWelcomMessage = rb_string_value_ptr(&WelcomMessage);

		WhoamI = rb_gv_get("szWhoamI");
		szWhoamI = rb_string_value_ptr(&WhoamI);

		Version = rb_gv_get("nVersion");
		nVersion = rb_num2int(Version);

		sprintf_s(szDbgString, "szWelcomMessage = %s\n", szWelcomMessage);
		OutputDebugStringA(szDbgString);

		sprintf_s(szDbgString, "szWhoamI = %s\n", szWhoamI);
		OutputDebugStringA(szDbgString);

		sprintf_s(szDbgString, "nVersion = %d\n", nVersion);
		OutputDebugStringA(szDbgString);

		rb_gv_set("szWhoamI", rb_str_new_cstr("Visual C++"));
		WhoamI = rb_gv_get("szWhoamI");
		szWhoamI = rb_string_value_ptr(&WhoamI);

		sprintf_s(szDbgString, "szWhoamI = %s\n", szWhoamI);
		OutputDebugStringA(szDbgString);
	}
	__finally {

	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
// ���� 3 - Ruby �Լ� ȣ���ϱ�
//
#define SCRIPT_FILE_3 "./Script/Sample03.rb"

typedef unsigned long ID;

enum ruby_special_consts {
#if USE_FLONUM
	RUBY_Qfalse = 0x00,		/* ...0000 0000 */
	RUBY_Qtrue = 0x14,		/* ...0001 0100 */
	RUBY_Qnil = 0x08,		/* ...0000 1000 */
	RUBY_Qundef = 0x34,		/* ...0011 0100 */

	RUBY_IMMEDIATE_MASK = 0x07,
	RUBY_FIXNUM_FLAG = 0x01,	/* ...xxxx xxx1 */
	RUBY_FLONUM_MASK = 0x03,
	RUBY_FLONUM_FLAG = 0x02,	/* ...xxxx xx10 */
	RUBY_SYMBOL_FLAG = 0x0c,	/* ...0000 1100 */
#else
	RUBY_Qfalse = 0,		/* ...0000 0000 */
	RUBY_Qtrue = 2,		/* ...0000 0010 */
	RUBY_Qnil = 4,		/* ...0000 0100 */
	RUBY_Qundef = 6,		/* ...0000 0110 */

	RUBY_IMMEDIATE_MASK = 0x03,
	RUBY_FIXNUM_FLAG = 0x01,	/* ...xxxx xxx1 */
	RUBY_FLONUM_MASK = 0x00,	/* any values ANDed with FLONUM_MASK cannot be FLONUM_FLAG */
	RUBY_FLONUM_FLAG = 0x02,
	RUBY_SYMBOL_FLAG = 0x0e,	/* ...0000 1110 */
#endif
	RUBY_SPECIAL_SHIFT = 8
};

#define Qfalse ((VALUE)RUBY_Qfalse)
#define Qtrue  ((VALUE)RUBY_Qtrue)


extern "C" {
	ID		rb_intern(const char*);
	VALUE	rb_funcall(VALUE, ID, int, ...);
	VALUE	rb_ary_entry(VALUE, long);
}

void CRubySampleDlg::OnBnClickedButton3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BOOL	bSuccess{ FALSE };
	char	szDbgString[MAX_PATH]{ 0, };

	VALUE   ScriptFile{ NULL };

	ID		myfunc_0{ 0 };
	ID		myfunc_1{ 0 };
	ID		myfunc_2{ 0 };
	ID		myfunc_3{ 0 };
	ID		myfunc_4{ 0 };
	ID		myfunc_5{ 0 };

	VALUE	WelcomMessage{ NULL };
	char *	szWelcomMessage{ NULL };

	VALUE	WhoamI{ NULL };
	char *	szWhoamI{ NULL };

	VALUE	ReturnValue{ NULL };
	VALUE	RetString{ NULL };

	__try {
		bSuccess = InitRuby();
		if (FALSE == bSuccess) __leave;

		ScriptFile = rb_str_new_cstr(SCRIPT_FILE_3);

		rb_load(ScriptFile, 0);


		WelcomMessage = rb_gv_get("szWelcomMessage");
		szWelcomMessage = rb_string_value_ptr(&WelcomMessage);

		WhoamI = rb_gv_get("szWhoamI");
		szWhoamI = rb_string_value_ptr(&WhoamI);


		sprintf_s(szDbgString, "[MAIN]szWhoamI = %s\n", szWhoamI);
		OutputDebugStringA(szDbgString);

		///////////////////////////////////////////////////////////////////
		// �Լ�(myfunc_0) ȣ���ϱ�
		myfunc_0 = rb_intern("myfunc_0");
		ReturnValue = rb_funcall(0, myfunc_0, 0);

		WhoamI = rb_gv_get("szWhoamI");
		szWhoamI = rb_string_value_ptr(&WhoamI);

		sprintf_s(szDbgString, "[myfunc_0]ReturnValue = %s\n", rb_string_value_ptr(&ReturnValue));
		OutputDebugStringA(szDbgString);
		
		sprintf_s(szDbgString, "[myfunc_0]szWhoamI = %s\n", szWhoamI);
		OutputDebugStringA(szDbgString);

		///////////////////////////////////////////////////////////////////
		// �Լ�(myfunc_1) ȣ���ϱ�
		myfunc_1 = rb_intern("myfunc_1");
		ReturnValue = rb_funcall(0, myfunc_1, 0);

		WhoamI = rb_gv_get("szWhoamI");
		szWhoamI = rb_string_value_ptr(&WhoamI);


		if (RUBY_Qnil == ReturnValue)
		{
			sprintf_s(szDbgString, "[myfunc_1]ReturnValue = NIL\n");
			OutputDebugStringA(szDbgString);
		}
		
		sprintf_s(szDbgString, "[myfunc_1]szWhoamI = %s\n", szWhoamI);
		OutputDebugStringA(szDbgString);

		///////////////////////////////////////////////////////////////////
		// �Լ�(myfunc_2) ȣ���ϱ�
		myfunc_2 = rb_intern("myfunc_2");
		ReturnValue = rb_funcall(0, myfunc_2, 0);

		WhoamI = rb_gv_get("szWhoamI");
		szWhoamI = rb_string_value_ptr(&WhoamI);

		sprintf_s(szDbgString, "[myfunc_2]ReturnValue = %s\n", rb_string_value_ptr(&ReturnValue));
		OutputDebugStringA(szDbgString);

		sprintf_s(szDbgString, "[myfunc_2]szWhoamI = %s\n", szWhoamI);
		OutputDebugStringA(szDbgString);

		///////////////////////////////////////////////////////////////////
		// �Լ�(myfunc_3) ȣ���ϱ�
		myfunc_3 = rb_intern("myfunc_3");
		ReturnValue = rb_funcall(0, myfunc_3, 0);

		WhoamI = rb_gv_get("szWhoamI");
		szWhoamI = rb_string_value_ptr(&WhoamI);

		RetString = rb_ary_entry(ReturnValue, 0);
		sprintf_s(szDbgString, "[myfunc_3]ReturnValue = [%s, %s]\n", rb_string_value_ptr(&RetString), (rb_ary_entry(ReturnValue, 1) == Qtrue)? "true" : "false");
		OutputDebugStringA(szDbgString);

		sprintf_s(szDbgString, "[myfunc_3]szWhoamI = %s\n", szWhoamI);
		OutputDebugStringA(szDbgString);

		///////////////////////////////////////////////////////////////////
		// �Լ�(myfunc_4) ȣ���ϱ�
		myfunc_4 = rb_intern("myfunc_4");
		ReturnValue = rb_funcall(0, myfunc_4, 1, rb_str_new_cstr("myfunc_4"));

		WhoamI = rb_gv_get("szWhoamI");
		szWhoamI = rb_string_value_ptr(&WhoamI);

		RetString = rb_ary_entry(ReturnValue, 0);
		sprintf_s(szDbgString, "[myfunc_4]ReturnValue = [%s, %s]\n", rb_string_value_ptr(&RetString), (rb_ary_entry(ReturnValue, 1) == Qtrue) ? "true" : "false");
		OutputDebugStringA(szDbgString);

		sprintf_s(szDbgString, "[myfunc_4]szWhoamI = %s\n", szWhoamI);
		OutputDebugStringA(szDbgString);

		///////////////////////////////////////////////////////////////////
		// �Լ�(myfunc_5) ȣ���ϱ�
		myfunc_4 = rb_intern("myfunc_5");
		ReturnValue = rb_funcall(0, myfunc_4, 2, rb_str_new_cstr("myfunc_4"), Qfalse);
	
		WhoamI = rb_gv_get("szWhoamI");
		szWhoamI = rb_string_value_ptr(&WhoamI);

		RetString = rb_ary_entry(ReturnValue, 0);
		sprintf_s(szDbgString, "[myfunc_5]ReturnValue = [%s, %s]\n", rb_string_value_ptr(&RetString), (rb_ary_entry(ReturnValue, 1) == Qtrue) ? "true" : "false");
		OutputDebugStringA(szDbgString);

		sprintf_s(szDbgString, "[myfunc_5]szWhoamI = %s\n", szWhoamI);
		OutputDebugStringA(szDbgString);

		bSuccess = TRUE;
	}
	__finally {

	}
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// 2 �� - Ruby���� C ȣ���ϱ�
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// ���� 4 - Ruby ���� ȣ�� ������ �Լ� ����� 1 
//
#define SCRIPT_FILE_4 "./Script/Sample04.rb"

#define Qnil   ((VALUE)RUBY_Qnil)
#define ANYARGS ...

enum ruby_value_type {
	RUBY_T_NONE = 0x00,

	RUBY_T_OBJECT = 0x01,
	RUBY_T_CLASS = 0x02,
	RUBY_T_MODULE = 0x03,
	RUBY_T_FLOAT = 0x04,
	RUBY_T_STRING = 0x05,
	RUBY_T_REGEXP = 0x06,
	RUBY_T_ARRAY = 0x07,
	RUBY_T_HASH = 0x08,
	RUBY_T_STRUCT = 0x09,
	RUBY_T_BIGNUM = 0x0a,
	RUBY_T_FILE = 0x0b,
	RUBY_T_DATA = 0x0c,
	RUBY_T_MATCH = 0x0d,
	RUBY_T_COMPLEX = 0x0e,
	RUBY_T_RATIONAL = 0x0f,

	RUBY_T_NIL = 0x11,
	RUBY_T_TRUE = 0x12,
	RUBY_T_FALSE = 0x13,
	RUBY_T_SYMBOL = 0x14,
	RUBY_T_FIXNUM = 0x15,

	RUBY_T_UNDEF = 0x1b,
	RUBY_T_NODE = 0x1c,
	RUBY_T_ICLASS = 0x1d,
	RUBY_T_ZOMBIE = 0x1e,

	RUBY_T_MASK = 0x1f
};


extern "C" {
	void	rb_define_global_function(const char*, VALUE(*)(ANYARGS), int);
}

VALUE MyDbgString1()
{
	OutputDebugString(_T("MyDbgString ȣ���\n"));
	return Qnil;
}


void CRubySampleDlg::OnBnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BOOL	bSuccess{ FALSE };
	VALUE   ScriptFile{ NULL };

	ID		DbgString{ 0 };

	__try {
		bSuccess = InitRuby();

		ScriptFile = rb_str_new_cstr(SCRIPT_FILE_4);

		rb_define_global_function("DbgString", (VALUE(*)(ANYARGS))MyDbgString1, 0);

		rb_load(ScriptFile, 0);

		bSuccess = TRUE;
	}
	__finally {

	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
// ���� 5 - Ruby ���� ȣ�� ������ �Լ� ����� 2 
//
# define SIGNED_VALUE long

#define SCRIPT_FILE_5 "./Script/Sample05.rb"


extern "C" {
	char *	rb_string_value_ptr(volatile VALUE*);
	char *	rb_string_value_cstr(volatile VALUE*);
	long	rb_num2int(VALUE);
	VALUE	rb_int2inum(SIGNED_VALUE);
}

#define T_MASK   RUBY_T_MASK

struct RBasic {
	VALUE flags;
	const VALUE klass;
};
#define BUILTIN_TYPE(x) (int)(((struct RBasic*)(x))->flags & T_MASK)

VALUE MyDbgString2(VALUE self, VALUE DbgString)
{
	int nType = 0;
	char *szDbgString{ NULL };

	nType = BUILTIN_TYPE(DbgString);

	szDbgString = rb_string_value_cstr(&DbgString);

	OutputDebugStringA(szDbgString);

	return Qnil;
}

VALUE MySum2(int argc, VALUE * NumArray, VALUE self)
{
	int nType = 0;
	int nStart = 0;
	int nEnd = 0;
	int nSum = 0;

	nStart = rb_num2int(NumArray[0]);
	nEnd = rb_num2int(NumArray[1]);

	if (nStart <= nEnd)
	{
		for (int nIndex = nStart; nIndex <= nEnd; nIndex++) nSum += nIndex;
	}
	else
	{
		for (int nIndex = nEnd; nIndex <= nStart; nIndex++) nSum += nIndex;
	}

	return rb_int2inum(nSum);
}


void CRubySampleDlg::OnBnClickedButton5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BOOL	bSuccess{ FALSE };
	VALUE   ScriptFile{ NULL };
	ID		DbgString{ 0 };

	__try {
		bSuccess = InitRuby();
		if (FALSE == bSuccess) __leave;

		ScriptFile = rb_str_new_cstr(SCRIPT_FILE_5);

		rb_define_global_function("DbgString", (VALUE(*)(ANYARGS))MyDbgString2, 1);
		rb_define_global_function("Sum", (VALUE(*)(ANYARGS))MySum2, -1);

		rb_load(ScriptFile, 0);

		bSuccess = TRUE;
	}
	__finally {

	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
// ���� 6 - Ruby ���� ȣ�� ������ �Լ� ����� 3 
//
#define SCRIPT_FILE_6 "./Script/Sample06.rb"

#define R_CAST(st)   (struct st*)
#define RBASIC(obj)  (R_CAST(RBasic)(obj))
#define RARRAY(obj)  (R_CAST(RArray)(obj))



#define FL_USHIFT    12

#define FL_USER0     (((VALUE)1)<<(FL_USHIFT+0))
#define FL_USER1     (((VALUE)1)<<(FL_USHIFT+1))
#define FL_USER2     (((VALUE)1)<<(FL_USHIFT+2))
#define FL_USER3     (((VALUE)1)<<(FL_USHIFT+3))
#define FL_USER4     (((VALUE)1)<<(FL_USHIFT+4))

#define RARRAY_EMBED_FLAG FL_USER1
/* FL_USER2 is for ELTS_SHARED */
#define RARRAY_EMBED_LEN_MASK (FL_USER4|FL_USER3)
#define RARRAY_EMBED_LEN_SHIFT (FL_USHIFT+3)
#define RARRAY_EMBED_LEN_MAX 3

#define RARRAY_LEN(a) \
    ((RBASIC(a)->flags & RARRAY_EMBED_FLAG) ? \
     (long)((RBASIC(a)->flags >> RARRAY_EMBED_LEN_SHIFT) & \
	 (RARRAY_EMBED_LEN_MASK >> RARRAY_EMBED_LEN_SHIFT)) : \
     RARRAY(a)->as.heap.len)

struct RArray {
	struct RBasic basic;
	union {
		struct {
			long len;
			union {
				long capa;
				VALUE shared;
			} aux;
			const VALUE *ptr;
		} heap;
		const VALUE ary[RARRAY_EMBED_LEN_MAX];
	} as;
};


VALUE MyDbgString3(VALUE self, VALUE DbgString)
{
	int nType = 0;
	char *szDbgString{ NULL };

	nType = BUILTIN_TYPE(DbgString);

	szDbgString = rb_string_value_cstr(&DbgString);

	OutputDebugStringA(szDbgString);

	return Qnil;
}

VALUE MySum3(VALUE self, VALUE NumArray)
{
	int nType = 0;
	int nSize = 0;
	int nStart = 0;
	int nEnd = 0;
	int nSum = 0;

	nType = BUILTIN_TYPE(NumArray);
	nSize = RARRAY_LEN(NumArray);

	nStart = rb_num2int(rb_ary_entry(NumArray, 0));
	nEnd = rb_num2int(rb_ary_entry(NumArray, 1));

	if (nStart <= nEnd)
	{
		for (int nIndex = nStart; nIndex <= nEnd; nIndex++) nSum += nIndex;
	}
	else
	{
		for (int nIndex = nEnd; nIndex <= nStart; nIndex++) nSum += nIndex;
	}

	return rb_int2inum(nSum);
}

void CRubySampleDlg::OnBnClickedButton6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BOOL	bSuccess{ FALSE };
	VALUE   ScriptFile{ NULL };
	ID		DbgString{ 0 };

	__try {
		bSuccess = InitRuby();
		if (FALSE == bSuccess) __leave;

		ScriptFile = rb_str_new_cstr(SCRIPT_FILE_6);

		rb_define_global_function("DbgString", (VALUE(*)(ANYARGS))MyDbgString3, 1);
		rb_define_global_function("Sum", (VALUE(*)(ANYARGS))MySum3, -2);

		rb_load(ScriptFile, 0);

		bSuccess = TRUE;
	}
	__finally {

	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// 3 �� - Ruby���� DLL ȣ���ϱ�
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// ���� 7 - FFI�� ����Ͽ� Ruby���� DLL ȣ���ϱ� 
//

void CRubySampleDlg::OnBnClickedButton7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
