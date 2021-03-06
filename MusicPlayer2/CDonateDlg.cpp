// CDonateDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MusicPlayer2.h"
#include "CDonateDlg.h"
#include "afxdialogex.h"


// CDonateDlg 对话框

IMPLEMENT_DYNAMIC(CDonateDlg, CDialogEx)

CDonateDlg::CDonateDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DONATE_DIALOG, pParent)
{

}

CDonateDlg::~CDonateDlg()
{
}

void CDonateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDonateDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDonateDlg 消息处理程序


BOOL CDonateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rect;
	GetDlgItem(IDC_DONATE_STATIC)->GetWindowRect(rect);
	ScreenToClient(rect);

	//设置图片的位置
	m_rc_pic.MoveToXY(rect.right + theApp.DPI(10), rect.top);
	m_rc_pic.right = m_rc_pic.left + theApp.DPI(200);
	m_rc_pic.bottom = m_rc_pic.top + theApp.DPI(200);

	GetClientRect(rect);
	if (m_rc_pic.right > rect.right - theApp.DPI(10))		//防止图片右侧超出窗口右侧
		m_rc_pic.right = rect.right - theApp.DPI(10);

	//获取“取消”按钮的位置
	GetDlgItem(IDCANCEL)->GetWindowRect(rect);
	ScreenToClient(rect);
	if (m_rc_pic.bottom > rect.top - theApp.DPI(10))		//防止图片下方达到“取消”按钮
		m_rc_pic.bottom = rect.top - theApp.DPI(10);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDonateDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()

	CDrawCommon draw;
	draw.Create(&dc, this);
	draw.DrawBitmap(IDB_DONATE, m_rc_pic.TopLeft(), m_rc_pic.Size(), CDrawCommon::StretchMode::FIT);
}
