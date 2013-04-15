// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "bidon.h"
#include "DlgProxy.h"
#include "bidonDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CbidonDlgAutoProxy

IMPLEMENT_DYNCREATE(CbidonDlgAutoProxy, CCmdTarget)

CbidonDlgAutoProxy::CbidonDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CbidonDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CbidonDlg)))
		{
			m_pDialog = reinterpret_cast<CbidonDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CbidonDlgAutoProxy::~CbidonDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CbidonDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CbidonDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CbidonDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// Note: we add support for IID_Ibidon to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .IDL file.

// {BC85D92D-DAE4-4968-96B3-7ECABF49E664}
static const IID IID_Ibidon =
{ 0xBC85D92D, 0xDAE4, 0x4968, { 0x96, 0xB3, 0x7E, 0xCA, 0xBF, 0x49, 0xE6, 0x64 } };

BEGIN_INTERFACE_MAP(CbidonDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CbidonDlgAutoProxy, IID_Ibidon, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {02280D38-59FB-4BDD-9876-EF5D9E35770F}
IMPLEMENT_OLECREATE2(CbidonDlgAutoProxy, "bidon.Application", 0x2280d38, 0x59fb, 0x4bdd, 0x98, 0x76, 0xef, 0x5d, 0x9e, 0x35, 0x77, 0xf)


// CbidonDlgAutoProxy message handlers
