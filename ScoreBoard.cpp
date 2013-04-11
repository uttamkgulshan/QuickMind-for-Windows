//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ScoreBoard.h"
#include "GameBoard.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"

TScoreBoard *ScoreBoard;

int i;

bool playerclick=false;


//---------------------------------------------------------------------------
__fastcall TScoreBoard::TScoreBoard(TComponent* Owner)
		: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TScoreBoard::Timer1Timer(TObject *Sender)
{
  if ( (i<(Form1->score+80)) && !playerclick)
  {
	if (i<=Form1->score) ScoreLabel->Caption=i;
   i++;
  }
  else
  {
   Timer1->Enabled=false;
   ScoreBoard->Close();
  }
}
//---------------------------------------------------------------------------

void __fastcall TScoreBoard::FormShow(TObject *Sender)
{
  i=0;
  playerclick=false;
  //Form1->score=1000;
  Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TScoreBoard::Image1Click(TObject *Sender)
{
playerclick=true;
}
//---------------------------------------------------------------------------

