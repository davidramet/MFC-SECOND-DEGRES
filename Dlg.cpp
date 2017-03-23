
// MFC SECOND DEGRESDlg.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "MFC SECOND DEGRES.h"
#include "MFC SECOND DEGRESDlg.h"
#include "afxdialogex.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// boîte de dialogue CAboutDlg utilisée pour la boîte de dialogue 'À propos de' pour votre application

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Données de boîte de dialogue
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Implémentation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// boîte de dialogue CMFCSECONDDEGRESDlg




CMFCSECONDDEGRESDlg::CMFCSECONDDEGRESDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCSECONDDEGRESDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_valeurA = 0.0f;
	m_valeurB = 0.0f;
	m_valeurC = 0.0f;
	m_delta = 0.0f;
	m_solutions = _T("");
	m_resux1 = 0.0f;
	m_resux2 = 0.0f;
}

void CMFCSECONDDEGRESDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_VALEUR1, m_valeurA);
	DDX_Text(pDX, IDC_VALEUR2, m_valeurB);
	DDX_Text(pDX, IDC_VALEUR3, m_valeurC);
	DDX_Text(pDX, IDC_DELTA, m_delta);
	DDX_Text(pDX, IDC_SOLUTIONS, m_solutions);
	DDX_Text(pDX, IDC_RESUX1, m_resux1);
	DDX_Text(pDX, IDC_RESUX2, m_resux2);
}

BEGIN_MESSAGE_MAP(CMFCSECONDDEGRESDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_AFFICHER, &CMFCSECONDDEGRESDlg::OnBnClickedAfficher)
	ON_BN_CLICKED(IDC_QUITTER, &CMFCSECONDDEGRESDlg::OnBnClickedQuitter)
	ON_STN_CLICKED(IDC_SOLUTIONS, &CMFCSECONDDEGRESDlg::OnStnClickedSolutions)
END_MESSAGE_MAP()


// gestionnaires de messages pour CMFCSECONDDEGRESDlg

BOOL CMFCSECONDDEGRESDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Ajouter l'élément de menu "À propos de..." au menu Système.

	// IDM_ABOUTBOX doit se trouver dans la plage des commandes système.
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

	// Définir l'icône de cette boîte de dialogue. L'infrastructure effectue cela automatiquement
	//  lorsque la fenêtre principale de l'application n'est pas une boîte de dialogue
	SetIcon(m_hIcon, TRUE);			// Définir une grande icône
	SetIcon(m_hIcon, FALSE);		// Définir une petite icône

	// TODO: ajoutez ici une initialisation supplémentaire

	return TRUE;  // retourne TRUE, sauf si vous avez défini le focus sur un contrôle
}

void CMFCSECONDDEGRESDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Si vous ajoutez un bouton Réduire à votre boîte de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'icône. Pour les applications MFC utilisant le modèle Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CMFCSECONDDEGRESDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de périphérique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'icône dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'icône
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le système appelle cette fonction pour obtenir le curseur à afficher lorsque l'utilisateur fait glisser
//  la fenêtre réduite.
HCURSOR CMFCSECONDDEGRESDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCSECONDDEGRESDlg::OnBnClickedAfficher()
{
	int defaut = 0;

	//Calcul de DELTA
	UpdateData(TRUE);
	m_delta = (m_valeurB * m_valeurB) - 4 * m_valeurA * m_valeurC;
	UpdateData(FALSE);

	//Déterminer les solutions et calcul de x1 /x2
	if(m_delta == 0)
	{
		UpdateData(TRUE);
		m_solutions = "Il y a une 1 solution !";
		m_resux1 = -m_valeurB / (2*m_valeurA);
		m_resux2 = defaut;
		UpdateData(FALSE);
	}
	if(m_delta < 0)
	{
		UpdateData(TRUE);
		m_solutions = "Il n'y a pas de solution !";
		m_resux1 = defaut;
		m_resux2 = defaut;
		UpdateData(FALSE);
	}
	if(m_delta > 0)
	{
		UpdateData(TRUE);
		m_solutions = "Il y a 2 solutions !";
		m_resux1 = (-m_valeurB-sqrt(m_delta)) / (2 * m_valeurA);
		m_resux2 = (-m_valeurB+sqrt(m_delta)) / (2 * m_valeurA);
		UpdateData(FALSE);
	}
	

}


void CMFCSECONDDEGRESDlg::OnBnClickedQuitter()
{
	OnOK();
}
