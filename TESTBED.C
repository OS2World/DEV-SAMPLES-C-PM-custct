#pragma	title("Test Bed Application  --  Version 2.00   -- (TestBed.C)")
#pragma	subtitle("  main( ) -   Interface Definitions")

#define	INCL_DOS		   /* Include OS/2 PM DOS Kernal	*/
#define	INCL_WIN		   /* Include OS/2 PM Windows Interface	*/

static char *PROGID = "@(#)testbed.c:2.00";

#include <os2.h>

#include "..\imagebtn.h"

#include "testbed.h"

/* This	is the main program module for the Test	Bed Application.  It	*/
/* performs program initialization/termination and provides the	main	*/
/* dispatch controller.	 The program requires OS/2 Version 1.2 or	*/
/* above.								*/
/*									*/
/* The application was created using Prominare Designer	and the	design	*/
/* is contained	within the TestBed.Des file.				*/
/*									*/
/* The application is built using the following	options	in Prominare	*/
/* Builder:								*/
/*									*/
/* Option	       Value						*/
/* ------	       -----						*/
/* Memory Model	       Small						*/
/* Op Sys	       OS/2 2.x	PM Normal				*/
/* Optimization	       Debug						*/
/* CPU		       80386						*/
/* Build Control       Compile Only					*/
/*		       Sub-system					*/
/* Warning Level       3						*/
/*									*/
/* Equivalent command line invocation of each module using the		*/
/* IBM C Set/2 Version 1.0 compiler is:					*/
/*									*/
/*     Icc -C -G3 -O+ -Rn -W3 -Fofilename filename.C			*/

/* Filename:   TestBed.C						*/

/*  Version:   2.00							*/
/*  Created:   1991-06-07						*/
/*  Revised:   1992-05-01						*/


/* Copyright ¸ 1989-1992  Prominare Inc.  All Rights Reserved.		*/

/* --------------------------------------------------------------------	*/


/* --- Module Definitions ---------------------------------------------	*/

PSZ  pszTestBedClassName = "TestBed";

HAB  hAB;			   /* Program Anchor Block Handle	*/
HMQ  hmqTestBed;		   /* Program Message Queue Handle	*/
HWND hwndTestBed;		   /* Client Window Handle		*/
HWND hwndTestBedFrame;		   /* Frame Window Handle		*/
HWND hmenuTestBed;		   /* Menu Handle			*/

BOOL fState1 = TRUE;

