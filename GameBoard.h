//---------------------------------------------------------------------------

#ifndef GameBoardH
#define GameBoardH
//---------------------------------------------------------------------------
#include <shellapi.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Graphics.hpp>

#include "TeCanvas.hpp"
//Needs Borland C++ Builder 6

//---------------------------------------------------------------------------



class TForm1 : public TForm
{
__published:	// IDE-managed Components
		TMainMenu *MainMenu1;
		TMenuItem *N1;
		TMenuItem *N2;
		TMenuItem *N3;
		TMenuItem *About1;
		TMenuItem *N4;
		TMenuItem *N5;
		TLabel *GuessBox1;
		TLabel *GuessBox2;
		TLabel *GuessBox3;
		TLabel *GuessBox4;
		TLabel *GuessBoxB1;
		TLabel *GuessBoxB2;
		TLabel *GuessBoxB3;
		TLabel *GuessBoxB4;
		TTimer *Timer1;
		TImage *Image1;
		TShape *PegA1;
		TShape *PegA2;
		TShape *PegA3;
		TShape *PegA4;
		TShape *PegB1;
		TShape *PegB2;
		TShape *PegB3;
		TShape *PegB4;
		TShape *Shape1;
		TShape *Shape2;
		TShape *Shape3;
		TShape *Shape4;
		TShape *HintA1;
		TShape *HintA2;
		TShape *HintA3;
		TShape *HintA4;
		TShape *HintB1;
		TShape *HintB2;
		TShape *HintB3;
		TShape *HintB4;

		TImage *BombLine;

		TImage *Image2;

		TShape *PegC1;
		TShape *PegC2;
		TShape *PegC3;
		TShape *PegC4;

		TShape *PegD1;
		TShape *PegD2;
		TShape *PegD3;
		TShape *PegD4;

		TShape *PegE1;
		TShape *PegE2;
		TShape *PegE3;
		TShape *PegE4;

		TShape *PegF1;
		TShape *PegF2;
		TShape *PegF3;
		TShape *PegF4;

		TShape *PegG1;
		TShape *PegG2;
		TShape *PegG3;
		TShape *PegG4;

		TShape *PegH1;
		TShape *PegH2;
		TShape *PegH3;
		TShape *PegH4;

		TShape *HintC1;
		TShape *HintC2;
		TShape *HintC3;
		TShape *HintC4;
	TShape *HintD1;
	TShape *HintD2;
	TShape *HintD3;
	TShape *HintD4;
	TShape *HintE1;
	TShape *HintE2;
	TShape *HintE3;
	TShape *HintE4;
	TShape *HintF1;
	TShape *HintF2;
	TShape *HintF3;
	TShape *HintF4;
		TImage *OkImage;
		TShape *HintG1;
		TShape *HintG2;
		TShape *HintG3;
		TShape *HintG4;
		TShape *HintH1;
		TShape *HintH2;
		TShape *HintH3;
		TShape *HintH4;
		TBevel *Bevel1;

		void __fastcall FormCreate(TObject *Sender);

		void __fastcall N5Click(TObject *Sender);

		void __fastcall ShapeMouseUp
		(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y);

		void __fastcall PegA1MouseDown(TObject *Sender,
		  TMouseButton Button, TShiftState Shift, int X, int Y);

		void __fastcall PegA2MouseDown(TObject *Sender,
		  TMouseButton Button, TShiftState Shift, int X, int Y);

		void __fastcall PegA3MouseDown(TObject *Sender,
		  TMouseButton Button, TShiftState Shift, int X, int Y);

		void __fastcall PegA4MouseDown(TObject *Sender,
		  TMouseButton Button, TShiftState Shift, int X, int Y);

		void __fastcall Timer1Timer(TObject *Sender);

		void __fastcall N3Click(TObject *Sender);

		void __fastcall OkImageClick(TObject *Sender);

		void __fastcall N4Click(TObject *Sender);

//==============================================================================


private:	// User declarations
public:		// User declarations

 __fastcall TForm1(TComponent* Owner);



 int mastercolor[5]; //τα κελιά 1-4 του πίνακα περιέχουν το χρώμα του καθενός στοιχείου του συνδυασμου.

 int boxnum; //δηλώνει σε ποιο από τα peg της ίδιας σειράς έκανε κλικ ο παίκτης.
 /*Θ' αλλαχθέί σε ChosenColor */

 int clCounter[5]; //τα κελιά 1-4 περιέχουν τον αριθμό του ενεργού χρώματος για κάθε στοιχείο της ενεργής σειράς χρωμάτων.

 int blackpegs;
 int whitepegs;

 int currentry;

 int timer;
 int timeleft;

 int step;
 int score;

 TShape* mastershape[5];

 TShape* peg[9][5];
 TShape* hint[9][5];


 void TForm1::GenerateCombination();
 void TForm1::EvaluateMatches();
 void TForm1::VisualiseHints();
 void TForm1::NextTry(int fromtry);
 void TForm1::ResetBoard();
 void TForm1::NewGame();
//  void ChangeColor(int boxnum);



};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
