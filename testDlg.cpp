
// testDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"
#include "afxdialogex.h"
#include"afxwin.h"
#include<fstream>
#include<sstream>
#include<iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CtestDlg �Ի���



CtestDlg::CtestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CtestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CtestDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CtestDlg ��Ϣ�������

BOOL CtestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CtestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CtestDlg::readfile()
{
	// in()
//ifstream
	
}


void CtestDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ifstream in("text.txt");
	string str;
	if (!in.is_open())
	{
		AfxMessageBox(_T("�����ļ�ʧ��"));
	}
	while (getline(in, str))
	{
		//����˼·���ȶ���һ��ʼ�����֣�����ѭ������˫�ص����������������Ĵ洢��
		//�ȶ�������
		string rest,rest1;
		CString c;
		string a;
		int num;
		char squre[3072] = { 0 };
		char matrix[50] = {0};
		char rest_of_matrix[3072] = {0};
		sscanf_s(str.c_str(),"%d",&num);
		//����ѭ��������vector����
		sscanf_s(str.c_str(), "%*[^[]%s", squre, sizeof(squre));
		rest = squre;
		for (int i = 0; i < num; i++)
		{
			
			CString s;
			po p;
			sscanf_s(rest.c_str(), "%[^]]", matrix,sizeof(matrix));
			//���ù̶���ʽ���ṹ�帳ֵ�����ҵ��뵽����֮��
			rest1 = matrix;
			sscanf_s(rest1.c_str(),"[%d,%d,%d,%d",&p.a,&p.b,&p.c,&p.d);
			vec.push_back(p);
			sscanf_s(rest.c_str(), "%*[^]]%s", rest_of_matrix, sizeof(rest_of_matrix));
			rest = rest_of_matrix;
			sscanf_s(rest.c_str(), "%*[^[]%s", rest_of_matrix,sizeof(rest_of_matrix));
			rest = rest_of_matrix;
		}
		vc.push_back(vec);
	}
	//�����Ƿ��ȡ�ɹ�
	vector<vector<po>>::iterator it;
	for (it = vc.begin(); it != vc.end(); it++)
	{
		vector<po>::iterator its;
		for (its = vec.begin(); its!= vec.end(); its++)
		{
			int a = (*its).a;
			int b = (*its).b;
			int c = (*its).c;
			int d = (*its).d;
			CString f;
			f.Format(_T("%d,%d,%d,%d"),a,b,c,d);
			MessageBox(f);

		}
	}
}