MRESULT	EXPENTRY ImageBtnWndProc(HWND hWnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT	EXPENTRY TestWndProc(HWND hWnd,	ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT	EXPENTRY TestDlgProc(HWND hWnd,	ULONG msg, MPARAM mp1, MPARAM mp2);

#pragma	subtitle("   Test Dialogues - Test Dialogue Procedure")
#pragma	page( )

/* --- TestDlgProc ----------------------------------------------------	*/
/*									*/
/*     This function is	used to	process	the messages for the test	*/
/*     dialogue	procedure.						*/
/*									*/
/*     Upon Entry:							*/
/*									*/
/*     HWND   hWnd; = Dialog Window Handle				*/
/*     ULONG  msg;  = PM Message					*/
/*     MPARAM mp1;  = Message Parameter	1				*/
/*     MPARAM mp2;  = Message Parameter	2				*/
/*									*/
/*     Upon Exit:							*/
/*									*/
/*     TestDlgProc = Message Handling Result				*/
/*									*/
/* --------------------------------------------------------------------	*/

MRESULT	EXPENTRY TestDlgProc(HWND hWnd,	ULONG msg, MPARAM mp1, MPARAM mp2)

{
SWP swp;			   /* Screen Window Position Holder	*/

switch ( msg )
   {
		       /* Perform dialog initialization			*/
   case	WM_INITDLG :
		       /* Centre dialog	on the screen			*/

       WinQueryWindowPos(hWnd, (PSWP)&swp);
       WinSetWindowPos(hWnd, HWND_TOP,
		       ((WinQuerySysValue(HWND_DESKTOP,	SV_CXSCREEN) - swp.cx) / 2),
		       ((WinQuerySysValue(HWND_DESKTOP,	SV_CYSCREEN) - swp.cy) / 2),
		       0, 0, SWP_MOVE);

       break;

			/* Process push	button selections		*/
   case	WM_COMMAND :
	switch (SHORT1FROMMP(mp1) )
	    {
	   case	IB_BUTTON1 :
	       WinMessageBox(HWND_DESKTOP, hWnd, "Image Button 1 Pressed.",
			     "Image Button Test", 0, MB_OK | MB_ICONASTERISK);
	
	       if ( fState1 )
		   fState1 = FALSE;
	       else
		   fState1 = TRUE;

	       WinEnableWindow(WinWindowFromID(hWnd, IB_BUTTON2), fState1);
	       break;

	   case	IB_BUTTON2 :
	       WinMessageBox(HWND_DESKTOP, hWnd, "Image Button 2 Pressed.",
			     "Image Button Test", 0, MB_OK | MB_ICONASTERISK);
	       break;

	   case	IB_BUTTON3 :
	       WinMessageBox(HWND_DESKTOP, hWnd, "Image Button 3 Pressed.",
			     "Image Button Test", 0, MB_OK | MB_ICONASTERISK);
	       break;

	   case	IB_BUTTON4 :
	       WinMessageBox(HWND_DESKTOP, hWnd, "Image Button 4 Pressed.",
			     "Image Button Test", 0, MB_OK | MB_ICONASTERISK);
	       break;

	    case DID_OK	:
		WinDismissDlg(hWnd, TRUE);
		break;

	    }
	break;
			/* Close requested, exit dialogue		*/
   case	WM_CLOSE :
	WinDismissDlg(hWnd, FALSE);
	break;
			/* Pass	through	unhandled messages		*/
   default :
       return(WinDefDlgProc(hWnd, msg, mp1, mp2));
   }
return(0L);
}
#pragma	subtitle("   Client Window - Client Window Procedure")
#pragma	page( )

/* --- TestWndProc ----------------------------------------------------	*/
/*									*/
/*     This function is	used to	process	the messages sent to the	*/
/*     applications client window.					*/
/*									*/
/*     Upon Entry:							*/
/*									*/
/*     HWND   hWnd; = Window Handle					*/
/*     ULONG  msg;  = PM Message					*/
/*     MPARAM mp1;  = Message Parameter	1				*/
/*     MPARAM mp2;  = Message Parameter	2				*/
/*									*/
/*     Upon Exit:							*/
/*									*/
/*     TestWndProc = Message Handling Result				*/
/*									*/
/* --------------------------------------------------------------------	*/

MRESULT	EXPENTRY TestWndProc(HWND hWnd,	ULONG msg, MPARAM mp1, MPARAM mp2)

{
RECTL rcl;			   /* Window Rectangle			*/
HPS   hPS;			   /* Presentation Space Handle		*/

switch ( msg )
   {
			/* Close the application			*/
   case	WM_CLOSE :
       WinPostMsg(hWnd,	WM_QUIT, 0L, 0L);
       break;
			/* Process menu	and button selections		*/
   case	WM_COMMAND :
       switch (	SHORT1FROMMP(mp1) )
	   {
	   case	IDM_TEST :
	       WinDlgBox(HWND_DESKTOP, hwndTestBedFrame, (PFNWP)TestDlgProc,
			 (HMODULE)NULL,	DLG_TEST, NULL);
	       break;

	   case	IDM_EXIT :
	       WinPostMsg(hWnd,	WM_CLOSE, 0L, 0L);
	       break;

	   }
       break;
			/* Window being	destroyed, perform clean-up	*/
			/* operations					*/

   case	WM_ERASEBACKGROUND :
       WinQueryWindowRect(hWnd,	&rcl);
       WinFillRect((HPS)LONGFROMMP(mp1), &rcl, SYSCLR_WINDOW);
       break;
			/* Paint client	window				*/
   case	WM_PAINT :
       WinFillRect(hPS = WinBeginPaint(hWnd, (HPS)NULL,	&rcl), &rcl, SYSCLR_WINDOW);
       WinEndPaint(hPS);
       break;
			/* Default message processing			*/
   default :
       return(WinDefWindowProc(hWnd, msg, mp1, mp2));
   }
return(0L);
}
#pragma	subtitle("   Client Window - Client Window Procedure")
#pragma	page( )

/* --- main -----------------------------------------------------------	*/
/*									*/
/*     This function is	used to	process	the messages sent to the	*/
/*     applications client window.					*/
/*									*/
/*     Upon Entry:							*/
/*									*/
/*     INT  argc;     =	Argument Count					*/
/*     CHAR *argv[ ]; =	Argument Vector					*/
/*									*/
/*     Upon Exit:							*/
/*									*/
/*     main = Return Result						*/
/*									*/
/* --------------------------------------------------------------------	*/

INT main(INT argc, CHAR	*argv[ ])

{
QMSG  qmsg;			   /* PM Message Queue Holder		*/
ULONG flCreateFlags;		   /* Window Creation Flags		*/

		       /* Initialize the program for PM	and create the	*/
		       /* message queue					*/

hmqTestBed = WinCreateMsgQueue(hAB = WinInitialize(0), 0);

		       /* Register the window class			*/

if ( !WinRegisterClass(hAB, pszTestBedClassName, (PFNWP)TestWndProc,
		       CS_SYNCPAINT | CS_SIZEREDRAW, 0)	)
   return(0);

if ( !WinRegisterClass(hAB, "ImageBtn",	(PFNWP)ImageBtnWndProc,
		       CS_PARENTCLIP | CS_SYNCPAINT | CS_SIZEREDRAW, USER_RESERVED) )
   return(0);
		       /* Create the main program window		*/

flCreateFlags =	FCF_NOBYTEALIGN	| FCF_TASKLIST | FCF_TITLEBAR |	FCF_ICON | FCF_SYSMENU |
		FCF_MENU | FCF_MINMAX |	FCF_ACCELTABLE | FCF_SIZEBORDER	| FCF_SHELLPOSITION;
if ( !(hwndTestBedFrame	= WinCreateStdWindow(HWND_DESKTOP, WS_VISIBLE, &flCreateFlags,
					     pszTestBedClassName, "Test Bed Application", 0L,
					     (HMODULE)NULL, ID_WINDOW, &hwndTestBed)) )
   return(0);
		       /* Get and dispatch the message to program	*/
		       /* windows					*/

while (	WinGetMsg(hAB, &qmsg, (HWND)NULL, 0, 0)	)
   WinDispatchMsg(hAB, &qmsg);

		       /* Have received	a WM_QUIT, start the program	*/
		       /* shutdown by destroying the program windows	*/
		       /* and destroying the message queue		*/

WinDestroyWindow(hwndTestBedFrame);
WinDestroyMsgQueue(hmqTestBed);

		       /* Notify PM that main program thread not needed	*/
		       /* any longer					*/
WinTerminate(hAB);
		       /* Exit back to OS/2 cleanly			*/
DosExit(EXIT_PROCESS, 0);
return(0);
}
