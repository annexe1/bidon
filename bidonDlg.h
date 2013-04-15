// bidonDlg.h : header file
//

#pragma once

class CbidonDlgAutoProxy;


// CbidonDlg dialog
class CbidonDlg : public CDialog
{
	DECLARE_DYNAMIC(CbidonDlg);
	friend class CbidonDlgAutoProxy;

// Construction
public:
	CbidonDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CbidonDlg();

// Dialog Data
	enum { IDD = IDD_BIDON_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	CbidonDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
};
