// DlgProxy.h: header file
//

#pragma once

class CbidonDlg;


// CbidonDlgAutoProxy command target

class CbidonDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CbidonDlgAutoProxy)

	CbidonDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CbidonDlg* m_pDialog;

// Operations
public:

// Overrides
	public:
	virtual void OnFinalRelease();

// Implementation
protected:
	virtual ~CbidonDlgAutoProxy();

	// Generated message map functions

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CbidonDlgAutoProxy)

	// Generated OLE dispatch map functions

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

