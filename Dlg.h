
// MFC SECOND DEGRESDlg.h : fichier d'en-tête
//

#pragma once


// boîte de dialogue CMFCSECONDDEGRESDlg
class CMFCSECONDDEGRESDlg : public CDialogEx
{
// Construction
public:
	CMFCSECONDDEGRESDlg(CWnd* pParent = NULL);	// constructeur standard

// Données de boîte de dialogue
	enum { IDD = IDD_MFCSECONDDEGRES_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV


// Implémentation
protected:
	HICON m_hIcon;

	// Fonctions générées de la table des messages
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	float m_valeurA;
	float m_valeurB;
	float m_valeurC;
	float m_delta;
	afx_msg void OnBnClickedAfficher();
	afx_msg void OnBnClickedQuitter();
	afx_msg void OnStnClickedSolutions();
	CString m_solutions;
	float m_resux1;
	float m_resux2;
};
